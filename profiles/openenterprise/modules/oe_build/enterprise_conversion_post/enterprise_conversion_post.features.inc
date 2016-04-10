<?php
/**
 * @file
 * enterprise_conversion_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_conversion_post_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
