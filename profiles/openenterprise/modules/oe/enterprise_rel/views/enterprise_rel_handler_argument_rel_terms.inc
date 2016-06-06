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

    $tids = explode('+', $arg);
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
    //dsm($rv_meta);
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

    //dsm($this->tids);

    $this->view->tids = $this->tids;
    return TRUE;
  }

  function query($group_by = FALSE) {
    $this->ensure_my_table();

    $this->query->add_tag('rel_terms');

    //dsm($this->tids);

    $tids = !empty($this->tids) ? $this->tids : array(0 => 0);
    $extra = array(
      array(
        'field' => 'tid',
        'value' => array($tids),
        'operator' => 'IN',
      )
    );
    $join = new views_join;
    $join->construct('taxonomy_index','node','nid','nid', $extra, "LEFT");
    $this->query->add_relationship('rel_terms_taxonomy_index', $join, 'taxonomy_index');

    $this->query->add_where_expression(0, "rel_terms_taxonomy_index.tid IS NOT NULL OR node.universal = 1");

    return;


    $tids = !empty($this->tids) ? $this->tids : array();
    $where_exp = '';
    if (!empty($this->default_tids)) {
      //$tids += $this->default_tids;
      $join = new views_join;
      $extra = array(
        array(
          'field' => 'tid',
          'value' => array($this->default_tids),
          'operator' => 'IN',
        )
      );
      //$extra = 'rel_terms_default_taxonomy_index.tid IN (' . implode(', ', $this->default_tids) . ')';
      $join->construct('taxonomy_index','node','nid','nid', $extra, "LEFT");
      $this->query->add_relationship('rel_terms_default_taxonomy_index', $join, 'taxonomy_index');
      $where_exp .= 'rel_terms_default_taxonomy_index.tid IS NOT NULL';
    }
    if (!empty($this->tids)) {
      $tids = !empty($this->tids) ? $this->tids : array(0 => 0);
      $extra = array(
        array(
          'field' => 'tid',
          'value' => array($tids),
          'operator' => 'IN',
        )
      );
      //$extra = 'rel_terms_taxonomy_index.tid IN (' . implode(', ', $tids) . ')';
      $where_exp .= (($where_exp) ? ' OR ' : '') . 'rel_terms_taxonomy_index.tid IS NOT NULL';
    }
    else {
      $extra = array();
    }
    $join = new views_join;
    $join->construct('taxonomy_index','node','nid','nid', $extra, "LEFT");
    $this->query->add_relationship('rel_terms_taxonomy_index', $join, 'taxonomy_index');

    $this->query->add_where_expression(0, "( $where_exp )");

    return;

    $this->query->leftJoin('taxonomy_index', 'rel_terms_taxonomy_index', 'node.nid = rel_terms_taxonomy_index.nid');

    $tids = array();
    if (!empty($this->default_tids)) {
      $tids += $this->default_tids;
      $this->query->add_table('taxonomy_index', NULL, NULL, 'rel_terms_default_taxonomy_index');
      //$this->query->add_where('rel_terms_default_taxonomy_index', 'tid', $this->default_tids, 'IN');
      $this->query->add_where_expression(0, 'rel_terms_default_taxonomy_index.tid', $this->default_tids, 'IN');
    }
    $tids += $this->tids;
    //$this->query->add_where('rel_terms_taxonomy_index', 'tid', $tids, 'IN');
    $this->query->add_where(0, 'rel_terms_taxonomy_index.tid', $tids, 'IN');

    //$this->query->add_where(0,
    //  db_or()
    //    ->condition("rel_terms_taxonomy_index.tid", $tids, 'IN')
    //    ->condition("rel_terms_default_taxonomy_index", $this->default_tids, 'IN')
    //);

    return;

    if (count($this->tids)) {
      if (!empty($this->default_tids)) {


      }
      $tids = $this->tids + $this->default_tids;
      $this->query->add_where('rel_terms_taxonomy_index', 'tid', $tids, 'IN');
      //$this->query->add_table('taxonomy_index', NULL, NULL, 'similarterms_taxonomy_index');
      if (!empty($this->default_tids)) {
        //$this->query->add_table('taxonomy_index', NULL, NULL, 'rel_terms_default_taxonomy_index');
        $db_and = db_and()
          ->isNull("rel_terms_taxonomy_index.tid")
          ->condition("rel_terms_default_taxonomy_index", $this->default_tids, 'IN');
        /*
        $this->query->add_where(0,
          db_or()
            ->condition("rel_terms_taxonomy_index.tid", $this->tids, 'IN')
            ->isNull("rel_terms_taxonomy_index.tid")
            //  ->condition("rel_terms_default_taxonomy_index", $this->default_tids, 'IN')
        );
        */
      }
      else {
        $this->query->add_where(0, 'rel_terms_taxonomy_index.tid', $this->tids, 'IN');
      }

      /*
      $this->query->add_where(0,
        db_or()
          ->condition("rel_terms_taxonomy_index.tid", $this->tids, 'IN')
          ->isNull("rel_terms_taxonomy_index.tid")
      );
      */
    }

    if (!empty($this->default_tids)) {
      //$this->query->add_table('taxonomy_index', NULL, NULL, 'rel_terms_default_taxonomy_index');
      //$this->query->add_where('rel_terms_default_taxonomy_index', 'tid', $this->default_tids, 'IN');
    }

    //$params = array(
    //  'function' => 'count',
    //);
    //$this->field_alias = $this->query->add_field('taxonomy_index', 'nid', 'similarterms_count_nid', $params);

    // exclude the current node(s)
    if (empty($this->options['include_args'])) {
      //$this->query->add_where(0, "node.nid", $this->value, 'NOT IN');
    }

  }
}
