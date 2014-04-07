<?php

function enterprise_config_wizard_web_services_setup_primary($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  
  $data['accounts'] = variable_get('config_var_accounts', array());
  
  $help = t('Open Enterprise integrates with several web services and APIs.');
  $form['main'] = array(
    '#markup' => $help,
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
  $form['accounts']['primary']['email'] = array(
    '#markup' => $help,
    '#editable' => 1,
  );   
  $form['accounts']['primary']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Primary email address'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['primary']['email']) ? $data['accounts']['primary']['email'] : '',
  );
  $form['accounts']['primary']['phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Primary phone'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['primary']['phone']) ? $data['accounts']['primary']['phone'] : '',
  );
  
  return $form;
}

function enterprise_config_wizard_web_services_setup_primary_submit($form, $form_state) {
  $values = $form_state['values'];
  $var = variable_get('config_var_accounts', array());
  $var['primary'] = array(
    'email' => $values['accounts']['primary']['email'],
    'phone' => $values['accounts']['primary']['phone'],
  );
  variable_set('config_var_accounts', $var);
}

function enterprise_config_wizard_web_services_setup_email($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  
  $data['accounts'] = variable_get('config_var_accounts', array());

  $help = t('Open Enterprise integrates with several web services and APIs.');
  $form['main'] = array(
    '#markup' => $help,
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
  $help = t('Create a !link.',
    array(
      '!link' => l(t('Gmail account'), 'https://mail.google.com'),
    )    
  );
  $form['accounts']['gmail']['gmail-help'] = array(
    '#markup' => $help,
    '#editable' => 1,
  );   
  $form['accounts']['gmail']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Gmail'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['gmail']['email']) ? $data['accounts']['gmail']['email'] : '',
  );
  
  $help = t('Create a !link.',
    array(
      '!link' => l(t('Yahoo! account'), 'https://mail.yahoo.com'),
    )    
  );
  $form['accounts']['yahoo']['yahoo-help'] = array(
    '#markup' => $help,
    '#editable' => 1,
  );   
  $form['accounts']['yahoo']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Yahoo! Mail'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['yahoo']['email']) ? $data['accounts']['yahoo']['email'] : '',
  );
  
  $help = t('Create a !link.',
    array(
      '!link' => l(t('Microsoft account'), 'https://signup.live.com/signup.aspx'),
    )    
  );
  $form['accounts']['microsoft']['bing-help'] = array(
    '#markup' => $help,
    '#editable' => 1,
  );   
  $form['accounts']['microsoft']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Microsoft account'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['microsoft']['email']) ? $data['accounts']['microsoft']['email'] : '',
  );
  
  $help = t('Set defaults for account setup');
  $form['accounts']['default']['help'] = array(
    '#markup' => $help,
    '#editable' => 1,
  );   
  $form['accounts']['default']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Default email'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['default']['email']) ? $data['accounts']['default']['email'] : '',
  );
  $form['accounts']['default']['username'] = array(
    '#type' => 'textfield',
    '#title' => t('Default username'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['default']['username']) ? $data['accounts']['default']['username'] : '',
  );
  
  return $form;
}

function enterprise_config_wizard_web_services_setup_email_submit($form, $form_state) {
  $values = $form_state['values'];
  $var = variable_get('config_var_accounts', array());
  $var['gmail'] = array(
    'email' => $values['accounts']['gmail']['email'],
  );
  $var['yahoo'] = array(
    'email' => $values['accounts']['yahoo']['email'],
  );
  $var['microsoft'] = array(
    'email' => $values['accounts']['microsoft']['email'],
  );
  $var['default'] = array(
    'email' => $values['accounts']['default']['email'],
    'username' => $values['accounts']['default']['username'],
  );
  variable_set('config_var_accounts', $var);
}

function enterprise_config_wizard_web_services_setup_addthis($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  
  $data['accounts'] = variable_get('config_var_accounts', array());

  $lo = array(
    'target' => 'addthis',
  );
  $items = array();
  $items[] =  t('Create an account on !link',
    array(
      '!link' => config_l(t('AddThis'), 'http://www.addthis.com/login', $lo),
    )
  );
  
  $items[] =  t('Create a !link for the site.',
    array(
      '!link' => config_l(t('profile'), 'https://www.addthis.com/settings/publisher', $lo),
    )
  );
  
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
    '#config_var' => 'accounts',
  );
  
  $form['accounts']['addthis']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis account email'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['addthis']['email']) ? $data['accounts']['addthis']['email'] : ((isset($data['accounts']['default']['email'])) ? $data['accounts']['default']['email'] : ''),
  );
  $form['accounts']['addthis']['profile_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Profile ID'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['addthis']['profile_id']) ? $data['accounts']['addthis']['profile_id'] : '',
  );
  
  return $form;
}

function enterprise_config_wizard_web_services_setup_addthis_submit($form, $form_state) {
  $values = $form_state['values'];
  $var = variable_get('config_var_accounts', array());
  $var['addthis'] = array(
    'email' => $values['accounts']['addthis']['email'],
    'profile_id' => $values['accounts']['addthis']['profile_id'],
  );
  variable_set('config_var_accounts', $var);
  variable_set('enterprise_social_pubid', $values['accounts']['addthis']['profile_id']);
}