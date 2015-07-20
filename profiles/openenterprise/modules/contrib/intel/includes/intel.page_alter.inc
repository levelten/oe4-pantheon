<?php
/**
 * @file
 * Support for adding intelligence to pages and processing form submissions
 * 
 * @author Tom McCracken <tomm@getlevelten.com>
 */

function intel_page_alter(&$page) {
  require_once drupal_get_path('module', 'intel') . "/includes/intel.ga.inc";
  global $user;

  $api_level = intel_api_level();

  $parsed_url = intel_parse_cms_url();

  $config = array(
    'debug' => intel_debug_mode(),
    // cmsHostpath, modulePath & apiPath are not standard io settings. They are used
    // exclusivly by intel module js.
    'cmsHostpath' => $parsed_url['hostpath'],
    'modulePath' => drupal_get_path('module', 'intel'),
    'libPath' => intel_get_library_path(),
    //'cms_hostpath' => $parsed_url['hostpath'],
    //'module_path' => drupal_get_path('module', 'intel'),
    'systemPath' => $_GET['q'],
    'systemHost' => $parsed_url['host'],
    'systemBasepath' => $parsed_url['base_path'],
    'srl' => $_GET['q'],
    //'lib_path' => intel_get_library_path(),
    'pageTitle' => '(not set)',
    'trackAnalytics' => 1, // this is set in intel_js_alter if ga script exists
    'trackAdhocCtas' => ($api_level == 'pro') ? 'track-cta' : '',
    'trackAdhocEvents' => 'track-event',
    'trackForms' => array(),
    'trackRealtime' => variable_get('intel_track_realtime', INTEL_TRACK_REALTIME_DEFAULT),
    'isLandingpage' => 0,
    'scorings' => intel_get_scorings('js_setting'),
    'storage' => array(
      'page' => array(
	      'analytics' => array(),
	    ),
      'session' => array(
	      'analytics' => array(),
	    ),
      'visitor' => array(
	      'analytics' => array(),
	    ),
    ),
  );

  if ($a = variable_get('intel_domain_name', '')) {
    $config['cookieDomain'] = $a;
  }

  $path_is_admin = path_is_admin(current_path());
  
  $ga_va = array();
  if ($user->uid) {
    if (intel_include_library_file('class.visitor.php')) {
      $ga_va = \LevelTen\Intel\ApiVisitor::extractCookieVa();
    }
  }  

  $entity = '';
  $entity_type = '';
  $intel_events = intel_get_intel_event_info();
  $page_events = array();
  $page_attrs = array();
  $visitor_attrs = array();

  intel_add_page_intel_push(array('set', "p.systemPath", $_GET['q']));

  // if entity not provided, lookup based on menu path
  if (arg(0) == 'node') {
    $entity = menu_get_object();
    $entity_type = 'node';
  }
  elseif (arg(0) == 'user') {
    $entity = menu_get_object('user');
    $entity_type = 'user';
  }

  $config['pageTitle'] = isset($entity->title) ? $entity->title : drupal_get_title();

  if ($entity_type && !empty($entity)) {
    $attrs = intel_get_entity_intel_attributes($entity, $entity_type, 1);
    $page_attrs = $attrs['page'];
    $visitor_attrs = $attrs['visitor'];
    $page_events = $attrs['events'];
  }

  if ($path_is_admin) {
    $intent = 'a';
  }

  // check if page intent is landing page
  if (isset($page_attrs['i']) && isset($page_attrs['i']['l'])) {
    $config['isLandingpage'] = 1;
    if ($api_level == 'pro') {
      //$page_events['landing_page_view'] = $intel_events['landing_page_view'];
    }
  }

  // set user role visitor attribute
  // only when user is logged in (otherwise page caching will cause errors)
  if ($user->uid) {
    $cur = isset($ga_va['r']) ? $ga_va['r'] : array();
    foreach ($user->roles AS $i => $l) {
      // don't send anonymous role
      if ($i == 1) {
        continue;
      }
      if (!isset($cur[$i])) {
        if (!isset($visitor_attrs['r'])) {
          $visitor_attrs['r'] = array();
        }
        $visitor_attrs['r'][$i] = '';
      }
    }
  }

  $page_attrs_info = intel_get_page_attribute_info();
  foreach ($page_attrs AS $key => $value) {
    if (isset($page_attrs_info[$key]['storage']) && is_array($page_attrs_info[$key]['storage'])) {
      foreach ($page_attrs_info[$key]['storage'] AS $namespace => $sv) {
        if (!isset($config['storage']['page'][$namespace])) {
          $config['storage']['page'][$namespace] = array();
        }
        $config['storage']['page'][$namespace][$key] = $sv;
      }
      // special exception for published age since it needs to be calculated in JS.
      if ($key == 'pd') {
        $config['storage']['page']['analytics']['pda'] = $page_attrs_info['pda']['storage']['analytics'];
      }
    }
    if (is_array($value)) {
      foreach ($value AS $key2 => $value2) {
        intel_add_page_intel_push(array('set', "pa.$key.$key2", $value2));
      }
    }
    else {
      intel_add_page_intel_push(array('set', "pa.$key", $value));
    }
  }

  $visitor_attrs_info = intel_get_visitor_attribute_info();
  foreach ($visitor_attrs AS $key => $value) {
    if (isset($visitor_attrs_info[$key]['storage'])) {
      foreach ($visitor_attrs_info[$key]['storage'] AS $namespace => $sv) {
        if (!isset($config['storage']['visitor'][$namespace])) {
          $config['storage']['visitor'][$namespace] = array();
        }
        $config['storage']['visitor'][$namespace][$key] = $sv;
      }
    }

    if (is_array($value)) {
      foreach ($value AS $key2 => $value2) {
        intel_add_page_intel_push(array('set', "va.$key.$key2", $value2));
      }
    }
    else {
      intel_add_page_intel_push(array('set', "va.$key", $value));
    }
  }

  // add events set to be applied to all pages
  $all_page_events = intel_intel_event_all_pages_load();
  $page_events = array_merge($page_events, $all_page_events);

  foreach ($page_events AS $key => $value) {
    $l10i_event_action = $value;
    //$l10i_event_action['method'] = '_addIntelEvent';
    //$l10i_event_action['method'] = 'event';

    if (!empty($l10i_event_action['valued_event'])) {
      $l10i_event_action['category'] .= '!';
    }

    $l10i_event_action = intel_filter_event_for_push($l10i_event_action);
    intel_add_page_intel_push(array('event', $l10i_event_action));
  }


  //intel_check_user_login($page);

  intel_check_form_submission($page);
  
  // check form processing
  // this is a hack to exclude webform's submission redirect page
  $track_forms = array();
  if ($entity_type == 'node' && isset($entity->type) && ($entity->type == 'webform')) {
    // check if page is a webform submit validation
    if (!empty($_POST['form_id']) && (substr($_POST['form_id'], 0, 20) == 'webform_client_form_')) {
      $track_forms = 0;
    }
  }

  //if (isset($node->type) && ($node->type == 'enterprise_landingpage')) {
  //  $is_landingpage = 1;
  //}

  // call hook for modules to add page pushes
  module_invoke_all('intel_page_intel_pushes');

  $pushes = intel_get_flush_page_intel_pushes();

  // add page title and system path to any IntelEvent that is missing values
  /*
  foreach ($pushes AS $i => $push) {
    if ($push['method'] == '_addIntelEvent') {
      if (empty($push['action'])) {
        $pushes[$i]['action'] = $page_title;
      }
      if (empty($push['label'])) {
        $pushes[$i]['label'] = $_GET['q'];
      }
    }
  }
  */

  if (isset($pushes['event']) && is_array($pushes['event'])) {
    foreach ($pushes['event'] AS $i => $push) {
      if (empty($push['action']) && empty($push['eventAction']) ) {
        $pushes['event'][$i]['eventAction'] = $config['pageTitle'];
      }
      if (empty($push['label']) && empty($push['eventLabel'])) {
        $pushes['event'][$i]['eventLabel'] = $_GET['q'];
      }
    }
  }

  //watchdog('intel_page_alter_pushes', print_r($pushes, 1));

  $parsed_url = intel_parse_cms_url();
  $js = array(
    'intel' => array(
      'config' => $config,
      'pushes' => $pushes,
    ),
    // TODO: move this to intel_disqus
    'disqus' => array(
      'callbacks' => array(
        'onNewComment' => array('_ioq.plugins.disqus.triggerComment'),
      ),
    ),
  );

  if ($ga_domain = variable_get('intel_domain_name', '')) {
    $js['intel']['config']['cookieDomain'] = $ga_domain;
  }

  // Get page status code for visibility filtering.
  $id = variable_get('googleanalytics_account', '');
  $status = drupal_get_http_header('Status');
  $trackable_status_codes = array(
    '403 Forbidden',
    '404 Not Found',
  );
  $track = 1;
  if (!(_googleanalytics_visibility_pages() || in_array($status, $trackable_status_codes)) && _googleanalytics_visibility_user($user)) {
    $track = 0;
    // TODO: Intel GA tracking should track google_analytics module settings
    //$js['intel']['config']['track_analytics'] = 0;
  }
  if (path_is_admin(current_path())) {
    $track = 0;  
  }
  if (!$track) {
    $js['intel']['config']['track_forms'] = 0;
    $js['intel']['config']['track_adhoc_ctas'] = 0;
    $js['intel']['config']['track_adhoc_events'] = 0;
  }
  else {
    $scripts = intel_intel_scripts();
    $enabled = variable_get('intel_intel_scripts_enabled', array());
    foreach ($scripts AS $key => $script) {
      if (!empty($enabled[$key]) || (!isset($enabled[$key]) && !empty($script['enabled']))) {
        drupal_add_js($script['path']);
      }
    }
  }

  
  if (!empty($_GET['debug'])) {
    if ($_GET['debug'] == 'ie9') {
      $script = "http://ie.microsoft.com/testdrive/HTML5/CompatInspector/inspector.js";
      drupal_add_js($script, array('scope' => 'header', 'type' => 'external', 'weight' => -10, 'group' => JS_LIBRARY));
    }
  }
  /*
  $script = variable_get('intel_js_monitor_script', '');
  if ($script) {
    drupal_add_js($script, array('type' => 'inline', 'scope' => 'header', 'weight' => -99, 'group' => -101));
  }
  */
  
  $script = intel_get_js_embed('l10i', 'local');
  //drupal_add_js($script, array('type' => 'inline', 'scope' => 'header', 'weight' => -1, 'group' => JS_LIBRARY));
  drupal_add_js($script, array('type' => 'inline', 'scope' => 'header', 'weight' => 0));

  /**
   * check admin alter enhancements
   */
  if ($_GET['q'] == 'admin/content') {
    drupal_add_css(drupal_get_path('module', 'intel') . '/css/intel.report.css');
    drupal_add_js(drupal_get_path('module', 'intel') . '/js/intel.admin_content_alter.js');
  }
  if ($_GET['q'] == 'admin/content/cta') {
    drupal_add_js(drupal_get_path('module', 'intel') . '/js/intel.admin_content_cta_alter.js');
  }

  drupal_alter('intel_page_settings_js', $js, $page);
  if (!empty($_GET['debug'])) {
    dsm('js'); dsm($js);
  }
  drupal_add_js($js, 'setting');
}

function intel_get_entity_intel_attributes($entity = '', $entity_type = '', $include_events = 0) {
  global $user;
  $visitor_attrs = array();
  $page_attrs = array();
  $page_events = array();

  // if entity not found, return empty attributes
  if (!$entity || !$entity_type) {
    return array(
      'page' => $page_attrs,
      'visitor' => $visitor_attrs,
    );
  }
//dsm($entity);
  $entity_info = entity_get_info($entity_type);
  $entity_attrs = array();

  $page_attr_info = intel_get_page_attribute_info();

  // resource type = entity_type
  $page_attrs['rt'] = $entity_type;
  // resource sub type = entity bundle
  if (isset($entity_info['entity keys']['bundle']) && isset($entity->{$entity_info['entity keys']['bundle']})) {
    $page_attrs['rt2'] = $entity->{$entity_info['entity keys']['bundle']};
    $page_attrs['rt2'] = str_replace('enterprise_', '', $page_attrs['rt2']); // trim enterprise namespace in Open Enterprise
  }
  // resource id = entity_id
  if (isset($entity_info['entity keys']['id']) && isset($entity->{$entity_info['entity keys']['id']})) {
    $page_attrs['rk'] = $entity->{$entity_info['entity keys']['id']};
    $entity_attrs = intel_entity_attr_load_by_params($entity_type, $page_attrs['rk']);

    if (is_array($entity_attrs)) {
      foreach ($entity_attrs AS $ea) {
        if (!isset($page_attr_info[$ea->attr_key])) {
          continue;
        }

        if ($page_attr_info[$ea->attr_key]['type'] == 'list' || $page_attr_info[$ea->attr_key]['type'] == 'vector') {
          $value_str = intel_index_encode($ea->attr_key);
          if (!isset($page_attrs[$ea->attr_key])) {
            $page_attrs[$ea->attr_key] = array();
          }
          if (!empty($page_attr_info[$ea->attr_key]['encode']) && isset($ea->vsid)) {
            $index = intel_index_encode($ea->vsid);
          }
          else {
            $index = isset($ea->value_str) ? $ea->value_str : $ea->value;
          }
          if ($page_attr_info[$ea->attr_key]['type'] == 'vector') {
            $page_attrs[$ea->attr_key][$index] = !empty($ea->value_num) ? $ea->value_num : 0;
          }
          else {
            $page_attrs[$ea->attr_key][$index] = '';
          }
        }
        else {
          $page_attrs[$ea->attr_key] = $ea->value;
          if (!empty($page_attr_info[$ea->attr_key]['encode']) && isset($ea->vsid)) {
            $page_attrs[$ea->attr_key] = intel_index_encode($ea->vsid);
          }
        }
      }
    }

    // create an empty entity_attr in case some attr needs to be saved
    $entity_attr = (object)array(
      'entity_type' => $page_attrs['rt'],
      'entity_id' => $page_attrs['rk'],
    );
  }
  // resource vid = entity vid
  if (isset($entity_info['entity keys']['revision']) && isset($entity->{$entity_info['entity keys']['revision']})) {
    //$page_attrs['rvi'] = $entity->{$entity_info['entity keys']['revision']};
  }

  // resource table = entity label
  if (isset($entity_info['entity keys']['label']) && isset($entity->{$entity_info['entity keys']['label']})) {
    //$page_attrs['rtl'] = $entity->{$entity_info['entity keys']['label']};
  }
  // resource language
  if (isset($entity_info['entity keys']['language']) && isset($entity->{$entity_info['entity keys']['language']}) && ($entity->{$entity_info['entity keys']['language']} != LANGUAGE_NONE)) {
    $page_attrs['lang'] = $entity->{$entity_info['entity keys']['language']};
  }

  // ? not sure if this is needed or enhances performance
  if (isset($entity->created)) {
    $val = date('YmdHiw', $entity->created);
    if (empty($page_attrs['pd']) || ($page_attrs['pd'] != $val)) {
      $page_attrs['pd'] = $val;
      /*
      if (isset($entity_attr)) {
        $entity_attr->attr_key = 'pd';
        $entity_attr->value = $val;
        intel_entity_attr_save($entity_attr);
      }
      */
    }
    /*
    $page_attrs['pd'] = $entity->created;
    $val = (int)date('w', $entity->created);

    // day of week
    if (!isset($page_attrs['pdw']) || ($page_attrs['pdw'] == $val)) {
      $page_attrs['pdw'] = $val;
      if (isset($entity_attr)) {
        $entity_attr->attr_key = 'pdw';
        $entity_attr->value = $val;
        intel_entity_attr_save($entity_attr);
      }
    }

    // hour of day
    $val = (int)date('Hi', $entity->created);
    if (!isset($page_attrs['pdt']) || ($page_attrs['pdt'] == $val)) {
      $page_attrs['pdt'] = $val;
      if (isset($entity_attr)) {
        $entity_attr->attr_key = 'pdt';
        $entity_attr->value = $val;
        intel_entity_attr_save($entity_attr);
      }
    }
    */
  }

  $uri = entity_uri($entity_type, $entity);
  if (!empty($uri['path'])) {
    $page_attrs['rl'] = $uri['path'];
    //$page_attrs['url'] = url($page_attrs['rl']);
  }
  //dsm($page_attrs);




//dsm($entity->uri);

  if ($entity_type == 'node') {
    $entity_bundle = $entity->type;
    $page_title = $entity->title;

    $path_entity = 1;
  }
  elseif ($entity_type == 'user') {
    $entity_bundle = 'user';

    //$page_attrs['pt'] = $entity->created;
    //$page_attrs['et'] = 'user';
    $path_entity = 1;
  }

  $page_entity_settings = array();
  if (!empty($entity_type) && !empty($entity_bundle)) {
    $page_entity_settings = variable_get('intel_entity_settings_' . $entity_type . '__' . $entity_bundle, array());
  }

  $lang = !empty($entity->language) ? $entity->language : LANGUAGE_NONE;
  $fields_info = field_info_instances($entity_type, $entity_bundle);
  // track entity uid (e.g. node author)
  if (!isset($page_entity_settings['track_page_uid']) || $page_entity_settings['track_page_uid']) {
    $key = !empty($page_entity_settings['track_page_uid']) ? $page_entity_settings['track_page_uid'] : 'a';
    if ($key == 1) {
      $key = 'a';
    }
    $page_attrs[$key] = $entity->uid;
  }

  // track page intent
  $intent = INTEL_PAGE_INTENT_DEFAULT;

  if (!empty($page_entity_settings['page_intent'])) {
    $intent = $page_entity_settings['page_intent'];
  }
  if (!empty($entity->field_page_intent[$lang][0]['value']) && ($entity->field_page_intent[$lang][0]['value'] != '_default')) {
    $intent = $entity->field_page_intent[$lang][0]['value'];
  }
  if ($intent) {
    $page_attrs['i'] = array(
      $intent => '',
    );
  }

  $vocab_entity_settings = intel_get_entity_settings_multi('taxonomy');

  // process vocabularies with global tracking enabled
  foreach ($fields_info AS $key => $field) {
    if (isset($entity->{$key}[$lang][0]['tid'])) {
      // get field_info to get associated vocabulary
      $field_info = field_info_field($key);
      $vocab_name = $field_info['settings']['allowed_values'][0]['vocabulary'];
      // check if tracking is enabled at the content type level or on globally on the vocabulary
      if (!empty($page_entity_settings['track_term_fields'][$key]) || !empty($vocab_entity_settings[$vocab_name]['track_page_terms'])) {
        $page_attr_key = !empty($vocab_entity_settings[$vocab_name]['page_attribute']['key']) ? $vocab_entity_settings[$vocab_name]['page_attribute']['key'] : 't';
        foreach ($entity->{$key}[$lang] AS $t) {
          if (!isset($page_attrs[$page_attr_key])) {
            $page_attrs[$page_attr_key] = array();
          }
          $page_attrs[$page_attr_key][$t['tid']] = '';
          if (!empty($vocab_entity_settings[$vocab_name]['track_page_terms_visitor'])) {
            $visitor_attr_key = !empty($vocab_entity_settings[$vocab_name]['visitor_attribute']['key']) ? $vocab_entity_settings[$vocab_name]['visitor_attribute']['key'] : $page_attr_key;
            if (!isset($visitor_attrs[$visitor_attr_key])) {
              $visitor_attrs[$visitor_attr_key] = array();
            }
            $visitor_attrs[$visitor_attr_key][$t['tid']] = '=+1';
          }
        }
      }
    }
  }

  // set custom page attributes if page_attribute_col field exists
  if (!empty($entity->field_page_attribute_col[$lang]) && is_array($entity->field_page_attribute_col[$lang])) {
    foreach ($entity->field_page_attribute_col[$lang] AS $i => $e) {
      $collection = field_collection_item_load($e['value']);
      $keys = explode('.', $collection->field_page_attribute[$lang][0]['value']);
      $value = !empty($collection->field_page_attribute_value[$lang][0]['value']) ? $collection->field_page_attribute_value[$lang][0]['value'] : '';
      if (count($keys) == 1) {  // flag and scalar values
        $page_attrs[$keys[0]] = $value;
      }
      else {
        if (!isset($page_attrs[$keys[0]])) {
          $page_attrs[$keys[0]] = array();
        }
        $page_attrs[$keys[0]][$keys[1]] = $value;
      }
    }
  }

  // set custom visitor attributes if visitor_attribute_col field exists
  if (!empty($entity->field_visitor_attribute_col[$lang]) && is_array($entity->field_visitor_attribute_col[$lang])) {
    foreach ($entity->field_visitor_attribute_col[$lang] AS $i => $e) {
      $collection = field_collection_item_load($e['value']);
      $keys = explode('.', $collection->field_visitor_attribute[$lang][0]['value']);
      $value = !empty($collection->field_visitor_attribute_value[$lang][0]['value']) ? $collection->field_visitor_attribute_value[$lang][0]['value'] : '';
      if (count($keys) == 1) {  // flag and scalar values
        $visitor_attrs[$keys[0]] = $value;
      }
      else {
        if (!isset($visitor_attrs[$keys[0]])) {
          $visitor_attrs[$keys[0]] = array();
        }
        $visitor_attrs[$keys[0]][$keys[1]] = $value;
      }
    }
  }

  // set attached intel events if intel_event_col field exists
  // TODO get page events working

  if ($include_events) {
    if (!empty($entity->field_intel_event_col[$lang]) && is_array($entity->field_intel_event_col[$lang])) {
      $intel_event_info = intel_get_intel_event_info();
      foreach ($entity->field_intel_event_col[$lang] AS $i => $e) {
        $collection = field_collection_item_load($e['value']);
        $key = $collection->field_intel_event[$lang][0]['value'];
        $page_events[$key] = $intel_event_info[$key];

        if(!empty($collection->field_intel_event_value[$lang][0]['value'])) {
          $page_events[$key]['value'] = $collection->field_intel_event_value[$lang][0]['value'];
        }

      }
    }
  }

  $attrs = array(
    'page' => $page_attrs,
    'visitor' => $visitor_attrs,
    'events' => $page_events,
  );

  // allow modules to add/alter attributes
  drupal_alter('intel_entity_intel_attributes', $attrs, $entity, $entity_type);

  return $attrs;
}

function intel_add_page_intel_push($push, $index = '') {
  return intel_page_intel_pushes('add', $push, $index);
}

function intel_get_page_intel_pushes() {
  return intel_page_intel_pushes('get');
}

function intel_get_flush_page_intel_pushes() {
  return intel_page_intel_pushes('get_flush');
}

function intel_page_intel_pushes($action = 'get', $push = array(), $index = '') {

  if (!isset($_SESSION['intel_page_pushes'])) {
    $_SESSION['intel_page_pushes'] = array();
  }
  if ($action == 'add') {
    // if push is assoc array containing method key, use that key
    if (!empty($push['method'])) {
      $method = $push['method'];
      unset($push['method']);
    }
    else {
      $method = array_shift($push);
    }

    if (!isset($_SESSION['intel_page_pushes'][$method])) {
      $_SESSION['intel_page_pushes'][$method] = array();
    }

    if ($method == 'set') {
      $index = $push[0];
      $value = $push[1];
    }
    else if ($method == 'event') {
      $index = count($_SESSION['intel_page_pushes'][$method]);
      $value = $push[0];
    }
    else {
      $index = count($_SESSION['intel_page_pushes'][$method]);
      $value = $push;
    }

    $_SESSION['intel_page_pushes'][$method][$index] = $value;
  }
  $ret = $_SESSION['intel_page_pushes'];
  if ($action == 'get_flush') {
    unset($_SESSION['intel_page_pushes']);
    //$_SESSION['intel_page_pushes'] = array();
  }
  return $ret;
}

/**
 * Sanitizes event tracking data that is being put into javascript.
 */
function _intel_ga_event_sanitize_events($ga_events) {
  if (is_array($ga_events)) {
    foreach ($ga_events as $i => $event) {
      foreach ($event as $j => $e) {
        $ga_events[$i][$j] = filter_xss($e);
      }
    }
    return $ga_events;
  }
  else {
    return array();
  }
}

/**
 * Strips event metadata values not needed for page push
 * @param $event
 */
function intel_filter_event_for_push($event) {
  /*
  if (isset($event['valued_event'])) {
    unset($event['valued_event']);
  }
  if (isset($event['title'])) {
    unset($event['title']);
  }
  if (isset($event['module'])) {
    unset($event['module']);
  }
  if (isset($event['description'])) {
    unset($event['description']);
  }
  if (isset($event['enable_all_pages'])) {
    unset($event['enable_all_pages']);
  }
  if (isset($event['selectable'])) {
    unset($event['selectable']);
  }
  if (isset($event['custom'])) {
    unset($event['custom']);
  }
  if (isset($event['key'])) {
    unset($event['key']);
  }
  */

  // translate from classic format to UA format
  $trans = array(
    'category' => 'eventCategory',
    'action' => 'eventAction',
    'label' => 'eventLabel',
    'value' => 'eventValue',
    'selector' => 1,
    'selector_filter' => 'selectorFilter',
    'event' => 'onEvent',
    'noninteraction' => 'nonInteraction',
    'callback' => 'triggerCallback',
    'refresh_force' => 'refreshForce',
    'method' => 1,
    'eventCategory' => 1,
    'eventAction' => 1,
    'eventValue' => 1,
    'nonInteraction' => 1,
    'onEvent' => 1,
    'onSelector' => 1,
    'selectorFilter' => 1,
    'refreshForce' => 1,
  );
  foreach ($event as $k => $v) {
    if (isset($trans[$k])) {
      $t = $trans[$k];

      if (empty($v)) {
        if ($k == 'value') {
          if ($v !== 0 && $v !== "0") {
            unset($event[$k]);
            continue;
          }
        }
        else {
          unset($event[$k]);
          continue;
        }

      }

      if (is_string($t)) {
        $event[$t] = $v;
        unset($event[$k]);
      }



    }
    else {
      unset($event[$k]);
    }

  }

  if (isset($event['triggerCallback']) && !$event['triggerCallback']) {
    unset($event['triggerCallback']);
  }

  return $event;
}

function intel_trigger_intel_event($event) {
  // strip values not needed by javascript
  $event = intel_filter_event_for_push($event);

  intel_add_page_intel_push($event);
}

function intel_trigger_intel_event_by_name($event_name, $values = array()) {
  $event = intel_intel_event_load($event_name);
  if (empty($event)) {
    return;
  }
  if (!empty($event['valued_event'])) {
    $event['category'] .= '!';
  }
  if (empty($event['event'])) {
    $event['event'] = 'pageshow';
  }
  if (empty($event['selector'])) {
    $event['selector'] = 'body';
  }
  $values['method'] = '_addIntelEvent';
  // merge event values on $values
  $values += $event;
  return intel_trigger_intel_event($values);
}

function intel_print_var($var) {
  dsm($var);
}

function intel_init() {
  // Need to use drupal_add_html_head() instead of drupal_add_js() to load monitor script above all js.
  if ($script = variable_get('intel_js_monitor_script', '')) {
    drupal_add_html_head(
      array(
        '#type' => 'markup',
        '#markup' => "$script\n",
        '#weight' => -99,
      ), 
      'intel_js_monitor');
  }

  // hack to support dpm/dsm functions if devel not installed
  /*
  if (intel_debug_mode() && !module_exists('devel')) {
    if (!function_exists('dpm')) {
      function dpm($input) {
        print_r($input);//
      }
    }
    if (!function_exists('dsm')) {
      function dsm($input) {
        print_r($input);//
      }
    }
  }
  */

}


function intel_parse_cms_url() {
  $parsed_url = &drupal_static(__FUNCTION__);
  if (!empty($parse_url)) {
    return $parse_url;
  }

  global $base_root, $base_path;
  $url = $base_root . $base_path . '?';
  foreach ($_GET AS $key => $value) {
    $url .= '&' . $key . '=' . $value;
  }
  $parsed_url = parse_url($url);
  $parsed_url['base_path'] = $base_path;
  $parsed_url['hostpath'] = $parsed_url['host'] . ((!empty($parsed_url['port'])) ? ':' . $parsed_url['port'] : '') . $base_path;

  return $parsed_url;
}

/**
 * Generates async embed code for Intel. The generated code is designed to be
 * used on Drupal generated pages and on static pages via copy and paste.
 *
 * @param string $type -
 *   l10i: only code to embed intel,
 *   ga: Google Analytics code using Google Analytics module settings
 *   combined: provides GA and Intel embed codes. Used for external pages
 * @param string $mode:
 *   null | internal: sets format for use on Drupal generated pages
 *   external: used to set formating for external page use
 * @param string $version: used to experiment with embed styles
 * @param string $terminator: specifies end of line terminator
 * @return string - embed code
 */
function intel_get_js_embed($type = 'l10i', $mode = 'external', $version = 'latest', $terminator = "") {
  $script = '';
  $l10i_ga_account = variable_get('intel_ga_account', '');
  // if l01i_ga_account not set, don't generate embed
  if (!$l10i_ga_account) {
    return $script;
  }
  $api_level = intel_api_level();

  $io_name = 'io';

  $debug = intel_debug_mode();
  if ($debug) {
    $terminator = "\n";
  }

  $l10i_domain_name = variable_get('intel_domain_name', '');

  $l10i_ga_tracker_prefix = variable_get('intel_ga_tracker_prefix', '');
  if (!$l10i_ga_tracker_prefix) {
    $l10i_ga_tracker_prefix = 'l10i';
  }

  $api_js_ver = trim(variable_get('intel_l10iapi_js_ver', ''));
  if (!$api_js_ver) {
    $api_js_ver = INTEL_L10IAPI_JS_VER;
  }

  $js_embed_style = variable_get('intel_l10iapi_js_embed_style', '');

  // set if api is installed locally with website, e.g. enterprise mode
  $api_local = 0;

  $wrap = ($mode == 'external') ? 1 : 0;

  if ($version == 'simple') {
    $wrap = 0;
    $script .= '<script>' . $terminator;
  }

  // generate GoA embed based on Google Analtyics module settings
  if (($type == 'ga') || ($type == 'combined')) {
    $library_tracker_url = '.google-analytics.com/ga.js';
    $library_cache_url = 'http://www' . $library_tracker_url;
    if (variable_get('googleanalytics_cache', 0) && $url = _googleanalytics_cache($library_cache_url)) {   
      $ga_src = 'ga.src = "' . $url . $query_string . '";';
    }
    else {
      $ga_src = "ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';";
    }
    $gaid = variable_get('googleanalytics_account', '');
       
    $script .= "var _gaq = _gaq || [];" . $terminator;
    $script .= "_gaq.push(['_setAccount', '$gaid']);" . $terminator;
    if ($l10i_domain_name) {
      $script .= "_gaq.push(['_setDomainName', '$l10i_domain_name']);" . $terminator;
    }
    $script .= "_gaq.push(['_trackPageview']);" . $terminator;
    $script .= "(function() {" . $terminator;
    $script .= "var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;" . $terminator;
    $script .= $ga_src . $terminator;
    $script .= "var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);" . $terminator;
    $script .= "})();" . $terminator;
  }

  // generate Intel embed
  if ($api_level && (($type == 'l10i') || ($type == 'combined'))) {
    $library_path = libraries_get_path('LevelTen') . 'Intel/scripts';
    $api_hostpath = variable_get('intel_l10iapi_url', '');
    if (empty($api_hostpath)) {
      $api_hostpath = INTEL_L10IAPI_URL;
    }
    // if api_hostpathe is relative (begins with '/'), install is local
    else if (substr($api_hostpath, 0 ,1) == '/') {
      $api_hostpath = $_SERVER['HTTP_HOST'] . $api_hostpath;
      $api_local = 1;
    }
    // verify compatible js_embed_style with api_level and $api_local
    if ($api_level == 'pro' || $api_level == 'basic') {
      if (!$js_embed_style) {
        $js_embed_style = 'property';
      }
      if (!$js_embed_style == 'property_dynsesinit' && $api_level == 'basic' ) {
        $js_embed_style = 'property';
      }
    }
    else {
      $js_embed_style = 'standard';
    }
    // if enterprise installation, use standard embed
    if ($api_local) {
      $js_embed_style = 'standard';
    }

    $sv = (variable_get('intel_debug_mode', 0)) ? '' : '.min';
    //$script .= "// LevelTen Intelligence" . $terminator;
    //$script .= "var _l10iq = _l10iq || [];" . $terminator;
    if ($api_local) {
      $script .= 'var _l10iss = {"apiUrl": "' . $api_hostpath . '/", "apiLevel": "' . $api_level . '"};' . $terminator;
    }
    $l10iq_pushes = array();
    //$l10iq_pushes[] = array('_setAccount', $l10i_ga_account, $l10i_ga_tracker_prefix);
    $params = array();
    $params['name'] = $l10i_ga_tracker_prefix;
    if ($l10i_domain_name) {
      $params['cookieDomain'] =  $l10i_domain_name;
      //$l10iq_pushes[] = array('_setDomainName', $l10i_domain_name);
    }
    $l10iq_pushes[] = array('ga.create', $l10i_ga_account, 'auto', $params);

    //$l10iq_pushes[] = array('_setOptions', (object) array());
    //$l10iq_pushes[] = array('set', (object) array());

    // trigger alter to enable other modules to add pushes
    drupal_alter('intel_l10iq_pushes', $l10iq_pushes);
    //foreach ($l10iq_pushes AS $p) {
    //  $script .= "_l10iq.push(" . json_encode($p) . ");" . $terminator;
    //}
    if ($version == 'simple') {
      $script .= '</script>' . $terminator;
      $script .= '<script src="http://' . $api_hostpath . '/js/' . $api_js_ver . '/l10i' . $sv . '.js"></script>' . $terminator;
    }
    // default version (async)
    else {
      if ($s = trim(variable_get('intel_custom_embed_script', ''))) {
        $script .= $s;
      } else {
        if ($js_embed_style != 'standard') {
          $l10ijs_propdir = '';
          $q_script = '';
          if (($api_level == 'pro') || ($api_level == 'basic')) {
            $l10ijs_propdir = '/p/' . $l10i_ga_account;
            //if ($js_embed_style != 'property') {
            if ($api_level == 'pro') {
              $q_script = "if(c.indexOf('l10i_s=')==-1){s='?t='+t}";
              //$q_script = "if(c.indexOf('l10i_s=')==-1){q='?t='+t}";
            }
          }
          $l10ijs_path = '/js/' . $api_js_ver . '/l10i' . $sv . '.js';


          $script .= "(function(w,d,o,u,b,i,r,a,s,c,t){" . $terminator;
          $script .= "w['OEIntelObject']=r;" . $terminator;
          $script .= "w[r]=w[r]||function() {" . $terminator;
          $script .= "(w[r].q=w[r].q||[]).push(arguments)" . $terminator;
          $script .= "}," . $terminator;
          $script .= "t=1*new Date();" . $terminator;
          $script .= "a='l10i_bt=';s='';" . $terminator;
          $script .= "d.cookie=a+t;c=d.cookie;" . $terminator;
          //$script .= "console.log(w[r]);" . $terminator;
          $script .= "if(c&&c.indexOf(a)!=-1){u+=i;$q_script}u+=b+s;" . $terminator;
          $script .= "a=d.createElement(o),b=d.getElementsByTagName(o)[0];a.async=1;a.src=u;b.parentNode.insertBefore(a,b)" . $terminator;
          $script .= "})(window,document,'script','//$api_hostpath','$l10ijs_path','$l10ijs_propdir','$io_name');" . $terminator;
          /*
          $script .= "d=q=c='';t=new Date().getTime();" . $terminator;
          $script .= "document.cookie='l10i_bt='+t+';path=/';c=document.cookie;if(c&&c.indexOf('l10i_bt=')!=-1){d='$l10ijs_propdir';$q_script}" . $terminator;
          $script .= "(function(i,s,o,g,r,a,m){" . $terminator;
          $script .= "i['OEIntelObject']=r;" . $terminator;
          $script .= "i[r]=i[r] || function() {" . $terminator;
          $script .= "(i[r].q=i[r].q||[]).push(arguments)" . $terminator;
          $script .= "}," . $terminator;
          $script .= "i[r].l=1*new Date();" . $terminator;
          $script .= "a=s.createElement(o),m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)" . $terminator;
          //$script .= "})(window,document,'script','//$api_hostpath'+d+'$l10ijs_path','_l10iq');" . $terminator;
          $script .= "})(window,document,'script','//$api_hostpath'+d+'$l10ijs_path','io');" . $terminator;
          */

          /*
          $script .= "(function() {" . $terminator;
          $script .= "var l10i=document.createElement('script'); l10i.type='text/javascript'; l10i.async=true;d=q=c='';t=new Date().getTime();" . $terminator;
          $script .= "document.cookie='l10i_bt='+t+';path=/';c=document.cookie;if(c&&c.indexOf('l10i_bt=')!=-1){d='$l10ijs_propdir';$q_script}" . $terminator;
          $script .= "l10i.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + '$api_hostpath'+d+'$l10ijs_path'+q;" . $terminator;
          $script .= "var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(l10i, s);" . $terminator;
          $script .= "})();" . $terminator;
          */
        }
        else { // standard mode
          $fr = ($debug && 0) ? " + '?t=' + new Date().getTime()" : '';
          $script .= "(function() {" . $terminator;
          $script .= "var l10i = document.createElement('script'); l10i.type = 'text/javascript'; l10i.async = true;" . $terminator;
          $script .= "l10i.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + '$api_hostpath/js/$api_js_ver/l10i$sv.js'$fr;" . $terminator;
          $script .= "var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(l10i, s);" . $terminator;
          $script .= "})();" . $terminator;
        }
        foreach ($l10iq_pushes AS $p) {
          $p = substr(json_encode($p),1);
          $p = substr($p, 0 ,-1);
          $script .= "$io_name(" . $p . ");" . $terminator;
        }
      }
    }
  }

  if ($wrap) {
    $script = '<script>' . $script . '</script>'; 
  }

  return $script;
}

function intel_js_alter(&$javascript) {
  $debug = intel_debug_mode();
  $options = array();

  // get intel options various modules have added to for intel
  if (!empty($javascript['settings']['data']) && is_array($javascript['settings']['data'])) {
    foreach ($javascript['settings']['data'] AS $i => $v) {
      if (!empty($v['intel'])) {
        $options[] = $v['intel'];
      }
    }
  }
  // search through javascript settings for main intel and google analytics settings
  $i = 0;
  $intel_i = -1;
  $ga_i = -1;
  while (isset($javascript[$i])) {
    if (substr($javascript[$i]['data'], 0, 10) == 'var _l10iq') {
      $intel_i = $i;
    }
    else if (substr($javascript[$i]['data'], 0, 32) == '(function(w,d,o,u,b,i,r,a,s,c,t)') {
      $intel_i = $i;
    }
    //if (substr($javascript[$i]['data'], 0, 8) == 'var _gaq') {
    if (substr($javascript[$i]['data'], 0, 51) == '(function(i,s,o,g,r,a,m){i["GoogleAnalyticsObject"]') {
      $ga_i = $i;
    }
    // if we have found both intel & ga js, exit loop
    if (($intel_i >= 0) && ($ga_i >= 0)) {
      break;
    }
    $i++;
  }

  if ($intel_i >= 0) {
    $options = drupal_array_merge_deep_array($options);
    // if google_analtyics script is added, turn on track_analtyics flag
    if ($ga_i == -1) {
      $options['config']['trackAnalytics'] = 0;
      //$javascript[$intel_i]['weight'] = $javascript[$ga_i]['weight'] + 1;
    }

    // embed new UA style calls using new format
    $pushstr = '';
    /*
    foreach ($options['pushes'] AS $method => $args) {
      // only move newer style calls withough leading _
      if (substr($method, 0 , 1) != '_') {
        $pushstr .= "oei('$method', " . json_encode($args) . ");\n";
        unset($options['pushes'][$method]);
      }
    }
    */
    //$json = drupal_json_encode($options);
    $io_name = 'io';
    $pushstr = $io_name . '("set", "config", ' . drupal_json_encode($options['config']) . ');' . "\n";
    //$str = '_l10iq.push(["set", "config", ' . drupal_json_encode($options['config']) . ']);' . "\n";
    if (isset($options['pushes']) && is_array($options['pushes'])) {
      foreach ($options['pushes'] as $cm => $push) {
        $pushstr .= $io_name . '("' . $cm . '",' . drupal_json_encode($push) . ');' . "\n";
        //$str .= '_l10iq.push(["' . $cm . '",' . drupal_json_encode($push) . ']);' . "\n";
      }
    }
    $javascript[$intel_i]['data'] .= $pushstr;
    //$javascript[$intel_i]['data'] = str_replace('_l10iq.push(["set",{}]);', $str, $javascript[$intel_i]['data']) . $pushstr;
    //$javascript[$intel_i]['data'] = str_replace('_l10iq.push(["set",{}]);', '_l10iq.push(["set",' . $json . ']);', $javascript[$intel_i]['data']) . $pushstr;
  }

  if ($debug && ($ga_i >= 0)) {
    if (variable_get('intel_debug_ga_debug', 0)) {
      $javascript[$ga_i]['data'] = str_replace('/ga.js', '/u/ga_debug.js', $javascript[$ga_i]['data']);
    }
    $hitCallback = "if((typeof window._l10im=='object')&&(typeof window._l10im.markTime=='function')){_l10im.markTime('ga._trackPageview')}";
    $javascript[$ga_i]['data'] = str_replace('ga("send", "pageview")', 'ga("send", "pageview", {hitCallback: function () {' . $hitCallback . '}})', $javascript[$ga_i]['data']);
    $script = " if ((typeof _l10im=='object')&&(typeof _l10im.markTime=='function')){ga(function() { _l10im.markTime('ga.ready')})}";
    //$script = " if ((typeof _l10im == 'object') && (typeof _l10im.markTime == 'function')) { _gaq.push(function() { _l10im.markTime('ga._trackPageview'); }); }";
    $javascript[$ga_i]['data'] .= $script;
  }

}

function intel_check_form_submission($page) {
  $vtk = IntelVisitor::extractVtk();
  // if vtk not present, don't processes
  if (empty($vtk)) {
    return;
  }

  // if api_level!=pro, vtk will not exist to process submission data correctly
  $api_level = intel_api_level();
  if ($api_level != 'pro') {
    return;
  }

$debug = 1;

  // check for webform submission
  $track = array(
    'category_id' => '',
    'value' => '', 
    'submission_path' => '',
    'form_title' => '',
    'oa' => array(),
  );
  // any url query elements that should be added to a redirect url
  $link_query = array();
  // submission object
  $submission = intel_submission_construct();
  $form_settings = array();
  $submit_context = array();
  $cta_context = array();
  // an array of fields to pass to intel's autofill form feature
  $autofill= array();
  $submission_data = array();
  $visitor = null;

  // fire hook for modules to report if a form has been submitted by setting $submission->type
  foreach (module_implements('intel_form_submission_check') AS $module) {
    $function = $module . '_intel_form_submission_check';
    $function($submission, $track, $submit_context, $form_settings, $link_query);
  }

  // if no submission type set, exit
  if (empty($submission->type)) {
    return;
  }

  // check if form submission has been submitted before, e.g. a duplicate submission
  $vars = array(
    'type' => $submission->type,
    'fid' => $submission->fid,
    'fsid' => $submission->fsid,
  );
  $submission0 = intel_submission_load_by_vars($vars);

  // TODO check this data for a while to assure uniqueness of fsids, then exit if previous submission exists.
  if (!empty($submission0->sid) && empty($_GET['debug']) && empty($debug)) {
    // form submission already created
    $vars = array(
      '!submission0' => print_r($submission0, 1),
      '!get' => print_r($_GET, 1),
      '!cookie' => print_r($_COOKIE, 1),
    );
    watchdog('intel', "form already submitted on form submission. <br>\n submission0=!submission0<br>\n<br>\nget=!get<br>\n<br>\ncookie=!cookie", $vars, WATCHDOG_DEBUG);  
    return '';
  }
  
  // load file for scoring data
  require_once drupal_get_path('module', 'intel') . "/includes/intel.ga.inc";
  
  // load current user
  // check if vid is set on submission to load a specific visitor
  if (!empty($submission->vid)) {
    $visitor = intel_visitor_load_or_create((int)$submission->vid);
  }
  else {
    $visitor = intel_visitor_load_or_create('user');
  }

  if (empty($visitor->vtk) && !empty($_SESSION['intel_vid'])) {
    $visitor = intel_visitor_load_or_create($_SESSION['intel_vid']);
  }


  // load data from api to get submission context
  if (!empty($visitor->vtk)) {
    try {
      $visitor->apiVisitorLoad();
    }
    catch (Exception $e) {
      // do nothing
    }
  }
  $api_data = $visitor->getApiVisitor();

  if (!empty($_GET['debug']) || !empty($debug)) {
    dpm('$visitor=');//
    dpm($visitor);//

    dpm('$api_data=');//
    dpm($api_data);//
    $error = $visitor->apiVisitorLoadError;
    dpm("$error");//
  }
  //watchdog('intel_fs_visitor', print_r($visitor, 1));
  //watchdog('intel_fs_api_data', print_r($api_data, 1));
  
  $a = explode('//', $GLOBALS['base_url']);
  $host = $a[1];

  // check thankyou page settings
  $node = menu_get_object();
  if (!empty($node) && isset($node->field_track_submission[$node->language][0]['value'])) {
    $track['category_id'] = $node->field_track_submission[$node->language][0]['value'];
  }
  if (!empty($node) && isset($node->field_track_submission_value[$node->language][0]['value'])) {
    $track['value'] = $node->field_track_submission_value[$node->language][0]['value'];
  }
  $submission->response_page_path = url($_GET['q']);
  $submission->response_page_host = $host;
  if (!empty($node)) {
    $submission->response_page_id = $node->nid; 
  }
  $scorings = intel_get_scorings();

  $cta_context = array();
    
  // if vid not set on visitor, save to create vid
  if (empty($visitor->vid)) {
    $visitor->save();
  }
  
  // update visitor attributes in analytics cookies
  // TODO check if this should be done here
  // va cookie is no longer supported in classic analytics
  // TODO: change to work with l10i_va cookie
  $va = $visitor->apiVisitor->extractCookieVa();
  if (isset($va)) {
    $visitor->setVar('data', 'analytics', '', $va);
  }

  $submission->vid = $visitor->vid;
  // check if api vtk was loaded succesfully
  if (!empty($visitor->apiVisitor->vtk)) {


    // if submit context not set by form_check hook, fetch it from api
    if (empty($submit_context)) {
      $fsi = $visitor->getVar('api_session', 'formSubmit', '_updated');
      if (empty($fsi)) {
        $fsi = $visitor->apiVisitor->getFlag('lfs');  // _updated is a better key for cross site forms
      }
      $submit_context = $visitor->getVar('api_session', 'formSubmit', $fsi);
    }
    if (!empty($submit_context)) {
      $referrer = !empty($submit_context['systemPath']) ? $submit_context['systemPath'] : $submit_context['location'];
      // strip query string
      $a = explode("?", $referrer);
      $referrer = $a[0];
      $lp_urlc = parse_url($submit_context['location']);
      $submission->form_page_host = $lp_urlc['host'];
      $submission->form_page_path = $lp_urlc['path'];

      if (!empty($submit_context['systemPath'])) {
        $a = explode('/', $submit_context['systemPath']);
        $lp_node = node_load($a[1]);
        $submission->form_page_id = !empty($lp_node->nid) ? $lp_node->nid : 0;
        $hook_context = array(
          'type' => 'form_submission',
          'form_settings' => $form_settings,
          'submit_context' => $submit_context,
          'cta_context' => $cta_context,
          'track' => $track,
          'submission' => $submission,
        );
        intel_execute_response_redirect_if_set($lp_node, $node, $link_query, $hook_context);
      }

      if (!empty($submit_context['isLandingpage'])) {
        $category = t('Landing page conversion') . '!';
        $track_conversion_value = (isset($scorings['landing_page_conversion'])) ? $scorings['landing_page_conversion'] : 0;      

        if (isset($lp_node->field_track_conversion)) {
          $track_conversion = $node->field_track_submission[$node->language][0]['value'];
          if (strpos($track_conversion, 'conversion') !== FALSE) {
            $category = t('Landing page conversion');
          }
          elseif (strpos($track_conversion, 'conversion!') === FALSE) {
            $category = '';
          }
        }
        if (isset($lp_node->field_track_conversion_value) && (trim($lp_node->field_track_conversion_value) == '')) {
          $track_conversion_value = $node->field_track_submission_value[$node->language][0]['value'];
        }

        if ($category) {
          $call = array(
            'eventCategory' => $category,
            'eventAction' => !empty($submit_context['pageTitle']) ? $submit_context['pageTitle'] : (!empty($lp_node->title) ? $lp_node->title : ''),
            'eventLabel' => $referrer,
            'eventValue' => $track_conversion_value,
            'nonInteraction' => FALSE,
          );
          if (!empty($submit_context['location'])) {
            $call['location'] = $submit_context['location'];
            if (!empty($submit_context['pageTitle'])) {
              $call['title'] = $submit_context['pageTitle'];
            }
            if (!empty($submit_context['customVars'])) {
              $call['customVars'] = $submit_context['customVars'];
            }
          }
          intel_add_page_intel_push(array('event', $call));
        }
      }
      //unset($visitor->session_data['form_submit'][$fsi]);
      
      // check if CTA was used to get there
      $cta_clicks = $visitor->getVar('api_session', 'ctaClick');
      $count = 0;
      if (!empty($cta_clicks) && is_array($cta_clicks)) {
        foreach ($cta_clicks AS $index => $click) {
          // filter "meta" elements
          if (substr($index, 0, 1) == '_') {
            continue;
          }
          $href_urlc = intel_parse_url($click['href'], $submit_context['location']);
//dsm("$referrer == {$href_urlc['system_path']} || ({$lp_urlc['host']} == {$href_urlc['host']} && {$lp_urlc['path']} == {$href_urlc['path']})");
          if ($referrer == $href_urlc['system_path'] || ($lp_urlc['host'] == $href_urlc['host'] && $lp_urlc['path'] == $href_urlc['path'])) {
            $cta_context = $click;
            $value = (isset($scorings['cta_conversion'])) ? $scorings['cta_conversion'] : 0;
            if (substr($click['label'], 0, 6) == 'block/') {
              // TODO make work with both blocks and beans
              $delta = substr($click['label'], 6);
              $submission->cta_id = $delta;
              $meta = cta_bean_meta_load($delta);
              if (isset($meta['data']['ga_event']['conversion']['value'])) {
                $value = $meta['data']['ga_event']['conversion']['value'];
              }
            }
            $call = array(
              'eventCategory' => t('CTA conversion!'),
              'eventAction' => $click['eventAction'],
              'eventLabel' => $click['eventLabel'],
              'eventValue' => $value,
              'nonInteraction' => FALSE,
            );
            if (!empty($click['location'])) {
              $call['location'] = $click['location'];
              if (!empty($click['pageTitle'])) {
                $call['title'] = $click['pageTitle'];
              }
              if (!empty($click['customVars'])) {
                $call['customVars'] = $click['customVars'];
              }
            }
            intel_add_page_intel_push(array('event', $call));

            $urlc = parse_url($click['location']);
            $submission->cta_page_host = $urlc['host'];
            $submission->cta_page_path = $urlc['path'];
            $a = explode('/', $click['system_path']);
            if (($a[0] == 'node') && !empty($a[1]) && is_numeric($a[1])) {
              $submission->cta_page_id = $a[1];
            }
            break;
          }
          // only check last 20 CTA clicks
          if ($count++ > 20) {
            break;
          }
        }
      }
    }
  }

  // if submit_context not available in api, check redirect using cookie
  if (intel_include_library_file('class.visitor.php')) {
    $loc0 = \LevelTen\Intel\ApiVisitor::getCookie('l10i_l');
  }
  if (empty($submit_context['location']) && !empty($loc0)) {
    $loc_comps = intel_parse_url($loc0);
    if (!empty($loc_comps['system_path'])) {
      $a = explode('/', $loc_comps['system_path']);
      if (($a[0] == 'node') && is_numeric($a[1])) {
        $lp_node = node_load($a[1]);
        $hook_context = array(
          'type' => 'form_submission',
          'form_settings' => $form_settings,
          'submit_context' => $submit_context,
          'cta_context' => $cta_context,
          'track' => $track,
          'submission' => $submission,
        );
        intel_execute_response_redirect_if_set($lp_node, $node, $link_query, $hook_context);
      }
    }
  }

  $intel_events = intel_get_intel_event_info();
if (!empty($_GET['debug']) || !empty($debug)) {
  dpm('$node'); dpm($node);//
  dpm('$scorings'); dpm($scorings);//
  dpm('$intel_events'); dpm($intel_events);//
  dpm('$track'); dpm($track);//
}

  if ($track['category_id'] == 'form_submission') {
    $category = t('Form submission');
    $track['value'] = ($track['value'] != '') ? $track['value'] : 0;
  }
  elseif (isset($intel_events['submission_' . $track['category_id']])) {
    $category = $intel_events['submission_' . $track['category_id']]['category'];
    $track['value'] = ($track['value'] != '') ? $track['value'] : $scorings[$track['category_id']];
  }
  else {
    $category = t('Form submission') . '!';
    $track['value'] = ($track['value'] != '') ? $track['value'] : $scorings['form_submission'];
  }
  
  if (empty($visitor->contact_created) && !empty($visitor->email)) {
    $visitor->setContactCreated(REQUEST_TIME);
  }
  $visitor->setLastActivity(REQUEST_TIME);
  
  // throw hook_intel_form_submission_data to enable modules to alter visitor, submission and track data
  $hook_context = array(
    'type' => 'form_submission',
    'form_settings' => $form_settings,
    'submit_context' => $submit_context,
    'cta_context' => $cta_context,
  );  
  
  foreach (module_implements('intel_form_submission_data') AS $module) {
    $function = $module . '_intel_form_submission_data';
    $function($visitor, $submission, $track, $hook_context);
  }

  // save submission object
  if (!empty($submission->vid)) {
    $sid = intel_submission_save($submission);
  }

  // if submission path does not exist, set default
  if (!$track['submission_path'] && !empty($sid)) {
    $track['submission_path'] = 'submission/' . $sid;
  }

  // save visitor
  if (!empty($visitor->vid)) {
    intel_visitor_save($visitor);
    //watchdog('intel.page_alter 992', print_r($visitor, 1));
  }

  // queue to sync visitor data
  intel_add_visitor_sync_request($visitor->vtk);

  // create form submission intel event
  $call = array(
    'eventCategory' => $category,
    'eventAction' => $track['form_title'],
    'eventLabel' => !empty($track['system_path']) ? $track['system_path'] : $track['submission_path'],
    'eventValue' => $track['value'],
    'nonInteraction' => FALSE,
  );
  /*
  if (!empty($submit_context['location'])) {
    $call['location'] = $submit_context['location'];
    if (!empty($submit_context['pageTitle'])) {
      $call['title'] = $submit_context['pageTitle'];
    }
    if (!empty($submit_context['customVars'])) {
      $call['customVars'] = $submit_context['customVars'];
    }
  }
  */
  if (!empty($track['oa'])) {
    $call['oa'] = $track['oa'];
  }


  intel_add_page_intel_push(array('event', $call));
//dpm('page_intel_push=');dpm($call);//

  // add known attribute to visitor
  if (!empty($visitor->contact_created)) {
    intel_add_page_intel_push(array('set', "va.k", ''));
  }

  if (module_exists('rules')) {
    rules_invoke_event('intel_form_submission', $submission->type, $submission->fid, $visitor);
  }

  // temp code to track submission for testing
  if (intel_debug_mode()) {
    $vars = array(
      '!submit_context' => print_r($submit_context, 1),
      '!visitor' => print_r($visitor->getProperties(), 1),
      '!submission' => print_r($submission, 1),
      '!get' => print_r($_GET, 1),
      '!cookie' => print_r($_COOKIE, 1),
    );
    //watchdog('intel', "form submission on form submission. <br>\n visitor=!visitor <br>\n<br>\nsubmission=!submission <br>\n<br>\nsubmit_context=!submit_context <br>\n<br>\nget=!get <br>\n<br>\ncookie=!cookie", $vars, WATCHDOG_DEBUG);
  }
  
  if (!empty($_GET['debug']) || !empty($debug)) {
    dpm('$submit_context='); dpm($submit_context);//
    dpm('$visitor='); dpm($visitor);//
    dpm('$submission='); dpm($submission);//
  }
}

/**
 * Determines of redirect has been set on
 * @param $lp_node - the landing page node
 * @param $menu_object - the object returned from get_menu_object, i.e. the
 * current node
 */
function intel_execute_response_redirect_if_set($lp_node, $menu_object = null, $link_query = array(), $hook_context = array()) {
  // check if redirect set
  if (isset($lp_node->language)) {
    $sys_path = '';
    $url = '';
    if (isset($lp_node->field_thankyou[$lp_node->language][0]['target_id'])) {
      $nid = $lp_node->field_thankyou[$lp_node->language][0]['target_id'];
      $sys_path = $url = 'node/' . $nid;
    }
    elseif (isset($lp_node->field_redirect_url[$lp_node->language][0]['url'])) {
      $url = trim($lp_node->field_redirect_url[$lp_node->language][0]['url']);
      $sys_path = drupal_get_normal_path($url);
    }

    // if url set and sys_path does not equal q, (on same page) do redirect.
    if ($url && ($sys_path != $_GET['q'])) {
      // cache cookies in Drupal session in case varnish or other caching is filtering
      // cookies
      intel_session_cookie_merge();
      $options = array('query' => $link_query);

      // allow modules to alter redirect
      $hook_context['lp_node'] = $lp_node;
      $hook_context['node'] = $menu_object;
      drupal_alter('intel_form_submission_redirect', $url, $options, $hook_context);
      drupal_goto($url, $options);
      exit;
    }
  }
}

function intel_session_cookie_merge() {
  $c0 = array();
  if (!empty($_SESSION['l10i_cookie']) && is_array($_SESSION['l10i_cookie'])) {
    $c0 = $_SESSION['l10i_cookie'];
  }
  $_SESSION['l10i_cookie'] = $_COOKIE + $c0;
}

function intel_visitor_sync_user($account) {
return; // TODO: disabled
  global $user;


  // TODO build a more configurable version for blocking user roles
  // Don't create visitor with identifier merges for accounts where muliple people might login

  // Don't autocreate visitor for user 1
  if ($user->uid == 1) {
    return;
  }

  // Don't autocreate visitor for admininistrators
  if (is_array($user)) {
    foreach ($user->roles AS $role) {
      if ($role == 'administrator') {
        return;
      }
    }
  }


  // if account is currently logged in user, set $vtk
  // otherwise another user is saving user data
  $vtk = ($user->uid && ($user->uid == $account->uid)) ? IntelVisitor::extractVtk() : '';
  // try loading by uid
  $visitor = intel_visitor_load($account->uid, FALSE, 'uid');

  if (!$visitor) {
    // try loading by email
    $visitor = intel_visitor_load($account->mail, FALSE, 'email');
  }

  if (!$visitor && $vtk) {
    // try loading by vtk
    $visitor = intel_visitor_load($vtk, FALSE, 'vtk');
  }

  // if associated visitor not found, create new one
  if (!$visitor) {
    $visitor = intel_visitor_create();
  }

  // set identifiers
  $visitor->setIdentifier('uid', $account->uid);
  $visitor->setIdentifier('email', $account->mail);
  if ($vtk) {
    $visitor->setIdentifier('vtk', $vtk);
    $visitor->last_activity = REQUEST_TIME;
  }
  if (empty($visitor->name)) {
    $visitor->setName($account->name);
  }
  $visitor->save();
}

/**
 * Implements hook_user_login()
 * @param $edit
 * @param $account
 */
// TODO: This causes problems with user session management.
// for some odd reason the intel_add_page_intel_push causes the user to be logged out
function intel_user_login(&$edit, &$account) {
  return;


  $visitor = intel_visitor_load($account->uid, FALSE, 'uid');

  if (!$visitor) {
    intel_visitor_sync_user($account);
  }
  else {
    $visitor->last_activity = REQUEST_TIME;
    $visitor->save();
  }


  $call = array(
    'eventCategory' => 'User login',
    'eventAction' => 'User login form',
    'eventLabel' => 'user/' . $account->uid,
    'eventValue' => 0,
    'nonInteraction' => FALSE,
    'location' => 'user',
  );
  intel_add_page_intel_push(array('event', $call));

//$pushes = intel_get_page_intel_pushes();
//watchdog('intel_user_login', print_r($pushes, 1));
}

/**
 * Implements hook_user_insert()
 */
function intel_user_insert(&$edit, $account, $category) {
  intel_visitor_sync_user($account);
}

/**
 * Implements hook_user_update()
 */
function intel_user_update(&$edit, $account, $category) {
  intel_visitor_sync_user($account);
}

function intel_form_user_register_form_alter(&$form, &$form_state) {
  // add submit handler
  $form['#submit'][] = 'intel_user_register_form_submit';
}

function intel_user_register_form_submit(&$form, &$form_state) {
  // create form submission intel event
  $call = array(
    'eventCategory' => 'User registration',
    'eventAction' => 'User registration form',
    'eventLabel' => 'user',
    'eventValue' => 0,
    'nonInteraction' => FALSE,
    'location' => 'user',
  );
  intel_add_page_intel_push(array('event', $call));
  $pushes = intel_get_page_intel_pushes();
  watchdog('intel_user_register_form_submit', print_r($pushes, 1));
}