<?php
/**
 * @file
 */

/**
 * Implements hook_ds_fields_info().
 */
function enterprise_rel_ds_fields_info($entity_type) {
  $node = array();
  $user = array();

  //dsm($entity_type);

  return array('node' => $node, 'user' => $user);
}