<?php

/**
 * @file
 * Token callbacks for the token_example module.
 */

/**
 * Implements hook_token_info().
 *
 * @ingroup token_example
 */
function intel_token_info() {
  // Add two different token types. The first is the generic text format. The
  // second is the user's default text format, which is itself a 'format' token
  // type so it can be used directly.
  $types = array();
  $types['intel_phone'] = array(
    'name' => t('Intel phone numbers'),
    'description' => t('Provides telephone numbers.'),
    'needs-data' => 'intel_phonenumber',
  );

  // Tokens phone numbers

  $tokens['intel_phone'] = array();
  $tokens['intel_phone']['number'] = array(
    'name' => t('Phone number'),
    'description' => t("Display version of phone number"),
  );
  $tokens['intel_phone']['number:e164'] = array(
    'name' => t('Phone number E.164'),
    'description' => t("Phone number formatted in E.164 format"),
  );
  $tokens['intel_phone']['title'] = array(
    'name' => t('Phone number title'),
    'description' => t("Phone number title"),
  );

  $phonenumbers = intel_get_phonenumbers();
  foreach ($phonenumbers AS $key => $num) {
    $tokens['site']['intel_phone:' . $key] = array(
      'name' => t('Phone number "%title"',
        array(
          '%title' => $num['title'],
        )
      ),
      'description' => t("Phone number via Intel"),
      'type' => 'intel_phone',
    );
  }

  $info = array(
    'types' => $types,
    'tokens' => $tokens,
  );

  return $info;
}

function intel_token_info_alter(&$data) {
  //dsm($data);
}

/**
 * Implements hook_tokens().
 *
 * @ingroup token_example
 */
function intel_tokens($type, $tokens, array $data = array(), array $options = array()) {

  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  if ($type == 'site') {
    foreach ($tokens AS $name => $token) {
      // get intel_phonenum key from token name;

      if (substr($name, 0, 12) == 'intel_phone:') {
        list($pre, $phone_name, $subtoken) = explode(':', $name, 3);
        //$phone_name = substr($a[0], 12);
        $phonenumber = intel_phonenumber_load($phone_name);
        if ($phonenumber) {
          $replacements += token_generate('intel_phone', array($subtoken => $token), array('intel_phonenumber' => $phonenumber), $options);
        }
      }
    }
  }
  // Text format tokens.
  if ($type == 'intel_phone' && (isset($data['intel_phonenumber']))) {
    // get phonenumber
    $phonenum = $data['intel_phonenumber'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'number':
        case 'number:display':
          $replacements[$original] = $sanitize ? filter_xss($phonenum['number_display']) : $phonenum['number_display'];
          break;
        case 'number:e164':
          $replacements[$original] = $sanitize ? filter_xss($phonenum['number']) : $phonenum['number'];
          break;
        case 'title':
          $replacements[$original] = $sanitize ? filter_xss($phonenum['title']) : $phonenum['title'];
          break;
      }
    }
  }

  return $replacements;
}
