<?php
/**
 * @file
 * enterprise_landingpage_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_landingpage_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function enterprise_landingpage_config_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function enterprise_landingpage_config_node_info() {
  $items = array(
    'enterprise_landingpage' => array(
      'name' => t('Landing page'),
      'base' => 'node_content',
      'description' => t('One sheet sales page designed to pitch an offer and get people to fill out a form.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
