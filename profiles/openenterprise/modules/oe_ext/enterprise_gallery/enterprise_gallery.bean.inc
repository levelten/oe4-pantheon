<?php
/**
 * @file
 * enterprise_gallery.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function enterprise_gallery_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'enterprise_gallery';
  $bean_type->label = 'Enterprise Gallery';
  $bean_type->options = '';
  $bean_type->description = 'A Bean featuring an image field with multiple uploads.';
  $export['enterprise_gallery'] = $bean_type;

  return $export;
}
