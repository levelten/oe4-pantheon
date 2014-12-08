<?php
/**
 * @file
 * Administration of emailclick data
 * 
 * @author Tom McCracken <tomm@getlevelten.com>
 */

function intel_emailclick_page($cid) {
  
  $emailclick = intel_emailclick_load($cid);
  $visitor = intel_visitor_load((int)$emailclick->vid);
  //$phonenumber = intel_phonenumber_load_by_number($emailclick->to_num);
  //if (!empty($emailclick->visitorid)) {
    //$visitor = intel_visitor_load_by_visitorid($emailclick->visitorid);
  //}
  if (!empty($_GET['debug'])) {
    dpm('$emailclick'); dpm($emailclick);//
    dpm('$visitor'); dpm($visitor);//
    //dpm('$phonenumber'); dpm($phonenumber);//
  }
  $type = str_replace('_', ' ', $emailclick->type);
  drupal_set_title(t('Email click', array('@type' => $type)), PASS_THROUGH);
  $output = '';
  
  $form = array();
  
  if ($link) {
    $form['data']['photo'] = array(
      '#type' => 'markup',
      '#markup' => $link . "<br>\n<br>\n",
    );
  }
  
  $form['visitor'] = array(
    '#type' => 'item',
    '#title' => t('Visitor'),
    '#markup' => l($visitor->label(), $visitor->uri()),
  );

  $form['clicked_at'] = array(
    '#type' => 'item',
    '#title' => t('Clicked at'),
    '#markup' => date("Y-m-d H:i", $emailclick->clicked),
  );

  $form['type'] = array(
    '#type' => 'item',
    '#title' => t('Type'),
    '#markup' => $emailclick->type,
  );

  $form['email_id'] = array(
    '#type' => 'item',
    '#title' => t('Email'),
    '#markup' => $emailclick->eid,
  );

  if ($emailclick->type == 'mailchimp') {
    $campaigns = intel_mailchimp_api_campaigns_list_by_campaign_id($emailclick->eid);
    if (isset($campaigns[$emailclick->eid])) {
      $link_options = array(
        'attributes' => array(
          'target' => 'mailchimp',
        ),
      );
      $form['email_id']['#markup'] = l( $campaigns[$emailclick->eid]['title'], $campaigns[$emailclick->eid]['archive_url_long'], $link_options);
    }
  }

  $email_links = array();

  if ($emailclick->response_page_path) {
    $url = "http://" . $emailclick->response_page_host . $emailclick->fresponse_page_path;
    if ($emailclick->response_page_id) {
      $url = 'node/' . $emailclick->response_page_id;
    }
    $markup = l(url($url), $url);
  }
  else {
    $markup = '(not set)';
  }

  $form['response_page'] = array(
    '#type' => 'item',
    '#title' => t('To page'),
    '#markup' => $markup,
  );

  $output = render($form);
  
  return $output;
}

function intel_admin_people_emailclicks($filter = array()) {
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
      'data' => t('Time'),
      'field' => 'c.clicked',
      'sort' => 'desc',
  );
  $header[] = array(
    'data' => t('Type'),
    'field' => 'c.type',
  );
  $header[] = array(
    'data' => t('Email'),
    'field' => 'c.eid',
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
  $result = intel_load_filtered_emailclick_result($filter, $options, $header, 50);

  $emailclicks = array();
  $vids = array();
  while ($r = $result->fetchObject()) {
    $vids[$r->vid] = $r->vid;
    $emailclicks[$r->cid] = $r;
  }
  $vids = array_values($vids);
  $visitors = intel_visitor_load_multiple($vids);

  $email_info = array();
  $rows = array();
  foreach ($emailclicks AS $cid => $emailclick) {

    // if visitor doesn't exist (anymore) skip
    if (empty($visitors[$emailclick->vid])) {
      continue;
    }
    $visitor = $visitors[$emailclick->vid];

    $row = array();
    $ops = l(t('meta'), 'emailclick/' . $emailclick->cid);
    $row[] = $visitor->label_link();
    if ($api_level == 'pro') {      
      $row[] = $visitor->location();
    }
    $row[] = ((REQUEST_TIME - $emailclick->clicked) > 604800) ? format_date($emailclick->clicked, 'short') : format_interval(REQUEST_TIME - $emailclick->clicked) . t(' ago');
    $row[] = $emailclick->type;


    $emaildesc = $emailclick->eid;

    // TODO: move mailchimp info processing to hook and process in mailchimp module

    if ($emailclick->type == 'mailchimp') {
      if (!isset($email_info['mailchimp'])) {
        $email_info['mailchimp'] = array();
      }
      if (!isset($email_info['mailchimp'][$emailclick->eid])) {
        $campaigns = intel_mailchimp_api_campaigns_list_by_campaign_id($emailclick->eid);
        if (isset($campaigns[$emailclick->eid])) {
          $email_info['mailchimp'][$emailclick->eid] = $campaigns[$emailclick->eid];
        }
      }
      if (isset($email_info['mailchimp'][$emailclick->eid]['archive_url_long'])) {
        $link_options = array(
          'attributes' => array(
            'target' => 'mailchimp',
          ),
        );
        $emaildesc = l( $campaigns[$emailclick->eid]['title'], $campaigns[$emailclick->eid]['archive_url_long'], $link_options);
      }
    }

    $row[] = $emaildesc;
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