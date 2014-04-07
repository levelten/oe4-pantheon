<?php
/**
 * @file
 * Admin configuration management
 */

function intel_contact_admin_settings_form($form, $form_state) {
  $form['intel_sync_visitordata_fullcontact'] = array(
    '#type' => 'checkbox',
    '#title' => t('Sync Full Contact data'),
    '#default_value' => variable_get('intel_sync_visitordata_fullcontact', 0),
    '#description' => t('Check to enable syncing data via FullContact API. Only available for pro accounts.'),
  );
  return system_settings_form($form);
}