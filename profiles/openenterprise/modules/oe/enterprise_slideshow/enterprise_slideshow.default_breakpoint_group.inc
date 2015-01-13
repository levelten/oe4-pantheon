<?php
/**
 * @file
 * enterprise_slideshow.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function enterprise_slideshow_default_breakpoint_group() {
  $export = array();

  // Breakpoints.
  $breakpoints = array();
  $breakpoints[] = 'custom.user.xs';
  $breakpoints[] = 'custom.user.sm';
  $breakpoints[] = 'custom.user.md';
  $breakpoints[] = 'custom.user.lg';
  $breakpoints[] = 'custom.user.xl';

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'slideshow';
  $breakpoint_group->name = 'Slideshow';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['slideshow'] = $breakpoint_group;

  return $export;
}
