<?php
/**
 * @file
 * oedemo.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function oedemo_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_domain';
  $strongarm->value = 'oeprodemo';
  $export['disqus_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_userapikey';
  $strongarm->value = 'diqhvu3KoFqvXAEfuD1HTO1LVJMc5dzDD1Cuk9k40r7PYP4P51SgrAaK0PiTATqi';
  $export['disqus_userapikey'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_account';
  $strongarm->value = 'UA-5541069-14';
  $export['googleanalytics_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_analytics_reports_oauth_token';
  $strongarm->value = '1/HqRXLE6E9pfARlOCLgQcj90EBJNkcazufNzcJ-nVjA4';
  $export['google_analytics_reports_oauth_token'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_analytics_reports_oauth_token_secret';
  $strongarm->value = 'zfOVnpko5AEO5scloBiVmJxt';
  $export['google_analytics_reports_oauth_token_secret'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_analytics_reports_profile_id';
  $strongarm->value = '20773980';
  $export['google_analytics_reports_profile_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_apikey';
  $strongarm->value = 'e84cac6f1c6640dbd143755675fb05b0';
  $export['intel_apikey'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_api_level';
  $strongarm->value = 'pro';
  $export['intel_api_level'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_extended_mode';
  $strongarm->value = 1;
  $export['intel_extended_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_ga_account';
  $strongarm->value = 'UA-5541069-16';
  $export['intel_ga_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_mailchimp_default_list_id';
  $strongarm->value = '70298b4268';
  $export['intel_mailchimp_default_list_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_track_phonecalls';
  $strongarm->value = 1;
  $export['intel_track_phonecalls'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_visitor_attributes_custom_i';
  $strongarm->value = array(
    'title' => 'Interests',
    'description' => 'Used to value a visitors interest in various items.',
    'type' => 'vector',
    'custom_options' => array(
      'ux' => array(
        'title' => 'UX
',
        'description' => '',
      ),
      'm' => array(
        'title' => 'Mobile
',
        'description' => '',
      ),
      'dr' => array(
        'title' => 'Drupal
',
        'description' => '',
      ),
      'c' => array(
        'title' => 'Content
',
        'description' => '',
      ),
      'sm' => array(
        'title' => 'Social media
',
        'description' => '',
      ),
      't' => array(
        'title' => 'Traffic
',
        'description' => '',
      ),
      'l' => array(
        'title' => 'Leads
',
        'description' => '',
      ),
      'a' => array(
        'title' => 'Analytics
',
        'description' => '',
      ),
    ),
    'selectable' => 1,
    'module' => 'intel',
    'options' => array(
      'ux' => array(
        'title' => 'UX
',
        'description' => '',
      ),
      'm' => array(
        'title' => 'Mobile
',
        'description' => '',
      ),
      'dr' => array(
        'title' => 'Drupal
',
        'description' => '',
      ),
      'c' => array(
        'title' => 'Content
',
        'description' => '',
      ),
      'sm' => array(
        'title' => 'Social media
',
        'description' => '',
      ),
      't' => array(
        'title' => 'Traffic
',
        'description' => '',
      ),
      'l' => array(
        'title' => 'Leads
',
        'description' => '',
      ),
      'a' => array(
        'title' => 'Analytics',
        'description' => '',
      ),
    ),
    'key' => 'i',
  );
  $export['intel_visitor_attributes_custom_i'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mailchimp_api_key';
  $strongarm->value = 'f55c733a7e69720740dfce566df455a8-us3';
  $export['mailchimp_api_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'twilio_account';
  $strongarm->value = 'AC1595656bb4c91d783d7aa59d9912be39';
  $export['twilio_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'twilio_number';
  $strongarm->value = '+14698046069';
  $export['twilio_number'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'twilio_token';
  $strongarm->value = 'ef21fa23066b3e9f436561605e880856';
  $export['twilio_token'] = $strongarm;

  return $export;
}
