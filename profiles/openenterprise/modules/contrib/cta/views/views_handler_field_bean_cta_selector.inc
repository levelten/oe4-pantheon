<?php
/**
 * Filter by bean type
 *
 * @ingroup views_filter_handlers
 */
class views_handler_field_bean_cta_selector extends views_handler_field {
  function construct() {
    parent::construct();
  }

  function render($values) {
    if (!empty($values->selector)) {
      $selectors = cta_selectors();
      if (!empty($selectors[$values->selector])) {
        return $selectors[$values->selector]['description'];
      }
    }
    return '';
  }
}
