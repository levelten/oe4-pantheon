<?php
/**
 * @file
 * enterprise_blog_config.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function enterprise_blog_config_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-enterprise_blog-body'.
  $field_instances['node-enterprise_blog-body'] = array(
    'bundle' => 'enterprise_blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
          'field_delimiter' => '',
          'field_formatter_class' => 'body',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'drupal_exit();' => array(
        'label' => 'hidden',
        'module' => 'smart_trim',
        'settings' => array(
          'conditions' => array(),
          'field_delimiter' => '',
          'field_formatter_class' => 'body',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
          'more_link' => 1,
          'more_text' => 'Read more',
          'summary_handler' => 'trim',
          'trim_length' => 450,
          'trim_link' => FALSE,
          'trim_options' => array(
            'text' => 'text',
          ),
          'trim_preserve_tags' => '',
          'trim_suffix' => '...',
          'trim_type' => 'chars',
        ),
        'type' => 'smart_trim_format',
        'weight' => 2,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'micro' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'mini' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
          'ellipsis' => FALSE,
          'field_delimiter' => '',
          'field_formatter_class' => 'body',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
          'trim_length' => 500,
          'word_boundary' => FALSE,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'smart_trim',
        'settings' => array(
          'conditions' => array(),
          'field_delimiter' => '',
          'field_formatter_class' => 'teaser',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
          'more_link' => 1,
          'more_text' => 'Read more',
          'summary_handler' => 'trim',
          'trim_length' => 250,
          'trim_link' => FALSE,
          'trim_options' => array(
            'text' => 'text',
          ),
          'trim_preserve_tags' => '',
          'trim_suffix' => '...',
          'trim_type' => 'chars',
        ),
        'type' => 'smart_trim_format',
        'weight' => 3,
      ),
      'text_teaser' => array(
        'label' => 'hidden',
        'module' => 'smart_trim',
        'settings' => array(
          'conditions' => array(),
          'field_delimiter' => '',
          'field_formatter_class' => 'body',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
          'more_link' => 0,
          'more_text' => 'Read more',
          'summary_handler' => 'trim',
          'trim_length' => 140,
          'trim_link' => FALSE,
          'trim_options' => array(
            'text' => 'text',
          ),
          'trim_preserve_tags' => '',
          'trim_suffix' => '...',
          'trim_type' => 'chars',
        ),
        'type' => 'smart_trim_format',
        'weight' => 2,
      ),
      'title' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-enterprise_blog-field_categories'.
  $field_instances['node-enterprise_blog-field_categories'] = array(
    'bundle' => 'enterprise_blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'micro' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'mini' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'rss' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'text_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'ds_extras_field_template' => '',
    'enterprise_edit_form_display' => 'sidebar',
    'entity_type' => 'node',
    'field_name' => 'field_categories',
    'label' => 'Categories',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-enterprise_blog-field_energy_level'.
  $field_instances['node-enterprise_blog-field_energy_level'] = array(
    'bundle' => 'enterprise_blog',
    'default_value' => array(
      0 => array(
        'radioactivity_energy' => 2000,
        'radioactivity_timestamp' => 1356623186,
      ),
    ),
    'deleted' => 0,
    'description' => 'Current energy level of the blog post.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'radioactivity',
        'settings' => array(
          'accuracy' => 100,
          'conditions' => array(),
          'energy' => 10,
          'field_delimiter' => '',
          'field_formatter_class' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
          'type' => 'none',
        ),
        'type' => 'radioactivity_combo_formatter',
        'weight' => 7,
      ),
      'drupal_exit();' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'micro' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'mini' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'radioactivity',
        'settings' => array(
          'accuracy' => 100,
          'conditions' => array(),
          'energy' => 10,
          'field_delimiter' => '',
          'field_formatter_class' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
          'type' => 'none',
        ),
        'type' => 'radioactivity_combo_formatter',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'text_teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'title' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'enterprise_edit_form_display' => 'sidebar',
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'fences_wrapper_class' => '',
    'field_name' => 'field_energy_level',
    'label' => 'Energy Level',
    'required' => 1,
    'settings' => array(
      'history' => 0,
      'history_limit' => 8,
      'profile' => 'blog_post_decay',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'radioactivity',
      'settings' => array(),
      'type' => 'radioactivity_basic_widget',
      'weight' => 50,
    ),
  );

  // Exported field_instance: 'node-enterprise_blog-field_image'.
  $field_instances['node-enterprise_blog-field_image'] = array(
    'bundle' => 'enterprise_blog',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'picture',
        'settings' => array(
          'colorbox_settings' => array(
            'colorbox_caption' => 'auto',
            'colorbox_caption_custom' => '',
            'colorbox_gallery' => 'post',
            'colorbox_gallery_custom' => '',
            'colorbox_group' => 'full-0',
          ),
          'conditions' => array(),
          'fallback_image_style' => '',
          'field_delimiter' => '',
          'field_formatter_class' => 'image',
          'image_link' => '',
          'lazyload' => 0,
          'lazyload_aspect_ratio' => 0,
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
          'picture_mapping' => 'full-16x9',
        ),
        'type' => 'picture',
        'weight' => 3,
      ),
      'drupal_exit();' => array(
        'label' => 'hidden',
        'module' => 'picture',
        'settings' => array(
          'colorbox' => 'full-0',
          'colorbox_settings' => array(
            'colorbox_caption' => 'auto',
            'colorbox_caption_custom' => '',
            'colorbox_gallery' => 'post',
            'colorbox_gallery_custom' => '',
            'colorbox_group' => '',
            'colorbox_multivalue_index' => NULL,
          ),
          'conditions' => array(),
          'fallback_image_style' => '',
          'field_delimiter' => '',
          'field_formatter_class' => 'image',
          'image_link' => 'content',
          'lazyload' => '',
          'lazyload_aspect_ratio' => '',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
          'picture_group' => 'full-16x9',
          'picture_mapping' => 'full-0',
        ),
        'type' => 'picture',
        'weight' => 3,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'micro' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'field_delimiter' => '',
          'field_formatter_class' => 'image',
          'image_link' => 'content',
          'image_style' => 'small-7x5-xs',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'mini' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'field_delimiter' => '',
          'field_formatter_class' => 'card-img-top',
          'image_link' => 'content',
          'image_style' => 'full-16x9-xs',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'field_delimiter' => '',
          'field_formatter_class' => 'image',
          'image_link' => '',
          'image_style' => 'full-16x9-md',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'field_delimiter' => '',
          'field_formatter_class' => 'thumbnail',
          'image_link' => 'content',
          'image_style' => 'large-7x5-md',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'text_teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'title' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'enterprise_edit_form_display' => 'sidebar',
    'entity_type' => 'node',
    'field_name' => 'field_image',
    'label' => 'Featured image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'content/blog/images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'caption_from_title' => 0,
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'imce' => 0,
            'reference' => 0,
            'remote' => 0,
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 0,
          'image_apps_featured_screenshot' => 0,
          'image_apps_logo' => 0,
          'image_apps_logo_small' => 0,
          'image_apps_screenshot' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-enterprise_blog-field_tags'.
  $field_instances['node-enterprise_blog-field_tags'] = array(
    'bundle' => 'enterprise_blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'drupal_exit();' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'micro' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'mini' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
      'rss' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'text_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'title' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'enterprise_edit_form_display' => 'sidebar',
    'entity_type' => 'node',
    'field_name' => 'field_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Categories');
  t('Current energy level of the blog post.');
  t('Energy Level');
  t('Featured image');
  t('Tags');

  return $field_instances;
}
