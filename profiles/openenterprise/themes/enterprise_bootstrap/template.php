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
    $mega = FALSE;
    foreach(element_children($menu_array[$level1]['#below']) as $level2) {
      if (count($menu_array[$level1]['#below'][$level2]['#below'])) {
        $mega = TRUE;
        continue;
      }
      $primary_nav = &$variables['primary_nav'];
    }
    foreach(element_children($menu_array[$level1]['#below']) as $level2) {
      $menu_array[$level1]['#below'][$level2]['#mega'] = $mega;
    }
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

  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ($sidebar_column_width) ? ' class="col-sm-6"' : ' class="col-sm-4"';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ($sidebar_column_width) ? '  class="col-sm-9"' : ' class="col-sm-8"';
  }
  else {
    $variables['content_column_class'] = 'col-sm-12';
  }

  // Navigation region settings.
  $variables['navbar_region_class'] = theme_get_setting('navbar_region_class');
  $variables['nav_logo_class'] = theme_get_setting('nav_logo_class');
  $variables['nav_menu_class'] = theme_get_setting('nav_menu_class');
  
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

  // Option to use Blokk font.
  if(theme_get_setting('enterprise_bootstrap_blokkfont')) {
    $blokk_path = $theme_path .'/fonts/blokkneue/blokkneue.css';
    $options = array(
      'group' => CSS_THEME,
      'every_page' => TRUE,
      'weight' => -1,
      'preprocess' => TRUE,
      );
    drupal_add_css($blokk_path, $options);
  }

  // Add Javscript files and settings from Enterprise Bootstrap settings
  // Mega Menu and mobile menu settings.
  $settings = array();
  $settings['megamenu'] = theme_get_setting('enterprise_bootstrap_megamenu');
  $settings['mobilemenu'] = theme_get_setting('enterprise_bootstrap_mobile_dropdown');
  $settings['mobilemenuhoverpush'] = theme_get_setting('enterprise_bootstrap_mobile_menu_hover_push');
  $settings['fittext'] = theme_get_setting('fittext_selector');
  
  // Process FitText selectors
  $selectors = array();
  if (!empty($settings['fittext'])) {
    $selector = explode("\n", $settings['fittext']);
    foreach ($selector as $value) {
      $selectors[] = explode('|', $value);
    }
    $settings['fittext'] = $selectors;
  }

  drupal_add_js(
    array(
      'enterprise_bootstrap' => $settings,
      ),
    array(
      'type' => 'setting',
      )
    );

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
  $hover_dropdown = theme_get_setting('bootstrap_hover_dropdown');
  if (!empty($hover_dropdown)) {
    switch ($hover_dropdown) {
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
 * Bootstrap theme wrapper function for the primary menu links.
 */
function enterprise_bootstrap_menu_tree__main_menu(&$variables) {
  $enterprise_mega = theme_get_setting('enterprise_bootstrap_megamenu');
  if ($enterprise_mega) {
    return '<div class="mega"><ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul></div>';
  } else {
    return '<div class="default-bootstrap"><ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul></div>';
  }
}

/**
 * Overrides theme_menu_link().
 */
function enterprise_bootstrap_menu_link(array $variables) {
  $enterprise_mega = theme_get_setting('enterprise_bootstrap_megamenu');
  $mobile_dropdown = theme_get_setting('enterprise_bootstrap_mobile_dropdown');
  
  if (!$enterprise_mega) {
    // Default Bootstrap menu
    $element = $variables['element'];
    $sub_menu = '';

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
        $element['#title'] .= ' <span class="caret"></span>';
        $element['#attributes']['class'][] = 'dropdown';
        $element['#localized_options']['html'] = TRUE;

        if ($mobile_dropdown) {
          // Set dropdown trigger element to # to prevent inadvertant page loading
          // when a submenu link is clicked.
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
  } // end default Bootstrap

  $element = $variables['element'];
  $sub_menu = '';

  if ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 2 && isset($element['#mega']) && $element['#mega'])) {
    $output = '';
    if (in_array('first', $element['#attributes']['class'])) {
      $output .= '<li><div class="mega-content"><div class="row">';
    }
    // Add conditions for when using Mega Block
    $mega_block_class = '';
    if (isset($element['#localized_options']['mega_block']['name']) && !empty($element['#localized_options']['mega_block']['name'])) {
      $mega_block_pieces = explode('|', $element['#localized_options']['mega_block']['name']);
      $mega_block_class = $mega_block_pieces[1];
    }
    $output .= ($element['#href'] !== '<block>') ? '<ul class="col-sm-3 list-unstyled">' : '<ul class="col-sm-3 list-unstyled mega-block mega-block-'.$mega_block_class.'">';
    $output .= '<li' . drupal_attributes($element['#attributes']) . '>';
    $output .= ($element['#href'] !== '<block>') ? '<p><strong>' . l($element['#title'], $element['#href'], $element['#localized_options']) . '</strong></p>' : l($element['#title'], $element['#href'], $element['#localized_options']);
    $output .= "</li>\n";
    if ($element['#below']) {
      unset($element['#below']['#theme_wrappers']);
      $output .= drupal_render($element['#below']);
    }
    $output .= '</ul>';
    if (in_array('last', $element['#attributes']['class'])) {
      $output .= '</div></div></li>';
    }
    return $output;
  }

  if ($element['#below']) {
    if ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // See if the children of this link is a mega menu or not.
      // The values don't make sense. Just go with it.
      $non_mega = TRUE;
      foreach ($element['#below'] as $key => $value) {
        if (isset($value['#mega']) && $value['#mega'] == TRUE) {
          $non_mega = FALSE;
          break;
        }
      }
      $non_mega_class = ($non_mega) ? 'non-mega' : '';

      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu"><div class="container '.$non_mega_class.'">' . drupal_render($element['#below']) . '</div></ul>';

      // Generate as standard dropdown.
      $element['#title'] .= ' <span class="caret"></span>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      $element['#localized_options']['attributes']['data-target'] = '#';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-hover'] = 'dropdown';
    }
    else {
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul>' . drupal_render($element['#below']) . '</ul>';
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
