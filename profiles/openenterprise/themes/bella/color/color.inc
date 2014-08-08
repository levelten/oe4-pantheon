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

  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => array(
    'css/colors.css',
  ),

  // Files to copy.
  'copy' => array(
    'logo.png',
  ),

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

// Add Kuler colors
$kuler_json = theme_get_setting('kuler_json', variable_get('theme_default'));
$kuler_check = theme_get_setting('kuler_check', variable_get('theme_default'));

if (!empty($kuler_json) && $kuler_check) {
  $json = array_unique(get_object_vars(json_decode($kuler_json)));
  $kuler_colors = array();
  foreach ($json as $key => $value) {
    if ($value != '[object Object]' && strlen($key) < 56) {
      $colors = explode(',', $value);
      $title = trim(str_replace('_', ' ', $key));
      if (count($colors) == 5) {
        $colorset = array(
          'title' => t(ucwords($key)),
          'colors' => array(
            'brandprimary' => $colors[0],
            'brandsecondary' => $colors[1],
            'brandaccent' => $colors[2],
            'brandaccent2' => $colors[3],
            'brandaccent3' => $colors[4],
          ),
        );
      }
      $kuler_colors[$title] = $colorset;
    }
  }
}

$colourlovers_palette = variable_get('colourlovers_theme_palette', '');
$colourlovers_check = theme_get_setting('colourlovers_check', variable_get('theme_default'));

if (module_exists('colourlovers') && $colourlovers_check && !empty($colourlovers_palette)) {
  
  // Only grab first 5 colors (if available).
  foreach ($colourlovers_palette as $key => $value) {
    foreach ($value['colors'] as $k => $v) {
      $colourlovers_palette[$key]['colors']['brandprimary'] = (isset($value['colors'][0])) ? '#'.$value['colors'][0] : '#FFF';
      $colourlovers_palette[$key]['colors']['brandsecondary'] = (isset($value['colors'][1])) ? '#'.$value['colors'][1] : '#FFF';
      $colourlovers_palette[$key]['colors']['brandaccent'] = (isset($value['colors'][2])) ? '#'.$value['colors'][2] : '#FFF';
      $colourlovers_palette[$key]['colors']['brandaccent2'] = (isset($value['colors'][3])) ? '#'.$value['colors'][3] : '#FFF';
      $colourlovers_palette[$key]['colors']['brandaccent3'] = (isset($value['colors'][4])) ? '#'.$value['colors'][4] : '#FFF';
      unset($colourlovers_palette[$key]['colors'][$k]);
    }
  }
  $first_key = key($colourlovers_palette);
  $temp = $colourlovers_palette[$first_key];
  $colourlovers_palette['default'] = $temp;
  unset($colourlovers_palette[$first_key]);

  $info['schemes'] = $colourlovers_palette;

} else if (!empty($kuler_colors)) {
  // Add default value in or else it borks.
  reset($kuler_colors);
  $first_key = key($kuler_colors);
  $temp = $kuler_colors[$first_key];
  $kuler_colors['default'] = $temp;
  unset($kuler_colors[$first_key]);

  $info['schemes'] = $kuler_colors;
} else {
  // Unset the extra color fields.
  unset($info['fields']['brandaccent2']);
  unset($info['fields']['brandaccent3']);
}
