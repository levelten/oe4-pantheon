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

  $info['types']['relevant'] = array(
    'name' => t('Relevant'),
    'description' => t('Shortcut tokens relevant content'),
  );

  $info['tokens']['rel-view'] = array(
    'name' => t('Relevant view'),
    'description' => t("Formats relevant page uris. Does not includes base_path."),
    'type' => 'relevant',
  );

  $info['tokens']['rel-view']['path'] = array(
    'name' => t('Relevant view path'),
    'description' => t("Formats relevant page uris. Does not includes base_path."),
    'type' => 'relevant',
  );


  $info['tokens']['node']['rel-view']['path'] = array(
    'name' => t('Node relevant view'),
    'description' => t("Formats relevant page uris. Does not includes base_path."),
    'type' => 'relevant',
  );

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

  if (!isset($rv_meta)) {
    if (isset($data['relevant_view_meta'])) {
      $rv_meta = $data['relevant_view_meta'];
    }
    else {
      $rv_meta = enterprise_rel_get_rel_view_meta();
    }
  }
  if (empty($rv_meta)) {
    return $replacements;
  }

  $ret_types = array(
    'path' => 'path',
    'path-value' => 'path-value',
    'dyn-path' => 'dyn-path',
  );

  if ($type == 'node') {
    //dsm($tokens);
    //dsm($data);
    $node = $data['node'];
    foreach ($tokens as $name => $original) {
      if (substr($name, 0, 9) != 'rel-view:') {
        continue;
      }
      $toks = explode(':', $name);
      array_shift($toks);
      $ret_type = 'url';
      if (!empty($ret_types[$toks[0]])) {
        //dsm($toks);
        $ret_type = $ret_types[$toks[0]];
        array_shift($toks);
      }
      $param_keys = array();
      $obj = null;
      //dsm($ret_type);
      //dsm($toks);
      $wrapper = entity_metadata_wrapper('node', $node);
      if (count($toks) >= 2 && $toks[0] == 'field') {
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

      if (empty($param_value['entities'])) {
        continue;
      }

      if ($ret_type == 'dyn-path' || $ret_type == 'path-value' ) {
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
      //dsm("value=$value");
      if (!empty($value)) {
        if ($ret_type == 'dyn-path') {
          $replacements[$original] = "rel-view/{$param_keys[0]}/{$param_keys[1]}/$value";
        }
      }
    }
  }

  //dsm($replacements);


  if ($type == 'relevant') {

    //dsm($tokens);
    //dsm($data);
    //dsm($options);
    //dsm($rv_meta);



    //$test = og_context('dywr_franchise');
    //$lang = isset($franchise->language) ? $franchise->language : LANGUAGE_NONE;
    //$node_lang = '';
return $replacements;
    foreach ($tokens as $name => $original) {
      switch ($name) {
        default:
          // check relevant:url:path
          if (substr($name, 0, 4) == 'url:' || $name == 'url') {
            $path = parse_url(substr($name, 4));
            $options = array();
            if (!empty($path['query'])) {
              parse_str($path['query'], $query);
              $options['query'] = $query;
            }
            $replacements[$original] = dwyr_franchise_url($path['path'], $options, $franchise);
          }
          else if (substr($name, 0, 5) == 'path:' || $name == 'path') {
            $e = explode(':', $name);
            $params = array();
            if (count($e) == 1) {
              return $rv_meta['path'];
            }
            else {

              if ($e[1] == 'taxonomy') {
                $params['taxonomy'] = array();

              }
            }
            //$path = parse_url(substr($name, 5));
            $options = array();
            if (!empty($path['query'])) {
              parse_str($path['query'], $query);
              $options['query'] = $query;
            }
            $replacements[$original] = dwyr_franchise_path($path['path'], $options, $franchise);
          }
          break;
      }
    }
  }
//dsm($replacements);
  return $replacements;
}

