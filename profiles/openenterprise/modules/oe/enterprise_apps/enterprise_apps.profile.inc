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

  $form['rolesfs'] = array(
    '#type' => 'fieldset',
    '#title' => t('Roles'),
    '#description' => t('User roles added during the installation.'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $options = array(
    'writer' => t('Writer'),
    'editor' => t('Editor'),
    'manager' => t('Manager'),
    'demo' => t('Demo (admin)'),
  );
  $form['rolesfs']['roles'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Roles',
    '#options' => $options,
    '#default_value' => array('writer', 'editor', 'manager'),
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

  watchdog('install-form', print_r($form_state['values'], 1));


  if ($form_state['values']['op'] == t('Continue')) {
    if (!empty($form_state['values']['roles']) && is_array($form_state['values']['roles'])) {
      $w = 2;
      foreach ($form_state['values']['roles'] as $name => $v) {
        if ($v) {
          $role = new stdClass();
          $role->name = $name;
          $role->weight = $w++;
          user_role_save($role);
        }
      }
      // sort admin role to end of list
      $r = user_role_load_by_name('administrator');
      $r->weight = $w;
      user_role_save($r);
    }


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
  $demo_app = '';
  $demo_info = array();

  if ($profile_settings['demo']['mode'] != 'min') {
    $demo_app = 'enterprise_demo';
  }

  if (!enterprise_apps_module_files_exist($demo_app)) {
    return;
  }

  require_once(drupal_get_path('module', $demo_app) . '/' . $demo_app . '.module');

  $func = $demo_app . '_enterprise_apps_install_demo_info';

  if (!function_exists($func)) {
    return;
  }

  $profile_settings['demo']['info'] = $demo_info = $func();

  $debug['demo_info'] = $demo_info;

  $batch = array(
    'operations' => array(),
    'title' => !empty($demo_info['batch_title']) ? st($demo_info['batch_title']) : st('Installing Open Enterprise Demo'),
    'init_message' => st('Preparing to install'),
    'error_message' => st('The installation has encountered an error.'),
    'finished' => '_enterprise_apps_install_demo_batch_finished',
  );

  // disable triggering demo auto config on install
  //enterprise_apps_prevent_app_enabled_hook(TRUE);

  // prepend enabling demo module
  $batch['operations'][] = array(
    '_enterprise_apps_enable_module_batch',
    array(
      $demo_app,
      'Enterprise demo',
    ),
  );

  // re-enable app auto config for all apps after demo
  /*
  $batch['operations'][] = array(
    '_enterprise_apps_prevent_app_enabled_hook_batch',
    array(
      FALSE,
    ),
  );
  */

  if (empty($demo_info['required_apps'])) {
    $demo_info['required_apps'] = array();
  }

  // create array of demo apps with optional apps from form
  $apps = array();
  foreach ($demo_info['required_apps'] as $name) {
    if (enterprise_apps_module_files_exist($name)) {
      $apps[$name] = $name;
    }
    if (enterprise_apps_module_files_exist($name . '_config')) {
      $apps[$name . '_config'] = $name . '_config';
    }
    if (!empty($profile_settings['demo']['demo_content']) && enterprise_apps_module_files_exist($name . '_content')) {
      $apps[$name . '_content'] = $name . '_content';
    }
  }

  // add optional apps before demo content
  if (isset($profile_settings['apps']) && is_array($profile_settings['apps'])) {
    foreach ($profile_settings['apps'] AS $name) {
      if (enterprise_apps_module_files_exist($name)) {
        $apps[$name] = $name;
      }
      if (enterprise_apps_module_files_exist($name . '_config')) {
        $apps[$name . '_config'] = $name . '_config';
      }
      if (!empty($profile_settings['demo']['demo_content']) && enterprise_apps_module_files_exist($name . '_content')) {
        $apps[$name . '_content'] = $name . '_content';
      }
    }
  }

  // add demo_config and content apps
  $apps[$demo_app . '_config'] = $demo_app . '_config';

  $a = !empty($profile_settings['demo']['demo_content']) ? 'enterprise_demo_content' : 'enterprise_demo_nocontent';
  $apps[$a] = $a;

  $apps['enterprise_permissions'] = 'enterprise_permissions';
  $apps['enterprise_permissions_content'] = 'enterprise_permissions_content';

  $profile_settings['demo']['enable_modules'] = $apps;
  $debug['apps'] = $apps;

  // verify app module exists and add to batch
  $missing = array();
  foreach ($apps as $name) {
    $batch['operations'][] = enterprise_apps_get_batch_operation_enable_module($name);
  }

  // process any custom settings from api
  $batch['operations'][] = array(
    'enterprise_apps_process_profile_settings',
    array(),
  );

//drupal_set_message(json_encode($batch))
//drupal_set_message(print_r($batch, 1));

  $debug['batch'] = $batch;
  variable_set('enterprise_demo_debug', $debug);

  variable_set('enterprise_apps_profile_settings', $profile_settings);

  return $batch;
}

function _enterprise_apps_install_demo_batch_finished($success, $results, $operations) {
  // CKEditor sets some settings that override the enterprise_editor. Make sure the
  // feature is fully reverted at this time.
  //features_revert(array('enterprise_editor' => array('ckeditor_profile', 'filter')));

  $profile_settings = variable_get('enterprise_apps_profile_settings', array());

  // must rebuild field instances after all fields are installed.
  if (!empty($profile_settings['demo']['info']['features_revert'])) {
    features_revert($profile_settings['demo']['info']['features_revert']);
  }

  $modules = module_list();
  $module_info_apps = array();
  $disable = array();
  foreach ($modules as $module) {
    $file = drupal_get_path('module', $module) . "/$module.info";
    $info = drupal_parse_info_file($file);
    if (!empty($info['apps'])) {
      $module_info_apps[$module] = $info['apps'];
      if (!empty($info['apps']['disable'])) {
        $disable[] = $module;
      }
    }
  }
  if (!empty($disable)) {
    module_disable($disable);
  }

  // must rebuild field instances after all fields are installed.
  //features_revert(array('enterprise_demo' => array('field_instance')));
  //features_revert(array('enterprise_intel' => array('field_instance')));

  // remove any redirects created on content import
  $query = db_delete('redirect')
    ->condition('access', 0);
  $query->execute();

  // bulk update pathauto paths
  module_load_include('inc', 'pathauto', 'pathauto.pathauto');
  $context = array();
  node_pathauto_bulk_update_batch_process($context);

  // set default front page
  $path = drupal_lookup_path("source", 'home');
  if (!empty($path)) {
    variable_set('site_frontpage', $path);
  }

  drupal_flush_all_caches();

  // clear status messages
  drupal_get_messages('status', TRUE);

  if ($success) {
    drupal_set_message(t('Congratulations! You have successfully installed Open Enterprise.'));
  }
  else {
    $error_operation = reset($operations);
    drupal_set_message(
      t('An error occurred during installation processing @operation with arguments : @args',
        array(
          '@operation' => $error_operation[0],
          '@args' => print_r($error_operation[0], TRUE),
        )
      ), 'error'
    );
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