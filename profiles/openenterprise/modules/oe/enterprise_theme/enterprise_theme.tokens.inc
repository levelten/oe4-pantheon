<?php
/**
 * @file
 * Code for the Enterprise Theme feature.
 */

function enterprise_theme_token_info() {

  //$info['types']['relevant'] = array(
  //  'name' => t('Relevant'),
  //  'description' => t('Tokens for relevant content.'),
  //);
  $info = array();

  $info['tokens']['site']['header-branding'] = array(
    'name' => t('Header branding'),
    'description' => t("Logo, site name, slogan in theme header."),
  );

  return $info;
}

function enterprise_theme_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'site') {
    foreach ($tokens as $name => $original) {
      if ($name == 'header-branding') {
        $replacements[$original] = theme('header_branding', array());
      }
      else if ($name == 'navbar-toggle') {
        $replacements[$original] = theme('navbar_toggle', array());
      }
    }
  }

  return $replacements;
}