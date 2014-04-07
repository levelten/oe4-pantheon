<?php


/**
 * Implementation of hook_features_export_options()
 */
function config_wizard_features_export_options() {
  $options = array();
  $wizards = (array) config_wizard_info_all();
  foreach ($wizards as $name => $wizard) {
    $options[$name] = $wizard['title'];
  }
  return $options;
}

/**
 * Implementation of hook_features_export()
 */
function config_wizard_features_export($data, &$export, $module_name = '') {
  $pipe = array();
  
  $export['dependencies'][] = 'config';

  foreach ((array) $data as $name) {
    $wizard = config_wizard_load($name);
    if (!empty($wizard)) {
      $export['features']['config_wizard'][$name] = $name;
      if (isset($wizard['module']) && !in_array($wizard['module'], $export['dependencies'])) {
        $export['dependencies'][] = $wizard['module'];
      }
    }
  }

  return $pipe;
}

/**
 * Implementation of hook_features_export_render()
 */
function config_wizard_features_export_render($module_name, $data) {
  $wizards = array();

  foreach ($data as $name) {
    $wizard = config_wizard_db_load($name);
    if (!empty($wizard)) {
      $wizards[$name] = $wizard;
    }
  }
  $code = '  $data = ' . features_var_export($wizards, '  ') . ';' . PHP_EOL;
  $code .= '  return $data;';

  return array('config_wizard_defaults' => $code);
}

/**
 * Implementation of hook_features_rebuild()
 */
function config_wizard_features_rebuild($module) {
  config_wizard_features_revert($module);
}

/**
 * Implementation of hook_features_revert()
 */
function config_wizard_features_revert($module) {
  if ($data = features_get_default('config_wizard', $module)) {
    foreach ($data as $name => $wizard) {
      config_wizard_db_save($name, $wizard);
    }
  }
}