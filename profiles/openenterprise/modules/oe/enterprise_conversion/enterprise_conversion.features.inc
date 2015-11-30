<?php
/**
 * @file
 * enterprise_conversion.features.inc
 */

/**
 * Implements hook_cta_selector_defaults().
 */
function enterprise_conversion_cta_selector_defaults() {
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
        'preview_prefix' => '<div class="row">' . PHP_EOL
          .'<aside class="sidebar sidebar-second col-sm-5">' . PHP_EOL
          .'<div class="region region-sidebar-second">' . PHP_EOL,
        'preview_suffix' => '</div>' . PHP_EOL
          .'</aside>' . PHP_EOL
          .'</div>' . PHP_EOL,
      ),
    ),
  );
  return $data;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_conversion_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "cta" && $api == "cta") {
    return array("version" => "1");
  }
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