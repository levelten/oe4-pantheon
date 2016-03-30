<?php
/**
 * @file
 * enterprise_landingpage_config.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_landingpage_config_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_enterprise_landingpage';
  $strongarm->value = 0;
  $export['comment_anonymous_enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_enterprise_landingpage';
  $strongarm->value = 1;
  $export['comment_default_mode_enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_enterprise_landingpage';
  $strongarm->value = '50';
  $export['comment_default_per_page_enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_enterprise_landingpage';
  $strongarm->value = '0';
  $export['comment_enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_enterprise_landingpage';
  $strongarm->value = 1;
  $export['comment_form_location_enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_enterprise_landingpage';
  $strongarm->value = '1';
  $export['comment_preview_enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_enterprise_landingpage';
  $strongarm->value = 1;
  $export['comment_subject_field_enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enterprise_conversion_settings_node__enterprise_landingpage';
  $strongarm->value = array(
    'landingpage' => 1,
  );
  $export['enterprise_conversion_settings_node__enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__enterprise_landingpage';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'conversion_cta_footer' => array(
        'custom_settings' => TRUE,
      ),
      'conversion_cta_sidebar' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'colorbox' => array(
        'custom_settings' => FALSE,
      ),
      'conversion_cta_forms' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'featured' => array(
        'custom_settings' => FALSE,
      ),
      'mini' => array(
        'custom_settings' => FALSE,
      ),
      'image' => array(
        'custom_settings' => FALSE,
      ),
      'text_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_stacked' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '6',
        ),
        'redirect' => array(
          'weight' => '5',
        ),
        'metatags' => array(
          'weight' => '8',
        ),
        'xmlsitemap' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_entity_settings_node__enterprise_landingpage';
  $strongarm->value = array(
    'page_intent' => 'l',
    'track_page_uid' => 0,
  );
  $export['intel_entity_settings_node__enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_enterprise_landingpage';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_enterprise_landingpage';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_enterprise_landingpage';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_enterprise_landingpage';
  $strongarm->value = '1';
  $export['node_preview_enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_enterprise_landingpage';
  $strongarm->value = 0;
  $export['node_submitted_enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_enterprise_landingpage_pattern';
  $strongarm->value = 'offer/[node:title]';
  $export['pathauto_node_enterprise_landingpage_pattern'] = $strongarm;

  return $export;
}
