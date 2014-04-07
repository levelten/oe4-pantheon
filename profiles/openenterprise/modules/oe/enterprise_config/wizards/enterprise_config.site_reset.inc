<?php

function enterprise_config_wizard_site_reset_nodes($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  $items = array();

  $types = node_type_get_types();
dsm($types);  
  $options = array();
  foreach ($types AS $name => $type) {
    $options[$name] = $type->name;
  }
  
  $form['delete_all_nodes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Delete all nodes'),
    '#default_value' => isset($data['delete_all_nodes']) ? $data['delete_all_nodes'] : 1,
  );
  
  $form['content_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types'),
    '#options' => $options,
    '#default_value' => isset($data['content_types']) ? $data['content_types'] : array(),
  );
  
  return $form;
}

function enterprise_config_wizard_site_reset_nodes_submit($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  $values = $form_state['values'];
  
  $batch_count = 10;
  $limit = 100;
  for($c = 0; $c < $limit; $c += $batch_count ) {
    $query = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->range(0, $batch_count);
    $nids = $query->execute()->fetchAllAssoc('nid');
    if (!count($nids)) {
      break;
    }
    $nids = array_keys($nids);
    
    node_delete_multiple($nids);
    
dsm($nids);
    
  
  }
}

function enterprise_config_wizard_environment_setup_options($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  
  $form['options'] = array(
    '#tree' => TRUE,
  );
  
  
  if ($data['name'] == 'local_tom') {
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
  
  $modules = array();
  if ($data['name'] == 'local_tom') {
    variable_set('googleanalytics_account', 'UA-5541069-18');
    variable_set('intel_ga_account', 'UA-5541069-9');
    variable_set('intel_apikey', 'd6dda05523c6c79a73cb63d230a73f9c');
    variable_set('intel_domain_name', '');
    if ($data['options']['intel_src'] == 'local') {
      
      variable_set('intel_l10iapi_url', 'lvlt_api.localhost:8082/v1/intel');
      variable_set('intel_l10iapi_connector', 'C:\Documents\Working\lvlt7/api/v1/intel/connector_local.php');
    }
    else {
      variable_set('intel_l10iapi_url', '');
      variable_set('intel_l10iapi_connector', '');    
    }
    $modules['devel'] = 1;
    $modules['dblog'] = 1;
    $modules['performance'] = 1;
    $modules['overlay'] = 1;
    config_module_enable_disable($modules);
  }
}