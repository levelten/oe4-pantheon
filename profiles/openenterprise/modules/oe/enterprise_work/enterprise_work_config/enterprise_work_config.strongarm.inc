<?php
/**
 * @file
 * enterprise_work_config.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_work_config_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_enterprise_work';
  $strongarm->value = 0;
  $export['comment_anonymous_enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_enterprise_work';
  $strongarm->value = 1;
  $export['comment_default_mode_enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_enterprise_work';
  $strongarm->value = '50';
  $export['comment_default_per_page_enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_enterprise_work';
  $strongarm->value = '0';
  $export['comment_enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_enterprise_work';
  $strongarm->value = 1;
  $export['comment_form_location_enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_enterprise_work';
  $strongarm->value = '1';
  $export['comment_preview_enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_enterprise_work';
  $strongarm->value = 1;
  $export['comment_subject_field_enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enterprise_rel_entity_settings_node__enterprise_work';
  $strongarm->value = array(
    'view_display' => 'enterprise_work:page',
    'filter' => array(
      'block_title' => '',
      'facets' => array(
        'taxonomy_term:service_types' => array(
          'display' => 'links',
          'title' => 'Services',
          'item_limit' => '',
        ),
      ),
    ),
    'breadcrumbs' => array(
      'node' => array(
        'model' => 'relview',
        'filtargs' => array(
          'taxonomy_term:service_types' => array(
            'display' => '',
          ),
        ),
      ),
    ),
    'inherit' => array(
      'ref_field' => '',
    ),
  );
  $export['enterprise_rel_entity_settings_node__enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__enterprise_work';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => TRUE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'colorbox' => array(
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
      'ical' => array(
        'custom_settings' => FALSE,
      ),
      'upcoming_events' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '9',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '6',
        ),
        'redirect' => array(
          'weight' => '7',
        ),
        'xmlsitemap' => array(
          'weight' => '8',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_entity_settings_node__enterprise_work';
  $strongarm->value = array(
    'page_intent' => 'i',
    'track_page_uid' => 0,
    'track_term_fields' => array(
      'field_personas' => 0,
      'field_categories' => 0,
      'field_tags' => 0,
      'field_industry_types' => 0,
      'field_organization_sizes' => 0,
      'field_organization_types' => 0,
      'field_service_areas' => 0,
      'field_service_types' => 0,
      'field_service_tags' => 0,
      'field_challenge_types' => 0,
      'field_cta_category' => 0,
      'field_keywords' => 0,
    ),
  );
  $export['intel_entity_settings_node__enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_enterprise_work';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_enterprise_work';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__enterprise_work';
  $strongarm->value = TRUE;
  $export['metatag_enable_node__enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_enterprise_work';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_enterprise_work';
  $strongarm->value = '1';
  $export['node_preview_enterprise_work'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_enterprise_work';
  $strongarm->value = 0;
  $export['node_submitted_enterprise_work'] = $strongarm;

  return $export;
}
