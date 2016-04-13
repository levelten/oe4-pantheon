<?php
/**
 * @file
 * enterprise_work_config.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enterprise_work_config_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_work|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_work';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'enterprise_custom_1' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'custom_markup' => '<h3>Testimonials</h3>',
        'ft' => array(),
        'field_delimiter' => '',
        'field_formatter_class' => '',
        'conditions' => array(
          0 => array(
            'condition' => 'hide_if_empty',
            'configuration' => array(
              'target' => 'field_testimonial',
            ),
          ),
        ),
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
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_testimonial' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'DS Label',
        ),
      ),
    ),
  );
  $export['node|enterprise_work|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_work|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_work';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'exclude node title settings' => '1',
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
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|enterprise_work|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enterprise_work_config_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_work|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_work';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_2col_fluid_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_image',
      ),
      'left' => array(
        1 => 'field_client',
        2 => 'field_service_types',
        3 => 'field_service_areas',
        4 => 'field_tags',
      ),
      'right' => array(
        5 => 'body',
        6 => 'enterprise_custom_1',
        7 => 'field_testimonial',
      ),
    ),
    'fields' => array(
      'field_image' => 'header',
      'field_client' => 'left',
      'field_service_types' => 'left',
      'field_service_areas' => 'left',
      'field_tags' => 'left',
      'body' => 'right',
      'enterprise_custom_1' => 'right',
      'field_testimonial' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(),
      'left' => array(
        'col-md-4' => 'col-md-4',
      ),
      'right' => array(
        'col-md-8' => 'col-md-8',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|enterprise_work|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_work|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_work';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_5_7';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'body',
        3 => 'field_testimonial',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title' => 'right',
      'body' => 'right',
      'field_testimonial' => 'right',
    ),
    'limit' => array(
      'field_testimonial' => '1',
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
  $export['node|enterprise_work|teaser'] = $ds_layout;

  return $export;
}
