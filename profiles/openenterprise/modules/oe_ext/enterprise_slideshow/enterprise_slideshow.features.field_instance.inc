<?php
/**
 * @file
 * enterprise_slideshow.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function enterprise_slideshow_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-enterprise_slideshow-field_enterprise_slide_class'
  $field_instances['bean-enterprise_slideshow-field_enterprise_slide_class'] = array(
    'bundle' => 'enterprise_slideshow',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_formatter_css_class',
        'settings' => array(
          'conditions' => array(),
          'depth' => 0,
          'field_delimiter' => '',
          'field_formatter_class' => '',
          'hidden' => 1,
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
          'target' => 'entity',
        ),
        'type' => 'cssclass_formatter',
        'weight' => 0,
      ),
      'enterprise_slideshow_arrow' => array(
        'label' => 'hidden',
        'module' => 'field_formatter_css_class',
        'settings' => array(
          'conditions' => array(),
          'depth' => 0,
          'field_delimiter' => '',
          'field_formatter_class' => '',
          'hidden' => 1,
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
          'target' => 'entity',
        ),
        'type' => 'cssclass_formatter',
        'weight' => 0,
      ),
      'enterprise_slideshow_pager' => array(
        'label' => 'hidden',
        'module' => 'field_formatter_css_class',
        'settings' => array(
          'conditions' => array(),
          'depth' => 0,
          'field_delimiter' => '',
          'field_formatter_class' => '',
          'hidden' => 1,
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
          'target' => 'entity',
        ),
        'type' => 'cssclass_formatter',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'enterprise_edit_form_display' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_enterprise_slide_class',
    'label' => 'Slide Class',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'bean-enterprise_slideshow-field_enterprise_slides'
  $field_instances['bean-enterprise_slideshow-field_enterprise_slides'] = array(
    'bundle' => 'enterprise_slideshow',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'flexslider_field_collection',
        'settings' => array(
          'conditions' => array(),
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
          'optionset' => 'enterprise_slideshow_no_auto',
          'thumbnail_image_field' => '',
          'thumbnail_image_style' => '',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_entity_flexslider',
        'weight' => 1,
      ),
      'enterprise_slideshow_arrow' => array(
        'label' => 'hidden',
        'module' => 'flexslider_field_collection',
        'settings' => array(
          'conditions' => array(),
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
          'optionset' => 'enterprise_slideshow_arrows_only',
          'thumbnail_image_field' => '',
          'thumbnail_image_style' => '',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_entity_flexslider',
        'weight' => 1,
      ),
      'enterprise_slideshow_pager' => array(
        'label' => 'hidden',
        'module' => 'flexslider_field_collection',
        'settings' => array(
          'conditions' => array(),
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
          'optionset' => 'enterprise_slideshow_pager_only',
          'thumbnail_image_field' => '',
          'thumbnail_image_style' => '',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_entity_flexslider',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'enterprise_edit_form_display' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_enterprise_slides',
    'label' => 'Slide Collection',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'field_collection_fieldset',
      'settings' => array(
        'collapsed' => 0,
        'last_item_collapsed' => 0,
      ),
      'type' => 'field_collection_fieldset',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_enterprise_slides-field_enterprise_slideshow_desc'
  $field_instances['field_collection_item-field_enterprise_slides-field_enterprise_slideshow_desc'] = array(
    'bundle' => 'field_enterprise_slides',
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
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'enterprise_slideshow_wide' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
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
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
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
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'enterprise_edit_form_display' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_enterprise_slideshow_desc',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'advanced_html' => 'advanced_html',
          'ds_code' => 'ds_code',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'advanced_html' => array(
              'weight' => -8,
            ),
            'ds_code' => array(
              'weight' => 12,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_enterprise_slides-field_enterprise_slideshow_image'
  $field_instances['field_collection_item-field_enterprise_slides-field_enterprise_slideshow_image'] = array(
    'bundle' => 'field_enterprise_slides',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'picture',
        'settings' => array(
          'colorbox' => 'slideshow',
          'conditions' => array(),
          'fallback_image_style' => 'enterprise_slideshow_large',
          'field_delimiter' => '',
          'field_formatter_class' => 'hidden-xs',
          'image_link' => '',
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
          'picture_group' => 'slideshow',
        ),
        'type' => 'picture',
        'weight' => 2,
      ),
      'enterprise_slideshow_wide' => array(
        'label' => 'hidden',
        'module' => 'picture',
        'settings' => array(
          'colorbox' => 'slideshow',
          'conditions' => array(),
          'fallback_image_style' => 'enterprise_slideshow_large',
          'field_delimiter' => '',
          'field_formatter_class' => '',
          'image_link' => '',
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
          'picture_group' => 'slideshow',
        ),
        'type' => 'picture',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'picture',
        'settings' => array(
          'colorbox' => 'slideshow',
          'conditions' => array(),
          'fallback_image_style' => 'enterprise_slideshow_large',
          'field_delimiter' => '',
          'field_formatter_class' => 'hidden-xs',
          'image_link' => '',
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
          'picture_group' => 'slideshow',
        ),
        'type' => 'picture',
        'weight' => 2,
      ),
    ),
    'enterprise_edit_form_display' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_enterprise_slideshow_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 0,
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_enterprise_slides-field_enterprise_slideshow_link'
  $field_instances['field_collection_item-field_enterprise_slides-field_enterprise_slideshow_link'] = array(
    'bundle' => 'field_enterprise_slides',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(
          'conditions' => array(),
          'field_delimiter' => '',
          'field_formatter_class' => 'btn btn-secondary',
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
        'type' => 'link_default',
        'weight' => 3,
      ),
      'enterprise_slideshow_wide' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(
          'conditions' => array(),
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
        ),
        'type' => 'link_default',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(
          'conditions' => array(),
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
        ),
        'type' => 'link_default',
        'weight' => 3,
      ),
    ),
    'enterprise_edit_form_display' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_enterprise_slideshow_link',
    'label' => 'Link',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_enterprise_slides-field_enterprise_slideshow_mobi'
  $field_instances['field_collection_item-field_enterprise_slides-field_enterprise_slideshow_mobi'] = array(
    'bundle' => 'field_enterprise_slides',
    'deleted' => 0,
    'description' => 'This is the image to be displayed only on a mobile device.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'field_delimiter' => '',
          'field_formatter_class' => 'visible-sm-*',
          'image_link' => '',
          'image_style' => 'slideshow_extra_small_400xh',
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
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'picture',
        'settings' => array(
          'colorbox' => 'slideshow',
          'conditions' => array(),
          'fallback_image_style' => '',
          'field_delimiter' => '',
          'field_formatter_class' => 'visible-sm-*',
          'image_link' => '',
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
          'picture_group' => 'slideshow',
        ),
        'type' => 'picture',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'enterprise_edit_form_display' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_enterprise_slideshow_mobi',
    'label' => 'Mobile Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 'private',
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 0,
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_enterprise_slides-field_enterprise_slideshow_title'
  $field_instances['field_collection_item-field_enterprise_slides-field_enterprise_slideshow_title'] = array(
    'bundle' => 'field_enterprise_slides',
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
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'enterprise_slideshow_wide' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
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
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
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
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'enterprise_edit_form_display' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_enterprise_slideshow_title',
    'label' => 'Title',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'advanced_html' => 'advanced_html',
          'ds_code' => 'ds_code',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'advanced_html' => array(
              'weight' => -8,
            ),
            'ds_code' => array(
              'weight' => 12,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Description');
  t('Image');
  t('Link');
  t('Mobile Image');
  t('Slide Class');
  t('Slide Collection');
  t('This is the image to be displayed only on a mobile device.');
  t('Title');

  return $field_instances;
}
