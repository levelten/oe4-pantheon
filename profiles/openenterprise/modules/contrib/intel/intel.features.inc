<?php
/*
/**
 * Implementation of hook_features_export_options()
 */
function intel_phonenumber_features_export_options() {
  $options = array();
  $numbs = (array) intel_get_phonenumbers();
  foreach ($numbs as $name => $numb) {
    $options[$name] = $numb['title'];
  }
  return $options;
}

/**
 * Implementation of hook_features_export()
 */
function intel_phonenumber_features_export($data, &$export, $module_name = '') {
  $pipe = array();

  foreach ((array) $data as $name) {
    $number = intel_phonenumber_load($name);
    if (!empty($number)) {
      $export['features']['intel_phonenumber'][$name] = $name;
      if (isset($number['module']) && !in_array($number['module'], $export['dependencies'])) {
        $export['dependencies'][] = $number['module'];
      }
    }
  }

  return $pipe;
}

/**
 * Implementation of hook_features_export_render()
 */
function intel_phonenumber_features_export_render($module_name, $data) {
  $numbers = array();

  foreach ($data as $name) {
    $number = intel_phonenumber_load($name);

    if (!empty($number)) {
      $numbers[$name] = $number;
    }
  }
  $code = '  $data = ' . features_var_export($numbers, '  ') . ';' . PHP_EOL;
  $code .= '  return $data;';

  return array('intel_phonenumber_defaults' => $code);
}

/**
 * Implementation of hook_features_rebuild()
 */
function intel_phonenumber_features_rebuild($module) {
  intel_phonenumber_features_revert($module);
}

/**
 * Implementation of hook_features_revert()
 */
function intel_phonenumber_features_revert($module) {
  if ($data = features_get_default('intel_phonenumber', $module)) {
    foreach ($data as $name => $number) {

      intel_phonenumber_save($number, $name);
    }
  }
}