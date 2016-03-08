<?php
/**
 * @file
 * enterprise_editor.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function enterprise_editor_config_filter_default_formats() {
  $formats = array();

  // Exported format: Advanced HTML.
  $formats['advanced_html'] = array(
    'format' => 'advanced_html',
    'name' => 'Advanced HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => -8,
    'filters' => array(
      'video_filter' => array(
        'weight' => -1,
        'status' => 1,
        'settings' => array(
          'video_filter_width' => 400,
          'video_filter_height' => 400,
          'video_filter_autoplay' => 0,
          'video_filter_related' => 1,
          'video_filter_html5' => 1,
        ),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'icon' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'insert_block' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'check_roles' => 0,
        ),
      ),
      'picture' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_tokens' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => 50,
        'status' => 1,
        'settings' => array(
          'local_paths' => '',
          'protocol_style' => 'full',
        ),
      ),
    ),
  );

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'video_filter' => array(
        'weight' => -1,
        'status' => 1,
        'settings' => array(
          'video_filter_width' => 400,
          'video_filter_height' => 400,
          'video_filter_autoplay' => 0,
          'video_filter_related' => 1,
          'video_filter_html5' => 1,
        ),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'icon' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'insert_block' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'check_roles' => 0,
        ),
      ),
      'picture' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_tokens' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => 50,
        'status' => 1,
        'settings' => array(
          'local_paths' => '',
          'protocol_style' => 'full',
        ),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'video_filter' => array(
        'weight' => -1,
        'status' => 1,
        'settings' => array(
          'video_filter_width' => 400,
          'video_filter_height' => 400,
          'video_filter_autoplay' => 0,
          'video_filter_related' => 1,
          'video_filter_html5' => 1,
        ),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'icon' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'insert_block' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'check_roles' => 0,
        ),
      ),
      'picture' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_tokens' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => 50,
        'status' => 1,
        'settings' => array(
          'local_paths' => '',
          'protocol_style' => 'full',
        ),
      ),
    ),
  );

  return $formats;
}
