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
  $strongarm->name = 'gridmagic';
  $strongarm->value = array(
    'bella' => array(
      'navigation' => 'disabled',
      'header' => 'disabled',
      'highlighted' => 'disabled',
      'help' => 'disabled',
      'content' => 'disabled',
      'sidebar_first' => 'disabled',
      'sidebar_second' => 'disabled',
      'footer' => 'auto_1-4',
      'footer_bottom' => 'disabled',
      'page_top' => 'disabled',
      'page_bottom' => 'disabled',
    ),
  );
  $export['gridmagic'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'less_engine';
  $strongarm->value = 'less.php';
  $export['less_engine'] = $strongarm;

  return $export;
}
