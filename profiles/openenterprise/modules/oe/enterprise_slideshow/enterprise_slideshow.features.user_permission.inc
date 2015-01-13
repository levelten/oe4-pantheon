<?php
/**
 * @file
 * enterprise_slideshow.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enterprise_slideshow_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any enterprise_slideshow bean'.
  $permissions['view any enterprise_slideshow bean'] = array(
    'name' => 'view any enterprise_slideshow bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
