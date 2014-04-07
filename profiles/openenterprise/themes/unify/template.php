<?php

/**
 * @file
 * template.php
 */



/**
 * Bootstrap theme wrapper function for the primary menu links.
 */
function unify_menu_tree__primary(&$variables) {
  //return '<div class="mega"><ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul></div>';  // changed to support unity theme
  return '<div class="mega"><ul class="menu nav navbar-nav navbar-right">' . $variables['tree'] . '</ul></div>';
}

/**
 * Bootstrap theme wrapper function for the main menu links.
 */
function unify_menu_tree__main_menu(&$variables) {
  //return '<div class="mega"><ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul></div>';  // changed to support unity theme
  return '<div class="mega"><ul class="menu nav navbar-nav navbar-right">' . $variables['tree'] . '</ul></div>';
}

/**
 * Bootstrap theme wrapper function for the primary menu links.
 */
function unify_menu_tree__secondary(&$variables) {
  return '<ul class="loginbar pull-right">' . $variables['tree'] . '</ul>';
}

function unify_preprocess_page(&$variables) {
  // hacks for unity theme
  $merge = array(
    '#attributes' => array(
      'class' => array('navbar-right'),
    ),
  );
  if (isset($variables['primary_nav']) && is_array($variables['primary_nav'])) {
    $variables['primary_nav'] = array_merge($variables['primary_nav'], $merge);
  }
  if (isset($variables['page']['navigation']['system_main-menu'])) {
    $variables['page']['navigation']['system_main-menu'] = array_merge($variables['page']['navigation']['system_main-menu'], $merge);
  }
}

/**
 * Overrides theme_breadcrumb().
 *
 * Print breadcrumbs as an ordered list.
 */
function unify_breadcrumb($variables) {
  $output = '';
  $breadcrumb = $variables['breadcrumb'];

  // Determine if we are to display the breadcrumb.
  $bootstrap_breadcrumb = theme_get_setting('bootstrap_breadcrumb');
  if (($bootstrap_breadcrumb == 1 || ($bootstrap_breadcrumb == 2 && arg(0) == 'admin')) && !empty($breadcrumb)) {
    $output = theme('item_list', array(
      'attributes' => array(
        'class' => array('breadcrumb', 'pull-right'),
      ),
      'items' => $breadcrumb,
      'type' => 'ol',
    ));
  }
  return $output;
}

function unify_ds_fields_info_alter(&$fields, $entity_type) {
  if (isset($fields['about_author'])) {
    $fields['about_author']['function'] = 'unify_enterprise_fields_about_author';
  }
}

function unify_enterprise_fields_about_author($variables) {
  $variables['title_tag'] = 'h2';
  $variables['title_prefix'] = '<div class="headline">';
  $variables['title_suffix'] = '</div>';
  return enterprise_style_ds_field_about_author($variables);
}