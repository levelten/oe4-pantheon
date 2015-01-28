<?php
/**
 * @file
 * enterprise_permissions_content.features.uuid_entities.inc
 */

/**
 * Implements hook_uuid_default_entities().
 */
function enterprise_permissions_content_uuid_default_entities() {
  $entities = array();

  $entities['enterprise_permissions_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'user',
      'uri' => 'user/04356eaf-8f1b-4c22-9177-388c078539dd',
      'cause' => FALSE,
    ),
    'entity_type' => 'user',
    'field_description' => array(),
    'field_firstname' => array(
      'und' => array(
        0 => array(
          'format' => NULL,
          'value' => 'Demo',
        ),
      ),
    ),
    'field_lastname' => array(
      'und' => array(
        0 => array(
          'format' => NULL,
          'value' => 'Tester',
        ),
      ),
    ),
    'field_picture' => array(),
    'field_title' => array(),
    'init' => 'demo-tester@example.com',
    'language' => '',
    'mail' => 'demo-tester@example.com',
    'metatags' => array(),
    'name' => 'demo-tester',
    'pass' => '$S$DiClQKoO4CDha82/Nr05/in.rfXNcNTSCgyTDYpVWazfeMiSPm5E',
    'picture' => NULL,
    'realname' => 'Demo Tester',
    'roles' => array(
      2 => 'authenticated user',
      7 => 'demo',
    ),
    'signature' => '',
    'signature_format' => 'full_html',
    'socialmedia' => array(
      'profiles' => array(),
    ),
    'status' => 1,
    'theme' => '',
    'timezone' => 'America/Chicago',
    'url_alias' => array(
      0 => array(
        'alias' => 'users/demo-tester',
        'language' => 'und',
      ),
    ),
    'uuid' => '04356eaf-8f1b-4c22-9177-388c078539dd',
  );
  
  $entities['enterprise_permissions_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'user',
      'uri' => 'user/d39b9843-f9ef-43fd-9601-7158f9499c37',
      'cause' => FALSE,
    ),
    'entity_type' => 'user',
    'field_description' => array(),
    'field_firstname' => array(
      'und' => array(
        0 => array(
          'format' => NULL,
          'value' => 'Writer',
        ),
      ),
    ),
    'field_lastname' => array(
      'und' => array(
        0 => array(
          'format' => NULL,
          'value' => 'Tester',
        ),
      ),
    ),
    'field_picture' => array(),
    'field_title' => array(),
    'init' => 'writer-tester@example.com',
    'language' => '',
    'mail' => 'writer-tester@example.com',
    'metatags' => array(),
    'name' => 'writer-tester',
    'pass' => '$S$DkKwqiLOWmsAmrKNdY0J.xSql3P7JxNVl4p01r7Qr3IveZcvl5gZ',
    'picture' => NULL,
    'realname' => 'Writer Tester',
    'roles' => array(
      2 => 'authenticated user',
      4 => 'writer',
    ),
    'signature' => '',
    'signature_format' => 'full_html',
    'socialmedia' => array(
      'profiles' => array(),
    ),
    'status' => 1,
    'theme' => '',
    'timezone' => 'America/Chicago',
    'url_alias' => array(
      0 => array(
        'alias' => 'users/writer-tester',
        'language' => 'und',
      ),
    ),
    'uuid' => 'd39b9843-f9ef-43fd-9601-7158f9499c37',
  );
  
  $entities['enterprise_permissions_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'user',
      'uri' => 'user/62b74b53-dcb7-48a8-926e-0cca7ffc47aa',
      'cause' => FALSE,
    ),
    'entity_type' => 'user',
    'field_description' => array(),
    'field_firstname' => array(
      'und' => array(
        0 => array(
          'format' => NULL,
          'value' => 'Editor',
        ),
      ),
    ),
    'field_lastname' => array(
      'und' => array(
        0 => array(
          'format' => NULL,
          'value' => 'Tester',
        ),
      ),
    ),
    'field_picture' => array(),
    'field_title' => array(),
    'init' => 'editor-tester@example.com',
    'language' => '',
    'mail' => 'editor-tester@example.com',
    'metatags' => array(),
    'name' => 'editor-tester',
    'pass' => '$S$DR0brshnsaXr96.U0St8uGon4VoircZhd0MEe4n/RQnaUKGosrHV',
    'picture' => NULL,
    'realname' => 'Editor Tester',
    'roles' => array(
      2 => 'authenticated user',
      5 => 'editor',
    ),
    'signature' => '',
    'signature_format' => 'full_html',
    'socialmedia' => array(
      'profiles' => array(),
    ),
    'status' => 1,
    'theme' => '',
    'timezone' => 'America/Chicago',
    'url_alias' => array(
      0 => array(
        'alias' => 'users/editor-tester',
        'language' => 'und',
      ),
    ),
    'uuid' => '62b74b53-dcb7-48a8-926e-0cca7ffc47aa',
  );
  
  $entities['enterprise_permissions_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'user',
      'uri' => 'user/d78d13ed-9343-4c88-8a86-17ae2b13cc4b',
      'cause' => FALSE,
    ),
    'entity_type' => 'user',
    'field_description' => array(),
    'field_firstname' => array(
      'und' => array(
        0 => array(
          'format' => NULL,
          'value' => 'Manager',
        ),
      ),
    ),
    'field_lastname' => array(
      'und' => array(
        0 => array(
          'format' => NULL,
          'value' => 'Tester',
        ),
      ),
    ),
    'field_picture' => array(),
    'field_title' => array(),
    'init' => 'manager-tester@example.com',
    'language' => '',
    'mail' => 'manager-tester@example.com',
    'metatags' => array(),
    'name' => 'manager-tester',
    'pass' => '$S$DR0brshnsaXr96.U0St8uGon4VoircZhd0MEe4n/RQnaUKGosrHV',
    'picture' => NULL,
    'realname' => 'Manager Tester',
    'roles' => array(
      2 => 'authenticated user',
      6 => 'manager',
    ),
    'signature' => '',
    'signature_format' => 'full_html',
    'socialmedia' => array(
      'profiles' => array(),
    ),
    'status' => 1,
    'theme' => '',
    'timezone' => 'America/Chicago',
    'url_alias' => array(
      0 => array(
        'alias' => 'users/manager-tester',
        'language' => 'und',
      ),
    ),
    'uuid' => 'd78d13ed-9343-4c88-8a86-17ae2b13cc4b',
  );
  
  $entities['enterprise_permissions_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'user',
      'uri' => 'user/e633084e-1b82-497b-8b90-414c443a3e42',
      'cause' => FALSE,
    ),
    'entity_type' => 'user',
    'field_description' => array(),
    'field_firstname' => array(
      'und' => array(
        0 => array(
          'format' => NULL,
          'value' => 'Administrator',
        ),
      ),
    ),
    'field_lastname' => array(
      'und' => array(
        0 => array(
          'format' => NULL,
          'value' => 'Tester',
        ),
      ),
    ),
    'field_picture' => array(),
    'field_title' => array(),
    'init' => 'administrator-tester@example.com',
    'language' => '',
    'mail' => 'administrator-tester@example.com',
    'metatags' => array(),
    'name' => 'administrator-tester',
    'pass' => '$S$DR0brshnsaXr96.U0St8uGon4VoircZhd0MEe4n/RQnaUKGosrHV',
    'picture' => NULL,
    'realname' => 'Administrator Tester',
    'roles' => array(
      2 => 'authenticated user',
      3 => 'administrator',
    ),
    'signature' => '',
    'signature_format' => 'full_html',
    'socialmedia' => array(
      'profiles' => array(),
    ),
    'status' => 1,
    'theme' => '',
    'timezone' => 'America/Chicago',
    'url_alias' => array(
      0 => array(
        'alias' => 'users/administrator-tester',
        'language' => 'und',
      ),
    ),
    'uuid' => 'e633084e-1b82-497b-8b90-414c443a3e42',
  );
  
  return $entities;
}
