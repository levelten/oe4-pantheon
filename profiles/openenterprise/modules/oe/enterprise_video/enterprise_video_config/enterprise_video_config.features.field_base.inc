<?php
/**
 * @file
 * enterprise_video.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function enterprise_video_config_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_video_embed'
  $field_bases['field_video_embed'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_video_embed',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'video_embed_field',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'video_embed_field',
  );

  return $field_bases;
}
