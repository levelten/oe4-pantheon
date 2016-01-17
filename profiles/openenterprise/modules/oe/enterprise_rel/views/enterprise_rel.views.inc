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