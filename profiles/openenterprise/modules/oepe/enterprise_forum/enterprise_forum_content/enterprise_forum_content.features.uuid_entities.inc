<?php
/**
 * @file
 * enterprise_forum_content.features.uuid_entities.inc
 */

/**
 * Implements hook_uuid_default_entities().
 */
function enterprise_forum_content_uuid_default_entities() {
  $entities = array();

  $entities['enterprise_forum_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/5084aafe-9f04-49e2-a522-da30cbd2f2ae',
      'cause' => 'node/b2170edf-73e0-4606-be6b-663ebc896ea3',
    ),
    'description' => '',
    'entity_type' => 'taxonomy_term',
    'format' => 'full_html',
    'metatags' => array(),
    'name' => 'Analytics',
    'url_alias' => array(),
    'uuid' => '5084aafe-9f04-49e2-a522-da30cbd2f2ae',
    'vocabulary_machine_name' => 'forums',
    'weight' => -1,
  );
  
  $entities['enterprise_forum_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/a6d3de81-ee14-4e45-a2f0-0b5c75ee0c6c',
      'cause' => 'node/8cb356c1-a4da-434d-afff-6b7fd816c710',
    ),
    'description' => '',
    'entity_type' => 'taxonomy_term',
    'format' => 'full_html',
    'metatags' => array(),
    'name' => 'Marketing',
    'url_alias' => array(),
    'uuid' => 'a6d3de81-ee14-4e45-a2f0-0b5c75ee0c6c',
    'vocabulary_machine_name' => 'forums',
    'weight' => -1,
  );

  $entities['enterprise_forum_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/8cb356c1-a4da-434d-afff-6b7fd816c710',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => 'Praesent aliquam enim eget ultrices ultricies. Nam imperdiet, arcu et pretium scelerisque, urna magna feugiat magna, in dignissim turpis nunc at leo. Vivamus ac malesuada eros, vitae maximus enim. Nulla fermentum tempor neque et tincidunt. Nam dignissim a dui a luctus. Vivamus blandit orci at elit viverra tempor. Aenean vestibulum auctor convallis. Nulla sed egestas nunc. Aliquam vitae finibus felis, vel pulvinar erat.',
        ),
      ),
    ),
    'cid' => 0,
    'comment' => 2,
    'comment_count' => 0,
    'cta' => array(
      'selections' => array(),
    ),
    'ds_switch' => '',
    'entity_type' => 'node',
    'forum_tid' => 30,
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 0,
    'status' => 1,
    'sticky' => 0,
    'taxonomy_forums' => array(
      'und' => array(
        0 => array(
          'tid' => 'a6d3de81-ee14-4e45-a2f0-0b5c75ee0c6c',
        ),
      ),
    ),
    'title' => 'What is Inbound Marketing',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'forum',
    'uid' => 1,
    'url_alias' => array(),
    'uuid' => '8cb356c1-a4da-434d-afff-6b7fd816c710',
  );

  $entities['enterprise_forum_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/b2170edf-73e0-4606-be6b-663ebc896ea3',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => '<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed ac mauris ante. Etiam fringilla, lectus vel lacinia interdum, est felis auctor nibh, ut suscipit lorem lacus vitae diam. Phasellus lobortis ligula ipsum, eu commodo diam consectetur vitae. Suspendisse potenti. Donec feugiat ligula ligula, ultricies iaculis nisi ornare nec. Nunc non neque nisl. Duis efficitur nisi non erat tempus volutpat. Aliquam auctor dignissim lorem et efficitur. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae;</p>
',
        ),
      ),
    ),
    'cid' => 0,
    'comment' => 2,
    'comment_count' => 0,
    'cta' => array(
      'selections' => array(),
    ),
    'ds_switch' => '',
    'entity_type' => 'node',
    'forum_tid' => 31,
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 0,
    'status' => 1,
    'sticky' => 0,
    'taxonomy_forums' => array(
      'und' => array(
        0 => array(
          'tid' => '5084aafe-9f04-49e2-a522-da30cbd2f2ae',
        ),
      ),
    ),
    'title' => 'Custom Dimensions in Universal Analytics',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'forum',
    'uid' => 1,
    'url_alias' => array(),
    'uuid' => 'b2170edf-73e0-4606-be6b-663ebc896ea3',
  );

  return $entities;
}
