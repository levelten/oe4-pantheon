<?php
/**
 * @file
 * enterprise_blog.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_blog_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_enterprise_blog';
  $strongarm->value = 0;
  $export['comment_anonymous_enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_enterprise_blog';
  $strongarm->value = 1;
  $export['comment_default_mode_enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_enterprise_blog';
  $strongarm->value = '50';
  $export['comment_default_per_page_enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_enterprise_blog';
  $strongarm->value = '0';
  $export['comment_enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_enterprise_blog';
  $strongarm->value = 1;
  $export['comment_form_location_enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_enterprise_blog';
  $strongarm->value = '1';
  $export['comment_preview_enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_enterprise_blog';
  $strongarm->value = 1;
  $export['comment_subject_field_enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_field_template';
  $strongarm->value = 1;
  $export['ds_extras_field_template'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__enterprise_blog';
  $strongarm->value = array(
    'view_modes' => array(
      'article_mini' => array(
        'custom_settings' => TRUE,
      ),
      'article_quote' => array(
        'custom_settings' => TRUE,
      ),
      'article_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => TRUE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'video_grid' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'article_featured' => array(
        'custom_settings' => TRUE,
      ),
      'article_related' => array(
        'custom_settings' => TRUE,
      ),
      'content_hover' => array(
        'custom_settings' => FALSE,
      ),
      'featured' => array(
        'custom_settings' => TRUE,
      ),
      'blog_full' => array(
        'custom_settings' => FALSE,
      ),
      'mini' => array(
        'custom_settings' => TRUE,
      ),
      'blog_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'blog_related' => array(
        'custom_settings' => TRUE,
      ),
      'list' => array(
        'custom_settings' => FALSE,
      ),
      'recent_news' => array(
        'custom_settings' => FALSE,
      ),
      'text_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'colorbox' => array(
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
          'weight' => '7',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_enterprise_blog';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_enterprise_blog';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_enterprise_blog';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_enterprise_blog';
  $strongarm->value = '1';
  $export['node_preview_enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_enterprise_blog';
  $strongarm->value = 0;
  $export['node_submitted_enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_enterprise_blog_pattern';
  $strongarm->value = 'blog/[node:author]/[node:title]';
  $export['pathauto_node_enterprise_blog_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_enterprise_blog';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_enterprise_blog'] = $strongarm;

  return $export;
}
