<?php

// Put the logo path into JavaScript for the live preview.
drupal_add_js(array('color' => array('logo' => theme_get_setting('logo', 'bella'))), 'setting');

$info = array(
  // Available colors and color labels used in theme.
  'fields' => array(
    'brandprimary' => t('Brand Primary'),
    'brandsecondary' => t('Brand Secondary'),
    'brandaccent' => t('Brand Accent'),
    'brandaccent2' => t('Brand Accent 2'),
    'brandaccent3' => t('Brand Accent 3'),
  ),
  // Pre-defined color schemes.
  'schemes' => array(
    'default' => array(
      'title' => t('Bella (default)'),
      'colors' => array(
        'brandprimary' => '#EA9B3E',
        'brandsecondary' => '#F5F5F5',
        'brandaccent' => '#FFFFFF',
      ),
    ),
    'bella_prince' => array(
      'title' => t('Prince'),
      'colors' => array(
        'brandprimary' => '#0995D8',
        'brandsecondary' => '#F5F5F5',
        'brandaccent' => '#FFFFFF',
      ),
    ),
    'bella_midnight' => array(
      'title' => t('Midnight'),
      'colors' => array(
        'brandprimary' => '#6E2E62',
        'brandsecondary' => '#F5F5F5',
        'brandaccent' => '#FFFFFF',
      ),
    ),
  ),

  // We aren't using any of the following, but Color will throw errors if it's missing.
  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => array('css/colors.css',),
  // Files to copy.
  'copy' => array('logo.png',),
  // Gradient definitions.
  'gradients' => array(
    array(
      // (x, y, width, height).
      'dimension' => array(0, 0, 0, 0),
      // Direction of gradient ('vertical' or 'horizontal').
      'direction' => 'vertical',
      // Keys of colors to use for the gradient.
      'colors' => array('top', 'bottom'),
    ),
  ),
  // Color areas to fill (x, y, width, height).
  'fill' => array(),
  // Coordinates of all the theme slices (x, y, width, height)
  // with their filename as used in the stylesheet.
  'slices' => array(),
  // Reference color used for blending. Matches the base.png's colors.
  'blend_target' => '#ffffff',
  // Preview files.
  'preview_css' => 'color/preview.css',
  'preview_js' => 'color/preview.js',
  'preview_html' => 'color/preview.html',
  // Base file for image generation.
  'base_image' => 'color/base.png',
);

$colourlovers_palette = variable_get('colourlovers_theme_palette', '');
$colourlovers_check = theme_get_setting('colourlovers_check', variable_get('theme_default'));

if (module_exists('colourlovers') && $colourlovers_check && !empty($colourlovers_palette)) {
  // Only grab first 5 colors (if available).
  foreach ($colourlovers_palette as $key => $value) {
    foreach ($value['colors'] as $k => $v) {
      $colourlovers_palette[$key]['color']['brandprimary'] = (isset($value['colors'][0])) ? '#'.$value['colors'][0] : '#FFFFFF';
      $colourlovers_palette[$key]['color']['brandsecondary'] = (isset($value['colors'][1])) ? '#'.$value['colors'][1] : '#FFFFFF';
      $colourlovers_palette[$key]['color']['brandaccent'] = (isset($value['colors'][2])) ? '#'.$value['colors'][2] : '#FFFFFF';
      $colourlovers_palette[$key]['color']['brandaccent2'] = (isset($value['colors'][3])) ? '#'.$value['colors'][3] : '#FFFFFF';
      $colourlovers_palette[$key]['color']['brandaccent3'] = (isset($value['colors'][4])) ? '#'.$value['colors'][4] : '#FFFFFF';
    }
    $colourlovers_palette[$key]['colors'] = $colourlovers_palette[$key]['color'];
    unset($colourlovers_palette[$key]['color']);
  }

  // Add COLOURlover palette to color palette.
  reset($colourlovers_palette);
  $colourlovers_palette = _color_clean_palette($colourlovers_palette);
  $info['schemes'] = $colourlovers_palette;

} else {
  // Unset the extra color fields.
  unset($info['fields']['brandaccent2']);
  unset($info['fields']['brandaccent3']);
}

// Flush LESS cache
if (module_exists('less')) {
  less_flush_caches();
}

/*
 * Helper function to get the palettes ready for the Color module.
 */
function _color_clean_palette($palette) {
  $first_key = key($palette);
  $temp = $palette[$first_key];
  $palette['default'] = $temp;
  unset($palette[$first_key]);

  return $palette;
}
