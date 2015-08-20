<?php
/**
 * @file
 * enterprise_client.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function enterprise_client_taxonomy_default_vocabularies() {
  return array(
    'client_types' => array(
      'name' => 'Client Types',
      'machine_name' => 'client_types',
      'description' => 'Client market segments, sectors and industries',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
  );
}
