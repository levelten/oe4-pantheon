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
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Relevance',
    'weight' => '10',
    'children' => array(
      0 => 'group_rel_person',
      1 => 'group_rel_subject',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Relevance',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'display_sidebar rel-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_rel_container|node|enterprise_etmaster|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rel_person|node|enterprise_etmaster|form';
  $field_group->group_name = 'group_rel_person';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_etmaster';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_rel_container';
  $field_group->data = array(
    'label' => 'Person',
    'weight' => '10',
    'children' => array(
      0 => 'field_personas',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsed',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),

    ),
  );
  $export['group_rel_person|node|enterprise_etmaster|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rel_subject|node|enterprise_etmaster|form';
  $field_group->group_name = 'group_rel_subject';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_etmaster';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_rel_container';
  $field_group->data = array(
    'label' => 'Subject',
    'weight' => '0',
    'children' => array(
      0 => 'field_categories',
      1 => 'field_tags',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_rel_subject|node|enterprise_etmaster|form'] = $field_group;

  return $export;
}
