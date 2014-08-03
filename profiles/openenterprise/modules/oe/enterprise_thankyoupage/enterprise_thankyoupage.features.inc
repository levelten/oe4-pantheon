<?php
/**
 * @file
 * enterprise_thankyoupage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_thankyoupage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function enterprise_thankyoupage_node_info() {
  $items = array(
    'enterprise_thankyou' => array(
      'name' => t('Thank you page'),
      'base' => 'node_content',
      'description' => t('Used as form submission acknowledgements.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
