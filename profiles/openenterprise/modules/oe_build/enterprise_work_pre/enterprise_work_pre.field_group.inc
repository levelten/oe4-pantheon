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
  $field_group->identifier = 'group_rel_market|node|enterprise_etmaster|form';
  $field_group->group_name = 'group_rel_market';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_etmaster';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_rel_label';
  $field_group->data = array(
    'label' => 'Market',
    'weight' => '50',
    'children' => array(
      0 => 'field_service_areas',
      1 => 'field_organization_types',
      2 => 'field_industry_types',
      3 => 'field_organization_sizes',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-rel-market field-group-htabs',
      ),
    ),
  );
  $export['group_rel_market|node|enterprise_etmaster|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rel_persona|node|enterprise_etmaster|form';
  $field_group->group_name = 'group_rel_persona';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_etmaster';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_rel_label';
  $field_group->data = array(
    'label' => 'Persona',
    'weight' => '51',
    'children' => array(),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-rel-persona field-group-htabs',
      ),
    ),
  );
  $export['group_rel_persona|node|enterprise_etmaster|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rel_service|node|enterprise_etmaster|form';
  $field_group->group_name = 'group_rel_service';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_etmaster';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_rel_label';
  $field_group->data = array(
    'label' => 'Services',
    'weight' => '49',
    'children' => array(
      0 => 'field_service_types',
      1 => 'field_service_tags',
      2 => 'field_challenge_types',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-rel-service field-group-htabs',
      ),
    ),
  );
  $export['group_rel_service|node|enterprise_etmaster|form'] = $field_group;

  return $export;
}
