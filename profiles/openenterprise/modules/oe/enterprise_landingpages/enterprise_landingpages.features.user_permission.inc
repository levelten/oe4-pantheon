<?php
/**
 * @file
 * enterprise_landingpages.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enterprise_landingpages_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any cta bean'.
  $permissions['view any cta bean'] = array(
    'name' => 'view any cta bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
