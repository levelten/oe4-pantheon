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

  // always return true so that views will work as blocks on non-nodes
  function validate_arg($arg) {
    //dsm("arg:" . $arg);

    $is_valid = parent::validate_arg($arg);

    return TRUE;
  }

  function query($group_by = FALSE) {
    $this->ensure_my_table();

    $this->query->add_tag('rel_text_index');

    //$this->query->add_tag('rel_text_index');
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
    $text_weight /= 40;
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
