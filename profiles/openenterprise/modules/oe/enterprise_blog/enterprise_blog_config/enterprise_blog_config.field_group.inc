<?php
/**
 * @file
 * enterprise_blog_config.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enterprise_blog_config_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_div|node|enterprise_blog|mini';
  $field_group->group_name = 'group_div';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'enterprise_blog';
  $field_group->mode = 'mini';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Body Wrapper',
    'weight' => '1',
    'children' => array(
      0 => 'title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Body Wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'card-block',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_div|node|enterprise_blog|mini'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Body Wrapper');

  return $field_groups;
}
