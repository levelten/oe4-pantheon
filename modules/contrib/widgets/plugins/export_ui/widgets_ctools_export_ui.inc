<?php
/**
 * Define this Export UI plugin.
 */
$plugin = array(
  'schema' => 'widgets_definitions',  // As defined in hook_schema().
  'access' => 'administer widgets sets',  // Define a permission users must have to access these pages.
  // Define the menu item.
  'menu' => array(
    'menu item' => 'widgets',
    'menu title' => 'Widgets',
    'menu description' => 'Administer widgets elements.',
  ),
  // Define user interface texts.
  'title singular' => t('Widgets element'),
  'title plural' => t('Widgets elements'),
  'title singular proper' => t('Widgets element'),
  'title plural proper' => t('Widgets elements'),
  // Define the names of the functions that provide the add/edit forms.
  'form' => array(
    'settings' => 'widgets_ctools_export_ui_form',
    // 'submit' and 'validate' are also valid callbacks.
  ),
);