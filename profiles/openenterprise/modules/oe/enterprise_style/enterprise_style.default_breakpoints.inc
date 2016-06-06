<?php
/**
 * @file
 * enterprise_style.default_breakpoints.inc
 */

require_once drupal_get_path('module', 'enterprise_style') . "/includes/enterprise_style.image.inc";

/**
 * Implements hook_default_breakpoints().
 */
function enterprise_style_default_breakpoints() {
  $image_settings = enterprise_style_image_settings();

  $weight = -10;

  $export = array();

  // Breakpoints.
  $breakpoints = array();
  foreach($image_settings['resolutions'] as $resolution_name => $resolution) {
    $breakpoint = new stdClass();
    $breakpoint->disabled = TRUE;
    $breakpoint->api_version = 1;
    $breakpoint->machine_name = 'custom.user.' . $resolution_name;
    $breakpoint->name = $resolution_name;
    $breakpoint->breakpoint = $resolution['breakpoint'];
    $breakpoint->source = 'user';
    $breakpoint->source_type = 'custom';
    $breakpoint->status = 1;
    $breakpoint->weight = $weight--;
    $breakpoint->multipliers = array(
      '1x' => '1x',
    );
    $export['custom.user.' . $resolution_name] = $breakpoint;
  }
  return $export;
}
