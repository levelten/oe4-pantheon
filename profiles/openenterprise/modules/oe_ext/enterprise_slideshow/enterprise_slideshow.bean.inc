<?php
/**
 * @file
 * enterprise_slideshow.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function enterprise_slideshow_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'enterprise_slideshow';
  $bean_type->label = 'Slideshow';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['enterprise_slideshow'] = $bean_type;

  return $export;
}
