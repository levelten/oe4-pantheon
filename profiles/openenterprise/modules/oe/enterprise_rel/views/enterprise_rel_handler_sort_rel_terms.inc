<?php
/**
 * Handler which sorts the by the similarity.
 *
 * @ingroups views_sort_handlers
 */
class enterprise_rel_handler_sort_rel_terms extends views_handler_sort {

  function option_definition() {
    $options = parent::option_definition();
    $options['order'] = array('default' => 'DESC');
    return $options;
  }

  function query() {
    $this->ensure_my_table();
    if (!empty($this->view->tids)) {
      $this->query->add_orderby('rel_terms_taxonomy_index', 'nid', $this->options['order'], NULL, array('function' => 'count'));
    }
    else {

    }
  }
}
