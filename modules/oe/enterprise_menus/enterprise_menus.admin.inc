<?php
// $Id$
/**
 * @file
 * Enterprise Menus Administrative Interface
 */

/**
 * Admin configuration form
 */
function enterprise_menus_admin_settings() {
  $node_types = _node_types_build()->names;
  $form['enterprise_menu_info'] = array(
    '#markup' => 'Select which content types to promote to top level menus.'
  );
  foreach ($node_types as $node_type => $node_type_label) {
    $form[$node_type] = array(
      '#type' => 'fieldset',
      '#title' => $node_type_label,
      '#collapsible' => FALSE,
    );
    $form[$node_type]['enterprise_menus_' . $node_type] = array(
      '#type' => 'checkbox',
      '#title' => 'Promote to Top Level',
      '#default_value' => variable_get('enterprise_menus_' . $node_type, FALSE),
    );
    $form[$node_type]['enterprise_menus_weight_' . $node_type] = array(
      '#type' => 'weight',
      '#title' => t('Weight'),
      '#default_value' => variable_get('enterprise_menus_weight_' . $node_type, 0),
      '#delta' => 50,
      '#description' => t('Heavier items will sink and the lighter items will be positioned nearer the top.'),
    );
  }
  
  $form = system_settings_form($form);

  // Need to be after system_settings_form so the changes are done.
  $form['#submit'][] = 'enterprise_menus_admin_settings_submit';
  
  return $form;
}

function enterprise_menus_admin_settings_submit($form, $form_state) {
  // Since we may have changed things, we need to do a rebuild.
  menu_rebuild();
  cache_clear_all();
}