<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_process_page()
 */
function bella_process_page(&$variables) {
  // Set the proper attributes for the main menu. There should be a better
  // way of doing this but none of the menu process stuff runs early enough.
  if (isset($variables['primary_nav']) && is_array($variables['primary_nav'])) {
    $primary_nav = &$variables['primary_nav'];
    foreach(element_children($primary_nav) as $level1) {
      $mega = FALSE;
      foreach(element_children($primary_nav[$level1]['#below']) as $level2) {
        if (count($primary_nav[$level1]['#below'][$level2]['#below'])) {
          $mega = TRUE;
          continue;
        }
      }
      foreach(element_children($primary_nav[$level1]['#below']) as $level2) {
        $primary_nav[$level1]['#below'][$level2]['#mega'] = $mega;
      }
    }
  }

  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($variables);
    $colors = _color_page_alter($vars);
  }
}


/**
 * Override or insert variables into the html template.
 */
function bella_process_html(&$vars) {
  // Hook into color.module
  if (module_exists('color')) {
    _color_html_alter($vars);
  }
}

/*
* Create custom LESS variables
*/
function bella_less_variables() {
  // Grab the color pallet saved by the color module.
  $color_pallete = variable_get('color_bella_palette', FALSE);
  // If the color palette hasn't been saved yet, use the default.
  if (empty($color_pallete)) {
    $color_pallete = array(
      'brandprimary' => '#EA9B3E',
    );
  }
  // Generate variables with color values.
  foreach ($color_pallete as $key => $value) {
    $color_pallete['@'.$key] = $color_pallete[$key];
    unset($color_pallete[$key]);
  }
  return $color_pallete;
}
