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
