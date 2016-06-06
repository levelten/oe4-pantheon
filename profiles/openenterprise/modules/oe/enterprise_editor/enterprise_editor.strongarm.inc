<?php
/**
 * @file
 * enterprise_editor.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_editor_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enterprise_editor_bootstrap_css';
  $strongarm->value = 0;
  $export['enterprise_editor_bootstrap_css'] = $strongarm;

  return $export;
}
