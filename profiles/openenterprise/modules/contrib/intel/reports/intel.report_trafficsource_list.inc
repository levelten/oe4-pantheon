<?php
/**
 * @file
 * Generates traffic source reports
 * 
 * @author Tom McCracken <tomm@getlevelten.com>
 */

function intel_trafficsource_list_report_page($report_params = '-', $report_subtype = '-', $entity_type = '-', $entity = '-') {
  require_once drupal_get_path('module', 'intel') . "/includes/intel.reports.inc";
  require_once drupal_get_path('module', 'intel') . "/includes/intel.ga.inc";
  $output = '';

  $vars = intel_init_reports_vars('trafficsource_list', 'trafficsource', $report_params, $report_subtype, $entity_type, $entity);

  $output = intel_build_report($vars);

  return $output;
}

//function intel_trafficsource_list_report($filters = array(), $context = 'site', $sub_index = '-') {
function intel_trafficsource_list_report($vars) {
  intel_include_library_file('ga/class.ga_model.php');

  $filters = $vars['filters'];
  $sub_index = $vars['report_subtype'];
  $context = $vars['context'];
  $context_mode = $vars['context_mode'];

  $report_mode = $vars['report_info']['key'];
  $report_modes = explode('.', $report_mode);
  $indexBy = $report_modes[0];
  $indexByLabel = $vars['report_info']['title'];
//dsm($indexBy);

  $cache_options = array();
  $row_count = 100;
  $feed_rows = 2 * $row_count;
  
  $output = '';

  /*
  if (!empty($filters['page'])) {
    $a = explode(":", $filters['page']);
    $path = $a[1];
  }
  */

  $timeops = 'l30d';
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
  $ga_data->setRequestSetting('indexBy', $indexBy);
  $ga_data->setRequestSetting('details', 0);
  
  if ($indexBy == 'trafficcategory') {
    $ga_data->setRequestDefaultParam('max_results', 10 * $feed_rows);
  }
  else {
    $ga_data->setRequestDefaultParam('max_results', 2 * $feed_rows);
  }
  $ga_data->loadFeedData('entrances'); 
  $ga_data->loadFeedData('entrances_valuedevents');  

  $d = $ga_data->data;

  // append array if no data exists
  $d += array(
    'trafficcategory' => array(),
    'medium' => array(),
    'source' => array(),
    'referralHostpath' => array(),
    'socialNetwork' => array(),
    'searchKeyword' => array(),
    'keyword' => array(),
    'campaign' => array(),
  );

  foreach ($d[$indexBy] AS $index => $de) {
    $score_components = array();
    //$d[$indexBy][$index]['score'] = intel_score_visit_aggregation($de, 1, $score_components);
    $d[$indexBy][$index]['score'] = intel_score_item($de, 1, $score_components, '', 'entrance');
    $d[$indexBy][$index]['score_components'] = $score_components;
    if (empty($de['i'])) {
      continue;
    }

    if (isset($de['i'])) {
      $d[$indexBy][$index]['links'] = array();
      $val = $de['i'];
      // encode paths in filters
      if ($indexBy == 'referralHostpath') {
        $val = str_replace('/', '|', $val);
      }
      $params = $vars['report_params'];
      $params['ft'] = 'trafficsource';
      $params['f'] = $indexBy . ':' . urlencode($val);

      $d[$indexBy][$index]['links'][] = l(t('scorecard'), intel_build_report_path('scorecard', $params));
      $d[$indexBy][$index]['links'][] = l(t('content'), intel_build_report_path('content', $params));
      $d[$indexBy][$index]['links'][] = l(t('visitors'), intel_build_report_path('visitor', $params));
    }
  }    

  // order date data cronologically
  //ksort($d['content']);
  
//dsm($d);
  
  $vars = array(
    'data' => $d,
    'row_count' => $row_count,
    'number_of_days' => $number_of_days,
    'start_date' => $start_date,
    'end_date' => $end_date,
    'targets' => intel_get_targets(),
    'analysis_days' => $number_of_days,
    'context' => $context,
    'context_mode' => $context_mode,
    'indexBy' => $indexBy,
    'indexByLabel' => $indexByLabel,
    'report_modes' => $report_modes,
  );
  $output .= theme_intel_trafficsource_list_report($vars);

  $output .= t("Timeframe: %start_date - %end_date %refresh", array(
    '%start_date' => date("Y-m-d H:i", $start_date),
    '%end_date' => date("Y-m-d H:i", $end_date),
    '%refresh' => (!empty($cache_options['refresh'])) ? '(refresh)' : '',
  ));  
  
  return $output;  
}

function theme_intel_trafficsource_list_report($vars) {
  intel_include_library_file("reports/class.trafficsource_report_view.php");
  
  $output = '';

  $report_view = new LevelTen\Intel\TrafficsourceReportView();
  $report_view->setData($vars['data']);
  $report_view->setTableRowCount($vars['row_count']);
  $report_view->setModes($vars['report_modes']);
  $report_view->setParam('context', $vars['context']);
  $report_view->setParam('context_mode', $vars['context_mode']);
  $report_view->setParam('indexBy', $vars['indexBy']);
  $report_view->setParam('indexByLabel', $vars['indexByLabel']);
  $report_view->setDateRange($vars['start_date'], $vars['end_date']);
  $report_view->setTargets(intel_get_targets());
  \LevelTen\Intel\ReportPageHeader::setAddScriptCallback('intel_report_add_js_callback');
  $output .= $report_view->renderReport();
  
  return $output; 
}