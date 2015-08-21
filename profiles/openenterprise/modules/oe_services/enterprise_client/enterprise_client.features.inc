<?php
/**
 * @file
 * enterprise_client.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_client_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function enterprise_client_node_info() {
  $items = array(
    'enterprise_client' => array(
      'name' => t('Client'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Client Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
