<?php
/**
 * @file
 * enterprise_press.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enterprise_press_config_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_press_release|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_press_release';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'social_media_share_buttons' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|enterprise_press_release|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_press_release|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_press_release';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'field_delimiter' => '',
        'field_formatter_class' => '',
        'conditions' => array(),
      ),
    ),
    'date_stacked' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|enterprise_press_release|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enterprise_press_config_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_press_release|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_press_release';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'sticky' => array(
        0 => 'social_media_share_buttons',
      ),
      'middle' => array(
        1 => 'body',
        2 => 'field_press_pdf',
      ),
    ),
    'fields' => array(
      'social_media_share_buttons' => 'sticky',
      'body' => 'middle',
      'field_press_pdf' => 'middle',
    ),
    'classes' => array(
      'layout_class' => array(
        'style-press-full' => 'style-press-full',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'sticky' => 'div',
      'middle' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|enterprise_press_release|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_press_release|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_press_release';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_2_10';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'date_stacked',
      ),
      'right' => array(
        1 => 'title',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'date_stacked' => 'left',
      'title' => 'right',
      'body' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'style-press-teaser' => 'style-press-teaser',
      ),
      'left' => array(
        'col-md-2' => 'col-md-2',
      ),
      'right' => array(
        'col-md-10' => 'col-md-10',
      ),
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
  $export['node|enterprise_press_release|teaser'] = $ds_layout;

  return $export;
}
