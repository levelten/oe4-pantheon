<?php
/**
 * @file
 * enterprise_coupon.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_coupon_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
}
