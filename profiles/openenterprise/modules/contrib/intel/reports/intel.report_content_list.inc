<?php
/**
 * @file
 * Generates content reports
 * 
 * @author Tom McCracken <tomm@getlevelten.com>
 */

function intel_content_list_report_page($report_params = '-', $report_subtype = '-', $entity_type = '-', $entity = '-') {
  require_once drupal_get_path('module', 'intel') . "/includes/intel.reports.inc";
  require_once drupal_get_path('module', 'intel') . "/includes/intel.ga.inc";
  $output = '';

  $vars = intel_init_reports_vars('content_list', 'content', $report_params, $report_subtype, $entity_type, $entity);

  $output = intel_build_report($vars);

  return $output;
}

//function intel_content_list_report($filters = array(), $context = 'site', $report_mode = '-', $mode = '') {
function intel_content_list_report($vars) {
  intel_include_library_file('ga/class.ga_model.php');
  require_once drupal_get_path('module', 'intel') . "/includes/intel.page_data.inc";

  $filters = $vars['filters'];
  $context = $vars['context'];
  $context_mode = $vars['context_mode'];

  $report_mode = !empty($vars['report_info']['key']) ? $vars['report_info']['key'] : 'default.top.combined';
  $report_modes = explode('.', $report_mode);
  
  $cache_options = array();
  // number of rows in report 
  $row_count = 100;
  // number of rows needed in data feed
  $feed_rows = 2 * $row_count;
  if ($report_modes[0] == 'engagement') {
    $feed_rows *= 4;
  }
  
  $output = '';    

  /*
  if (!empty($filters['page'])) {
    $a = explode(":", $filters['page']);
    $path = $a[1];
  }
  */

  $timeops = $vars['timeframe'];
  //$timeops = 'yesterday';
  list($start_date, $end_date, $number_of_days) = _intel_get_report_dates_from_ops($timeops, $cache_options);
  
  $ga_data = new LevelTen\Intel\GAModel();
  $ga_data->setContext($vars['context']);
  $ga_data->setContextMode($vars['context_mode']);
  $ga_data->setReportModes($report_modes);
  $ga_data->setAttributeInfoAll($vars['attribute_info']);
  $ga_data->buildFilters($filters, $vars['subsite']);
  $ga_data->setDateRange($start_date, $end_date);
  $ga_data->setRequestCallback('intel_ga_feed_request_callback', array('cache_options' => $cache_options));
//$ga_data->setDebug(1);
//dsm($context);  
//dsm($ga_data->gaFilters); 
  //$ga_data->setDataIndexCallback('category', '_intel_determine_category_index');  

  $ga_data->setRequestSetting('indexBy', 'content');
  $ga_data->setRequestSetting('details', 0);

  //$ga_data->setDebug(1);
  // base pageview/entrance data
  if (($report_modes[0] != 'social') && ($report_modes[0] != 'seo')) {
    $ga_data->setRequestDefaultParam('max_results', 2 * $feed_rows);
    $ga_data->loadFeedData('pageviews'); 
  }

  //$ga_data->setDebug(0);

  if (($report_modes[0] != 'social') && ($report_modes[0] != 'seo')) {
    $ga_data->setRequestDefaultParam('max_results', 2 * $feed_rows);
    $ga_data->loadFeedData('entrances');
  }

  // events data
//$ga_data->setDebug(1);
  $use_default = 1;
  if (($report_modes[0] == 'engagement') || ($report_modes[0] == 'social')) {
    $ga_data->setRequestSetting('details', 1);
    $ga_data->setRequestDefaultParam('max_results', 5 * $feed_rows);    
    $ga_data->loadFeedData('pageviews_valuedevents');
    $use_default = 0;
  }
  elseif ($report_modes[0] == 'social') {
    $use_default = 0;
  }
  if ($use_default) {
    $ga_data->setRequestSetting('details', 0);
    $ga_data->setRequestDefaultParam('max_results', 2 * $feed_rows);    
    $ga_data->loadFeedData('pageviews_valuedevents');
    
    $ga_data->setRequestDefaultParam('max_results', $feed_rows);
    $ga_data->loadFeedData('entrances_valuedevents');
  }
  
  // referrer data
//$ga_data->setDebug(1); 
  if ($report_modes[0] == 'seo') {
    $ga_data->setRequestSetting('details', 0);
    $ga_data->setRequestDefaultParam('max_results', $feed_rows);  
    $ga_data->setRequestSetting('subIndexBy', 'organicSearch');
    $ga_data->loadFeedData('entrances');
    
    $ga_data->setRequestSetting('details', 1);
    $ga_data->setRequestDefaultParam('max_results', 5 * $feed_rows);  
    $ga_data->setRequestSetting('subIndexBy', 'searchKeyword');
    $ga_data->loadFeedData('entrances');
  }
  elseif ($report_modes[0] == 'social') {
    $ga_data->setRequestSetting('details', 1);
    $ga_data->setRequestDefaultParam('max_results', 10 * $feed_rows);  
    $ga_data->setRequestSetting('subIndexBy', 'socialNetwork');
    $ga_data->loadFeedData('entrances');
  }

  $d = $ga_data->data;
//dsm($data);

  foreach ($d['content'] AS $index => $de) {
    $score_components = array();

    if ($report_modes[0] == 'seo') {
      //$d['content'][$index]['score'] = intel_score_visit_aggregation($de, 1, $score_components, 'seo');
      $d['content'][$index]['score'] = intel_score_item($de, 1, $score_components, 'seo', 'entrance');
    }
    elseif ($report_modes[0] == 'social') {
      //$d['content'][$index]['score'] = intel_score_visit_aggregation($de, 1, $score_components, 'social');
      $d['content'][$index]['score'] = intel_score_item($de, 1, $score_components, 'social', 'entrance');
      $d['content'][$index]['score'] += $d['content'][$index]['pageview']['events']['_all']['value'];  
    }
    elseif ($report_modes[0] == 'engagement') {
      $d['content'][$index]['score'] = $d['content'][$index]['pageview']['events']['_all']['value'];      
    }
    else {
      if ($context == 'page' || $context == 'page-attr') {
        $d['content'][$index]['score'] = intel_score_item($de, 1, $score_components, '', 'page');
      }
      else { 
        $d['content'][$index]['score'] = intel_score_item($de, 1, $score_components, '', 'site');
      }
    } 
    $d['content'][$index]['score_components'] = $score_components;  
    if (isset($de['i'])) {
      $params = $vars['report_params'];
      $params['ft'] = 'page';
      $u = explode('/', $de['i'], 2);
      $uri = isset($u[1]) ? '/' . $u[1] : '/';
      $uri = str_replace('/', '|', $uri);
      $params['f'] = 'pagePath:' . urlencode($uri);
      $d['content'][$index]['links'] = array();
      $d['content'][$index]['links'][] = l(t('scorecard'), intel_build_report_path('scorecard', $params));
      $d['content'][$index]['links'][] = l(t('sources'), intel_build_report_path('trafficsource', $params));
      $d['content'][$index]['links'][] = l(t('visitors'), intel_build_report_path('visitor', $params));
    }
  }

//dsm($d);

  // order date data cronologically
  //ksort($d['content']);
  $vars = array(
    'data' => $d,
    'row_count' => $row_count,
    'number_of_days' => $number_of_days,
    'start_date' => $start_date,
    'end_date' => $end_date,
    'targets' => intel_get_targets(),
    'context' => $context,
    'context_mode' => $context_mode,
    'report_modes' => $report_modes,
  );
  $output .= theme_intel_content_list_report($vars);

  $output .= t("Timeframe: %start_date - %end_date %refresh", array(
    '%start_date' => date("Y-m-d H:i", $start_date),
    '%end_date' => date("Y-m-d H:i", $end_date),
    '%refresh' => (!empty($cache_options['refresh'])) ? '(refresh)' : '',
  ));  
  
  return $output;  
}

function theme_intel_content_list_report($vars) {
  intel_include_library_file("reports/class.content_report_view.php");
  
  $output = '';

  $report_view = new levelten\intel\ContentReportView();
  $report_view->setData($vars['data']);
  $report_view->setTableRowCount($vars['row_count']);
  $report_view->setModes($vars['report_modes']);
  $report_view->setParam('context', $vars['context']);
  $report_view->setParam('context_mode', $vars['context_mode']);
  $report_view->setDateRange($vars['start_date'], $vars['end_date']);
  $report_view->setPageMetaCallback('intel_get_page_meta_callback');
  $report_view->setTargets(intel_get_targets());
  \LevelTen\Intel\ReportPageHeader::setAddScriptCallback('intel_report_add_js_callback');
  $output .= $report_view->renderReport();
  
  return $output; 
}