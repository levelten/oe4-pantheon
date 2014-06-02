<?php
/**
 * @file
 * Generates author reports
 * 
 * @author Tom McCracken <tomm@getlevelten.com>
 */

function intel_page_attribute_list_report_page($sub_index = '-', $filter_type = '', $filter_element = '') {
  $output = '';
  $filters = array();
  $context = 'site';
  $reports = intel_reports();
  
  if ($filter_type) {
    $filters[$filter_type] = urldecode($filter_element);
    $context = $filter_type;
  }  
  require_once drupal_get_path('module', 'intel') . "/includes/intel.ga.inc";  
  
  if (empty($_GET['return_type']) || ($_GET['return_type'] == 'nonajax')) {
    intel_add_report_headers();

    drupal_set_title(t('@title report', array('@title' => $reports['content'][$sub_index]['title'])), PASS_THROUGH);
    $filters += $_GET;
    $filter_form = drupal_get_form('intel_report_filters_form', $filters, $context);
    $output .= drupal_render($filter_form);  
  }
  
  if (empty($_GET['return_type'])) {
    $output .= intel_get_report_ajax_container();
  }
  elseif ($_GET['return_type'] == 'nonajax') {
    $output .= intel_page_attribute_list_report($filters, $context, $sub_index);
  }
  elseif ($_GET['return_type'] == 'json') {
    $data = array(
      'report' => intel_page_attribute_list_report($filters, $context, $sub_index),
    );
    drupal_json_output($data);
    return;    
  }  
   
  return $output;
}

function intel_page_attribute_list_report($filters = array(), $context = 'site', $sub_index = '-', $mode = '') {
  intel_include_library_file('ga/class.ga_model.php');
  require_once drupal_get_path('module', 'intel') . "/includes/intel.page_data.inc";

  $reports = intel_reports();
  $report_mode = $reports['content'][$sub_index]['key'];
  $report_modes = explode('.', $report_mode);

  $a = explode(':', $report_modes[0]);
  $attr_key = $a[1];

  $attr_info = intel_page_attribute_load($attr_key);
  $indexBy = 'pageAttribute:' . $attr_key;

  //dsm($attr_info);
  //dsm($report_modes);

  $cache_options = array();
  $row_count = 100;
  $feed_rows = 2 * $row_count;
  
  $output = '';    

  $timeops = 'l30d';
  //$timeops = 'yesterday';
  list($start_date, $end_date, $number_of_days) = _intel_get_report_dates_from_ops($timeops, $cache_options);
  
  $ga_data = new LevelTen\Intel\GAModel();
  $ga_data->setPageAttributeInfo($attr_info);
  $ga_data->buildFilters($filters, $context);

  //$ga_data->addGAFilter('ga:customVarValue1!@&a=1&');

  $ga_data->setDateRange($start_date, $end_date);
  $ga_data->setRequestCallback('intel_ga_feed_request_callback', array('cache_options' => $cache_options));

  //$ga_data->setDataIndexCallback('category', '_intel_determine_category_index');
  //$ga_data->setDebug(1);

  $ga_data->setRequestSetting('indexBy', $indexBy);
  $ga_data->setRequestSetting('details', 0);
  $ga_data->setRequestDefaultParam('max_results', 2 * $feed_rows);
  $ga_data->loadFeedData('pageviews');

  $ga_data->setRequestDefaultParam('max_results', 1 * $feed_rows);
  $ga_data->loadFeedData('entrances');
  
  $ga_data->setRequestDefaultParam('max_results', 2 * $feed_rows);
  $ga_data->loadFeedData('pageviews_valuedevents');

  $ga_data->loadFeedData('entrances_valuedevents');
  
  $d = $ga_data->data;

//dsm($d);

  foreach ($d[$indexBy] AS $index => $de) {
    $score_components = array();
    $d[$indexBy][$index]['score'] = intel_score_page_aggregation($de, 1, $score_components);
    $d[$indexBy][$index]['score_components'] = $score_components;
  }   

  $data_options = array(
    'page_count' => 1,
  );
  foreach ($d[$indexBy] AS $index => $de) {
    if (empty($de['i']) || (substr($de['i'], 0 , 1) == '_')) { 
      continue; 
    }

    if (($attr_info['type'] == 'scalar') || ($attr_info['type'] == 'value')) {
      $optionInfo = intel_get_attribute_option('page', $attr_key, $de['i'], $data_options);
    }
    else if ($attr_info['type'] == 'list') {
      $a = explode('.', $de['i']);
      $optionInfo = intel_get_attribute_option('page', $attr_key, $a[1], $data_options);
    }
    if (!empty($optionInfo['title'])) {
      $d[$indexBy][$index]['info'] = $optionInfo;
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
  $report_view->setDateRange($vars['start_date'], $vars['end_date']);
  $report_view->setTargets(intel_get_targets());
  $report_view->setAttributeInfo($vars['attr_info']);
  \LevelTen\Intel\ReportPageHeader::setAddScriptCallback('intel_report_add_js_callback');
  $output .= $report_view->renderReport();
  
  return $output;
}