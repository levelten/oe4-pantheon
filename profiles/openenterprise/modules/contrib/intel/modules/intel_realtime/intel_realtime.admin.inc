<?php

function intel_realtime_log_page() {
  $header = array();
  $header[] = array(
    'data' => t('id'),
    'field' => 'l.id',
  );
  $header[] = array(
    'data' => t('time'),
    'field' => 'l.time',
    'sort' => 'desc',
  );
  $header[] = array(
    'data' => t('VTK'),
    'field' => 'l.vtk',
  );
  $header[] = array(
    'data' => t('SID'),
    'field' => 'l.sid',
  );
  $header[] = array(
    'data' => t('Type'),
    'field' => 'l.type',
  );
  $header[] = array(
    'data' => t('Path/Category'),
    'field' => 'l.path',
  );
  /*
  $header[] = array(
    'data' => t('Data'),
    'field' => 'l.data',
  );
  */
  /*
  $header[] = array(
    'data' => t('Operations'),
  );
  */

  $filter = array();
  $options = array();
  $result = intel_realtime_log_load_filtered($filter, $options, $header, 50);

  $cur_path = current_path();
  $rows = array();
  $prev = (object) array(
    'time' => 0,
  );
  while ($r = $result->fetchObject()) {
    $row = array();
    $ops = l(t('details'), $cur_path . '/' . $r->id);
    $attached_event = 0;
    if (
      ($r->type == 'event')
      && ($r->time == $prev->time)
      && ($r->vtk == $prev->vtk)
    ) {
      $attached_event = 1;
    }
    $row[] = l($r->id, $cur_path . '/' . $r->id);
    if ($r->time != $prev->time) {
      $row[] = format_interval(REQUEST_TIME - $r->time) . t(' ago');
    }
    else {
      $row[] = '';
    }
    $row[] = substr($r->vtk, 0, 10);
    $row[] = $r->sid;
    $row[] = (($attached_event) ? '> ' : '') . $r->type;
    if ($r->type == 'pageview') {
      $row[] = $r->path;
    }
    else {
      $row[] = $r->category;
    }

    //$row[] = $ops;
    $rows[] = $row;
    if ($r->type == 'pageview') {
      $prev = $r;
    }
    else if (!$attached_event) {
      $prev = (object) array(
        'time' => $r->time,
      );
    }
  }

  $output['table'] = array(
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No instances were returned'),
    '#theme' => 'table',
  );
  $output['pager']['#markup'] = theme('pager');
  return $output;
}

function intel_realtime_log_hit_page($hit) {
  $output = '';

  $hit->data = urldecode($hit->data);
  $hit->data = json_decode($hit->data);


  intel_include_library_file('class.visitor.php');

  if (isset($hit->data->pa)) {
    $hit->data->pa = \LevelTen\Intel\ApiVisitor::unserializeCustomVar($hit->data->pa);
  }
  if (isset($hit->data->va)) {
    $hit->data->va = \LevelTen\Intel\ApiVisitor::unserializeCustomVar($hit->data->va);
  }
  if (isset($hit->data->va0)) {
    $hit->data->va0 = \LevelTen\Intel\ApiVisitor::unserializeCustomVar($hit->data->va0);
  }

  if (function_exists('dpm')) {
    dpm($hit);
  }

  $output = '';
  $output .= "request time: " . REQUEST_TIME . "\n<br />";
  $output .= "delta time: " . format_interval(REQUEST_TIME - $hit->time) . t(' ago') ."\n<br />\n<br />";

  $output .= '<pre>' . print_r($hit, 1) . '</pre>';

  return $output;
}

function intel_realtime_log_clear_page($time = -1) {
  $output = '';
  $cur_path = current_path();
  if ($time == -1) {
    $items = array();
    $items[] = l(t('All'), $cur_path . '/0');
    $items[] = l(t('30 mins'), $cur_path . '/1800');
    $items[] = l(t('1 hour'), $cur_path . '/3600');
    $items[] = l(t('4 hours'), $cur_path . '/14400');
    $items[] = l(t('12 hours'), $cur_path . '/43200');
    $items[] = l(t('24 hours'), $cur_path . '/86400');
    $output = theme('item_list', array('items' => $items));
  }
  else {
    intel_realtime_log_clear($time);
    drupal_set_message(t('Log has been cleared.'));
  }

  return $output;
}