<?php
/**
 * @file
 * enterprise_satsurvey.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enterprise_satsurvey_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enterprise_satsurvey';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Satisfaction Survey Submissions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Satisfaction Surveys';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'serial' => 'serial',
    'value' => 'value',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'serial' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Webform submissions: Serial number */
  $handler->display->display_options['fields']['serial']['id'] = 'serial';
  $handler->display->display_options['fields']['serial']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['serial']['field'] = 'serial';
  $handler->display->display_options['fields']['serial']['label'] = 'SID';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['webform_nid'] = '40';
  $handler->display->display_options['fields']['value']['webform_cid'] = '3';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['label'] = 'Work';
  $handler->display->display_options['fields']['value_3']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_3']['webform_nid'] = '40';
  $handler->display->display_options['fields']['value_3']['webform_cid'] = '7';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['label'] = '';
  $handler->display->display_options['fields']['value_1']['webform_nid'] = '40';
  $handler->display->display_options['fields']['value_1']['webform_cid'] = '6';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['label'] = 'Score';
  $handler->display->display_options['fields']['value_2']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_2']['webform_nid'] = '40';
  $handler->display->display_options['fields']['value_2']['webform_cid'] = '5';
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['label'] = 'Ops';
  $handler->display->display_options['fields']['view_submission']['access_check'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/people/sat-surveys';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Satisfaction surveys';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Work Page */
  $handler = $view->new_display('page', 'Work Page', 'work_page');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Webform submissions: Data */
  $handler->display->display_options['relationships']['data']['id'] = 'data';
  $handler->display->display_options['relationships']['data']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['data']['field'] = 'data';
  $handler->display->display_options['relationships']['data']['label'] = 'Work';
  $handler->display->display_options['relationships']['data']['webform_nid'] = '40';
  $handler->display->display_options['relationships']['data']['webform_cid'] = '7';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Webform submission data: Data field (numeric) */
  $handler->display->display_options['arguments']['data_numeric']['id'] = 'data_numeric';
  $handler->display->display_options['arguments']['data_numeric']['table'] = 'webform_submitted_data';
  $handler->display->display_options['arguments']['data_numeric']['field'] = 'data_numeric';
  $handler->display->display_options['arguments']['data_numeric']['relationship'] = 'data';
  $handler->display->display_options['arguments']['data_numeric']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['data_numeric']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['data_numeric']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['data_numeric']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['data_numeric']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['data_numeric']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['data_numeric']['validate_options']['types'] = array(
    'enterprise_work' => 'enterprise_work',
  );
  $handler->display->display_options['arguments']['data_numeric']['validate']['fail'] = 'ignore';
  $handler->display->display_options['path'] = 'node/%/surveys';
  $handler->display->display_options['menu']['title'] = 'Sat Surveys';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['enterprise_satsurvey'] = $view;

  return $export;
}
