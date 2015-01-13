<?php
/**
 * @file
 * enterprise_slideshow.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function enterprise_slideshow_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'slideshow';
  $picture_mapping->breakpoint_group = 'slideshow';
  $picture_mapping->mapping = array(
    'custom.user.xs' => array(
      '1x' => 'enterprise_slideshow_small',
    ),
    'custom.user.sm' => array(
      '1x' => 'enterprise_slideshow_medium',
    ),
    'custom.user.md' => array(
      '1x' => 'enterprise_slideshow_large',
    ),
    'custom.user.lg' => array(
      '1x' => 'enterprise_slideshow_full',
    ),
    'custom.user.xl' => array(
      '1x' => '',
    ),
  );
  $export['slideshow'] = $picture_mapping;

  return $export;
}
