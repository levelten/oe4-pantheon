<?php
/**
 * @file
 * enterprise_link.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_link_config_ctools_plugin_api($module = NULL, $api = NULL) {
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
function enterprise_link_config_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function enterprise_link_config_node_info() {
  $items = array(
    'enterprise_link' => array(
      'name' => t('Link'),
      'base' => 'node_content',
      'description' => t('Add links to other web pages'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
