<?php
/**
 * @file
 * enterprise_demo.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_demo_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_developer';
  $strongarm->value = 1;
  $export['disqus_developer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enterprise_intel_entity_settings_node__enterprise_blog';
  $strongarm->value = array(
    'field_intel_event_col' => 'field_intel_event_col',
    'field_page_attribute_col' => 'field_page_attribute_col',
    'field_visitor_attribute_col' => 'field_visitor_attribute_col',
    'field_blog_categories' => 'field_blog_categories',
  );
  $export['enterprise_intel_entity_settings_node__enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enterprise_intel_entity_settings_node__enterprise_landingpage';
  $strongarm->value = array(
    'field_intel_event_col' => 'field_intel_event_col',
    'field_page_attribute_col' => 'field_page_attribute_col',
    'field_visitor_attribute_col' => 'field_visitor_attribute_col',
    'field_blog_categories' => 0,
  );
  $export['enterprise_intel_entity_settings_node__enterprise_landingpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enterprise_intel_entity_settings_node__enterprise_thankyou';
  $strongarm->value = array(
    'field_intel_event_col' => 'field_intel_event_col',
    'field_page_attribute_col' => 'field_page_attribute_col',
    'field_visitor_attribute_col' => 'field_visitor_attribute_col',
    'field_blog_categories' => 0,
  );
  $export['enterprise_intel_entity_settings_node__enterprise_thankyou'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enterprise_intel_entity_settings_node__webform';
  $strongarm->value = array(
    'field_intel_event_col' => 0,
    'field_page_attribute_col' => 0,
    'field_visitor_attribute_col' => 0,
    'field_blog_categories' => 0,
  );
  $export['enterprise_intel_entity_settings_node__webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enterprise_intel_vocab_field_map';
  $strongarm->value = array(
    'blog_categories' => 'field_blog_categories',
    'blog_tags' => 'field_blog_tags',
  );
  $export['enterprise_intel_vocab_field_map'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_entity_settings_node__enterprise_blog';
  $strongarm->value = array(
    'page_intent' => 't',
    'track_page_uid' => 1,
  );
  $export['intel_entity_settings_node__enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_entity_settings_taxonomy__blog_categories';
  $strongarm->value = array(
    'page_intent' => 'i',
    'track_page_terms' => 1,
    'page_attribute' => array(
      'key' => 'j',
      'title' => 'Subject',
    ),
    'track_page_terms_visitor' => 1,
    'visitor_attribute' => array(
      'key' => '',
      'description' => 'Number of times a page subjects have been viewed',
    ),
  );
  $export['intel_entity_settings_taxonomy__blog_categories'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_entity_settings_taxonomy__blog_tags';
  $strongarm->value = array(
    'page_intent' => 'i',
    'track_page_terms' => 1,
  );
  $export['intel_entity_settings_taxonomy__blog_tags'] = $strongarm;

  /*
  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'home';
  $export['site_frontpage'] = $strongarm;
  */

  return $export;
}