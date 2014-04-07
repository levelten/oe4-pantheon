<?php
// $Id$
/**
 * @file
 * Slug Administrative Interface

 */

/**
 * Admin configuration form
 */
function slug_admin_settings() {
  $form['slug_menu'] = array(
    '#type' => 'select',
    '#title' => 'Slug Menu',
    '#description' => 'Select the menu to use for slugs.',
    '#options' => menu_get_menus(),
    '#default_value' => variable_get('slug_menu', 'main-menu'),
  );
  
  $node_types = _node_types_build()->names;
  $form['slug_info'] = array(
    '#markup' => 'Select which content types to enable slugs.'
  );
  foreach ($node_types as $node_type => $node_type_label) {
    $form['slug_' . $node_type] = array(
      '#type' => 'checkbox',
      '#title' => $node_type_label,
      '#default_value' => variable_get('slug_' . $node_type, FALSE),
    );
  }

  return system_settings_form($form);
}
