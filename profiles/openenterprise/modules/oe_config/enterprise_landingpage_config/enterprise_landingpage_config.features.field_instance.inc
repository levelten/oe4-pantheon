<?php
/**
 * @file
 * enterprise_landingpage_config.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function enterprise_landingpage_config_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-enterprise_landingpage-body'.
  $field_instances['node-enterprise_landingpage-body'] = array(
    'bundle' => 'enterprise_landingpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'conversion_cta_footer' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'conversion_cta_sidebar' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
          'field_delimiter' => '',
          'field_formatter_class' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'ical' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
          'ellipsis' => FALSE,
          'field_delimiter' => '',
          'field_formatter_class' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
          'trim_length' => 600,
          'word_boundary' => FALSE,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'node-enterprise_landingpage-field_intel_event_col'.
  $field_instances['node-enterprise_landingpage-field_intel_event_col'] = array(
    'bundle' => 'enterprise_landingpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'conversion_cta_footer' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'conversion_cta_sidebar' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_intel_event_col',
    'label' => 'Intel events',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'node-enterprise_landingpage-field_landingpage_cta_footer'.
  $field_instances['node-enterprise_landingpage-field_landingpage_cta_footer'] = array(
    'bundle' => 'enterprise_landingpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'conversion_cta_footer' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'conditions' => array(),
          'field_delimiter' => '',
          'field_formatter_class' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
          'links' => 0,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 0,
      ),
      'conversion_cta_sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'enterprise_edit_form_display' => '',
    'entity_type' => 'node',
    'entityconnect_unload_add' => 0,
    'entityconnect_unload_edit' => 0,
    'field_name' => 'field_landingpage_cta_footer',
    'label' => 'Default Footer CTA',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'node-enterprise_landingpage-field_landingpage_cta_sidebar'.
  $field_instances['node-enterprise_landingpage-field_landingpage_cta_sidebar'] = array(
    'bundle' => 'enterprise_landingpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'conversion_cta_footer' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'conversion_cta_sidebar' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'conditions' => array(),
          'field_delimiter' => '',
          'field_formatter_class' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
          'links' => 0,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'enterprise_edit_form_display' => '',
    'entity_type' => 'node',
    'entityconnect_unload_add' => 0,
    'entityconnect_unload_edit' => 0,
    'field_name' => 'field_landingpage_cta_sidebar',
    'label' => 'Default Sidebar CTA',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'node-enterprise_landingpage-field_page_attribute_col'.
  $field_instances['node-enterprise_landingpage-field_page_attribute_col'] = array(
    'bundle' => 'enterprise_landingpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'conversion_cta_footer' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'conversion_cta_sidebar' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_page_attribute_col',
    'label' => 'Page attributes',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-enterprise_landingpage-field_redirect_url'.
  $field_instances['node-enterprise_landingpage-field_redirect_url'] = array(
    'bundle' => 'enterprise_landingpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'conversion_cta_footer' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'conversion_cta_sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'enterprise_edit_form_display' => '',
    'entity_type' => 'node',
    'field_name' => 'field_redirect_url',
    'label' => 'Custom URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-enterprise_landingpage-field_thankyou'.
  $field_instances['node-enterprise_landingpage-field_thankyou'] = array(
    'bundle' => 'enterprise_landingpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'conversion_cta_footer' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'conversion_cta_sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'enterprise_edit_form_display' => '',
    'entity_type' => 'node',
    'field_name' => 'field_thankyou',
    'label' => 'Thank you page',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'node-enterprise_landingpage-field_visitor_attribute_col'.
  $field_instances['node-enterprise_landingpage-field_visitor_attribute_col'] = array(
    'bundle' => 'enterprise_landingpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'conversion_cta_footer' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'conversion_cta_sidebar' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_visitor_attribute_col',
    'label' => 'Visitor attributes',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Custom URL');
  t('Default Footer CTA');
  t('Default Sidebar CTA');
  t('Intel events');
  t('Page attributes');
  t('Thank you page');
  t('Visitor attributes');

  return $field_instances;
}
