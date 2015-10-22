<?php

/**
 * @file
 * template.php
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
