<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_preprocess_page()
 */
function enterprise_bootstrap_ce_preprocess_page(&$variables) {

}

/**
 * Bootstrap theme wrapper function for the primary menu links.
 */
function enterprise_bootstrap_ce_menu_tree__main_menu(&$variables) {
  return _enterprise_bootstrap_ce_menu_wrapper($variables);
}
function enterprise_bootstrap_ce_menu_tree__primary_nav(&$variables) {
  return _enterprise_bootstrap_ce_menu_wrapper($variables);
}

/*
 * Helper function to determine which wrapper to add to the main menu.
 */
function _enterprise_bootstrap_ce_menu_wrapper($variables) {
  return '<div class="default-bootstrap"><ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul></div>';
}