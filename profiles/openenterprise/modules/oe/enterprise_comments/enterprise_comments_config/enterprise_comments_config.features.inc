<?php
/**
 * @file
 * enterprise_comments.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_comments_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
