<?php
/**
 * @file
 * enterprise_conversion.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enterprise_webform_config_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_form_redirect|node|webform|form';
  $field_group->group_name = 'group_form_redirect';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Form redirect',
    'weight' => '2',
    'children' => array(
      0 => 'field_redirect_url',
      1 => 'field_thankyou',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Form redirect',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-form-redirect field-group-fieldset  display_sidebar',
        'description' => 'Select a thank you page or a custom URL to redirect after form submission.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_form_redirect|node|webform|form'] = $field_group;

  return $export;
}
