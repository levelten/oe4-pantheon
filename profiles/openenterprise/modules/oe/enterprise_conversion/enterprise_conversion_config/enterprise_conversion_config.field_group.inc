<?php
/**
 * @file
 * enterprise_conversion.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enterprise_conversion_config_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_landingpage_redirect|bean|cta|form';
  $field_group->group_name = 'group_landingpage_redirect';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'cta';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Landing page redirect',
    'weight' => '3',
    'children' => array(
      0 => 'field_landingpage',
      1 => 'field_redirect_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Landing page redirect',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-landingpage-redirect field-group-fieldset display_sidebar',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_landingpage_redirect|bean|cta|form'] = $field_group;

  return $export;
}
