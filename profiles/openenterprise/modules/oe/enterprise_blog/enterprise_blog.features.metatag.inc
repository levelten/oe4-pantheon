<?php
/**
 * @file
 * meta.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function enterprise_blog_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:enterprise_blog.
  $config['node:enterprise_blog'] = array(
    'instance' => 'node:enterprise_blog',
    'config' => array(
      'image_src' => array(
        'value' => '[node:field_image]',
      ),
      'og:type' => array(
        'value' => 'blog',
      ),
      'og:image' => array(
        'value' => '[node:field_image]',
      ),
    ),
  );

  return $config;
}