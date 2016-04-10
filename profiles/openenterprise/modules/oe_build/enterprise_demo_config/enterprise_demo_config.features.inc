<?php
/**
 * @file
 * enterprise_demo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_demo_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "deploy" && $api == "deploy_plans") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_intel_phonenumber_defaults().
 */
function enterprise_demo_config_intel_phonenumber_defaults() {
  $data = array(
    'main' => array(
      'title' => 'Main Phone',
      'description' => '',
      'number' => '+12145551212.',
      'number_display' => '(214) 555-1212',
      'handling_forwarding_number' => '',
      'handling_twiml' => '',
      'track_phonecall' => '',
      'track_phonecall_value' => '',
      'send_sms' => '',
      'custom' => 1,
      'key' => 'main',
    ),
  );
  return $data;
}
