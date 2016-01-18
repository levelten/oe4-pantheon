<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_process_page()
 */
function enterprise_bootstrap_process_page(&$variables) {

  // Set the proper attributes for the main menu. There should be a better
  // way of doing this but none of the menu process stuff runs early enough.
  if (isset($variables['page'])
    && isset($variables['page']['navigation'])
    && isset($variables['page']['navigation']['system_main-menu'])
    && is_array($variables['page']['navigation']['system_main-menu'])
    ) {
    enterprise_bootstrap_transform_main_menu($variables['page']['navigation']['system_main-menu']);
  }
  if (isset($variables['primary_nav']) && is_array($variables['primary_nav'])) {
    enterprise_bootstrap_transform_main_menu($variables['primary_nav']);
  }
}

/**
 * Set proper attributes for main menu
 */
function enterprise_bootstrap_transform_main_menu(&$menu_array) {
  foreach(element_children($menu_array) as $level1) {
    foreach(element_children($menu_array[$level1]['#below']) as $level2) {
      if (count($menu_array[$level1]['#below'][$level2]['#below'])) {
        $menu_array[$level1]['#below'][$level2]['#mega'] = TRUE;
      } else {
        $menu_array[$level1]['#below'][$level2]['#mega'] = FALSE;
      }
    }
  }
}

/**
 * Implements hook_preprocess_html()
 */
function enterprise_bootstrap_preprocess_html(&$variables) {
  // Add dark class to theme if enabled.
  $theme_dark = theme_get_setting('eb_dark_theme');
  if ($theme_dark) {
    $variables['classes_array'][] = 'theme-dark';
  }
}

/**
 * Implements hook_preprocess_page()
 */
function enterprise_bootstrap_preprocess_page(&$variables) {
  // Variables
  $theme_path = drupal_get_path('theme', 'enterprise_bootstrap');

  // Preprocess blocks on home page for striping.
  if (module_exists('block_class')) {
    $front_blocks = $variables['page']['content'];
    foreach ($front_blocks as $key => $value) {
      if (is_array($front_blocks[$key]) && isset($front_blocks[$key]['#block'])) {
        // Add region to block vars (we only care about content)
        $front_blocks[$key]['#block']->block_container = 'content';
      }
    }
  }

  // Apply image styles to logo.
  $logo_path = theme_get_setting('logo_path');
  $logo_image_style = theme_get_setting('logo_image_style');

  // Change out logo with image style version.
  if (isset($logo_image_style) && isset($logo_path) && !empty($logo_image_style)) {
    if ($logo_image_style !== 'default') {
      $variables['logo'] = image_style_url($logo_image_style, $logo_path);
    }
  }

  // Add information about the number of sidebars.
  if (theme_get_setting('enterprise_bootstrap_sidebar_column') != 1) {
    $variables['sidebar_column_class'] = 'col-sm-3';
    $sidebar_column_width = TRUE;
  } else {
    $variables['sidebar_column_class'] = 'col-sm-4';
    $sidebar_column_width = FALSE;
  }

  // Set sidebar columns.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ($sidebar_column_width) ? ' class="col-sm-6"' : ' class="col-sm-4"';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ($sidebar_column_width) ? '  class="col-sm-9"' : ' class="col-sm-8"';
  }
  else {
    $variables['content_column_class'] = ' class = "col-sm-12"';
  }

  /*
   * Enterprise Header settings
   */
  $variables['navbar_header_display'] = theme_get_setting('navbar_header_display');
  if (empty($variables['navbar_header_display'])) {
    $variables['navbar_header_display'] = 'standard';
  }
  if ($variables['navbar_header_display'] == 'none') {
    $variables['navbar_header_display'] = '';
    $variables['navbar_classes_array'][] = 'navbar-no-header';
  }

  /*
   * Enterprise Megamenu settings
   */
  $enterprise_megamenu = theme_get_setting('enterprise_bootstrap_megamenu');
  $variables['navbar_region_class'] = '';
  $variables['nav_logo_class'] = array();
  $variables['nav_menu_class'] = array();

  switch ($enterprise_megamenu) {
    case 'bootstrap':
      $variables['nav_mega_menu'] = 'default-bootstrap';
      break;
    case 'enterprise':
      $variables['nav_mega_menu'] = 'enterprise-megamenu';
      break;
    case 'yamm':
      $variables['nav_mega_menu'] = 'yamm';
      break;

    default:
      $variables['nav_mega_menu'] = 'default-bootstrap';
      break;
  }

  // Set Navbar container classes for Enterprise Megamenu
  if ($enterprise_megamenu == 'enterprise') {
    $nav_wrapper = theme_get_setting('nav_wrapper');
    $variables['nav_wrapper'] = ($nav_wrapper) ? $nav_wrapper : 'container-fluid';
    $variables['nav_inner'] = ($nav_inner = theme_get_setting('nav_inner')) ? $nav_inner : 'container';
    $variables['navbar_region_class'] .= '';
    // Fix navbar wrapper/inner conflict. If the wrapper is container, the inner will always be fluid.
    if ($nav_wrapper == 'container') {
      $variables['nav_inner'] = 'container-fluid';
    }
  } else {
    $variables['nav_wrapper'] = '';
    $variables['nav_inner'] = 'navbar-mega-menu';
  }

  // Navbar attributes
  $s = theme_get_setting('navbar_class');
  if (!empty($s)) {
    $s = explode(' ', $s);
    $variables['navbar_classes_array'] = array_merge($variables['navbar_classes_array'], $s);
  }

  // Navigation region settings.
  $variables['navbar_region_class'] .= theme_get_setting('navbar_region_class');

  // Hide caret.
  if (theme_get_setting('enterprise_bootstrap_hide_caret')) {
    $variables['navbar_region_class'] .= ' hide-caret';
  }

  // Add nav_logo classes from theme settings.
  $variables['nav_logo_class']['class'][] = 'navbar-header';
  $nav_logo_class = explode(' ', trim(theme_get_setting('nav_logo_class')));
  foreach ($nav_logo_class as $value) {
    $variables['nav_logo_class']['class'][] = $value;
  }
  // Clean out duplicate classes.
  array_unique($variables['nav_logo_class']['class']);

  // Building attributes for Nav Menu (wrapper around ul.nav)
  $variables['nav_menu_class']['class'][] = $enterprise_megamenu;
  $nav_menu_class = explode(' ', trim(theme_get_setting('nav_menu_class')));
  foreach ($nav_menu_class as $value) {
    $variables['nav_menu_class']['class'][] = $value;
  }
  // Clean out duplicate classes.
  array_unique($variables['nav_menu_class']['class']);

  // Title region settings.
  $variables['title_placement'] = theme_get_setting('title_placement');
  $variables['title_container'] = theme_get_setting('title_container');
  $variables['title_row'] = ($variables['title_container'] == 'container') ? 'row' : '';
  $variables['title_class'] = theme_get_setting('title_class');

  // Highlighted region settings.
  $variables['highlighted_container_front'] = theme_get_setting('highlighted_container_front');
  $variables['highlighted_placement'] = theme_get_setting('highlighted_placement');
  $variables['highlighted_container'] = theme_get_setting('highlighted_container');
  $variables['highlighted_row'] = ($variables['highlighted_container']) ? '' : 'row';
  $variables['highlighted_class'] = theme_get_setting('highlighted_class');

  // Header region settings.
  $variables['header_container_front'] = theme_get_setting('header_container_front');
  $variables['header_container'] = theme_get_setting('header_container');
  $variables['header_row'] = ($variables['header_container']) ? '' : 'row';
  $variables['header_class'] = theme_get_setting('header_class');

  // Footer region settings.
  $variables['footer_container'] = theme_get_setting('footer_container');
  $variables['footer_class'] = theme_get_setting('footer_class');

  // Make blocks full width on front page.
  // @todo: look into switching page template based on path.
  $variables['full_width_front'] = theme_get_setting('enterprise_bootstrap_front_container');
  $variables['full_width_container'] = ($variables['full_width_front']) ? 'wide' : 'container';
  $variables['full_width_anti_container'] = ($variables['full_width_container'] == 'wide') ? 'container' : 'wide';
  $variables['sidebars_front'] = theme_get_setting('enterprise_bootstrap_sidebars_front');

  // If we don't want sidebars on the front page, unset them.
  if (!$variables['sidebars_front'] && drupal_is_front_page()) {
    unset($variables['page']['sidebar_first']);
    unset($variables['page']['sidebar_second']);
  }

  /*
   * Zebra Striping for Front Page Blocks
   */
  $block_striping = theme_get_setting('enterprise_bootstrap_block_striping');
  if (isset($variables['page']['content']) && drupal_is_front_page() && isset($block_striping) && $block_striping) {
    // Get the blocks in the content area.
    $children = element_children($variables['page']['content']);
    $count = (count($children));

    // List of blocks that shouldn't be included in striping, add additional blocks here.
    // Examples include metatags or workbench.
    $stripe_exlude = array(
      'metatags',
      'workbench_block',
    );
    // Remove excluded from count.
    $count = $count - count($stripe_exlude);
    // Add zebra classes to blocks.
    foreach ($variables['page']['content'] as $key => $value) {
      // Skip the excluded blocks.
      if (in_array($key, $stripe_exlude)) {
        continue;
      }
      // Determine striping class.
      $zebra_class = ($count % 2 == 0) ? 'block-row-even' : 'block-row-odd';
      if (!empty($value['#block']) && $value['#block'] && isset($value['#block']->css_class)) {
        $existing_class = $variables['page']['content'][$key]['#block']->css_class;
        $variables['page']['content'][$key]['#block']->css_class = $existing_class . ' ' . $zebra_class;
        $count--;
      } /*else {
        $variables['page']['content'][$key]['classes_array'][] = $zebra_class;
        $count--;
      }*/
    }
  }

  // Add Javscript files and settings from Enterprise Bootstrap settings
  // Mega Menu and mobile menu settings.
  $settings = array();
  $settings['megamenu'] = theme_get_setting('enterprise_bootstrap_megamenu');
  $settings['mobilemenu'] = theme_get_setting('enterprise_bootstrap_mobile_dropdown');
  $settings['mobilemenuhoverpush'] = theme_get_setting('enterprise_bootstrap_mobile_menu_hover_push');
  $settings['mobilemenuhoverpushwidth'] = theme_get_setting('enterprise_bootstrap_mobile_menu_hover_push_width');
  $settings['fittext'] = theme_get_setting('fittext_selector');
  $settings['sticky_menu'] = theme_get_setting('sticky_menu');

  // Process FitText selectors
  $selectors = array();
  if (!empty($settings['fittext'])) {
    $selector = explode("\n", $settings['fittext']);
    foreach ($selector as $value) {
      $selectors[] = explode('|', $value);
    }
    $settings['fittext'] = $selectors;
  }

  // Add settings to Drupal.settings
  drupal_add_js(array('enterprise_bootstrap' => $settings),array('type' => 'setting'));

  // fitText.js
  $fittext = theme_get_setting('fittext');
  if (!empty($fittext)) {
    switch ($fittext) {
      case 1:
      drupal_add_js('//cdnjs.cloudflare.com/ajax/libs/FitText.js/1.1/jquery.fittext.min.js', 'external');
      break;
      case 2:
      drupal_add_js('//cdnjs.cloudflare.com/ajax/libs/FitText.js/1.1/jquery.fittext.js', 'external');
      break;
      default:
        # Do nothing.
      break;
    }
  }
  // bootstrap-hover-dropdown
  $menu_data['hover_dropdown'] = theme_get_setting('bootstrap_hover_dropdown');
  if (!empty($menu_data['hover_dropdown'])) {
    switch ($menu_data['hover_dropdown']) {
      case 1:
      drupal_add_js('//cdnjs.cloudflare.com/ajax/libs/bootstrap-hover-dropdown/2.0.10/bootstrap-hover-dropdown.min.js', 'external');
      break;
      case 2:
      drupal_add_js('//cdnjs.cloudflare.com/ajax/libs/bootstrap-hover-dropdown/2.0.10/bootstrap-hover-dropdown.js', 'external');
      break;
      default:
        # Do nothing.
      break;
    }
  }
  // Responsive Tabs
  $responsive_tabs = theme_get_setting('responsive_tabs');
  if (!empty($responsive_tabs)) {
    switch ($responsive_tabs) {
      case 1:
      drupal_add_js($theme_path  . '/js/responsivetabs/jquery.responsiveTabs.min.js');
      drupal_add_css($theme_path . '/css/responsive-tabs.css');
      break;
      case 2:
      drupal_add_js($theme_path  . '/js/responsivetabs/jquery.responsiveTabs.js');
      drupal_add_css($theme_path . '/css/responsive-tabs.css');
      break;
      default:
        # Do nothing.
      break;
    }
  }

  // Gridline
  $gridline = theme_get_setting('gridline');
  if (!empty($gridline)) {
    switch ($gridline) {
      case 1:
      drupal_add_js($theme_path  . '/js/gridline/gridline.min.js');
      break;
      case 2:
      drupal_add_js($theme_path  . '/js/gridline/gridline.js');
      break;
      default:
        # Do nothing.
      break;
    }
  }

  // equalize.js
  // $equalize = theme_get_setting('equalize');
  // if (!empty($equalize)) {
  //   if ($equalize == 1) {
  //     drupal_add_js('//cdnjs.cloudflare.com/ajax/libs/equalize.js/1.0.1/equalize.min.js', 'external');
  //   }
  // }

  // Add Bootstrap Javascript libraries
  $bootstrap_js = theme_get_setting('enterprise_bootstrap_js_options');
  if(!empty($bootstrap_js)) {
    $bootstrap_js = array_filter($bootstrap_js);
    $js_path = drupal_get_path('theme', 'enterprise_bootstrap').'/bootstrap/js/';
    $options = array(
      'group' => JS_THEME,
      'every_page' => TRUE,
      'preprocess' => TRUE,
      );
    foreach ($bootstrap_js as $key => $value) {
      drupal_add_js($js_path.$key.'.js', $options);
    }
  }
}

/**
 * Implements hook_preprocess_block()
 */
function enterprise_bootstrap_preprocess_block(&$variables) {
  // Remove duplicate classes and empty classes
  $variables['classes_array'] = array_unique(array_diff($variables['classes_array'], array('')));
  // Add classes to blocks for front page containers.
  if (isset($variables['elements']['#block']->block_container) && $variables['elements']['#block']->block_container == 'content') {
    // Only add container class if it's the front page and NOT the main system block.
    $block_container = theme_get_setting('enterprise_bootstrap_front_container');
    if ($variables['is_front'] && $block_container) {
      $variables['theme_hook_suggestions'][] = 'block__container';
    }
  }
}

/**
 * Returns HTML for a list of maintenance tasks to perform.
 *
 * @param $variables
 *   An associative array containing:
 *   - items: An associative array of maintenance tasks.
 *   - active: The key for the currently active maintenance task.
 *
 * @ingroup themeable
 */
function enterprise_bootstrap_task_list($variables) {
  $items = $variables['items'];
  $active = $variables['active'];

  $done = isset($items[$active]) || $active == NULL;
  $output = '<h2 class="element-invisible">Installation tasks</h2>';
  $output .= '<ol class="task-list">';

  foreach ($items as $k => $item) {
    $icon = '<i class="glyphicon glyphicon-minus"></i>';
//    $class = 'glyphicon glyphicon-minus';
    if ($active == $k) {
      $class = 'active';
      $status = '(' . t('active') . ')';
      $icon = '<i class="glyphicon glyphicon-refresh"></i>';
      $done = FALSE;
    }
    else {
      $class = $done ? 'done' : '';
      $status = $done ? '(' . t('done') . ')' : '';
      if ($done) {
        $icon = '<i class="glyphicon glyphicon-ok"></i>';
      }
    }
    $output .= '<li';
    $output .= ($class ? ' class="' . $class . '"' : '') . '>';
    $output .= $icon;
    $output .= $item;
    $output .= ($status ? '<span class="element-invisible">' . $status . '</span>' : '');
    $output .= '</li>';
  }
  $output .= '</ol>';
  return $output;
}

/**
 * Overrides theme_menu_local_action().
 */
function enterprise_bootstrap_menu_local_action($variables) {
  $link = $variables['element']['#link'];

  $options = isset($link['localized_options']) ? $link['localized_options'] : array();

  // If the title is not HTML, sanitize it.
  if (empty($options['html'])) {
    $link['title'] = check_plain($link['title']);
  }

  $icon = _bootstrap_iconize_button($link['title']);

  // Format the action link.
  $output = '<li>';
  if (isset($link['href'])) {
    // Turn link into a mini-button and colorize.
    if (!isset($options['attributes']['class'])) {
      $options['attributes']['class'] = array();
    }
    $string = is_string($options['attributes']['class']);
    if ($string) {
      $options['attributes']['class'] = explode(' ', $options['attributes']['class']);
    }
    $options['attributes']['class'][] = 'btn';
    $options['attributes']['class'][] = 'btn-sm';
    $options['attributes']['class'][] = 'btn-primary';
    if ($string) {
      $options['attributes']['class'] = implode(' ', $options['attributes']['class']);
    }
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
 * Implements hook_theme_registry_alter().
 */
function enterprise_bootstrap_theme_registry_alter(&$theme_registry) {
  array_unshift($theme_registry['menu_tree']['preprocess functions'], 'enterprise_bootstrap_menu_tree_alter');
}

/**
 * Helper function for adding the tree context to the variables.
 *
 * A faux "hook_menu_tree_alter()" if you will.
 */
function enterprise_bootstrap_menu_tree_alter(&$variables) {
  // Save the original tree render array so it can be
  // used in future theme preprocessors.
  $variables['#tree'] = $variables['tree'];
}

/**
 * Bootstrap theme wrapper function for the primary menu links.
 */
function enterprise_bootstrap_menu_tree__main_menu(&$variables) {
  return _enterprise_bootstrap_menu_wrapper($variables);
}
function enterprise_bootstrap_menu_tree__primary_nav(&$variables) {
  return _enterprise_bootstrap_menu_wrapper($variables);
}

/*
 * Implements theme_menu_link__main_menu().
 */
function enterprise_bootstrap_menu_link__main_menu($variables) {
  // Default Bootstrap menu
  $element = $variables['element'];
  $sub_menu = '';

  // We'll store a lot of info about this menu link in here.
  $menu_data = array(
    'title' => $element['#original_link']['link_title'],
    'mlid' => $element['#original_link']['mlid'],
    'theme_hook' => $variables['theme_hook_original'],
    'depth' => (!empty($element['#original_link']['depth'])) ? intval($element['#original_link']['depth']) : NULL,
    'expanded' => (!empty($element['#original_link']['expanded'])) ? $element['#original_link']['expanded'] : 0,
    'enterprise_mega' => theme_get_setting('enterprise_bootstrap_megamenu'),
    'mega' => (!empty($element['#mega'])) ? $element['#mega'] : FALSE,
    'mega_block' => (!empty($element['#localized_options']['mega_block']['name'])) ? $element['#localized_options']['mega_block']['name'] : NULL,
    'menu_block' => (is_array($element['#theme']) && in_array('menu_link__menu_block', $element['#theme'])) ? TRUE : FALSE,
    'mega_columns' => theme_get_setting('enterprise_bootstrap_mega_columns'),
    'dropdown' => theme_get_setting('enterprise_bootstrap_dropdown'),
    'mobile_dropdown' => theme_get_setting('enterprise_bootstrap_mobile_dropdown'),
    'hover_dropdown' => theme_get_setting('bootstrap_hover_dropdown'),
    'disable_icon_menu_block' => (!empty($element['#localized_options']['disable_icon_menu_block']) && $element['#localized_options']['disable_icon_menu_block']) ? TRUE : FALSE,
  );

  // Add class for when Icon Menu is being used.
  if (!empty($element['#localized_options']['icon']['icon'])) {
    $element['#attributes']['class'][] = 'has-icon';
  }
  // Add Menu link ID for specific styling cases.
  $element['#attributes']['class'][] = 'mlid-'.$element['#original_link']['mlid'];

  // Set up Mega Menu classes.
  switch ($menu_data['mega_columns']) {
    case 'col-md-6':
    case 'col-md-4':
    case 'col-md-3':
    case 'col-md-2':
      // Use Bootstrap classes
      $menu_data['mega_item_class'] = $menu_data['mega_columns'];
      $menu_data['mega_wrapper_class'] = 'row';
      break;

    case 'col-table':
      // Use display:table-cell hack
      $menu_data['mega_item_class'] = 'mega-table-cell';
      $menu_data['mega_wrapper_class'] = 'mega-table-wrapper';
      break;

    case 'col-md-12':
    case 'col-custom':
      // Provide blank classes for mega menu
      $menu_data['mega_item_class'] = 'mega-custom-item';
      $menu_data['mega_wrapper_class'] = 'mega-custom-wrapper';
      break;

    default:
      // By default, just make it 4 columns.
      $menu_data['mega_item_class'] = 'col-md-3';
      $menu_data['mega_wrapper_class'] = '';
      break;
  }

  // Last chance to turn into a mega menu via Enterprise Extras option.
  // But only do that if it's the main menu.
  if (!empty($element['#original_link']['options']['enterprise_mega']) && $element['#original_link']['options']['enterprise_mega']) {
    $menu_data['mega'] = TRUE;
  }

  // If we're using default Bootstrap, just run that first.
  if ($menu_data['enterprise_mega'] == 'bootstrap') {
    if ($element['#below']) {
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
        if (!$menu_data['dropdown']) {
          $element['#attributes']['class'][] = 'hover';
          $element['#localized_options']['attributes']['data-target'] = '#';
          $element['#localized_options']['attributes']['class'][] = 'dropdown-hover';
          $element['#localized_options']['attributes']['data-hover'] = 'dropdown';
        } else {
          $element['#title'] .= ' <span class="caret"></span>';
          $element['#localized_options']['attributes']['data-target'] = '#';
          $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
          $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
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
  } else {

    if ($menu_data['depth'] == 2 && $menu_data['mega']) {
      $output = array();

      if (in_array('first', $element['#attributes']['class'])) {
        if ($menu_data['enterprise_mega'] == 'yamm') {
          $output[] = '<li class="yamm-content">';
        } else {
          $output[] = '<div class="'.$menu_data['mega_wrapper_class'].'">';
        }
      }

      // Add conditions for Mega Block.
      if (!empty($menu_data['mega_block'])) {
        $mega_block_pieces = explode('|', $menu_data['mega_block']);
        $menu_data['mega_item_class'] .= ' mega-block mega-block-' . $mega_block_pieces[1];
      }

      // Append classes if Mega Block is being used.
      switch ($element['#href']) {
        case '<block>':
          $output[] = '<div class="'.$menu_data['mega_item_class'].'"><ul class="mega-sub-menu">';
          $output[] = '<li' . drupal_attributes($element['#attributes']) . '>';
          $output[] = l($element['#title'], $element['#href'], $element['#localized_options']);
          break;
        default:
          // Add standard mega menu classes, add <strong> if link is the top link.
          $output[] = '<div class="'.$menu_data['mega_item_class'].'"><ul class="mega-sub-menu list-unstyled">';
          $output[] = '<li' . drupal_attributes($element['#attributes']) . '>';
          $output[] = '<strong>'.l($element['#title'], $element['#href'], $element['#localized_options']).'</strong>';
          break;
      }

      // Render children (sub-menu)
      if ($element['#below'] && $menu_data['expanded']) {
        unset($element['#below']['#theme_wrappers']);
        $output[] = drupal_render($element['#below']);
      }
      $output[] = '</ul></div>';

      if (in_array('last', $element['#attributes']['class'])) {
        if ($menu_data['enterprise_mega'] == 'yamm') {
          $output[] = '</li>';
        } else {
          $output[] = '</div>';
        }
      }
      return implode("\n", $output);
    }

    if ($element['#below'] && $menu_data['expanded']) {

      if ($menu_data['depth'] == 1) {
        // Add class if child isn't a mega menu.
        $mega_class = '';
        foreach ($element['#below'] as $key => $value) {
          if (!empty($value['#mega']) && $value['#mega'] == FALSE) {
            $mega_class = 'non-mega';
            break;
          }
        }

        // Add our own wrapper.
        unset($element['#below']['#theme_wrappers']);
        if ($menu_data['enterprise_mega'] == 'yamm') {
          $element['#attributes']['class'][] = 'yamm-fw';
          $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
        } else {
          $sub_menu = '<ul class="dropdown-menu"><div class="'.$mega_class.'">' . drupal_render($element['#below']) . '</div></ul>';
        }

        // Generate as standard dropdown.
        $element['#attributes']['class'][] = 'dropdown';
        $element['#attributes']['class'][] = 'mega-menu';
        $element['#localized_options']['html'] = TRUE;

        // Set dropdown trigger element to # to prevent inadvertant page loading
        // when a submenu link is clicked.
        if (!$menu_data['dropdown']) {
          $element['#attributes']['class'][] = 'hover';
          $element['#localized_options']['attributes']['data-target'] = '#';
          $element['#localized_options']['attributes']['class'][] = 'dropdown-hover';
          $element['#localized_options']['attributes']['data-hover'] = 'dropdown';
        } else {
          $element['#title'] .= ' <span class="caret"></span>';
          $element['#localized_options']['attributes']['data-target'] = '#';
          $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
          $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
        }
      } else {
        unset($element['#below']['#theme_wrappers']);
        $sub_menu = '<ul>' . drupal_render($element['#below']) . '</ul>';
      }

      // On primary navigation menu, class 'active' is not set on active menu item.
      // @see https://drupal.org/node/1896674
      if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
        $element['#attributes']['class'][] = 'active';
      }
      $output = l($element['#title'], $element['#href'], $element['#localized_options']);
      return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
    }
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
        if (!$menu_data['dropdown']) {
          $element['#attributes']['class'][] = 'hover';
          $element['#localized_options']['attributes']['data-target'] = '#';
          $element['#localized_options']['attributes']['class'][] = 'dropdown-hover';
          $element['#localized_options']['attributes']['data-hover'] = 'dropdown';
        } else {
          $element['#title'] .= ' <span class="caret"></span>';
          $element['#localized_options']['attributes']['data-target'] = '#';
          $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
          $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
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
}

/*
 * Implements theme_menu_link__main_block().
 */
function enterprise_bootstrap_menu_link__menu_block(array $variables) {
  // Stick to default theming.
  return theme_menu_link($variables);
}

/**
 * Overrides theme_menu_link().
 */
function enterprise_bootstrap_menu_link(array $variables) {
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
      if ($menu_data['dropdown']) {
        $element['#attributes']['class'][] = 'hover';
          $element['#localized_options']['attributes']['data-target'] = '#';
          $element['#localized_options']['attributes']['class'][] = 'dropdown-hover';
          $element['#localized_options']['attributes']['data-hover'] = 'dropdown';
        } else {
          $element['#title'] .= ' <span class="caret"></span>';
          $element['#localized_options']['attributes']['data-target'] = '#';
          $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
          $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
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

/*
 * Helper function to determine which wrapper to add to the main menu.
 */
function _enterprise_bootstrap_menu_wrapper($variables) {
  $enterprise_mega = theme_get_setting('enterprise_bootstrap_megamenu');
  // Enterprise Megamenu options
  // 'bootstrap' => t('Bootstrap Default'),
  // 'enterprise' => t('Enterprise Mega Menu'),
  // 'yamm' => t('YAMM'),

  // Extract additional data.
  if (!empty($variables['#tree'])) {
    foreach ($variables['#tree'] as $element) {
      if (is_array($element)) {
        // Check if link is part of menu block.
        if ((!empty($element['#theme']) && is_array($element['#theme'])) && (in_array('menu_link__menu_block', $element['#theme']) || in_array('menu_link', $element['#theme']))) {
          return '<ul class="menu nav">' . $variables['tree'] . '</ul>';
        }
      }
    }
    switch ($enterprise_mega) {
      case 'default':
        return '<div class="default-bootstrap"><ul class="menu nav">' . $variables['tree'] . '</ul></div>';
        break;

      case 'enterprise':
        return '<div class="mega-content"><ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul></div>';
        break;

      case 'yamm':
        return '<ul class="menu nav navbar-nav yamm">' . $variables['tree'] . '</ul>';
        break;

      case 'bootstrap':
      default:
        return '<div class="default-bootstrap"><ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul></div>';
        break;
    }
  }
}
