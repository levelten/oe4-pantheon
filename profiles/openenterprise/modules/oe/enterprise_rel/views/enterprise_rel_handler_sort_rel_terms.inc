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

  /**
   * Defines query elements.
   */
  public function query() {
    if (in_array('similar_entries', $this->query->tags)) {
    //$this->query->add_orderby('node', 'nid', $this->options['order'], 'rel_score');
      $this->query->add_orderby(NULL, NULL, $this->options['order'], 'rel_score');

      $this->query->add_field('node', 'nid', 'nid', array('function' => 'groupby'));
      $this->query->add_groupby('nid');
      $this->query->distinct = TRUE;

      //dsm($this->query);
      //$this->query->add_groupby('nid');
      //$this->query->add_groupby('rel_score');
    }
  }

  /*
  function query() {
    $this->ensure_my_table();
    if (!empty($this->view->tids)) {
      $this->query->add_orderby('rel_terms_taxonomy_index', 'nid', $this->options['order'], NULL, array('function' => 'count'));
    }
    else {

    }
  }
  */
}
