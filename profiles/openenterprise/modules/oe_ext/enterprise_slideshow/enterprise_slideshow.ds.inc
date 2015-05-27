<?php
/**
 * @file
 * enterprise_slideshow.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enterprise_slideshow_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|enterprise_slideshow|default';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'enterprise_slideshow';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_enterprise_slides' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['bean|enterprise_slideshow|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|enterprise_slideshow|enterprise_slideshow_arrow';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'enterprise_slideshow';
  $ds_fieldsetting->view_mode = 'enterprise_slideshow_arrow';
  $ds_fieldsetting->settings = array(
    'field_enterprise_slides' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['bean|enterprise_slideshow|enterprise_slideshow_arrow'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|enterprise_slideshow|enterprise_slideshow_pager';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'enterprise_slideshow';
  $ds_fieldsetting->view_mode = 'enterprise_slideshow_pager';
  $ds_fieldsetting->settings = array(
    'field_enterprise_slides' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['bean|enterprise_slideshow|enterprise_slideshow_pager'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_enterprise_slides|full';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_enterprise_slides';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_enterprise_slideshow_desc' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'slide-desc',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_enterprise_slideshow_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_enterprise_slideshow_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'slide-button',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_enterprise_slideshow_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h3',
          'ow-cl' => 'slide-title',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['field_collection_item|field_enterprise_slides|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enterprise_slideshow_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|enterprise_slideshow|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'enterprise_slideshow';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_enterprise_slide_class',
        1 => 'field_enterprise_slides',
      ),
    ),
    'fields' => array(
      'field_enterprise_slide_class' => 'ds_content',
      'field_enterprise_slides' => 'ds_content',
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
  $export['bean|enterprise_slideshow|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|enterprise_slideshow|enterprise_slideshow_arrow';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'enterprise_slideshow';
  $ds_layout->view_mode = 'enterprise_slideshow_arrow';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_enterprise_slide_class',
        1 => 'field_enterprise_slides',
      ),
    ),
    'fields' => array(
      'field_enterprise_slide_class' => 'ds_content',
      'field_enterprise_slides' => 'ds_content',
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
  $export['bean|enterprise_slideshow|enterprise_slideshow_arrow'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|enterprise_slideshow|enterprise_slideshow_pager';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'enterprise_slideshow';
  $ds_layout->view_mode = 'enterprise_slideshow_pager';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_enterprise_slide_class',
        1 => 'field_enterprise_slides',
      ),
    ),
    'fields' => array(
      'field_enterprise_slide_class' => 'ds_content',
      'field_enterprise_slides' => 'ds_content',
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
  $export['bean|enterprise_slideshow|enterprise_slideshow_pager'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_enterprise_slides|full';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_enterprise_slides';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_enterprise_slideshow',
        1 => 'field_enterprise_slideshow_title',
        2 => 'group_desktop_image',
        3 => 'field_enterprise_slideshow_desc',
        4 => 'group_mobile_image',
        5 => 'field_enterprise_slideshow_image',
        6 => 'field_enterprise_slideshow_mobi',
        7 => 'field_enterprise_slideshow_link',
      ),
    ),
    'fields' => array(
      'group_enterprise_slideshow' => 'ds_content',
      'field_enterprise_slideshow_title' => 'ds_content',
      'group_desktop_image' => 'ds_content',
      'field_enterprise_slideshow_desc' => 'ds_content',
      'group_mobile_image' => 'ds_content',
      'field_enterprise_slideshow_image' => 'ds_content',
      'field_enterprise_slideshow_mobi' => 'ds_content',
      'field_enterprise_slideshow_link' => 'ds_content',
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
  $export['field_collection_item|field_enterprise_slides|full'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function enterprise_slideshow_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'enterprise_slideshow_arrow';
  $ds_view_mode->label = 'Enterprise Slideshow Arrow';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
  );
  $export['enterprise_slideshow_arrow'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'enterprise_slideshow_pager';
  $ds_view_mode->label = 'Enterprise Slideshow Pager';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
  );
  $export['enterprise_slideshow_pager'] = $ds_view_mode;

  return $export;
}
