<?php
DEFINE('LINKINTEL_ENABLED_DEFAULT', 1);
DEFINE('LINKINTEL_PRIORITY_DEFAULT', 50);
DEFINE('LINKINTEL_ALLOW_VARIANTS_DEFAULT', 3);
DEFINE('LINKINTEL_CONTENT_AUTOGEN_DEFAULT', 1);
DEFINE('LINKINTEL_CONTENT_TARGET_COUNT_DEFAULT', 5);
DEFINE('LINKINTEL_SIDEBAR_AUTOGEN_DEFAULT', 1);
DEFINE('LINKINTEL_SIDEBAR_TARGET_COUNT_DEFAULT', 3);
DEFINE('LINKINTEL_REQUEST_SYNC_TITLE_DEFAULT', 1);
DEFINE('LINKINTEL_REQUEST_SYNC_TAX_DEFAULT', 1);
//DEFINE(LINKINTEL_REQUEST_SYNC_TAX_VOCABS_DEFAULT', array());
DEFINE('LINKINTEL_REQUEST_SYNC_KWRESEARCH_DEFAULT', 1);
DEFINE('LINKINTEL_AUTOGEN_EXCLUSIVITY_DEFAULT', 0);
DEFINE('LINKINTEL_REQUEST_MODE_DEFAULT', 0);
DEFINE('LINKINTEL_REQUESTS_RELEVANCE_COEF', 40);
DEFINE('LINKINTEL_NOLINKINTEL_TAGS', 'code,pre');

/**
 * returns array of priority options
 */
function linkintel_get_content_autogen_options() {
  return array(
    0 => t('Don\'t autogen content links'),
    1 => t('Autogen - limit to X links per page'),
    2 => t('Autogen - limit to X links per 500 words'),
  );
}

/**
 * returns array of priority options
 */
function linkintel_get_sidebar_autogen_options() {
  return array(
    0 => t('Don\'t autogen sidebar links'),
    1 => t('Autogen - limit to X links per page'),
  );
}

/**
 * returns array of priority options
 */
function linkintel_get_mode_options($style = 'link') {
  $modes = array(
    0 => t('Coded'),
    1 => t('Content'),
    2 => t('Sidebar'),
    10 => t('Filter'),
  );
  if($style == 'request') {
    $modes[0] = t('Either');  
  }
  if($style != 'report') {
    unset($modes[10]);   
  }
  
  return $modes;
}

function linkintel_get_autogen_exclusivity_options() {
  $options = array(
    0 => t('Default priorities'),
    1 => t('Content links have priority'),
    2 => t('Sidebar links have priority'),  
  );
  return $options;
}

function linkintel_get_autogen_options() {
  $options = array(
    0 => t('N'),
    1 => t('Y (LI)'),
    2 => t('Y (filter)'),  
  );
  return $options;
}

function linkintel_get_allow_variants_options($mode = 'form') {
  $options = array(
    0 => t('Disable variant matching'),
    2 => t('Enable variant matching on sidebar only'),
    3 => t('Enable variant matching on all links'),  
  );
  if($mode == 'report') {
     $options = array(
      0 => t('No'),
      1 => t('Content'),
      2 => t('Sidebar'),
      3 => t('All'),  
    );   
  }
  return $options;
}

/**
 * returns array of priority options
 */
function linkintel_get_link_attributes() {
  $attr = array(
    'title' => t('Title'),
    'target' => t('Target'),
    'rel' => t('Nofollow'),
    'name' => t('Name'),
    'id' => t('ID'),
    'class' => t('Class'),
    'style' => t('Style'),
  );
  return $attr;
}

/**
 * returns array of priority options
 */
function linkintel_get_node_type_exclude_options() {
  static $types;
  if($types) {
    return $types;
  }
  $types = array();
  $t_obj = node_get_types();
  foreach($t_obj AS $type) {
    $types[$type->type] = $type->name;  
  } 
  return $types;
}