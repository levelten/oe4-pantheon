<?php
/**
 * @file
 * enterprise_seo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_seo_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
