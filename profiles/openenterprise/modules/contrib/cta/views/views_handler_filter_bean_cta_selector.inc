<?php
/**
 * Filter by bean type
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_bean_cta_selector extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('CTA selectors');
      $selectors = cta_selectors();
      $options = array();
      foreach ($selectors as $name=> $info) {
        $options[$name] = $info['description'];
      }
      asort($options);
      $this->value_options = $options;
    }
  }

  /*
  function op_simple() {
    if (empty($this->value)) {
      return;
    }
    $alias = $this->query->add_table('cta_bean_selector');
    $this->query->add_where_expression(0, "$alias.delta = :cta_selector",
      array(
        'cta_selector' => $this->value,
      )
    );

    dsm($this->query);

    return;
    $this->ensure_my_table();

    // We use array_values() because the checkboxes keep keys and that can cause
    // array addition problems.
    $statements = array();

    $not_in = $this->operator == 'not in' ? TRUE : FALSE;
    $schema_operator = $not_in ? 'NOT LIKE' : 'LIKE';
    $composite = $not_in ? ' AND ' : ' OR ';

    foreach ($this->value as $schema) {
      $statements[] = 'uri ' . $schema_operator . ' \'' . db_like($schema) . '://%\'';
    }

    $this->query->add_where_expression($this->options['group'], implode($composite, $statements));
  }
  */
}
