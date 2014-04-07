<?php

/**
 * @file
 */

function config_webform_component($name) {
	$comps = config_webform_components();
	$comp = $comps[$name];
	
	drupal_alter('config_webform_component', $comp, $name);
	
	return $comp;
}

function config_webform_components() {
  $comps['email'] = array(
	  'name' => 'Email',
	  'form_key' => 'email',
	  'type' => 'email',
	  'mandatory' => 1,
	  'weight' => 25,
	  'pid' => 0,
	  'extra' => array(
	    'title_display' => 'inline',
	    'private' => 0,
	  ),
	);	
	$comps['first_name'] = array(
	  'name' => 'First name',
	  'form_key' => 'first_name',
	  'type' => 'textfield',
	  'mandatory' => 1,
	  'weight' => 10,
	  'pid' => 0,
	  'extra' => array(
	    'title_display' => 'inline',
	    'private' => 0,
	  ),	
	);
  $comps['last_name'] = array(
    'name' => 'Last name',
    'form_key' => 'last_name',
    'type' => 'textfield',
    'mandatory' => 1,
    'weight' => 10,
    'pid' => 0,
    'extra' => array(
      'title_display' => 'inline',
      'private' => 0,
    ),  
  );
	
  drupal_alter('config_webform_components', $comps);
  
	return $comps;
}