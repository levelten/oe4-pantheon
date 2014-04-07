<?php

function enterprise_config_wizard_mailchimp_setup_start($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  $items = array();
  $lo = array(
    'target' => 'mailchimp',
  );
  $items[] = t('Create a !link.',
    array(
      '!link' => config_l(t('MailChimp account'), 'http://mailchimp.com', $lo),
    )
  );
  $items[] = t('Create "Main" mailing list in MailChimp');
  if (module_exists('intel')) {
    $items[] = t('Add merge field "Intelligence" (type: website, tag: L10I_VURL)');
    $items[] = t('Add merge field "Intel ID" (type: Text, tag: L10I_VID)');
  }
  $form['main'] = array(
    '#markup' => theme('item_list', array('items' => $items, 'type' => 'ol')),
    '#editable' => 1,
  ); 
  
  $form[] = array(
    '#markup' => "\n<br />\n<br />",
    '#editable' => 1,
  ); 

  $form['accounts'] = array(
    '#tree' => TRUE,
    '#config_var' => 'accounts'
  );
  $accounts = variable_get('config_var_accounts', array());
  $form['accounts']['mailchimp']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Account email address'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['mailchimp']['email']) ? $data['accounts']['mailchimp']['email'] : ((isset($accounts['default']['email'])) ? $accounts['default']['email'] : ''),
  );
  $form['accounts']['mailchimp']['username'] = array(
    '#type' => 'textfield',
    '#title' => t('Account username'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['mailchimp']['username']) ? $data['accounts']['mailchimp']['username'] : ((isset($accounts['default']['username'])) ? $accounts['default']['username'] : ''),
  );
  
  return $form;
}

function enterprise_config_wizard_mailchimp_setup_start_submit($form, $form_state) {
  $values = $form_state['values'];
  
  $modules = array(
    'mailchimp' => 1,
    'mailchimp_lists' => 1,
    'webform_mailchimp' => 1,
    'intel_mailchimp' => 1,
  );
  config_module_enable_disable($modules);
  
  $var = variable_get('config_var_accounts', array());
  $var['mailchimp'] = array(
    'email' => $values['accounts']['mailchimp']['email'],
    'username' => $values['accounts']['mailchimp']['username'],
  );
  variable_set('config_var_accounts', $var);
}

function enterprise_config_wizard_mailchimp_setup_api($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  $help = t('Open Enterprise integrates with several web services and APIs.');
  $form['main'] = array(
    '#markup' => $help,
    '#editable' => 1,
  ); 
  
  $form[] = array(
    '#markup' => "\n<br />\n<br />",
    '#editable' => 1,
  ); 

  return $form;
}