<?php
/**
 * @file
 * enterprise_conversion_test.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_conversion_test_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "deploy" && $api == "deploy_plans") {
    return array("version" => "1");
  }
}
