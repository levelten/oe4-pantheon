<?php

/**
 * @file
 * Alter view data for bean block entity.
 */

/**
 * Implements hook_views_data_alter().
 */
function bean_views_data_alter(&$data) {
  $data['bean']['cta_selector'] = array(
    'title' => t('CTA selector'),
    'help' => t('The CTA selector on a bean'),
    'field' => array(
      'handler' => 'views_handler_field_bean_cta_selector',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_bean_cta_selector',
    ),
  );
}
