<?php

/**
 * Implements hook_views_data()
 **/
function enterprise_rel_views_data_alter(&$data) {

  $data['similarterms']['similarterms']['moved to'] = array('node', 'similarterms');
  $data['node']['similarterms'] = array(
    'title' => t('Similarity'),
    'group' => t('Similar By Terms'),
    'help' => t('Percentage/count of terms which node has in common with node given as argument.'),
    'field' => array(
      'handler' => 'similarterms_handler_field_similar',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'similarterms_handler_sort_similar',
    ),
  );
  $data['similarterms']['nid']['moved to'] = array('node', 'similar_nid');
  $data['node']['similar_nid'] = array(
    'title' => t('Nid'),
    'group' => t('Similar By Terms'),
    'help' => t('ID of content item(s). Passes term ids to Similar By Terms.'), // The help that appears on the UI,
    'argument' => array(
      'handler' => 'similarterms_handler_argument_node_nid',
      // 'parent' => 'views_handler_argument_numeric', // make sure parent is included
      'name field' => 'title', // the field to display in the summary.
      //'numeric' => TRUE,
      //'validate type' => 'nid',
    ),
  );
  /*
  $data['similarterms']['tid']['moved to'] = array('taxonomy_term_data', 'similar_tid');
  $data['taxonomy_term_data']['similar_tid'] = array(
    'title' => t('Term ID'),
    'group' => t('Similar By Terms'),
    'help' => t('ID of content item(s). Passes term ids to Similar By Terms.'), // The help that appears on the UI,
    'argument' => array(
      'handler' => 'similarterms_handler_argument_taxonomy_tid',
      //'parent' => 'views_handler_argument_string', // make sure parent is included
      'name field' => 'name', // the field to display in the summary.
      'zero is null' => TRUE,
      //'validate type' => 'taxonomy_tid',
    ),
  );
  */

  /*
  $data['similarterms']['tid'] = array(
    'title' => t('Term ID'),
    'group' => t('Similar By Terms'),
    'help' => t('ID of content item(s). Passes term ids to Similar By Terms.'), // The help that appears on the UI,
    'argument' => array(
      'handler' => 'similarterms_handler_argument_taxonomy_tid',
      'parent' => 'views_handler_argument_taxonomy', // make sure parent is included
      'name field' => 'name', // the field to display in the summary.
      'zero is null' => TRUE,
      //'validate type' => 'taxonomy_tid',
    ),
  );
  */

  //dsm($data);
}

function enterprise_rel_views_data() {

  // We namespace the data keys to prevent conflicts with 'similar'.
  $data['enterprise_rel']['table']['group'] = t('Relevant');
  $data['enterprise_rel']['table']['join'] = array('#global' => array());

  $data['enterprise_rel']['terms'] = array(
    'title' => t('By Terms'),
    'help' => t('The rating given to the related content given as an argument.'),
    'field' => array(
      'handler' => 'enterprise_rel_handler_field_rel_terms',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'enterprise_rel_handler_sort_rel_terms'
    ),
  );
  $data['enterprise_rel']['terms_default'] = array(
    'title' => t('By Default Terms'),
    'help' => t('The rating given to the related content given as an argument.'),
    'field' => array(
      'handler' => 'enterprise_rel_handler_field_rel_terms_default',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'enterprise_rel_handler_sort_rel_terms_default'
    ),
  );
  $data['enterprise_rel']['rel_tid'] = array(
    'group' => t('Relevant'),
    'title' => t('By Terms'),
    'help' => t('Display content if it has the selected taxonomy terms.'),
    'argument' => array(
      'handler' => 'enterprise_rel_handler_argument_rel_terms',
      //'name table' => 'taxonomy_term_data',
      'name field' => 'name',
      //'empty field name' => t('Uncategorized'),
      'numeric' => TRUE,
      //'skip base' => 'taxonomy_term_data',
    ),
  );
  $data['enterprise_rel']['rel_text_index'] = array(
    'group' => t('Relevant'),
    'title' => t('By Text Index'),
    'help' => t('Display content if it has the selected taxonomy terms.'),
    'argument' => array(
      'handler' => 'enterprise_rel_handler_argument_rel_text_index',
      //'name table' => 'taxonomy_term_data',
      'name field' => 'name',
      //'empty field name' => t('Uncategorized'),
      'numeric' => TRUE,
      //'skip base' => 'taxonomy_term_data',
    ),
  );

  return $data;

  $data['taxonomy_index']['similar_tid'] = array(
    'group' => t('Similar By Terms'),
    'title' => t('Term ID'),
    'help' => t('Display content if it has the selected taxonomy terms.'),
    'argument' => array(
      'handler' => 'views_handler_argument_term_node_tid',
      'name table' => 'taxonomy_term_data',
      'name field' => 'name',
      'empty field name' => t('Uncategorized'),
      'numeric' => TRUE,
      'skip base' => 'taxonomy_term_data',
    ),
    'filter' => array(
      'title' => t('Has taxonomy term'),
      'handler' => 'views_handler_filter_term_node_tid',
      'hierarchy table' => 'taxonomy_term_hierarchy',
      'numeric' => TRUE,
      'skip base' => 'taxonomy_term_data',
      'allow empty' => TRUE,
    ),
  );

  return $data;

  // We namespace the data keys to prevent conflicts with 'similar'.
  $data['similarterms']['tid'] = array(
    'title' => t('Term ID'),
    'group' => t('Similar By Terms'),
    'help' => t('ID of content item(s). Passes term ids to Similar By Terms.'), // The help that appears on the UI,
    'argument' => array(
      'handler' => 'similarterms_handler_argument_taxonomy_tid',
      'parent' => 'views_handler_argument_taxonomy', // make sure parent is included
      'name field' => 'name', // the field to display in the summary.
      'zero is null' => TRUE,
      //'validate type' => 'taxonomy_tid',
    ),
  );

  return $data;
}

function enterprise_rel_views_plugins_alter(&$plugins) {
  //dsm($plugins);
  $p = &$plugins['argument default']['taxonomy_tid'];
  $p['handler'] = 'enterprise_rel_views_plugin_argument_default_taxonomy_tid';
  $p['file'] = 'enterprise_rel_views_plugin_argument_default_taxonomy_tid.inc';
  $p['path'] = drupal_get_path('module', 'enterprise_rel');
  //dsm($plugins);
}

function enterprise_rel_views_query($view) {
  $done = &drupal_static(__FUNCTION__, array());

  // prevent execution when called from different rel arguments
  if (!empty($done[$view->dom_id])) {
    return;
  }
  $done[$view->dom_id] = 1;

  $args = array();
  if (!empty($view->argument['rel_tid'])) {
    $args['tid'] = &$view->argument['rel_tid'];

    $tids = !empty($args['tid']->tids) ? $args['tid']->tids : array(0 => 0);

    $extra = array(
      array(
        'field' => 'tid',
        'value' => array($tids),
        'operator' => 'IN',
      )
    );
    $join = new views_join;
    $join->construct('taxonomy_index','node','nid','nid', $extra, "LEFT");
    $view->query->add_relationship('rel_terms_taxonomy_index', $join, 'taxonomy_index');

    $view->query->add_where_expression(0, "rel_terms_taxonomy_index.tid IS NOT NULL OR node.universal = 1");
  }


  if (!empty($view->argument['rel_text_index'])) {
    $args['text_index'] = &$view->argument['rel_text_index'];
    $args['text_index']->nids = $args['text_index']->value;
  }

  if (!empty($args['text_index']) && !empty($args['text_index']->nids)) {
    $boolean = !empty($args['text_index']->options['boolean_mode']);
    $text = '';

    // Since the view could have multiple nid arguments, load each node
    // and populate the $text variable with node titles and bodies.
    foreach ($args['text_index']->nids as $nid) {
      $node = node_load($nid);
      if (isset($node->title) && isset($node->body) && isset($node->body[$node->language])) {
        // Remove punctuation from the title.
        $title = preg_replace('/[^a-z0-9 _-]+/i', '', $node->title);

        // Alter the relevancy of words in the node title if option is selected.
        if ($boolean && !empty($args['text_index']->options['source_relevance']) && isset($args['text_index']->options['title_operator'])) {
          $title = $args['text_index']->alter_node_title($title);
        }

        // Strip tags and add slashes only to the body before adding the title.
        $body = trim(addslashes(strip_tags($node->body[$node->language][0]['value'])));
        $text .= " $title $body";
      }
    }

    // Perform replacements to add custom operators to node body and title words.
    if ($boolean && !empty($args['text_index']->options['enable_custom_operators']) && !empty($args['text_index']->options['custom_operators'])) {
      $replacements = array_map('trim', explode('|', $args['text_index']->options['custom_operators']));
      $words = array_map('similar_handler_argument_nid::get_search_word', $replacements);
      $text = preg_replace($words, $replacements, $text);
    }

    $text = trim($text);

    $query = $boolean ? $args['text_index']->similar_build_query($text, 'IN BOOLEAN MODE') : $args['text_index']->similar_build_query($text);

    // Exclude the current node(s).
    if (count($args['text_index']->nids) > 1) {
      $view->query->add_where(0, 'node.nid', $args['text_index']->nids, 'NOT IN');
    }
    else {
      $view->query->add_where(0, 'node.nid', $args['text_index']->nids[0], '<>');
    }
  }

  $tax_weight = .5;

  if (!empty($args['tid']->tids)) {
    $weight = $tax_weight / count($args['tid']->tids);
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
  $view->query->add_field(NULL, $query, 'rel_score', $params);

  $view->query->add_field('node', 'nid', 'nid', array('function' => 'groupby'));
  //$this->query->add_groupby('node.nid');
  $view->query->distinct = TRUE;

  // Add a node_access tag to prevent conflict with node_access module.
  $view->query->add_tag('node_access');

  $view->query->add_tag('rel_arguments');
}
