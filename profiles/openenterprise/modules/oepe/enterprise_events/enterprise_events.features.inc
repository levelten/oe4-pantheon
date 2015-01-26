<?php
/**
 * @file
 * enterprise_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_events_ctools_plugin_api($module = NULL, $api = NULL) {
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
function enterprise_events_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function enterprise_events_node_info() {
  $items = array(
    'enterprise_event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('An <i>event</i> with a time, location and registration link'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
