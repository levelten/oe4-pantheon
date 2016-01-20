<?php

function enterprise_config_wizard_install_config0($form, $form_state) {
  $data = $form_state['config']['wizard_data'];
  
  $form['main'] = array(
    '#markup' => t('TODO: information architecture config. Click submit to continue.'),
  );

  $profile = drupal_get_profile();
  if ($profile != 'openenterprise') {
    $form['config0_enable_base_config'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable base config'),
      '#description' => t('Used for initial setup of new website. Enables admin menu, backup & migrate and others'),
      '#default_value' => 0,
    );
  }

  return $form;
}

function enterprise_config_wizard_install_config0_submit($form, $form_state) {
  $values = $form_state['values'];
  if (!empty($values['config0_enable_base_config'])) {
    $modules = array();
    $modules['admin_menu'] = 1;
    $modules['admin_menu_toolbar'] = 1;
    $modules['backup_migrate'] = 1;
    $modules['module_filter'] = 1;
    $modules['toolbar'] = 0;
    config_module_enable_disable($modules);
  }
}

/**
 * Provides list of available apps with default enabled value
 * @return array: list of apps flagged true if enabled
 */
function enterprise_config_content_features_list() {
  $features = array(
    'enterprise_blog' => 1,
    'enterprise_careers' => 0,
    'enterprise_case_studies' => 0,
    'enterprise_clients' => 0,
    'enterprise_curated' => 0,
    'enterprise_events' => 0,
    'enterprise_industries' => 0,
    'enterprise_landingpages' => 1,
    'enterprise_news' => 0,
    'enterprise_press' => 0,
    'enterprise_product' => 0,
  );
  return $features;
}

function enterprise_config_content_features_list_meta() {
  $features = enterprise_config_content_features_enabled();
  $meta = array();
  foreach ($features AS $name => $enabled) {
    if ($enabled) {
      $meta[$name] = drupal_parse_info_file(drupal_get_path('module', $name). "/$name.info");
    }
  }
  return $meta;
}

/**
 * Provides enabled status of content apps
 * @return array: list of apps flagged true if enabled
 */
function enterprise_config_content_features_enabled() {
  $features = enterprise_config_content_features_list();
  foreach ($features AS $name => $default) {
    $features[$name] = module_exists($name);
  }
  return $features;
}

function enterprise_config_wizard_install_content_features($form, $form_state) {
  $form['main'] = array(
    '#markup' => t('Select the content features you would like to enable on your site.'),
  );
  
  $features = enterprise_config_content_features_list();
  $info = enterprise_config_content_features_list_meta();

  $form['features'] = array(
	  '#tree' => TRUE,
	);
 
	foreach ($features AS $module => $default_value) {
	  $path = drupal_get_path('module', $module) . '/' . $module . '.info';
    $info = drupal_parse_info_file($path);
    // if module already enabled, keep it turned on
    if (module_exists($module)) {
      $default_value = 1;
    }
    if (empty($info)) {
      $msg = t('Content feature @feature_name not found. Please download if you would like to use it on your site.',
        array(
          '@feature_name' => $module,
        )
      );
      drupal_set_message($msg, 'warning');
      continue;
    }
	  $form['features'][$module] = array(
	    '#type' => 'checkbox',
	    '#title' => (isset($info['name'])) ? $info['name'] : $module,
	    '#description' => (isset($info['description'])) ? $info['description'] : '',
	    '#default_value' => $default_value,
	  );
	}

	return $form;
}

function enterprise_config_wizard_install_features_validate($form, $form_state) {
//form_set_error('enterprise_blog', t('sure you dont want to blog'));
}

function enterprise_config_wizard_install_features_submit($form, $form_state) {
  $values = $form_state['values'];
  $modules = array();
  $modules['fontello'] = 1; // TODO: hack to solve enterprise_base dependancy on Fontello
  foreach ($values['features'] AS $name => $value) {
  	$modules[$name] = $value;
  }
  config_module_enable_disable($modules);
}

function enterprise_config_wizard_install_content_feature_config($form, $form_state) {
  $feature_name = $form_state['config']['substep_n'];

  $config_info = enterprise_apps_config_info($feature_name);

  $cf = enterprise_apps_config_form($form, $form_state, $config_info);
  // remove included submit button, use config wizard submit instead
  unset($cf['submit']);
  $form = array_merge($form, $cf);

  $form['#submit'][] = 'enterprise_apps_config_form_submit';
  return $form;
}

function enterprise_config_wizard_install_ia($form, $form_state) {
  $config = $form_state['config'];
  $wizard = $config['wizard'];
  $config_data = $config['wizard_data'];

  $form['main'] = array(
    '#markup' => t('TODO: information architecture config. Click submit to continue.'),
  );

  $description = '';
  $default_value = '';
  $form['ia'] = array(
    '#type' => 'textarea',
    '#title' => t('Main menu'),
    '#description' => $description,
    '#default_value' => $default_value,
  );
  
  return $form;
}

function enterprise_config_wizard_install_ia_submit($form, $form_state) {
  $config = $form_state['config'];
  $wizard = $config['wizard'];
  $config_data = $config['wizard_data'];
  $values = $form_state['values'];

  $tree = menu_tree_all_data('main-menu');

  $main_menu = menu_navigation_links('main-menu');

  $items = explode("\r\n", $values['ia']);
  $menu_parents = array(0);
  $prev_mlid = 0;
  foreach ($items AS $i => $line) {
    $a = explode("\t", $line);
    if (count($a) != 3) {
      continue;
    }
    $title = $a[0];
    $path = $a[1];
    $type_comp = $a[2];
    $level = 1;
    foreach (str_split($title) AS $char) {
      if ($char != '>') {
        break;
      }
      $level++;
    }
    $title = substr($title, ($level-1));
    // check item is child of previous
    // check if change in menu level
    if ($level != (count($menu_parents) -1)) {
      // check item is child of previous
      if ($level == count($menu_parents)) {
        $menu_parents[] = $prev_mlid;
      }
      else {
        $menu_parents = array_slice($menu_parents, 0 ,$level);
      }
    }
    $plid = end($menu_parents);
    
    $menu_settings = array(
      'link_title' => $title,
      'enabled' => 1,
      'weight' => $i,
      'parent' => 'main-menu:' . $plid,
      'plid' => $plid,
    );
    $mlid = _enterprise_config_wizard_install_ia_setup_menu_item($title, $path, $type_comp, $menu_settings);
    if ($mlid) {
      $prev_mlid = $mlid;
    }
    /*
    if (isset($link_path)) {
      $menu_link = array(
        'link_path' => $link_path,
        'link_title' => $title,
        'menu_name' => 'main-menu',
        'weight' => $i,
      );
      menu_link_save($menu_link);
    }
    */
  }
  
  return $form;
}

function _enterprise_config_wizard_install_ia_setup_menu_item($title, $path, $type_comp, $menu_settings) {
//$args = func_get_args();
  static $content_types;
  if (!isset($content_types)) {
    $content_types = node_type_get_types();
  }
  
  $type = explode('.', $type_comp); 
  if ($type[0] == 'node') {
    $content_type = '';
    if (isset($content_types[$type[1]])) {
      $content_type = $type[1];
    }
    else if (isset($content_types['enterprise_' . $type[1]])) {
      $content_type = 'enterprise_' . $type[1];
    }
    else if ($type[1] == 'webform') {
      $modules = array(
        'enterprise_webform' => 1
      );
      config_module_enable_disable($modules);
      if (module_exists('webform')) {
        $content_types = node_type_get_types();
        $content_type = 'webform';
      }
    }
    if (!$content_type) {
      t('Content type @ct for page @title is not enabled. Item was skipped',
        array(
          '@ct' => $type[1],
          '@title' => $title,
        )
      );
      drupal_set_message();
      return FALSE;
    }
    $node = '';
    $sys_path = drupal_lookup_path("source", $path);
    if ($sys_path) {
      $node = menu_get_object("node", 1, $sys_path);
    }
    if (!isset($node->nid)) {
      $vars = array(
        'title' => $title,
      );
      $node = config_node_construct($content_type, $vars);      
    }

    if (isset($node->type)) {
      $vars = array(
        'title' => $title,
        'path' => array(
          'alias' => $path,
          'pathauto' => 0,
        ),
        'menu' => $menu_settings,
      );
      $node = config_node_modify($node, $vars);
      node_save($node);      
    }
    if (isset($node->menu)) {
      return $node->menu['mlid']; 
    }
  }
  return FALSE;
}

function enterprise_config_wizard_install_finished($form, $form_state) {
  $config = $form_state['config'];
  $wizard = $config['wizard'];
  $config_data = $config['wizard_data'];

  $form['main'] = array(
    '#markup' => t('TODO: what to do next'),
  );

  return $form;
}
