<?php
/**
 * @file
 * enterprise_slideshow.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function enterprise_slideshow_taxonomy_default_vocabularies() {
  return array(
    'enterprise_slideshow_classes' => array(
      'name' => 'Enterprise Slideshow Classes',
      'machine_name' => 'enterprise_slideshow_classes',
      'description' => 'A list of wrapper classes available for Enterprise Slideshow blocks',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
    ),
  );
}
