<?php
/**
 * @file
 * Code for the Enterprise landing pages feature.
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function enterprise_conversion_ds_view_modes_info() {
  $view_modes = array();

  $selectors = cta_selectors();

  foreach ($selectors as $k => $v) {
    $key = 'conversion_' . $k;
    $ds_view_mode = new stdClass();
    $ds_view_mode->api_version = 1;
    $ds_view_mode->view_mode = $key;
    $ds_view_mode->label = $v['description'];
    $ds_view_mode->entities = array(
      'node' => 'node',
    );
    $view_modes[$key] = $ds_view_mode;
  }



  return $view_modes;
}