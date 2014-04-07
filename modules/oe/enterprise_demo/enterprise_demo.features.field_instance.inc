<?php
/**
 * @file
 * enterprise_demo.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function enterprise_demo_field_default_field_instances() {
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

  // Translatables
  // Included for use with string extractors like potx.
  t('CTA category');

  return $field_instances;
}
