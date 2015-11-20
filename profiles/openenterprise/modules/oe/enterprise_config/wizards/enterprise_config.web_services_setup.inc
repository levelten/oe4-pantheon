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
  //$form['accounts']['primary']['email'] = array(
  //  '#markup' => $help,
  //  '#editable' => 1,
  //);
  $fieldname = 'email';
  $form['accounts']['primary'][$fieldname] = array(
    '#type' => 'textfield',
    '#title' => t('Primary email address'),
    '#default_value' => isset($data['accounts']['primary'][$fieldname]) ? $data['accounts']['primary'][$fieldname] : '',
    '#description' => t('Input: The recovery email address, e.g. reggie@getlevelten.com'),
  );
  $fieldname = 'phone';
  $form['accounts']['primary'][$fieldname] = array(
    '#type' => 'textfield',
    '#title' => t('Primary phone'),
    '#default_value' => isset($data['accounts']['primary'][$fieldname]) ? $data['accounts']['primary'][$fieldname] : '',
  );
  $fieldname = 'username';
  $form['accounts']['personal'][$fieldname] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => isset($data['accounts']['personal'][$fieldname]) ? $data['accounts']['personal'][$fieldname] : '',
    '#description' => t('Input: reggie[clientcode]'),
  );
  $fieldname = 'firstname';
  $form['accounts']['personal'][$fieldname] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
    '#default_value' => isset($data['accounts']['personal'][$fieldname]) ? $data['accounts']['personal'][$fieldname] : '',
    '#description' => t('Input: Reggie'),
  );
  $fieldname = 'lastname';
  $form['accounts']['personal'][$fieldname] = array(
    '#type' => 'textfield',
    '#title' => t('Lastname name'),
    '#default_value' => isset($data['accounts']['personal'][$fieldname]) ? $data['accounts']['personal'][$fieldname] : '',
  );
  $fieldname = 'birthdate';
  $form['accounts']['personal'][$fieldname] = array(
    '#type' => 'textfield',
    '#title' => t('Birthdate'),
    '#default_value' => isset($data['accounts']['personal'][$fieldname]) ? $data['accounts']['personal'][$fieldname] : '',
    '#description' => t('Input: Use the start date of the agency - 20 years'),
  );
  $fieldname = 'gender';
  $options = array(
    'male' => t('Male'),
    'femail' => t('Female'),
    'other' => t('Other'),
  );
  $form['accounts']['personal'][$fieldname] = array(
    '#type' => 'select',
    '#title' => t('Gender'),
    '#options' => $options,
    '#default_value' => isset($data['accounts']['personal'][$fieldname]) ? $data['accounts']['personal'][$fieldname] : '',
    '#description' => t('Input: The gender of the agency owner.'),
  );
  /*
  $fieldname = 'security_questions';
  $form['accounts']['personal'][$fieldname] = array(
    '#type' => 'textarea',
    '#title' => t('Security Questions'),
    '#options' => $options,
    '#default_value' => isset($data['accounts']['personal'][$fieldname]) ? $data['accounts']['personal'][$fieldname] : '',
    '#description' => t('Input: Questions and Answers for any security questions.'),
  );
  */
  
  return $form;
}

function enterprise_config_wizard_web_services_setup_primary_submit($form, $form_state) {
  $values = $form_state['values'];
  $var = variable_get('config_var_accounts', array());
  $var['primary'] = array(
    'email' => $values['accounts']['primary']['email'],
    'phone' => $values['accounts']['primary']['phone'],
  );
  $var['personal'] = array(
    'username' => $values['accounts']['personal']['username'],
    'firstname' => $values['accounts']['personal']['firstname'],
    'lastname' => $values['accounts']['personal']['lastname'],
    'birthdate' => $values['accounts']['personal']['birthdate'],
    'gender' => $values['accounts']['personal']['gender'],
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
  if (module_exists('socialmedia')) {
    $profile = socialmedia_profile_load('addthis');
    if (empty($profile)) {
      $profile = array(
        'inputs' => array(),
      );
    }
    $profile['pubid'] = $values['accounts']['addthis']['profile_id'];
    $profile['inputs']['pubid'] = $values['accounts']['addthis']['profile_id'];
    socialmedia_profile_save($profile, 'addthis', 0);
  }
}

function enterprise_config_wizard_web_services_setup_disqus($form, $form_state) {
  $data = $form_state['config']['wizard_data'];

  $data['accounts'] = variable_get('config_var_accounts', array());

  $lo = array(
    'target' => 'disqus',
  );
  $items = array();
  $items[] =  t('Create an account on !link. This sets up the primary moderator for Disqus comments.', array(
    '!link' => config_l(t('Disqus'), 'https://disqus.com/', $lo),
  ));

  $items[] =  t('Next create an account on !link. ', array(
      '!link' => config_l(t('Disqus for Publishers'), 'https://publishers.disqus.com/', $lo),
  ));

  $items[] =  t('Input the username from disqus.com and the shortcode from publishers.disqus.com below.', array(
  ));

  $lo = array(
    'target' => '_modal',
  );
  $items[] =  t('Complete the configuration on the !link.', array(
    '!link' => config_l(t('Disqus configuration form'), 'admin/config/services/disqus', $lo),
  ));

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

  $form['accounts']['disqus']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Disqus account email'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['disqus']['email']) ? $data['accounts']['disqus']['email'] : ((isset($data['accounts']['default']['email'])) ? $data['accounts']['default']['email'] : ''),
  );
  $form['accounts']['disqus']['username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['disqus']['username']) ? $data['accounts']['disqus']['username'] : '',
  );
  $form['accounts']['disqus']['shortname'] = array(
    '#type' => 'textfield',
    '#title' => t('Shortname'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['disqus']['shortname']) ? $data['accounts']['disqus']['shortname'] : '',
  );

  return $form;
}

function enterprise_config_wizard_web_services_setup_disqus_submit($form, $form_state) {
  $values = $form_state['values'];
  $var = variable_get('config_var_accounts', array());
  $var['disqus'] = array(
    'email' => $values['accounts']['disqus']['email'],
    'username' => $values['accounts']['disqus']['username'],
    'shortname' => $values['accounts']['disqus']['shortname'],
  );
  variable_set('config_var_accounts', $var);

  if (module_exists('disqus')) {
    variable_set('disqus_domain', $values['accounts']['disqus']['shortname']);
  }
}