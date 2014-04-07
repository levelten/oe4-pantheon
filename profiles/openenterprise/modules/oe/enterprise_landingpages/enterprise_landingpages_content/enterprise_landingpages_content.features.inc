<?php
/**
 * @file
 * enterprise_landingpages_content.features.inc
 */

/**
 * Implements hook_cta_block_setting_defaults().
 */
function enterprise_landingpages_content_cta_block_setting_defaults() {
  $data = array(
    'webform:client-block-1aa7b3ac-74a1-4099-8015-1ef579add761' => array(
      'list_visibility' => 1,
      'selectors' => array(
        0 => 'cta_forms',
      ),
      'categories' => array(),
      'data' => array(
        'ga_event' => array(
          'track' => 0,
          'track_display' => 0,
          'track_click' => 0,
          'track_conversion' => 0,
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
    ),
    'webform:client-block-1fe8ec6e-050d-4e4f-9204-f0cba8085b7f' => array(
      'list_visibility' => 1,
      'selectors' => array(
        0 => 'cta_forms',
      ),
      'categories' => array(),
      'data' => array(
        'ga_event' => array(
          'track' => 0,
          'track_display' => 0,
          'track_click' => 0,
          'track_conversion' => 0,
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
    ),
    'webform:client-block-ed36ec72-9393-4f7a-8418-4571024f07c4' => array(
      'list_visibility' => 1,
      'selectors' => array(
        0 => 'cta_forms',
        1 => 'cta_sidebar',
      ),
      'categories' => array(),
      'data' => array(
        'ga_event' => array(
          'track' => 0,
          'track_display' => 0,
          'track_click' => 0,
          'track_conversion' => 0,
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
    ),
    'webform:client-block-c54a0ce3-e853-470c-a1c6-dcb89c8a5dd3' => array(
      'list_visibility' => 1,
      'selectors' => array(
        0 => 'cta_forms',
      ),
      'categories' => array(),
      'data' => array(
        'ga_event' => array(
          'track' => 0,
          'track_display' => 0,
          'track_click' => 0,
          'track_conversion' => 0,
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
    ),
    'webform:client-block-806bdfa9-61b3-4e25-a3eb-0710d3800861' => array(
      'list_visibility' => 1,
      'selectors' => array(
        0 => 'cta_forms',
      ),
      'categories' => array(),
      'data' => array(
        'ga_event' => array(
          'track' => 0,
          'track_display' => 0,
          'track_click' => 0,
          'track_conversion' => 0,
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
    ),
  );
  return $data;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_landingpages_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "deploy" && $api == "deploy_plans") {
    return array("version" => "1");
  }
}
