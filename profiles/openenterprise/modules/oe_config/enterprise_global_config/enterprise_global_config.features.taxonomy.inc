<?php
/**
 * @file
 * enterprise_global_config.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function enterprise_global_config_taxonomy_default_vocabularies() {
  return array(
    'categories' => array(
      'name' => 'Categories',
      'machine_name' => 'categories',
      'description' => 'Global classification terms',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
    'personas' => array(
      'name' => 'Personas',
      'machine_name' => 'personas',
      'description' => 'Target audience representation',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
  );
}
