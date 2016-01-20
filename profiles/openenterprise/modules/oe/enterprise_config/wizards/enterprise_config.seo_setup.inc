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
	$wizard = $config['wizard_info'];
	$config_data = $config['wizard_data'];
dsm($config_data);
	if (empty($config_data['analytics']['level'])) {
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

function enterprise_config_config_wizard_analytics_setup_intel($form, $form_state) {
  $config = $form_state['config'];
  $wizard = $config['wizard_info'];
  $config_data = $config['wizard_data'];

  if (empty($config_data['analytics']['level']) || ($config_data['analytics']['level'] == 'ga_basic')) {
    $next = config_get_wizard_next_step_path($wizard, $config['step_n'], $config['substep_n'], TRUE);
    drupal_goto($next);
  }
  $config_data = $form_state['config']['wizard_data'];
  $help = t('Open Enterprise provides both essential SEO features and a suite of advanced SEO Tools.');
  $help .= ' ' . t('If search engine traffic is important for your website we recommend enabling the advanced tools.');
  $form[] = array(
    '#markup' => $help,
  ); 
  $options = array(
    'basic' => t('Enable essential SEO features only'),
    'advanced' => t('Enable essential SEO features and advanced SEO Tools')
  ); 
  $form['seo']['level'] = array(
    '#type' => 'radios',
    '#title' => t('Level'),
    '#options' => $options,
    '#default_value' => isset($config['seo']['level']) ? $config['seo']['level'] : 'advanced',
  );
  
  return $form;
}

function enterprise_config_config_wizard_install_seo_metatag($form, $form_state) {
  $form[] = array(
    '#markup' => t('Do config settings.'),
  );
  
  $modules = array(
    'metatag' => 1,
  );
  config_module_enable_disable($modules);
  
  include_once drupal_get_path('module', 'metatag') . '/metatag.admin.inc';
  
  $config = metatag_config_load('global');
  $f = metatag_config_edit_form(array(), $form_state, $config);
dsm($f);

  $f['actions']['save']['#value'] = t('Save global meta tags');
  unset($f['actions']['cancel']);
  //unset($f['#theme']);
  //unset($f['#submit']);
  $form = array_merge($form, $f);
  $form['#submit'][] = 'seo_setup_1_form_submit';
  
  return $form;
}

function enterprise_config_wizard_install_3_3_access() {
	$data = config_wizard_data_init('install');
	if (isset($data['seo']) && isset($data['seo']['level']) && ($data['seo']['level'] == 'advanced')) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

function enterprise_config_config_wizard_install_3_3($form, $form_state) {
  $form[] = array(
    '#markup' => t('Do config settings.'),
  );  
  
  return $form;
}