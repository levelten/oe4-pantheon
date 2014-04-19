<?php
namespace LevelTen\Intel\Realtime;
/**
 * @file
 * @author  Tom McCracken <tomm@getlevelten.com>
 * @version 1.0
 * @copyright 2013 LevelTen Ventures
 * 
 * @section LICENSE
 * All rights reserved. Do not use without permission.
 * 
 */



function track_pageview() {
  global $GET;
  $instance = track_instance_construct();
  $instance->type = 'pageview';
  $instance->data['type'] = 'pageview';
  track_instance_dbsave($instance);
  if ($instance->isEntrance) {
    $session = track_session_construct();
    track_session_dbsave($session);
  }
  else {
    track_session_dbupdate_last($instance->vtk, $instance->sid, $instance->time);
  }
  $response = array(
    'message' => "OK",
  );
  return $response;
}

function track_event() {
  global $GET;
  $instance = track_instance_construct();
  $instance->type = 'event';
  $instance->data['type'] = 'event';
  track_instance_dbsave($instance);
  $response = array(
    'message' => "OK",
  );
  return $response;
}

function track_session() {
  global $GET;

  $session = track_session_construct();
  track_session_dbsave($session);
}

function track_session_construct() {
  global $GET;

  $session = (object) array();
  $session->vtk = $GET['vtk'];
  $session->sid = $GET['sid'];
  $session->start = (int)$GET['t'];
  $session->last = (int)$GET['t'];
  $session->data = array();
  $session->data['ts'] = $GET['ts'];
  $session->data['vtk'] = $GET['vtk'];
  $session->data['sid'] = $GET['sid'];
  return $session;
}

function track_instance_construct() {
  global $GET;

  $instance = (object) array();
  $instance->vtk = $GET['vtk'];
  $instance->sid = $GET['sid'];
  $instance->time = (int)$GET['t'];
  $instance->path = $GET['p'];
  $instance->host = $GET['h'];
  $instance->isEntrance = (int)$GET['ie'];
  if (isset($GET['ec'])) {
    $instance->category = $GET['ec'];
    $instance->action = $GET['ea'];
    $instance->label = $GET['el'];
    $instance->value = (int)$GET['ev'];
    $instance->noninteraction = $GET['ei'];
  }
  $instance->data = $GET;
  unset($instance->data['q']);
  unset($instance->data['callback']);
  return $instance;
}

function track_instance_dbsave($instance, $db_mode = 1) {
  global $db, $db_tableprefix;

  $data = !empty($instance->data) ? $instance->data : (object) array();
  if (!is_string($data)) {
    $data = json_encode($data);
  }

  $vars = array(
    ':time' => !empty($instance->time) ? $instance->time : 0,
    ':vtk' => !empty($instance->vtk) ? $instance->vtk : '',
    ':sid' => !empty($instance->sid) ? $instance->sid : 1,
    ':type' => !empty($instance->type) ? $instance->type : '',
    ':host' => !empty($instance->host) ? $instance->host : '',
    ':path' => !empty($instance->path) ? $instance->path : '',
    ':query' => !empty($instance->query) ? $instance->query : '',
    ':category' => !empty($instance->category) ? $instance->category : '',
    //':action' => !empty($instance->action) ? $instance->action : '',
    ':label' => !empty($instance->label) ? $instance->label : '',
    ':value' => !empty($instance->value) ? $instance->value : '',
    ':data' => $data,
  );
  $fields = array();
  $values = array();
  foreach ($vars AS $k => $v) {
    $fields[] = substr($k, 1);
    $values[] = $k;
  }
  $fields_str = implode(', ', $fields);
  $values_str = implode(', ', $values);

  $query_str = "
    INSERT INTO {$db_tableprefix}realtime
    ($fields_str)
    VALUES($values_str)";

  //}
  $query = $db->prepare($query_str);
  try {
    $result = $query->execute($vars);
  }
  catch(PDOException $e) {
    system_log($e->getMessage(), 'error');
  }
  return $instance;
}

function track_session_dbupdate_last($vtk, $sid, $time) {
  global $db, $db_tableprefix;

  $vars = array(
    ':vtk' => $vtk,
    ':sid' => $sid,
    ':last' => $time,
  );

  $query_str = "
    UPDATE {$db_tableprefix}realtime_session
      SET
        last = :last
      WHERE
        vtk = :vtk
        AND sid = :sid
  ";

  $query = $db->prepare($query_str);
  try {
    $result = $query->execute($vars);
  }
  catch(PDOException $e) {
    system_log($e->getMessage(), 'error');
  }
}

function track_session_dbsave($session, $db_mode = 1) {
  global $db, $db_tableprefix;

  $data = !empty($session->data) ? $session->data : (object) array();
  if (!is_string($data)) {
    $data = json_encode($data);
  }

  $vars = array(
    ':vtk' => !empty($session->vtk) ? $session->vtk : '',
    ':sid' => !empty($session->sid) ? $session->sid : 0,
    ':start' => !empty($session->start) ? $session->start : 0,
    ':last' => !empty($session->last) ? $session->last : 0,
    ':data' => $data,
  );
  $fields = array();
  $values = array();
  foreach ($vars AS $k => $v) {
    $fields[] = substr($k, 1);
    $values[] = $k;
  }
  $fields_str = implode(', ', $fields);
  $values_str = implode(', ', $values);

  $query_str = "
    INSERT INTO {$db_tableprefix}realtime_session
    ($fields_str)
    VALUES($values_str)";

  //}
  $query = $db->prepare($query_str);
  try {
    $result = $query->execute($vars);
  }
  catch(PDOException $e) {
    system_log($e->getMessage(), 'error');
  }
  return $session;
}

function track_log_prune() {
  global $db, $db_tableprefix;

  $conditions = isset($filters['conditions']) ? $filters['conditions'] : array();

  $query_str = "DELETE FROM {$db_tableprefix}realtime WHERE time < :time";
  $vars = array(
    ':time' => REQUEST_TIME - 1800,
  );
  $query = $db->prepare($query_str);
  $query->execute($vars);

  $query_str = "
    DELETE
    FROM {$db_tableprefix}realtime_visitor v
    LEFT OUTER JOIN {$db_tableprefix}realtime l
      ON v.vtk = l.vtk AND v.sid = l.sid
    WHERE l.time IS NULL";
  $query = $db->prepare($query_str);
  $query->execute();
}

function track_log() {
  global $GET, $POST;

  $time_end = isset($GET['t']) ? $GET['t'] : REQUEST_TIME;
  $time_start = isset($GET['st']) ? $GET['st'] : ($time_end - 1800);
  $filters = array(
    'conditions' => array(),
  );
  $filters['conditions'][] = array(
    'time',
    $time_start,
    '>=',
  );
  $filters['conditions'][] = array(
    'time',
    $time_end,
    '<=',
  );

  $instances = track_instance_dbload_by_filter($filters);

  // TODO: create a more effienct than decodeing json to encode json
  $data = array();
  foreach ($instances AS $instance) {
    $data[] = json_decode($instance['data']);
  }

  $response = array(
    'instances' => $data,
  );
  return $response;
}

function track_instance_dbload_by_filter($filters, $decode_types = array(), $decode_mode = 'object') {
  global $db, $db_tableprefix, $settings;

  $conditions = isset($filters['conditions']) ? $filters['conditions'] : array();
  $vars = array();
  //$query_str = "SELECT * FROM {$db_tableprefix}realtime";
  $query_str = "SELECT data FROM {$db_tableprefix}realtime";
  if (!empty($conditions)) {
    $query_str .= ' WHERE ';
    $count = 0;
    foreach ($conditions AS $i => $cond) {
      $hash = ':' . $cond[0];
      // check if hash name is unique
      if (isset($vars[$hash])) {
        $hash = $hash . '_' . $i;
      }
      $vars[$hash] = $cond[1];
      if ($count) {
        $query_str .= ' AND ';
      }
      $query_str .= $cond[0];
      $query_str .= isset($cond[2]) ? $cond[2] : '=';
      $query_str .= $hash;
      $count++;
    }
  }
  $query = $db->prepare($query_str);
  $query->execute($vars);
  $instances = $query->fetchAll(\PDO::FETCH_ASSOC);

  return $instances;
}

function track_utmz_parser($utmz, $sepChar = '%7C', $equalChar = '=') {
  $data = (object)array();

  $utmz_b = strstr($utmz, 'u');
  $utmz_a = substr($utmz, 0, strpos($utmz, $utmz_b) - 1);

  //assign variables to first half of cookie
  list($utmz_domainHash, $utmz_timestamp, $utmz_sessionNumber, $utmz_campaignNumber) = explode('.', $utmz_a);

  //break apart second half of cookie
  $utmzPairs = array();
  $z = explode($sepChar, $utmz_b);
  foreach ($z as $value) {
    $v = explode($equalChar, $value);
    $utmzPairs[$v[0]] = $v[1];
  }

  //Variable assignment for second half of cookie
  foreach ($utmzPairs as $key => $value) {
    switch ($key) {
      case 'utmcsr':
        $data->source = $value;
        break;
      case 'utmcmd':
        $data->medium = $value;
        break;
      case 'utmctr':
        $data->term = $value;
        break;
      case 'utmcct':
        $data->content = $value;
        break;
      case 'utmccn':
        $data->campaign = $value;
        break;
      case 'utmgclid':
        $data->gclid = $value;
        break;
      default:
        //do nothing
    }
  }
  return $data;
}