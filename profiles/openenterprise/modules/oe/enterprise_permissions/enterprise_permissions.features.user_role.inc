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

  $roles['writer'] = array(
    'name' => 'writer',
    'weight' => 3,
  );

  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 4,
  );

  $roles['manager'] = array(
    'name' => 'manager',
    'weight' => 5,
  );

  $roles['demo'] = array(
    'name' => 'demo',
    'weight' => 6,
  );

  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 10,
  );

  return $roles;
}
