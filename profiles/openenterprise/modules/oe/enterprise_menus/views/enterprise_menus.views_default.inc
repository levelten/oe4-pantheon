<?php

/**
 * Implements hook_views_default_views_alter().
 */
function enterprise_menus_views_default_views_alter(&$views) {
  // Disable the default message view, if it exists.
  if (isset($views['message'])) {
    $views['message']->disabled = TRUE;
  }
}
