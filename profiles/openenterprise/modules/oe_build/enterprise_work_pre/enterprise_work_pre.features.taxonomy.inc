<?php
/**
 * @file
 * enterprise_work_pre.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function enterprise_work_pre_taxonomy_default_vocabularies() {
  return array(
    'challenge_types' => array(
      'name' => 'Challenge types',
      'machine_name' => 'challenge_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
    'industry_types' => array(
      'name' => 'Industry types',
      'machine_name' => 'industry_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
    'organization_sizes' => array(
      'name' => 'Organization sizes',
      'machine_name' => 'organization_sizes',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
    'organization_types' => array(
      'name' => 'Organization types',
      'machine_name' => 'organization_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
    'personas' => array(
      'name' => 'Personas',
      'machine_name' => 'personas',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
    'service_areas' => array(
      'name' => 'Service areas',
      'machine_name' => 'service_areas',
      'description' => 'Geo graphical areas served',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
    'service_tags' => array(
      'name' => 'Service tags',
      'machine_name' => 'service_tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
    'service_types' => array(
      'name' => 'Service types',
      'machine_name' => 'service_types',
      'description' => 'Categories of service offerings',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
  );
}
