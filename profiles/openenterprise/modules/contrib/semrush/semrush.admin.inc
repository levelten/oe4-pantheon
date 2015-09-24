<?php

/**
 * @file
 * Admin include file.
 */

/**
 * Displays the form for the standard settings tab.
 *
 * @return
 *   array A structured array for use with Forms API.
 */
function semrush_admin_settings($form, &$form_state) {

  $form['semrush_apikey'] = array(
    '#type' => 'textfield',
    '#title' => t('SEMRush API key'),
    '#description' => t(''),
    '#default_value' => variable_get('semrush_apikey', ''),
    //'#description' => t('In order to enable the API tools you will need a SEMRush account login (username & password). !semrush_link.',
    //  array(
    //    '!semrush_link' => l(t('Get your API account here'), SEMRUSH_LINK_API_ACCOUNT, array('attributes' => array('target', 'semrush'))),
    //  )
    //),
  );

  $form['semrush_phrase_fullsearch_display_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Keyword phrase results limit'),
    '#description' => t('The maximum number of records to retrieve from a phrase_fullsearch api response.'),
    '#default_value' => variable_get('semrush_phrase_fullsearch_display_limit', SEMRUSH_PHASE_FULLSEARCH_DISPLAY_LIMIT_DEFAULT),
    //'#description' => t('In order to enable the API tools you will need a SEMRush account login (username & password). !semrush_link.',
    //  array(
    //    '!semrush_link' => l(t('Get your API account here'), SEMRUSH_LINK_API_ACCOUNT, array('attributes' => array('target', 'semrush'))),
    //  )
    //),
  );
  return system_settings_form($form);
  /*
  $semrush = semrush_include_api_class();
  $account = 0;
  if ($semrush) {
	  $ret = $semrush->getAPICredits();
	  if ($ret->credits_per_month) {
	    $account = 1;
	  }  
  }
  if(!$account) {
  	// remove error message from semrush_include_api_class()
  	if(isset($_SESSION['messages']['error'])) {
  		unset($_SESSION['messages']['error']);
  	}
    drupal_set_message(t('You are unable to log in to SEMRush. Please enter a valid SEMRush API username and password.'), 'error');
  }
  */
  //dsm($ret);

  $form['semrush_username'] = array(
    '#type' => 'textfield',
    '#title' => t('SEMRush API username'),
    '#description' => t(''),
    '#default_value' => variable_get('semrush_username', ''),
    '#description' => t('In order to enable the API tools you will need a SEMRush account login (username & password). !semrush_link.',
      array(
      '!semrush_link' => l(t('Get your API account here'), SEMRUSH_LINK_API_ACCOUNT, array('attributes' => array('target', 'semrush'))),
    )
    ),
  );
  $form['semrush_password'] = array(
    '#type' => 'password',
    '#title' => t('SEMRush API password'),
    '#description' => t(''),
    '#default_value' => variable_get('semrush_password', ''),
  );

  $form['semrush_cache_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Cache time'),
    '#description' => t('API results are cached. Use this value to set in seconds the time before checking if the cache data is out of date.'),
    '#default_value' => variable_get('semrush_cache_time', SEMRUSH_CACHE_TIME),
  );

  if ($account) {
    $form['semrush_account_status'] = array(
      '#type' => 'markup',
      '#value' => '<h3>' . t('Account Status') . '</h3>',
    );
    $form['semrush_remaining_monthly_credits'] = array(
      '#type' => 'item',
      '#title' => t('Remaining montly credits'),
      '#markup' => $ret->remaining_monthly_credits,
    );
    $form['semrush_credits_per_month'] = array(
      '#type' => 'item',
      '#title' => t('Credits per month'),
      '#markup' => $ret->credits_per_month,
    );
  }

  $form['semrush_stats_report_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Stats report options'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['semrush_stats_report_options'] = array_merge($form['semrush_stats_report_options'], semrush_stats_report_form_options());

  return system_settings_form($form);
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function semrush_free_keyword_tool_page($keyword = NULL) {
  if (!$embed_id = variable_get('semrush_free_embed_id', '')) {
    drupal_set_message(
      t('You will need a embed id before you can use the free keyword tool. !admin_link', 
        array(
      '!admin_link' => l(t('Configure setting here'), 'admin/config/semrush'),
    )
      ), 'error');
    $output = '';
  }
  else {
    $output = '
      <iframe width="673" height="557" scrolling="no" frameborder=0 src="http://freekeywordtool.semrush.com/themes/keyword_tool_widget_big.html?name=Test&color_b=#01679a&color_t=#ffffff&embed_id=' . $embed_id . '"></iframe>
      <br/><a href="http://www.semrush.com">Powered by SEMRush Internet Marketing Software</a>
    ';
  }
  return $output;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function semrush_free_keyword_niche_page($keyword = NULL) {
  if (!$embed_id = variable_get('semrush_free_embed_id', '')) {
    drupal_set_message(
      t('You will need a embed id before you can use the free keyword tool. !admin_link', 
        array(
      '!admin_link' => l(t('Configure setting here'), 'admin/config/semrush'),
    )
      ), 'error');
    $output = '';
  }
  else {
    $output = '
    <iframe width="673" height="557" scrolling="no" frameborder=0 src="http://nichefinder.semrush.com/themes/niche_finder_widget_big.html?name=Test&color_b=#01679a&color_t=#ffffff&embed_id=' . $embed_id . '"></iframe>
    <br/><a href="http://www.semrush.com">Powered by SEMRush Internet Marketing Software</a>
    ';
  }
  return $output;
}

