<?php
/**
 * @file
 */

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

  /*
  $info['tokens']['node']['rel-view'] = array(
    'name' => t('Node relevant view'),
    'description' => t("Formats relevant page uris. Does not includes base_path."),
    'type' => 'relevant',
  );

  $info['tokens']['current-page']['rel-view'] = array(
    'name' => t('Current page relevant view'),
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
  if (!isset($rv_meta)) {
    if (isset($data['relevant_view_meta'])) {
      $rv_meta = $data['relevant_view_meta'];
    }
    else {
      $rv_meta = enterprise_rel_get_rel_view_meta();
    }
  }
  if (empty($rv_meta)) {
    return;
  }

  if ($type == 'relevant') {

    //dsm($tokens);
    //dsm($data);
    //dsm($options);
    //dsm($rv_meta);



    //$test = og_context('dywr_franchise');
    //$lang = isset($franchise->language) ? $franchise->language : LANGUAGE_NONE;
    //$node_lang = '';
return;
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