<?php
/**
 * @file
 * Code for the Enterprise Apps Admin.
 */

function enterprise_apps_apps_list_page() {
  $apps_info = enterprise_apps_get_apps_info();
  $header = array(
    t('App'),
    t('Actions'),
  );
  $rows = array();
  foreach ($apps_info as $name => $info) {
    $row = array();
    $row[] = $info['name'];
    $row[] = l(t('config'), 'admin/structure/features/apps/' . $name . '/config');
    $rows[] = $row;
  }
  $vars = array(
    'header' => $header,
    'rows' => $rows,
  );
  return theme('table', $vars);
}

function enterprise_apps_feature_config_form($form, &$form_state, $feature) {

  $app_name = enterprise_apps_get_app_project_name($feature->name);

  $form = enterprise_apps_config_form($form, $form_state, $app_name);

  return $form;
}

function enterprise_apps_config_form($form, &$form_state, $app_name) {
  //drupal_add_css(drupal_get_path('module', 'enterprise_config') . '/css/enterprise_config.admin.css');

  //dsm($config_info);

  $apps_info = enterprise_apps_get_apps_info();
  drupal_set_title(t('App Config %name', array('%name' => $apps_info[$app_name]['name'])), PASS_THROUGH);

  $config_info = enterprise_apps_config_info($app_name);

  $form['app_config_info'] = array(
    '#type' => 'value',
    '#value' => $config_info,
  );

  $form['#tree'] = TRUE;

  $form = enterprise_apps_config_form_blocks($form, $form_state, $config_info);

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );

  // Use the default block admin form submit.
  //$form['#submit'][] = 'enterprise_config_apps_structures_blocks_form_submit';
  //$form['#submit'][] = 'block_admin_display_form_submit';
  //dsm($form);
  return $form;
}

function enterprise_apps_config_form_blocks($form, &$form_state, $config_info) {
  $form['blocks'] = array();
  $theme = variable_get('theme_default', 'bartik');

  $form['blocks']['theme'] = array(
    '#type' => 'value',
    '#value' => $theme,
  );
  // Fetch and sort blocks.
  require_once(drupal_get_path('module', 'block') . '/block.admin.inc');
  $app_block_keys = array();
  foreach ($config_info['blocks'] AS $ci_block_name => $ci_block) {
    $app_block_keys[$ci_block['module'] . ':' . $ci_block['delta']] = $ci_block_name;
  }
  $blocks = block_admin_display_prepare_blocks($theme);
  $app_blocks = array();
  foreach($blocks as $block) {
    if (isset($app_block_keys[$block['module'] . ':' . $block['delta']])) {
      $block['config_info_name'] = $app_block_keys[$block['module'] . ':' . $block['delta']];
      $app_blocks[] = $block;
    }
  }


  $block_regions = system_region_list($theme);

  //dsm($blocks);
  //dsm($app_block_keys);
  //dsm($config_info);
  //dsm($app_blocks);
  //dsm($theme);
  //dsm($block_regions);

  foreach ($app_blocks as $i => $block) {
    $config_info_name = $block['config_info_name'];
    $key = $block['module'] . '_' . $block['delta'];

    $ci_block = $config_info['blocks'][$block['config_info_name']];
    $block['node_types'] = db_query("SELECT type FROM {block_node_type} WHERE module = :module AND delta = :delta", array(
      ':module' => $block['module'],
      ':delta' => $block['delta'],
    ))->fetchCol();

    $result = db_query("SELECT * FROM {block_views} WHERE module = :module AND delta = :delta", array(
      ':module' => $block['module'],
      ':delta' => $block['delta'],
    ))->fetchAll();
    $block['views'] = array();
    if (is_array($result)) {
      foreach ($result AS $row) {
        $block['views'][] = "$row->view:$row->display";
      }
    }

    $block['pages_array'] = array();
    if (trim($block['pages'])) {
      $block['pages_array'] = explode("\n", $block['pages']);
    }

    $form['blocks'][$key] = array(
      '#type' => 'fieldset',
      '#title' => t('@block', array('@block' => $block['info'])),
      '#description' =>  isset($app_blocks_struc['description']) ? $app_blocks_struc['description'] : '',
      '#collapsible' => TRUE,
    );
    $form['blocks'][$key]['block'] = array(
      '#type' => 'value',
      '#value' => $block,
    );
    $suffix = '';
    $default = '';
    if (($block['region'] == BLOCK_REGION_NONE) && isset($ci_block['default']['region'])) {
      foreach ($ci_block['default']['region'] AS $region) {
        if (isset($block_regions[$region])) {
          $default = $region;
          $suffix = ' ' . t('(currently hidden)');
          break;
        }
      }
    }
    else {
      $default = $block['region'] != BLOCK_REGION_NONE ? $block['region'] : NULL;
    }
    $form['blocks'][$key]['region'] = array(
      '#type' => 'select',
      '#default_value' => $default,
      '#empty_value' => BLOCK_REGION_NONE,
      '#title' => t('Region'),
      '#options' => $block_regions,
      '#field_suffix' => $suffix,
    );
    $options = array();
    $defaults = array();
    $checks = array('path', 'node_type', 'views');
    $custom = $block;
    // look through ci_block visibility settings and diff with existing block settings
    // store existing block settings in custom visibility preset
    if (!empty($ci_block['visibility_presets'])) {
      foreach ($ci_block['visibility_presets'] AS $k => $b) {
        $options[$k] = $b['title'];
        $b += array(
          'path' => array(
            'pages' => array(),
            'visibility' => 0,
          ),
          'node_type' => array(
            'types' => array(),
          ),
          'views' => array(
            'views' => array(),
          ),
        );
        $bc = $b;

        if (($b['path']['visibility'] == $block['visibility'])) {
          foreach ($block['pages_array'] AS $i => $page) {
            if ($bci = array_search($page, $b['path']['pages'])) {
              unset($bc['path']['pages'][$bci]);
              unset($custom['pages'][$i]);
            }
          }
        }
        foreach ($block['node_types'] AS $i => $type) {
          //dsm($type);
          $bci = array_search($type, $b['node_type']['types']);
          if ($bci !== FALSE) {
            //dsm($bci);
            unset($bc['node_type']['types'][$bci]);
            unset($custom['node_types'][$i]);
          }
        }
        foreach ($block['views'] AS $i => $view) {
          $bci = array_search($view, $b['views']['views']);
          if ($bci !== FALSE) {
            unset($bc['views']['views'][$bci]);
            unset($custom['views'][$i]);
          }
        }

        //dsm($bc);
        if (empty($bc['path']['pages']) && empty($bc['node_type']['types']) && empty($bc['views']['views'])) {
          $defaults[] = $k;
        }
      }
      //dsm($custom);
      //dsm($options);
      $description_extra = '';
      if (!empty($custom['pages_array'])|| !empty($custom['node_types']) || !empty($custom['views'])) {
        $options['custom'] = t('Keep existing custom settings');
        $defaults[] = 'custom';
        $custom_preset = array(
          'path' => array(
            'pages' => $custom['pages_array'],
            'visibility' => 0,
          ),
          'node_type' => array(
            'types' => $custom['node_types'],
          ),
          'views' => array(
            'views' => $custom['views'],
          ),
        );

        // add custom settings to app_config to preserve
        $form['app_config_info']['#value']['blocks'][$config_info_name]['visibility_preset']['custom'] = $custom_preset;
        $description_extra = ' ' . t('There are some existing custom visibility settings. These settings may conflict with presets. To keep the existing settings leave "Keep existing..." option selected.');
      }
      if ($block['region'] == -1 && isset($ci_block['default']['visibility_preset'])) {
        $defaults = $ci_block['default']['visibility_preset'];
      }
      $description_extra .= ' ' . t('For advanced settings see the !link.',
          array(
            '!link' => l(t('block configure form'), 'admin/structure/block/manage/' . $block['module'] . '/' . $block['delta'] . '/configure', array('attributes' => array('target' =>  '_blank'))),
          )
        );
      $form['blocks'][$key]['visibility_presets'] = array(
        '#type' => 'checkboxes',
        '#default_value' => $defaults,
        '#title' => t('Visibility'),
        '#options' => $options,
        '#description' => t('Use the check boxes to display the block only on specific pages within your site. Leave all selections unchecked to show on all pages.') . $description_extra,
        '#attributes' => array(
          'class' => array('scrollable'),
        )
      );
      $form['blocks'][$key]['visibility_presets_default'] = array(
        '#type' => 'value',
        '#value' => $defaults,
      );
    }

  }
  if (isset($form['blocks']) && count($form['blocks'])) {
    $form['blocks'] += array(
      '#type' => 'fieldset',
      '#title' => t('Blocks config'),
      '#description' => t('Configure placement of app blocks.'),
      '#collapsible' => TRUE,
    );
  }
  return $form;
}

function enterprise_apps_config_form_validate($form, &$form_state) {

}

function enterprise_apps_config_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $config_info = $values['app_config_info'];
  //dsm($values);
  //dsm($config_info);

  $config_settings = array();

  if (isset($values['blocks']) && is_array($values['blocks'])) {
    $config_settings['blocks'] = array(
      'theme' => $values['blocks']['theme'],
    );
    foreach ($values['blocks'] AS $name => $block) {
      if (!is_array($block) || !isset($block['block'])) {
        continue;
      }
      $ci_name = $block['block']['config_info_name'];
      $config_settings['blocks'][$ci_name] = array(
        'region' => array($block['region']),
        'visibility_presets' => array(),
      );
      if (!empty($block['visibility_presets'])) {
        foreach ($block['visibility_presets'] AS $k => $v) {
          if ($v) {
            $config_settings['blocks'][$ci_name]['visibility_presets'][] = $k;
          }
        }
      }
    }
  }

  enterprise_apps_config_blocks($config_settings, $config_info);

}