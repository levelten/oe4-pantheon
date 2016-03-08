<?php
/**
 * @file
 * enterprise_premiumoffer.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enterprise_premiumoffer_config_field_group_info() {
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
    'weight' => '8',
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

  return $export;
}
