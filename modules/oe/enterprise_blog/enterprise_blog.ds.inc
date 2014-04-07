<?php
/**
 * @file
 * enterprise_blog.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enterprise_blog_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_blog|blog_featured';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_blog';
  $ds_fieldsetting->view_mode = 'blog_featured';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
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
    'submit_info' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|enterprise_blog|blog_featured'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_blog|blog_mini';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_blog';
  $ds_fieldsetting->view_mode = 'blog_mini';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
        'field_delimiter' => '',
        'field_formatter_class' => '',
        'linked_field' => array(
          'linked' => 0,
          'destination' => '',
          'advanced' => array(
            'title' => '',
            'target' => '',
            'class' => '',
            'rel' => '',
            'text' => '',
          ),
        ),
        'conditions' => array(),
      ),
    ),
  );
  $export['node|enterprise_blog|blog_mini'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_blog|blog_related';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_blog';
  $ds_fieldsetting->view_mode = 'blog_related';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|enterprise_blog|blog_related'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_blog|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_blog';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'social_media_share_buttons' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'unpublished' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'submit_info' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'field_delimiter' => '',
        'field_formatter_class' => 'sticky-hide',
        'conditions' => array(),
      ),
    ),
    'about_author' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'prev_next_node' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|enterprise_blog|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_blog|rss';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_blog';
  $ds_fieldsetting->view_mode = 'rss';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'node_link' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|enterprise_blog|rss'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_blog|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_blog';
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
    'submit_info' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'field_delimiter' => '',
        'field_formatter_class' => 'author',
        'conditions' => array(),
      ),
    ),
  );
  $export['node|enterprise_blog|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enterprise_blog_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_blog|blog_featured';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_blog';
  $ds_layout->view_mode = 'blog_featured';
  $ds_layout->layout = 'bootstrap_2col_fluid_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'submit_info',
        2 => 'body',
      ),
      'right' => array(
        3 => 'field_image',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'submit_info' => 'left',
      'body' => 'left',
      'field_image' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'style-blog-featured' => 'style-blog-featured',
      ),
      'left' => array(
        'span5' => 'span5',
      ),
      'right' => array(
        'span7' => 'span7',
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
  $export['node|enterprise_blog|blog_featured'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_blog|blog_mini';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_blog';
  $ds_layout->view_mode = 'blog_mini';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'title' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'style-blog-mini' => 'style-blog-mini',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|enterprise_blog|blog_mini'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_blog|blog_related';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_blog';
  $ds_layout->view_mode = 'blog_related';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_image',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|enterprise_blog|blog_related'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_blog|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_blog';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'submit_info',
      ),
      'sticky' => array(
        1 => 'social_media_share_buttons',
        2 => 'prev_next_node',
      ),
      'middle' => array(
        3 => 'field_image',
        4 => 'body',
        5 => 'unpublished',
      ),
      'footer' => array(
        6 => 'field_blog_tags',
        7 => 'field_energy_level',
        8 => 'about_author',
        9 => 'comments',
      ),
    ),
    'fields' => array(
      'submit_info' => 'header',
      'social_media_share_buttons' => 'sticky',
      'prev_next_node' => 'sticky',
      'field_image' => 'middle',
      'body' => 'middle',
      'unpublished' => 'middle',
      'field_blog_tags' => 'footer',
      'field_energy_level' => 'footer',
      'about_author' => 'footer',
      'comments' => 'footer',
    ),
    'classes' => array(
      'layout_class' => array(
        'style-blog-full' => 'style-blog-full',
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
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|enterprise_blog|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_blog|rss';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_blog';
  $ds_layout->view_mode = 'rss';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_image',
        2 => 'author',
        3 => 'post_date',
        4 => 'body',
        5 => 'node_link',
        6 => 'field_energy_level',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_image' => 'ds_content',
      'author' => 'ds_content',
      'post_date' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
      'field_energy_level' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|enterprise_blog|rss'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_blog|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_blog';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_2col_fluid_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'submit_info',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title' => 'right',
      'submit_info' => 'right',
      'body' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'style-blog-teaser' => 'style-blog-teaser',
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
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|enterprise_blog|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function enterprise_blog_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'blog_featured';
  $ds_view_mode->label = 'Blog Featured';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['blog_featured'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'blog_mini';
  $ds_view_mode->label = 'Blog Mini';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['blog_mini'] = $ds_view_mode;

  return $export;
}
