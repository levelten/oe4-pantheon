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
  $form['install'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
  );
  $form['install']['standard'] = array(
    '#type' => 'radio',
    '#name' => 'config_method',
    '#default_value' => TRUE,
    '#return_value' => 'standard',
    '#title' => st('<strong>Install the Open Enterprise suite</strong>'),
    '#description' => st('Install the standard collection of Open Enterprise applications and example content.'),
    '#attributes' => array(
      'name' => 'install_option',
    ),
  );
  /**
   * @TODO Build out custom installation process.
   */
//  $form['install']['custom'] = array(
//    '#type' => 'radio',
//    '#name' => 'config_method',
//    '#default_value' => FALSE,
//    '#return_value' => 'custom',
//    '#title' => st('<strong>Choose which applications to install</strong>'),
//    '#description' => st('Select which Open Enterprise applications you would like to install.'),
//    '#attributes' => array(
//      'name' => 'install_option',
//    ),
//  );
  $form['install']['skip'] = array(
    '#type' => 'radio',
    '#name' => 'config_method',
    '#default_value' => FALSE,
    '#return_value' => 'skip',
    '#title' => st('<strong>Skip this step</strong>'),
    '#attributes' => array(
      'name' => 'install_option',
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Continue'),
  );
  return $form;
}

function enterprise_apps_config_features_options_form_validate($form, &$form_state) {
  /*
  if (!valid_email_address($form_state['values']['client_mail'])) {
    form_set_error('client_mail', st('Please enter a valid email address'));
  }
  */
}

function enterprise_apps_config_features_options_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  if ($form_state['values']['op'] == t('Continue')) {
    if (!empty($values['install']['standard'])) {
      $_SESSION['enterprise_apps_demo'] = 'enterprise_demo';
    }
    else if (!empty($values['install']['custom'])) {
      // @TODO Build out custom installation process.
    }
    else if (!empty($values['install']['skip'])) {

    }
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

    // re-enable app auto config for all apps after demo
    $pre_ops[] = array(
      '_enterprise_apps_prevent_app_enabled_hook_batch',
      array(
        FALSE,
      ),
    );

    // prepend pre_ops to array
    $batch['operations'] = array_merge($pre_ops, $batch['operations']);

    return $batch;
  }
}

/**
 * Batch callback invoked when enable batch is completed.
 */
function enterprise_apps_install_cleanup(&$install_state) {
  unset($_SESSION['enterprise_apps_demo']);
}