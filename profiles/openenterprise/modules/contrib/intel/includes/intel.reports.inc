<?php
/**
 * @file
 * Functions to support extended Google Analytics data.
 *
 * @author Tom McCracken <tomm@getlevelten.com>
 */

//function intel_init_reports_vars($report_name, $report_type, $report_subtype = '-', $context = '-', $timeframe = '-', $filter_type = '-', $filter_element = '-', $subsite = '-') {
function intel_init_reports_vars($report_name, $report_type, $report_params = '-', $report_subtype = '-',  $entity_type = '-', $entity = '-') {
//$args = func_get_args();
//dsm($args);
  $vars = array(
    'title' => '',
    'report_name' => $report_name,
    'report_type' => $report_type,
    'report_subtype' => ($report_subtype && ($report_subtype != '-')) ? $report_subtype : '',
    'report_mode' => 'default.top',
    'report_modes' => array(),
    'context' => '',
    'context_mode' => '',
    'timeframe' => 'ld30',
    'filter_type' => '',
    'filter' => '',
    'subsite' => '',
    'report_args' => array(),
    'report_params' => array(),
    'filters' => array(),
    'report_info' => array(),
    'report callback' => 'intel_' . $report_name . '_report',
    'entity' => ($entity && ($entity != '-')) ? $entity : '',
    'entity_type' => ($entity_type && ($entity_type != '-')) ? $entity_type : '',
    'entities' => array(),
    'attribute_info' => array(
      'page' => array(),
      'visitor' => array(),
    ),
    'related_reports' => array(),
  );
  // save end elements of report request uri
  $vars['report_args'] = array_slice(explode('/', $_GET['q']), 3);

  $to_vars = array(
    'ft' => 'filter_type',
    'f' => 'filter',
    'c' => 'context',
    'cm' => 'context_mode',
    't' => 'timeframe',
    's' => 'subsite',
  );
  $args = explode('&', $report_params);
  foreach ($args AS $kv) {
    $kv = explode('=', $kv);
    if (count($kv) != 2) {
      continue;
    }
    $vars['report_params'][$kv[0]] = $kv[1];
    if (isset($to_vars[$kv[0]])) {
      $vars[$to_vars[$kv[0]]] = $kv[1];
    }
  }

  $reports = intel_reports();

  if (isset($reports[$report_type]) && isset($reports[$report_type][$report_subtype])) {
    $vars['report_info'] = $reports[$report_type][$report_subtype];
    if (isset($vars['report_info']['title'])) {
      $vars['title'] = $vars['report_info']['title'];
    }
    if ($vars['report_info']['key']) {
      $vars['report_mode'] = $vars['report_info']['key'];
    }
    if (isset($vars['report_info']['report callback'])) {
      $vars['report callback'] = $vars['report_info']['report callback'];
      if (isset($vars['report_info']['file'])) {
        include_once drupal_get_path('module', 'intel') . '/' . $vars['report_info']['file'];
      }
    }
  }

  if ($vars['subsite']) {
    $vars['filters'] = intel_reports_add_filter($vars['filters'], $vars['subsite'], 'page-attr');
    if (empty($vars['context_mode'])) {
      $vars['context_mode'] = 'subsite';
    }
  }

  // process special filters that pass in the actual Drupal entity
  if ($entity_type == 'node') {
    $vars['filter_type'] = 'page';
    $sys_path = 'node/' . $entity->nid;
    // check if page is homepage
    $site_frontpage = variable_get('site_frontpage', '');
    $path = ($site_frontpage == $sys_path) ? '/' : url('node/' . $entity->nid);
    // escape / chars
    $vars['filter'] = 'pagePath:' . str_replace('/', '|', $path);
    $vars['report_params'] = array('ft' => $vars['filter_type'], 'f' =>  $vars['filter']);
  }
  elseif ($entity_type == 'intel_visitor') {
    $vars['filter_type'] = 'visitor';
    $vars['filter'] = 'vtk:' . substr($entity->vtk, 0, 20);
    $vars['report_params'] = array('ft' => $vars['filter_type'], 'f' =>  $vars['filter']);
  }
  elseif ($entity_type == 'og_group') {
    $vars['filter_type'] = 'page-attr';
    // TODO use entity_info to determine id
    $vars['filter'] = 'og:' . $entity->id;
    //$vars['og_entity'] = intel_visitor_load($filter_element->vtk);
  }

  // process static filter
  if ($vars['filter_type']) {
    if ($vars['filter_type'] == 'visitor') {
      $v = explode(':', $vars['filter']);
      $vars['entity'] = intel_visitor_load($v[1]);
      $vars['entity_type'] = 'intel_visitor';
    }

    $vars['filter'] = urldecode($vars['filter']);
    // if filter is landingPagePath or pagePath, replace | encoding with /
    if (strpos($vars['filter'], 'agePath:') || strpos($vars['filter'], 'ostpath:')) {
      $vars['filter'] = str_replace('|', '/', $vars['filter']);
    }

    $vars['filters'] = intel_reports_add_filter($vars['filters'], $vars['filter'], $vars['filter_type']);

    if (!$vars['context'] && ($report_type == 'scorecard' || $report_type == 'content')) {
      $vars['context'] = $vars['filter_type'];
    }
  }

  if (!$vars['context']) {
    if (!empty($vars['filter_type'])) {
      $vars['context'] = $vars['filter_type'];
    }
    else {
      if ($report_type == 'content') {
        $vars['context'] = 'page';
      }
      else {
        $vars['context'] = 'site';
      }
    }
  }

  $attr_info = intel_get_page_attribute_info();

  // add any valid dynamic filters in query string
  $valid_filter_types = intel_reports_filter_types();
  foreach ($_GET AS $filter_type => $filter) {
    if (isset($valid_filter_types[$filter_type])) {
      $vars['filters'] = intel_reports_add_filter($vars['filters'], $filter_type, $filter);
    }
  }

  // get attr info if needed
  foreach ($vars['filters'] AS $type => $farr) {
    if ($type == 'page-attr') {
      foreach ($farr AS $i => $filter) {
        $a = explode(':', $filter);
        $vars['attribute_info']['page'][$a[0]] = intel_get_page_attribute_info($a[0]);
      }
    }
    if ($type == 'visitor-attr') {
      foreach ($farr AS $i => $filter) {
        $a = explode(':', $filter);
        $vars['attribute_info']['visitor'][$a[0]] = intel_get_visitor_attribute_info($a[0]);
      }
    }
  }

  // if page filter exists, try to load the node to get attributes
  if ($vars['filter_type'] == 'page' && empty($vars['entity'])) {
    $a = explode(':', $vars['filter']);
    $url = intel_parse_url($a[1]);
    if (!empty($url['nid'])) {
      $vars['entity'] = node_load($url['nid']);
      $vars['entity_type'] = 'node';
    }
  }

  if ($vars['entity_type'] == 'node') {
    if (!isset($vars['entities']['node'])) {
      $vars['entities']['node'] = array();
    }
    $vars['entities']['node'][$vars['entity']->nid] = $vars['entity'];
    $entity_attrs = intel_get_entity_intel_attributes($vars['entity'], 'node');
  }

  if (!empty($entity_attrs)) {
    foreach ($entity_attrs['page'] AS $attr_key => $value) {
      // skip/disable entity type
      if ($attr_key == 'et') {
        continue;
      }

      $params = array(
        'ft' => 'page-attr',
      );
      $path0 = intel_build_report_path($vars['report_type'], $params, $vars['report_subtype']);

      if ($attr_info[$attr_key]['type'] == 'flag') {
        //$vars['related_reports'][] = 'ga:customVarValue1=@&' . $attr_key . '&';
      }
      elseif ($attr_info[$attr_key]['type'] == 'item') {
        $attr_option_info = intel_get_attribute_option_info('page', $attr_key, $value);
        $params['f'] = $attr_key . ':' . $value;
        $vars['related_reports'][] = l($attr_info[$attr_key]['title'] . ': ' . $attr_option_info['title'], intel_build_report_path($vars['report_type'], $params, $vars['report_subtype']));
      }
      else if ($attr_info[$attr_key]['type'] == 'list') {
        if (is_array($value)) {
          foreach ($value AS $k => $v) {
            $attr_option_info = intel_get_attribute_option_info('page', $attr_key, $k);
            $t = $attr_info[$attr_key]['title'] . ': ' . (isset($attr_option_info['title']) ? $attr_option_info['title'] : $v);
            $params['f'] = $attr_key . ':' . $k;
            $vars['related_reports'][] = l($t, intel_build_report_path($vars['report_type'], $params, $vars['report_subtype']));
          }
        }
      }
    }
  }

  // parse contexts and report_modes into array elements
  $vars['report_modes'] = explode('.', $vars['report_mode']);

  $a = explode('.', $vars['context']);
  if (count($a) == 2) {
    $vars['context'] = $a[0];
    $vars['context_mode'] = $a[1];
  }

//dsm($vars);
  return $vars;
}

function intel_build_report_params_arg($params, $ignore = array()) {
  $str = '';
  foreach ($params AS $k => $v) {
    if (in_array($k, $ignore) || empty($v)) {
      continue;
    }
    if ($str) {
      $str .= '&';
    }
    $str .= "$k=$v";
  }
  return $str;
}

function intel_build_report_path($report_type, $report_params = '', $report_subtype = '') {
  $path = 'admin/reports/intel/' . $report_type;
  if (is_array($report_params)) {
    $report_params = intel_build_report_params_arg($report_params);
  }
  $path .= '/' . (($report_params) ? $report_params : '-');
  if ($report_subtype) {
    $path .= '/' . $report_subtype;
  }


  return $path;
}

function intel_build_report($vars) {
  $output = '';
  $vars += array(
    'title' => '',
  );
  $api_level = intel_api_level();
  $api_level = 'free';
  $error = '';
  $emsgs = array(
    'page-attr' => t('Page attribute and content segment reporting features are not available with the free version of Intelligence.'),
    'visitor'  => t('Visitor data and reporting features are not available with the free or basic versions of Intelligence.'),
  );
  // Page attribute report api access
  if ($vars['filter_type'] == 'page-attr' || (substr($vars['report_subtype'], 0, 3) == 'pa-')) {
    if ($api_level != 'pro' && $api_level != 'basic') {
      $error = $emsgs['page-attr'];
    }
  }
  // Visitor report api access
  if ($vars['filter_type'] == 'visitor' || $vars['report_type'] == 'visitor') {
    if ($api_level != 'pro') {
      $error = $emsgs['visitor'];
    }
  }


  if (empty($_GET['return_type']) || ($_GET['return_type'] == 'nonajax')) {
    intel_add_report_headers();
    if (!empty($vars['title'])) {
      drupal_set_title($vars['title'], PASS_THROUGH);
    }

    $filter_form = drupal_get_form('intel_report_filters_form', $vars['filters'], $vars);
    $output .= drupal_render($filter_form);
  }

  if ($error) {
    drupal_set_message($error, 'error');
  }
  elseif (empty($_GET['return_type'])) {
    $output .= intel_get_report_ajax_container();
  }
  elseif ($_GET['return_type'] == 'nonajax') {
    $output .= $vars['report callback']($vars);
  }
  elseif ($_GET['return_type'] == 'json') {
    $data = array(
      'report' => $vars['report callback']($vars),
    );
    drupal_json_output($data);
    return;
  }
  return $output;
}

function intel_reports_add_filter($filters, $filter, $filter_type = '-') {
  if (!isset($filters[$filter_type])) {
    $filters[$filter_type] = array();
  }
  $filters[$filter_type][] = $filter;
  return $filters;
}

function intel_reports_filter_types() {
  array(
    'page' => t('Page'),
    'page-attr' => t('Page attribute'),
    'event' => t('Event'),
    'trafficsource' => t('Traffic source'),
    'visitor' => t('Visitor'),
    'visitor-attr' => t('Visitor attribute'),
    'location' => t('location'),
  );
}

function _intel_get_report_dates_from_ops($ops = 'l30d', &$cache_options = array(), $return_hash = FALSE) {
  $start = '';
  $end = '';
  if (!empty($_GET['timeops'])) {
    $ops = $_GET['timeops'];
  }

  if ($ops == 'today') {
    $start = 'midnight';
    $end = 'now';
    $cache_options = array('refresh' => 1);
  }
  elseif (($ops == 'l24') || ($ops == 'l24fn')) {
    $start = '-24 hours';
    $end = 'now';
    $cache_options = array('refresh' => 1);
  }
  elseif ($ops == 'yesterday') {
    $start = '-1 day midnight';
    $end = "midnight - 1 second";
  }
  elseif ($ops == 'l7dfn') {
    $start = "-7 days";
    $end = "now";
    $cache_options = array('refresh' => 1);
  }
  elseif ($ops == 'l7d') {
    $start = "-7 days midnight";
    $end = "midnight - 1 second";
    $cache_options = array('refresh' => 1);
  }
  elseif ($ops == 'l30dfn') {
    $start = "-30 days";
    $end = "now";
    $cache_options = array('refresh' => 1);
  }
  elseif ($ops == 'thismonth') {
    $start = "midnight first day of this month";
    $end = "midnight first day of next month - 1 second";
  }
  elseif ($ops == 'lastmonth') {
    $start = "midnight first day of last month";
    $end = "midnight first day of this month - 1 second";
  }
  elseif ($ops == 'monthtodate') {
    $start = "midnight first day of this month";
    $end = "now";
  }
  else  {  // "l30d" last 30 days from yesterday
    $start = "-30 days midnight";
    $end = "midnight - 1 second";
  }
  return _intel_get_report_dates($start, $end);
}

function _intel_get_report_dates($start_default = "-31 days", $end_default = "-1 day", $return_hash = FALSE) {
  if (!empty($_GET['dates'])) {
    $a = explode(":", $_GET['dates']);
    $_GET['start_date'] = $a[0];
    $_GET['end_date'] = $a[1];
  }
  $start_date = (!empty($_GET['start_date'])) ? strtotime($_GET['start_date']) : strtotime($start_default);
  $end_date = (!empty($_GET['end_date'])) ? strtotime($_GET['end_date']) : strtotime($end_default);
  $number_of_days = round(($end_date - $start_date)/60/60/24);
  if (!$return_hash) {
    return array(
      $start_date,
      $end_date,
      $number_of_days,
    );
  }
  else {
    return array(
      'start_date' => $start_date,
      'end_date' => $end_date,
      'number_of_days' => $number_of_days,
    );
  }
}

function intel_report_filters_form($form, &$form_state, $filters = array(), $vars = array()) {
  $dynamic_filters = array();
  $context = (!empty($vars['context'])) ? $vars['context'] : '';
  $form['filters'] = array(
    '#type' => 'fieldset',
    '#title' => t('Filters'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $events = array(
    '' => t('-'),
  );
  $metas = intel_get_intel_event_info();
  foreach ($metas AS $meta) {
    if (isset($meta['category'])) {
      $events[$meta['category']] = $meta['title'];
    }
  }

  if ($context != 'page') {
    $modes = array(
      '' => '-',
      'landingPagePath' => t('Entrance'),
      'pagePath' => t('View'),
    );
    $mode_default = 'entrance';
    $path_default = '';
    if (!empty($filters['page'])) {
      $a = explode(':', $filters['page'][0]);
      $mode_default = $a[0];
      $path_default = $a[1];
      $dynamic_filters['page'] = "{$a[0]}={$a[1]}";
    }
    $form['filters']['page_mode'] = array(
      '#type' => 'select',
      '#title' => t('Page mode'),
      '#id' => 'page-mode',
      '#options' => $modes,
      '#default_value' => $mode_default,
      '#prefix' => '<div class="filter-fieldset filter-fieldset-page">',
    );
    $form['filters']['page_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Page path'),
      '#id' => 'page-path',
      '#size' => 80,
      '#default_value' => $path_default,
      '#suffix' => '</div>',
    );
  }

  if ($context != 'page-attr') {
    $pa_options = array(
      '' => t('-'),
    );
    $pa_options = array_merge($pa_options, intel_get_field_page_attribute_allowed_values());
    $pa_type_default = '';
    $pa_value_default = '';
    if (!empty($filters['page-attr'])) {
      $a = explode(':', $filters['page-attr'][0]);
      $va_type_default = $a[0];
      $va_value_default = $a[1];
      $dynamic_filters['page-attr'] = "{$a[0]}={$a[1]}";
    }
    $form['filters']['page_attr_type'] = array(
      '#type' => 'select',
      '#title' => t('Page attribute'),
      '#options' => $pa_options,
      '#default_value' => $pa_type_default,
      '#prefix' => '<div class="filter-fieldset filter-fieldset-visitor-attr">',
    );
    $form['filters']['page_attr_value'] = array(
      '#type' => 'textfield',
      '#title' => t('Page attribute value'),
      '#id' => 'page-attr-value',
      '#size' => 80,
      '#default_value' => $pa_value_default,
      '#suffix' => '</div>',
    );
  }

  if ($context != 'trafficsource') {
    $trafficsource_types = array(
      '' => t('-'),
      'source' => t('Source'),
      'medium' => t('Medium'),
      'referralPath' => t('Referral path'),
      'socialNetwork' => t('Social network'),
      'keyword' => t('Keyword'),
    );
    $trafficsource_type_default = '';
    $trafficsource_value_default = '';
    if (!empty($filters['trafficsource'])) {
      $a = explode(':', $filters['trafficsource'][0]);
      $trafficsource_type_default = $a[0];
      $trafficsource_value_default = $a[1];
      $dynamic_filters['trafficsource'] = "{$a[0]}={$a[1]}";
    }
    $form['filters']['trafficsource_type'] = array(
      '#type' => 'select',
      '#title' => t('Traffic source type'),
      '#id' => 'trafficsource-type',
      '#options' => $trafficsource_types,
      '#default_value' => $trafficsource_type_default,
      '#prefix' => '<div class="filter-fieldset filter-fieldset-referrer">',
    );
    $form['filters']['trafficsource_value'] = array(
      '#type' => 'textfield',
      '#title' => t('Traffic source value'),
      '#id' => 'trafficsource-value',
      '#size' => 80,
      '#default_value' => $trafficsource_value_default,
      '#suffix' => '</div>',
    );
  }

  $loc_types = array(
    '' => t('-'),
    'subContinent' => t('Sub Continent'),
    'country' => t('Country'),
    'region' => t('Region / state'),
    'city' => t('City'),
    'metro' => t('Metro'),
  );
  $loc_type_default = '';
  $loc_value_default = '';
  if (!empty($filters['location'])) {
    $a = explode(':', $filters['location'][0]);
    $loc_type_default = $a[0];
    $loc_value_default = $a[1];
    $dynamic_filters['location'] = "{$a[0]}={$a[1]}";
  }
  $form['filters']['location_type'] = array(
    '#type' => 'select',
    '#title' => t('Location type'),
    '#id' => 'location-type',
    '#options' => $loc_types,
    '#default_value' => $loc_type_default,
    '#prefix' => '<div class="filter-fieldset filter-fieldset-location">',
  );
  $form['filters']['loc_value'] = array(
    '#type' => 'textfield',
    '#title' => t('Location value'),
    '#id' => 'location-value',
    '#size' => 80,
    '#default_value' => $loc_value_default,
    '#suffix' => '</div>',
  );

  if ($context != 'visitor') {
    $visitor_options = array(
      '' => t('-'),
      'vtkid' => t('By visitor token'),
      'email' => t('By email address'),
    );
    $visitor_type_default = '';
    $visitor_value_default = '';
    if (!empty($filters['visitor'])) {
      $a = explode(':', $filters['visitor'][0]);
      $visitor_type_default = $a[0];
      $visitor_value_default = $a[1];
      $dynamic_filters['visitor'] = "{$a[0]}={$a[1]}";
    }
    $form['filters']['visitor_type'] = array(
      '#type' => 'select',
      '#title' => t('Visitor'),
      '#id' => 'visitor-type',
      '#options' => $visitor_options,
      '#default_value' => $visitor_type_default,
      '#prefix' => '<div class="filter-fieldset filter-fieldset-visitor">',
    );
    $form['filters']['visitor_value'] = array(
      '#type' => 'textfield',
      '#title' => t('Visitor value'),
      '#id' => 'visitor-value',
      '#size' => 80,
      '#default_value' => $visitor_value_default,
      '#suffix' => '</div>',
    );

    $va_options = array(
      '' => t('-'),
    );
    $va_options = array_merge($va_options, intel_get_field_visitor_attribute_allowed_values());
    $va_type_default = '';
    $va_value_default = '';
    if (!empty($filters['visitor-attr'])) {
      $a = explode(':', $filters['visitor-attr']);
      $va_type_default = $a[0];
      $va_value_default = $a[1];
      $dynamic_filters['visitor-attr'] = "{$a[0]}={$a[1]}";
    }
    $form['filters']['visitor_attr_type'] = array(
      '#type' => 'select',
      '#title' => t('Visitor attribute'),
      '#id' => 'visitor-attr-type',
      '#options' => $va_options,
      '#default_value' => $va_type_default,
      '#prefix' => '<div class="filter-fieldset filter-fieldset-visitor-attr">',
    );
    $form['filters']['visitor_attr_value'] = array(
      '#type' => 'textfield',
      '#title' => t('Visitor attribute value'),
      '#id' => 'visitor-attr-value',
      '#size' => 80,
      '#default_value' => $va_value_default,
      '#suffix' => '</div>',
    );
  }

  $form['filters']['apply'] = array(
    '#type' => 'markup',
    '#markup' => '<input type="button" id="apply-report-filter" value="Apply" class="form-submit">',
  );

  // do not display form if not in extended mode
  if (!variable_get('intel_extended_mode', 0)) {
    $form = array();
  }

  $link_keys = array(
    'scorecard' => t('scorecard'),
    'trafficsource' => t('sources'),
    'content' => t('content'),
    'visitor' => t('visitors'),
  );
  $link_base_path = '';
  //if (strpos($_GET['q'], 'admin/reports/intel/') === 0) {
    $link_base_path = 'admin/reports/intel';
  //}

  if (!empty($vars['subsite'])) {
    $filter = explode(':', $vars['subsite']);
    $pa_info = intel_get_page_attribute_info($filter[0]);
    //$title = '<strong>' . t('Page group') . '</strong>';
    $title = '<strong>' . t('Subsite') . '</strong>';
    if (isset($pa_info['title'])) {
      $title .= ': ' . $pa_info['title'];
      $pa_option_info = intel_get_attribute_option_info('page', $filter[0], $filter[1]);
      $title .= ': ' . (!empty($pa_option_info['title']) ? $pa_option_info['title'] : $filter[1]);
    }
    else {
      $title .= ': ' . $filter[0] . ": " . $filter[1] . "<br />\n";
    }

    if (!empty($link_base_path)) {
      //$links[] = l(t('x'), $link_base_path . '/' . $vars['report_args'][0];
      /*
      foreach ($link_keys AS $key => $t) {
        $args = array_slice($vars['report_args'], 1);
        $links[] = l($t, $link_base_path . '/' . $key . '/-/-/-/-/-/'. $vars['report_args'][5]);
      }
      */
    }
    $title = '<div class="intel-static-subsite" style="font-size: 115%;">' . $title;

    if (!empty($links)) {
      $title .= ' [' . implode('|', $links) . ']';
    }
    $title .= '</div>';

    $form['subsite_display'] = array(
      '#type' => 'markup',
      '#markup' => $title,
    );
  }

  // create static filter header
  if (!empty($vars['filter_type'])) {
    $filter = explode(':', $vars['filter']);
    $title = '';

    if ($vars['filter_type'] == 'page') {
      $title = '<strong>' . t('Page') . '</strong>' . ': ' . $filter[1];
    }
    if ($vars['filter_type'] == 'page-attr') {
      $pa_info = intel_get_page_attribute_info($filter[0]);
      $title = '<strong>' . t('Page attribute') . '</strong>';
      if (isset($pa_info['title'])) {
        $title .= ': ' . $pa_info['title'];
        $pa_option_info = intel_get_attribute_option_info('page', $filter[0], $filter[1]);
        $title .= ': ' . (!empty($pa_option_info['title']) ? $pa_option_info['title'] : $filter[1]);
      }
      else {
        $title .= ': ' . $filter[0] . ": " . $filter[1];
      }
    }
    if ($vars['filter_type'] == 'trafficsource') {
      $title = '<strong>' . t('Traffic source') . '</strong>' . ': ' . $filter[1] . " ({$filter[0]})";
    }
    if ($vars['filter_type'] == 'visitor') {
      $title = '<strong>' . t('Visitor') . '</strong>' . ': ';
      $title .= (($vars['entity_type'] == 'intel_visitor' && !empty($vars['entity'])) ? $vars['entity']->label() : $filter[1]);
    }

    if ($title) {

      if (isset($link_keys[$vars['filter_type']])) {
        unset($link_keys[$vars['filter_type']]);
      }
      if ($vars['filter_type'] == 'page') {
        unset($link_keys['content']);
      }

      $links = array();
      if (!empty($link_base_path)) {
        // don't show clear link if reports shown on entity tab
        if (strpos($_GET['q'], 'admin/reports/intel/') === 0) {
          $params = $vars['report_params'];
          $params['ft'] = '';
          $params['f'] = '';
          $links[] = l(t('x'), intel_build_report_path($vars['report_type'], $params, $vars['report_subtype']));
        }
        if (strpos($_GET['q'], 'admin/reports/intel/') !== 0) {
          foreach ($link_keys AS $key => $t) {
            $args = array_slice($vars['report_args'], 1);
            $links[] = l($t, intel_build_report_path($key, $vars['report_params'], $vars['report_subtype']));
          }
        }
      }
      $title = '<div class="intel-static-filter" style="font-size: 115%;">' . $title;

      if (!empty($links)) {
        $title .= ' [' . implode(' ', $links) . ']';
      }
      $title .= '</div>';

      $form['static_filters_display'] = array(
        '#type' => 'markup',
        '#markup' => $title,
      );
    }
  }

  if (!empty($vars['related_reports'])) {
    $related = implode(', ', $vars['related_reports']);
    $form['related_reports'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="intel-related-links">' . t('related') . ': ' . $related . '</div>',
    );
  }


  if (isset($filters_display) && count($filters_display)) {
    $form['filters_display'] = array(
      '#type' => 'markup',
      '#markup' => '<strong>' . t('Filters') . '</strong>' . ': ' . implode(', ', $filters_display),
    );
  }
  return $form;
}

function intel_add_report_headers() {
  drupal_add_js('https://www.google.com/jsapi', array('type' => 'external', 'scope' => 'header'));
  drupal_add_js("google.load('visualization', '1', {packages: ['corechart']});google.load('visualization', '1', {packages: ['table']});", array('type' => 'inline', 'scope' => 'header'));
  drupal_add_js(libraries_get_path('LevelTen') . '/Intel/charts/charts.js');
  drupal_add_css(drupal_get_path('module', 'intel') . '/css/intel.report.css');
  drupal_add_js(drupal_get_path('module', 'intel') . '/js/intel.report.js');
}

function intel_get_report_ajax_container() {
  $output = '<div id="intel-report-container" data-q="' . $_GET['q'] . '" data-dates="' . ((!empty($_GET['dates'])) ? $_GET['dates'] : '') . '" data-refresh="' . ((!empty($_GET['refresh'])) ? 1 : 0) . '"><div class="loader"><img src="/' . drupal_get_path('module', 'intel') . '/images/ajax_loader_report.gif' . '" alt="loading LevelTen Intelligence"><br>Gathering Intelligence...</div></div>';
  return $output;
}

