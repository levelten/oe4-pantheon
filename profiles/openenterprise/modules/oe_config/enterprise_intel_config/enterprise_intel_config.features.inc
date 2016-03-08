<?php
/**
 * @file
 * enterprise_intel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_intel_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
