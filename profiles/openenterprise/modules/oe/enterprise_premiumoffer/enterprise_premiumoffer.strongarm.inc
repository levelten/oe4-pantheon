<?php
/**
 * @file
 * enterprise_premiumoffer.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_premiumoffer_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_enterprise_premiumoffer';
  $strongarm->value = 0;
  $export['comment_anonymous_enterprise_premiumoffer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_enterprise_premiumoffer';
  $strongarm->value = 1;
  $export['comment_default_mode_enterprise_premiumoffer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_enterprise_premiumoffer';
  $strongarm->value = '50';
  $export['comment_default_per_page_enterprise_premiumoffer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_enterprise_premiumoffer';
  $strongarm->value = '0';
  $export['comment_enterprise_premiumoffer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_enterprise_premiumoffer';
  $strongarm->value = 1;
  $export['comment_form_location_enterprise_premiumoffer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_enterprise_premiumoffer';
  $strongarm->value = '1';
  $export['comment_preview_enterprise_premiumoffer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_enterprise_premiumoffer';
  $strongarm->value = 1;
  $export['comment_subject_field_enterprise_premiumoffer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enterprise_conversion_settings_node__enterprise_premiumoffer';
  $strongarm->value = array(
    'premiumoffer' => 1,
  );
  $export['enterprise_conversion_settings_node__enterprise_premiumoffer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__enterprise_premiumoffer';
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
        'custom_settings' => FALSE,
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
        'custom_settings' => TRUE,
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
      'conversion_cta_footer' => array(
        'custom_settings' => TRUE,
      ),
      'conversion_cta_sidebar' => array(
        'custom_settings' => TRUE,
      ),
      'conversion_cta_forms' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '4',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '1',
        ),
        'redirect' => array(
          'weight' => '3',
        ),
        'xmlsitemap' => array(
          'weight' => '2',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__enterprise_premiumoffer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_enterprise_premiumoffer';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_enterprise_premiumoffer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_enterprise_premiumoffer';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_enterprise_premiumoffer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_enterprise_premiumoffer';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_enterprise_premiumoffer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_enterprise_premiumoffer';
  $strongarm->value = '1';
  $export['node_preview_enterprise_premiumoffer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_enterprise_premiumoffer';
  $strongarm->value = 0;
  $export['node_submitted_enterprise_premiumoffer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_gender_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_gender_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_service_tags_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_service_tags_pattern'] = $strongarm;

  return $export;
}