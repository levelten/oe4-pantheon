<?php
/**
 * @file
 * enterprise_demo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_demo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "deploy" && $api == "deploy_plans") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
