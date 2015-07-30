<?php
/**
 * @file
 */


/**
 * Get the settings for images
 *
 * TODO: This should be editable and alterable
 */
function enterprise_style_image_settings() {
  return array(
    'ratios' => array(
      '0' => 0,
      //'2x3' => 3/2,
      '5x7' => 7/5,
      //'3x4' => 4/3,
      '1x1' => 1,
      //'4x3' => 3/4,
      '7x5' => 5/7,
      //'3x2' => 2/3,
      '16x9' => 9/16,
      '3x1' => 1/3,
    ),
    /*
    'ratios_label' => array(
      '0' => '',
      '3x4' => 'Portrait Photo (3:4)',
      '1x1' => 'Square (1:1)',
      '4x3' => 'Landscape Photo (4:3)',
      '16x9' => 'Hi-Def (16:9)',
      '3x1' => 'Panoramic (3:1)',
    ),
    */
    'ratios_label' => array(
      '0' => '',
      '2x3' => 'portrait photo',
      '5x7' => 'portrait photo',
      '3x4' => 'portrait photo',
      '1x1' => 'square',
      '4x3' => 'landscape photo',
      '7x5' => 'landscape photo',
      '3x2' => 'landscape photo',
      '16x9' => 'hi-def',
      '3x1' => 'panoramic',
    ),
    'sizes' => array(
      'full' => 1,
      'large' => 1/2,
      'medium' => 1/4,
      'small' => 1/6,
    ),
    'resolutions' => array(
      'lg' => array(
        'inner-width' => 1140,
        'breakpoint' => '(min-width: 1200px)',
      ),
      'md' => array(
        'inner-width' => 940,
        'breakpoint' => '(min-width: 992px) and (max-width: 1199px)',
      ),
      'sm' => array(
        'inner-width' => 720,
        'breakpoint' => '(min-width: 768px) and (max-width: 991px)',
      ),
      'xs' => array(
        'inner-width' => 480,
        'breakpoint' => '(max-width: 767px)',
      ),
    ),
  );
}

/**
 * Implements hook_image_default_styles()
 *
 * @return array
 */
function enterprise_style_image_default_styles() {
  $image_settings = enterprise_style_image_settings();
  $styles = array();

  foreach($image_settings['ratios'] as $ratio_name => $ratio) {
    foreach($image_settings['sizes'] as $size_name => $size) {
      foreach($image_settings['resolutions'] as $resolution_name => $resolution) {
        if ($ratio) {
          $width = round($resolution['inner-width'] * $size, 0);
          $height = round($resolution['inner-width'] * $size * $ratio, 0);
        }
        else {
          $width = round($resolution['inner-width'] * $size, 0);
          $height = '';
        }
        $key = $size_name . '-' . $ratio_name . '-' . $resolution_name;
        $styles[$key] = array(
          'label' => ucfirst($size_name) . ': ' . str_replace('x', ':', $ratio_name) . '-' . $resolution_name . ' (' . $width . 'x' . $height . ')',
          'effects' => array(
            array(
              'name' => 'image_scale_and_crop',
              'data' => array(
                'width' => $width,
                'height' => $height,
                'upscale' => 1,
              ),
              'weight' => 0,
            ),
          ),
        );
        // if no ratio, i.e. no croping
        if (!$ratio) {
          $styles[$key]['label'] = ucfirst($size_name) . '-' . t('original ratio') . '-' . $resolution_name;
          $styles[$key]['effects'][0]['name'] = 'image_scale';
          //unset($styles[$key]['effects'][0]['data']['height']);
        }
      }
    }
  }

  return $styles;
}

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
      $picture_mapping = new stdClass();
      $picture_mapping->disabled = FALSE;
      $picture_mapping->api_version = 2;
      $picture_mapping->label = $size_name . '-' . $ratio_name;
      $picture_mapping->machine_name = $size_name . '-' . $ratio_name;
      $picture_mapping->breakpoint_group = $size_name . '-' . $ratio_name;
      $picture_mapping->mapping = $mappings;
      $export[$size_name . '-' . $ratio_name] = $picture_mapping;
    }
  }
  return $export;
}

/**
 * Implements hook_flush_caches($component).
 *
 * TODO: Find a better way to do this. Cache clear isn't good but it keeps
 * everything in sync with the settings above.
 */
function enterprise_style_flush_caches() {
  $value = variable_get('picture_ckeditor_groups', array(
    'default' => array(
      'enabled' => NULL,
      'weight' => NULL,
      'fallback' => NULL,
    ),
  ));
  $image_settings = enterprise_style_image_settings();
  $weight = 1;

  foreach($image_settings['sizes'] as $size_name => $size) {
    foreach($image_settings['ratios'] as $ratio_name => $ratio) {
      $value[$size_name . '-' . $ratio_name] = array(
        'enabled' => 1,
        'weight' => $weight++,
        'fallback' => $size_name . '-' . $ratio_name . '-' . current(array_keys($image_settings['resolutions'])),
      );
    }
  }

  variable_set('picture_ckeditor_groups', $value);
}