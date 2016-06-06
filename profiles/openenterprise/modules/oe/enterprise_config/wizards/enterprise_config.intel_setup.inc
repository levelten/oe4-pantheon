<?php

function enterprise_config_config_wizard_intel_setup_ga($form, $form_state) {
  $config = $form_state['config'];
  $wizard = $config['wizard'];
  $config_data = $config['wizard_data'];

  $data['accounts'] = variable_get('config_var_accounts', array());

  // check if a valid GA tracking id exists
  /*
  $validate = enterprise_config_config_wizard_intel_setup_ga_validate($form, $form_state);
  $validated = !(form_get_errors());
  form_clear_error();


  $errors = config_check_validate_func('enterprise_config_config_wizard_intel_setup_ga_validate', $form, $form_state);
  //$validated = empty(config_check_validate_func('enterprise_config_config_wizard_analytics_setup_basic_validate', $form, $form_state));
  */



  $modules = array(
    'googleanalytics' => 1,
  );
  config_module_enable_disable($modules);
	$help = <<<HELP
<p>
You will need to setup 2 Google Analytics tracking ids/properties. One for standard (thru) GA tracking, and one for Intelligence.
It is recommended to name both properties with the the same name root and add thru and Intel to the end, i.e. OE Pro Demo thru, OE Prod Demo Intel
</p><br />
<p>
If the client already has a Google Analytics account, have them add the default email to the account (TODO, what level of permissions)
If you do not already have a Google Analytics account, <a href="http://www.google.com/analytics" target="ga">create one</a>.
</p><br />
Enter the standard (thru) tracking id in the <a href="/admin/config/system/googleanalytics" target="_modal">Google Analtyics configuration form</a>.
HELP;

  $form['main'] = array(
    '#markup' => $help,
  );


  $form[] = array(
    '#markup' => "\n<br />\n<br />",
    '#editable' => 1,
  );

  $form['accounts'] = array(
    '#tree' => TRUE,
    '#config_var' => 'accounts',
  );

  $form['accounts']['google_analytics']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Account email'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['google_analytics']['email']) ? $data['accounts']['google_analytics']['email'] : ((isset($data['accounts']['default']['email'])) ? $data['accounts']['default']['email'] : ''),
  );
  $form['accounts']['google_analytics']['account'] = array(
    '#type' => 'textfield',
    '#title' => t('Account Name'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['google_analytics']['account']) ? $data['accounts']['google_analytics']['account'] : '',
  );
  $form['accounts']['google_analytics']['standard_property'] = array(
    '#type' => 'textfield',
    '#title' => t('Standard (thru) Property Name'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['standard_property']['property']) ? $data['accounts']['standard_property']['property'] : '',
  );
  $form['accounts']['google_analytics']['intel_property'] = array(
    '#type' => 'textfield',
    '#title' => t('Intel Property Name'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['intel_property']['property']) ? $data['accounts']['intel_property']['property'] : '',
  );

  return $form;
}

function enterprise_config_config_wizard_intel_setup_ga_validate($form, $form_state) {
  $config = $form_state['config'];
  $wizard = $config['wizard'];
  $config_data = $config['wizard_data'];

  $gaid = variable_get('googleanalytics_account', 'UA-');
  if (empty($gaid) || strlen($gaid) < 5) {
    $msg = t('Please enter a valid Google Analtyics tracking id before proceeding. (via the !link.)', array(
      '!link' => config_l(t('Google Analytics configuration form'), 'admin/config/system/googleanalytics', array('target' => '_modal'))
    ));
    form_set_error('main', $msg);
  }
}

function enterprise_config_config_wizard_intel_setup_ga_submit($form, $form_state) {
  $values = $form_state['values'];
  $var = variable_get('config_var_accounts', array());
  $var['google_analytics'] = array(
    'email' => $values['accounts']['disqus']['email'],
    'account' => $values['accounts']['google_analytics']['account'],
    'standard_property' => $values['accounts']['google_analytics']['standard_property'],
    'intel_property' => $values['accounts']['google_analytics']['intel_property'],
  );
  variable_set('config_var_accounts', $var);
}

function enterprise_config_config_wizard_intel_setup_intel_account($form, $form_state) {
  $config = $form_state['config'];
  $wizard = $config['wizard'];
  $config_data = $config['wizard_data'];

  $data['accounts'] = variable_get('config_var_accounts', array());

  $help = <<<HELP
<p>
Create an Intelligence account/property at <a href="http://getcm2.com/user" target="getcm2">getcm2.com</a> using the default email for this site and the Intel tracking id from Google Analytics.
Once the property is created, a getcm2.com user with administration permissions can change the level of the API to Pro for the property.
</p><br />
Enter the Intelligence tracking id from Google Analytics and the API key from getcm2.com in the <a href="/admin/config/intel/settings" target="_modal">Intelligence configuration form</a>.
HELP;

  $form['main'] = array(
    '#markup' => $help,
  );


  $form[] = array(
    '#markup' => "\n<br />\n<br />",
    '#editable' => 1,
  );

  $form['accounts'] = array(
    '#tree' => TRUE,
    '#config_var' => 'accounts',
  );

  $form['accounts']['intel']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('GetCM2 Account email'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['intel']['email']) ? $data['accounts']['intel']['email'] : ((isset($data['accounts']['default']['email'])) ? $data['accounts']['default']['email'] : ''),
  );
  $form['accounts']['intel']['property'] = array(
    '#type' => 'textfield',
    '#title' => t('GetCM2 Property Name'),
    //'#descriptions' => $options,
    '#default_value' => isset($data['accounts']['intel']['property']) ? $data['accounts']['intel']['property'] : '',
  );

  return $form;
}

function enterprise_config_config_wizard_intel_setup_intel_account_validate($form, $form_state) {
  $config = $form_state['config'];
  $wizard = $config['wizard'];
  $config_data = $config['wizard_data'];

  $gaid = variable_get('intel_ga_account', 'UA-');
  if (empty($gaid) || strlen($gaid) < 5) {
    $msg = t('Please enter a valid Google Analtyics tracking id before proceeding. (via the !link.)', array(
      '!link' => config_l(t('Google Analytics configuration form'), 'admin/config/intel/settings', array('target' => '_modal'))
    ));
    form_set_error('main', $msg);
  }

  $apikey = variable_get('intel_apikey', '');
  if (empty($apikey)) {
    $msg = t('Please enter a valid Intelligence API key before proceeding. (via the !link.)', array(
      '!link' => config_l(t('Google Analytics configuration form'), 'admin/config/intel/settings', array('target' => '_modal'))
    ));
    form_set_error('main', $msg);
  }
}

function enterprise_config_config_wizard_intel_setup_intel_account_submit($form, $form_state) {
  $values = $form_state['values'];
  $var = variable_get('config_var_accounts', array());
  $var['intel'] = array(
    'email' => $values['accounts']['intel']['email'],
    'property' => $values['accounts']['intel']['property'],
    //'tid' => variable_get('intel_ga_account', ''),
    //'apikey' => variable_get('intel_apikey', ''),
  );
  variable_set('config_var_accounts', $var);
}

function enterprise_config_config_wizard_intel_setup_ga_api($form, $form_state) {
  $config = $form_state['config'];
  $wizard = $config['wizard'];
  $config_data = $config['wizard_data'];

  $help = <<<HELP
<p>
You will need to connect/authorize the site to connect with the Google Analytics API.
</p><br />
<p>
Follow the instructions on <a href="/admin/config/system/google-analytics-reports-api" target="_modal">Google Analytics API configuration form</a> to authorize the site.
Once authorized, you will be presented with a Reports profile select box. Select the property/view for the Intel Property.
</p><br />

HELP;

  $form['main'] = array(
    '#markup' => $help,
  );


  /*
  $form[] = array(
    '#markup' => "\n<br />\n<br />",
    '#editable' => 1,
  );
  */
  
  return $form;
}

function enterprise_config_analytics_setup_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'googleanalytics_admin_settings_form') {
    $form['tracking']['#type'] = '';
    $show = array('domain_tracking');
    foreach ($form['tracking'] AS $k => $v) {
      if ((substr($k, 0 , 1) != '#') && !in_array($k, $show)) {
        hide($form['tracking'][$k]);
      }
    }
    hide($form['googleanalytics_custom_var']);
    hide($form['advanced']);
  }
  else if ($form_id == 'intel_admin_settings') {
    $ga_domain_mode = variable_get('googleanalytics_domain_mode', '');
    if ($ga_domain_mode) {
      $a = explode('//', $GLOBALS['base_root']);
      $domain = $a[1];
      $form['tracking']['intel_domain_name']['#default_value'] = $domain;
    }
    hide($form['reports']);
    hide($form['l10iapi']['advanced']);
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
    }
  }
  else if ($form_id == 'intel_admin_scoring') {
    hide($form['targets']);
    hide($form['scores']);
    $form['advanced']['#title'] = t('Goal settings');
    $form['advanced']['#collapsed'] = FALSE;
  }
}