<?php
/**
 * @file
 * enterprise_global_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_global_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function enterprise_global_config_node_info() {
  $items = array(
    'enterprise_etmaster' => array(
      'name' => t('[master]'),
      'base' => 'node_content',
      'description' => t('Dev - Master content type model'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'enterprise_etsource' => array(
      'name' => t('[source]'),
      'base' => 'node_content',
      'description' => t('Dev - Resource for cloning field instances and settings.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
