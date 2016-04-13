<?php
/**
 * @file
 * enterprise_curated.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enterprise_curated_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_curated|curated_featured';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_curated';
  $ds_fieldsetting->view_mode = 'curated_featured';
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
  $export['node|enterprise_curated|curated_featured'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_curated|curated_mini';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_curated';
  $ds_fieldsetting->view_mode = 'curated_mini';
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
  );
  $export['node|enterprise_curated|curated_mini'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_curated|curated_related';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_curated';
  $ds_fieldsetting->view_mode = 'curated_related';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|enterprise_curated|curated_related'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_curated|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_curated';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'social_media_share_buttons' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'unpublished' => array(
      'weight' => '4',
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
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comment_count' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'field_delimiter' => '',
        'field_formatter_class' => 'sticky-hide',
        'conditions' => array(),
      ),
    ),
  );
  $export['node|enterprise_curated|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_curated|rss';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_curated';
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
  $export['node|enterprise_curated|rss'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|enterprise_curated|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'enterprise_curated';
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
  $export['node|enterprise_curated|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enterprise_curated_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_curated|curated_featured';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_curated';
  $ds_layout->view_mode = 'curated_featured';
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
        'style-curated-featured' => 'style-curated-featured',
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
  $export['node|enterprise_curated|curated_featured'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_curated|curated_mini';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_curated';
  $ds_layout->view_mode = 'curated_mini';
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
        'style-curated-mini' => 'style-curated-mini',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|enterprise_curated|curated_mini'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_curated|curated_related';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_curated';
  $ds_layout->view_mode = 'curated_related';
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
  $export['node|enterprise_curated|curated_related'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_curated|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_curated';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'submit_info',
        1 => 'comment_count',
      ),
      'sticky' => array(
        2 => 'social_media_share_buttons',
        3 => 'prev_next_node',
      ),
      'middle' => array(
        4 => 'unpublished',
        5 => 'field_image',
        6 => 'body',
      ),
      'footer' => array(
        7 => 'field_curated_tags',
        8 => 'about_author',
        9 => 'comments',
        10 => 'field_energy_level',
      ),
    ),
    'fields' => array(
      'submit_info' => 'header',
      'comment_count' => 'header',
      'social_media_share_buttons' => 'sticky',
      'prev_next_node' => 'sticky',
      'unpublished' => 'middle',
      'field_image' => 'middle',
      'body' => 'middle',
      'field_curated_tags' => 'footer',
      'about_author' => 'footer',
      'comments' => 'footer',
      'field_energy_level' => 'footer',
    ),
    'classes' => array(
      'layout_class' => array(
        'style-curated-full' => 'style-curated-full',
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
  $export['node|enterprise_curated|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_curated|rss';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_curated';
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
  $export['node|enterprise_curated|rss'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|enterprise_curated|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'enterprise_curated';
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
        'style-curated-teaser' => 'style-curated-teaser',
      ),
      'left' => array(
        'span4' => 'span4',
      ),
      'right' => array(
        'span8' => 'span8',
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
  $export['node|enterprise_curated|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function enterprise_curated_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'curated_featured';
  $ds_view_mode->label = 'Curated Featured';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['curated_featured'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'curated_mini';
  $ds_view_mode->label = 'Curated Mini';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['curated_mini'] = $ds_view_mode;

  return $export;
}
