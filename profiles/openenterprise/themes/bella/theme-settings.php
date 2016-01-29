<?php

/**
 * Include common functions used through out theme.
 */

function bella_form_system_theme_settings_alter(&$form, &$form_state) {

  $default_settings = array();

  $filename = DRUPAL_ROOT . '/' . drupal_get_path('theme', 'project') . '/project.info';
  $info = drupal_parse_info_file($filename);
  if (isset($info['settings'])) {
    $default_settings = $info['settings'];
  }

  // Set weight override.
  foreach ($form as $key => $value) {
    // Check if vertical tab.
    if ($value['#type'] == 'vertical_tabs') {
      switch ($key) {
        case 'enterprise_bootstrap':
          $form[$key]['#weight'] = -9;
          break;
        case 'bella':
          $form[$key]['#weight'] = -8;
          $eb_weight++;
          break;
        case 'general':
          $form[$key]['#weight'] = -7;
          $eb_weight++;
          break;
      }
    }
  }

  $form['bella'] = array(
    '#type' => 'vertical_tabs',
    '#prefix' => '<h2><small>Bella</small></h2>',
    '#weight' = -8,
  );

  $form['bella_display'] = array(
    '#type' => 'fieldset',
    '#group' => 'bella',
    '#title' => t('Display'),
    '#attributes' => array(
      'class' => array('columns'),
    ),
  );

  $form['bella_display']['bella_buttons'] = array(
    '#title' => t('Bella Buttons'),
    '#description' => t('Enable fancy Bella buttons (transparent outlines)'),
    '#type' => 'checkbox',
    '#default_value' => theme_get_setting('bella_buttons'),
  );

}