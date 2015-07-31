<?php
/**
 * @file
 * enterprise_style.default_picture_mapping.inc
 */

require_once drupal_get_path('module', 'enterprise_style') . "/includes/enterprise_style.image.inc";

/**
 * Implements hook_default_picture_mapping().
 */
function enterprise_style_default_picture_mapping() {
  $image_settings = enterprise_style_image_settings();
  $export = array();

  foreach($image_settings['sizes'] as $size_name => $size) {
    foreach($image_settings['ratios'] as $ratio_name => $ratio) {
      $mappings = array();
      foreach($image_settings['resolutions'] as $resolution_name => $resolution) {
        $mappings['custom.user.' . $resolution_name] = array(
          '1x' => array(
            'mapping_type' => 'image_style',
            'image_style' => $size_name . '-' . $ratio_name . '-' . $resolution_name,
          )
        );
      }

      $picture_mapping = new PictureMapping();
      $picture_mapping->disabled = FALSE;
      $picture_mapping->api_version = 2;
      $picture_mapping->label = ucfirst($size_name) . ' (' . $ratio_name . ')';
      $picture_mapping->machine_name = $size_name . '-' . $ratio_name;
      $picture_mapping->breakpoint_group = $size_name . '-' . $ratio_name;
      $picture_mapping->mapping = $mappings;
      $export[$size_name . '-' . $ratio_name] = $picture_mapping;
      
    }
  }
  return $export;
}
