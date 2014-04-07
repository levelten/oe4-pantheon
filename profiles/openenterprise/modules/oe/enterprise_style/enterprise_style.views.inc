<?php
/**
 * @file
 */

/**
 * Implements hook_views_plugins().
 */
function enterprise_style_views_plugins() {
  $module_path = drupal_get_path('module', 'enterprise_style');
  return array(
    'style' => array(
      'enterprise_style_list_plugin_style' => array(
        'title' => t('Bootstrap List'),
        'help' => t('Bootstrap List Style'),
        'path' => $module_path . '/plugins/list',
        'handler' => 'EnterpriseStyleListPluginStyle',
        'parent' => 'default',
        'theme' => 'enterprise_style_list_plugin_style',
        'theme path' => $module_path . '/theme/list',
        'theme file' => 'theme.inc',
        'uses row plugin' => TRUE,
        'uses row class' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'help topic' => 'style-list',
      ),
    ),
  );
}


/*
        'uses row plugin' => TRUE,
        'uses row class' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'help topic' => 'style-list',
 */