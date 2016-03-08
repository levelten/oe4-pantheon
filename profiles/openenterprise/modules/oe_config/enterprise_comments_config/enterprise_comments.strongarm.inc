<?php
/**
 * @file
 * enterprise_comments.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_comments_config_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'disqus_location';
  $strongarm->value = 'block';
  $export['disqus_location'] = $strongarm;

  return $export;
}
