<?php

function bella_form_system_theme_settings_alter(&$form, &$form_state) {

	$form['kuler_settings'] = array(
		'#type' => 'fieldset',
		'#title' => t('Adobe Kuler Settings'),
		'#description' => t('Adding in text for JSON Kuler'),
		'#weight' => -1,
	);
	$form['kuler_settings']['kuler_check'] = array(
		'#type' => 'checkbox',
		'#title' => t('Use Adobe Kuler?'),
		'#default_value' => theme_get_setting('kuler_check'),
		'#options' => array(
			0 => t('No'),
			1 => t('Yes'),
		),
		'#description' => t('Checking this will replace the current color schemes with those provided by the Kuler JSON.'),
	);
	$form['kuler_settings']['kuler_json'] = array(
		'#type' => 'textarea',
		'#title' => t('Kuler JSON'),
		'#default_value' => theme_get_setting('kuler_json'),
		'#description' => t('If you have Kuler JSON, you can enter it here to provide theme color options. You can get Kuler JSON by using this gist: !gist', array('!gist' => l('Kuler JSON Gist', 'https://gist.github.com/kyletaylored/1a2edba96509277cfcca', array('attributes' => array('target' => '_blank',))))),
	);

	$form['colourlovers_settings'] = array(
		'#type' => 'fieldset',
		'#title' => t('COLOURLovers Settings'),
		'#weight' => -1,
	);
	$form['colourlovers_settings']['colourlovers_check'] = array(
		'#type' => 'checkbox',
		'#title' => t('Enable COLOURLovers palettes'),
		'#default_value' => theme_get_setting('colourlovers_check'),
		'#options' => array(
			0 => t('No'),
			1 => t('Yes'),
		),
		'#description' => t('Checking this will replace the current color schemes with those provided by the !colourlover.', array('!colourlover' => l('COLOURLovers API', 'admin/appearance/colourlovers'))),
	);
	$form['colourlovers_settings']['colourlovers_demo'] = array(
  	'#markup' => variable_get('colourlovers_demo_html', 'No palettes generated.'),
  );
  
}
