<?php
/**
 * @file
 * enterprise_events.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_events_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_enterprise_event';
  $strongarm->value = 0;
  $export['comment_anonymous_enterprise_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_enterprise_event';
  $strongarm->value = 1;
  $export['comment_default_mode_enterprise_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_enterprise_event';
  $strongarm->value = '50';
  $export['comment_default_per_page_enterprise_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_enterprise_event';
  $strongarm->value = '0';
  $export['comment_enterprise_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_enterprise_event';
  $strongarm->value = 1;
  $export['comment_form_location_enterprise_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_enterprise_event';
  $strongarm->value = '1';
  $export['comment_preview_enterprise_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_enterprise_event';
  $strongarm->value = 1;
  $export['comment_subject_field_enterprise_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_region_blocks';
  $strongarm->value = array(
    'event_details' => array(
      'title' => 'Event Details',
      'info' => 'node_enterprise_event_full',
    ),
  );
  $export['ds_extras_region_blocks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_region_to_block';
  $strongarm->value = 1;
  $export['ds_extras_region_to_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__enterprise_event';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => TRUE,
      ),
      'nopremium_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'blog_featured' => array(
        'custom_settings' => FALSE,
      ),
      'blog_mini' => array(
        'custom_settings' => FALSE,
      ),
      'past_webcast' => array(
        'custom_settings' => FALSE,
      ),
      'upcoming_webcast' => array(
        'custom_settings' => FALSE,
      ),
      'icon' => array(
        'custom_settings' => FALSE,
      ),
      'upcoming_events' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '5',
        ),
        'redirect' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__enterprise_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_enterprise_event';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_enterprise_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_enterprise_event';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_enterprise_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_enterprise_event';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_enterprise_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_enterprise_event';
  $strongarm->value = '0';
  $export['node_preview_enterprise_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_enterprise_event';
  $strongarm->value = 1;
  $export['node_submitted_enterprise_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_enterprise_event_pattern';
  $strongarm->value = 'resources/event/[node:title]';
  $export['pathauto_node_enterprise_event_pattern'] = $strongarm;

  return $export;
}
