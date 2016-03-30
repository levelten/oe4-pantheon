<?php
/**
 * @file
 * enterprise_blog_config.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function enterprise_blog_config_taxonomy_default_vocabularies() {
  return array(
    'blog_categories' => array(
      'name' => 'Blog Categories',
      'machine_name' => 'blog_categories',
      'description' => 'Blog specific categories',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
  );
}
