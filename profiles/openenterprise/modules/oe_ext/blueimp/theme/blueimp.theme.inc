<?php
/**
 * @file
 * Theming functions for the blueimp module.
 *
 * Preprocessor functions fill variables for templates and helper
 * functions to make theming easier.
 */

/**
 * Default theme implementation for blueimp_gallery
 */
function theme_blueimp_gallery(&$vars) {
  // Reference configuration variables
  $items = &$vars['items'];
  $attributes = &$vars['settings']['attributes'];
  $output = '';

  // Build the list
  if (!empty($items)) {
    $output .= '<div' . drupal_attributes($attributes) . '>';
    foreach ($items as $i => $item) {
      $caption = '';
      if (!empty($item['item']['title'])) {
        $caption = $item['item']['title'];
      }
      
      $image = array(
        'thumbnail' => $item['thumbnail'],
        'settings' => array(
          'attributes' => array(
            'href' => $item['slide'],
            'title' => $caption,
            // 'data-gallery' => '',
          ),
        ),
      );

      $output .= theme('blueimp_links', array('image' => $image));
    }
    $output .= '</div>';
  }

  return $output;
}

/**
 * Default theme implementation for blueimp_links
 */
function theme_blueimp_links(&$vars) {
  $image = $vars['image'];
  return '<a' . drupal_attributes($image['settings']['attributes']) . '>' . $image['thumbnail'] . "</a>\n";
}

/**
 * Template preprocess handler for 'blueimp' theme.
 */
function template_process_blueimp(&$vars) {
  // Reference configuration variables
  $settings = &$vars['settings'];
  $items = &$vars['items'];

  // Configure attributes for containing elements
  $attributes = array();
  // Merge with defined attributes
  if (isset($settings['attributes']) and is_array($settings['attributes'])) {
    $attributes += $settings['attributes'];
  }

  // Set the ID for each blueimp instance if none is provided
  if (empty($attributes['id'])) {
    $blueimp_id = &drupal_static('blueimp_id', 0);
    $attributes['id'] = 'blueimp-gallery-' . ++$blueimp_id;
  }

  // Add the blueimp class to be namespaced
  $attributes['class'][] = 'blueimp-gallery';

  // Add widget contents.
  $settings['widget'] = '';
  $settings['widget'] .= '<div class="slides"></div>' . "\n";
  $settings['widget'] .= '<h3 class="title"></h3>' . "\n";
  $settings['widget'] .= '<a class="prev">‹</a>' . "\n";
  $settings['widget'] .= '<a class="next">›</a>' . "\n";
  $settings['widget'] .= ($settings['display_style'] !== 'carousel') ? '<a class="close">×</a>' . "\n" : '';
  $settings['widget'] .= '<a class="play-pause"></a>' . "\n";
  $settings['widget'] .= '<ol class="indicator"></ol>';

  switch ($settings['display_style']) {
    case 'lightbox':
      
      break;

    case 'carousel':
      $attributes['class'][] = 'blueimp-gallery-carousel';
      $attributes['class'][] = 'blueimp-gallery-controls';
      break;
    
    default:
      # code...
      break;
  }

  // Add gallery controls.
  if (!empty($settings['gallery_controls'])) {
    $attributes['class'][] = 'blueimp-gallery-controls';
  }

  // Clean up classes array.
  array_unique($attributes['class']);

  // Add the attributes to the settings array.
  $settings['attributes'] = $attributes;


}

/**
 * Process function for blueimp_gallery
 */
function template_process_blueimp_gallery(&$vars) {
  $settings = $vars['settings'];

  // Store gallery id.
  $gallery_id = $vars['settings']['attributes']['id'];

  // Reset the list of attributes
  $vars['settings']['attributes'] = array();

  // Set the ID for each Blueimp link set.
  if (!empty($settings['attributes']['id'])) {
    $vars['settings']['attributes']['id'] = str_replace('gallery', 'links', $settings['attributes']['id']);
  }

  $vars['settings']['gallery_id'] = $gallery_id;
  $vars['settings']['link_id'] = $vars['settings']['attributes']['id'];

  // Finally, add the configuration to the page
  blueimp_add($vars['settings']);
}

/**
 * Process function for blueimp_links
 */
function template_process_blueimp_links(&$vars) {
  // Reset the list of attributes
  $vars['settings']['attributes'] = array();

  // Reference configuration variables
  $item = &$vars['item'];
  $settings = &$vars['settings'];
  $attributes = &$vars['settings']['attributes'];

}


/*
 * Add Blueimp gallery options to the page for rendering.
 */
function blueimp_add($vars) {
  // Setups JS options.
  $options = array(
    'slides' => array(),
  );

  // Add additional options.
  $options['slides'][] = $vars;

  drupal_add_js(array('blueimp_fields' => $options), array('type' => 'setting'));
}
