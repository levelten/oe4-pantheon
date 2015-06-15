<?php
/**
 * @file
 * enterprise_landingpages.features.inc
 */

/**
 * Implements hook_cta_selector_defaults().
 */
function enterprise_landingpages_cta_selector_defaults() {
  $data = array(
    'cta_footer' => array(
      'name' => 'cta_footer',
      'description' => 'CTA: footer selector',
      'data' => array(
        'cta_description' => 'footer',
        'preset_vocabulary' => 'cta_categories',
      ),
    ),
    'cta_forms' => array(
      'name' => 'cta_forms',
      'description' => 'CTA: form selector',
      'data' => array(
        'cta_description' => 'form',
      ),
    ),
    'cta_sidebar' => array(
      'name' => 'cta_sidebar',
      'description' => 'CTA: sidebar selector',
      'data' => array(
        'cta_description' => 'sidebar',
        'preset_vocabulary' => 'cta_categories',
      ),
    ),
  );
  return $data;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_landingpages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "cta" && $api == "cta") {
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
 * Implements hook_node_info().
 */
function enterprise_landingpages_node_info() {
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
