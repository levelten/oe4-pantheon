<?php

/**
 * Shows the similarity of the node.
 *
 * @ingroup views_field_handlers
 */
class enterprise_rel_handler_field_rel_terms extends views_handler_field {

  // needed to override unreferenced terms field in sql select
  function query() {
    enterprise_rel_views_query($this->view);
  }

  function render($values) {
    $output = number_format($values->rel_score, 3);
    return $output;
  }

  /*
  function option_definition() {
    $options = parent::option_definition();
    $options['count_type'] = array('default' => 1);
    $options['percent_suffix'] = array('default' => 1);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['count_type'] = array(
      '#type' => 'radios',
      '#title' => t('Display type'),
      '#default_value' => $this->options['count_type'],
      '#options' => array(
        0 => t('Show count of common terms'),
        1 => t('Show as percentage'),
      ),
    );
  }

  function query() {
    if (!empty($this->view->tids)) {
      $params = array(
        'function' => 'count',
      );
      $this->field_alias = $this->query->add_field('rel_terms_taxonomy_index', 'nid', NULL, $params);
    }
    else {
      $this->field_alias = $this->query->add_field('', '0', 'rel_terms_taxonomy_index_nid');
    }



  }

  function render($values) {
    $value_key = 'rel_terms_taxonomy_index_nid';
    if ($this->options['count_type'] == 0) {
      return $values->{$value_key};
    }
    else {
      if (!empty($this->view->tids)) {
        $output = number_format($values->{$value_key}/count($this->view->tids) * 100) . '%';
      }
      else {
        $output = t('0% (No Terms Found)');
      }

      return $output;
    }
  }
  */
}
