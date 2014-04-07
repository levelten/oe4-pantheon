<?php


/**
 * Implementation of hook_features_export_options()
 */
function widgets_definition_features_export_options() {
  $options = array();
  $defs = (array) widgets_element_definitions();
  // create options list of only custom definitions
  foreach ($defs as $name => $def) {
    if (empty($def['module'])) {
      $options[$name] = $def['label'];
    }
  }
  return $options;
}

/**
 * Implementation of hook_features_export()
 */
function widgets_definition_features_export($data, &$export, $module_name = '') {
  $pipe = array();

  $export['dependencies'][] = 'widgets';

  foreach ((array) $data as $name) {
    $def = widgets_element_definition_load($name);
    if (!empty($def)) {
      $export['features']['widgets_definition'][$name] = $name;
      if (isset($def['module']) && !in_array($def['module'], $export['dependencies'])) {
        $export['dependencies'][]= $def['module'];
      }
    }
  }

  return $pipe;
}

/**
 * Implementation of hook_features_export_render()
 */
function widgets_definition_features_export_render($module_name, $data) {
  $defs = array();

  foreach ($data as $name) {
    $def = widgets_element_definition_load($name);
    if (!empty($def)) {
      $defs[$name] = $def;
    }
  }
  $code = '  $data = ' . features_var_export($defs, '  ') . ';' . PHP_EOL;
  $code .= '  return $data;';

  return array('widgets_definition_defaults' => $code);
}

/**
 * Implementation of hook_features_rebuild()
 */
function widgets_definition_features_rebuild($module) {
  widgets_definition_features_revert($module);
}

/**
 * Implementation of hook_features_revert()
 */
function widgets_definition_features_revert($module) {
  if ($data = features_get_default('widgets_definition', $module)) {
    foreach ($data as $name => $def) {
      widgets_element_definition_save($def);
    }
  }
}

/**
 * Implementation of hook_features_export_options()
 */
function widgets_set_features_export_options() {
  $options = array();
  $sets = (array) widgets_sets();
  // create options list of only custom definitions
  foreach ($sets as $name => $elem) {
    $options[$name] = $set['name'];
  }
  return $options;
}

/**
 * Implementation of hook_features_export()
 */
function widgets_set_features_export($data, &$export, $module_name = '') {
  $pipe = array();

  $export['dependencies'][] = 'widgets';

  foreach ((array) $data as $name) {
    $set = widgets_set_load($name);
    if (!empty($set)) {
      $export['features']['widgets_set'][$name] = $name;
      if (isset($set['module']) && !in_array($set['module'], $export['dependencies'])) {
        $export['dependencies'][]= $set['module'];
      }
    }
  }

  return $pipe;
}

/**
 * Implementation of hook_features_export_render()
 */
function widgets_set_features_export_render($module_name, $data) {
  $sets = array();

  foreach ($data as $name) {
    $def = widgets_set_load($name);
    if (!empty($set)) {
      $sets[$name] = $set;
    }
  }
  $code = '  $data = ' . features_var_export($sets, '  ') . ';' . PHP_EOL;
  $code .= '  return $data;';

  return array('widgets_set_defaults' => $code);
}

/**
 * Implementation of hook_features_rebuild()
 */
function widgets_set_features_rebuild($module) {
  widgets_set_features_revert($module);
}

/**
 * Implementation of hook_features_revert()
 */
function widgets_set_features_revert($module) {
  if ($data = features_get_default('widgets_set', $module)) {
    foreach ($data as $set_name => $set) {
      // use name as uuid, strip numeric wsid
      if (isset($set['wsid'])) {
        unset($set['wsid']);
      }
      // set will contained localized wsid
      $set = widgets_set_save($set);
      // itterate through elements and save custom elements
      if (isset($set['elements']) && is_array($set['elements'])) {
        foreach ($set['elements'] AS $elem_name => $elem) {
          // set wsid to localized wsid
          $elem['wsid'] = $set['wsid'];
          if (isset($set['weid'])) {
            unset($set['weid']);
          }
          // set will contained localized weid
          $elem = widgets_element_save($elem);
        }
      }
    }
  }
}