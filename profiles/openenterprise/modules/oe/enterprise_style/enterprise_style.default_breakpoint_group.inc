<?php
/**
 * @file
 * enterprise_style.default_breakpoint_group.inc
 */

require_once drupal_get_path('module', 'enterprise_style') . "/includes/enterprise_style.image.inc";

/**
 * Implements hook_default_breakpoint_group().
 */
function enterprise_style_default_breakpoint_group() {
  $image_settings = enterprise_style_image_settings();

  $export = array();

  // Breakpoints.
  $breakpoints = array();
  foreach($image_settings['resolutions'] as $resolution_name => $resolution) {
    $breakpoints[] = 'custom.user.' . $resolution_name;
  }

  //foreach($image_settings['ratios'] as $ratio_name => $ratio) {
    //foreach($image_settings['sizes'] as $size_name => $size) {
  foreach($image_settings['sizes'] as $size_name => $size) {
    foreach($image_settings['ratios'] as $ratio_name => $ratio) {
      $breakpoint_group = new stdClass();
      $breakpoint_group->disabled = TRUE;
      $breakpoint_group->api_version = 1;
      $breakpoint_group->machine_name = $size_name . '-' . $ratio_name;
      //$breakpoint_group->name = ucfirst($size_name) . '-' . str_replace('x', ':', $ratio_name);
      if ($ratio_name != '0') {
        //$breakpoint_group->name = ucfirst($size_name) . ': ' . $image_settings['ratios_label'][$ratio_name];
        $breakpoint_group->name = ' - ' . ucfirst($size_name) . ': ' . str_replace('x', ':', $ratio_name) . ' (' . $image_settings['ratios_label'][$ratio_name] . ')';
      }
      else {
        //$breakpoint_group->name = ucfirst($size_name);
        $breakpoint_group->name = ucfirst($size_name);
      }

      $breakpoint_group->breakpoints = $breakpoints;
      $breakpoint_group->type = 'custom';
      $breakpoint_group->overridden = 0;
      $export[$size_name . '-' . $ratio_name] = $breakpoint_group;
    }
  }

  return $export;
}
