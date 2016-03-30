<?php
/**
 * Argument handler to accept a node id.
 * based on node_handler_argument_node_nid except that it doesn't
 * add a where clause to the query.
 *
 * @ingroup views_argument_handlers
 */
/**
 * Taxonomy tid default argument.
 */
class enterprise_rel_handler_argument_rel_terms extends views_handler_argument_many_to_one {

  function title_query() {
    $titles = array();
    $result = db_select('taxonomy_term_data', 'td')
      ->fields('td', array('name'))
      ->condition('td.tid', $this->value)
      ->execute();
    foreach ($result as $term) {
      $titles[] = check_plain($term->name);
    }
    return $titles;
  }


  function option_definition() {
    $options = parent::option_definition();

    $options['view'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['view'] = array(
      '#type' => 'checkbox',
      '#title' => t('Load taxonomies from view.'),
      '#default_value' => $this->options['view'],
    );
  }

  /**
   * Overrides argument's default actions list to ensure that node ID
   * from URL is provided.
   */
  public function default_actions($which = NULL) {
    $defaults = parent::default_actions();
    unset($defaults['ignore'], $defaults['not found'], $defaults['summary'], $defaults['empty']);

    if ($which) {
      if (!empty($defaults[$which])) {
        return $defaults[$which];
      }
    }
    else {
      return $defaults;
    }
  }

  function validate_arg($arg) {

    //dsm("arg:" . $arg);
    // first run the inherited arg validation
    //if (!parent::validate_arg($arg)) {
    //  dsm('no validate');
    //  return FALSE;
    //}

    $this->tids = array();
    $is_valid = 0;

    /*
    $term = taxonomy_get_term_by_name('default');
    //dsm($term);
    if (!empty($term)) {
      $term = array_shift($term);
      $this->view->default_tids = $this->default_tids = array();
      $this->view->default_tids[$term->tid] = $this->default_tids[$term->tid] = $term->tid;
    }
    */
    if (strpos($arg, '+')) {
      $tids = explode('+', $arg);
    }
    else {
      $tids = explode(',', $arg);
    }
    if (!empty($_REQUEST['rel_add_tids'])) {
      $t = explode(',', $_REQUEST['rel_add_tids']);
      $tids = array_merge($tids, $t);
    }
    //dsm($tids);
    if (!empty($tids)) {
      foreach ($tids as $e) {
        if (!empty($e)) {
          $a = (int)$e;
          $this->tids[$a] = $a;
          $is_valid = 1;
        }
      }
    }

    $rv_meta = enterprise_rel_get_rel_view_meta();
    if (!empty($rv_meta['current']['params'])) {
      $param_keys = array(
        'taxonomy_term',
        'taxonomy_term_parent',
      );
      foreach ($param_keys as $param_key) {
        if (!empty($rv_meta['current']['params'][$param_key])) {
          foreach ($rv_meta['current']['params'][$param_key] as $vocab => $param) {
            if (!empty($param['entities'])) {
              foreach ($param['entities'] as $term) {
                $this->tids[$term->tid] = $term->tid;
              }
            }
          }
        }
      }
    }

    $this->view->tids = $this->tids;

    return TRUE;
  }

  function query($group_by = FALSE) {

    $this->ensure_my_table();

    $this->query->add_tag('rel_terms');

    //enterprise_rel_views_query($this->view);
  }
}
