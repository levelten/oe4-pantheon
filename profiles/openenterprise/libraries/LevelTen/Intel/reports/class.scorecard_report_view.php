<?php
/**
 * @file
 * @author  Tom McCracken <tomm@levelten.net>
 * @version 1.0
 * @copyright 2013 LevelTen Ventures
 * 
 * @section LICENSE
 * All rights reserved. Do not use without permission.
 * 
 */
namespace LevelTen\Intel;
require_once 'class.report_view.php';
require_once __DIR__ . '/../charts/class.line_chart.php';
require_once __DIR__ . '/../charts/class.table_chart.php';
require_once __DIR__ . '/../charts/class.pie_chart.php';
require_once __DIR__ . '/../charts/class.column_chart.php';
require_once __DIR__ . '/../charts/class.combo_chart.php';

class ScorecardReportView extends ReportView {
  private $tableRowCount = 5;
  private $objectives = array();
  
  function __construct() {
    parent::__construct();
  }
  
  function setTableRowCount($rowCount) {
    $this->tableRowCount = $rowCount;
  }
  
  function setObjective($key, $value) {
    $this->objectives[$key] = $value;
  }
  
  function getTrafficCategories() {
    $c = array(
      'direct' => 'direct',
      'organic search' => 'organic',
      'social network' => 'social',
      'referral link' => 'referral',      
      'feed' => 'feed',
    );
    return $c;
  }
  
  function getConversionGoals() {
    $g = array(
      'n6' => 'ToFu conversion',
      'n7' => 'MoFu conversion',
      'n8' => 'BoFu conversion',
      'n1' => 'Contact form',
    );
    return $g;
  }
  
  function getEngagementEvents() {
    $e = array(
      'Social share!' => 'social shares',
      'Comment!' => 'comments',
      //'CTA click!' => 'cta clicks',
    );
    return $e;
  }
  
  function renderReport() {
    $output = '';
    
    $context = $this->params['context'];
    $context_mode = $this->params['context_mode'];
    
    $output .= $this->renderMainChart();
    
    $output .= $this->renderSummarySection();
    
    $output .= $this->renderGoalsSection();
    
    if ($context != 'page') {
      $output .= $this->renderContentSection();
    }
    
    if ($context != 'trafficsource') {
      $output .= $this->renderTrafficsourceSection();
    }
    
    $output .= 'generated by <a href="http://levelten.net" target="_blank">LevelTen Intelligence</a>';
    
    return '<div id="intel-report">' . $output . '</div>';    
  }
  
  function renderMainChart() {
    $output = '';
    $data = $this->data;

    $context = $this->params['context'];
    $context_mode = $this->params['context_mode'];
    $main_chart = new ComboChart('objectives');
    //$entrances_chart->setOption('title', 'Performance');
    $main_chart->addColumn('date', 'day');
    //$main_chart->setColumnElement(0, 'pattern', 'MMM d');
    $main_chart->addColumn('number', 'Entrances');
    $main_chart->addColumn('number', 'Additional pageviews');
    $main_chart->addColumn('number', 'Goal value');
    $main_chart->addColumn('number', 'Event value');
    $main_chart->addColumn('number', 'Traffic value');
      
    foreach ($data['date'] AS $day => $d) {
      if (substr($day, 0 ,1) == '_') {
        continue;
      }
      $ts = strtotime($day);
      $jstime = 1000*$ts;
   
      $main_chart->newWorkingRow();
      $main_chart->addRowItem($jstime);
      $main_chart->addRowItem($d['entrance']['entrances']);
      $main_chart->addRowItem(round($d['pageview']['pageviews'] - $d['entrance']['entrances']));
      $main_chart->addRowItem($d['score_components']['_all']['goals']);
      $main_chart->addRowItem($d['score_components']['_all']['events']);
      $main_chart->addRowItem($d['score_components']['_all']['traffic']);
      $main_chart->addRowToSettings();
    } 
  
    $main_chart->setOption('isStacked', 1);
    $series = array(
      'type' => "area",
      'color' => $this->chartColors[0],
      'pointSize' => 6,
      'lineWidth' => 3,
      'areaOpacity' => 0.1,  
    );
    $main_chart->setOption('series.0', $series);
    $series = array(
      'type' => "line",
      'color' => $this->chartColorsCompliments[0][0],
      'pointSize' => 6,
      'lineWidth' => 3,
      'areaOpacity' => 0.1,  
    );
    $main_chart->setOption('series.1', $series);
    $series = array(
      'type' => "bars",
      'color' => $this->chartColors[1],
    );
    $main_chart->setOption('series.2', $series);
    $series = array(
      'type' => "bars",
      'color' => $this->chartColorsCompliments[1][0],
    );
    $main_chart->setOption('series.3', $series);
    $series = array(
      'type' => "bars",
      'color' => $this->chartColorsCompliments[1][1],
    );
    $main_chart->setOption('series.4', $series);
  
    $output = '<div id="report-main-chart">';
    $output .= $main_chart->renderOutput();
    $output .= '</div>';
  
    return $output;
  }
  
  function renderSummarySection() {
    $output = '';
    $data = $this->data;

    $datasum = $data['date']['_all'];
    $context = $this->params['context'];
    $context_mode = $this->params['context_mode'];
    $targets = $this->targets;
    $analysis_days = $this->params['analysis_days'];
    $statusColorsBg = $this->statusColorsBackground;
    $statusColors = $this->statusColors;
    $summary_elements = array();

    $visitTitle = 'Visit';
    $visitTitleAbv = 'Visit';
    $visitDataKeys = 'entrance.entrances';
    $visitDataIndexes = array('entrance', 'entrances');
    if ($context_mode == 'subsite') {
      $visitDataKeys = 'session.sessions';
      $visitDataIndexes = array('session', 'sessions');
    }
    else if ($context == 'page' || $context == 'page-attr') {
      $visitTitle = 'Entrance';
      $visitTitleAbv = 'Entr';
    }

    $init_e = array(
      'data' => $data['date'],
      'linecolor' => $this->chartColors[0],
    );
  
    $value = $datasum['score'] / $analysis_days;
    $status = 'complete';
    if ($value < $targets['value_per_page_per_day']) {
      $status = 'warning';
    }
    if ($value < $targets['value_per_page_per_day_warning']) {
      $status = 'error';
    }
    $e = $init_e;
    $e['linecolor'] = $statusColors[$status];
    $e['bgcolor'] = $statusColorsBg[$status];
    $e['keys'] = 'score';
    $e['title'] = 'Value/Day';
    $e['total'] = number_format($value, 2);
    $summary_elements['value_per_day'] = self::renderSparklineValueElement($e);

    $value = $datasum[$visitDataIndexes[0]][$visitDataIndexes[1]] / $analysis_days;

    $status = 'complete';
    if ($value < $targets['entrances_per_page_per_day']) {
      $status = 'warning';
    }
    if ($value < $targets['entrances_per_page_per_day_warning']) {
      $status = 'error';
    }
    $e = $init_e;
    $e['linecolor'] = $statusColors[$status];
    $e['bgcolor'] = $statusColorsBg[$status];
    if ($context_mode == 'subsite') {
      $e['keys'] = 'session.sessions';
      $e['title'] = 'Visits/Day';
    }
    else {
      $e['keys'] = 'entrance.entrances';
      $e['title'] = 'Entrances/Day';
    }

    $e['total'] = number_format($value, 1);
    $summary_elements['entrances_per_day'] = self::renderSparklineValueElement($e);

    !empty($datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]) ? ($datasum['score'] / $datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]) : 0;

    $status = 'complete';
    if ($value < $targets['value_per_page_per_entrance']) {
      $status = 'warning';
    }
    if ($value < $targets['value_per_page_per_entrance_warning']) {
      $status = 'error';
    }
    $e = $init_e;
    $e['linecolor'] = $statusColors[$status];
    $e['bgcolor'] = $statusColorsBg[$status];
    $e['keys'] = 'score';
    $e['keys2'] = $visitDataKeys;
    $e['keys_operator'] = '/';
    $e['format'] = array(
      'type' => 'money',
      'decimals' => 2,
    );
    $e['title'] = 'Value/' . $visitTitleAbv;
    $total = !empty($datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]) ? ($datasum['score'] / $datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]) : 0;
    $e['total'] = '$' . number_format($total, 2);
    $summary_elements['valuePerVisit'] = self::renderSparklineValueElement($e);

    $e = $init_e;
    $e['keys'] = $visitDataKeys;
    $e['title'] = $visitTitle . 's';
    $e['total'] = number_format($datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]);
    $summary_elements['visits'] = self::renderSparklineValueElement($e);

    if ($context_mode == 'subsite') {
      $e = $init_e;
      $e['keys'] = 'entrance.entrances';
      $e['title'] = 'Entrances';
      $e['total'] = number_format($datasum['entrance']['entrances']);
      $summary_elements['entrances'] = self::renderSparklineValueElement($e);
    }

    $e['keys'] = 'pageview.pageviews';
    $e['title'] = 'Pageviews';
    $e['total'] = number_format($datasum['pageview']['pageviews']);
    $summary_elements['pageviews'] = self::renderSparklineValueElement($e);
    
    $e['keys'] = 'entrance.sticks';
    $e['keys2'] = 'entrance.entrances';
    $e['keys_operator'] = '/';
    $e['format'] = array(
      'type' => 'percentage',
      'decimals' => 1,
    );
    $e['title'] = 'Stick rate';
    $total = !empty($datasum['entrance']['entrances']) ? ($datasum['entrance']['sticks'] / $datasum['entrance']['entrances']) : 0;
    $e['total'] = number_format(100 * $total, 1) . "%";
    $summary_elements['stickrate'] = self::renderSparklineValueElement($e);
    
    $e = $init_e;
  
    $e['keys'] = $visitDataIndexes[0] . '.newVisits';
    $e['title'] = 'New Visits';
    $total = !empty($datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]) ? ($datasum[$visitDataIndexes[0]]['newVisits'] / $datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]) : 0;
    $e['total'] = number_format(100 * $total, 1) . "%";
    $summary_elements['percentNewVisits'] = self::renderSparklineValueElement($e);
  
    $e = $init_e;
    $e['keys'] = $visitDataIndexes[0] . '.timeOnSite';
    $e['keys2'] = $visitDataKeys;
    $e['keys_operator'] = '/';
    $e['title'] = 'Avg. Time on Site';
    $total = !empty($datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]) ? ($datasum[$visitDataIndexes[0]]['timeOnSite'] / $datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]) : 0;
    $e['total'] = self::formatDeltaTime($total);
    $summary_elements['avgTimeOnSite'] = self::renderSparklineValueElement($e);
    
    $e['keys'] = $visitDataIndexes[0] . '.pageviews';
    $e['keys2'] = $visitDataKeys;
    $e['keys_operator'] = '/';
    $e['title'] = 'Pages/' . $visitTitleAbv;
    $total = !empty($datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]) ? ($datasum['pageview']['pageviews'] / $datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]) : 0;
    $e['total'] = number_format($total, 2);
    $summary_elements['pageviewsPerSession'] = self::renderSparklineValueElement($e);
    
    $e = $init_e;
    $e['keys'] = 'score';
    $e['format'] = array(
      'type' => 'money',
      'decimals' => 2,
    );
    $e['title'] = 'Value';
    if ($data['date']['_all']['score'] > 1000) {
      $e['total'] = number_format($data['date']['_all']['score'], 0);
    }
    else {
      $e['total'] = number_format($data['date']['_all']['score'], 2);
    }
    $summary_elements['value'] = self::renderSparklineValueElement($e);
    
    $e['keys'] = 'score';
    $e['format'] = array(
      'type' => 'money',
      'decimals' => 2,
    );
    $e['title'] = 'Value/Day';
    $e['total'] = number_format($data['date']['_all']['score'] / $analysis_days, 2);
    
    $e = $init_e;
    $ib = ($context_mode == 'subsite') ? 'pageview' : 'entrance';
    $e['keys'] = $ib . '.goalCompletionsAll';
    $e['title'] = 'Goals completed';
    $e['total'] = number_format($datasum[$ib]['goalCompletionsAll']);
    $summary_elements['goals'] = self::renderSparklineValueElement($e);
    
    $e['keys2'] = $visitDataKeys;
    $e['keys_operator'] = '/';
    $e['format'] = array(
      'type' => 'percentage',
      'decimals' => 1,
    );
    $e['title'] = 'Conversion/' . $visitTitleAbv;
    $total = !empty($datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]) ? ($datasum[$ib]['goalCompletionsAll'] / $datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]) : 0;
    $e['total'] = number_format(100 * $total, 2) . '%';
    $summary_elements['goalsPerVisit'] = self::renderSparklineValueElement($e);
    
    $e = $init_e;
    $e['keys'] = 'pageview.events._all.totalValuedEvents';
    $e['title'] = 'Val. events';
    $e['total'] = number_format($datasum['pageview']['events']['_all']['totalValuedEvents']);
    $summary_elements['valuedEventsVisit'] = self::renderSparklineValueElement($e);
    
    $e['keys2'] = 'entrance.entrances';
    $e['keys_operator'] = '/';
    $e['format'] = array(
      'type' => 'percentage',
      'decimals' => 1,
    );
    $e['title'] = 'Val. events/dVisits';
    $total = !empty($datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]) ? ($datasum['pageview']['events']['_all']['totalValuedEvents'] / $datasum[$visitDataIndexes[0]][$visitDataIndexes[1]]) : 0;
    $e['total'] = number_format(100 * $total, 2);

    $summary_elements['valuedEventsPerVisit'] = self::renderSparklineValueElement($e);
    
    $output = '<div id="key-metrics-section" class="report-section">';
    $decimal = ($analysis_days < 10) ? 1 : 0;
    $output .= '<h3>' . 'Key metrics (' . number_format($analysis_days, $decimal) . ' days)</h3>';
    
    //$output = '<div class="kpis">';
    
    $output .= $summary_elements['value_per_day'];
    $output .= $summary_elements['entrances_per_day'];
    $output .= $summary_elements['valuePerVisit'];
    
    //$output .= '</div>';
    $output .= $summary_elements['visits'];
    if (isset($summary_elements['entrances'])) {
      $output .= $summary_elements['entrances'];
    }
    $output .= $summary_elements['stickrate']; 
  
    $output .= $summary_elements['pageviews'];
    $output .= $summary_elements['pageviewsPerSession'];
  
    $output .= $summary_elements['percentNewVisits'];
    $output .= $summary_elements['avgTimeOnSite']; 
    
    $output .= $summary_elements['value'];
     
    
    $output .= $summary_elements['goals'];
    $output .= $summary_elements['goalsPerVisit']; 
    
    $output .= $summary_elements['valuedEventsVisit'];
    $output .= $summary_elements['valuedEventsPerVisit']; 
    
    $output .= '</div>'; 
    
    return $output;
  }
  
  function renderGoalsSection() {
    $output = '';
    $data = $this->data;
    $datasum = $data['date']['_all'];
    $context = $this->params['context'];
    $context_mode = $this->params['context_mode'];
    $targets = $this->targets;
    $analysis_days = $this->params['analysis_days'];
    $goals = $this->goals;

    // select which context to get data from
    $goalSrc = 'pageview';
    if ($context == 'page' || $context == 'page-attr') {
      $goalSrc = 'entrance';
    }
    $eventSrc = 'pageview';
    $eventSrc2 = 'entrance';
    if ($context == 'page' || $context == 'page-attr') {
      $eventSrc = 'entrance';
      $eventSrc2 = 'pageview';
    }
    
    $pie_chart1 = new PieChart();
    $pie_chart1->addColumn('string', '');
    $pie_chart1->addColumn('number', 'Value');
    $pie_chart1->setSetting('useTotal', 1);
    if ($context == 'page' || $context == 'page-attr') {
      $total = $data['date']['_all']['entrance']['events']['_all']['value'] + $data['date']['_all']['entrance']['goalValueAll'];
    }
    else {
      $total = $data['date']['_all'][$goalSrc]['goalValueAll'];
    }
    $pie_chart1->setSetting('total', $total);
    
    if ($context != 'page' && $context != 'page-attr') {
      $pie_chart2 = new PieChart();
      $pie_chart2->addColumn('string', '');
      $pie_chart2->addColumn('number', 'Value');
      $pie_chart2->setSetting('useTotal', 1);
      $total = $data['date']['_all'][$eventSrc]['events']['_all']['value'];
      $pie_chart2->setSetting('total', $total);
    }
    
    $goals_table = new TableChart('blank');
    $goals_table->addColumn('string', 'Goals');
    $goals_table->addColumn('number', 'Completed');
    $goals_table->addColumn('number', 'Value');
    $goals_table->setOption('sortColumn', 2);
  
    $events_table = new TableChart('blank');
    $events_table->addColumn('string', 'Events');
    $events_table->addColumn('number', 'Completed');
    $events_table->addColumn('number', 'Value');
    $events_table->setOption('sortColumn', 2);
    
    $events_2_table = new TableChart('blank');
    $events_2_table->addColumn('string', 'Events');
    $events_2_table->addColumn('number', 'Completed');
    $events_2_table->addColumn('number', 'Value');
    $events_2_table->setOption('sortColumn', 2);

    
    // Goals
    $rowlimit = 5;
    $chartdata_goals = array();
    $chartdata_events = array();
    
    usort($datasum[$goalSrc]['goals'], array($this, 'usort_by_value_then_completions'));
    $i = 1;
    foreach($datasum[$goalSrc]['goals'] AS $n => $d) {
      if (empty($d['i'])) { continue; }
      $goals_table->newWorkingRow();
      $goals_table->addRowItem($goals[$d['i']]);
      $goals_table->addRowItem($d['completions']);
      $goals_table->addRowItem($d['value']);
      $goals_table->addRow();
      
      $pie_chart1->newWorkingRow();
      $pie_chart1->addRowItem($goals[$d['i']]);
      $pie_chart1->addRowItem($d['value']);
      $pie_chart1->addRow();
      if ($i++ >= $rowlimit) {
        break;
      }
    }
    
    usort($datasum[$eventSrc]['events'], array($this, 'usort_by_value_then_totalValuedEvents'));
    $i = 1;
    $v['rows'] = array();
    foreach($datasum[$eventSrc]['events'] AS $n => $d) {
      if (empty($d['i'])) { continue; }
      $events_table->newWorkingRow();
      $events_table->addRowItem($d['i']);
      $events_table->addRowItem($d['totalValuedEvents']);
      $events_table->addRowItem($d['value']);
      $events_table->addRow();
      
      if ($context == 'page' || $context == 'page-attr') {
        $pie_chart1->newWorkingRow();
        $pie_chart1->addRowItem($d['i']);
        $pie_chart1->addRowItem($d['value']);
        $pie_chart1->addRow();
      }
      else {
        $pie_chart2->newWorkingRow();
        $pie_chart2->addRowItem($d['i']);
        $pie_chart2->addRowItem($d['value']);
        $pie_chart2->addRow();
      }
      if ($i++ >= $rowlimit) {
        break;
      }
    }

    usort($datasum[$eventSrc2]['events'],  array($this, 'usort_by_value_then_totalValuedEvents'));
    $i = 1;
    $v['rows'] = array();
    foreach($datasum[$eventSrc2]['events'] AS $cat => $d) {
    if (empty($d['i'])) { continue; }
      $events_2_table->newWorkingRow();
      $events_2_table->addRowItem($d['i']);
      $events_2_table->addRowItem($d['totalValuedEvents']);
      $events_2_table->addRowItem($d['value']);
      $events_2_table->addRow();
      if ($i++ >= $rowlimit) {
        break;
      }
    }

    $output .= '<div id="goals-section" class="report-section">';
    $output .= '<h3>Goals &amp; valued events</h3>';
    $output .= '<div class="pane-left">';
    $output .= $pie_chart1->renderOutput();

    $output .= '</div><div class="pane-spacer">&nbsp;</div>';
    $output .= '<div class="pane-right">';
    if ($context == 'page' || $context == 'page-attr') {
      $output .= '<h3>Valued events (onpage)</h3>';
      $output .= $events_2_table->renderOutput();
      if (!empty($this->data['date']['_links']['events_pageview'])) {
        $output .= '<div>' . implode('|', $this->data['date']['_links']['events_pageview']) . '</div>';
      }
    }
    else {
      $output .= $pie_chart2->renderOutput();
    }
    $output .= '</div>'; 

    $output .= '<div class="pane-left" style="clear: left;">';
    $output .= '<h3>Goals' . (($context == 'page'  || $context == 'page-attr') ? ' (entrance)': '') . '</h3>';
    $output .= $goals_table->renderOutput();
    if (!empty($this->data['date']['_links']['goals'])) {
      $output .= '<div>' . implode('|', $this->data['date']['_links']['goals']) . '</div>';
    }
    $output .= '</div><div class="pane-spacer">&nbsp;</div>';
    $output .= '<div class="pane-right">';
    $output .= '<h3>Valued events' . (($context == 'page' || $context == 'page-attr') ? ' (entrance)': '') . '</h3>';
    $output .= $events_table->renderOutput();
    if (!empty($this->data['date']['_links']['events'])) {
      $output .= '<div>' . implode('|', $this->data['date']['_links']['events']) . '</div>';
    }
    $output .= '</div>';    
    $output .= '</div>';
    
    return $output;
  }
  
  function renderContentSection() {
    $output = '';
    $this->data += array(
      'content' => array(),
    );
    $startDate = $this->dateRange['start'];
    $endDate = $this->dateRange['end'];
   
    $all_pages = new TableChart('blank');
    $all_pages->addColumn('string', 'Page');
    $all_pages->addColumn('number', 'Entrances');
    $all_pages->addColumn('number', 'Pageviews');
    $all_pages->addColumn('number', 'V. Evts');
    $all_pages->addColumn('number', 'Goals');
    $all_pages->addColumn('number', 'Value');
    
    $attr_pages = new TableChart('blank');
    $attr_pages->addColumn('string', 'Page');
    $attr_pages->addColumn('number', 'Entrances');
    $attr_pages->addColumn('number', 'Pageviews');
    $attr_pages->addColumn('number', 'V. Evts');
    $attr_pages->addColumn('number', 'Goals');
    $attr_pages->addColumn('number', 'Value');

    $value_str = '';
    $this->sortData('by_score_then_entrances', 'content');
    foreach($this->data['content'] AS $n => $d) {
      if (empty($d['i']) || (substr($d['i'], 0 , 1) == '_')) { continue; }
      $a = explode('/', $d['i'], 2);
      $host = $a[0];
      $path = (isset($a[1])) ? $a[1] : '';

      $pageMeta = $this->getPageMeta($path);
      
      if ($pageMeta) {
        $d['score_dates'] = $this->getPageScoreDates($startDate, $endDate, $pageMeta->created);
        $intent = $pageMeta->intent;
      }
      else {
        $d['score_dates'] = $this->getPageScoreDates($startDate, $endDate, 0);
        $intent = '';
      }
      if ($intent == 'u') {
        continue;
      }
      
      $entrances = !empty($d['entrance']['entrances']) ? $d['entrance']['entrances'] : 0;
      $pageviews = !empty($d['pageview']['pageviews']) ? $d['pageview']['pageviews'] : 0;
      $goals = !empty($d['entrance']['goalCompletionsAll']) ? $d['entrance']['goalCompletionsAll'] : 0;
      $events = !empty($d['pageview']['events']['_all']['totalValuedEvents']) ? $d['pageview']['events']['_all']['totalValuedEvents'] : 0;
      $value = $d['score'];
      $days = $d['score_dates']['days'];

      $pathstr = $this->formatRowString("/$path", 60);
      if (count($all_pages->settings['rows']) < 10) {
        $all_pages->newWorkingRow();
        $l = render::link($pathstr, 'http://' . $d['i'], array('attributes' => array('target' => '_blank')));
        $all_pages->addRowItem($l);        
        $all_pages->addRowItem($entrances);    
        $all_pages->addRowItem($pageviews);
        $all_pages->addRowItem($events);
        $all_pages->addRowItem($goals);
        $all_pages->addRowItem($value);
        $all_pages->addRow(); 
      }
      
      if ($intent == 't') {
        $attr_pages->newWorkingRow();
        $l = render::link($pathstr, 'http://' . $d['i'], array('attributes' => array('target' => '_blank')));
        $attr_pages->addRowItem($l);        
        $attr_pages->addRowItem($entrances);    
        $attr_pages->addRowItem($pageviews);
        $attr_pages->addRowItem($events);
        $attr_pages->addRowItem($goals);
        $attr_pages->addRowItem($value);
        $attr_pages->addRow(); 
      }

      if (count($attr_pages->settings['rows']) >= 10) {
        break;
      }
    }

    $output = '';
    $output .= '<div id="content-section" class="report-section">';
    $output .= '<h3>Content</h3>';
    $output .= '<h3>All pages</h3>';
    $output .= $all_pages->renderOutput();
    if (!empty($this->data['content']['_links']['default'])) {
      $output .= '<div>' . implode('|', $this->data['content']['_links']['default']) . '</div>';
    }
    $output .= '<h3>Attraction pages</h3>';
    $output .= $attr_pages->renderOutput();
    if (!empty($this->data['content']['_links']['i.t'])) {
      $output .= '<div>' . implode('|', $this->data['content']['_links']['i.t']) . '</div>';
    }

    return '<div id="intel-report">' . $output . '</div>';
  }
  
  function renderTrafficsourceSection() {
    $output = '';
    $data = $this->data;
    $data += array(
      'trafficsources' => array(
        'trafficcategory' => array(),
        'medium' => array(),
        'source' => array(),
        'referralHostpath' => array(),
        'socialNetwork' => array(),
        'searchKeyword' => array(),
        'campaign' => array(),
      ),
    );
    $startDate = $this->dateRange['start'];
    $endDate = $this->dateRange['end'];
    $context = $this->params['context'];
    $context_mode = $this->params['context_mode'];
   
    $categories = new TableChart('blank');
    $categories->addColumn('string', 'Traffic categories');
    $categories->addColumn('number', 'Visits');
    $categories->addColumn('number', 'Value');
    $categories->addColumn('number', 'Val/entr');
    
    $mediums = new TableChart('blank');
    $mediums->addColumn('string', 'Mediums');
    $mediums->addColumn('number', 'Visits');
    $mediums->addColumn('number', 'Value');
    $mediums->addColumn('number', 'Val/entr');
    
    $sources = new TableChart('blank');
    $sources->addColumn('string', 'Sources');
    $sources->addColumn('number', 'Visits');
    $sources->addColumn('number', 'Value');
    $sources->addColumn('number', 'Val/entr');
    
    $referrals = new TableChart('blank');
    $referrals->addColumn('string', 'Referral links');
    $referrals->addColumn('number', 'Visits');
    $referrals->addColumn('number', 'Value');
    $referrals->addColumn('number', 'Val/entr');
    
    $socials = new TableChart('blank');
    $socials->addColumn('string', 'Social networks');
    $socials->addColumn('number', 'Visits');
    $socials->addColumn('number', 'Value');
    $socials->addColumn('number', 'Val/entr');
    
    $keywords = new TableChart('blank');
    $keywords->addColumn('string', 'Keywords');
    $keywords->addColumn('number', 'Visits');
    $keywords->addColumn('number', 'Value');
    $keywords->addColumn('number', 'Val/entr');
    
    $campaigns = new TableChart('blank');
    $campaigns->addColumn('string', 'Campaigns');
    $campaigns->addColumn('number', 'Visits');
    $campaigns->addColumn('number', 'Value');
    $campaigns->addColumn('number', 'Val/entr');

    $pie_chart = new PieChart();
    $pie_chart->addColumn('string', '');
    $pie_chart->addColumn('number', 'Value');
    $pie_chart->setSetting('useTotal', 1);
    $total = isset($data['trafficsources']['trafficcategory']['_all']['score']) ? $data['trafficsources']['trafficcategory']['_all']['score'] : 0;
    $pie_chart->setSetting('total', $total);
  
    $rowlimit = 5;

    /*
    if ($context_mode == 'subsite') {
      $val0 = $data['trafficsources']['trafficcategory']['_all'];
      $vali = $data['date']['_all'];
      $isData = array(
        'i' => 'intersite',
        'entrance' => array(
          'entrances' => $vali['session']['sessions'] - $val0['entrance']['entrances'],
          'pageviews' => $vali['session']['pageviews'] - $val0['entrance']['pageviews'],
        ),
        'score' => $vali['score'] - $val0['score'],
      );
      $data['trafficsources']['trafficcategory']['intersite'] = $isData;
      $data['trafficsources']['source']['intersite'] = $isData;
    }
    */

    @uasort($data['trafficsources']['trafficcategory'], array($this, 'usort_by_score_then_entrances'));
    $i = 1;
    foreach($data['trafficsources']['trafficcategory'] AS $n => $d) {
      if (empty($d['i']) || (substr($d['i'], 0 , 1) == '_')) { continue; }
      $categories->newWorkingRow();
      $categories->addRowItem($d['i']);        
      $categories->addRowItem($d['entrance']['entrances']);    
      $categories->addRowItem(round($d['score'], 2)); 
      $categories->addRowItem(round($d['score'] / $d['entrance']['entrances'], 2)); 
      $categories->addRow(); 
      
      $pie_chart->newWorkingRow();
      $pie_chart->addRowItem($d['i']);        
      $pie_chart->addRowItem(round($d['score'], 2)); 
      $pie_chart->addRow(); 
      if ($i++ >= $rowlimit) {
        break;
      }
    }

    @uasort($data['trafficsources']['medium'], array($this, 'usort_by_score_then_entrances'));
    $i = 1;
    foreach($data['trafficsources']['medium'] AS $n => $d) {
      if (empty($d['i']) || (substr($d['i'], 0 , 1) == '_')) { continue; }
      $mediums->newWorkingRow();
      $mediums->addRowItem($d['i']);        
      $mediums->addRowItem($d['entrance']['entrances']);    
      $mediums->addRowItem(round($d['score'], 2)); 
      $mediums->addRowItem(round($d['score'] / $d['entrance']['entrances'], 2)); 
      $mediums->addRow(); 
      if ($i++ >= $rowlimit) {
        break;
      }
    } 
    
    @uasort($data['trafficsources']['source'], array($this, 'usort_by_score_then_entrances'));
    $i = 1;
    foreach($data['trafficsources']['source'] AS $n => $d) {
      if (empty($d['i']) || (substr($d['i'], 0 , 1) == '_')) { continue; }
      $sources->newWorkingRow();
      $sources->addRowItem($d['i']);        
      $sources->addRowItem($d['entrance']['entrances']);    
      $sources->addRowItem(round($d['score'], 2)); 
      $sources->addRowItem(round($d['score'] / $d['entrance']['entrances'], 2)); 
      $sources->addRow(); 
      if ($i++ >= $rowlimit) {
        break;
      }
    }

    @uasort($data['trafficsources']['referralHostpath'], array($this, 'usort_by_score_then_entrances'));
    $i = 1;
    foreach($data['trafficsources']['referralHostpath'] AS $n => $d) {
      if (empty($d['i']) || (substr($d['i'], 0 , 1) == '_')) { continue; }
      $referrals->newWorkingRow();
      $pathstr = $this->formatRowString($d['i'], 48);
      $l = render::link($pathstr, 'http://' . $d['i'], array('attributes' => array('target' => '_blank')));
      $referrals->addRowItem($l);        
      $referrals->addRowItem($d['entrance']['entrances']);    
      $referrals->addRowItem(round($d['score'], 2)); 
      $referrals->addRowItem(round($d['score'] / $d['entrance']['entrances'], 2)); 
      $referrals->addRow(); 
      if ($i++ >= $rowlimit) {
        break;
      }
    } 
    
    @uasort($data['trafficsources']['socialNetwork'], array($this, 'usort_by_score_then_entrances'));
    $i = 1;
    foreach($data['trafficsources']['socialNetwork'] AS $n => $d) {
      if (empty($d['i']) || (substr($d['i'], 0 , 1) == '_')) { continue; }
      $socials->newWorkingRow();
      $socials->addRowItem($d['i']);        
      $socials->addRowItem($d['entrance']['entrances']);    
      $socials->addRowItem(round($d['score'], 2)); 
      $socials->addRowItem(round($d['score'] / $d['entrance']['entrances'], 2)); 
      $socials->addRow(); 
      if ($i++ >= $rowlimit) {
        break;
      }
    }

    @uasort($data['trafficsources']['searchKeyword'], array($this, 'usort_by_score_then_entrances'));
    $i = 1;
    foreach($data['trafficsources']['searchKeyword'] AS $n => $d) {
      if (empty($d['i']) || (substr($d['i'], 0 , 1) == '_')) { continue; }
      $keywords->newWorkingRow();
      $keywords->addRowItem($d['i']);        
      $keywords->addRowItem($d['entrance']['entrances']);    
      $keywords->addRowItem(round($d['score'], 2)); 
      $keywords->addRowItem(round($d['score'] / $d['entrance']['entrances'], 2)); 
      $keywords->addRow(); 
      if ($i++ >= $rowlimit) {
        break;
      }
    } 
    
    @uasort($data['trafficsources']['campaign'], array($this, 'usort_by_score_then_entrances'));
    $i = 1;
    foreach($data['trafficsources']['campaign'] AS $n => $d) {
      if (empty($d['i']) || (substr($d['i'], 0 , 1) == '_')) { continue; }
      $campaigns->newWorkingRow();
      $campaigns->addRowItem($d['i']);        
      $campaigns->addRowItem($d['entrance']['entrances']);    
      $campaigns->addRowItem(round($d['score'], 2)); 
      $campaigns->addRowItem(round($d['score'] / $d['entrance']['entrances'], 2)); 
      $campaigns->addRow(); 
      if ($i++ >= $rowlimit) {
        break;
      }
    }

    $output = '<div id="trafficsources-section" class="report-section">';
    $output .= "<h3>Traffic sources</h3>";
    $output .= '<div class="pane-left">' . $pie_chart->renderOutput() . '</div>';
    $output .= '<div class="pane-spacer">&nbsp;</div>';
    $output .= '<div class="pane-right"><h3>Mediums</h3>' . $mediums->renderOutput();
    if (!empty($data['trafficsources']['medium']['_links'])) {
      $output .= '<div>' . implode('|', $data['trafficsources']['medium']['_links']) . '</div>';
    }
    $output .= '</div>';
    
    $output .= '<div class="pane-left" style="clear: left;"><h3>Categories</h3>' . $categories->renderOutput();
    if (!empty($data['trafficsources']['trafficcategory']['_links'])) {
      $output .= '<div>' . implode('|', $data['trafficsources']['trafficcategory']['_links']) . '</div>';
    }
    $output .= '</div>';
    $output .= '<div class="pane-spacer">&nbsp;</div>';
    $output .= '<div class="pane-right"><h3>Sources</h3>' . $sources->renderOutput();
    if (!empty($data['trafficsources']['source']['_links'])) {
      $output .= '<div>' . implode('|', $data['trafficsources']['source']['_links']) . '</div>';
    }
    $output .= '</div>';
    
    $output .= '<div class="pane-left" style="clear: left;"><h3>Referral links</h3>' . $referrals->renderOutput();
    if (!empty($data['trafficsources']['referralHostpath']['_links'])) {
      $output .= '<div>' . implode('|', $data['trafficsources']['referralHostpath']['_links']) . '</div>';
    }
    $output .= '</div>';
    $output .= '<div class="pane-spacer">&nbsp;</div>';
    $output .= '<div class="pane-right"><h3>Social networks</h3>' . $socials->renderOutput();
    if (!empty($data['trafficsources']['socialNetwork']['_links'])) {
      $output .= '<div>' . implode('|', $data['trafficsources']['socialNetwork']['_links']) . '</div>';
    }
    $output .= '</div>';

    $output .= '<div class="pane-left" style="clear: left;"><h3>Search keywords</h3>' . $keywords->renderOutput();
    if (!empty($data['trafficsources']['searchKeyword']['_links'])) {
      $output .= '<div>' . implode('|', $data['trafficsources']['searchKeyword']['_links']) . '</div>';
    }
    $output .= '</div>';
    $output .= '<div class="pane-spacer">&nbsp;</div>';
    $output .= '<div class="pane-right"><h3>Campaigns</h3>' . $campaigns->renderOutput();
    if (!empty($data['trafficsources']['campaign']['_links'])) {
      $output .= '<div>' . implode('|', $data['trafficsources']['campaign']['_links']) . '</div>';
    }
    $output .= '</div>';
      
    $output .= '</div>';  
    
    return $output;
  }
  


}

