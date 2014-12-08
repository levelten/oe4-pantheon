<?php

/**
 * @file
 * Forms and callbacks for controlling the admin side of intel_webform.
 * 
 * These forms will appear in intel_webform local action of webforms.
 */

function intel_webform_manage($node) {
  $form = array();
  $render_array = array();

  
  $render_array['form'] = drupal_get_form('intel_webform_settings_form', $node);  
  
  return $render_array;
}

function intel_webform_settings_form($form, &$form_state, $node) {
  $form['nid'] = array(
    '#type' => 'value',
    '#value' => $node->nid,
  );
  
  $settings = variable_get('intel_webform_settings_node_' . $node->nid, array());

  $form_state['intel_settings'] = $settings;
  
  $form['field'] = array(
    '#type' => 'fieldset',
    '#title' => t('Primary field maps'),
  );
  
  $options = array('' => t('None'));
  if (!empty($node->webform['components'])) {
    foreach ($node->webform['components'] AS $field) {
      if ($field['type'] == 'email') {
        $options[$field['form_key']] = $field['name'];
      }
    }
  }    
  $form['field']['field_visitor_email'] = array(
    '#type' => 'select',
    '#title' => t('Visitor email field'),
    '#default_value' => !empty($settings['field_visitor_email']) ? $settings['field_visitor_email'] : '',
    '#description' => t('If you select an existing email field, that fields input will be used. If not, a field will be shown to the user.'),
    '#options' => $options,
  );
  
  $options = array('' => t('None'));
  if (!empty($node->webform['components'])) {
    foreach ($node->webform['components'] AS $field) {
      if ($field['type'] == 'textfield') {
        $options[$field['form_key']] = $field['name'];
      }
    }
  }    
  $form['field']['field_visitor_name'] = array(
    '#type' => 'select',
    '#title' => t('Visitor name field'),
    '#default_value' => !empty($settings['field_visitor_name']) ? $settings['field_visitor_name'] : '',
    '#description' => t('Select the field that contains the visitors first or full name.'),
    '#options' => $options,
  );
  
  $form['field']['field_visitor_name2'] = array(
    '#type' => 'select',
    '#title' => t('Visitor last name field'),
    '#default_value' => !empty($settings['field_visitor_name2']) ? $settings['field_visitor_name2'] : '',
    '#description' => t('Select the field that contains the visitors last name if there is one.'),
    '#options' => $options,
  );
  
  $form['add_field'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional field maps'),
  );
  
  $prop_info = intel_get_visitor_property_info();
  $options = intel_visitor_property_select_options();
  
  if (!empty($node->webform['components'])) {
    foreach ($node->webform['components'] AS $field) {
      $key = $field['form_key'];
      if (strpos($key, 'intel_') === 0) {
        continue;
      }
      $form['add_field']['fieldmap_' . $key] = array(
        '#type' => 'select',
        '#title' => $field['name'] . " ($key) " . t('field'),
        '#options' => $options,
        '#default_value' => !empty($settings['fieldmap'][$key]) ? $settings['fieldmap'][$key] : '',
        '#description' => t('Select visitor property to save this field to.'),
      );  
    }
  }
  /*
  if (variable_get('intel_track_phonecalls', INTEL_TRACK_PHONECALLS_DEFAULT)) {
    $form['sms'] = array(
      '#type' => 'fieldset',
      '#title' => t('SMS options'),
      '#collapsible' => FALSE,
      '#description' => t('Option for sending SMS text when form submitted.'),
    );
    $form['sms']['send_sms'] = array(
      '#type' => 'textfield',
      '#title' => t('Send to number'),
      '#default_value' => !empty($settings['send_sms']) ? $settings['send_sms'] : '',
      '#description' => t('Enter a number if you want to send a text when the number is called.'),
      '#size' => 20,
    );
  }
  */

  $form['settings']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  
  return $form;
}


function intel_webform_settings_form_validate($form, &$form_state) {

}

function intel_webform_settings_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $settings = array(
    'field_visitor_email' => $values['field_visitor_email'],
    'field_visitor_name' => $values['field_visitor_name'],
    'field_visitor_name2' => $values['field_visitor_name2'],
    'fieldmap' => array(),
  ) + $form_state['intel_settings'];

  foreach ($values AS $key => $value) {
    if ($value && (strpos($key, 'fieldmap_') === 0)) {
      $field = str_replace('fieldmap_', '', $key);
      $settings['fieldmap'][$field] = $value;
    }
  }
  if (!empty($values['send_sms'])) {
    $settings['send_sms']= $values['send_sms'];
  }
  variable_set('intel_webform_settings_node_' . $values['nid'], $settings);
}

function intel_webform_manage_phone($node) {
  $form = array();
  $render_array = array();


  $render_array['form'] = drupal_get_form('intel_webform_phone_settings_form', $node);

  return $render_array;
}

function intel_webform_phone_settings_form($form, &$form_state, $node) {
  $form['nid'] = array(
    '#type' => 'value',
    '#value' => $node->nid,
  );

  $settings = variable_get('intel_webform_settings_node_' . $node->nid, array());

  $form_state['intel_settings'] = $settings;

  if (variable_get('intel_track_phonecalls', INTEL_TRACK_PHONECALLS_DEFAULT)) {
    $form['sms'] = array(
      '#type' => 'fieldset',
      '#title' => t('SMS options'),
      '#collapsible' => FALSE,
      '#description' => t('Option for sending SMS text when form submitted.'),
    );
    $form['sms']['send_sms'] = array(
      '#type' => 'textfield',
      '#title' => t('Send to number'),
      '#default_value' => !empty($settings['send_sms']) ? implode(', ', $settings['send_sms']) : '',
      '#description' => t('Enter any numbers you want to sent a text when the number is called. Seperate multiple numbers with commas.'),
      //'#size' => 20,
    );
  }

  $form['settings']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

function intel_webform_phone_settings_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $settings = $form_state['intel_settings'];

  $settings['send_sms'] = array();
  if (!empty($values['send_sms'])) {
    $vals = explode(',', $values['send_sms']);
    foreach ($vals AS $value) {
      $value = trim($value);
      $settings['send_sms'][$value] = $value;
    }
  }
  variable_set('intel_webform_settings_node_' . $values['nid'], $settings);

  // flush caches if entitycache exists
  if (module_exists('entitycache') && isset($values['nid'])) {
    cache_clear_all($values['nid'], 'cache_entity_node');
  }
}