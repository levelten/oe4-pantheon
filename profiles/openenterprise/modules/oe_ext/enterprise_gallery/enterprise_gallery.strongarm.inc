<?php
/**
 * @file
 * enterprise_gallery.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_gallery_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'slick_admin_css';
  $strongarm->value = 0;
  $export['slick_admin_css'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'slick_css';
  $strongarm->value = 1;
  $export['slick_css'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'slick_module_css';
  $strongarm->value = 1;
  $export['slick_module_css'] = $strongarm;

  return $export;
}
