<?php
/**
 * @file
 * enterprise_slideshow.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_slideshow_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_bean__enterprise_slideshow';
  $strongarm->value = array(
    'view_modes' => array(
      'default' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'enterprise_slideshow_arrow' => array(
        'custom_settings' => TRUE,
      ),
      'enterprise_slideshow_pager' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'horizontal' => array(
        'custom_settings' => FALSE,
      ),
      'vertical' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'label' => array(
          'weight' => '0',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'revision' => array(
          'weight' => '3',
        ),
        'view_mode' => array(
          'weight' => '2',
        ),
        'redirect' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'enterprise_slideshow_arrow' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'enterprise_slideshow_pager' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_bean__enterprise_slideshow'] = $strongarm;

  return $export;
}
