<?php
/**
 * @file
 * Generates author reports
 * 
 * @author Tom McCracken <tomm@getlevelten.com>
 */

function intel_page_attribute_list_report_page($report_params = '-', $report_subtype = '-', $entity_type = '-', $entity = '-') {
  require_once drupal_get_path('module', 'intel') . "/includes/intel.reports.inc";
  require_once drupal_get_path('module', 'intel') . "/includes/intel.ga.inc";
  $output = '';

  $vars = intel_init_reports_vars('page_attribute_list', 'content', $report_params, $report_subtype, $entity_type, $entity);

  $output = intel_build_report($vars);

  return $output;
}

//function intel_page_attribute_list_report($filters = array(), $context = 'site', $sub_index = '-', $mode = '') {
function intel_page_attribute_list_report($vars) {
  intel_include_library_file('ga/class.ga_model.php');
  require_once drupal_get_path('module', 'intel') . "/includes/intel.page_data.inc";

  $filters = $vars['filters'];
  $context = $vars['context'];
  $context_mode = $vars['context_mode'];

  $report_mode = $vars['report_info']['key'];

  //$reports = intel_reports();
  //$report_mode = $reports['content'][$sub_index]['key'];
  $report_modes = explode('.', $report_mode);

  $a = explode(':', $report_modes[0]);
  $attr_key = $a[1];

  $attr_info = intel_get_page_attribute_info($attr_key);
  $vars['attribute_info']['page'][$attr_key] = $attr_info;
  $indexBy = 'pageAttribute:' . $attr_key;

  //dsm($attr_info);
  //dsm($report_modes);

  $cache_options = array();
  $row_count = 100;
  // user larger than default number of result rows to get larger sampling
  // needed since data is summed across customVar strings (i.e. page) in
  // segment
  $feed_rows = 50 * $row_count;
  
  $output = '';    

  $timeops = $vars['timeframe'];
  //$timeops = 'yesterday';
  list($start_date, $end_date, $number_of_days) = _intel_get_report_dates_from_ops($timeops, $cache_options);

  $ga_data = new LevelTen\Intel\GAModel();
  $ga_data->setContext($vars['context']);
  $ga_data->setContextMode($vars['context_mode']);
//$ga_data->setDebug(1);
  $ga_data->setAttributeInfoAll($vars['attribute_info']);
  $ga_data->buildFilters($filters, $vars['subsite']);

  //dsm($ga_data->gaFilters);


  //$ga_data->addGAFilter('ga:customVarValue1!@&a=1&');

  $ga_data->setDateRange($start_date, $end_date);
  $ga_data->setRequestCallback('intel_ga_feed_request_callback', array('cache_options' => $cache_options));
  // set advancedSort to get better mix of data for pageviews and entraces
  $ga_data->setAdvancedSort(1);

  //$ga_data->setDataIndexCallback('category', '_intel_determine_category_index');

  $ga_data->setRequestSetting('indexBy', $indexBy);
  $ga_data->setRequestSetting('context', $vars['context']);

  // build pagepath map
  $ga_data->setRequestDefaultParam('max_results', 2 * $feed_rows);
  $ga_data->loadFeedData('entrances_pagepathmap');

  $ga_data->setRequestSetting('details', 0);
  $ga_data->setRequestDefaultParam('max_results', 2 * $feed_rows);
  $ga_data->loadFeedData('pageviews');

  $ga_data->setRequestDefaultParam('max_results', 1 * $feed_rows);
  $ga_data->loadFeedData('entrances');

  // advanced sort not needed for valued events
  $ga_data->setAdvancedSort(0);

  $ga_data->setRequestDefaultParam('max_results', 2 * $feed_rows);
  $ga_data->loadFeedData('pageviews_valuedevents');
  
  $ga_data->setRequestDefaultParam('max_results', 2 * $feed_rows);
  $ga_data->loadFeedData('entrances_valuedevents');
  
  $d = $ga_data->data;

  $data_options = array(
    'page_count' => 1,
  );
  foreach ($d[$indexBy] AS $index => $de) {
    if (empty($de['i']) || (substr($de['i'], 0 , 1) == '_')) { 
      continue; 
    }

    if (($attr_info['type'] == 'item') || ($attr_info['type'] == 'scalar')) {
      $optionInfo = intel_get_attribute_option_info('page', $attr_key, $de['i'], $data_options);
    }
    else if ($attr_info['type'] == 'list') {
      $optionInfo = intel_get_attribute_option_info('page', $attr_key, $de['i'], $data_options);
    }
    if (!empty($optionInfo['title'])) {
      $d[$indexBy][$index]['info'] = $optionInfo;
    }
  }

  foreach ($d[$indexBy] AS $index => $de) {
    $score_components = array();
    $d[$indexBy][$index]['score'] = intel_score_page_aggregation($de, 1, $score_components);
    $d[$indexBy][$index]['score_components'] = $score_components;
    if (isset($de['i'])) {
      $val = $de['i'];
      $params = $vars['report_params'];
      $params['ft'] = 'page-attr';
      $params['f'] = $attr_key . ':' . urlencode($val);
      $d[$indexBy][$index]['links'] = array();
      $d[$indexBy][$index]['links'][] = l(t('scorecard'), intel_build_report_path('scorecard', $params));
      //$d[$indexBy][$index]['links'][] = l(t('content'), intel_build_report_path('content', $params));
      $d[$indexBy][$index]['links'][] = l(t('sources'), intel_build_report_path('trafficsource', $params));
      $d[$indexBy][$index]['links'][] = l(t('visitors'), intel_build_report_path('visitor', $params));
    }
  }

//dsm($d);

  $vars = array(
    'data' => $d,
    'row_count' => $row_count,
    'number_of_days' => $number_of_days,
    'start_date' => $start_date,
    'end_date' => $end_date,
    'context' => $context,
    'context_mode' => $context_mode,
    'report_modes' => $report_modes,
    'attr_info' => $attr_info,
    'indexBy' => $indexBy,
  );
  $output .= theme_intel_page_attribute_list_report($vars);

  $output .= t("Timeframe: %start_date - %end_date %refresh", array(
    '%start_date' => date("Y-m-d H:i", $start_date),
    '%end_date' => date("Y-m-d H:i", $end_date),
    '%refresh' => (!empty($cache_options['refresh'])) ? '(refresh)' : '',
  ));  
  
  return $output;  
}

/*
function intel_scorecard_apply_filters_to_request($request, $filterstr, $segmentstr) {
  if ($filterstr) {
    $request['filters'] .= (($request['filters']) ? ';' : '') . $filterstr;
  }
  if ($segmentstr) {
    $request['segment'] .= (($request['segment']) ? ';' : '') . $segmentstr;
  }
  return $request;
}
*/

function theme_intel_page_attribute_list_report($vars) {
  intel_include_library_file('reports/class.page_attribute_report_view.php');
  
  $output = '';

  $report_view = new LevelTen\Intel\PageAttributeReportView();
  $report_view->setData($vars['data']);
  $report_view->setTableRowCount($vars['row_count']);
  $report_view->setModes($vars['report_modes']);
  $report_view->setParam('context', $vars['context']);
  $report_view->setParam('context_mode', $vars['context_mode']);
  $report_view->setDateRange($vars['start_date'], $vars['end_date']);
  $report_view->setTargets(intel_get_targets());
  $report_view->setAttributeInfo($vars['attr_info']);
  \LevelTen\Intel\ReportPageHeader::setAddScriptCallback('intel_report_add_js_callback');
  $output .= $report_view->renderReport();
  
  return $output;
}