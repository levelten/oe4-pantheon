<?php

/**
 * Include common functions used through out theme.
 */

function bella_form_system_theme_settings_alter(&$form, &$form_state) {

	$default_settings = array();

	$filename = DRUPAL_ROOT . '/' . drupal_get_path('theme', 'project') . '/project.info';
	$info = drupal_parse_info_file($filename);
	if (isset($info['settings'])) {
		$default_settings = $info['settings'];
	}

	$form['bella'] = array(
		'#type' => 'vertical_tabs',
		'#prefix' => '<h2><small>Bella</small></h2>',
		'#weight' => -8,
	);

	$form['bella'] = array(
		'#type' => 'fieldset',
		'#group' => 'bella',
		'#title' => t('Display'),
		'#attributes' => array(
	    'class' => array('columns'),
	  ),
	);

	$form['bella']['bella_buttons'] = array(
		'#title' => t('Bella Buttons'),
		'#description' => t('Enable fancy Bella buttons (transparent outlines)'),
		'#type' => 'checkbox',
		'#default_value' => theme_get_setting('bella_buttons'),
	);

}