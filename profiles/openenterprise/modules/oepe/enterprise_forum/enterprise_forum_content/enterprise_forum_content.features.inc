<?php
/**
 * @file
 * enterprise_forum_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_forum_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "deploy" && $api == "deploy_plans") {
    return array("version" => "1");
  }
}
