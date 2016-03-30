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

    enterprise_rel_views_query($this->view);

    $this->query->add_orderby(NULL, NULL, $this->options['order'], 'rel_score');
  }
}
