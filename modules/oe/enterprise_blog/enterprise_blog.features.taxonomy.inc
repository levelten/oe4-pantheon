<?php
/**
 * @file
 * enterprise_blog.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function enterprise_blog_taxonomy_default_vocabularies() {
  return array(
    'blog_categories' => array(
      'name' => 'Blog Categories',
      'machine_name' => 'blog_categories',
      'description' => 'Blog specific categories',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
      'slug' => '',
    ),
    'blog_tags' => array(
      'name' => 'Blog Tags',
      'machine_name' => 'blog_tags',
      'description' => 'Blog specific tagging',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
      'slug' => '',
    ),
  );
}
