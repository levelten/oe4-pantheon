<?php
/**
 * @file
 * oedemo.features.uuid_entities.inc
 */

/**
 * Implements hook_uuid_default_entities().
 */
function oedemo_uuid_default_entities() {
  $entities = array();

  $entities['oedemo'][] = (object) array(
    '__metadata' => array(
      'type' => 'bean',
      'uri' => 'bean/9f44c6ad-a6d8-4456-8dc5-70e568b9e5df',
      'cause' => FALSE,
    ),
    'cta' => array(
      'list_visibility' => 1,
      'selectors' => array(
        0 => 'cta_forms',
      ),
      'categories' => array(),
      'data' => array(
        'ga_event' => array(
          'track' => 0,
          'track_display' => 0,
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
    'delta' => 'hubspot-form-offer-min',
    'description' => NULL,
    'entity_type' => 'bean',
    'field_body' => array(
      'und' => array(
        0 => array(
          'format' => 'advanced_html',
          'value' => '<script charset="utf-8" src="//js.hubspot.com/forms/current.js"></script>
<script>
  hbspt.forms.create({ 
    portalId: \'215077\',
    formId: \'faddb679-6722-4477-856e-6b00dcca876e\'
  });
</script>',
        ),
      ),
    ),
    'field_landingpage' => array(),
    'field_redirect_url' => array(),
    'label' => 'HubSpot form: Offer (min)',
    'log' => '',
    'revision' => 1,
    'revisions' => array(),
    'slug' => 'hubspot_form_offer_min',
    'title' => '',
    'type' => 'cta',
    'uid' => 1,
    'url_alias' => array(),
    'uuid' => '9f44c6ad-a6d8-4456-8dc5-70e568b9e5df',
    'view_mode' => 'default',
  );

  return $entities;
}
