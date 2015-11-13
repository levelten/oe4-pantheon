<?php

/**
 * @file
 * template.php
 */

/**
 * Overrides theme_menu_tree().
 */
function enterprise_health_menu_tree__menu_block(&$variables) {
  return '<ul class="menu nav nav-stacked nav-pills">' . $variables['tree'] . '</ul>';
}