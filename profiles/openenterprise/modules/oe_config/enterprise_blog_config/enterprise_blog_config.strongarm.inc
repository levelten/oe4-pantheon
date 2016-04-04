<?php
/**
 * @file
 * enterprise_blog_config.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_blog_config_strongarm() {
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
  $strongarm->name = 'enterprise_rel_entity_settings_node__enterprise_blog';
  $strongarm->value = array(
    'view_display' => 'enterprise_blog:page',
    'filter' => array(
      'block_title' => '',
      'facets' => array(
        'taxonomy_term:categories' => array(
          'display' => 'links',
          'title' => '',
          'item_limit' => '',
        ),
        'user:user' => array(
          'display' => 'links',
          'title' => 'Authors',
          'item_limit' => '',
        ),
        'taxonomy_term:tags' => array(
          'display' => 'links',
          'title' => '',
          'item_limit' => '',
        ),
      ),
    ),
    'breadcrumbs' => array(
      'node' => array(
        'model' => 'relview',
        'filtargs' => array(
          'taxonomy_term:categories' => array(
            'display' => '',
          ),
          'user:user' => array(
            'display' => '',
          ),
        ),
      ),
    ),
    'inherit' => array(
      'ref_field' => '',
    ),
  );
  $export['enterprise_rel_entity_settings_node__enterprise_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__enterprise_blog';
  $strongarm->value = array(
    'view_modes' => array(
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
      'content_hover' => array(
        'custom_settings' => FALSE,
      ),
      'featured' => array(
        'custom_settings' => TRUE,
      ),
      'mini' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
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
      'image' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_stacked' => array(
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
        'metatags' => array(
          'weight' => '40',
        ),
        'xmlsitemap' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'disqus' => array(
          'mini' => array(
            'weight' => '1002',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '1002',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1002',
            'visible' => FALSE,
          ),
        ),
      ),
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
