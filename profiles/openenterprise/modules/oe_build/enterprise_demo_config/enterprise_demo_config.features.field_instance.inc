<?php
/**
 * @file
 * enterprise_demo.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function enterprise_demo_config_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-enterprise_blog-field_cta_category'
  $field_instances['node-enterprise_blog-field_cta_category'] = array(
    'bundle' => 'enterprise_blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'blog_featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'blog_mini' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
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
        'type' => 'taxonomy_term_reference_link',
        'weight' => 22,
      ),
      'rss' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'enterprise_edit_form_display' => 'sidebar',
    'entity_type' => 'node',
    'field_name' => 'field_cta_category',
    'label' => 'CTA category',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-enterprise_blog-field_keywords'
  $field_instances['node-enterprise_blog-field_keywords'] = array(
    'bundle' => 'enterprise_blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'blog_featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'blog_mini' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
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
        'type' => 'taxonomy_term_reference_link',
        'weight' => 23,
      ),
      'rss' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
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
    'field_name' => 'field_keywords',
    'label' => 'Keywords',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 47,
    ),
  );

  // Exported field_instance: 'node-enterprise_landingpage-field_keywords'
  $field_instances['node-enterprise_landingpage-field_keywords'] = array(
    'bundle' => 'enterprise_landingpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
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
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
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
    'field_name' => 'field_keywords',
    'label' => 'Keywords',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 47,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('CTA category');
  t('Keywords');

  return $field_instances;
}
