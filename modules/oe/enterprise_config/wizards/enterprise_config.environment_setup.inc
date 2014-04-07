<?php

function enterprise_config_wizard_environment_setup_select($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  $items = array();

  // names follow the format 'env_type:env_options'. For env_types using; dev|local,
  // test|stage, or live|prod.
  $options = array(
    'dev' => t('Development'),
    'local:tom' => t('- Tom\'s local'),
    'test' => t('Testing'),
    'prod' => t('Live'),
  );
  $form['name'] = array(
    '#type' => 'select',
    '#title' => t('Environment'),
    '#options' => $options,
    '#default_value' => isset($data['name']) ? $data['name'] : '',
  );
  
  return $form;
}

function enterprise_config_wizard_environment_setup_options($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  
  $form['options'] = array(
    '#tree' => TRUE,
  );
  

  if ($data['name'] == 'local:tom') {
    $options = array(
      'local' => t('local'),
      '' => t('Default'),
    );
    $form['options']['intel_src'] = array(
      '#type' => 'select',
      '#title' => t('Intelligence API source'),
      '#options' => $options,
      '#default_value' => isset($data['options']['intel_src']) ? $data['options']['intel_src'] : '',    
    );
  }

  return $form;
}

function enterprise_config_wizard_environment_setup_options_submit($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  $values = $form_state['values'];
dsm($form_state);
  $name_e = explode(':', $data['name']);

  $modules = array();
  if ($name_e[0] == 'dev' || $name_e[0] == 'local') {
    $modules['backup_migrate'] = 1;
    $modules['devel'] = 1;
    $modules['deploy'] = 1;
    $modules['deploy_ui'] = 1;
    $modules['deploy_managed_ui'] = 1;
    $modules['dblog'] = 1;
    $modules['ds_ui'] = 1;
    $modules['field_ui'] = 1;
    $modules['uuid'] = 1;
    $modules['uuid_path'] = 1;
    $modules['views_ui'] = 1;
    $modules['performance'] = 0;
    $modules['overlay'] = 0;
  }
  if ($data['name'] == 'local:tom') {
    variable_set('googleanalytics_account', 'UA-5541069-12');
    
    //variable_set('google_analytics_reports_oauth_token', '1/xJ2Pn4k1cRpNFbvKsKpazNFAeAN05iSHc8WMWZP8ae0');
    //variable_set('google_analytics_reports_oauth_token_secret', '3Q1N09yWTj0EgaLaGjxH6IJ5');
    variable_set('google_analytics_reports_profile_id', '20161899');

    variable_set('intel_ga_account', 'UA-5541069-13');
    variable_set('intel_apikey', 'ac9ee0035ffc5fc173c36dcf9b0d6810');
    variable_set('intel_domain_name', '');

    if ($values['options']['intel_src'] == 'local') {
      variable_set('intel_l10iapi_url', 'lvlt_api.localhost:8082/v1/intel');
      variable_set('intel_l10iapi_connector', 'C:\Documents\Working\lvlt_api/v1/intel/connector_local.php');
    }
    else {
      variable_set('intel_l10iapi_url', '');
      variable_set('intel_l10iapi_connector', '');    
    }


  }

  if (count($modules)) {
    config_module_enable_disable($modules);
  }
}