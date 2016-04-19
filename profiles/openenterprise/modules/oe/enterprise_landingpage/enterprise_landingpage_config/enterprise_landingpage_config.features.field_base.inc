<?php
/**
 * @file
 * enterprise_landingpage_config.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function enterprise_landingpage_config_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_landingpage_cta_footer'.
  $field_bases['field_landingpage_cta_footer'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_landingpage_cta_footer',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'views',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'view' => array(
          'args' => array(),
          'display_name' => 'entityref_footer',
          'view_name' => 'enterprise_landingpage_cta',
        ),
      ),
      'target_type' => 'bean',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_landingpage_cta_sidebar'.
  $field_bases['field_landingpage_cta_sidebar'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_landingpage_cta_sidebar',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'views',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'view' => array(
          'args' => array(),
          'display_name' => 'entityref_sidebar',
          'view_name' => 'enterprise_landingpage_cta',
        ),
      ),
      'target_type' => 'bean',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
