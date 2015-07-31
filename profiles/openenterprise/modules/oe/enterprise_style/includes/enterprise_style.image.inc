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