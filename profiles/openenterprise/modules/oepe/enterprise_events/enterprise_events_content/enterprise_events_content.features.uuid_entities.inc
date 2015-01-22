<?php
/**
 * @file
 * enterprise_events_content.features.uuid_entities.inc
 */

/**
 * Implements hook_uuid_default_entities().
 */
function enterprise_events_content_uuid_default_entities() {
  $entities = array();

  $entities['enterprise_events_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/16066aae-a656-479c-994b-38df5e5396a3',
      'cause' => FALSE,
    ),
    'body' => array(),
    'cid' => 0,
    'comment' => 1,
    'comment_count' => 0,
    'cta' => array(
      'selections' => array(),
    ),
    'ds_switch' => '',
    'entity_type' => 'node',
    'field_categories' => array(),
    'field_event_datetime' => array(
      'und' => array(
        0 => array(
          'date_type' => 'datetime',
          'timezone' => 'America/Chicago',
          'timezone_db' => 'UTC',
          'value' => '2015-01-28 20:00:00',
          'value2' => '2015-01-28 21:00:00',
        ),
      ),
    ),
    'field_image' => array(),
    'field_tags' => array(),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 0,
    'status' => 1,
    'sticky' => 0,
    'title' => 'Intro to Inbound Marketing',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_event',
    'uid' => 1,
    'url_alias' => array(),
    'uuid' => '16066aae-a656-479c-994b-38df5e5396a3',
  );

  return $entities;
}
