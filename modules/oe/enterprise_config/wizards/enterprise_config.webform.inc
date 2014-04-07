<?php

function enterprise_config_wizard_webform_start($form, $form_state) {
  $data = $form_state['config']['wizard_data'];

  $content = t('Either select an existing webform to configure or enter a title for a new one.');
  $form['main'] = array(
    '#markup' => $content,
    '#editable' => 1,
  ); 
  
  $form[] = array(
    '#markup' => "\n<br />\n<br />",
    '#editable' => 1,
  ); 

  $options = array(
    'add' => t('Create a new form from scratch'),
    'clone' => t('Clone an existing form'),
    'update' => t('Modify and existing form'),
  );
  $form['crud_mode'] = array(
    '#type' => 'radios',
    '#title' => t('What would you like to do?'),
    '#options' => $options,
    '#default_value' => isset($data['crud_mode']) ? $data['crud_mode'] : 'add',
  );
  
  $query = db_select('node', 'n')
    ->fields('n')
    ->condition('type', 'webform');
  $results = $query->execute();
  $options = array(
    '' => t('NONE'),
  );
  while ($r = $results->fetchObject()) {
    $options[$r->nid] = $r->title . " [nid:{$r->nid}]";
  }
  $form['nid'] = array(
    '#type' => 'select',
    '#title' => t('Source webform'),
    '#options' => $options,
    '#default_value' => isset($data['nid']) ? $data['nid'] : '',
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#descriptions' => $options,
    '#default_value' => isset($data['title']) ? $data['title'] : '',
  );
  
  return $form;
}

function enterprise_config_wizard_webform_start_validate($form, $form_state) {
  $values = $form_state['values'];
 
  if (($values['crud_mode'] != 'add') && !$values['nid']) {
    form_set_error('nid', t('Select a source webform.'));
  }
  if (($values['crud_mode'] != 'update') && !trim($values['title'])) {
    form_set_error('title', t('Create a title for the new webform.'));
  }
}

function enterprise_config_wizard_webform_start_submit($form, &$form_state) {
  include_once drupal_get_path('module', 'enterprise_config') . '/includes/enterprise_config.lib.inc';

  $values = $form_state['values'];
  if ($values['crud_mode'] == 'add') {
    $vars = array(
      'title' => $values['title'],
    );
    $node = enterprise_config_construct_webform($vars);
    node_save($node);
    $form_state['values']['nid'] = $node->nid;
  }
  if ($values['crud_mode'] == 'clone') {
    $vars = array(
      'nid' => $values['nid'],
    );
    $node = config_node_construct('webform', $vars);
    $node->title = $values['title'];
    enterprise_config_unset_entity_uuid($node);
    node_save($node);
    $form_state['values']['clone_nid'] = $form_state['values']['nid'];  
    $form_state['values']['nid'] = $node->nid;    
  }
}

function enterprise_config_wizard_webform_fields($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
//dsm($data);
  $node = node_load($data['nid']);

  $content = t('Select form fields.');
  $form['main'] = array(
    '#markup' => $content,
    '#editable' => 1,
  );

  $form['fields'] = array(
    '#tree' => TRUE,
  );

  $fields  = config_webform_present_components();
  
  $query = db_select('webform_component', 'c')
    ->fields('c');
  $result = $query->execute();
  
  while ($r = $result->fetchAssoc()) {
    $key = $r['form_key'];
    if (!isset($fields[$key])) {
      $fields[$key] = $r;
    }
  }
  
  $ignore = array(
    'mailchimp',
    'intel_visitor_url',
  );
  
  $form['components'] = array(
    '#type' => 'value',
    '#value' => $fields,
    '#config_data' => FALSE,
  );
  
  $data['fields'] = array();
  foreach($node->webform['components'] AS $i => $comp) {
    if (in_array($comp['form_key'], $ignore)) {
      continue;
    }
    $data['fields'][] = $comp['form_key'];
  }
  
  
  $options = array();
  foreach ($fields AS $key => $field) {
    if (in_array($key, $ignore)) {
      continue;
    }
    $options[$key] = $field['name'];
  }
  
  $form['fields'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Form fields'),
    '#options' => $options,
    '#default_value' => isset($data['fields']) ? $data['fields'] : array('email', 'first_name', 'last_name'),
  );
   
  return $form;
}

function enterprise_config_wizard_webform_fields_submit($form, &$form_state) {
  $values = $form_state['values'];
  $config = $form_state['config'];
  $data = $config['wizard_data'];
  $node = node_load($data['nid']);

  $existing_keys = array();
  $components = $node->webform['components'];
  $components = array();
  /*
  foreach ($components AS $i => $comp) {
    $existing_keys[$comp['form_key']] = $i;
  }
  */
  $cid = 1;
  foreach ($values['fields'] AS $key => $value) {
    if (!$value) {
      continue;
    }
    $comp = $values['components'][$key];
    $comp['nid'] = $node->nid;
    $comp['cid'] = $cid;
    // unserialize extra data if not already done
    if (is_scalar($comp['extra'])) {
      $comp['extra'] = unserialize($comp['extra']);
    }
    $components[$cid] = $comp;
    $cid++;
  }
  $node->webform['components'] = $components;
dsm($node->webform);
  node_save($node);
  $form_state['config']['wizard_data']['webform'] = $node;
  // don't save components
  unset($form_state['values']['components']);
}

function enterprise_config_wizard_webform_fieldsord($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  $node = node_load($data['nid']);

  $lo = array(
    'target' => '_modal',
  );
  $content = config_l(t('Sort fields and verifiy details'), 'node/' . $node->nid . '/webform', $lo);
  $form['main'] = array(
    '#markup' => $content,
    '#editable' => 1,
  );

  $form['fields'] = array(
    '#tree' => TRUE,
  );

  return $form;
}

function enterprise_config_wizard_webform_emails($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  $node = node_load($data['nid']);

  $lo = array(
    'target' => '_modal',
  );
  $content = config_l(t('Configure emails to be sent on submission'), 'node/' . $node->nid . '/webform/emails', $lo);
  $form['main'] = array(
    '#markup' => $content,
    '#editable' => 1,
  );

  $form['fields'] = array(
    '#tree' => TRUE,
  );
  
  return $form;
}

function enterprise_config_wizard_webform_submission_actions($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  $node = node_load($data['nid']);

  $lo = array(
    'target' => '_modal',
  );
  $content = config_l(t('Configure submission actions'), 'node/' . $node->nid . '/webform/configure', $lo);
  $form['main'] = array(
    '#markup' => $content,
    '#editable' => 1,
  );

  $form['fields'] = array(
    '#tree' => TRUE,
  );
  
  return $form;
}

function enterprise_config_wizard_webform_intel($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  $node = node_load($data['nid']);

  $lo = array(
    'target' => '_modal',
  );
  $content = config_l(t('Map fields to Intelligence'), 'node/' . $node->nid . '/webform/intel', $lo);
  $form['main'] = array(
    '#markup' => $content,
    '#editable' => 1,
  );

  $form['intel'] = array(
    '#tree' => TRUE,
  );
  
  //dsm($data);

  return $form;
}

function enterprise_config_wizard_webform_intel_submit($form, &$form_state) {
  $values = $form_state['values'];
  $config = $form_state['config'];
  $data = $config['wizard_data'];
  $node = node_load($data['nid']);
//dsm($form_state);
  
  $intel_visitor_url_comp = enterprise_config_get_webform_component($node, 'intel_visitor_url');

  if (!$intel_visitor_url_comp) {  
    $node->webform['components'][] = array(
      'nid' => $node->nid,
      'name' => 'Visitor intel',
      'form_key' => 'intel_visitor_url',
      'type' => 'hidden',
      'mandatory' => 0,
      'weight' => 99,
      'pid' => 0,
      'extra' => array(
        'hidden_type' => 'hidden',
      ),
    );
    node_save($node);
  }  
  
  $form_state['config']['wizard_data']['webform'] = $node;
}

function enterprise_config_wizard_webform_mailchimp($form, &$form_state) {
  $data = $form_state['config']['wizard_data'];
  $node = node_load($data['nid']);
  $form_state['config']['wizard_data']['webform'] = $node;
  
  $lo = array(
    'target' => '_modal',
  );
  $content = config_l(t('Map fields to Intelligence'), 'node/' . $node->nid . '/webform/intel', $lo);
  $form['main'] = array(
    '#markup' => $content,
    '#editable' => 1,
  );
  // make fieldset 'extra' rather than 'mailchimp' so webform_mailchimp validation works, move values in submit hook
  $form['extra'] = array(
    '#tree' => TRUE,
  );
  
  $mc_comp = enterprise_config_get_webform_component($node, 'mailchimp');
  if (!$mc_comp) {
    $mc_comp = array(
      'nid' => $data['nid'],
      'name' => 'MailChimp',
      'form_key' => 'mailchimp',
      'type' => 'mailchimp',
      'mandatory' => 0,
      'weight' => 100,
      'pid' => 0,
      'value' => '',
      'extras' => array(),
    );
  }
  
  $form_state['mc_comp'] = $mc_comp;
  
  include_once drupal_get_path('module', 'webform_mailchimp') . '/webform_mailchimp.inc';
  
  $mc_form = _webform_edit_mailchimp($mc_comp);
//dsm($mc_form);

  $form['extra']['mailchimp_list'] = $mc_form['extra']['mailchimp_list'];
  $form['extra']['use_existing_email_field'] = $mc_form['extra']['use_existing_email_field'];
  $form['extra']['checkbox_checked_by_default'] = $mc_form['extra']['checkbox_checked_by_default'];
  $form['extra']['checkbox_checked_by_default']['#default_value'] = isset($mc_comp['extras']['checkbox_checked_by_default']) ? $mc_comp['extras']['checkbox_checked_by_default'] : 1;
  $form['extra']['checkbox_hidden'] = $mc_form['extra']['checkbox_hidden'];
  $form['extra']['checkbox_hidden']['#default_value'] = isset($mc_comp['extras']['checkbox_hidden']) ? $mc_comp['extras']['checkbox_hidden'] : 1;
  $form['extra']['mergefields'] = $mc_form['extra']['mergefields'];
  
  $merge_default = '';
  foreach ($node->webform['components'] AS $i => $comp) {
    if ($comp['form_key'] == 'first_name') {
      $merge_default .= "FNAME|first_name\n";
    }
    if ($comp['form_key'] == 'last_name') {
      $merge_default .= "LNAME|last_name\n";
    }
  }
  $form['extra']['mergefields']['#default_value'] = $merge_default;
  
  //dsm($data);

  return $form;
}

function enterprise_config_wizard_webform_mailchimp_submit($form, &$form_state) {
  $values = $form_state['values'];
  $config = $form_state['config'];
  $data = $config['wizard_data'];
  $node = node_load($data['nid']);
//dsm($form_state);
  
  $mc_comp = $form_state['mc_comp'];
  $mc_comp['extra']['mailchimp_list'] = $values['extra']['mailchimp_list'];
  $mc_comp['extra']['use_existing_email_field'] = $values['extra']['use_existing_email_field'];
  $mc_comp['extra']['checkbox_checked_by_default'] = $values['extra']['checkbox_checked_by_default'];
  $mc_comp['extra']['checkbox_hidden'] = $values['extra']['checkbox_hidden'];
  $mc_comp['extra']['mergefields'] = $values['extra']['mergefields'];  
  
  $mc_comp['extra'] += array(
        'checkbox_label' => 'Subscribe to newsletter',
        'title_display' => 'before',
        'private' => 0,
        'conditional_operator' => '=',
        'field_prefix' => '',
        'field_suffix' => '',
        'description' => '',
        'attributes' => array (),
        'conditional_component' => '',
        'conditional_values' => '',
  );
  enterprise_config_set_webform_component($node, 'mailchimp', $mc_comp);
  //$node->webform = $webform;
//dsm($node);
  node_save($node);
  $form_state['values'] = array(
    'mailchimp' => $form_state['values'],
  );
  $form_state['config']['wizard_data']['webform'] = $node;
}

function enterprise_config_get_webform_component($node, $key) {
  foreach ($node->webform['components'] AS $i => $comp) {
    if ($comp['form_key'] == $key) {
      return $comp;
    }
  }
  return FALSE;
}

function enterprise_config_set_webform_component(&$node, $key, $component) {
  $index = -1;
  foreach ($node->webform['components'] AS $i => $comp) {
    if ($comp['form_key'] == $key) {
      $node->webform['components'][$i] = $component;
      $index = $i;
      break;
    }
  }
  if ($index == -1) {
    $node->webform['components'][] = $component;
  }
  return $node;
}

// see https://drupal.org/node/2030697
function enterprise_config_construct_webform($vars) {
  require_once drupal_get_path('module', 'config') . "/includes/config.webform.inc";
  $node = config_node_construct('webform', $vars);
//dsm($node);
  //$ewrapper = entity_metadata_wrapper('node', $node);
//dsm($ewrapper);

  $components = array();

  /*
  $components = array();
  $components[] = config_webform_component('first_name');
  $components[] = config_webform_component('last_name');
  $components[] = config_webform_component('email');
  */
//dsm($components);
  
  // Setup notification email.
  $emails = array(
    array(
      'email' => 'somebody@example.tld',
      'subject' => 'default',
      'from_name' => 'default',
      'from_address' => 'default',
      'template' => 'default',
      'excluded_components' => array(),
    ),
  );
  // Attach the webform to the node.
  $node->webform = array(
    'confirmation' => '',
    'confirmation_format' => NULL,
    'redirect_url' => '<confirmation>',
    'status' => '1',
    'block' => '0',
    'teaser' => '0',
    'allow_draft' => '0',
    'auto_save' => '0',
    'submit_notice' => '1',
    'submit_text' => '',
    'submit_limit' => '-1', // User can submit more than once.
    'submit_interval' => '-1',
    'total_submit_limit' => '-1',
    'total_submit_interval' => '-1',
    'record_exists' => TRUE,
    'roles' => array(
      0 => '1', // Anonymous user can submit this webform.
    ),
    'emails' => $emails,
    'components' => $components,
  );
  return $node;
//dsm($node);
  // Save the node.
  //node_save($node);
}

function config_webform_present_components() {
  $components = array();
  $weight = 0;
  $components['first_name'] = array(
    'name' => 'First name',
    'form_key' => 'first_name',
    'type' => 'textfield',
    'mandatory' => 1,
    'weight' => $weight++,
    'pid' => 0,
    'extra' => array(
      'title_display' => 'before',
      'private' => 0,
    ),
  );
  $components['last_name'] = array(
    'name' => 'Last name',
    'form_key' => 'last_name',
    'type' => 'textfield',
    'mandatory' => 1,
    'weight' => $weight++,
    'pid' => 0,
    'extra' => array(
      'title_display' => 'before',
      'private' => 0,
    ),
  );
  $components['email'] = array(
    'name' => 'Email',
    'form_key' => 'email',
    'type' => 'email',
    'mandatory' => 1,
    'weight' => $weight++,
    'pid' => 0,
    'extra' => array(
      'title_display' => 'before',
      'private' => 0,
    ),
  );
  $components['phone'] = array(
    'name' => 'Phone number',
    'form_key' => 'phone',
    'type' => 'text',
    'mandatory' => 1,
    'weight' => $weight++,
    'pid' => 0,
    'extra' => array(
      'title_display' => 'before',
      'private' => 0,
    ),
  );
  if (module_exists('webform_phone')) {
    $components['phone']
  }
  $components['website'] = array(
    'name' => 'Website',
    'form_key' => 'website',
    'type' => 'text',
    'mandatory' => 1,
    'weight' => $weight++,
    'pid' => 0,
    'extra' => array(
      'title_display' => 'before',
      'private' => 0,
    ),
  );
  $components['subject'] = array(
    'name' => 'Subject',
    'form_key' => 'subject',
    'type' => 'textfield',
    'mandatory' => 1,
    'weight' => $weight++,
    'pid' => 0,
    'extra' => array(
      'title_display' => 'before',
      'private' => 0,
    ),
  );
  $components['message'] = array(
    'name' => 'Message',
    'form_key' => 'message',
    'type' => 'textarea',
    'mandatory' => 1,
    'weight' => $weight++,
    'pid' => 0,
    'extra' => array(
      'title_display' => 'before',
      'private' => 0,
    ),
  );
  return $components;
}