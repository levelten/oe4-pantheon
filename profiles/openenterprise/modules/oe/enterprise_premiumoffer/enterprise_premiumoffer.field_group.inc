<?php
/**
 * @file
 * enterprise_premiumoffer.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enterprise_premiumoffer_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_assets_file|node|enterprise_premiumoffer|form';
  $field_group->group_name = 'group_assets_file';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_premiumoffer';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_assets';
  $field_group->data = array(
    'label' => 'File assets',
    'weight' => '13',
    'children' => array(
      0 => 'field_files',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-assets-file field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_assets_file|node|enterprise_premiumoffer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_assets_image|node|enterprise_premiumoffer|form';
  $field_group->group_name = 'group_assets_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_premiumoffer';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_assets';
  $field_group->data = array(
    'label' => 'Image assets',
    'weight' => '12',
    'children' => array(
      0 => 'field_images',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-assets-image field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_assets_image|node|enterprise_premiumoffer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_assets|node|enterprise_premiumoffer|form';
  $field_group->group_name = 'group_assets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_premiumoffer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Assets',
    'weight' => '6',
    'children' => array(
      0 => 'group_assets_file',
      1 => 'group_assets_image',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_assets|node|enterprise_premiumoffer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cta|node|enterprise_premiumoffer|form';
  $field_group->group_name = 'group_cta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_premiumoffer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Default CTAs',
    'weight' => '9',
    'children' => array(
      0 => 'field_cta_footer',
      1 => 'field_cta_sidebar',
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
  $export['group_cta|node|enterprise_premiumoffer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_patient_charateristics|node|enterprise_premiumoffer|form';
  $field_group->group_name = 'group_patient_charateristics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_premiumoffer';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_rel';
  $field_group->data = array(
    'label' => 'Patient Characteristics',
    'weight' => '18',
    'children' => array(
      0 => 'field_genders',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-patient-charateristics field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_patient_charateristics|node|enterprise_premiumoffer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rel|node|enterprise_premiumoffer|form';
  $field_group->group_name = 'group_rel';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_premiumoffer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Relevancy',
    'weight' => '17',
    'children' => array(
      0 => 'field_service_types',
      1 => 'field_procedure_tags',
      2 => 'group_patient_charateristics',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Relevancy',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-rel field-group-div display_sidebar',
        'description' => 'Select any categories that are relevant to the premium offer.
<br /><br />',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_rel|node|enterprise_premiumoffer|form'] = $field_group;

  return $export;
}
