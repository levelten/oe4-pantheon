<?php

/**
 * @file
 * Admin include file.
 */

/**
 * Displays the form for the standard settings tab.
 *
 * @return
 *   array A structured array for use with Forms API.
 */
function linkintel_admin_settings($form, &$form_state) {
  $form['linkintel_target_domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Target domain'),
    '#description' => t('Link Intel links are converted to absolute links. Use this field to set your main domain name. If left blank, $_SERVER[HTTP_HOST] will be used.'),
    '#default_value' => variable_get('linkintel_target_domain', ''),
  );
  $form['linkintel_internal_domains'] = array(
    '#type' => 'textarea',
    '#title' => t('Internal domains'),
    '#description' => t('Enter all domains and subdomains that this instance of Drupal can be accessed (i.e. parked domains). Enter one per line. This data is used to determine if any absolute URLs are internal links.'),
    '#default_value' => variable_get('linkintel_internal_domains', array()),
    '#value_callback' => '_linkintel_internal_domains_value_callback',
    '#element_validate' => array('_linkintel_internal_domains_element_validate'),
  );
  return system_settings_form($form);
}

function _linkintel_internal_domains_value_callback($element, $edit = FALSE) {
  if (!$edit) {
    return implode("\n", $element['#default_value']);
  }
  return $edit;
}

function _linkintel_internal_domains_element_validate($element, &$form_state) {
  $value = explode("\n", $form_state['values']['linkintel_internal_domains']);
  $value = explode("\n", $element['#value']);
  foreach ($value AS $i => $v) {
    $value[$i] = trim($v);
  }

  form_set_value($element, $value, $form_state);
}
