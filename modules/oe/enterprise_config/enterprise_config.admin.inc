<?php

function enterprise_config_admin_accounts_page() {
	$output = array();
	
  $accounts = variable_get('config_var_accounts', array());
  
  $output = config_render_array_data($accounts);
	
	return $output;
}

function config_render_array_data($data, $level = 0) {
  $output = '';
  $items = array();
  foreach ((array) $data AS $key => $value) {
    if (is_array($value)) {
      $items[] = '<label>' . $key . ':';
      $items[] = config_render_array_data($value, ($level+1));
    }
    else {
      $items[] = '<label>' . $key . ':</label> ' . $value;
    }
  }
  $output = theme('item_list', array('items' => $items));
  return $output;
}