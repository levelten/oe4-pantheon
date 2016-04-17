<?php
/**
 * @file
 * enterprise_work_pre.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enterprise_work_pre_field_group_info() {
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
      0 => 'group_rel_subject',
      1 => 'group_rel_subject',
      2 => 'group_rel_organization',
      3 => 'group_rel_person',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsed',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'display_sidebar rel-fieldset',
        'description' => '',
      ),
    ),
  );
  $export['group_rel_container|node|enterprise_etmaster|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rel_organization|node|enterprise_etmaster|form';
  $field_group->group_name = 'group_rel_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_etmaster';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_rel_container';
  $field_group->data = array(
    'label' => 'Organization',
    'weight' => '4',
    'children' => array(
      0 => 'field_industry_types',
      1 => 'field_organization_sizes',
      2 => 'field_organization_types',
      3 => 'field_service_areas',
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
  $export['group_rel_organization|node|enterprise_etmaster|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rel_solution|node|enterprise_etmaster|form';
  $field_group->group_name = 'group_rel_solution';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_etmaster';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_rel_container';
  $field_group->data = array(
    'label' => 'Solutions',
    'weight' => '2',
    'children' => array(
      0 => 'field_service_types',
      1 => 'field_service_tags',
      2 => 'field_challenge_types',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Person',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_rel_service|node|enterprise_etmaster|form'] = $field_group;

  return $export;
}
