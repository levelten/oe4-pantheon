<?php
/**
 * @file
 * Entity form enhancements
 * 
 * @author Tom McCracken <tomm@getlevelten.com>
 */


function intel_admin_entity_type_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'node_type_form') {
    $entity_type = 'node';
    $bundle = isset($form['#node_type']->type) ? $form['#node_type']->type : '';

  }
  elseif ($form_id == 'taxonomy_form_vocabulary') {
    $entity_type = 'taxonomy';
    $bundle = isset($form['#vocabulary']->machine_name) ? $form['#vocabulary']->machine_name : '';
  }
  else {
    return;
  }
  $form['intel'] = array(
    '#type' => 'fieldset',
    '#title' => t('LevelTen Intelligence'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#group' => 'additional_settings',      
  ); 
  $form_state['intel'] = array(
    'entity_type' => $entity_type,
    'bundle' => $bundle,
  ); 
  $form['#submit'][] = 'intel_entity_type_form_submit';

  $entity_settings = array();
  // if new entity bundle, $bundle will not be set
  if ($bundle) {
    $entity_settings = variable_get('intel_entity_settings_' . $entity_type . '__' . $bundle, array());
  }
  $pi = intel_get_page_intents('select');
  $page_intents = array();
  foreach ($pi AS $key => $v) {
    $page_intents[$key] = $v['title'];
  }

  $form['intel']['intel_page_intent'] = array(
    '#type' => 'select',
    '#title' => t('Default page intent'),
    '#options' => $page_intents,
    '#default_value' => !empty($entity_settings['page_intent']) ? $entity_settings['page_intent'] : INTEL_PAGE_INTENT_DEFAULT,
    '#description' => t('Sets the default page intent for this content type. Defaults can be overriden per node using page_intent field.'),
  );

  if ($form_id == 'node_type_form') {
    $form['intel']['intel_track_page_uid'] = array(
      '#type' => 'checkbox',
      '#title' => t('Track author'),
      '#default_value' => !empty($entity_settings['track_page_uid']) ? $entity_settings['track_page_uid'] : 'a',
      '#description' => t('If enabled, node author will be tracked in analytics for this content type.'),
    );

    $options = array();
    $fields_info = field_info_instances($entity_type, $bundle);
    foreach ($fields_info AS $key => $field) {
      $field_info = field_info_field($key);
      if (isset($field_info['settings']['allowed_values'][0]['vocabulary'])) {
        $vocab_name = $field_info['settings']['allowed_values'][0]['vocabulary'];
        $options[$key] = $field['label'];
      }
    }
    $form['intel']['intel_track_term_fields'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Track vocabularies'),
      '#options' => $options,
      '#default_value' => !empty($entity_settings['track_term_fields']) ? $entity_settings['track_term_fields'] : array(),
      '#description' => t('If checked, any terms in the vocabulary will be added to page attributes.'),
    );
  }
  elseif ($form_id == 'taxonomy_form_vocabulary') {
    $form['intel']['intel_track_page_terms'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add terms to page attributes'),
      '#default_value' => !empty($entity_settings['track_page_terms']) ? $entity_settings['track_page_terms'] : INTEL_TRACK_PAGE_TERMS_DEFAULT,
      '#description' => t('If enabled terms in this vocabulary will be added to page attributes.'),
    );
  }
}
// TODO: should this be converted to use a entity_type_insert hook?
function intel_admin_entity_type_form_submit($form, &$form_state) {
  if (!isset($form_state['intel'])) {
    return;
  }
  $values = $form_state['values'];
  $entity_type = $form_state['intel']['entity_type'];
  $bundle = $form_state['intel']['bundle'];
  if (!$bundle && !empty($values['name'])) {
    $bundle = $values['name'];
  }

  $entity_settings = array();

  if (isset($values['intel_page_intent'])) {
    $entity_settings['page_intent'] = $values['intel_page_intent'];
  }

  if (isset($values['intel_track_page_uid'])) {
    $entity_settings['track_page_uid'] = $values['intel_track_page_uid'];
  }
  if (isset($values['intel_track_term_fields'])) {
    $entity_settings['track_term_fields'] = $values['intel_track_term_fields'];
  }

  if (isset($values['intel_track_page_terms'])) {
    $entity_settings['track_page_terms'] = $values['intel_track_page_terms'];
  }

  variable_set('intel_entity_settings_' . $entity_type . '__' . $bundle, $entity_settings);
}

function intel_admin_entity_edit_form_alter(&$form, &$form_state, $form_id = '') {
  drupal_add_css(drupal_get_path('module', 'intel') . "/css/intel.entity_edit.css");
  drupal_add_js(drupal_get_path('module', 'intel') . "/js/intel.entity_edit.js");
  
  $form_add = array(
    '#type' => 'fieldset',
    '#title' => t('LevelTen Intelligence'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#group' => 'additional_settings',  
    '#attributes' => array(
      'class' => array('intel-vert-tab'),
    ),  
  ); 
  $field_count = 0;
  $lang = !empty($form['language']['#value']) ? $form['language']['#value'] : LANGUAGE_NONE;
  if (isset($form['field_page_intent'])) {
    $form_add['field_page_intent'] = $form['field_page_intent'];
    unset($form['field_page_intent']);
    $field_count++;
  }
  if (isset($form['field_page_attribute_col'])) {
    $form_add['intel']['field_page_attribute_col'] = $form['field_page_attribute_col'];
    unset($form['field_page_attribute_col']);
    $field_count++;
  }
  if (isset($form['field_visitor_attribute_col'])) {
    $form_add['field_visitor_attribute_col'] = $form['field_visitor_attribute_col'];
    unset($form['field_visitor_attribute_col']);
    $field_count++;
  }
  if (isset($form['field_intel_event_col'])) {
    $form_add['field_intel_event_col'] = $form['field_intel_event_col'];
    unset($form['field_intel_event_col']);
    $field_count++;
  }
  if ($field_count) {
    $form['intel'] = $form_add;
  }

  if (isset($form['field_visitor_category_col'])) {
    $form['field_visitor_category_col']['#prefix'] = '<div class="intel-visitor-action-col">';
    $form['field_visitor_category_col']['#suffix'] = '</div>';
  }
  //dsm($form);
  
}