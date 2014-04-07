<?php
/**
 * @file
 * enterprise_curated.radioactivity_decay_profile.inc
 */

/**
 * Implements hook_default_radioactivity_decay_profile().
 */
function enterprise_curated_default_radioactivity_decay_profile() {
  $export = array();

  $radioactivity_decay_profile = new stdClass();
  $radioactivity_decay_profile->disabled = FALSE; /* Edit this to true to make a default radioactivity_decay_profile disabled initially */
  $radioactivity_decay_profile->api_version = 1;
  $radioactivity_decay_profile->machine_name = 'curated_post_decay';
  $radioactivity_decay_profile->name = 'Curated Post Decay';
  $radioactivity_decay_profile->description = 'Decay profile for popular curated posts.';
  $radioactivity_decay_profile->enable_decay = 1;
  $radioactivity_decay_profile->granularity = '3600';
  $radioactivity_decay_profile->half_life = 432000;
  $radioactivity_decay_profile->cut_off = '0.1';
  $radioactivity_decay_profile->storage = 'Live';
  $export['curated_post_decay'] = $radioactivity_decay_profile;

  return $export;
}
