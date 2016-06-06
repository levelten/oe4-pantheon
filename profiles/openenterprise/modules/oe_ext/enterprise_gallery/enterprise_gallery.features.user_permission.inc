<?php
/**
 * @file
 * enterprise_gallery.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enterprise_gallery_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any enterprise_gallery bean'.
  $permissions['create any enterprise_gallery bean'] = array(
    'name' => 'create any enterprise_gallery bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any enterprise_gallery bean'.
  $permissions['delete any enterprise_gallery bean'] = array(
    'name' => 'delete any enterprise_gallery bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any enterprise_gallery bean'.
  $permissions['edit any enterprise_gallery bean'] = array(
    'name' => 'edit any enterprise_gallery bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'view any enterprise_gallery bean'.
  $permissions['view any enterprise_gallery bean'] = array(
    'name' => 'view any enterprise_gallery bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
