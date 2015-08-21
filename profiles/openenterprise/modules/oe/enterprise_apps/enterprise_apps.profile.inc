<?php
/**
 * @file
 * Code for the Enterprise CRM feature.
 */

/**
 * Add install tasks to profile install tasks.
 *
 * See apps.api.php for use.
 *
 */
function enterprise_apps_profile_install_tasks($install_state) {
  // Only use apps forms during interactive installs.
  $tasks = array();
  if ($install_state['interactive']) {
    //$_SESSION['apps_server'] = $apps_server;
    //$apps_server_name = $apps_server['machine name'];
    $tasks['enterprise_apps_config_features_form'] = array(
      'display_name' => st('Install applications'),
      'type' => 'form',
      'function' => 'enterprise_apps_config_features_options_form',
    );

    $tasks['enterprise_apps_install_demo'] = array(
      'display' => FALSE,
      'type' => 'batch',
      'run' => (isset($_SESSION['enterprise_apps_demo'])) ? INSTALL_TASK_RUN_IF_NOT_COMPLETED : INSTALL_TASK_SKIP,
      'function' => 'enterprise_apps_install_demo',
    );
    $tasks['enterprise_apps_install_cleanup'] = array(
      'display' => FALSE,
      'type' => 'normal',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'function' => 'enterprise_apps_install_cleanup',
    );
  }
  return $tasks;
}

function enterprise_apps_config_features_options_form($form, $form_state, &$install_state) {
  drupal_set_title(t('Install applications'));

  $ext_apps = array(
    'enterprise_careers' => 0,
    'enterprise_events' => 0,
    'enterprise_faq' => 1,
    'enterprise_forum' => 0,
    'enterprise_image' => 0,
    'enterprise_link' => 0,
    'enterprise_location' => 0,
    'enterprise_news' => 0,
    'enterprise_press' => 1,
    'enterprise_news' => 0,
    'enterprise_video' => 0,
    'enterprise_work' => 0,
  );

  $msg = st('Major site components such blogs and landing pages are provided in modular features called Apps.');
  $msg .= ' ' . st('After installation, you can add Apps at anytime using the Features admin.');
  $form['install'] = array(
    '#type' => 'fieldset',
    //'#tree' => TRUE,
    '#title' => t('Apps'),
    '#description' => $msg,
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $msg = "<br /><hr />" . '<h4>' . st('Essential Apps') . '</h4>';
  $msg .= ' ' . st('The selections below provide automated initial setup for popular combinations of Apps.');
  $form['install']['demo_mode_msg'] = array(
    '#type' => 'markup',
    '#markup' => $msg,
  );

  $options = array(
    'attract_convert' => '<strong>' . st('Attract & convert') . '</strong>',
    'attract' => '<strong>' . st('Attract') . '</strong>',
    'min' => '<strong>' . st('Minimal') . '</strong>',
    //'standard' => '<strong>' . st('Full suite') . '</strong>',
  );
  $form['install']['demo_mode'] = array(
    '#type' => 'radios',
    '#title' => '',
    '#options' => $options,
    '#default_value' => 'attract_convert',
  );
  $form['install']['demo_mode']['min']['#description'] = st('Only installs base Open Enterprise apps. The only available content type will be basic pages.');
  $form['install']['demo_mode']['attract']['#description'] = st('Installs essential apps for content marketing including; blog, social media, and webforms.');
  $form['install']['demo_mode']['attract_convert']['#description'] = st('Adds landing pages, calls-to-action and A/B testing to facilitate robust conversion workflows.');
  //$form['install']['demo_mode']['standard']['#description'] = st('Installs the apps for the standard Open Enterprise demo. Includes all essential apps plus; Press releases, FAQ.');

  if (!enterprise_apps_module_files_exist('enterprise_conversion')) {
    $form['install']['demo_mode']['attract_convert']['#disabled'] = TRUE;
    $form['install']['demo_mode']['standard']['#disabled'] = TRUE;
    $form['install']['demo_mode']['#default_value'] = 'attract';
  }
  /*
  else if (!enterprise_apps_module_files_exist('enterprise_press')) {
    $form['install']['demo_mode']['standard']['#disabled'] = TRUE;
    $form['install']['demo_mode']['#default_value'] = 'attract_convert';
  }
  */

  system_rebuild_module_data();

  $msg = '';
  foreach ($ext_apps AS $name => $enabled) {
    if (enterprise_apps_module_files_exist($name)) {
      if (!$msg) {
        $msg = "<hr />" . '<h4>' . st('Extended Apps') . '</h4>';
        $msg .= st('Extended apps provide optional add-on features.');
        $form['install']['extapps_msg'] = array(
          '#type' => 'markup',
          '#markup' => $msg,
        );
      }
      $path = drupal_get_path('module', $name) . '/' . $name . '.info';
      $info = drupal_parse_info_file($path);
      $form['install']['extapp_' . $name] = array(
        '#type' => 'checkbox',
        //'#title' => str_replace('Enterprise ', '', $info['name']),
        '#title' => $info['name'],
        '#description' => isset($info['description']) ?  $info['description'] : '',
        '#default_value' => $enabled,
      );
    }
  }

  /*
  $form['install']['bare'] = array(
    '#type' => 'radio',
    '#name' => 'config_method',
    //'#default_value' => FALSE,
    '#return_value' => 'skip',
    '#title' => st('<strong>Bare</strong>'),
    '#description' => st('Does not install any content apps. The only available content type will be basic pages.'),
    '#attributes' => array(
      'name' => 'install_option',
    ),
  );

  $form['install']['inbound'] = array(
    '#type' => 'radio',
    '#name' => 'config_method',
    //'#default_value' => FALSE,
    '#return_value' => 'inbound',
    '#title' => st('<strong>Essentials</strong>'),
    '#description' => st('Installs essential apps for content marketing including; Blog, Social media, Webform and Landingpages & Calls-to-action.'),
    '#attributes' => array(
      'name' => 'install_option',
    ),
  );

  $form['install']['standard'] = array(
    '#type' => 'radio',
    '#name' => 'config_method',
    //'#default_value' => TRUE,
    '#return_value' => 'standard',
    '#title' => st('<strong>Full</strong>'),
    '#description' => st('Installs the apps for the standard Open Enterprise demo. Includes all essential apps plus; Press releases, FAQ.'),
    '#attributes' => array(
      'name' => 'install_option',
    ),
  );
  */

  $msg = "<br /><hr />" . '<h4>' . st('Demo content') . '</h4>';
  $msg .= st('Most Apps provide optional content to help demonstrate functionality. Use the checkbox below to enable demo content to be installed.');
  $form['install']['demo_content_msg'] = array(
    '#type' => 'markup',
    '#markup' => $msg,
  );

  $form['install']['demo_content'] = array(
    '#type' => 'checkbox',
    '#title' => '<strong>' . st('Install demo content') . '</strong>',
    '#default_value' => TRUE,
  );


  $link_options = array(
    'attributes' => array(
      'target' => 'intelapi',
    )
  );
  $msg = st('Enter your Open Enterprise API connection info to access to extended apps, enhanced analytics, updates &amp; support.');
  $msg .= ' ' . st('To get an API key visit !link.',
      array(
        '!link' => l(t('getCM2.com'), 'http://' . OE_HOME_URL, $link_options),
      )
    );

  $form['intel'] = array(
    '#type' => 'fieldset',
    '#title' => t('API connect'),
    '#description' => $msg,
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['intel']['oe_pkey'] = array(
    '#type' => 'textfield',
    '#title' => st('Property ID'),
    '#default_value' => '',
    '#description' => st('Input your property id.'),
    '#size' => 32,
  );

  $form['intel']['oe_apikey'] = array(
    '#type' => 'textfield',
    '#title' => st('API key'),
    '#default_value' => '',
    '#description' => st('Input the property api key.'),
  );


  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Continue'),
  );
  return $form;
}

function enterprise_apps_config_features_options_form_validate($form, &$form_state) {
  include_once drupal_get_path('module', 'intel') . '/intel.module';

  // if not api connect info given, return.
  if (empty($form_state['values']['oe_pkey']) || empty($form_state['values']['oe_apikey'])) {
    return;
  }

  $options = array(
    'pkey' => $form_state['values']['oe_pkey'],
    'apikey' => $form_state['values']['oe_apikey'],
    //'apiUrl' => 'getcm2.localhost:8082/api/v1',
  );
  $message = '';
  $status = 200;


  try {
    $property = openenterprise_api_property_load($options, $message, $status);
  }
  catch (Exception $e) {
    // continue
  }

  if (empty($property) || empty($property->status)) {
    if ($status == 404) {
      form_set_error('oe_pkey', t('Property not found. Please select a different property id.'));
    }
    if ($status == 403) {
      form_set_error('oe_apikey', t('API key does not match key found in API.'));
    }
    return;
  }


  if (!empty($property->profile_settings)) {
    $profile_settings = '';
    // check format
    $property->profile_settings = trim($property->profile_settings);
    if (substr($property->profile_settings, 0, 5) == 'array') {
      eval('$profile_settings = ' . $property->profile_settings . ';');
    }
    else if (substr($property->profile_settings, 0, 2) == 'a:') {
      $profile_settings = unserialize($property->profile_settings);
    }
    if ($profile_settings) {
      $form_state['api_profile_settings'] = $profile_settings;
    }
  }

  $property->apikey = $property->intel_apikey = $form_state['values']['oe_apikey'];
  $property->pkey = $form_state['values']['oe_pkey'];
  openenterprise_property_save($property);
}

function enterprise_apps_config_features_options_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  if ($form_state['values']['op'] == t('Continue')) {
    $profile_settings = array();
    if (isset($form_state['api_profile_settings'])) {
      $profile_settings = $form_state['api_profile_settings'];
    }
    $profile_settings['demo'] = array();

    $profile_settings['apps_debug'] = array(
      'form_state_values' => $values,
    );

    $profile_settings['demo']['mode'] = $values['demo_mode'];
    if ($profile_settings['demo']['mode'] != 'min') {
      $_SESSION['enterprise_apps_demo'] = 'enterprise_demo';
    }

    $profile_settings['apps'] = array();
    foreach ($form_state['values'] AS $key => $value) {
      if ((substr($key, 0, 7) == 'extapp_') && $value) {
        list($x, $name) = explode('_', $key, 2);
        $profile_settings['apps'][] = $name;
      }
    }

    if (!empty($values['demo_content'])) {
      $profile_settings['demo']['demo_content'] = 1;
    }
    variable_set('enterprise_apps_profile_settings', $profile_settings);
  }
}

function enterprise_apps_install_demo(&$install_state) {
  $profile_settings = variable_get('enterprise_apps_profile_settings', array());
//drupal_set_message(json_encode($profile_settings));
  $app = '';
  if ($profile_settings['demo']['mode'] != 'min') {
    $app = 'enterprise_demo';
  }

  if ($app) {
    require_once(drupal_get_path('module', $app) . '/' . $app . '.module');
  }

  $func = $app . '_enterprise_apps_app_enabled_batch';
  if (function_exists($func)) {

    // get installation batch
    $batch = $func();

    $pre_ops = array();

    $apps_ops = array();

    // disable triggering demo auto config on install
    enterprise_apps_prevent_app_enabled_hook(TRUE);

    // prepend enabling demo module
    $pre_ops[] = array(
      '_enterprise_apps_enable_module_batch',
      array(
        'enterprise_demo',
        'Enterprise demo',
      ),
    );

    // re-enable app auto config for all apps after demo
    $pre_ops[] = array(
      '_enterprise_apps_prevent_app_enabled_hook_batch',
      array(
        FALSE,
      ),
    );

    // prepend pre_ops to array
    $batch['operations'] = array_merge($pre_ops, $batch['operations']);

    if (isset($profile_settings['apps']) && is_array($profile_settings['apps'])) {
      foreach ($profile_settings['apps'] AS $name) {
        $apps_ops[] = enterprise_apps_get_batch_operation_enable_module($name);
        if (!empty($profile_settings['demo']['demo_content']) && enterprise_apps_module_files_exist($name . '_content')) {
          $apps_ops[] = enterprise_apps_get_batch_operation_enable_module($name . '_content');
        }
      }
    }

    // apps ops need to be inserted just before demo content, so find demo
    // content
    $i = 0;
    foreach ($batch['operations'] AS $i => $op) {
      if (isset($op[0])
        && $op[0] == '_enterprise_apps_enable_module_batch'
        && is_array($op[1]) && isset($op[1][0])
        && $op[1][0] == 'enterprise_demo_content'
      ) {
        break;
      }
    }

    // insert apps_ops before enterprise_demo_content
    array_splice($batch['operations'], $i, 0, $apps_ops);

    // process any custom settings from api
    $batch['operations'][] = array(
      'enterprise_apps_process_profile_settings',
      array(),
    );

//drupal_set_message(json_encode($batch))
//drupal_set_message(print_r($batch, 1));

    return $batch;
  }
}

function enterprise_apps_process_profile_settings() {
  $settings = variable_get('enterprise_apps_profile_settings', array());

  if (isset($settings['module_enable']) && is_array($settings['module_enable'])) {
    module_enable($settings['module_enable']);
  }

  if (isset($settings['strongarm']) && is_array($settings['strongarm'])) {
    foreach ($settings['strongarm'] AS $key => $value) {
      variable_set($key, $value);
    }
  }

  if (module_exists('intel') && !empty($settings['intel_phonenumber_defaults']) && is_array($settings['intel_phonenumber_defaults'])) {
    include_once drupal_get_path('module', 'intel') . '/includes/intel.ga.inc';
    foreach ($settings['intel_phonenumber_defaults'] as $name => $number) {
      intel_phonenumber_save($number, $name);
    }
  }

  if (module_exists('mailchimp_lists') && !empty($settings['default_mailchimp_list']) && is_array($settings['default_mailchimp_list'])) {
    foreach ($settings['default_mailchimp_list'] as $name => $data) {
      $entity = entity_import('mailchimp_list', $data);
      $entity->save();
    }
  }
}

/**
 * Batch callback invoked when enable batch is completed.
 */
function enterprise_apps_install_cleanup(&$install_state) {
  unset($_SESSION['enterprise_apps_demo']);
}

function enterprise_apps_profile_data_export() {
  // variable table/strongarm data
  $data = array();

  $data['module_enable'] = array(
    'intel_mailchimp',
    'intel_twilio',
    'mailchimp_lists',
    'strongarm',
    'twilio',
    'webform_mailchimp',
  );

  $data['strongarm'] = array();

  $sa_vars = array(
    'alchemy_apikey' => '',
    'disqus_domain' => '',
    'disqus_userapikey' => '',
    'googleanalytics_account' => '',
    'google_analytics_reports_oauth_token' => '',
    'google_analytics_reports_oauth_token_secret' => '',
    'google_analytics_reports_profile_id' => '',
    'intel_extended_mode' => '',
    'intel_ga_account' => '',
    'intel_mailchimp_default_list_id' => '',
    'intel_track_phonecalls' => '',
    'mailchimp_api_key' => '',
    'twilio_account' => '',
    'twilio_number' => '',
    'twilio_token' => '',
  );

  foreach ($sa_vars AS $name => $default) {
    $data['strongarm'][$name] = variable_get($name, $default);
  }

  // intel data
  $numbs = (array) intel_get_phonenumbers();
  if (!empty($numbs) && is_array($numbs)) {
    $data['intel_phonenumber_defaults'] = $numbs;
  }

  // mailchimp settings
  $mc_lists = mailchimp_lists_load_multiple();
  if (!empty($mc_lists) && is_array($mc_lists)) {
    $data['default_mailchimp_list'] = array();
    foreach ($mc_lists AS $id => $list) {
      $data['default_mailchimp_list'][$list->name] = json_encode($list);
    }
  }

  //$output = json_encode($data);

  //$output = serialize($data);

  $output = var_export($data);

  return $output;
}