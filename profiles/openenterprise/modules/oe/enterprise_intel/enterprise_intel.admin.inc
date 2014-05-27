<?php

function enterprise_intel_admin_config_form($form, $form_state) {
  $content_types = node_type_get_types();
//dsm($content_types);

  $options = array(
    'field_intel_event_col' => t('Events field collection'),
    'field_page_attribute_col' => t('Page attribute field collection'),
    'field_visitor_attribute_col' => t('Visitor attribute field collection'),
  );

  // determine existing term reference fields
  $fields_info = field_info_fields();
//dsm($fields_info);
  $term_ref_fields = array();
  foreach ($fields_info AS $name => $info) {
    if ($info['type'] == 'taxonomy_term_reference') {
      $vocab = $info['settings']['allowed_values'][0]['vocabulary'];
      if (!isset($term_ref_fields[$vocab])) {
        $term_ref_fields[$vocab] = array();
      }
      $term_ref_fields[$vocab][$name] = $name;
    }
  }
//dsm($term_ref_fields);

  $tax_settings = intel_get_entity_settings_multi('taxonomy');
//dsm($tax_settings);
  $msg = t('Select an existing term reference field to use as base field for adding taxonomy selectors on all content types.');

  $form['vocab_base_fields'] = array(
    '#type' => 'fieldset',
    '#title' => t('Term reference base fields'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#description' => $msg,
  );

  $vocab_map = variable_get('enterprise_intel_vocab_field_map', array());
  foreach ($tax_settings AS $bundle => $settings) {

    if (!isset($term_ref_fields[$bundle])) {
      $msg = '';
      //$msg = t('It appears the @name vocabulary is intented to be used as an Intelligence control');
      //$msg = t('An existing term reference field associated with the @name vocabulary was not found.', array('@name' => $bundle));
      //$msg .= ' ' . t('A term reference field associated with this vocabulary must be created prior to adding instances to any content type.');
      $msg .= t('No existing fields were found associated with this vocabulary.');
      $msg .= ' ' . t('To use this vocabulary !link.', array(
        '!link' => l(t('create a term reference field'), 'admin/structure/types'),
      ));
      $form['vocab_base_fields']['vocab_base_fields_' . $bundle] = array(
        '#type' => 'item',
        '#title' => t('Base field for @name term reference fields.', array('@name' => $bundle)),
        '#markup' => $msg,
        //'#description' => t('Select and existing term reference associated with the @name vocabulary to apply to all content types.', array('@name' => $bundle)),
      );
      continue;
    }
    $form['base_fields']['vocab_base_fields_' . $bundle] = array(
      '#type' => 'select',
      '#title' => t('Base field for @name term reference fields.', array('@name' => $bundle)),
      '#options' => $term_ref_fields[$bundle],
      '#default_value' => isset($vocab_map[$bundle]) ? $vocab_map[$bundle] : 0,
      '#description' => t('Select and existing term reference associated with the @name vocabulary to apply to all content types.', array('@name' => $bundle)),
    );
    if (isset($vocab_map[$bundle])) {
      $options[$vocab_map[$bundle]] = t('@name term reference field', array('@name' => $bundle));
    }
    /*
    if (!empty($settings['track_page_terms']) || !empty($settings['page_attribute']['key'])) {
      $options['vocab_' . $bundle] = t('@name term reference field', array('@name' => $bundle));
    }
    */
  }

  $msg = '';
  $msg .= t('select the Intelligence controls you would like to add/remove for each content type.');
  $form['content_type'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content type configuration'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#description' => $msg,
  );


  foreach ($content_types AS $bundle => $content_type) {
    $fields = field_info_instances('node', $bundle);
    //dsm($fields);

    $default_value = variable_get('enterprise_intel_entity_settings_node__' . $bundle, array());
//dsm($default_value);
    foreach ($fields AS $field_name => $field) {
      if (isset($options[$field_name])) {
        $default_value[$field_name] = $field_name;
      }
    }
//dsm($default_value);
    $form['content_type']['content_type_' . $bundle] = array(
      '#type' => 'checkboxes',
      '#title' => $content_type->name . ' ' . t('config'),
      '#options' => $options,
      '#default_value' => $default_value,
      '#description' => t('Select the Intelligence control fields you would like to add to the @name content type.', array('@name' => $content_type->name)),
    );
  }

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Execute configuration'),
  );

  return $form;
}

function enterprise_intel_admin_config_form_submit($form, $form_state) {
  //dsm($form);
  //dsm($form_state);
  $values = $form_state['values'];

  // build mapping of vocabularies to base field
  $vocab_map = array();
  foreach ($values AS $name => $value) {
    if (strpos($name, 'vocab_base_fields_') === 0) {
      list($a, $b, $c, $vocab_name) = explode('_', $name, 4);
      if ($value) {
        $vocab_map[$vocab_name] = $value;
      }
    }
  }dsm($vocab_map);

  variable_set('enterprise_intel_vocab_field_map', $vocab_map);

  // build settings for each content type
  $settings = array();
  foreach ($values AS $name => $values) {
    if (strpos($name, 'content_type_') === 0) {
      list($a, $b, $type_name) = explode('_', $name, 3);
      $settings[$type_name] = array();
      foreach ($values AS $fname => $fvalue) {
        if (strpos($fname, 'field_') === 0) {
          $settings[$type_name][$fname] = $fvalue;
        }
        else if (strpos($fname, 'vocab_') === 0) {
          list($a, $vocab_name) = explode('_', $fname, 2);
          if (!empty($vocab_map[$vocab_name])) {
            $settings[$type_name][$vocab_map[$vocab_name]] = ($fvalue) ? $vocab_map[$vocab_name] : 0;
          }
        }
      }
      //dsm($settings[$type_name]);
      variable_set('enterprise_intel_entity_settings_node__' . $type_name, $settings[$type_name]);
    }
  }

  //dsm($settings);

  enterprise_intel_revert_intel_controls();
  //enterprise_intel_revert_intel_controls('node', 'enterprise_blog', $values['content_type_enterprise_blog']);

}

