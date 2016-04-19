<?php
/**
 * @file
 * enterprise_landingpage_config.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enterprise_landingpage_config_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_landingpage|conversion_cta_footer';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_landingpage';
  $ds_fieldsetting->view_mode = 'conversion_cta_footer';
  $ds_fieldsetting->settings = array(
    'cta_landingpage_referenced' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:1:{s:7:"context";a:1:{i:0;s:25:"argument_entity_id:node_1";}}s:4:"type";s:11:"views_panes";s:7:"subtype";s:38:"enterprise_landingpage_cta-pane_footer";}',
        'load_terms' => 0,
        'ft' => array(),
        'field_delimiter' => '',
        'field_formatter_class' => '',
        'conditions' => array(
          0 => array(
            'condition' => 'hide_not_empty',
            'configuration' => array(
              'target' => 'field_landingpage_cta_footer',
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
    'field_landingpage_cta_footer' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|enterprise_landingpage|conversion_cta_footer'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_landingpage|conversion_cta_sidebar';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_landingpage';
  $ds_fieldsetting->view_mode = 'conversion_cta_sidebar';
  $ds_fieldsetting->settings = array(
    'cta_landingpage_referenced' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:1:{s:7:"context";a:1:{i:0;s:25:"argument_entity_id:node_1";}}s:4:"type";s:11:"views_panes";s:7:"subtype";s:39:"enterprise_landingpage_cta-pane_sidebar";}',
        'load_terms' => 0,
        'ft' => array(),
        'field_delimiter' => '',
        'field_formatter_class' => '',
        'conditions' => array(
          0 => array(
            'condition' => 'hide_not_empty',
            'configuration' => array(
              'target' => 'field_landingpage_cta_sidebar',
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
    'field_landingpage_cta_sidebar' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|enterprise_landingpage|conversion_cta_sidebar'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function enterprise_landingpage_config_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'cta_landingpage_referenced';
  $ds_field->label = 'CTA Linking to Content (random)';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '*|*';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['cta_landingpage_referenced'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enterprise_landingpage_config_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_landingpage|conversion_cta_footer';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_landingpage';
  $ds_layout->view_mode = 'conversion_cta_footer';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_landingpage_cta_footer',
        1 => 'cta_landingpage_referenced',
      ),
    ),
    'fields' => array(
      'field_landingpage_cta_footer' => 'ds_content',
      'cta_landingpage_referenced' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|enterprise_landingpage|conversion_cta_footer'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_landingpage|conversion_cta_sidebar';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_landingpage';
  $ds_layout->view_mode = 'conversion_cta_sidebar';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_landingpage_cta_sidebar',
        1 => 'cta_landingpage_referenced',
      ),
    ),
    'fields' => array(
      'field_landingpage_cta_sidebar' => 'ds_content',
      'cta_landingpage_referenced' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|enterprise_landingpage|conversion_cta_sidebar'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_landingpage|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_landingpage';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|enterprise_landingpage|default'] = $ds_layout;

  return $export;
}
