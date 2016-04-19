<?php
/**
 * @file
 * enterprise_image.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_image_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function enterprise_image_config_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function enterprise_image_config_node_info() {
  $items = array(
    'enterprise_image' => array(
      'name' => t('Image'),
      'base' => 'node_content',
      'description' => t('A image file for displaying in galleries'),
      'has_title' => '1',
      'title_label' => t('Image name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
