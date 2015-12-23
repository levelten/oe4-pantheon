<?php

/**
 * @file
 * Alter view data for bean block entity.
 */

/**
 * Implements hook_views_data_alter().
 */
function cta_views_data_alter(&$data) {
  // TODO: I would like to move CTA selectors to be apart of the bean/block group.
  // Wasted too much time on this, so moving on.
  return;
  $data['cta_bean_selector']['selector']['moved to'] = array('bean', 'cta_selector');
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

/**
 * Implements hook_views_data().
 */
function cta_views_data() {
  $data['cta_bean_selector']['table']['group']  = t('CTA Selector');
  $data['cta_bean_selector']['table']['join'] = array(
    'bean' => array(
      'left_field' => 'delta',
      'field' => 'delta',
    ),
  );

  $data['cta_bean_selector']['selector'] = array(
    'title' => t('CTA selector'),
    'help' => t("The CTA selector set on a bean."),
    'field' => array(
      'handler' => 'views_handler_field_bean_cta_selector',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_bean_cta_selector',
      'title' => t('Selector'),
    ),
  );

  return $data;
}
