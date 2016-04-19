<?php
/**
 * @file
 * enterprise_seo.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function enterprise_seo_config_taxonomy_default_vocabularies() {
  return array(
    'keywords' => array(
      'name' => 'Keywords',
      'machine_name' => 'keywords',
      'description' => 'Target phrases for search engine optimization',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
      'slug' => '',
    ),
  );
}
