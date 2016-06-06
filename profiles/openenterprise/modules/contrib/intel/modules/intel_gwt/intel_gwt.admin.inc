<?php
function intel_gwt_admin_form($form, $form_state) {
  $form = array();

  $settings = variable_get('intel_gwt_settings', array());

  /*
   * Make sure to enable the Search Console API (Webmaster Tools API) in
   * Googles API console
   */

  $client_id = variable_get('google_analytics_reports_client_id', NULL);
  $client_secret = variable_get('google_analytics_reports_client_secret', NULL);
  $access_token = variable_get('intel_gwt_access_token', NULL);
  $redirect_uri = variable_get('intel_gwt_redirect_uri', NULL);

  // Load the Google API PHP Client Library.
  require_once libraries_get_path('google-api') . '/src/Google/autoload.php';
  if (!empty($access_token) && is_array($access_token) && !empty($access_token['access_token'])) {
    require_once libraries_get_path('google-api') . '/src/Google/autoload.php';
    $client = new Google_Client();
    try {
      $client->setClientId($client_id);
      $client->setClientSecret($client_secret);
      //$client->addScope(Google_Service_Drive::DRIVE_METADATA_READONLY);
      $client->addScope(Google_Service_Webmasters::WEBMASTERS);
      $client->setAccessToken(json_encode($access_token));

      $webmaster = new Google_Service_Webmasters($client);
      $sites = $webmaster->sites;

      $results = $sites->listSites();
      if (count($results) == 0) {
        drupal_set_message(t('No sites were fetched from Google WMT api.', 'warning'));
      }
    }
    catch (Exception $e) {
      drupal_set_message($e->getMessage(), 'error');
    }
  }
  else {
    drupal_set_message(t('Google WMT api has not been authenticated. Click "Authenticate" to authorize.', 'warning'));
  }

  $form['site_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Site url'),
    '#description' => t('Enter the site url, including protocol, if you want to override the the default server site url.'),
    //'#required' => TRUE,
    '#default_value' => isset($settings['site_url']) ? $settings['site_url'] : '',
  );

  $form['search_batch_row_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Batch row limit'),
    '#description' => t('The number of rows to fetch from API for batch search analytics imports. Maximum of 5000. Default is 1000.'),
    //'#required' => TRUE,
    '#default_value' => isset($settings['search_batch_row_limit']) ? $settings['search_batch_row_limit'] : '',
    '#size' => 8,
  );

  $value = '';
  if (!empty($settings['search_batch_contains_queries'])) {
    foreach ($settings['search_batch_contains_queries'] AS $v) {
      $value .= $v['query'] . '|' . $v['row_limit'] . "\n";
    }
  }
  $form['search_batch_contains_queries'] = array(
    '#type' => 'textarea',
    '#title' => t('Batch query filters'),
    '#default_value' => $value,
    '#description' => t('Enter any query keywords you would like run in addition to the unfiltered fetch. Enter one query per line as keyword,row limit (e.g. <em>example,500</em>). Note that adding query filters will add to fetch time.'),
  );

  $form['search_batch_row_limit_weekly'] = array(
    '#type' => 'textfield',
    '#title' => t('Batch weekly row limit'),
    '#description' => t('The number of rows to fetch from API for weekly batch search analytics imports. Maximum of 5000. Default is 1000.'),
    //'#required' => TRUE,
    '#default_value' => isset($settings['search_batch_row_limit_weekly']) ? $settings['search_batch_row_limit_weekly'] : '',
    '#size' => 8,
  );

  $value = '';
  if (!empty($settings['search_batch_contains_queries_weekly'])) {
    foreach ($settings['search_batch_contains_queries_weekly'] AS $v) {
      $value .= $v['query'] . '|' . $v['row_limit'] . "\n";
    }
  }
  $form['search_batch_contains_queries_weekly'] = array(
    '#type' => 'textarea',
    '#title' => t('Batch weekly query filters'),
    '#default_value' => $value,
    '#description' => t('Enter any query keywords you would like run in addition to the unfiltered fetch. Enter one query per line as keyword,row limit (e.g. <em>example,500</em>). Note that adding query filters will add to fetch time.'),
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );

  $form['authenticate'] = array(
    '#type' => 'submit',
    '#value' => t('Authenticate'),
  );

  return $form;
}

function intel_gwt_admin_form_submit($form, $form_state) {
  $values = $form_state['values'];

  if ($values['op'] == $values['authenticate']) {
    intel_gwt_authenticate_start();
    return;
  }

  $settings = variable_get('intel_gwt_settings', array());
  $settings['site_url'] = $values['site_url'];
  $settings['search_batch_row_limit'] = $values['search_batch_row_limit'];
  $settings['search_batch_contains_queries'] = array();

  $a = explode("\n", $values['search_batch_contains_queries']);
  foreach ($a AS $b) {
    $b = trim($b);
    if (!$b) {
      continue;
    }
    $c = explode("|", $b);
    $d = array(
      'query' => $c[0],
    );
    if (!empty($c[1]) && is_numeric($c[1])) {
      $d['row_limit'] = (int)$c[1];
    }
    $settings['search_batch_contains_queries'][] = $d;
  }

  $settings['search_batch_row_limit_weekly'] = $values['search_batch_row_limit_weekly'];
  $settings['search_batch_contains_queries_weekly'] = array();

  $a = explode("\n", $values['search_batch_contains_queries_weekly']);
  foreach ($a AS $b) {
    $b = trim($b);
    if (!$b) {
      continue;
    }
    $c = explode("|", $b);
    $d = array(
      'query' => $c[0],
    );
    if (!empty($c[1]) && is_numeric($c[1])) {
      $d['row_limit'] = (int)$c[1];
    }
    $settings['search_batch_contains_queries_weekly'][] = $d;
  }

  variable_set('intel_gwt_settings', $settings);
}

function intel_gwt_authenticate_start() {
  $client_id = variable_get('google_analytics_reports_client_id', NULL);
  $client_secret = variable_get('google_analytics_reports_client_secret', NULL);
  //$access_token = variable_get('google_analytics_reports_api_access_token', NULL);
  //$refresh_token = variable_get('google_analytics_reports_api_refresh_token', NULL);

  // Load the Google API PHP Client Library.
  require_once libraries_get_path('google-api') . '/src/Google/autoload.php';
  $client = new Google_Client();
  $client->setClientId($client_id);
  $client->setClientSecret($client_secret);
  $client->addScope(Google_Service_Webmasters::WEBMASTERS);
  $redirect_uri = 'http://' . $_SERVER['HTTP_HOST'] . '/admin/config/system/google-analytics-reports-api';
  $redirect_uri = variable_get('intel_gwt_redirect_uri', $redirect_uri);
  $redirect_uri = 'http://' . $_SERVER['HTTP_HOST'] . '/admin/config/intel/intel_gwt/oauth';
  $client->setRedirectUri($redirect_uri);
  $redirect_uri = variable_set('intel_gwt_redirect_uri', $redirect_uri);

  // force a refresh token to be returned
  $client->setApprovalPrompt('force');
  $client->setAccessType('offline');

  $auth_url = $client->createAuthUrl();
  drupal_goto(filter_var($auth_url, FILTER_SANITIZE_URL));

  return;
}

function intel_gwt_admin_oauth() {
  if (empty($_GET['code'])) {
    drupal_set_message(t('No code provided'));
    return;
  }
  require_once libraries_get_path('google-api') . '/src/Google/autoload.php';
  $client = new Google_Client();
  $client_id = variable_get('google_analytics_reports_client_id', NULL);
  $client_secret = variable_get('google_analytics_reports_client_secret', NULL);
  $client->setClientId($client_id);
  $client->setClientSecret($client_secret);
  //$client->addScope(Google_Service_Drive::DRIVE_METADATA_READONLY);
  $client->addScope(Google_Service_Webmasters::WEBMASTERS);
  $redirect_uri = variable_get('intel_gwt_redirect_uri', '');
  $client->setRedirectUri($redirect_uri);
  try {
    $client->authenticate($_GET['code']);
    $access_token = $client->getAccessToken();
    $access_token = json_decode($access_token, TRUE);
    if (empty($access_token['refresh_token'])) {
      drupal_set_message(t('Refresh token was not returned.'), 'warning');
    }
  }
  catch (Exception $e) {
    drupal_set_message($e->getMessage(), 'error');
    return t('Oh no');
  }

  dsm($access_token);
  variable_set('intel_gwt_access_token', $access_token);


  return 'OK';
}