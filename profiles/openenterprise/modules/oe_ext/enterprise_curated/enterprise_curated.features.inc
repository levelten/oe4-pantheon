<?php
/**
 * @file
 * enterprise_curated.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_curated_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "radioactivity" && $api == "radioactivity_decay_profile") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function enterprise_curated_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function enterprise_curated_node_info() {
  $items = array(
    'enterprise_curated' => array(
      'name' => t('Curated Post'),
      'base' => 'node_content',
      'description' => t('A curated post is a post for your currated content. It countains a title and body and can be categorized using tags.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
