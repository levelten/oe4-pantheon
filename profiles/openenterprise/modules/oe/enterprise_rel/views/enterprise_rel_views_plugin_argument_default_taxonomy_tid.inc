<?php

/**
 * @file
 * Definition of views_plugin_argument_default_taxonomy_tid.
 */

/**
 * Taxonomy tid default argument.
 */
class enterprise_rel_views_plugin_argument_default_taxonomy_tid extends views_plugin_argument_default_taxonomy_tid {
  function init(&$view, &$argument, $options) {
    parent::init($view, $argument, $options);

    // Convert legacy vids option to machine name vocabularies.
    if (!empty($this->options['vids'])) {
      $vocabularies = taxonomy_get_vocabularies();
      foreach ($this->options['vids'] as $vid) {
        if (isset($vocabularies[$vid], $vocabularies[$vid]->machine_name)) {
          $this->options['vocabularies'][$vocabularies[$vid]->machine_name] = $vocabularies[$vid]->machine_name;
        }
      }
    }
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['view'] = array('default' => FALSE, 'bool' => TRUE);
    $options['count'] = array('default' => '');
    $options['hierarchy_level'] = array('default' => '');

    //$options['term_page'] = array('default' => TRUE, 'bool' => TRUE);
    //$options['node'] = array('default' => FALSE, 'bool' => TRUE);
    //$options['anyall'] = array('default' => ',');
    //$options['limit'] = array('default' => FALSE, 'bool' => TRUE);
    //$options['vocabularies'] = array('default' => array());

    return $options;
  }

  function options_form(&$form, &$form_state) {
    // get the parent form elements
    parent::options_form($form, $form_state);

    // we want to insert the view form element after node form element
    $elems = element_children($form);
    $post = array();
    $keep = array(
      'term_page' => 1,
      'node' => 1,
    );
    foreach ($elems as $key) {
      if (empty($keep[$key])) {
        $post[$key] = $form[$key];
        unset($form[$key]);
      }
    }

    $form['view'] = array(
      '#type' => 'checkbox',
      '#title' => t('Load default filter from page view'),
      '#default_value' => $this->options['view'],
    );

    $form += $post;

    $form['count'] = array(
      '#type' => 'textfield',
      '#title' => t('Maximum number of terms'),
      '#default_value' => $this->options['count'],
      '#size' => 5,
    );

    $options = array(
      '' => '- ' . t('All') . ' -',
      '-1' => '-1',
      '0' => '0',
      '1' => '1',
      '2' => '2',
      '3' => '3',
    );
    $form['hierarchy_level'] = array(
      '#type' => 'select',
      '#title' => t('Hierarchy level'),
      '#options' => $options,
      '#default_value' => $this->options['hierarchy_level'],
    );
  }

  function options_validate(&$form, &$form_state) {
    parent::options_validate($form, $form_state);

    $values = $form_state['values']['options']['argument_default']['taxonomy_tid'];
    if (!empty($values['count']) && !is_numeric($values['count'])) {
      form_set_error('count', t('The maximum number of terms must be a number or blank.'));
    }
  }

  /*
  function options_submit(&$form, &$form_state, &$options = array()) {
    // Filter unselected items so we don't unnecessarily store giant arrays.
    $options['vocabularies'] = array_filter($options['vocabularies']);
  }
  */

  function get_argument() {
    $arg = parent::get_argument();

    if (!empty($this->options['hierarchy_level']) || !empty($this->options['count'])) {
      $tids = explode('+', $arg);

      if (!empty($this->options['hierarchy_level'])) {
        $terms = array();
        foreach ($tids as $tid) {
          $terms[$tid] = taxonomy_term_load($tid);
        }
        $bottom_level = 0;
        $terms = enterprise_rel_get_terms_levels($terms, $bottom_level);
        $level = (int)$this->options['hierarchy_level'];
        if ($level < 0) {
          $level = $bottom_level + 1 + $level;
        }

        foreach ($tids as $i => $tid) {
          if ($terms[$tid]->level != $level) {
            unset($tids[$i]);
          }
        }
      }

      if (!empty($this->options['count'])) {
        array_splice($tids, $this->options['count']);
      }

      $arg = implode('+', $tids);
    }

    return $arg;
  }
}
