<?php
/**
 * @file
 * enterprise_landingpage_config.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enterprise_landingpage_config_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cta|node|enterprise_landingpage|form';
  $field_group->group_name = 'group_cta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_landingpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Default CTAs',
    'weight' => '2',
    'children' => array(
      0 => 'field_landingpage_cta_sidebar',
      1 => 'field_landingpage_cta_footer',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cta field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_cta|node|enterprise_landingpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_form_container|node|enterprise_landingpage|form';
  $field_group->group_name = 'group_form_container';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_landingpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Form',
    'weight' => '3',
    'children' => array(
      0 => 'group_form_redirect',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Form',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-form-container field-group-fieldset display_sidebar',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_form_container|node|enterprise_landingpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_form_redirect|node|enterprise_landingpage|form';
  $field_group->group_name = 'group_form_redirect';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_landingpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Form redirect',
    'weight' => '4',
    'children' => array(
      0 => 'field_redirect_url',
      1 => 'field_thankyou',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Form redirect',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-form-redirect field-group-fieldset display_sidebar',
        'description' => 'Select a thank you page or a custom URL to redirect after form submission. If nothing is selected the form\'s default submission values will be used.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_form_redirect|node|enterprise_landingpage|form'] = $field_group;
  $export['group_form_redirect|node|enterprise_landingpage|form'] = $field_group;

  return $export;
}
