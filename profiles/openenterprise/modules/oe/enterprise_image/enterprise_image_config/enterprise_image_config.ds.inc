<?php
/**
 * @file
 * enterprise_image.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enterprise_image_config_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_image|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_image';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'unpublished' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'submit_info' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'prev_next_node' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'social_media_share_buttons' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|enterprise_image|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_image|mini';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_image';
  $ds_fieldsetting->view_mode = 'mini';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
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
  $export['node|enterprise_image|mini'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_image|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_image';
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
    'submit_info' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|enterprise_image|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_image|teaser_stacked';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_image';
  $ds_fieldsetting->view_mode = 'teaser_stacked';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'exclude node title settings' => '0',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
        'field_delimiter' => '',
        'field_formatter_class' => 'thumbnail',
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
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|enterprise_image|teaser_stacked'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enterprise_image_config_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_image|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_image';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'submit_info',
      ),
      'sticky' => array(
        1 => 'social_media_share_buttons',
        2 => 'prev_next_node',
      ),
      'middle' => array(
        3 => 'field_image',
        4 => 'body',
        5 => 'unpublished',
      ),
      'footer' => array(
        6 => 'field_tags',
      ),
    ),
    'fields' => array(
      'submit_info' => 'header',
      'social_media_share_buttons' => 'sticky',
      'prev_next_node' => 'sticky',
      'field_image' => 'middle',
      'body' => 'middle',
      'unpublished' => 'middle',
      'field_tags' => 'footer',
    ),
    'classes' => array(
      'layout_class' => array(),
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
  $export['node|enterprise_image|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_image|mini';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_image';
  $ds_layout->view_mode = 'mini';
  $ds_layout->layout = 'bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
      ),
      'middle' => array(
        1 => 'field_image',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_image' => 'middle',
    ),
    'classes' => array(
      'layout_class' => array(),
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
  $export['node|enterprise_image|mini'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_image|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_image';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_2col_fluid_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'submit_info',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title' => 'right',
      'submit_info' => 'right',
      'body' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(),
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
  $export['node|enterprise_image|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_image|teaser_stacked';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_image';
  $ds_layout->view_mode = 'teaser_stacked';
  $ds_layout->layout = 'bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'middle' => array(
        0 => 'field_image',
      ),
      'header' => array(
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_image' => 'middle',
      'title' => 'header',
    ),
    'classes' => array(
      'layout_class' => array(),
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
  $export['node|enterprise_image|teaser_stacked'] = $ds_layout;

  return $export;
}
