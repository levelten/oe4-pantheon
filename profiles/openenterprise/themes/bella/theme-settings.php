<?php

function bella_form_system_theme_settings_alter(&$form, &$form_state) {

	$form['colourlovers_settings'] = array(
		'#type' => 'fieldset',
		'#title' => t('COLOURLovers Settings'),
		'#weight' => -1,
	);
	$form['colourlovers_settings']['colourlovers_check'] = array(
		'#type' => 'checkbox',
		'#title' => t('Enable COLOURLovers palettes'),
		'#default_value' => theme_get_setting('colourlovers_check'),
		'#description' => t('Checking this will replace the current color schemes with those provided by the !colourlover.', array('!colourlover' => l('COLOURLovers API', 'admin/appearance/colourlovers'))),
	);
	$form['colourlovers_settings']['colourlovers_container'] = array(
		'#type' => 'container',
  	'#states' => array(
			'visible' => array(
				':input[name="colourlovers_check"]' => array('checked' => TRUE),
			),
		),
	);
	$form['colourlovers_settings']['colourlovers_container']['colourlovers_demo'] = array(
		'#type' => 'markup',
  	'#markup' => variable_get('colourlovers_demo_html', 'No palettes generated.'),
  );

}
