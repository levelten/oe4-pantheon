<?php

/**
 * @file
 * template.php
 */

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
}

/*
 * Implements hook_preprocess_page().
 */
function project_preprocess_page(&$vars) {

  // Sidebar objects
  $sidebar_first = $vars['page']['sidebar_first'];
  $sidebar_second = $vars['page']['sidebar_second'];

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

  // Header
  $header = array();
  $header['class'][] = 'header';
  $header['class'][] = 'clearfix';
  $header['class'][] = theme_get_setting('navigation_sticky');
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
  if (module_exists('search')) {
    $search_form = drupal_get_form('search_form');
    $search_box = drupal_render($search_form);
    $vars['search_box'] = $search_box;
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

  dpm($vars);

}