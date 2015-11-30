<?php
/**
 * @file
 */


function enterprise_rel_token_info_alter(&$info) {
  //$entity_info = entity_get_info();
  //$token_types = entity_token_types_chained();
  //dsm($token_types);
}

function enterprise_rel_token_info() {

  //$info['types']['relevant'] = array(
  //  'name' => t('Relevant'),
  //  'description' => t('Tokens for relevant content.'),
  //);
  $info = array();

  $info['types']['rel-view'] = array(
    'name' => t('Relevant view'),
    'description' => t("Tokens for the relevant view."),
    'type' => 'rel-view',
  );

  $info['tokens']['rel-view']['path'] = array(
    'name' => t('Relevant view path'),
    'description' => t("Formats relevant page uris. Does not includes base_path."),
  );

  $info['tokens']['node']['rel-view'] = array(
    'name' => t('Relevant view'),
    'description' => t("Formats relevant page uris. Does not includes base_path."),
    'type' => 'rel-view',
  );

  $info['tokens']['node']['rel-view']['path'] = array(
    'name' => t('Path to relevant view'),
    'description' => t("Formats relevant page uris. Does not includes base_path."),
    'type' => 'rel-view',
  );

  $info['tokens']['node']['rel-view']['path']['default-args'] = array(
    'name' => t('Path with all default args to relevant view'),
    'description' => t("Formats relevant page uris. Does not includes base_path."),
    'type' => 'rel-view',
  );

  /*
  $info['tokens']['node']['rel-view']['path']['default-args'] = array(
    'name' => t('Path to rel view with all default arguments'),
    'description' => t("Formats relevant page uris. Does not includes base_path."),
    'type' => 'relevant',
  );
  */

  return $info;
}

/**
 * Implements hook_tokens().
 *
 * @ingroup token_example
 */
function enterprise_rel_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  $sanitize = !empty($options['sanitize']);
  $rv_meta = &drupal_static(__FUNCTION__);
  //dsm($rv_meta);

  $ret_types = array(
    'path' => 'path',
    'path-value' => 'path-value',
    'dyn-path' => 'dyn-path',
  );

  if ($type == 'node' && !empty($data['node'])) {

    //dsm($tokens);
    //dsm($data);
    $node = $data['node'];
    $rv_meta = enterprise_rel_get_rel_view_meta('node/' . $node->nid);
    //dsm($rv_meta);
    if (empty($rv_meta)) {
      return $replacements;
    }
    //dsm($tokens);

    foreach ($tokens as $name => $original) {
      if (substr($name, 0, 9) != 'rel-view:') {
        continue;
      }
      $toks = explode(':', $name);
      //dsm($toks);
      array_shift($toks);
      $ret_type = 'path';
      if (!empty($toks[0]) && !empty($ret_types[$toks[0]])) {
        //dsm($toks);
        $ret_type = $ret_types[$toks[0]];
        array_shift($toks);
      }
      $param_keys = array();
      $obj = null;
      $wrapper = entity_metadata_wrapper('node', $node);
      if ($toks[0] == 'default-args') {

      }
      else if (count($toks) >= 2 && $toks[0] == 'field') {
        $param_keys[] = 'field';
        $param_keys[] = $fn = $toks[1];
        $param_value = array(
          'entities' => array(),
        );
        if (empty($node->{$fn}[LANGUAGE_NONE][0])) {
          continue;
        }
        $param_value['entities'][] = (object)$node->{$fn}[LANGUAGE_NONE][0];
      }
//dsm($param_value);


      if ($ret_type == 'dyn-path' || $ret_type == 'path-value' ) {
        if (empty($param_value['entities'])) {
          continue;
        }
        if (empty($rv_meta[$param_keys[0] . '_filtargs'][$param_keys[1]])) {
          continue;
        }
        $fa = $rv_meta[$param_keys[0] . '_filtargs'][$param_keys[1]];

        $value = enterprise_rel_format_dyn_argument_string($param_keys[0], $param_value, $rv_meta['view'], $fa);
      }
      else {
        // TODO: non field types not finished
        $param_keys[] = $toks[0];
        $param_keys[] = $fn = $toks[1];
        $param_value = array(
          'entities' => array(),
        );
        $options = array();

      }
      //dsm($toks);
      //dsm($ret_type);
      //dsm("value=$value");
      if ($ret_type == 'path') {
        if (empty($toks)) {
          $replacements[$original] = $rv_meta['path'];
        }
      }
      else if ($ret_type == 'dyn-path') {
        if (!empty($value)) {
          $replacements[$original] = "rel-view/{$param_keys[0]}/{$param_keys[1]}/$value";
        }
      }
    }

    // Chained token relationships.
    /*
    if ($format_tokens = token_find_with_prefix($tokens, 'rel-view')) {
      if ($items = field_get_items('node', $node, 'body')) {
        $body_format = filter_format_load($items[0]['format']);
        $replacements += token_generate('format', $format_tokens, array('format' => $body_format), $options);
      }
    }
    */
  }

//dsm($replacements);
  return $replacements;
}

