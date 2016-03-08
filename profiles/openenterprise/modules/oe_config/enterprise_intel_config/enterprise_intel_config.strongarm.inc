<?php
/**
 * @file
 * enterprise_intel.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_intel_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_pages';
  $strongarm->value = 'admin
admin/*
batch
node/add*
node/*/edit
node/*/analytics
node/*/blocks
node/*/devel
node/*/webform
node/*/webform-results
user/*/*';
  $export['googleanalytics_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_intel_scripts_enabled';
  $strongarm->value = array(
    'addthis' => 'addthis',
    'youtube' => 'youtube',
  );
  $export['intel_intel_scripts_enabled'] = $strongarm;

  return $export;
}
