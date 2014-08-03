<?php
/**
 * @file
 * enterprise_thankyoupage_content.features.uuid_entities.inc
 */

/**
 * Implements hook_uuid_default_entities().
 */
function enterprise_thankyoupage_content_uuid_default_entities() {
  $entities = array();

  $entities['enterprise_thankyoupage_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/90815ebd-54e6-4bce-9734-676b839e8b65',
      'cause' => FALSE,
    ),
    'body' => array(),
    'cid' => 0,
    'comment' => 1,
    'comment_count' => 0,
    'content_experiments' => NULL,
    'cta' => array(
      'selections' => array(),
    ),
    'ds_switch' => '',
    'entity_type' => 'node',
    'field_file' => array(),
    'field_intel_event_col' => array(),
    'field_page_attribute_col' => array(),
    'field_track_submission' => array(),
    'field_track_submission' => array(
      'und' => array(
        0 => array(
          'value' => 'goal_contact-form',
        ),
      ),
    ),
    'field_visitor_attribute_col' => array(),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 0,
    'slug' => 'thank_you_for_contacting_us',
    'status' => 1,
    'sticky' => 0,
    'title' => 'Thank you for contacting us',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_thankyou',
    'uid' => 1,
    'url_alias' => array(
      0 => array(
        'alias' => 'thank-you/contact',
        'language' => 'und',
      ),
    ),
    'uuid' => '90815ebd-54e6-4bce-9734-676b839e8b65',
  );

  return $entities;
}
