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
      'brandsecondary' => '#F5F5F5',
      'brandaccent' => '#FFF',
      'brandaccent2' => '#EA9B3E',
      'brandaccent3' => '#EA9B3E',
    );
  }
  // Generate variables with color values.
  foreach ($color_pallete as $key => $value) {
    $color_pallete['@'.$key] = $color_pallete[$key];
    unset($color_pallete[$key]);
  }
  return $color_pallete;
}
