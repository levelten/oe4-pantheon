<?php
/**
 * @file
 * enterprise_press.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_press_ctools_plugin_api($module = NULL, $api = NULL) {
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
function enterprise_press_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function enterprise_press_node_info() {
  $items = array(
    'enterprise_press_release' => array(
      'name' => t('Press release'),
      'base' => 'node_content',
      'description' => t('A <i>Press release</i> is used to release a pdf.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
