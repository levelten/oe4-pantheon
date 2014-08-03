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
//print_r($user);
  /*
  if ($user->uid != 1) {
  //dsm($user);
  print_r($_SESSION);
  watchdog('intel: ' . $_GET['q'], print_r($_SESSION, 1));

// testing how session work. Looking at login/logout transition
// TODO remove (form testing only)
$_SESSION['intel'] = isset($_SESSION['intel']) ? $_SESSION['intel'] + 1 : 0;
$vtk = IntelVisitor::extractVtk();
watchdog('intel_page_alter session test', "$vtk = {$_SESSION['intel']}");
  }
  */

  $api_level = intel_api_level();
  
  $path_is_admin = path_is_admin(current_path());
  
  $ga_va = array();
  if ($user->uid && !empty($_COOKIE['__utmv'])) {
    if (intel_include_library_file('class.visitor.php')) {
      $ga_va = \LevelTen\Intel\ApiVisitor::extractCookieVa();
    }
  }  

  $is_landingpage = 0;
  
  $entity = '';
  $intel_events = intel_get_intel_event_info();
  $visitor_attrs = array();
  $page_attrs = array();
  $page_events = array();
  $page_title = drupal_get_title();
  $l10i_var_action = array(
    'method' => '_setIntelVar',
    'scope' => 'page',
    'namespace' => 'analytics',
  );
  // Add section and content type custom vars  
  if (arg(0) == 'node') {
    $entity = menu_get_object();

    if ($entity) {
      $entity_type = 'node';
      $entity_bundle = $entity->type;
      $page_title = $entity->title;

      $page_entity_settings = variable_get('intel_entity_settings_' . $entity_type . '__' . $entity_bundle, array());

      $page_attrs['pt'] = $entity->created;
      $page_attrs['et'] = 'n';
      $page_attrs['ct'] = str_replace('enterprise_', '', $entity->type); // trim enterprise namespace in Open Enterprise
    }
  }
  elseif (arg(0) == 'user') {
    $entity = menu_get_object('user');
    if ($entity) {
      $entity_type = 'user';
      $entity_bundle = 'user';

      $page_entity_settings = variable_get('intel_entity_settings_' . $entity_type . '__' . $entity_bundle, array());

      $page_attrs['pt'] = $entity->created;
      $page_attrs['et'] = 'u';

    }
  }
  // TODO support for taxomony terms listing page

  // do field operations
  if ($entity) {
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
    if ($path_is_admin) {
      $intent = 'a';
    }
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
      if ($intent == 'l') {
        $is_landingpage = 1;
        if ($api_level == 'pro') {
          $page_events['landing_page_view'] = $intel_events['landing_page_view'];
        }
      }     
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
    if (!empty($entity->field_intel_event_col[$lang]) && is_array($entity->field_intel_event_col[$lang])) {
      foreach ($entity->field_intel_event_col[$lang] AS $i => $e) {
        $collection = field_collection_item_load($e['value']);
        $key = $collection->field_intel_event[$lang][0]['value'];
        $page_events[$key] = $intel_events[$key];
        if(!empty($collection->field_intel_event_value[$lang][0]['value'])) {
          $page_events[$key]['value'] = $collection->field_intel_event_value[$lang][0]['value'];
        }
      }
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

  $l10i_var_action = array(
    'method' => '_setIntelVar',
    'scope' => 'page',
    'namespace' => 'analytics',
  );
  foreach ($page_attrs AS $key => $value) {
    if (is_array($value)) {
      foreach ($value AS $key2 => $value2) {
        $l10i_var_action['keys'] = "$key.$key2";
        $l10i_var_action['value'] = $value2;
        intel_add_page_intel_push($l10i_var_action);
      }
    }
    else {
      $l10i_var_action['keys'] = $key;
      $l10i_var_action['value'] = $value;
      intel_add_page_intel_push($l10i_var_action);      
    }
  }
  
  $l10i_var_action['scope'] = 'visitor';
  foreach ($visitor_attrs AS $key => $value) {
    if (is_array($value)) {
      foreach ($value AS $key2 => $value2) {
        $l10i_var_action['keys'] = "$key.$key2";
        $l10i_var_action['value'] = $value2;
        intel_add_page_intel_push($l10i_var_action);
      }
    }
    else {
      $l10i_var_action['keys'] = $key;
      $l10i_var_action['value'] = $value;
      intel_add_page_intel_push($l10i_var_action);      
    }
  }

  // add events set to be applied to all pages
  $all_page_events = intel_intel_event_all_pages_load();
  $page_events = array_merge($page_events, $all_page_events);

  foreach ($page_events AS $key => $value) {
    $l10i_event_action = $value;
    $l10i_event_action['method'] = '_addIntelEvent';
    if (!empty($l10i_event_action['valued_event'])) {
      $l10i_event_action['category'] .= '!';
    }
    $l10i_event_action = intel_filter_event_for_push($l10i_event_action);
    intel_add_page_intel_push($l10i_event_action);
  }

  //intel_check_user_login($page);

  intel_check_form_submission($page);
  
  // check form processing
  // this is a hack to exclude webform's submission redirect page
  $track_forms = array();
  if (isset($node->type) && ($node->type == 'webform')) {
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
  //watchdog('intel_page_alter_pushes', print_r($pushes, 1));

  $parsed_url = intel_parse_cms_url();
  $js = array(
    'intel' => array(
      'debug' => intel_debug_mode(),
      'cms_hostpath' => $parsed_url['hostpath'],
      'module_path' => drupal_get_path('module', 'intel'),
      'system_path' => $_GET['q'],
      'lib_path' => intel_get_library_path(),
      'page_title' => $page_title,
      'track_analytics' => 0, // this is set in intel_js_alter if ga script exists
      'track_adhoc_ctas' => ($api_level == 'pro') ? 'track-cta' : '',
      'track_adhoc_events' => 'track-event',
      'track_forms' => $track_forms,
      'track_realtime' => variable_get('intel_track_realtime', INTEL_TRACK_REALTIME_DEFAULT),
      'is_landingpage' => $is_landingpage,
      'pushes' => $pushes,
      'scorings' => intel_get_scorings('js_setting'),
    ),
    'disqus' => array(
      'callback_onnewcomment' => 'l10iDisqus.trackComment',
    ),
  );
  if ($ga_domain = variable_get('intel_domain_name', '')) {
    $js['intel']['ga']['_setDomainName'] = $ga_domain;
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
    $js['intel']['track_analytics'] = 0;
  } 
  if (path_is_admin(current_path())) {
    $track = 0;  
  }
  if (!$track) {    
    $js['intel']['track_forms'] = 0;
    $js['intel']['track_adhoc_ctas'] = 0;
    $js['intel']['track_adhoc_events'] = 0;
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
  drupal_add_js($script, array('type' => 'inline', 'scope' => 'header', 'weight' => -1, 'group' => JS_LIBRARY));

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
    if (!$index) {
      $index = 'i' . count($_SESSION['intel_page_pushes']);
    }
    $_SESSION['intel_page_pushes'][$index] = $push;
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
 * Implements hook_page_alter().
 */
function intel_get_js_embed($type = 'intel', $mode = 'external', $version = 'latest', $terminator = "") {
  $script = '';
  $debug = intel_debug_mode();
  if ($debug) {
    $terminator = "\n";
  }
  $l10i_ga_account = variable_get('intel_ga_account', '');
  $l10i_domain_name = variable_get('intel_domain_name', '');
  $l10i_ga_tracker_prefix = variable_get('intel_ga_tracker_prefix', 'l10i');
  $api_level = variable_get('intel_api_level', '');
  $api_js_ver = trim(variable_get('intel_l10iapi_js_ver', ''));
  $api_js_ver = ($api_js_ver) ? $api_js_ver : INTEL_L10IAPI_JS_VER;
  if ($l10i_ga_account && !$l10i_ga_tracker_prefix) {
    $l10i_ga_tracker_prefix = 'l10i';
  }

  $wrap = ($mode == 'external') ? 1 : 0;
  if ($version == 'simple') {
    $wrap = 0;
    $script .= '<script>' . $terminator;
  }
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
  if ($api_level && (($type == 'l10i') || ($type == 'combined'))) {
    //$host_root = intel_get_host_root();
    $library_path = libraries_get_path('LevelTen') . 'Intel/scripts';
    //$api_hostpath = variable_get('intel_l10iapi_hostpath', '');
    $api_hostpath = variable_get('intel_l10iapi_url', '');
    if (!trim($api_hostpath)) {
      $api_hostpath = INTEL_L10IAPI_URL;
    }
    $data_mode = (variable_get('intel_api_level', 'free') == 'free') ? 0 : 1;
    $api_pid = variable_get('intel_l10iapi_profileid', '');
    $sv = (variable_get('intel_debug_mode', 0)) ? '' : '.min';
    //$script .= "// LevelTen Intelligence" . $terminator;
    $script .= "var _l10iq = _l10iq || [];" . $terminator;
    //$script .= "var _intel = _intel || [];" . $terminator;
    $l10iq_pushes = array();
    //$l10iq_pushes[] = array('_setTrackerPrefix', $l10i_ga_tracker_prefix);
    $l10iq_pushes[] = array('_setAccount', $l10i_ga_account, $l10i_ga_tracker_prefix);
    if ($l10i_domain_name) {
      $l10iq_pushes[] = array('_setDomainName', $l10i_domain_name);
    }
    $l10iq_pushes[] = array('_setApiUrl', $api_hostpath . '/');
    $l10iq_pushes[] = array('_setDataMode', $data_mode);
    $l10iq_pushes[] = array('_setOptions', (object) array());

    // trigger alter to enable other modules to add pushes
    drupal_alter('intel_l10iq_pushes', $l10iq_pushes);

    foreach ($l10iq_pushes AS $p) {
      $script .= "_l10iq.push(" . json_encode($p) . ");" . $terminator;
    }

/*
    $script .= "_l10iq.push(['_setTrackerPrefix', '$l10i_ga_tracker_prefix']);" . $terminator;  
    $script .= "_l10iq.push(['_setAccount', '$l10i_ga_account']);" . $terminator; 
    if ($l10i_domain_name) {
      $script .= "_l10iq.push(['_setDomainName', '$l10i_domain_name']);" . $terminator;
    }
    $script .= "_l10iq.push(['_setApiUrl', '$api_hostpath/']);" . $terminator; 
    $script .= "_l10iq.push(['_setDataMode', $data_mode]);" . $terminator;  
    $script .= "_l10iq.push(['_setOptions', {}]);" . $terminator;
*/
    
    if ($version == 'latest') {
      if ($s = trim(variable_get('intel_custom_embed_script', ''))) {
        $script .= $s;
      } else {
        $fr = ($debug && 0) ? " + '?t=' + new Date().getTime()" : ''; 
        $script .= "(function() {" . $terminator;
        $script .= "var l10i = document.createElement('script'); l10i.type = 'text/javascript'; l10i.async = true;" . $terminator;
        $script .= "l10i.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + '$api_hostpath/js/$api_js_ver/l10i$sv.js'$fr;" . $terminator;
        $script .= "var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(l10i, s);" . $terminator;
        $script .= "})();" . $terminator;
      }

      if (0) { // use combined l10i.js
        $script .= "(function() {" . $terminator;
        $script .= "var l10il = document.createElement('script'); l10il.type = 'text/javascript'; l10il.async = true;" . $terminator;
        $script .= "l10il.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + '$api_hostpath/js/intel$sv.js'$fr;" . $terminator;
        $script .= "var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(l10il, s);" . $terminator;
        $script .= "})();" . $terminator;
      }
    }
    elseif ($version == 'simple') {
      $script .= '</script>' . $terminator;
      $script .= '<script src="http://' . $api_hostpath . '/js/' . $api_js_ver . '/l10i' . $sv . '.js"></script>' . $terminator;
      if (0) { // use combined l10i.js
        $script .= '<script src="http://' . $api_hostpath . '/js/intel.js"></script>' . $terminator;
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
    if (substr($javascript[$i]['data'], 0, 8) == 'var _gaq') {
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
    if ($ga_i >= 0) {
      $options['track_analytics'] = 1;
    }
    $json = drupal_json_encode($options);
    $javascript[$intel_i]['data'] = str_replace('_l10iq.push(["_setOptions",{}]);', '_l10iq.push(["_setOptions",' . $json . ']);', $javascript[$intel_i]['data']);
  }

  if ($debug && ($ga_i >= 0)) {
    if (variable_get('intel_debug_ga_debug', 0)) {
      $javascript[$ga_i]['data'] = str_replace('/ga.js', '/u/ga_debug.js', $javascript[$ga_i]['data']);
    }
    $script = " if ((typeof _l10im == 'object') && (typeof _l10im.markTime == 'function')) { _gaq.push(function() { _l10im.markTime('ga._trackPageview'); }); }";
    $javascript[$ga_i]['data'] .= $script;
  }

}

function intel_check_form_submission($page) {
  // if api_level!=pro, vtk will not exist to process submission data correctly
  $api_level = variable_get('intel_api_level', '');

  // check for webform submission
  $track = array(
    'category_id' => '',
    'value' => '', 
    'submission_path' => '',
    'form_title' => '',
  );
  // any url query elements that should be added to a redirect url
  $link_query = array();
  // submission object
  $submission = intel_submission_construct();
  $form_settings = array();
  $submit_context = array();
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
  if (!empty($submission0->sid) && empty($_GET['debug'])) {
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

  if (!empty($_GET['debug'])) {
    dpm('$visitor=');//
    dpm($visitor);//

    dpm('$api_data=');//
    dpm($api_data);//
    $error = $visitor->apiVisitorLoadError;
    dpm("$error");//
  }
  watchdog('intel_fs_visitor', print_r($visitor, 1));
  watchdog('intel_fs_api_data', print_r($api_data, 1));
  
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
  $va = $visitor->apiVisitor->extractCookieVa();
  if (isset($va)) {
    $visitor->setVar('data', 'analytics', '', $va);
  }
  
  $submission->vid = $visitor->vid;
  // check if api vtk was loaded succesfully
  if (!empty($visitor->apiVisitor->vtk)) {
    $fsi = $visitor->getVar('api_session', 'form_submit', '_updated'); 
    if (empty($fsi)) {
      $fsi = $visitor->apiVisitor->getFlag('lfs');  // _updated is a better key for cross site forms
    }

    // if submit context not set by form_check hook, fetch it from api
    if (empty($submit_context)) {
      $submit_context = $visitor->getVar('api_session', 'form_submit', $fsi);
    }
    if (!empty($submit_context)) {
      $referrer = !empty($submit_context['system_path']) ? $submit_context['system_path'] : $submit_context['location'];
      // strip query string
      $a = explode("?", $referrer);
      $referrer = $a[0];
      $urlc = parse_url($submit_context['location']);
      $submission->form_page_host = $urlc['host'];
      $submission->form_page_path = $urlc['path'];

      if (!empty($submit_context['system_path'])) {
        $a = explode('/', $submit_context['system_path']);
        $lp_node = node_load($a[1]);
        $submission->form_page_id = !empty($lp_node->nid) ? $lp_node->nid : 0;
        intel_execute_response_redirect_if_set($lp_node, $link_query);
      }

      if (!empty($submit_context['is_landingpage'])) {
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
            'method' => '_addIntelEvent',
            'event' => 'pageshow',
            'selector' => 'body',
            'category' => $category,
            'action' => !empty($submit_context['page_title']) ? $submit_context['page_title'] : (!empty($lp_node->title) ? $lp_node->title : ''),
            'label' => $referrer,
            'value' => $track_conversion_value,
            'noninteraction' => FALSE,
            'location' => !empty($submit_context['location']) ? $submit_context['location'] : (!empty($lp_node->nid) ? url("node/{$lp_node->title}") : ''),
          );
          intel_add_page_intel_push($call);
        }
      }
      //unset($visitor->session_data['form_submit'][$fsi]);
      
      // check if CTA was used to get there
      $cta_clicks = $visitor->getVar('api_session', 'cta_click');
      if (!empty($cta_clicks) && is_array($cta_clicks)) {
        foreach ($cta_clicks AS $index => $click) {
          // filter "meta" elements
          if (substr($index, 0, 1) == '_') {
            continue;
          }
          if ($referrer = $click['href']) {
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
              'method' => '_addIntelEvent',
              'event' => 'pageshow',
              'selector' => 'body',
              'category' => t('CTA conversion!'),
              'action' => $click['action'],
              'label' => $click['label'],
              'value' => $value,
              'noninteraction' => FALSE,
              'location' => $click['location'],
            );    
            intel_add_page_intel_push($call);
            $urlc = parse_url($click['location']);
            $submission->cta_page_host = $urlc['host'];
            $submission->cta_page_path = $urlc['path'];
            $a = explode('/', $click['system_path']);
            if (($a[0] == 'node') && !empty($a[1]) && is_numeric($a[1])) {
              $submission->cta_page_id = $a[1];
            }
            break;
          }
        }
      }
    }
  }

  // if submit_context not available in api, check redirect using cookie
  if (empty($submit_context['location']) && !empty($_COOKIE['l10i_l'])) {
    $loc_comps = intel_parse_url($_COOKIE['l10i_l']);
    if (!empty($loc_comps['system_path'])) {
      $a = explode('/', $loc_comps['system_path']);
      if (($a[0] == 'node') && is_numeric($a[1])) {
        $lp_node = node_load($a[1]);
        intel_execute_response_redirect_if_set($lp_node, $link_query);
      }
    }
  }

  $intel_events = intel_get_intel_event_info();
if (!empty($_GET['debug'])) {
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
    'method' => '_addIntelEvent',
    'event' => 'pageshow',
    'selector' => 'body',
    'category' => $category,
    'action' => $track['form_title'],
    'label' => $track['submission_path'],
    'value' => $track['value'],
    'noninteraction' => FALSE,
    'location' => !empty($submit_context['location']) ? $submit_context['location'] : (!empty($lp_node->nid) ? url("node/{$lp_node->nid}") : ''),
  );
  intel_add_page_intel_push($call);
//dpm('page_intel_push=');dpm($call);//

  // add known attribute to visitor
  if (!empty($visitor->contact_created)) {
    $call = array(
      'method' => '_setIntelVar',
      'scope' => 'visitor',
      'namespace' => 'analytics',
      'keys' => 'k',
      'value' => '',
    );
    intel_add_page_intel_push($call);
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
  
  if (!empty($_GET['debug'])) {
    dpm('$submit_context='); dpm($submit_context);//
    dpm('$visitor='); dpm($visitor);//
    dpm('$submission='); dpm($submission);//
  }
}

/**
 * Determines of redirect has been set on
 * @param $lp_node - the landing page node
 */
function intel_execute_response_redirect_if_set($lp_node, $link_query = array()) {
  // check if redirect set
  if (isset($lp_node->language)) {
    $url = '';
    if (isset($lp_node->field_thankyou[$lp_node->language][0]['target_id'])) {
      $url = 'node/' . $lp_node->field_thankyou[$lp_node->language][0]['target_id'];
    }
    elseif (isset($lp_node->field_redirect_url[$lp_node->language][0]['url'])) {
      $url = trim($lp_node->field_redirect_url[$lp_node->language][0]['url']);
    }
    if ($url && ($url != $_GET['q'])) {
      $options = array('query' => $link_query);
      drupal_goto($url, $options);
      exit;
    }
  }
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
    'method' => '_addIntelEvent',
    'event' => 'pageshow',
    'selector' => 'body',
    'category' => 'User login',
    'action' => 'User login form',
    'label' => 'user/' . $account->uid,
    'value' => 0,
    'noninteraction' => FALSE,
    'location' => 'user',
  );
  intel_add_page_intel_push($call);

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
    'method' => '_addIntelEvent',
    'event' => 'pageshow',
    'selector' => 'body',
    'category' => 'User registration',
    'action' => 'User registration form',
    'label' => 'user',
    'value' => 0,
    'noninteraction' => FALSE,
    'location' => 'user',
  );
  intel_add_page_intel_push($call);
  $pushes = intel_get_page_intel_pushes();
  watchdog('intel_user_register_form_submit', print_r($pushes, 1));
}