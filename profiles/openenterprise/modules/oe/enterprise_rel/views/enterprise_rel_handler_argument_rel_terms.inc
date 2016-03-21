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

  var $similar_handler;

  function getSimilarHandler() {
    if (empty($this->similar_handler)) {
      $this->similar_handler = new similar_handler_argument_nid();
    }
    return $this->similar_handler;
  }

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

    $similar_handler = $this->getSimilarHandler();
    $options = array_merge($options, $similar_handler->option_definition());

    $options['default_action'] = array('default' => 'default');
    $options['default_argument_type'] = array('default' => 'taxonomy_tid');
    unset($options['validate']['contains']['type']);
    unset($options['boolean_mode']);
    //$options['validate']['contains']['type'] = array('default' => 'node');
    //$options['boolean_mode'] = array('default' => 0);


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

    unset($form['not']);
    $form['default_argument_type']['#disabled'] = TRUE;

    $form['similar'] = array(
      '#type' => 'fieldset',
      '#title' => t('FULLTEXT search options'),
    );

    // Add fields for increasing or decreasing relevance of destination ndoe fields.
    $relevance_options = array(
      '0' => '0%',
      '0.1' => '10%',
      '0.2' => '20%',
      '0.3' => '30%',
      '0.4' => '40%',
      '0.5' => '50%',
      '0.6' => '60%',
      '0.7' => '70%',
      '0.8' => '80%',
      '0.9' => '90%',
      '1.0' => '100%',
      '1.1' => '110%',
      '1.2' => '120%',
      '1.3' => '130%',
      '1.4' => '140%',
      '1.5' => '150%',
      '1.6' => '160%',
      '1.7' => '170%',
      '1.8' => '180%',
      '1.9' => '190%',
      '2.0' => '1000%',
    );
    $form['adjust_relevance'] = array(
      '#type' => 'checkbox',
      '#title' => t('Adjust relevance of fields'),
      '#default_value' => $this->options['adjust_relevance'],
      '#description' => t('Adjust the relevance of content titles, bodies, and other fields in matching.'),
      '#fieldset' => 'similar',
    );
    $form['title_relevance'] = array(
      '#type' => 'select',
      '#title' => t('Relevance of content\'s title.'),
      '#options' => $relevance_options,
      '#default_value' => $this->options['title_relevance'],
      '#description' => t('Increase or decrease the relevance of matches in destination content\'s title field.'),
      '#fieldset' => 'similar',
      '#dependency' => array('edit-options-adjust-relevance' => array('1')),
    );
    $form['body_relevance'] = array(
      '#type' => 'select',
      '#title' => t('Relevance of content\'s body.'),
      '#options' => $relevance_options,
      '#default_value' => $this->options['body_relevance'],
      '#description' => t('Increase or decrease the relevance of matches in '.
        'destination content\'s body and other fields.'),
      '#fieldset' => 'similar',
      '#dependency' => array('edit-options-adjust-relevance' => array('1')),
    );

    // Add fields for enabling matching in fields defined by field module.
    if (module_exists('field')) {
      $field_options = self::get_field_options();

      $form['include_fields'] = array(
        '#type' => 'checkbox',
        '#title' => t('Include content fields in matching'),
        '#default_value' => !empty($this->options['include_fields']),
        '#description' => t('Enable FULLTEXT queries on fields defined with Field module.'),
        '#fieldset' => 'similar',
      );
      foreach ($field_options as $table => $field) {
        $form['included_fields:'. $table] = array(
          '#type' => 'select',
          '#title' => $field,
          '#options' => $relevance_options,
          '#default_value' => isset($this->options['included_fields:'. $table]) ? $this->options['included_fields:'. $table] : 1,
          '#fieldset' => 'similar',
          '#dependency' => array(
            'edit-options-include-fields' => array('1'),
            'edit-options-adjust-relevance' => array('1'),
          ),
          '#dependency_count' => 2,
        );
      }
    }

    $form['boolean_mode'] = array(
      '#type' => 'checkbox',
      '#title' => t('Execute search in boolean mode'),
      '#default_value' => !empty($this->options['boolean_mode']),
      '#fieldset' => 'similar',
      '#description' => t('Boolean mode enables the ability to increase or decrease the relevance of certain fields.<br />'.
        'Note: Boolean mode may negatively affect the accuracy of view results.'),
    );

    // Add options for increasing or decreasing relevance of source node.
    $form['source_relevance'] = array(
      '#type' => 'checkbox',
      '#title' => t('Adjust source relevance'),
      '#default_value' => !empty($this->options['source_relevance']),
      '#description' => t('Increase the relevance of words in the title of the content being viewed.'),
      '#fieldset' => 'similar',
      '#dependency' => array('edit-options-boolean-mode' => array('1')),
    );
    $form['title_operator'] = array(
      '#type' => 'select',
      '#title' => t('Relevance of source content\'s title'),
      '#options' => array(
        'none' => t('No change'),
        'increase' => t('Increase title relevance'),
        'decrease' => t('Decrease title relevance'),
        'require_all' => t('Require all terms'),
        'require_some' => t('Require at least one term'),
        'require_complete' => t('Require complete title'),
        'exclude_all' => t('Exclude all terms'),
        'exclude_some' => t('Exclude at least one term'),
        'exclude_complete' => t('Exclude complete title'),
      ),
      '#default_value' => $this->options['title_operator'],
      '#fieldset' => 'similar',
      '#dependency' => array(
        'edit-options-boolean-mode' => array('1'),
        'edit-options-source-relevance' => array('1'),
      ),
      '#dependency_count' => 2,
    );

    // Add fields for creating custom relevance rules for specific words or phrases.
    $form['enable_custom_operators'] = array(
      '#type' => 'checkbox',
      '#title' => t('Set custom operators in words and phrases'),
      '#default_value' => !empty($this->options['enable_custom_operators']),
      '#fieldset' => 'similar',
      '#dependency' => array('edit-options-boolean-mode' => array('1')),
    );
    $form['custom_operators'] = array(
      '#type' => 'textfield',
      '#title' => t('Operators'),
      '#default_value' => $this->options['custom_operators'],
      '#description' => t('Use boolean logical operators to customize the FULLTEXT query. Each expression should '.
        'be separated by a vertical bar |.<br />'.
        'Available operators:  +  -  >  <  (  )  ~  "<br />'.
        'See http://dev.mysql.com/doc/refman/5.5/en/fulltext-boolean.html for more information.'),
      '#maxlength' => 1024,
      '#fieldset' => 'similar',
      '#dependency' => array(
        'edit-options-boolean-mode' => array('1'),
        'edit-options-enable-custom-operators' => array('1'),
      ),
      '#dependency_count' => 2,
    );

  }

  /**
   * Returns an array of fields that have been indexed by Similar Entries.
   */
  private static function get_field_options() {
    $field_options = array();
    $indices = similar_get_indices();
    foreach (field_info_fields() as $field => $info) {
      if ($info['type'] == 'text') {
        $table = key($info['storage']['details']['sql'][FIELD_LOAD_CURRENT]);
        if (isset($indices[$table])) {
          $field_options[$table] = $field;
        }
      }
    }
    return $field_options;
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

    $this->nids = array();

    $entity = menu_get_object();
    if (!empty($entity->entity_type) && ($entity->entity_type == 'node')) {
      $this->nids[] = $entity->nid;
    }
    $this->view->tids = $this->nids;

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

    if (!empty($this->nids)) {
      $boolean = !empty($this->options['boolean_mode']);
      $text = '';

      // Since the view could have multiple nid arguments, load each node
      // and populate the $text variable with node titles and bodies.
      foreach ($this->nids as $nid) {
        $node = node_load($nid);
        if (isset($node->title) && isset($node->body) && isset($node->body[$node->language])) {
          // Remove punctuation from the title.
          $title = preg_replace('/[^a-z0-9 _-]+/i', '', $node->title);

          // Alter the relevancy of words in the node title if option is selected.
          if ($boolean && !empty($this->options['source_relevance']) && isset($this->options['title_operator'])) {
            $title = $this->alter_node_title($title);
          }

          // Strip tags and add slashes only to the body before adding the title.
          $body = trim(addslashes(strip_tags($node->body[$node->language][0]['value'])));
          $text .= " $title $body";
        }
      }

      // Perform replacements to add custom operators to node body and title words.
      if ($boolean && !empty($this->options['enable_custom_operators']) && !empty($this->options['custom_operators'])) {
        $replacements = array_map('trim', explode('|', $this->options['custom_operators']));
        $words = array_map('similar_handler_argument_nid::get_search_word', $replacements);
        $text = preg_replace($words, $replacements, $text);
      }

      $text = trim($text);

      $query = $boolean ? $this->similar_build_query($text, 'IN BOOLEAN MODE') : $this->similar_build_query($text);

      // Exclude the current node(s).
      if (count($this->nids) > 1) {
        $this->query->add_where(0, 'node.nid', $this->nids, 'NOT IN');
      }
      else {
        $this->query->add_where(0, 'node.nid', $this->nids[0], '<>');
      }

    }

    $tax_weight = .5;

    if (!empty($this->tids)) {
      $weight = $tax_weight / count($this->tids);
      if (!empty($query)) {
        $query = "($query + ($weight * COUNT(rel_terms_taxonomy_index.nid)))";
      }
      else {
        $query = "($weight * COUNT(rel_terms_taxonomy_index.nid))";
      }

    }

    if (empty($query)) {
      $query = '0';
    }

    //dsm($query);

    // An empty string is passed for the table to bypass the table alias.
    $params = array(
      'function' => 'round',
    );
    $params = array();
    $this->query->add_field(NULL, $query, 'rel_score', $params);

    //dsm($this->query);

    //$this->query->add_field('node', 'nid', 'node_nid', array('function' => 'groupby'));
    //$this->query->add_groupby('nid');
    //$this->query->has_aggregate = TRUE;
    //$this->query->distinct = TRUE;



    // Add a node_access tag to prevent conflict with node_access module.
    $this->query->add_tag('node_access');

    // Add a Similar Entries tag to indicate that filters and sort handlers are valid.
    $this->query->add_tag('similar_entries');

    return;
  }

  /**
   * Builds a query from argument configuration options.
   * @param $text
   *   The text of the current node to be used in the query.
   * @param $modifier
   *   An optional FULLTEXT search modifer. ie 'IN BOOLEAN MODE'.
   * @see similar_handler_argument_nid::query()
   */
  public function similar_build_query($text, $modifier = '') {
    $text_weight = .5;
    $query = array();
    if (!empty($modifier)) {
      $modifier = " $modifier";
    }

    $elms = array();

    $weight = !empty($this->options['adjust_relevance']) && isset($this->options['title_relevance'])
      ? $this->options['title_relevance'] : 1;
    $elms['node.title'] = $weight;
    $query[] = "($weight * (MATCH(node.title) AGAINST('$text'$modifier)))";

    // The body field is always included in the query if it exists.
    if (db_table_exists('field_data_body')) {
      $weight = !empty($this->options['adjust_relevance']) ? $this->options['body_relevance'] : 1;
      $body_table = $this->query->add_table('field_data_body');

      if ($weight !== 0) {
        $elms["{$body_table}.body_value"] = $weight;
        $query[] = "($weight * (MATCH($body_table.body_value) AGAINST('$text'$modifier)))";
      }
    }

    if (module_exists('field') && !empty($this->options['include_fields'])) {
      $indices = similar_get_indices();
      foreach (self::get_field_options() as $table => $value) {
        $weight = !empty($this->options['adjust_relevance']) && isset($this->options['included_fields:'. $table])
          ? $this->options['included_fields:'. $table] : 1;
        $alias = $this->query->ensure_table($table);
        $fields = "$alias." . implode(", $alias.", $indices[$table]);
        $elms[$fields] = $weight;
        $query[] = "($weight * (MATCH($fields) AGAINST('$text'$modifier)))";
      }
    }

    $elms_count = count($elms);
    $query = array();
    foreach ($elms as $match => $weight) {
      $weight = $text_weight * $weight / $elms_count;
      $query[] = "($weight * (MATCH($match) AGAINST('$text'$modifier)))";
    }

    return "(". implode(" + ", $query) . ")";

    // Return a query that calculates an average score to prevent scores from fluctuating too much.
    // We multiply the score by different amounts depending on the modifier used.
    return "((". implode(" + ", $query) . ") / ". count($query) .")";
  }
}
