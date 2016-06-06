<?php
/**
 * @file
 * enterprise_coupon.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function enterprise_coupon_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'coupon';
  $bean_type->label = 'Coupon';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['coupon'] = $bean_type;

  return $export;
}
