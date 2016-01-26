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

/**
 * Implements hook_preprocess_html()
 */
function bella_preprocess_html(&$vars) {

  // Add Bella button class.
  if (theme_get_setting('bella_buttons')) {
    $vars['classes_array'][] = 'bella-buttons';
  }

}
