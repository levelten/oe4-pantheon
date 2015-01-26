<?php
/**
 * @file
 * enterprise_news.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enterprise_news_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_news|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_news';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'social_media_share_buttons' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'submit_info' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|enterprise_news|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_news|recent_news';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_news';
  $ds_fieldsetting->view_mode = 'recent_news';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'strong',
        'class' => '',
        'field_delimiter' => '',
        'field_formatter_class' => '',
        'conditions' => array(),
      ),
    ),
    'post_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
  );
  $export['node|enterprise_news|recent_news'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_news|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_news';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'field_delimiter' => '',
        'field_formatter_class' => '',
        'conditions' => array(),
      ),
    ),
    'date_stacked' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|enterprise_news|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enterprise_news_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_news|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_news';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'submit_info',
      ),
      'sticky' => array(
        1 => 'social_media_share_buttons',
      ),
      'middle' => array(
        2 => 'field_news_image',
        3 => 'body',
        4 => 'field_news_link',
      ),
    ),
    'fields' => array(
      'submit_info' => 'header',
      'social_media_share_buttons' => 'sticky',
      'field_news_image' => 'middle',
      'body' => 'middle',
      'field_news_link' => 'middle',
    ),
    'classes' => array(
      'layout_class' => array(
        'style-news-full' => 'style-news-full',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'sticky' => 'div',
      'middle' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|enterprise_news|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_news|recent_news';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_news';
  $ds_layout->view_mode = 'recent_news';
  $ds_layout->layout = 'bootstrap_2col_fluid_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'post_date',
      ),
      'right' => array(
        1 => 'title',
      ),
    ),
    'fields' => array(
      'post_date' => 'left',
      'title' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'style-news-recent' => 'style-news-recent',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|enterprise_news|recent_news'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_news|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_news';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_2_10';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'date_stacked',
      ),
      'right' => array(
        1 => 'title',
        2 => 'body',
        3 => 'field_news_link',
      ),
    ),
    'fields' => array(
      'date_stacked' => 'left',
      'title' => 'right',
      'body' => 'right',
      'field_news_link' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'style-news-teaser' => 'style-news-teaser',
      ),
      'left' => array(
        'col-md-2' => 'col-md-2',
      ),
      'right' => array(
        'col-md-10' => 'col-md-10',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|enterprise_news|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function enterprise_news_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'recent_news';
  $ds_view_mode->label = 'News: Recent';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['recent_news'] = $ds_view_mode;

  return $export;
}
