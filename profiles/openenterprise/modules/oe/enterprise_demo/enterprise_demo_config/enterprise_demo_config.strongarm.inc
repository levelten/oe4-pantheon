<?php
/**
 * @file
 * enterprise_demo.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_demo_config_strongarm() {
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
  $strongarm->name = 'enterprise_intel_vocab_field_map';
  $strongarm->value = array(
    'blog_categories' => 'field_blog_categories',
    'blog_tags' => 'field_blog_tags',
  );
  $export['enterprise_intel_vocab_field_map'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'error_level';
  $strongarm->value = 0;
  $export['error_level'] = $strongarm;

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
  $strongarm->name = 'intel_entity_settings_taxonomy__categories';
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
  $export['intel_entity_settings_taxonomy__categories'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_entity_settings_taxonomy__tags';
  $strongarm->value = array(
    'page_intent' => 'i',
    'track_page_terms' => 1,
  );
  $export['intel_entity_settings_taxonomy__tags'] = $strongarm;

  return $export;
}