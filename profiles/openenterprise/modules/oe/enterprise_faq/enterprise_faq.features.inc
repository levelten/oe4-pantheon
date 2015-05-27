<?php
/**
 * @file
 * enterprise_faq.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_faq_ctools_plugin_api($module = NULL, $api = NULL) {
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
function enterprise_faq_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function enterprise_faq_node_info() {
  $items = array(
    'enterprise_faq' => array(
      'name' => t('FAQ'),
      'base' => 'node_content',
      'description' => t('Answers to frequently asked questions'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
