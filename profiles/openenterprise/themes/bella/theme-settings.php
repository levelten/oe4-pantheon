<?php

function bella_form_system_theme_settings_alter(&$form, &$form_state) {
	$form['general']['#weight'] = -8;

	$form['bella'] = array(
		'#type' => 'vertical_tabs',
		'#prefix' => '<h2><small>Bella</small></h2>',
		'#weight' => -9,
	);

	$form['bella_config'] = array(
		'#type' => 'fieldset',
		'#group' => 'bella',
		'#title' => t('Kuler JSON'),
		'#description' => t('Adding in text for JSON Kuler'),
	);
	$form['bella_config']['bella_kuler'] = array(
		'#type' => 'checkbox',
		'#title' => t('Use Kuler?'),
		'#default_value' => theme_get_setting('bella_kuler'),
		'#options' => array(
			0 => t('No'),
			1 => t('Yes'),
		),
		'#description' => t('Checking this will replace the current color schemes with those provided by the Kuler JSON.'),
	);
	$form['bella_config']['bella_kuler_json'] = array(
		'#type' => 'textarea',
		'#title' => t('Kuler JSON'),
		'#default_value' => theme_get_setting('bella_kuler_json'),
		'#description' => t('If you have Kuler JSON, you can enter it here to provide theme color options. You can get Kuler JSON by using this gist: !gist', array('!gist' => l('Kuler JSON Gist', 'https://gist.github.com/kyletaylored/1a2edba96509277cfcca', array('attributes' => array('target' => '_blank',))))),
	);
	
}
