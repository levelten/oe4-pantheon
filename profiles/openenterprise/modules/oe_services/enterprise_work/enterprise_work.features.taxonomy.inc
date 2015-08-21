<?php
/**
 * @file
 * enterprise_work.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function enterprise_work_taxonomy_default_vocabularies() {
  return array(
    'service_areas' => array(
      'name' => 'Service Areas',
      'machine_name' => 'service_areas',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
    'service_types' => array(
      'name' => 'Service Types',
      'machine_name' => 'service_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
  );
}
