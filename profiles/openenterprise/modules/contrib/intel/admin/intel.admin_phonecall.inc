<?php
/**
 * @file
 * Administration of phonecall data
 * 
 * @author Tom McCracken <tomm@getlevelten.com>
 */

function intel_phonecall_page($cid) {
  
  $phonecall = intel_phonecall_load($cid);
  $visitor = intel_visitor_load((int)$phonecall->vid);
  $phonenumber = intel_phonenumber_load_by_number($phonecall->to_num);
  //if (!empty($phonecall->visitorid)) {
    //$visitor = intel_visitor_load_by_visitorid($phonecall->visitorid);
  //}
  if (!empty($_GET['debug'])) {
    dpm('$phonecall'); dpm($phonecall);//
    dpm('$visitor'); dpm($visitor);//
    dpm('$phonenumber'); dpm($phonenumber);//
  }
  $type = str_replace('_', ' ', $phonecall->type);
  drupal_set_title(t('@type phone call', array('@type' => $type)), PASS_THROUGH);
  $output = '';
  
  $form = array();
  
  if ($link) {
    $form['data']['photo'] = array(
      '#type' => 'markup',
      '#markup' => $link . "<br>\n<br>\n",
    );
  }
  
  $form['initiated_by'] = array(
    '#type' => 'item',
    '#title' => t('Initiated by'),
    '#markup' => l($visitor->label(), $visitor->uri()),
  );

  $form['initiated_at'] = array(
    '#type' => 'item',
    '#title' => t('Initiated at'),
    '#markup' => date("Y-m-d H:i", $phonecall->initiated),
  );

  $form['from_num'] = array(
    '#type' => 'item',
    '#title' => t('From'),
    '#markup' => $phonecall->from_num,
  );

  $form['to_num'] = array(
    '#type' => 'item',
    '#title' => t('To'),
    '#markup' => $phonecall->to_num . ((!empty($phonenumber['title'])) ? ' (' . $phonenumber['title'] . ')' : ''),
  );

  $output = render($form);
  
  return $output;
}

function intel_admin_people_phonecalls($filter = array()) {
  $output = "";
  $api_level = variable_get('intel_api_level', '');
  $header = array();
  $header[] = array(
    'data' => t('Name'),
    'field' => 'v.name',
  );
  if ($api_level == 'pro') {
    $header[] = array(
      'data' => t('Location'),
    );
  }
  $header[] = array(
      'data' => t('Initiated'),
      'field' => 'c.initiated',
      'sort' => 'desc',
  );
  $header[] = array(
    'data' => t('Type'),
    'field' => 'c.type',
  );
  $header[] = array(
    'data' => t('Number'),
    'field' => 'c.to_num',
  );
  $header[] = array(
    'data' => t('Operations'),
  );

  if (empty($filter['conditions'])) {
    $filter['conditions'] = array(
      array('c.vid', 0, '!='),
    );
  }
  $options = array();
  $result = intel_load_filtered_phonecall_result($filter, $options, $header, 50);

  $phonecalls = array();
  $vids = array();
  while ($r = $result->fetchObject()) {
    $vids[$r->vid] = $r->vid;
    $phonecalls[$r->cid] = $r;
  }
  $vids = array_values($vids);
  $visitors = intel_visitor_load_multiple($vids);

  $rows = array();
  foreach ($phonecalls AS $cid => $phonecall) {

    // if visitor doesn't exist (anymore) skip
    if (empty($visitors[$phonecall->vid])) {
      continue;
    }
    $visitor = $visitors[$phonecall->vid];

    $row = array();
    $ops = l(t('meta'), 'phonecall/' . $phonecall->cid);
    $row[] = $visitor->label_link();
    if ($api_level == 'pro') {      
      $row[] = $visitor->location();
    }
    $row[] = ((REQUEST_TIME - $phonecall->initiated) > 604800) ? format_date($phonecall->initiated, 'short') : format_interval(REQUEST_TIME - $phonecall->initiated) . t(' ago');
    $row[] = $phonecall->type;
    $row[] = $phonecall->to_num;
    $row[] = $ops;
    $rows[] = $row;
  }

  $vars = array(
    'header' => $header, 
    'rows' => $rows, 
  );
  $output .= theme('table', $vars);
  //pager_default_initialize($total, 1, $element = 0);
  $output .= theme('pager');

  return $output;
}