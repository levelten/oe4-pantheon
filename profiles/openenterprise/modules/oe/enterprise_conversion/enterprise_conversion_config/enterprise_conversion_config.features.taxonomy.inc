<?php
/**
 * @file
 * enterprise_conversion.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function enterprise_conversion_config_taxonomy_default_vocabularies() {
  return array(
    'cta_categories' => array(
      'name' => 'CTA categories',
      'machine_name' => 'cta_categories',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
      'slug' => '',
    ),
  );
}
