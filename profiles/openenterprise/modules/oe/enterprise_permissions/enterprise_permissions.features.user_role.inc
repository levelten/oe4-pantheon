<?php
/**
 * @file
 * enterprise_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function enterprise_permissions_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 10,
  );

  // Exported role: demo.
  $roles['demo'] = array(
    'name' => 'demo',
    'weight' => 6,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 4,
  );

  // Exported role: manager.
  $roles['manager'] = array(
    'name' => 'manager',
    'weight' => 5,
  );

  // Exported role: writer.
  $roles['writer'] = array(
    'name' => 'writer',
    'weight' => 3,
  );

  return $roles;
}
