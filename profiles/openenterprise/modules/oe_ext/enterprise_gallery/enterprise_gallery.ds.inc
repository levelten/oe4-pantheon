<?php
/**
 * @file
 * enterprise_gallery.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function enterprise_gallery_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'slick_carousel';
  $ds_view_mode->label = 'Slick Carousel';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
  );
  $export['slick_carousel'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'slick_gallery';
  $ds_view_mode->label = 'Slick Gallery';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
  );
  $export['slick_gallery'] = $ds_view_mode;

  return $export;
}
