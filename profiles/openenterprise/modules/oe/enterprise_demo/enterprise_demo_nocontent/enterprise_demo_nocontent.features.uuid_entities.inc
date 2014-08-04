<?php
/**
 * @file
 * enterprise_demo_nocontent.features.uuid_entities.inc
 */

/**
 * Implements hook_uuid_default_entities().
 */
function enterprise_demo_nocontent_uuid_default_entities() {
  $entities = array();

$entities['enterprise_demo_nocontent'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/da99084c-c5ee-4e6e-9e02-d11c71602daf',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => 'Welcome to Open Enterprise
	
',
        ),
      ),
    ),
    'cid' => 0,
    'comment' => 1,
    'comment_count' => 0,
    'cta' => array(
      'selections' => array(),
    ),
    'ds_switch' => '',
    'entity_type' => 'node',
    'exclude_node_title' => 1,
    'field_cta_category' => array(),
    'field_page_attribute_col' => array(),
    'field_visitor_attribute_col' => array(),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 0,
    'slug' => 'home',
    'status' => 1,
    'sticky' => 0,
    'title' => 'Home',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'page',
    'uid' => 1,
    'url_alias' => array(
      0 => array(
        'alias' => 'home',
        'language' => 'und',
      ),
    ),
    'uuid' => 'da99084c-c5ee-4e6e-9e02-d11c71602daf',
  );
  
  return $entities;
}
