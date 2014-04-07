<?php

function enterprise_config_config_wizard_analytics_setup($form, $form_state) {
  $config_data = $form_state['config']['wizard_data'];
  $help = t('Open Enterprise recommends tracking site metrics using Google Analytics.');
  $help .= ' ' . t('If search engine traffic is important for your website we recommend enabling the advanced tools.');
  $form['main'] = array(
    '#markup' => $help,
    '#editable' => 1,
  ); 
  $options = array(
    '' => t('Do not enable Google Analtyics tracking'),
    'ga_basic' => t('Enable basic Google Analytics tracking'),
    'ga_intel' => t('Enable advanced Google Analtyics and LevelTen Intelligence tracking'),
  ); 
  $form['analytics'] = array(
    '#tree' => TRUE,
  );
  $form['analytics']['level'] = array(
    '#type' => 'radios',
    '#title' => t('Level'),
    '#options' => $options,
    '#default_value' => isset($config['analytics']['level']) ? $config['analytics']['level'] : 'ga_intel',
  );
  
  return $form;
}

function enterprise_config_config_wizard_analytics_setup_basic($form, $form_state) {
  $config = $form_state['config'];
  $wizard = $config['wizard'];
  $config_data = $config['wizard_data'];
  
  $validate = enterprise_config_config_wizard_analytics_setup_basic_validate($form, $form_state);
  $validated = !(form_get_errors());
  form_clear_error();
  
  
  $errors = config_check_validate_func('enterprise_config_config_wizard_analytics_setup_basic_validate', $form, $form_state); 
  //$validated = empty(config_check_validate_func('enterprise_config_config_wizard_analytics_setup_basic_validate', $form, $form_state));
  
	if (empty($errors) || empty($config_data['analytics']['level'])) {
		$next = config_get_wizard_next_step_path($wizard, $config['step_n'], $config['substep_n'], TRUE);
		drupal_goto($next);
	}

  $modules = array(
    'googleanalytics' => 1,
  );
  config_module_enable_disable($modules);	
	$help = '';
  $form['main'] = array(
    '#markup' => $help,
  ); 
  return $form;
}

function enterprise_config_config_wizard_analytics_setup_basic_validate($form, $form_state) {
  $config = $form_state['config'];
  $wizard = $config['wizard'];
  $config_data = $config['wizard_data'];
  
  $gaid = variable_get('googleanalytics_account', '');
  if (!$gaid) {
    $msg = t('Please enter a valid Google Analtyics tracking id before proceeding.');
    form_set_error('main', $msg);
  }
}

function enterprise_config_config_wizard_analytics_setup_intel($form, $form_state) {
  $config = $form_state['config'];
  $wizard = $config['wizard'];
  $config_data = $config['wizard_data'];

  if (empty($config_data['analytics']['level']) || ($config_data['analytics']['level'] == 'ga_basic')) {
    $next = config_get_wizard_next_step_path($wizard, $config['step_n'], $config['substep_n'], TRUE);
    drupal_goto($next);
  }
  $config_data = $form_state['config']['wizard_data'];
  
  $modules = array(
    'google_analytics_api' => 1,
    'intel' => 1,
  );
  config_module_enable_disable($modules); 
  
  $items = array();
  $items[] = t('Create a second Google Analtyics tracking id');
  $items[] = t('Get a @linkLevelTen Intelligence api key');
  
  //$form[] = array(
  //  '#markup' => theme('item_list', array('items' => $items, 'type' => 'ol')),
 // );
  
  return $form;
}

function enterprise_config_analytics_setup_form_alter(&$form, &$form_state, $form_id) {
//dsm($form_id);
  if ($form_id == 'googleanalytics_admin_settings_form') {
    $form['tracking']['#type'] = '';
    $show = array('domain_tracking');
    foreach ($form['tracking'] AS $k => $v) {
      if ((substr($k, 0 , 1) != '#') && !in_array($k, $show)) {
        hide($form['tracking'][$k]);
      }
    }
    hide($form['googleanalytics_custom_var']);
    hide($form['advanced']);
  }
  else if ($form_id == 'intel_admin_settings') {
//dsm($form);
    $ga_domain_mode = variable_get('googleanalytics_domain_mode', '');
//dsm($GLOBALS);
    if ($ga_domain_mode) {
      $a = explode('//', $GLOBALS['base_root']);
      $domain = $a[1];
      $form['tracking']['intel_domain_name']['#default_value'] = $domain;
    }
    hide($form['reports']);
    hide($form['l10iapi']['advanced']);
  }
  else if ($form_id == 'google_analytics_api_admin') {
    if (isset($form['ga']) && isset($form['ga']['google_analytics_reports_profile_id'])) {
      $options = $form['ga']['google_analytics_reports_profile_id']['#options'];
      $intel_ga_account = variable_get('intel_ga_account', '');
      foreach ($options AS $key => $value) {
        $a = explode(' - ', $value);
        if ($a[1] == $intel_ga_account) {
          $form['ga']['google_analytics_reports_profile_id']['#default_value'] = $key;
          $form['ga']['google_analytics_reports_cache_length']['#default_value'] = 86400;
          break;
        }
      }
      hide($form['revoke']);
//dsm($intel_ga_account);      
    }
//dsm($form);    
  }
  else if ($form_id == 'intel_admin_scoring') {
//dsm($form);
    hide($form['targets']);
    hide($form['scores']);
    $form['advanced']['#title'] = t('Goal settings');
    $form['advanced']['#collapsed'] = FALSE;
  }
}