<?php
/**
 * @file
 * enterprise_global_config.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enterprise_global_config_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rel_container|node|enterprise_etmaster|form';
  $field_group->group_name = 'group_rel_container';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_etmaster';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_rel_label';
  $field_group->data = array(
    'label' => 'Relevance',
    'weight' => '48',
    'children' => array(
      0 => 'group_rel_global',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-rel-container field-group-htabs',
      ),
    ),
  );
  $export['group_rel_container|node|enterprise_etmaster|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rel_global|node|enterprise_etmaster|form';
  $field_group->group_name = 'group_rel_global';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_etmaster';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_rel_container';
  $field_group->data = array(
    'label' => 'Global',
    'weight' => '48',
    'children' => array(
      0 => 'field_categories',
      1 => 'field_tags',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-rel-global field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_rel_global|node|enterprise_etmaster|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rel_label|node|enterprise_etmaster|form';
  $field_group->group_name = 'group_rel_label';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_etmaster';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Relevance',
    'weight' => '48',
    'children' => array(
      0 => 'group_rel_container',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Relevance',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-rel-label field-group-div display_sidebar',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_rel_label|node|enterprise_etmaster|form'] = $field_group;

  return $export;
}
