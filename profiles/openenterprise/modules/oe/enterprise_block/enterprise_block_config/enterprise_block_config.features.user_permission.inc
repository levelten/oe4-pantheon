<?php
/**
 * @file
 * enterprise_block.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enterprise_block_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any basic_block bean'.
  $permissions['view any basic_block bean'] = array(
    'name' => 'view any basic_block bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
