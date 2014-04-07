<?php
/**
 * @file
 * enterprise_landingpages_test.features.uuid_entities.inc
 */

/**
 * Implements hook_uuid_default_entities().
 */
function enterprise_landingpages_test_uuid_default_entities() {
  $entities = array();

  $entities['enterprise_landingpages_test'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/9c9f78e6-f425-4dec-8aef-ea1276cc6bc4',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => '<p>Thank you for contacting us.</p>
',
        ),
      ),
    ),
    'cid' => 0,
    'comment' => 1,
    'comment_count' => 0,
    'entity_type' => 'node',
    'field_file' => array(),
    'field_track_submission' => array(
      'und' => array(
        0 => array(
          'value' => 'goal_tofu-conversion',
        ),
      ),
    ),
    'field_track_submission_value' => array(),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'promote' => 0,
    'status' => 1,
    'sticky' => 0,
    'title' => 'Test thank you page',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_thankyou',
    'uid' => 1,
    'uuid' => '9c9f78e6-f425-4dec-8aef-ea1276cc6bc4',
  );
  $entities['enterprise_landingpages_test'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/08b2f62b-93a3-4f3b-b7dc-4d61869eba3b',
      'cause' => FALSE,
    ),
    'body' => array(),
    'cid' => 0,
    'comment' => 1,
    'comment_count' => 0,
    'entity_type' => 'node',
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'promote' => 0,
    'status' => 1,
    'sticky' => 0,
    'title' => 'Test webform',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'webform',
    'uid' => 1,
    'uuid' => '08b2f62b-93a3-4f3b-b7dc-4d61869eba3b',
    'webform' => array(
      'nid' => 561,
      'confirmation' => '',
      'confirmation_format' => 'full_html',
      'redirect_url' => 'thank-you/test',
      'status' => 1,
      'block' => 1,
      'teaser' => 0,
      'allow_draft' => 0,
      'auto_save' => 0,
      'submit_notice' => 1,
      'submit_text' => '',
      'submit_limit' => -1,
      'submit_interval' => -1,
      'total_submit_limit' => -1,
      'total_submit_interval' => -1,
      'record_exists' => TRUE,
      'roles' => array(
        0 => 1,
      ),
      'emails' => array(
        1 => array(
          'nid' => 561,
          'eid' => 1,
          'email' => 'somebody@example.tld',
          'subject' => 'default',
          'from_name' => 'default',
          'from_address' => 'default',
          'template' => 'default',
          'excluded_components' => array(),
          'html' => 0,
          'attachments' => 0,
        ),
      ),
      'components' => array(
        1 => array(
          'nid' => 561,
          'cid' => 1,
          'pid' => 0,
          'form_key' => 'first_name',
          'name' => 'First name',
          'type' => 'textfield',
          'value' => '',
          'extra' => array(
            'title_display' => 'before',
            'private' => 0,
            'width' => '',
            'maxlength' => '',
            'field_prefix' => '',
            'field_suffix' => '',
            'disabled' => 0,
            'unique' => 0,
            'description' => '',
            'attributes' => array(),
            'conditional_component' => '',
            'conditional_operator' => '=',
            'conditional_values' => '',
          ),
          'mandatory' => 1,
          'weight' => 0,
          'page_num' => 1,
        ),
        2 => array(
          'nid' => 561,
          'cid' => 2,
          'pid' => 0,
          'form_key' => 'last_name',
          'name' => 'Last name',
          'type' => 'textfield',
          'value' => '',
          'extra' => array(
            'title_display' => 'before',
            'private' => 0,
            'width' => '',
            'maxlength' => '',
            'field_prefix' => '',
            'field_suffix' => '',
            'disabled' => 0,
            'unique' => 0,
            'description' => '',
            'attributes' => array(),
            'conditional_component' => '',
            'conditional_operator' => '=',
            'conditional_values' => '',
          ),
          'mandatory' => 1,
          'weight' => 1,
          'page_num' => 1,
        ),
        3 => array(
          'nid' => 561,
          'cid' => 3,
          'pid' => 0,
          'form_key' => 'email',
          'name' => 'Email',
          'type' => 'email',
          'value' => '',
          'extra' => array(
            'title_display' => 'before',
            'private' => 0,
            'width' => '',
            'unique' => 0,
            'disabled' => 0,
            'description' => '',
            'attributes' => array(),
            'conditional_component' => '',
            'conditional_operator' => '=',
            'conditional_values' => '',
          ),
          'mandatory' => 1,
          'weight' => 2,
          'page_num' => 1,
        ),
        4 => array(
          'nid' => 561,
          'cid' => 4,
          'pid' => 0,
          'form_key' => 'intel_visitor_url',
          'name' => 'Visitor intel',
          'type' => 'hidden',
          'value' => '',
          'extra' => array(
            'hidden_type' => 'hidden',
            'private' => 0,
            'conditional_component' => '',
            'conditional_operator' => '=',
            'conditional_values' => '',
          ),
          'mandatory' => 0,
          'weight' => 99,
          'page_num' => 1,
        ),
      ),
      'intel' => array(
        'field_visitor_email' => 'email',
        'field_visitor_name' => 'first_name',
        'field_visitor_name2' => 'last_name',
        'fieldmap' => array(),
      ),
    ),
  );
  $entities['enterprise_landingpages_test'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/2b4354c1-f948-41cc-b5b0-50caef7f5339',
      'cause' => FALSE,
    ),
    'body' => array(),
    'cid' => 0,
    'comment' => 1,
    'comment_count' => 0,
    'entity_type' => 'node',
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'promote' => 0,
    'status' => 1,
    'sticky' => 0,
    'title' => 'Test landing page',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_landingpage',
    'uid' => 1,
    'uuid' => '2b4354c1-f948-41cc-b5b0-50caef7f5339',
  );
  $entities['enterprise_landingpages_test'][] = (object) array(
    '__metadata' => array(
      'type' => 'bean',
      'uri' => 'bean/bdfc31ca-2eb9-45e9-8102-6d41c4e1e3c1',
      'cause' => FALSE,
    ),
    'cta' => array(
      'list_visibility' => 1,
      'selectors' => array(
        0 => 'cta_sidebar',
      ),
      'categories' => array(),
      'data' => array(
        'ga_event' => array(
          'track' => 1,
          'track_display' => 1,
          'track_click' => 1,
          'track_conversion' => 1,
          'click' => array(
            'value' => 0,
            'action' => '',
            'selector' => '',
            'event' => '',
          ),
          'conversion' => array(
            'value' => 0,
            'action' => '',
          ),
          'display' => array(
            'action' => '',
          ),
        ),
      ),
      'custom_path' => '',
      'custom_selector' => '',
    ),
    'data' => array(
      'view_mode' => 'default',
    ),
    'default_revision' => 1,
    'delta' => 'default-cta-sidebar',
    'description' => NULL,
    'entity_type' => 'bean',
    'field_body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'value' => '<p><img src="http://placehold.it/360x300&amp;text=CTA" /></p>
',
        ),
      ),
    ),
    'field_landingpage' => array(
      'und' => array(
        0 => array(
          'target_id' => '2b4354c1-f948-41cc-b5b0-50caef7f5339',
        ),
      ),
    ),
    'field_redirect_url' => array(),
    'label' => 'Default CTA (sidebar)',
    'log' => '',
    'revisions' => array(),
    'title' => '',
    'type' => 'cta',
    'uid' => 1,
    'uuid' => 'bdfc31ca-2eb9-45e9-8102-6d41c4e1e3c1',
    'view_mode' => 'default',
  );
  $entities['enterprise_landingpages_test'][] = (object) array(
    '__metadata' => array(
      'type' => 'bean',
      'uri' => 'bean/410d81da-86b0-473d-9984-8ded63b9b7e5',
      'cause' => FALSE,
    ),
    'cta' => array(
      'list_visibility' => 1,
      'selectors' => array(
        0 => 'cta_footer',
      ),
      'categories' => array(),
      'data' => array(
        'ga_event' => array(
          'track' => 1,
          'track_display' => 1,
          'track_click' => 1,
          'track_conversion' => 1,
          'click' => array(
            'value' => 0,
            'action' => '',
            'selector' => '',
            'event' => '',
          ),
          'conversion' => array(
            'value' => 0,
            'action' => '',
          ),
          'display' => array(
            'action' => '',
          ),
        ),
      ),
      'custom_path' => '',
      'custom_selector' => '',
    ),
    'data' => array(
      'view_mode' => 'default',
    ),
    'default_revision' => 1,
    'delta' => 'default-cta-footer',
    'description' => NULL,
    'entity_type' => 'bean',
    'field_body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'value' => '<p><img src="http://placehold.it/1024x206&amp;text=CTA" /></p>
',
        ),
      ),
    ),
    'field_landingpage' => array(
      'und' => array(
        0 => array(
          'target_id' => '2b4354c1-f948-41cc-b5b0-50caef7f5339',
        ),
      ),
    ),
    'field_redirect_url' => array(),
    'label' => 'Default CTA (footer)',
    'log' => '',
    'revisions' => array(),
    'title' => '',
    'type' => 'cta',
    'uid' => 1,
    'uuid' => '410d81da-86b0-473d-9984-8ded63b9b7e5',
    'view_mode' => 'default',
  );

  return $entities;
}
