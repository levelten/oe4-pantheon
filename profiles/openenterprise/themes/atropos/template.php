<?php

/**
 * @file
 * template.php
 */

/**
 * Bootstrap theme wrapper function for the primary menu links.
 */
function atropos_menu_tree__primary(&$variables) {
  //return '<div class="mega"><ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul></div>';  // changed to support unity theme
  return '<ul class="nav nav-pills nav-main scroll-menu" id="topMain">' . $variables['tree'] . '</ul>';
}

/**
 * Bootstrap theme wrapper function for the primary menu links.
 */
function atropos_menu_tree__secondary(&$variables) {
  return '<ul class="loginbar pull-right">' . $variables['tree'] . '</ul>';
}

function atropos_preprocess_page(&$variables) {
  // hacks for unity theme
  $merge = array(
    '#attributes' => array(
      'class' => array('navbar-right'),
    ),
  );
  $variables['primary_nav'] = array_merge($variables['primary_nav'], $merge);

  //dsm($variables);
}

