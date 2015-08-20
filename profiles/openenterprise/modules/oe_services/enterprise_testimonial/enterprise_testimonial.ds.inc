<?php
/**
 * @file
 * enterprise_testimonial.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function enterprise_testimonial_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_testimonial|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_testimonial';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_firstname',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_firstname' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|enterprise_testimonial|teaser'] = $ds_layout;

  return $export;
}
