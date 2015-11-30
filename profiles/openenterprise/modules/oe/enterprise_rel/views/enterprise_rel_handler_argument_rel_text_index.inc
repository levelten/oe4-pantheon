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
class enterprise_rel_handler_argument_rel_text_index extends similar_handler_argument_nid {

  function validate_arg($arg) {
    //dsm("arg:" . $arg);

    $is_valid = parent::validate_arg($arg);

    return TRUE;
  }

  function query($group_by = FALSE) {
    if (empty($this->view->nids)) {
      $this->query->add_field('', '0', 'score');
    }
    else {
      return parent::query($group_by);
    }
  }
}
