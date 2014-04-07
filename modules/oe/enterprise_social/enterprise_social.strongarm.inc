<?php
/**
 * @file
 * enterprise_social.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_social_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'socialmedia_default_link_class_profile';
  $strongarm->value = 'btn btn-default btn-social btn-social-profile';
  $export['socialmedia_default_link_class_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'socialmedia_default_link_class_sharing';
  $strongarm->value = 'btn btn-default btn-social btn-social-share';
  $export['socialmedia_default_link_class_sharing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'socialmedia_icon_default_style';
  $strongarm->value = 'enterprise_vector:32x32';
  $export['socialmedia_icon_default_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'socialmedia_platforms_site';
  $strongarm->value = array(
    'twitter' => 'twitter',
    'facebook' => 'facebook',
    'flickr' => 'flickr',
    'googleplus' => 'googleplus',
    'linkedin' => 'linkedin',
    'pinterest' => 'pinterest',
    'rss' => 'rss',
    'slideshare' => 'slideshare',
    'vimeo' => 'vimeo',
    'youtube' => 'youtube',
    'addthis' => 'addthis',
  );
  $export['socialmedia_platforms_site'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'socialmedia_platforms_user';
  $strongarm->value = array(
    'twitter' => 'twitter',
    'facebook' => 'facebook',
    'flickr' => 'flickr',
    'googleplus' => 'googleplus',
    'linkedin' => 'linkedin',
    'pinterest' => 'pinterest',
    'rss' => 'rss',
    'slideshare' => 'slideshare',
    'vimeo' => 'vimeo',
    'youtube' => 'youtube',
    'addthis' => 'addthis',
  );
  $export['socialmedia_platforms_user'] = $strongarm;

  return $export;
}
