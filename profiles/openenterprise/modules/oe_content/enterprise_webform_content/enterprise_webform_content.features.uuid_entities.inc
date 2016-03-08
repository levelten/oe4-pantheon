<?php
/**
 * @file
 * enterprise_webform_content.features.uuid_entities.inc
 */

/**
 * Implements hook_uuid_default_entities().
 */
function enterprise_webform_content_uuid_default_entities() {
  $entities = array();

  $entities['enterprise_webform_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'bean',
      'uri' => 'bean/7a689d82-dec9-44bc-8af5-53c82b154274',
      'cause' => FALSE,
    ),
    'data' => array(
      'view_mode' => 'default',
    ),
    'default_revision' => 1,
    'delta' => 'contact-info-and-map',
    'description' => NULL,
    'entity_type' => 'bean',
    'field_body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'value' => '<p><a href="http://goo.gl/maps/cUKnp" target="_blank"><img src="http://maps.googleapis.com/maps/api/staticmap?center=4228+N.+Central+Expy.+Dallas,+TX+75206&amp;zoom=15&amp;size=400x200&amp;maptype=roadmap&amp;sensor=false&amp;markers=color:red%7Ccolor:red%7Clabel:%7C32.817539,-96.787963" /></a></p>

<p><strong>LevelTen Interactive</strong><br />
4228 N. Central Expwy.<br />
Dallas, TX 75206</p>

<p>Phone: <a class="phone" href="tel:[site:intel_phone:main:number:e164]">[site:intel_phone:main:number]</a><br /></p>
',
        ),
      ),
    ),
    'label' => 'Custom: Contact info and map',
    'log' => '',
    'revision' => 1,
    'revisions' => array(),
    'slug' => 'contact_us_block',
    'title' => '',
    'type' => 'basic_block',
    'uid' => 1,
    'url_alias' => array(),
    'uuid' => '7a689d82-dec9-44bc-8af5-53c82b154274',
    'view_mode' => 'default',
  );
  $entities['enterprise_webform_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/cf3a4aa8-a24a-4bac-af77-76b77020fa1d',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => '<p style="font-size: 14px; line-height: 21px;">To find out how Venture can use its fourteen years of web development and Internet marketing experience, and true Drupal expertise to help your online business or project succeed, please fill in as much information below as you can and we will be in contact shortly.</p>

<p style="font-size: 14px; line-height: 21px;">For questions or issues with OpenEnterprise or our many contributed Drupal modules and themes, please use the support queue on the appropriate&nbsp;<a href="http://drupal.org/project/openenterprise" style="font-size: 14px;" target="_blank">Drupal.org project page</a>. &nbsp;You can also search our current&nbsp;<a href="http://www.leveltendesign.com/jobs?__hstc=204032207.7c338bbc463b1f30154e928e28379753.1364824486725.1366732534467.1366737985335.30&amp;__hssc=204032207.49.1366737985335" style="font-size: 14px;">job openings</a>.</p>

<p style="font-size: 14px; line-height: 21px;">To ensure high quality standards, all of our development and marketing work is done in-house, so we do not respond to requests for outsourcing, offshoring, SEO or development partnerships.</p>
',
        ),
      ),
    ),
    'cid' => 0,
    'comment' => 1,
    'comment_count' => 0,
    'ds_switch' => '',
    'entity_type' => 'node',
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'promote' => 1,
    'slug' => 'contact',
    'status' => 1,
    'sticky' => 0,
    'title' => 'Contact us',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'webform',
    'uid' => 1,
    'url_alias' => array(
      0 => array(
        'alias' => 'contact',
        'language' => 'und',
      ),
    ),
    'uuid' => 'cf3a4aa8-a24a-4bac-af77-76b77020fa1d',
    'webform' => array(
      'nid' => 12,
      'confirmation' => 'Thank you for contacting us.',
      'confirmation_format' => 'full_html',
      'redirect_url' => '<confirmation>',
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
        1 => 2,
      ),
      'emails' => array(),
      'components' => array(
        2 => array(
          'nid' => 12,
          'cid' => 2,
          'pid' => 0,
          'form_key' => 'first_name',
          'name' => 'First name',
          'type' => 'textfield',
          'value' => '',
          'extra' => array(
            'width' => '',
            'maxlength' => '',
            'field_prefix' => '',
            'field_suffix' => '',
            'disabled' => 0,
            'unique' => 0,
            'title_display' => 'before',
            'description' => '',
            'attributes' => array(),
            'private' => 0,
            'conditional_component' => '',
            'conditional_operator' => '=',
            'conditional_values' => '',
            'intel_field_map' => 'name:first',
          ),
          'mandatory' => 1,
          'weight' => 0,
          'page_num' => 1,
        ),
        1 => array(
          'nid' => 12,
          'cid' => 1,
          'pid' => 0,
          'form_key' => 'last_name',
          'name' => 'Last name',
          'type' => 'textfield',
          'value' => '',
          'extra' => array(
            'width' => '',
            'maxlength' => '',
            'field_prefix' => '',
            'field_suffix' => '',
            'disabled' => 0,
            'unique' => 0,
            'title_display' => 'before',
            'description' => '',
            'attributes' => array(),
            'private' => 0,
            'conditional_component' => '',
            'conditional_operator' => '=',
            'conditional_values' => '',
            'intel_field_map' => 'name:last',
          ),
          'mandatory' => 0,
          'weight' => 1,
          'page_num' => 1,
        ),
        3 => array(
          'nid' => 12,
          'cid' => 3,
          'pid' => 0,
          'form_key' => 'email',
          'name' => 'Email',
          'type' => 'email',
          'value' => '',
          'extra' => array(
            'width' => '',
            'unique' => 0,
            'disabled' => 0,
            'title_display' => 'before',
            'description' => '',
            'attributes' => array(),
            'private' => 0,
            'conditional_component' => '',
            'conditional_operator' => '=',
            'conditional_values' => '',
            'intel_field_map' => 'email:email',
          ),
          'mandatory' => 1,
          'weight' => 2,
          'page_num' => 1,
        ),
        4 => array(
          'nid' => 12,
          'cid' => 4,
          'pid' => 0,
          'form_key' => 'message',
          'name' => 'Message',
          'type' => 'textarea',
          'value' => '',
          'extra' => array(
            'cols' => 60,
            'rows' => 5,
            'title_display' => 'before',
            'resizable' => 1,
            'disabled' => 0,
            'description' => '',
            'attributes' => array(),
            'private' => 0,
            'conditional_component' => '',
            'conditional_operator' => '=',
            'conditional_values' => '',
          ),
          'mandatory' => 1,
          'weight' => 3,
          'page_num' => 1,
        ),
        5 => array(
          'nid' => 12,
          'cid' => 5,
          'pid' => 0,
          'form_key' => 'intel_visitor_url',
          'name' => 'Visitor link',
          'type' => 'hidden',
          'value' => '',
          'extra' => array(
            'private' => FALSE,
            'hidden_type' => 'value',
            'conditional_component' => '',
            'conditional_operator' => '=',
            'conditional_values' => '',
          ),
          'mandatory' => 0,
          'weight' => 4,
          'page_num' => 1,
        ),
        6 => array(
          'nid' => 12,
          'cid' => 6,
          'pid' => 0,
          'form_key' => 'mailchimp',
          'name' => 'MailChimp',
          'type' => 'mailchimp',
          'value' => '',
          'extra' => array(
            'mailchimp_list' => '70298b4268',
            'use_existing_email_field' => 'email',
            'checkbox_label' => 'Subscribe to newsletter',
            'checkbox_checked_by_default' => 1,
            'checkbox_hidden' => 0,
            'mergefields' => 'FNAME|first_name
LNAME|last_name',
            'title_display' => 'before',
            'private' => 0,
            'conditional_operator' => '=',
            'field_prefix' => '',
            'field_suffix' => '',
            'description' => '',
            'attributes' => array(),
            'conditional_component' => '',
            'conditional_values' => '',
          ),
          'mandatory' => 0,
          'weight' => 5,
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

  return $entities;
}
