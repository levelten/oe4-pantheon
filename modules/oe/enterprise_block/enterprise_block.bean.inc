<?php
/**
 * @file
 * enterprise_block.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function enterprise_block_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'basic_block';
  $bean_type->label = 'Basic block';
  $bean_type->options = '';
  $bean_type->description = 'A general exportable block';
  $export['basic_block'] = $bean_type;

  return $export;
}
