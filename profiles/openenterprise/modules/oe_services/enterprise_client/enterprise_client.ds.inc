<?php
/**
 * @file
 * enterprise_client.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enterprise_client_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_client|mini';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_client';
  $ds_fieldsetting->view_mode = 'mini';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
        'exclude node title settings' => '0',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
        'field_delimiter' => '',
        'field_formatter_class' => '',
        'conditions' => array(),
        'linked_field' => array(
          'linked' => 0,
          'destination' => '',
          'advanced' => array(
            'title' => '',
            'target' => '',
            'class' => '',
            'rel' => '',
            'text' => '',
          ),
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|enterprise_client|mini'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enterprise_client_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_client|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_client';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_3_9';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'body',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'body' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|enterprise_client|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_client|mini';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_client';
  $ds_layout->view_mode = 'mini';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'title' => 'ds_content',
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
  $export['node|enterprise_client|mini'] = $ds_layout;

  return $export;
}
