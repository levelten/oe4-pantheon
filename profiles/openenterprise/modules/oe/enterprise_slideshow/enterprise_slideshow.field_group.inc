<?php
/**
 * @file
 * enterprise_slideshow.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enterprise_slideshow_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_desktop_image|field_collection_item|field_enterprise_slides|full';
  $field_group->group_name = 'group_desktop_image';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_enterprise_slides';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Desktop Image',
    'weight' => '1',
    'children' => array(
      0 => 'field_enterprise_slideshow_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Desktop Image',
      'instance_settings' => array(
        'classes' => 'group-desktop-image field-group-div hidden-xs',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_desktop_image|field_collection_item|field_enterprise_slides|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enterprise_slide_settings|bean|enterprise_slideshow|form';
  $field_group->group_name = 'group_enterprise_slide_settings';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'enterprise_slideshow';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Settings',
    'weight' => '9',
    'children' => array(
      0 => 'revision',
      1 => 'view_mode',
      2 => 'redirect',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Settings',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-enterprise-slide-settings field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_enterprise_slide_settings|bean|enterprise_slideshow|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enterprise_slideshow|field_collection_item|field_enterprise_slides|default';
  $field_group->group_name = 'group_enterprise_slideshow';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_enterprise_slides';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '0',
    'children' => array(
      0 => 'field_enterprise_slideshow_desc',
      1 => 'field_enterprise_slideshow_link',
      2 => 'field_enterprise_slideshow_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-enterprise-slideshow field-group-div',
      ),
    ),
  );
  $export['group_enterprise_slideshow|field_collection_item|field_enterprise_slides|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enterprise_slideshow|field_collection_item|field_enterprise_slides|enterprise_slideshow_wide';
  $field_group->group_name = 'group_enterprise_slideshow';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_enterprise_slides';
  $field_group->mode = 'enterprise_slideshow_wide';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '0',
    'children' => array(
      0 => 'field_enterprise_slideshow_title',
      1 => 'field_enterprise_slideshow_desc',
      2 => 'field_enterprise_slideshow_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption',
      'instance_settings' => array(
        'classes' => 'group-enterprise-slideshow field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_enterprise_slideshow|field_collection_item|field_enterprise_slides|enterprise_slideshow_wide'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enterprise_slideshow|field_collection_item|field_enterprise_slides|full';
  $field_group->group_name = 'group_enterprise_slideshow';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_enterprise_slides';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '0',
    'children' => array(
      0 => 'field_enterprise_slideshow_desc',
      1 => 'field_enterprise_slideshow_link',
      2 => 'field_enterprise_slideshow_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption',
      'instance_settings' => array(
        'classes' => 'group-enterprise-slideshow field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_enterprise_slideshow|field_collection_item|field_enterprise_slides|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mobile_image|field_collection_item|field_enterprise_slides|full';
  $field_group->group_name = 'group_mobile_image';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_enterprise_slides';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Mobile Image',
    'weight' => '2',
    'children' => array(
      0 => 'field_enterprise_slideshow_mobi',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Mobile Image',
      'instance_settings' => array(
        'classes' => 'group-mobile-image field-group-div visible-phone',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_mobile_image|field_collection_item|field_enterprise_slides|full'] = $field_group;

  return $export;
}
