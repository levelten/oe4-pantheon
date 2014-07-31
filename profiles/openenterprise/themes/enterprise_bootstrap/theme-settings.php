<?php

function enterprise_bootstrap_form_system_theme_settings_alter(&$form, &$form_state) {
	$form['general']['#weight'] = -8;

	$form['enterprise_bootstrap'] = array(
		'#type' => 'vertical_tabs',
		'#prefix' => '<h2><small>Enterprise Bootstrap</small></h2>',
		'#weight' => -9,
	);

	$form['enterprise_bootstrap_config'] = array(
		'#type' => 'fieldset',
		'#group' => 'enterprise_bootstrap',
		'#title' => t('Display settings'),
		'#description' => t('Full width, block striping, etc.'),
	);
	$form['enterprise_bootstrap_config']['enterprise_bootstrap_front_blocks'] = array(
		'#type' => 'select',
		'#title' => t('Front Block Striping'),
		'#options' => array(
			0 => t('No'),
			1 => t('Yes'),
		),
		'#default_value' => theme_get_setting('enterprise_bootstrap_front_blocks'),
		'#description' => t('If Yes, this will turn the blocks on the front page into full-width containers for horizontal striping.'),
	);

}
