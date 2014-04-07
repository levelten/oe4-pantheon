<?php
/**
 * @file
 * oedemo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oedemo_ctools_plugin_api($module = NULL, $api = NULL) {
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
function oedemo_intel_phonenumber_defaults() {
  $data = array(
    'main' => array(
      'title' => 'Main contact number',
      'description' => '',
      'number' => '+14698046069',
      'number_display' => '469.804.6069',
      'handling_forwarding_number' => '+12148878586',
      'handling_twiml' => '',
      'track_phonecall' => 'goal_contact-call',
      'track_phonecall_value' => '',
      'send_sms' => '',
      'custom' => 1,
      'key' => 'main',
    ),
  );
  return $data;
}

/**
 * Implements hook_default_mailchimp_list().
 */
function oedemo_default_mailchimp_list() {
  $items = array();
  $items['open_enterprise_updates'] = entity_import('mailchimp_list', '{
    "name" : "open_enterprise_updates",
    "mc_list_id" : "70298b4268",
    "label" : "Main",
    "description" : "",
    "settings" : {
      "roles" : { "2" : 2, "1" : 1 },
      "mergefields" : {
        "EMAIL" : "mail",
        "FNAME" : "field-firstname",
        "LNAME" : "field-lastname",
        "L10I_VURL" : "",
        "L10I_SCORE" : ""
      },
      "mergefields_display" : {
        "EMAIL" : true,
        "FNAME" : 0,
        "LNAME" : 0,
        "L10I_VURL" : 0,
        "L10I_SCORE" : 0
      },
      "doublein" : 0,
      "show_register_form" : 0,
      "default_register_form_optin" : 0,
      "show_account_form" : 0,
      "form_label" : "",
      "submit_label" : "Subscribe!",
      "include_interest_groups" : 0,
      "opt_in_interest_groups" : 0,
      "interest_groups_label" : "Interest Groups",
      "cron" : 0,
      "webhooks" : 0,
      "allow_anonymous" : 1,
      "required" : 1
    },
    "entity_type" : "mailchimp_list",
    "slug" : ""
  }');
  return $items;
}
