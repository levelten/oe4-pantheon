<?php
/**
 * @file
 * enterprise_theme.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_theme_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'less_engine';
  $strongarm->value = 'less.php';
  $export['less_engine'] = $strongarm;

  return $export;
}
