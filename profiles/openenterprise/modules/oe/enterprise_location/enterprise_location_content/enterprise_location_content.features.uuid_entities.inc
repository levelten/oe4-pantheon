<?php
/**
 * @file
 * enterprise_location_content.features.uuid_entities.inc
 */

/**
 * Implements hook_uuid_default_entities().
 */
function enterprise_location_content_uuid_default_entities() {
  $entities = array();

  $entities['enterprise_location_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/bc47ca89-d2a0-48cc-81a0-318c6a388d5b',
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
    'field_address' => array(
      'und' => array(
        0 => array(
          'administrative_area' => 'TX',
          'country' => 'US',
          'data' => NULL,
          'dependent_locality' => NULL,
          'first_name' => NULL,
          'last_name' => NULL,
          'locality' => 'Austin',
          'name_line' => NULL,
          'organisation_name' => NULL,
          'postal_code' => 78731,
          'premise' => '2nd Floor',
          'sub_administrative_area' => NULL,
          'sub_premise' => NULL,
          'thoroughfare' => '7000 North Mopac Exprwy',
        ),
      ),
    ),
    'field_categories' => array(),
    'field_geo' => array(
      'und' => array(
        0 => array(
          'bottom' => '30.353581100000',
          'geo_type' => 'point',
          'geohash' => '9v6kxttn2v8kn',
          'geom' => 'POINT (-97.7494484 30.3535811)',
          'lat' => '30.353581100000',
          'left' => '-97.749448400000',
          'lon' => '-97.749448400000',
          'right' => '-97.749448400000',
          'top' => '30.353581100000',
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
    'title' => 'LevelTen Austin',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_location',
    'uid' => 1,
    'url_alias' => array(),
    'uuid' => 'bc47ca89-d2a0-48cc-81a0-318c6a388d5b',
  );
  $entities['enterprise_location_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/68007d34-96d1-4c0e-b309-ccecbcc0359b',
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
    'field_address' => array(
      'und' => array(
        0 => array(
          'administrative_area' => 'TX',
          'country' => 'US',
          'data' => NULL,
          'dependent_locality' => NULL,
          'first_name' => NULL,
          'last_name' => NULL,
          'locality' => 'Dallas',
          'name_line' => NULL,
          'organisation_name' => NULL,
          'postal_code' => 75206,
          'premise' => 'Suite 210',
          'sub_administrative_area' => NULL,
          'sub_premise' => NULL,
          'thoroughfare' => '4228 N. Central Expwy',
        ),
      ),
    ),
    'field_categories' => array(),
    'field_geo' => array(
      'und' => array(
        0 => array(
          'bottom' => '32.816569300000',
          'geo_type' => 'point',
          'geohash' => '9vg4tw0fmevuy',
          'geom' => 'POINT (-96.7882768 32.8165693)',
          'lat' => '32.816569300000',
          'left' => '-96.788276800000',
          'lon' => '-96.788276800000',
          'right' => '-96.788276800000',
          'top' => '32.816569300000',
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
    'title' => 'LevelTen Dallas',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_location',
    'uid' => 1,
    'url_alias' => array(),
    'uuid' => '68007d34-96d1-4c0e-b309-ccecbcc0359b',
  );

  return $entities;
}
