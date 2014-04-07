<?php

function enterprise_config_wizard_conversion_workflow_start($form, $form_state) {
  $data = $form_state['config']['wizard_data'];

  $content = t('What do you want to do.');
  $form['main'] = array(
    '#markup' => $content,
    '#editable' => 1,
  ); 
  
  $form[] = array(
    '#markup' => "\n<br />\n<br />",
    '#editable' => 1,
  ); 

  $options = array(
    'new' => t('Create a new conversion workflow scratch'),
    'add_landingpage' => t('Add a landing page to and existing workflow'),
  );
  $form['crud_mode'] = array(
    '#type' => 'radios',
    '#title' => t('What would you like to do?'),
    '#options' => $options,
    '#default_value' => isset($data['crud_mode']) ? $data['crud_mode'] : 'add',
  );
  
  return $form;
}

function enterprise_config_wizard_conversion_workflow_naming($form, $form_state) {
  $data = $form_state['config']['wizard_data'];

  $content = t('Select form fields.');
  $form['main'] = array(
    '#markup' => $content,
    '#editable' => 1,
  );


  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Machine name'),
    '#default' => t('Provide a machine name for your conversion workflow'),
    '#default_value' => isset($data['name']) ? $data['name'] : '',
  );
  
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default' => t('Provide a machine name for your conversion workflow'),
    '#default_value' => isset($data['title']) ? $data['title'] : '',
  );
  
  return $form;
}

function enterprise_config_wizard_conversion_workflow_naming_submit($form, &$form_state) {
  $values = $form_state['values'];
  $config = $form_state['config'];
  $data = $config['wizard_data'];

  $vars = array(
    'title' => $values['title'],
    'path' => array(
      'pathauto' => 0,
      'alias' => drupal_clean_css_identifier($values['name']),
    ),
  );
  $node = config_node_construct('enterprise_thankyou', $vars);
  config_node_modify($node, $vars);
dsm($node);
  node_save($node);
  config_wizard_data_set('thankyou_nid', $node->nid);
}

function enterprise_config_wizard_conversion_workflow_thankyou_page($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  $node = node_load($data['thankyou_nid']);

  dsm($data);
  dsm($node);
  $lo = array(
    'target' => '_modal',
  );
  $content = config_l(t('Edit thankyou page'), 'node/' . $node->nid . '/edit', $lo);
  $form['main'] = array(
    '#markup' => $content,
    '#editable' => 1,
  );

  /*
  
  include_once drupal_get_path('module', 'node') . '/node.pages.inc';
  
  $ne_form = drupal_get_form($node->type . '_node_form', $node);

  dsm($ne_form);
  dsm($ne_form_state);
  */

  return $form;
}

function enterprise_config_conversion_workflow_form_alter(&$form, &$form_state, $form_id) {
//dsm($form_id);
  if ($form_id == 'enterprise_thankyou_node_form') {
    $show = array(
      'actions',
      'title',
      'body',
      'field_file',
      'field_track_submission',
      'field_track_submission_value',
    );
    foreach ($form AS $key => $value) {
      if (substr($key, 0, 1) == '#') {
        continue;
      }
      if (in_array($key, $show)) {
        continue;
      }
      hide($form[$key]);
      
    }

  }
  else if ($form_id == 'google_analytics_api_admin') {
    if (isset($form['ga']) && isset($form['ga']['google_analytics_reports_profile_id'])) {
      $options = $form['ga']['google_analytics_reports_profile_id']['#options'];
      $intel_ga_account = variable_get('intel_ga_account', '');
      foreach ($options AS $key => $value) {
        $a = explode(' - ', $value);
        if ($a[1] == $intel_ga_account) {
          $form['ga']['google_analytics_reports_profile_id']['#default_value'] = $key;
          $form['ga']['google_analytics_reports_cache_length']['#default_value'] = 86400;
          break;
        }
      }
      hide($form['revoke']);
//dsm($intel_ga_account);      
    }
//dsm($form);    
  }
  else if ($form_id == 'intel_admin_scoring') {
//dsm($form);
    hide($form['targets']);
    hide($form['scores']);
    $form['advanced']['#title'] = t('Goal settings');
    $form['advanced']['#collapsed'] = FALSE;
  }
}