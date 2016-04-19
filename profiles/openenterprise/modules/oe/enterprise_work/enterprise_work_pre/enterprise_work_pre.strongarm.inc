<?php
/**
 * @file
 * enterprise_work_pre.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_work_pre_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_entity_settings_taxonomy__challenge_types';
  $strongarm->value = array(
    'page_intent' => 'i',
    'track_page_terms' => 0,
    'track_page_terms_visitor' => 0,
  );
  $export['intel_entity_settings_taxonomy__challenge_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_entity_settings_taxonomy__industry_types';
  $strongarm->value = array(
    'page_intent' => 'i',
    'track_page_terms' => 0,
    'track_page_terms_visitor' => 0,
  );
  $export['intel_entity_settings_taxonomy__industry_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_entity_settings_taxonomy__organization_sizes';
  $strongarm->value = array(
    'page_intent' => 'i',
    'track_page_terms' => 0,
    'track_page_terms_visitor' => 0,
  );
  $export['intel_entity_settings_taxonomy__organization_sizes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_entity_settings_taxonomy__organization_types';
  $strongarm->value = array(
    'page_intent' => 'i',
    'track_page_terms' => 0,
    'track_page_terms_visitor' => 0,
  );
  $export['intel_entity_settings_taxonomy__organization_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_entity_settings_taxonomy__service_areas';
  $strongarm->value = array(
    'page_intent' => 'i',
    'track_page_terms' => 0,
    'track_page_terms_visitor' => 0,
  );
  $export['intel_entity_settings_taxonomy__service_areas'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_entity_settings_taxonomy__service_tags';
  $strongarm->value = array(
    'page_intent' => 'i',
    'track_page_terms' => 0,
    'track_page_terms_visitor' => 0,
  );
  $export['intel_entity_settings_taxonomy__service_tags'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'intel_entity_settings_taxonomy__service_types';
  $strongarm->value = array(
    'page_intent' => 'i',
    'track_page_terms' => 0,
    'track_page_terms_visitor' => 0,
  );
  $export['intel_entity_settings_taxonomy__service_types'] = $strongarm;

  return $export;
}
