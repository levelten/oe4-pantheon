<?php

/**
 * @file
 * template.php
 */

/**
 * Include common functions used through out theme.
 */
include_once dirname(__FILE__) . '/theme/common.inc';
include_once dirname(__FILE__) . '/theme/slider.inc';

/*
 * Implements hook_preprocess_html().
 */
function project_preprocess_html(&$vars) {
	$theme_path = drupal_get_path('theme', 'project');

  drupal_add_css($theme_path . '/lte-ie-8.css', array(
    'group' => CSS_THEME,
    'browsers' => array(
      'IE' => 'lte IE 8',
      '!IE' => FALSE
      ),
    'preprocess' => FALSE
  ));

  // Add plugin scripts.
  $plugin_path = $theme_path . '/plugins/';
  $plugins = array();

  // Animate.css
  $animate = theme_get_setting('animate');
  if ($animate > 0) {
    $plugins['animate']['options']['type'] = NULL;
    $plugins['animate']['type'] = 'css';
    switch ($animate) {
      case 1:
      $plugins['animate']['path'] = $plugin_path.'animate/animate.min.css';
      break;
      case 2:
      $plugins['animate']['path'] = $plugin_path.'animate/animate.css';
      break;
      case 3:
      $plugins['animate']['path'] = 'https://cdnjs.cloudflare.com/ajax/libs/animate.css/3.4.0/animate.min.css';
      $plugins['animate']['options']['type'] = 'external';
      break;
    }

    // Conditionally add Morphext based on Animate.
    if ($animate > 0) {
      $morphext = theme_get_setting('morphext');
      $plugins['morphext_js']['type'] = 'js';
      switch ($morphext) {
        case 1:
        $plugins['morphext_js']['path'] = $plugin_path.'morphext/morphext.min.js';
        break;
        case 2:
        $plugins['morphext_js']['path'] = $plugin_path.'morphext/morphext.js';
        break;
      }
      if ($morphext > 0) {
        $plugins['morphext_css']['path'] = $plugin_path.'morphext/morphext.css';
        $plugins['morphext_css']['type'] = 'css';
      }
    }
  }

  // Bootstrap Notify
  $bootstrap_notify = theme_get_setting('bootstrap_notify');
  if ($bootstrap_notify > 0) {
    $plugins['bootstrap_notify']['options']['type'] = NULL;
    $plugins['bootstrap_notify']['type'] = 'js';
    switch ($bootstrap_notify) {
      case 1:
      $plugins['bootstrap_notify']['path'] = $plugin_path.'bootstrap-notify/bootstrap-notify.min.js';
      break;
      case 2:
      $plugins['bootstrap_notify']['path'] = $plugin_path.'bootstrap-notify/bootstrap-notify.js';
      break;
    }
  }

  // Chart.js
  $chartjs = theme_get_setting('chartjs');
  if ($chartjs > 0) {
    $plugins['chartjs']['options']['type'] = NULL;
    $plugins['chartjs']['type'] = 'js';
    switch ($chartjs) {
      case 1:
      $plugins['chartjs']['path'] = $plugin_path.'charts/Chart.min.js';
      break;
      case 2:
      $plugins['chartjs']['path'] = $plugin_path.'charts/Chart.js';
      break;
      case 3:
      $plugins['chartjs']['path'] = 'https://cdnjs.cloudflare.com/ajax/libs/Chart.js/1.0.2/Chart.min.js';
      $plugins['chartjs']['options']['type'] = 'external';
      break;
    }
  }

  // Font Awesome
  $fontawesome = theme_get_setting('fontawesome');
  if ($fontawesome > 0) {
    $plugins['fontawesome']['options']['type'] = NULL;
    $plugins['fontawesome']['type'] = 'css';
    switch ($fontawesome) {
      case 1:
      $plugins['fontawesome']['path'] = $plugin_path.'font-awesome/css/font-awesome.min.css';
      break;
      case 2:
      $plugins['fontawesome']['path'] = $plugin_path.'font-awesome/css/font-awesome.css';
      break;
      case 3:
      $plugins['fontawesome']['path'] = 'https://maxcdn.bootstrapcdn.com/font-awesome/4.5.0/css/font-awesome.min.css';
      $plugins['fontawesome']['options']['type'] = 'external';
      break;
    }
  }

  // Hover.css
  $hover_css = theme_get_setting('hover_css');
  if ($hover_css > 0) {
    $plugins['hover_css']['options']['type'] = NULL;
    $plugins['hover_css']['type'] = 'css';
    switch ($hover_css) {
      case 1:
      $plugins['hover_css']['path'] = $plugin_path.'hover/hover-min.css';
      break;
      case 2:
      $plugins['hover_css']['path'] = $plugin_path.'hover.css';
      break;
      case 3:
      $plugins['hover_css']['path'] = 'https://cdnjs.cloudflare.com/ajax/libs/hover.css/2.0.2/css/hover-min.css';
      $plugins['hover_css']['options']['type'] = 'external';
      break;
    }
  }

  // Jasny Bootstrap CSS
  $jasny_css = theme_get_setting('jasny_css');
  if ($jasny_css > 0) {
    $plugins['jasny_css']['options']['type'] = NULL;
    $plugins['jasny_css']['type'] = 'css';
    switch ($jasny_css) {
      case 1:
      $plugins['jasny_css']['path'] = $plugin_path.'jasny-bootstrap/css/jasny-bootstrap.min.css';
      break;
      case 2:
      $plugins['jasny_css']['path'] = $plugin_path.'jasny-bootstrap/css/jasny-bootstrap.css';
      break;
      case 3:
      $plugins['jasny_css']['path'] = 'https://cdnjs.cloudflare.com/ajax/libs/jasny-bootstrap/3.1.3/css/jasny-bootstrap.min.css';
      $plugins['jasny_css']['options']['type'] = 'external';
      break;
    }
  }

  // Jasny Bootstrap JS
  $jasny_js = theme_get_setting('jasny_js');
  if ($jasny_js > 0) {
    $plugins['jasny_js']['options']['type'] = NULL;
    $plugins['jasny_js']['type'] = 'js';
    switch ($jasny_js) {
      case 1:
      $plugins['jasny_js']['path'] = $plugin_path.'jasny-bootstrap/js/jasny-bootstrap.min.js';
      break;
      case 2:
      $plugins['jasny_js']['path'] = $plugin_path.'jasny-bootstrap/js/jasny-bootstrap.js';
      break;
      case 3:
      $plugins['jasny_js']['path'] = 'https://cdnjs.cloudflare.com/ajax/libs/jasny-bootstrap/3.1.3/js/jasny-bootstrap.min.js';
      $plugins['jasny_js']['options']['type'] = 'external';
      break;
    }
  }

  // Maplace
  $maplace = theme_get_setting('maplace');
  if ($maplace > 0) {
    $plugins['maplace']['options']['type'] = NULL;
    $plugins['maplace']['type'] = 'js';
    switch ($maplace) {
      case 1:
      $plugins['maplace']['path'] = $plugin_path.'maplace/maplace.min.js';
      break;
      case 1:
      $plugins['maplace']['path'] = $plugin_path.'maplace/maplace.min.js';
      break;
      case 3:
      $plugins['maplace']['path'] = 'https://cdnjs.cloudflare.com/ajax/libs/maplace-js/0.2.5/maplace.min.js';
      $plugins['maplace']['options']['type'] = 'external';
      break;
    }

    // Google Maps API Key
    $gmap_api_key = theme_get_setting('gmap_api_key');
    if (!empty($gmap_api_key)) {
      $plugins['gmap']['type'] = 'js';
      $plugins['gmap']['path'] = 'https://maps.google.com/maps/api/js?sensor=false&libraries=geometry&v=3.22&key='.$gmap_api_key;
      $plugins['gmap']['options']['type'] = 'external';
      $plugins['gmap']['options']['weight'] = -100;
    } else {
      drupal_set_message(t('You do not have an API key set. If using Maplace, you need to obtain a Google Maps API key. For more info please go to !google website', array('!google' => l('Google Maps JavaScript API developers', 'https://developers.google.com/maps/documentation/javascript/get-api-key'))), 'status', FALSE);
    }
  }

  // Pace by Hubspot
  $pacejs = theme_get_setting('pacejs');
  if ($pacejs > 0) {
    $plugins['pacejs']['options']['type'] = NULL;
    $plugins['pacejs']['type'] = 'js';
    switch ($pacejs) {
      case 1:
      $plugins['pacejs']['path'] = $plugin_path.'pace/pace.min.js';
      break;
      case 1:
      $plugins['pacejs']['path'] = $plugin_path.'pace/pace.js';
      break;
      case 3:
      $plugins['pacejs']['path'] = 'https://cdnjs.cloudflare.com/ajax/libs/pace/1.0.2/pace.min.js';
      $plugins['pacejs']['options']['type'] = 'external';
      break;
    }
  }

  // Vide
  $vide = theme_get_setting('vide');
  if ($vide > 0) {
    $plugins['vide']['options']['type'] = NULL;
    $plugins['vide']['type'] = 'js';
    switch ($vide) {
      case 1:
      $plugins['vide']['path'] = $plugin_path.'vide/jquery.vide.min.js';
      break;
      case 2:
      $plugins['vide']['path'] = $plugin_path.'vide/jquery.vide.js';
      break;
    }
  }

  // Waypoints
  $waypoints = theme_get_setting('waypoints');
  if ($waypoints > 0) {
    $plugins['waypoints']['options']['type'] = NULL;
    $plugins['waypoints']['type'] = 'js';
    switch ($waypoints) {
      case 1:
      $plugins['waypoints']['path'] = $plugin_path.'waypoints/jquery.waypoints.min.js';
      break;
      case 2:
      $plugins['waypoints']['path'] = $plugin_path.'waypoints/jquery.waypoints.js';
      break;
      case 3:
      $plugins['waypoints']['path'] = 'https://cdnjs.cloudflare.com/ajax/libs/waypoints/4.0.0/noframework.waypoints.min.js';
      $plugins['waypoints']['options']['type'] = 'external';
      break;
    }
  }

  // Add all plugins.
  foreach ($plugins as $key => $value) {
    if (isset($value['path'])) {
      if ($value['type'] == 'js') {
        if (!empty($value['options']['external'])) {
          drupal_add_js($value['path'], $value['options']);
        } else {
          drupal_add_js($value['path']);
        }
      } else {
        if (!empty($value['options']['external'])) {
          drupal_add_css($value['path'], $value['options']);
        } else {
          drupal_add_css($value['path']);
        }
      }
    }
  }

  // Adding additional classes when necessary.
  // Transparent Navbar.
  if (theme_get_setting('navbar_transparent')) {
    $vars['classes_array'][] = 'transparent-header';
  }
  // Boxed layout.
  if (theme_get_setting('layout_style')) {
    $vars['classes_array'][] = 'boxed';
    if ($pattern = theme_get_setting("pattern")) {
     $vars['classes_array'][] = $pattern; 
    }
  }

}

/*
 * Implements hook_preprocess_page().
 */
function project_preprocess_page(&$vars) {

  // Sidebar objects
  $sidebar_first = (!empty($vars['page']['sidebar_first'])) ? $vars['page']['sidebar_first'] : NULL;
  $sidebar_second = (!empty($vars['page']['sidebar_second'])) ? $vars['page']['sidebar_second'] : NULL;

  $main_class = 'col-md-8';
  $sidebar_first_class = 'col-md-4 col-lg-3';
  $sidebar_second_class = 'col-md-4 col-lg-3';

  // Sidebar class logic.
  if (!empty($sidebar_first) && !empty($sidebar_second)) {
    // TWO SIDEBARS
    $main_class = 'col-md-6 col-md-push-3';
    $sidebar_first_class = 'col-md-3 col-md-pull-6';
    $sidebar_second_class = 'col-md-3';
  } elseif (!empty($sidebar_first) && empty($sidebar_second)) {
    // FIRST SIDEBAR
    $main_class = 'col-md-8 col-lg-offset-1 col-md-push-4 col-lg-push-3';
    $sidebar_first_class = 'col-md-4 col-lg-3 col-md-pull-8 col-lg-pull-9';
  } elseif (empty($sidebar_first) && !empty($sidebar_second)) {
    // SECOND SIDEBAR
    $main_class = 'col-md-8';
    $sidebar_second_class = 'col-md-4 col-lg-3 col-lg-offset-1';
  } else {
    $main_class = 'col-md-12';
  }

  $vars['main_class'] = $main_class;
  $vars['sidebar_first_class'] = $sidebar_first_class;
  $vars['sidebar_second_class'] = $sidebar_second_class;

  // Header Top
  $header_top = array();
  $header_top['class'][] = 'header-top';
  $header_top['class'][] = theme_get_setting('header_top_color');
  $vars['header_top_attr'] = $header_top;
  // Header Top Classes for Menu width
  $header_top_class = (theme_get_setting('header_top_class')) ? theme_get_setting('header_top_class') : 'small';
  if (!empty($header_top_class)) {
    switch ($header_top_class) {
      case 'small':
        $vars['header_top_class']['left']['class'][] = 'col-sm-6 col-md-9';
        $vars['header_top_class']['right']['class'][] = 'col-sm-6 col-md-3';
        break;
      case 'medium':
        $vars['header_top_class']['left']['class'][] = 'col-sm-6 col-md-8';
        $vars['header_top_class']['right']['class'][] = 'col-sm-6 col-md-4';
        break;
      case 'large':
        $vars['header_top_class']['left']['class'][] = 'col-sm-6 col-md-7';
        $vars['header_top_class']['right']['class'][] = 'col-sm-6 col-md-5';
        break;
      default:
        $vars['header_top_class']['left']['class'][] = 'col-sm-6 col-md-6';
        $vars['header_top_class']['right']['class'][] = 'col-sm-6 col-md-6';
        break;
    }
  }

  // Header
  $header = array();
  $header['class'][] = 'header';
  $header['class'][] = theme_get_setting('header_sticky');
  $header['class'][] = 'clearfix';
  $vars['header_attr'] = $header;

  // Navigation
  $navbar = array();
  $navbar['class'][] = 'main-navigation';

  // Navbar action classes.
  $navbar_actions = theme_get_setting('navbar_actions');
  foreach ($navbar_actions as $key => $value) {
    $navbar['class'][] = $key;
  }

  // Add search bar.
  $vars['toggle_search'] = theme_get_setting('toggle_search');
  if ($vars['toggle_search'] && module_exists('search')) {
    $search_form = drupal_get_form('search_form');
    $search_box = drupal_render($search_form);
    $vars['search_box'] = $search_box;
    $vars['search_icon'] = _project_icon('search');
    $navbar['class'][] = 'with-dropdown-buttons';
  }

  $vars['navbar_attr'] = $navbar;

  // Main Content
  $vars['page_title_separator'] = theme_get_setting('page_title_separator');


  // Footer
  $footer = array();
  $footer['class'][] = 'clearfix';
  $footer['class'][] = theme_get_setting('footer_dark');
  $vars['footer_attr'] = $footer;

  // Add Javscript settings from Project settings
  $settings = array();
  $settings['social_media_links'] = theme_get_setting('social_media_links');

  // Add settings to Drupal.settings
  drupal_add_js(array('project' => $settings),array('type' => 'setting'));

  // Add back to top arrow
  $vars['back_to_top'] = theme_get_setting('back_to_top');
}

/**
 * Implements hook_preprocess_maintenance_page().
 */
function project_preprocess_maintenance_page(&$vars) {
  project_preprocess_html($vars);
  project_preprocess_page($vars);

  // Inject regions.
  $regions = system_region_list('project');
  foreach ($regions as $key => $value) {
    $blocks = block_get_blocks_by_region($key);
    $vars['page'][$key] = $blocks;
  }

  // Add main menu.
  $main_menu = menu_tree('main-menu');
  $main_menu['#theme_wrappers'][] = 'project_menu_tree__main_menu';
  $vars['main_menu'] = $main_menu;

  // Add back Bootstrap.js
  $bootstrap_path = drupal_get_path('theme', 'enterprise_bootstrap');
  drupal_add_js($bootstrap_path . '/bootstrap/dist/js/bootstrap.js');

}

/**
 * Implements hook_preprocess_block()
 */
function project_preprocess_block(&$variables) {
  // Remove duplicate classes and empty classes
  $variables['classes_array'] = array_unique(array_diff($variables['classes_array'], array('')));
  // Add classes to blocks for front page containers.
  if (isset($variables['elements']['#block']->block_container) && $variables['elements']['#block']->block_container == 'content') {
    // Only add container class if it's the front page and NOT the main system block.
    if ($variables['is_front']) {
      $variables['theme_hook_suggestions'][] = 'block__container';
    }
  }
}

/*
 * Implements hook_css_alter().
 */
function project_css_alter(&$css) {
  // Explicitly remove Enterprise Bootstrap styling.
  foreach ($css as $key => $value) {
    if (strpos($value['data'], 'enterprise_bootstrap.less') !== FALSE) {
      unset($css[$key]);
    }
  }
}

/*
 * Implements theme_status_messages().
 */
function project_status_messages($variables) {
  $bootstrap_notify = theme_get_setting('bootstrap_notify');
  $display = $variables['display'];
  $statuses = array();
  $notify_message = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
    'info' => t('Informative message'),
  );

  // Map Drupal message types to their corresponding Bootstrap classes.
  // @see http://twitter.github.com/bootstrap/components.html#alerts
  $status_class = array(
    'status' => 'success',
    'error' => 'danger',
    'warning' => 'warning',
    'info' => 'info',
  );

  $status_icon = array(
    'status' => 'glyphicon glyphicon-ok-sign',
    'error' => 'glyphicon glyphicon-remove-sign',
    'warning' => 'glyphicon glyphicon-question-sign',
    'info' => 'glyphicon glyphicon-info-sign',
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    $output = '';
    $devel = 0;
    $class = (isset($status_class[$type])) ? ' alert-' . $status_class[$type] : '';
    $output .= "<div class=\"alert alert-block$class\">\n";
    $output .= "  <a class=\"close\" data-dismiss=\"alert\" href=\"#\">&times;</a>\n";

    // Set heading.
    if (!empty($status_heading[$type])) {
      $output .= '<h4 class="element-invisible">' . $status_heading[$type] . "</h4>\n";
    }

    // Grab all messages.
    if (count($messages) > 1) {
      $output .= " <ul>\n";
      $notify_message .= " <ul>\n";

      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
        $notify_message .= '  <li>' . $message . "</li>\n";
        $msg = substr($message, 0, 150);
        if (strpos($msg, 'Krumo') !== FALSE) {
          $devel = 1;
        }
      }

      $output .= " </ul>\n";
      $notify_message .= " </ul>\n";
    }
    else {
      $output .= $messages[0];
      $notify_message .= $messages[0];
      $msg = substr($messages[0], 0, 150);
      if (strpos($msg, 'Krumo') !== FALSE) {
        $devel = 1;
      }
    }

    $output .= "</div>\n";

    // Only process if Bootstrap Notify is enabled.
    $template = '<div data-notify="container" class="col-xs-11 col-sm-5 alert alert-{0}" role="alert"><button type="button" aria-hidden="true" class="close" data-notify="dismiss">&times;</button><span data-notify="icon" style="margin-right:5px;"></span><span data-notify="title">{1}</span><div class="well-sm" data-notify="message">{2}</div></div>';
    $notify_options = '{
      message:'.json_encode($notify_message).',
      title:'.json_encode($status_heading[$type]).',
      icon:'. json_encode($status_icon[$type]).',
    }';

    $notify_settings = '{
      type:"'.$status_class[$type].'",
      delay:10000,
      offset: {y:50,x:20},
      mouse_over: "pause",
      template:'.json_encode($template).',
    }';

    $statuses[] = array(
      'devel' => $devel,
      'standard' => $output,
      'notify' => array(
        'options' => $notify_options,
        'settings' => $notify_settings,
      ),
    );

  }

  // Normal output if not using Bootstrap Notify.
  $status_output = '';
  foreach ($statuses as $status) {
    if ($status['devel'] == 1) {
      $status_output .= $status['standard'];
      continue;
    } elseif ($bootstrap_notify) {
      drupal_add_js('jQuery.notify('.$status['notify']['options'].', '.$status['notify']['settings'].');',
        array('type' => 'inline', 'scope' => 'footer')
      );
      continue;
    } else {
      $status_output .= $status['standard'];
    }
  }

  return $status_output;
  
}

/**
 * Overrides theme_menu_local_action().
 */
function project_menu_local_action($variables) {
  $link = $variables['element']['#link'];

  $options = isset($link['localized_options']) ? $link['localized_options'] : array();

  // If the title is not HTML, sanitize it.
  if (empty($options['html'])) {
    $link['title'] = check_plain($link['title']);
  }

  $icon = _project_iconize_button($link['title']);

  // Format the action link.
  $output = '<li class="active alt">';
  if (isset($link['href'])) {
    // Turn link into a mini-button and colorize based on title.
    // if ($class = _project_colorize_button($link['title'])) {
    //   if (!isset($options['attributes']['class'])) {
    //     $options['attributes']['class'] = array();
    //   }
    //   $string = is_string($options['attributes']['class']);
    //   if ($string) {
    //     $options['attributes']['class'] = explode(' ', $options['attributes']['class']);
    //   }
    //   // $options['attributes']['class'][] = 'btn';
    //   // $options['attributes']['class'][] = 'btn-xs';
    //   // $options['attributes']['class'][] = $class;
    //   if ($string) {
    //     $options['attributes']['class'] = implode(' ', $options['attributes']['class']);
    //   }
    // }
    // Force HTML so we can add the icon rendering element.
    $options['html'] = TRUE;
    $output .= l($icon . $link['title'], $link['href'], $options);
  }
  else {
    $output .= $icon . $link['title'];
  }
  $output .= "</li>\n";

  return $output;
}

/**
 * Alter LESS include paths.
 *
 * @param &string[]  $less_paths
 * @param string     $system_name
 */
function project_less_paths_alter(array &$less_paths, $system_name) {
  $colorize = theme_get_setting('colorize');
  if ($colorize) {
    $less_paths[] = drupal_get_path('theme', 'project') . '/less/color.less';
  }
}

/**
 * Implements hook_menu_tree__MENU_ID
 */
function project_menu_tree__main_menu($variables) {
  return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}

/**
 * Implements hook_menu_link__MENU_ID
 */
function project_menu_link__main_menu(array $variables) {
  // Default Bootstrap menu
  $element = $variables['element'];
  $sub_menu = '';

  // We'll store a lot of info about this menu link in here.
  $menu_data = array(
    'mlid' => $element['#original_link']['mlid'],
    'theme_hook' => $variables['theme_hook_original'],
    'depth' => (!empty($element['#original_link']['depth'])) ? intval($element['#original_link']['depth']) : NULL,
    'expanded' => (!empty($element['#original_link']['expanded'])) ? $element['#original_link']['expanded'] : 0,
    'menu_block' => (is_array($element['#theme']) && in_array('menu_link__menu_block', $element['#theme'])) ? TRUE : FALSE,
    'dropdown' => theme_get_setting('enterprise_bootstrap_dropdown'),
    'mobile_dropdown' => theme_get_setting('enterprise_bootstrap_mobile_dropdown'),
    'hover_dropdown' => theme_get_setting('bootstrap_hover_dropdown'),
  );

  // Add class for when Icon Menu is being used.
  if (!empty($element['#localized_options']['icon']['icon'])) {
    $element['#attributes']['class'][] = 'has-icon';
  }
  // Add Menu link ID for specific styling cases.
  $element['#attributes']['class'][] = 'mlid-'.$element['#original_link']['mlid'];


  // Handle all other menus.
  if ($element['#below'] && $menu_data['expanded']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';

      // Generate as standard dropdown.
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      if (!empty($menu_data['dropdown'])) {
        $element['#localized_options']['attributes']['data-target'] = '#';
        $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
        $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';        
      } else {
        $element['#attributes']['class'][] = 'hover';
        $element['#localized_options']['attributes']['data-target'] = '#';
        $element['#localized_options']['attributes']['class'][] = 'dropdown-hover';
        $element['#localized_options']['attributes']['data-hover'] = 'dropdown';
      }
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
