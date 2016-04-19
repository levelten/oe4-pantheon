<?php
/**
 * @file
 * enterprise_block.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_block_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
