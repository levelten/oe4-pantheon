<?php
/**
 * @file
 * enterprise_gallery.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function enterprise_gallery_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-enterprise_gallery-field_gallery_image'.
  $field_instances['bean-enterprise_gallery-field_gallery_image'] = array(
    'bundle' => 'enterprise_gallery',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'slick_fields',
        'settings' => array(
          'asnavfor_auto' => 0,
          'asnavfor_main' => '',
          'asnavfor_thumbnail' => '',
          'aspect_ratio' => '',
          'cache' => '',
          'color_field' => '',
          'colorbox_style' => '',
          'conditions' => array(),
          'current_display' => 'main',
          'current_view_mode' => 'default',
          'field_delimiter' => '',
          'field_formatter_class' => '',
          'grid' => '',
          'grid_medium' => '',
          'grid_small' => '',
          'iframe_lazy' => FALSE,
          'image_style' => '',
          'lightbox_ready' => FALSE,
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
          'markup' => 0,
          'media_switch' => '',
          'mousewheel' => 0,
          'nested_optionset' => '',
          'nested_slick' => FALSE,
          'nested_style' => '',
          'optionset' => 'default',
          'optionset_thumbnail' => '',
          'overridables' => array(
            'arrows' => 0,
            'autoplay' => 0,
            'dots' => 0,
            'draggable' => 0,
          ),
          'override' => 0,
          'picture' => 0,
          'picture_fallback' => '',
          'picture_ready' => FALSE,
          'picture_style' => '',
          'preserve_keys' => FALSE,
          'skin' => '',
          'skin_arrows' => '',
          'skin_dots' => '',
          'skin_thumbnail' => '',
          'slide_caption' => array(
            'alt_field' => 0,
            'title_field' => 0,
          ),
          'slide_classes' => '',
          'slide_image' => '',
          'slide_layout' => '',
          'slide_link' => '',
          'slide_overlay' => array(),
          'slide_title' => '',
          'thumbnail_caption' => '',
          'thumbnail_hover' => 0,
          'thumbnail_style' => '',
          'type' => '',
          'use_ajax' => FALSE,
          'view_mode' => '',
          'visible_slides' => '',
        ),
        'type' => 'slick',
        'weight' => 0,
      ),
      'slick_carousel' => array(
        'label' => 'hidden',
        'module' => 'slick_fields',
        'settings' => array(
          'asnavfor_auto' => 0,
          'asnavfor_main' => '',
          'asnavfor_thumbnail' => '',
          'aspect_ratio' => '',
          'cache' => '',
          'color_field' => '',
          'colorbox_style' => '',
          'conditions' => array(),
          'current_display' => 'main',
          'current_view_mode' => 'slick_carousel',
          'field_delimiter' => '',
          'field_formatter_class' => '',
          'grid' => '',
          'grid_medium' => '',
          'grid_small' => '',
          'iframe_lazy' => FALSE,
          'image_style' => 'full-0-lg',
          'lightbox_ready' => FALSE,
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
          'markup' => 0,
          'media_switch' => '',
          'mousewheel' => 0,
          'nested_optionset' => '',
          'nested_slick' => FALSE,
          'nested_style' => '',
          'optionset' => 'slideshow_normal',
          'optionset_thumbnail' => '',
          'overridables' => array(
            'arrows' => 0,
            'autoplay' => 0,
            'dots' => 0,
            'draggable' => 0,
          ),
          'override' => 0,
          'picture' => 0,
          'picture_fallback' => '',
          'picture_ready' => FALSE,
          'picture_style' => '',
          'preserve_keys' => FALSE,
          'skin' => 'classic',
          'skin_arrows' => '',
          'skin_dots' => '',
          'skin_thumbnail' => '',
          'slide_caption' => array(
            'alt_field' => 0,
            'title_field' => 'title_field',
          ),
          'slide_classes' => '',
          'slide_image' => '',
          'slide_layout' => 'bottom',
          'slide_link' => '',
          'slide_overlay' => array(),
          'slide_title' => '',
          'thumbnail_caption' => '',
          'thumbnail_hover' => 0,
          'thumbnail_style' => 'media_thumbnail',
          'type' => '',
          'use_ajax' => FALSE,
          'view_mode' => '',
          'visible_slides' => '',
        ),
        'type' => 'slick',
        'weight' => 0,
      ),
      'slick_gallery' => array(
        'label' => 'hidden',
        'module' => 'slick_fields',
        'settings' => array(
          'asnavfor_auto' => 1,
          'asnavfor_main' => '',
          'asnavfor_thumbnail' => '',
          'aspect_ratio' => '',
          'cache' => '',
          'color_field' => '',
          'colorbox_style' => '',
          'conditions' => array(),
          'current_display' => 'main',
          'current_view_mode' => 'slick_gallery',
          'field_delimiter' => '',
          'field_formatter_class' => '',
          'grid' => '',
          'grid_medium' => '',
          'grid_small' => '',
          'iframe_lazy' => FALSE,
          'image_style' => 'full-0-lg',
          'lightbox_ready' => FALSE,
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
          'markup' => 0,
          'media_switch' => '',
          'mousewheel' => 0,
          'nested_optionset' => '',
          'nested_slick' => FALSE,
          'nested_style' => '',
          'optionset' => 'slideshow_gallery_top',
          'optionset_thumbnail' => 'slideshow_gallery_bottom',
          'overridables' => array(
            'arrows' => 0,
            'autoplay' => 0,
            'dots' => 0,
            'draggable' => 0,
          ),
          'override' => 0,
          'picture' => 0,
          'picture_fallback' => '',
          'picture_ready' => FALSE,
          'picture_style' => '',
          'preserve_keys' => FALSE,
          'skin' => 'classic',
          'skin_arrows' => '',
          'skin_dots' => '',
          'skin_thumbnail' => 'classic',
          'slide_caption' => array(
            'alt_field' => 0,
            'title_field' => 'title_field',
          ),
          'slide_classes' => '',
          'slide_image' => '',
          'slide_layout' => 'bottom',
          'slide_link' => '',
          'slide_overlay' => array(),
          'slide_title' => '',
          'thumbnail_caption' => '',
          'thumbnail_hover' => 0,
          'thumbnail_style' => 'media_thumbnail',
          'type' => '',
          'use_ajax' => FALSE,
          'view_mode' => '',
          'visible_slides' => '',
        ),
        'type' => 'slick',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'enterprise_edit_form_display' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_gallery_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'reference' => 0,
            'remote' => 0,
            'upload' => 'upload',
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
            'search_all_fields' => 0,
          ),
        ),
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Image');

  return $field_instances;
}
