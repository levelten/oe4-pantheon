<?php
/**
 * @file
 * Code for the Enterprise CRM feature.
 */

define('ENTERPRISE_APPS_L10IAPI_HREF', 'http://api.getlevelten.com');

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
    /*
      'apps_profile_download_app_modules_' . $apps_server_name => array(
        'display' => FALSE,
        'type' => 'batch',
        'run' => (isset($_SESSION['apps']))?INSTALL_TASK_RUN_IF_NOT_COMPLETED:INSTALL_TASK_SKIP,
        'function' => 'apps_profile_download_app_modules',
      ),
      // Only need this if using filetransfer authorization.
      'apps_profile_authorize_transfer_' . $apps_server_name => array(
        'display' => FALSE,
        'type' => 'form',
        'run' => (!is_writeable(conf_path()) && isset($_SESSION['apps']))?INSTALL_TASK_RUN_IF_NOT_COMPLETED:INSTALL_TASK_SKIP,
        'function' => 'apps_profile_authorize_transfer',
      ),
      'apps_profile_install_app_modules_' . $apps_server_name => array(
        'display' => FALSE,
        'type' => 'batch',
        'run' => (isset($_SESSION['apps']))?INSTALL_TASK_RUN_IF_NOT_COMPLETED:INSTALL_TASK_SKIP,
        'function' => 'apps_profile_install_app_modules',
      ),
      'apps_profile_enable_app_modules_' . $apps_server_name => array(
        'display' => FALSE,
        'type' => 'batch',
        'run' => (isset($_SESSION['apps']))?INSTALL_TASK_RUN_IF_NOT_COMPLETED:INSTALL_TASK_SKIP,
        'function' => 'apps_profile_enable_app_modules',
      ),
    );
    */
  }
  return $tasks;
}

function enterprise_apps_config_features_options_form($form, $form_state, &$install_state) {
  drupal_set_title(t('Install applications'));

  $msg = st('Major site components such blogs and landing pages are provided in modular features called Apps.');
  $msg .= ' ' . st('After installation, you can add Apps at anytime using the Features admin.');
  $msg .= ' ' . st('The selections below provide automated initial setup for popular combinations of Apps.');
  $form['install'] = array(
    '#type' => 'fieldset',
    //'#tree' => TRUE,
    '#title' => t('Apps'),
    '#description' => $msg,
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $options = array(
    'min' => '<strong>' . st('Minimal') . '</strong>',
    'attract' => '<strong>' . st('Attract') . '</strong>',
    'attract_convert' => '<strong>' . st('Attract & convert') . '</strong>',
    'standard' => '<strong>' . st('Full suite') . '</strong>',
  );
  $form['install']['demo_mode'] = array(
    '#type' => 'radios',
    '#title' => '',
    '#options' => $options,
    '#default_value' => 'standard',
  );
  $form['install']['demo_mode']['min']['#description'] = st('Only installs base Open Enterprise apps. The only available content type will be basic pages.');
  $form['install']['demo_mode']['attract']['#description'] = st('Installs essential apps for content marketing including; blog, social media, and webforms.');
  $form['install']['demo_mode']['attract_convert']['#description'] = st('Adds landing pages, calls-to-action and A/B testing to facilitate robust conversion workflows.');
  $form['install']['demo_mode']['standard']['#description'] = st('Installs the apps for the standard Open Enterprise demo. Includes all essential apps plus; Press releases, FAQ.');

  if (!enterprise_apps_module_files_exist('enterprise_landingpages')) {
    $form['install']['demo_mode']['attract_convert']['#disabled'] = TRUE;
    $form['install']['demo_mode']['standard']['#disabled'] = TRUE;
    $form['install']['demo_mode']['#default_value'] = 'attract';
  }
  else if (!enterprise_apps_module_files_exist('enterprise_press')) {
    $form['install']['demo_mode']['standard']['#disabled'] = TRUE;
    $form['install']['demo_mode']['#default_value'] = 'attract_convert';
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

  $msg = st('Most Apps provide optional content to help demonstrate functionality. Use the checkbox below to enable demo content to be installed.');
  $form['install']['demo_content_msg'] = array(
    '#type' => 'markup',
    '#markup' => '<hr />' . $msg,
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
  $msg = st('The Intelligence API provides enhanced analytics, visitor data and site functionality.');
  $msg .= ' ' . st('You can get a Free or Pro key at !link.',
      array(
        '!link' => l(t('Intelligence API'), ENTERPRISE_APPS_L10IAPI_HREF, $link_options),
      )
    );

  $form['intel'] = array(
    '#type' => 'fieldset',
    '#title' => t('API connect'),
    '#description' => $msg,
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['intel']['intel_tid'] = array(
    '#type' => 'textfield',
    '#title' => st('Tid'),
    '#default_value' => '',
    '#description' => st('Input the Intel property tracking id.'),
    '#size' => 32,
  );

  $form['intel']['intel_apikey'] = array(
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
  $options = array(
    'tid' => $form_state['values']['intel_tid'],
    'apikey' => $form_state['values']['intel_apikey'],
    'params' => array(
      'ext_data' => 1,
    ),
  );
  $message = '';
  $property = array();
  $api_level = intel_verify_apikey($message, $property, $options);
  if (!empty($property['status']) && !empty($property['level'])) {
    $form_state['api_profile_settings'] = $property;
    variable_set('intel_ga_account', $form_state['values']['intel_tid']);
    variable_set('intel_apikey', $form_state['values']['intel_apikey']);
    variable_set('intel_api_level', $property['level']);
    if (!empty($property['profile_settings'])) {
      $profile_settings = '';
      // check format
      $property['profile_settings'] = trim($property['profile_settings']);
      if (substr($property['profile_settings'], 0, 5) == 'array') {
        eval('$profile_settings = ' . $property['profile_settings'] . ';');
      }
      else if (substr($property['profile_settings'], 0, 2) == 'a:') {
        $profile_settings = unserialize($property['profile_settings']);
      }
      if ($profile_settings) {
        $form_state['api_profile_settings'] = $profile_settings;
      }

    }
  }

  /*
  if (!valid_email_address($form_state['values']['client_mail'])) {
    form_set_error('client_mail', st('Please enter a valid email address'));
  }
  */
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

    if ($values['demo_mode'] != 'min') {
      $_SESSION['enterprise_apps_demo'] = 'enterprise_demo';
    }
    $profile_settings['demo']['mode'] = $values['demo_mode'];

    if (!empty($values['demo_content'])) {
      $profile_settings['demo']['demo_content'] = 1;
    }

    variable_set('enterprise_apps_profile_settings', $profile_settings);
  }
}

function enterprise_apps_install_demo(&$install_state) {
  $app = $_SESSION['enterprise_apps_demo'];

  require_once(drupal_get_path('module', $app) . '/' . $app . '.module');
  $func = $app . '_enterprise_apps_app_enabled_batch';
  if (function_exists($func)) {

    // get installation batch
    $batch = $func();

    $pre_ops = array();

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

    /*
    $pre_ops[] = array(
      'enterprise_apps_process_profile_settings',
      array(),
    );
    */

    // re-enable app auto config for all apps after demo
    $pre_ops[] = array(
      '_enterprise_apps_prevent_app_enabled_hook_batch',
      array(
        FALSE,
      ),
    );

    // prepend pre_ops to array
    $batch['operations'] = array_merge($pre_ops, $batch['operations']);

    // process any custom settings from api
    $batch['operations'][] = array(
      'enterprise_apps_process_profile_settings',
      array(),
    );

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