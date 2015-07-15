<?php
/**
 * @file
 * Functions to support extended Google Analytics data.
 *
 * @author Tom McCracken <tomm@getlevelten.com>
 */

/**
 * types = flag, list, scalar, vector
 */
function intel_get_intel_event_info_default() {
  $event = array();

  $event['landing_page_view'] = array(
    'title' => t('Landing page view'),
    'description' => t('Landing page pageview'),
    //'event' => 'pageshow',
  );
  $event['landing_page_conversion'] = array(
    'title' => t('Landing page conversion'),
    'description' => t('Form submission from a landing page'),
    'valued_event' => 1,
    'value' => 0,
  );
  $event['form_submission'] = array(
    'title' => t('Form submission'),
    'description' => t('General form submission'),
    'valued_event' => 1,
    'value' => 25,
  );
  $event['phone_call'] = array(
    'title' => t('Phone call'),
    'description' => t('General phone call'),
    'valued_event' => 1,
    'value' => 25,
  );
  $event['addthis_social_share'] = array(
    'title' => t('AddThis social share'),
    'category' => t('Social share'),
    'description' => t('Click on social sharing widget'),
    'valued_event' => 1,
    'value' => 5,
    'js_setting' => 1,
  );
  $event['addthis_social_share_clickback'] = array(
    'title' => t('AddThis social share clickback'),
    'category' => t('Social share clickback'),
    'description' => t('Visitor referred from a social share'),
    'valued_event' => 1,
    'value' => 0,
    'js_setting' => 1,
  );
  $event['addthis_social_follow'] = array(
    'title' => t('AddThis social profile click'),
    'category' => t('Social profile'),
    'description' => t('Click on social profile follow button'),
    'valued_event' => 1,
    'value' => 2,
    'js_setting' => 1,
  );
  $event['disqus_comment'] = array(
    'title' => t('Disqus comment'),
    'category' => t('Comment'),
    'description' => t('Click on social sharing widget'),
    'valued_event' => 1,
    'value' => 10,
    'js_setting' => 1,
  );
  return $event;
}

function intel_get_event_goal_info() {
  $event = array();
  $goals = variable_get('intel_event_goals', array());

  foreach ($goals AS $key => $goal) {
    $ekey = 'goal_' . $key;
    $event[$ekey] = $goal;
    $event[$ekey]['title'] = $event[$ekey]['category'] = t('Goal') . ': ' . $goal['title'];
    $event[$ekey]['category'] .= '+';
    $event[$ekey]['selectable'] = 1;
  }

  $goals = variable_get('intel_submission_goals', intel_get_submission_goals_default());

  foreach ($goals AS $key => $goal) {
    $ekey = 'submission_goal_' . $key;
    $event[$ekey] = $goal;
    $event[$ekey]['title'] = $event[$ekey]['category'] = t('Form submission') . ': ' . $goal['title'];
    $event[$ekey]['category'] .= '+';
    $event[$ekey]['event'] = 'form_submission';
  }

  $goals = variable_get('intel_phonecall_goals', intel_get_phonecall_goals_default());

  foreach ($goals AS $key => $goal) {
    $ekey = 'phonecall_goal_' . $key;
    $event[$ekey] = $goal;
    $event[$ekey]['title'] = $event[$ekey]['category'] = t('Phone call') . ': ' . $goal['title'];
    $event[$ekey]['category'] .= '+';
    $event[$ekey]['event'] = 'phonecall';
  }
  return $event;
}

function intel_get_intel_event_info($name = NULL, $options = array()) {
  $events = &drupal_static(__FUNCTION__);
  if (count($events)) {
    if (isset($name)) {
      if (isset($events[$name])) {
        return $events[$name];
      }
    }
    else {
      return $events;
    }
  }
  $events = intel_get_intel_event_info_default();
  $events = array_merge($events, intel_get_event_goal_info());

  foreach ($events AS $k => $v) {
    if (isset($v['static_options'])) {
      $events[$k]['options'] = $v['static_options'];
    }
    if (empty($v['category'])) {
      $events[$k]['category'] = $v['title'];
    }
    $events[$k]['module']  = 'intel';
    $events[$k]['key']  = $k;
  }

  $custom = variable_get('intel_intel_events_custom', array());

  foreach ($custom AS $k => $v) {
    // check if custom attribute
    if (isset($events[$k])) {
      foreach ($v AS $a => $b) {
        $events[$k][$a] = $b;
      }
    }
    else {
      $custom[$k]['module']  = 'intel';
      $custom[$k]['custom'] = 1;
      $events[$k] = $custom[$k];
      if (empty($v['category'])) {
        $events[$k]['category'] = $v['title'];
      }
    }
    if (!empty($custom[$k]['custom_options'])) {
//sdm($custom[$k]['custom_options']);
      if (!isset($events[$k]['options'])) {
        $events[$k]['options'] = $custom[$k]['custom_options'];
      }
      else {
        $events[$k]['options'] += $custom[$k]['custom_options'];
      }
    }
    $events[$k]['key']  = $k;
  }

  foreach (module_implements('intel_intel_events') AS $module) {
    $function = $module . '_intel_intel_events';
    $a = $function();
    if (empty($a) || !is_array($a)) {
      continue;
    }
    foreach ($a AS $k => $v) {
      $v['module'] = $module;
      $v['key']  = $k;
      $events[$k] = $v;
    }
  }

  drupal_alter('intel_intel_events', $events);

  uasort($events, '_intel_sort_by_category');

  if (isset($name)) {
    if (isset($events[$name])) {
      return $events[$name];
    }
    else {
      return FALSE;
    }
  }
  else {
    return $events;
  }
}

/**
 * Alias of intel_get_intel_event_info for use with hook_menu autoloading
 *
 * @param $key
 * @return mixed
 */
function intel_intel_event_load($key) {
  return intel_get_intel_event_info($key);
}

function intel_intel_event_all_pages_load() {
  $events = &drupal_static(__FUNCTION__);
  if (isset($events)) {
    return $events;
  }
  $events = array();
  $e = intel_get_intel_event_info();
  foreach ($e AS $key => $event) {
    if (!empty($event['enable_all_pages'])) {
      $events[$key] = $event;
    }
  }
  return $events;
}

/**
 * types = flag, list, scalar, vector
 */
function intel_get_visitor_attribute_info_default() {
  $attributes = array();
  $user_roles = user_roles();
  // remove anonymous user
  unset($user_roles[1]);

  $options = array();
  foreach ($user_roles AS $rid => $role) {
    $options[$rid] = array(
      'title' => $role,
    );
  }
  $attributes['r'] = array(
    'title' => t('User roles'),
    'description' => t('Set to Drupal user roles for authenticated visitors.'),
    'type' => 'list',
    'static_options' => $options,
  );
  $attributes['k'] = array(
    'title' => t('Known'),
    'description' => t('If a visitor has submitted an email address.'),
    'type' => 'flag',
  );
  $attributes['s'] = array(
    'title' => t('Score'),
    'description' => t('Sum of valued events and goals triggered by visitor.'),
    'type' => 'scalar',
    'selectable' => 1,
  );
  $attributes['l'] = array(
    'title' => t('Lead score'),
    'description' => t('Used to value visitors customer potential.'),
    'type' => 'scalar',
    'selectable' => 1,
  );
  $attributes['g'] = array(
    'title' => t('Groups'),
    'description' => t('Used to categorize visitors by a defining characteristics.'),
    'type' => 'list',
    'custom_options' => array(),
    'selectable' => 1,
  );
  $attributes['i'] = array(
    'title' => t('Interests'),
    'description' => t('Used to value a visitors interest in various items.'),
    'type' => 'vector',
    'custom_options' => array(),
    'selectable' => 1,
  );
  $attributes['e1l'] = array(
    'title' => t('First entrance page'),
    'title_plural' => t('First entrance pages'),
    'description' => t('The first page hit on a visitors first visit to the site.'),
    'type' => 'item',
    'options_description' => t('Auto generated in javascript.'),
    //'options info callback' => 'intel_page_attribute_content_type_option_info',
    'storage' => array(
      'analytics' => array(
        'struc' => 'dimension',
        'index' => 15,
        'format' => 'single',
      )
    ),
  );
  $attributes['e1rl'] = array(
    'title' => t('First referrer'),
    'title_plural' => t('First referrers'),
    'description' => t('The first referrer url for a visitors first visit to the site.'),
    'type' => 'item',
    'options_description' => t('Auto generated in javascript.'),
    //'options info callback' => 'intel_page_attribute_content_type_option_info',
    'storage' => array(
      'analytics' => array(
        'struc' => 'dimension',
        'index' => 16,
        'format' => 'single',
      )
    ),
  );
  $attributes['e1s'] = array(
    'title' => t('First source'),
    'title_plural' => t('First sources'),
    'description' => t('The first referrer url for a visitors first visit to the site.'),
    'type' => 'item',
    'options_description' => t('Auto generated in javascript.'),
    //'options info callback' => 'intel_page_attribute_content_type_option_info',
    'storage' => array(
      'analytics' => array(
        'struc' => 'dimension',
        'index' => 17,
      )
    ),
  );
  $attributes['e1m'] = array(
    'title' => t('First medium'),
    'title_plural' => t('First mediums'),
    'description' => t('The first referrer url for a visitors first visit to the site.'),
    'type' => 'item',
    'options_description' => t('Auto generated in javascript.'),
    //'options info callback' => 'intel_page_attribute_content_type_option_info',
    'storage' => array(
      'analytics' => array(
        'struc' => 'dimension',
        'index' => 17,
      )
    ),
  );
  return $attributes;
}

function intel_get_page_attribute_info_default() {
  $attributes = array();

  $attributes['a'] = array(
    'title' => t('Author'),
    'title_plural' => t('Authors'),
    'description' => t('The uid of a node author.'),
    'type' => 'item',
    'options_description' => t('Auto generated from entity uid.'),
    'options info callback' => 'intel_page_attribute_author_option_info',
  );
  $attributes['rt'] = array(
    'title' => t('Entity type'),
    'title_plural' => t('Entity types'),
    'description' => t('The entity type of the page. (node, user...)'),
    'type' => 'value',
    'options_description' => t('Auto generated from page entity.'),
    'options info callback' => 'intel_page_attribute_entity_type_option_info',
    'access callback' => 0,
    'storage' => array(
      'analytics' => array(
        'struc' => 'dimension',
        'index' => 6,
      )
    ),
  );
  $attributes['rt2'] = array(
    'title' => t('Content type'),
    'title_plural' => t('Content types'),
    'description' => t('Node type or entity bundle type.'),
    'type' => 'value',
    'options_description' => t('Auto generated from entity type/bundle.'),
    'options info callback' => 'intel_page_attribute_content_type_option_info',
    'storage' => array(
      'analytics' => array(
        'struc' => 'dimension',
        'index' => 6,
      )
    ),
  );
  $attributes['rk'] = array(
    'title' => t('Entity id'),
    'title_plural' => t('Entity ids'),
    'description' => t('The standard id for the entity, e.g. node id.'),
    'type' => 'item',
    'options_description' => t('Auto generated from entity type/bundle.'),
    'access callback' => 0,
    //'options info callback' => 'intel_page_attribute_content_type_option_info',
    'storage' => array(
      'analytics' => array(
        'struc' => 'dimension',
        'index' => 6,
      )
    ),
  );
  $attributes['rvi'] = array(
    'title' => t('Revision id'),
    'title_plural' => t('Revision ids'),
    'description' => t('The revision number of an entity.'),
    'type' => 'item',
    'encode' => FALSE,
    'options_description' => t('Auto generated from entity data.'),
    'access callback' => FALSE,
    //'options info callback' => 'intel_page_attribute_content_type_option_info',
    'storage' => array(
      'analytics' => array(
        'struc' => 'dimension',
        'index' => 1,
      )
    ),
  );
  $attributes['rl'] = array(
    'title' => t('Entity path'),
    'title_plural' => t('Entity path'),
    'description' => t('The Drupal system path for an entity.'),
    'type' => 'value',
    'options_description' => t('Auto generated from entity data.'),
    'access callback' => FALSE,
    //'options info callback' => 'intel_page_attribute_content_type_option_info',
    'storage' => array(
      'analytics' => array(
        'struc' => 'dimension',
        'index' => 6,
      )
    ),
  );
  /*
  $attributes['url'] = array(
    'title' => t('URL'),
    'title_plural' => t('URLs'),
    'description' => t('The default url for a node or entity, using the url function.'),
    'type' => 'value',
    'options_description' => t('Auto generated from entity type/bundle.'),
    'options info callback' => 'intel_page_attribute_content_type_option_info',
    'access callback' => FALSE,
    'storage' => array(
      'analytics' => array(
        'struc' => 'dimension',
        'index' => 6,
        'format' => 'single',
      )
    ),
  );
  /*
  $attributes['lang'] = array(
    'title' => t('Language'),
    'title_plural' => t('Languages'),
    'description' => t('The language of the page.'),
    'type' => 'value',
    'options_description' => t('Auto generated from entity data.'),
    //'options info callback' => 'intel_page_attribute_content_type_option_info',
    'access callback' => FALSE,
    'storage' => array(
      'analytics' => array(
        'struc' => 'dimension',
        'index' => 13,
      )
    ),
  );
  */
  /*
  $attributes['ct'] = array(
    'title' => t('Content type'),
    'title_plural' => t('Content types'),
    'description' => t('Node type or entity bundle type.'),
    'type' => 'item',
    'options_description' => t('Auto generated from entity type/bundle.'),
    'options info callback' => 'intel_page_attribute_content_type_option_info',
  );
  $attributes['et'] = array(
    'title' => t('Entity type'),
    'title_plural' => t('Entity types'),
    'description' => t('The entity type of the page. (node, user...)'),
    'type' => 'item',
    'options_description' => t('Auto generated from page entity.'),
    'options info callback' => 'intel_page_attribute_entity_type_option_info',
  );
  */
  $attributes['i'] = array(
    'title' => t('Page intent'),
    'description' => t('The role a page plays on the site.'),
    'type' => 'list',
    'static_options' => intel_get_page_intents_default('config'),
    'custom_options' => array(),
    'selectable' => 1,
  );
  $attributes['pd'] = array(
    'title' => t('Published date'),
    'description' => t('The time (unix timestamp) a node was created.'),
    'options_description' => t('Auto generated from entity created date.'),
    'options info callback' => 'intel_page_attribute_published_date_option_info',
    'type' => 'value',
    'format' => 'datetimedow',
    'access callback' => '_intel_user_access_extended',
    'storage' => array(
      'analytics' => array(
        'struc' => 'dimension',
        'index' => 1,
      )
    ),
  );

  $attributes['pda'] = array(
    'title' => t('Published age'),
    'description' => t('The time in seconds since the page was published (created).'),
    'options_description' => t('Auto generated from entity created date.'),
    'options info callback' => 'intel_page_attribute_published_age_option_info',
    'type' => 'value',
    'format' => 'timeago',
    'access callback' => '_intel_user_access_extended',
    'storage' => array(
      'analytics' => array(
        'struc' => 'dimension',
        'index' => 10,
        'format' => 'timeago',
      )
    ),
    'index_grouping' => array(
      0,
      86400,
      86400*7,
      86400*30,
      86400*90,
      86400*365,
    ),
  );
  /*
  $attributes['pdw'] = array(
    'title' => t('Published DOW'),
    'description' => t('The day of the week (integer 1-7) of the day of week a page was published.'),
    'options_description' => t('Auto generated from entity created date.'),
    'options info callback' => 'intel_page_attribute_published_dow_option_info',
    'type' => 'scalar',
//    'storage' => array(
//      'analytics' => array(
//        'struc' => 'metric',
//        'index' => 5,
//      )
//    ),
  );
  $attributes['pdt'] = array(
    'title' => t('Published TOD'),
    'description' => t('The time in HH.MM format a page was published.'),
    'options_description' => t('Auto generated from entity created date.'),
    'options info callback' => 'intel_page_attribute_published_tod_option_info',
    'type' => 'scalar',
//    'storage' => array(
//      'analytics' => array(
//        'struc' => 'metric',
//        'index' => 3,
//      )
//    ),
    'index_grouping' => array(),
  );
  for ($i = 0; $i <= 2400; $i += 100) {
    $attributes['pdt']['index_grouping'][] = $i;
  }
  */
  $attributes['s'] = array(
    'title' => t('Section'),
    'title_plural' => t('Sections'),
    'description' => t('Node type or entity bundle type.'),
    'type' => 'item',
    'custom_options' => array(),
    'selectable' => 1,
    'access callback' => FALSE,
  );
  $attributes['t'] = array(
    'title' => t('Tag'),
    'title_plural' => t('Tags'),
    'description' => t('List of taxomony term ids.'),
    'type' => 'list',
    'options_description' => t('Auto generated from terms in selected taxonomy fields.'),
    'options info callback' => 'intel_page_attribute_taxomony_term_option_info',
    'storage' => array(
      'analytics' => array(
        'struc' => 'dimension',
        'index' => 1,
      )
    ),
  );
  return $attributes;
}

/**
 * Returns page attribute definitions.
 * @param null $name
 *   Designates a specific visitor attribute to return. If null, all visitor
 *   attributes will be returned as an array.
 * @return array
 */
function intel_get_page_attribute_info($name = NULL) {
  return intel_get_attribute_info($name, 'page');
}

/**
 * Alias for intel_get_page_attribute_info() to be used with hook_menu's
 * autoloading
 */
function intel_page_attribute_load($name) {
  return intel_get_page_attribute_info($name);
}

/**
 * Returns page attribute definitions.
 * @param null $name
 *   Designates a specific visitor attribute to return. If null, all visitor
 *   attributes will be returned as an array.
 * @return array
 */
function intel_get_visitor_attribute_info($name = NULL) {
  return intel_get_attribute_info($name, 'visitor');
}

/**
 * Alias for intel_get_visitor_attribute_info() to be used with hook_menu's
 * autoloading
 */
function intel_visitor_attribute_load($name) {
  return intel_get_visitor_attribute_info($name);
}

function intel_get_attribute_info($name = NULL, $mode = 'visitor') {
  $attributes = &drupal_static(__FUNCTION__);
  if (isset($attributes[$mode])) {
    if (isset($name)) {
      if (isset($attributes[$mode][$name])) {
        return $attributes[$mode][$name];
      }
    } else {
      return $attributes[$mode];
    }
  }
  $attrs = ($mode == 'page') ? intel_get_page_attribute_info_default() : intel_get_visitor_attribute_info_default();

  foreach ($attrs AS $k => $v) {
    if (isset($v['static_options'])) {
      $attrs[$k]['options'] = $v['static_options'];
    }
    $attrs[$k]['module']  = 'intel';
    $attrs[$k]['key'] = $k;
  }

  // process vocabularies set as custom attributes
  $entity_settings = intel_get_entity_settings_multi('taxonomy');
  foreach ($entity_settings AS $k => $v) {

    // check if attribute key is set or if intel_track_page_terms_visitor
    if ((isset($v[$mode . '_attribute']) && !empty($v[$mode . '_attribute']['key']))
      || (($mode == 'visitor') && !empty($v['track_page_terms_visitor']))
    ) {
      $vocab_info = taxonomy_vocabulary_machine_name_load($k);
      if (empty($vocab_info->vid)) {
        continue;
      }
      // if mode == visitor,
      if (($mode == 'visitor') && (empty($v[$mode . '_attribute']['key']))) {
        $key = !empty($v['page_attribute']['key']) ? $v['page_attribute']['key'] : 't';
        if (!isset($v['visitor_attribute'])) {
          $v['visitor_attribute'] = array();
        }
        $v['visitor_attribute'] += $v['page_attribute'];
      }
      else {
        $key = $v[$mode . '_attribute']['key'];
      }

      $attrs[$key] = $v[$mode . '_attribute'];
      if (empty($attrs[$key]['title'])) {
        $attrs[$key]['title'] = $vocab_info->name;
      }
      if (empty($attrs[$key]['description'])) {
        $attrs[$key]['description'] = $vocab_info->description;
      }
      $attrs[$key]['options_description'] = t('Generated from taxonomy vocabulary !link.',
        array(
          '!link' => l($vocab_info->name, 'admin/structure/taxonomy/' . $k . '/edit'),
        )
      );
      $attrs[$key]['key'] = $key;
      $attrs[$key]['type'] = ($mode == 'visitor') ? 'vector' : 'list';
      $attrs[$key]['module']  = 'intel';
      $attrs[$key]['source_type']  = 'taxonomy';
      $attrs[$key]['options info callback']  = 'intel_page_attribute_taxomony_term_option_info';
      $attrs[$key]['module']  = 'intel';
      $attrs[$key]['options'] = array();

    }
  }

  // load custom attributes and overrides
  $custom = intel_get_page_attributes_custom_multi($mode);
  foreach ($custom AS $k => $v) {
    // check if custom attribute
    if (isset($attrs[$k])) {
      foreach ($v AS $a => $b) {
        $attrs[$k][$a] = $b;
      }
    }
    else {
      $custom[$k]['module']  = 'intel';
      $custom[$k]['key']  = $k;
      $custom[$k]['custom'] = 1;
      $attrs[$k] = $custom[$k];
    }
    if (!empty($custom[$k]['custom_options'])) {
//sdm($custom[$k]['custom_options']);
      if (!isset($attrs[$k]['options'])) {
        $attrs[$k]['options'] = $custom[$k]['custom_options'];
      }
      else {
        $attrs[$k]['options'] += $custom[$k]['custom_options'];
      }
    }
  }

  foreach (module_implements('intel_' . $mode . '_attribute_info') AS $module) {
    $function = $module . '_intel_' . $mode . '_attribute_info';
    $a = $function();
    if (empty($a) || !is_array($a)) {
      continue;
    }
    foreach ($a AS $k => $v) {
      $v['module'] = $module;
      $v['key'] = $k;
      $attrs[$k] = $v;
    }
  }

  drupal_alter('intel_' . $mode . '_attribute_info', $attrs);

  uasort($attrs, '_intel_sort_by_title');

  $attributes[$mode] = $attrs;

  if (isset($name)) {
    if (isset($attributes[$mode][$name])) {
      return $attributes[$mode][$name];
    }
    else {
      return FALSE;
    }
  } else {
    return $attributes[$mode];
  }
}

/**
 * Provides visitor and page attribute option meta data. Primarily used to provide
 * a human readable title for a given attribute option id.
 *
 * @param $mode
 *   sets the type of attribute, page | visitor
 * @param $attr_key
 *   The name that identifies the attribute
 * @param $option_id
 *   Attribute specific key that identifies which option id to provide info.
 *   Typically a numeric id or machine name, e.g. uid for authors, tid for tax
 *   terms, content type machine name.
 * @param array $data_options (optional)
 *
 * @return array
 *   - title: human readable label for the option
 *   - [extras]: additional data may be added as requested in $data_options
 */
function intel_get_attribute_option_info($mode, $attr_key, $option_id, $data_options = array()) {
  $info = intel_get_visitor_attribute_info();
  //dsm($info);
  if ($mode == 'page') {
    $attrInfo = intel_get_page_attribute_info($attr_key);
  }
  else {
    $attrInfo = intel_get_visitor_attribute_info($attr_key);
  }
  if (!empty($attrInfo)) {

  }

  //dsm($attrInfo);

  $data = array(
    'title' => '',
  );

  if (!empty($attrInfo['options info callback'])) {
    $data = $attrInfo['options info callback']($option_id, $data_options);
  }
  else if (($attrInfo['module'] == 'intel') && isset($attrInfo['source_type']) && ($attrInfo['source_type'] == 'taxonomy')) {
    $term = taxonomy_term_load($option_id);
    if (!empty($term)) {
      $data['title'] = $term->name;
    }
    if (!empty($data_options['page_count'])) {
      $query = db_query("SELECT count(nid) FROM {taxonomy_index} WHERE tid = :tid", array(
        ':tid' => $option_id,
      ));

      $data['page_count'] = $query->fetchField();
    }
  }
  else if (isset($attrInfo['options'][$option_id])) {
    $data = $attrInfo['options'][$option_id];
  }

  return $data;
}

function intel_page_attribute_author_option_info($option_id, $data_options) {
  $data = array(
    'title' => '',
  );
  $account = user_load($option_id);
  if (!empty($account)) {
    $data['title'] = format_username($account);
    $data['uri'] = 'user/' . $account->uid;
  }

  if (!empty($data_options['page_count'])) {
    $query = db_query("SELECT count(nid) FROM {node} WHERE uid = :uid", array(
      ':uid' => $option_id,
    ));

    $data['page_count'] = $query->fetchField();
  }
  return $data;
}

function intel_page_attribute_content_type_option_info($option_id, $data_options) {
  $data = array(
    'title' => '',
  );
  $types = node_type_get_types();
  //print_r($types);
  $type = '';
  if (isset($types[$option_id])) {
    $data['title'] = $types[$option_id]->name;
    $type = $option_id;
  }
  else if (isset($types['enterprise_' . $option_id])) {
    $data['title'] = $types['enterprise_' . $option_id]->name;
    $type = 'enterprise_' . $option_id;
  }

  if ($type && !empty($data_options['page_count'])) {
    $query = db_query("SELECT count(nid) FROM {node} WHERE type = :type", array(
      ':type' => $type,
    ));

    $data['page_count'] = $query->fetchField();
  }
  return $data;
}

// TODO: Not completed
function intel_page_attribute_entity_type_option_info($option_id, $data_options) {
  $data = array(
    'title' => '',
  );
  $types = node_type_get_types();
  //print_r($types);
  $type = '';
  if (isset($types[$option_id])) {
    $data['title'] = $types[$option_id]->name;
    $type = $option_id;
  }
  else if (isset($types['enterprise_' . $option_id])) {
    $data['title'] = $types['enterprise_' . $option_id]->name;
    $type = 'enterprise_' . $option_id;
  }

  if ($type && !empty($data_options['page_count'])) {
    $query = db_query("SELECT count(nid) FROM {node} WHERE type = :type", array(
      ':type' => $type,
    ));

    $data['page_count'] = $query->fetchField();
  }
  return $data;
}

function intel_page_attribute_taxomony_term_option_info($option_id, $data_options) {
  $data = array(
    'title' => '',
  );
  $term = taxonomy_term_load($option_id);
  if (!empty($term)) {
    $data['title'] = $term->name;
    $data['uri'] = 'taxonomy/term/' . $option_id;
  }

  if (!empty($data_options['page_count'])) {
    $query = db_query("SELECT count(nid) FROM {taxonomy_index} WHERE tid = :tid", array(
      ':tid' => $option_id,
    ));

    $data['page_count'] = $query->fetchField();
  }

  return $data;
}

function intel_page_attribute_published_date_option_info($value, $data_options) {
  $data = array();
  $count_value = '';
  $count_op = 'LIKE';
  if (substr($value, 0 , 1) == 'w') {
    $dow = array(
      t('Sunday'),
      t('Monday'),
      t('Tuesday'),
      t('Wednesday'),
      t('Thursday'),
      t('Friday'),
      t('Saturday'),
    );
    $i = (int)substr($value, 1, 1);
    $data['title'] = $dow[$i];
    $count_value = '^[0-9]{12}' . $i . '$';
    $count_op = 'REGEXP';
  }
  else if (substr($value, 0, 2) == 'Hi') {
    $i = substr($value, 2, 4) .
    $data['title'] = substr($value, 2, 2) . ':' . substr($value, 4, 2);
    $count_value = '^[0-9]{8}' . $i . '[0-9]$';
    $count_op = 'REGEXP';
  }
  else if (substr($value, 0, 1) == 'H') {
    $i = substr($value, 1, 2);
    $data['title'] = substr($value, 1, 2) .  ':00 ' . t('hours');
    $count_value = '^[0-9]{8}' . $i . '[0-9]{3}$';
    $count_op = 'REGEXP';
  }
  // YYYYMMDDHHMM
  else if (strlen($value) == 8) {
    $data['title'] = substr($value, 0, 4) . '-' . substr($value, 4, 2) . '-' . substr($value, 6, 2);
    $count_value = substr($value, 0, 8) . '%';
  }
  // YYYYMM
  else {
    $data['title'] = substr($value, 0, 4) . '-' . substr($value, 4, 2);
    $count_value = substr($value, 0, 6) . '%';
  }

  if (!empty($data_options['page_count']) && $count_value) {
    $data['page_count'] = intel_entity_attr_entity_count('pd', $count_value, null, $count_op);
  }
  return $data;
}

function intel_page_attribute_published_age_option_info($option_id, $data_options) {
  $group = explode('-', $option_id);
  $titles = array(
    '0' => t('Last 24 hours'),
    '86400' => t('A day to a week'),
    '604800' => t('A week to a month'),
    '2592000' => t('A month to 3 months'),
    '7776000' => t('3 months to a year'),
  );

  $data = array(
    'title' => isset($titles[$group[0]]) ? $titles[$group[0]] : $option_id,
  );

  if (!empty($data_options['page_count'])) {
    $data['page_count'] = intel_entity_attr_entity_count('pdw', (int)$option_id);
  }
  return $data;
}

function intel_page_attribute_published_dow_option_info($option_id, $data_options) {
  $dow = array(
    t('Sunday'),
    t('Monday'),
    t('Tuesday'),
    t('Wednesday'),
    t('Thursday'),
    t('Friday'),
    t('Saturday'),
  );

  $data = array(
    'title' => isset($dow[$option_id]) ? $dow[$option_id] : $option_id,
  );

  if (!empty($data_options['page_count'])) {
      $data['page_count'] = intel_entity_attr_entity_count('pdw', (int)$option_id);
  }
  return $data;
}

function intel_page_attribute_published_tod_option_info($option_id, $data_options) {
  $group = explode('-', $option_id);

  $h0 = (int)substr($group[0], 0, -2);
  $m0 = substr($group[0], -2);
  $pf0 = 'am';
  if ($h0 > 12) {
    $h0 = $h0 - 12;
    $pf0 = 'pm';
  }

  if (isset($group[1])) {
    $h1 = (int)substr($group[1], 0, -2);
    $m1 = 59;
    if ($h1 > 12) {
      $h1 = $h1 - 12;
    }
    $d1 = " - $h1:$m1";
  }

  $data = array(
    'title' => "$h0:$m0$d1 $pf0",
  );

  if (!empty($data_options['page_count'])) {
    if (count($group) == 2) {
      $data['page_count'] = intel_entity_attr_entity_count('pdt', (int)$group[0], (int)$group[1]);
    }
    else {
      $data['page_count'] = intel_entity_attr_entity_count('pdt', (int)$group[0]);
    }
  }
  return $data;
}

function intel_get_page_intents_default($filter = 'report') {
  $intents = array();
  if ($filter == 'report') {
    $intents[''] = array(
      'title' => t('(not set)'),
      'description' => t('Intent is not set by page.'),
      'category' => 'system',
    );
  }
  if ($filter == 'entity_edit') {
    $intents['_default'] = array(
      'title' => t('- Default -'),
      'description' => t('Use the default for the entity type.'),
      'category' => 'system',
    );
  }
  $intents['a'] = array(
    'title' => t('Admin'),
    'description' => t('Pages used to administer the site.'),
  );
  $intents['t'] = array(
    'title' => t('Attraction'),
    'description' => t('Pages designed to attract people and generate buzz such as blog posts and podcasts.'),
  );
  $intents['i'] = array(
    'title' => t('Information'),
    'description' => t('Page that are informational such as product and services.'),
  );
  $intents['l'] = array(
    'title' => t('Landing page'),
    'description' => t('Page that is designed to entice visitors to submit a form or do one specific action.'),
  );
  $intents['u'] = array(
    'title' => t('Utility'),
    'description' => t('Support pages that should be excluded from content reports. Useful for thankyou pages.'),
  );
  return $intents;
}

function intel_get_page_intents($filter = 'report') {
  $intents = &drupal_static(__FUNCTION__);
  if (!empty($intents)) {
    return $intents;
  }
  $page_attributes = intel_get_page_attribute_info();

  $page_intents = $page_attributes['i']['options'];

  uasort($page_intents, '_intel_sort_by_title');

  return $page_intents;
}


/*
function intel_visitor_attribute_load($key) {
  $attributes = intel_get_visitor_attribute_info();
  $attribute = $attributes[$key];
  $attribute['key'] = $key;
  return $attribute;
}
*/


function intel_get_phonenumbers() {
  $phonenumbers = &drupal_static(__FUNCTION__);
  if (count($phonenumbers)) {
    return $phonenumbers;
  }
  $phonenumbers = variable_get('intel_phonenumbers', array());
  foreach ($phonenumbers AS $name => $number) {
    $phonenumbers[$name]['custom'] = 1;
  }

  drupal_alter('intel_phonenumbers', $phonenumbers);

  return $phonenumbers;
}

function intel_phonenumber_load($key) {
  $phonenumbers = intel_get_phonenumbers();
  if (!isset($phonenumbers[$key])) {
    return FALSE;
  }
  $phonenumber = $phonenumbers[$key];
  $phonenumber['key'] = $key;
  return $phonenumber;
}

function intel_phonenumber_load_by_number($number) {
  $numbers = &drupal_static(__FUNCTION__);
  if (isset($numbers[$number])) {
    return $numbers[$number];
  }
  $phonenumbers = intel_get_phonenumbers();
  foreach ($phonenumbers AS $name => $phonenumber) {
    if ($phonenumber['number'] == $number) {
      $numbers[$number] = $phonenumber;
      break;
    }
  }

  if (isset($numbers[$number])) {
    return $numbers[$number];
  }
  // number not found
  else {
    return FALSE;
  }
}

function intel_phonenumber_save($phonenumber, $key = '') {
  if (empty($key)) {
    if (!empty($phonenumber['key'])) {
      $key = $phonenumber['key'];
    }
    else {
      return FALSE;
    }
  }
  if (empty($phonenumber['title'])) {
    $phonenumber['title'] = $phonenumber['number'];
  }
  if (empty($phonenumber['number_display'])) {
    $phonenumber['number_display'] = $phonenumber['number'];
  }

  $phonenumbers = variable_get('intel_phonenumbers', array());
  $phonenumbers[$key] = $phonenumber;
  $phonenumbers = variable_set('intel_phonenumbers', $phonenumbers);
  return $phonenumber;
}

function intel_get_page_attributes_custom_multi($mode = 'visitor') {
  $query = db_select('variable', 'v')
    ->fields('v')
    ->condition('name', 'intel_' . $mode . '_attribute_custom_%', 'LIKE');
  $result = $query->execute();

  $data = array();
  while ($row = $result->fetchObject()) {
    $a = explode('_', $row->name);
    $data[$a[4]] = unserialize($row->value);
  }
  return $data;
}

function intel_get_entity_settings_multi($entity_type, $bundle = '') {
  $query = db_select('variable', 'v')
    ->fields('v');

  if ($bundle == '') {
    $query->condition('name', 'intel_entity_settings_' . $entity_type . '__%', 'LIKE');
  }
  else {
    $query->condition('name', 'intel_entity_settings_' . $entity_type . '__' . $bundle);
  }
  $result = $query->execute();

  $data = array();
  while ($row = $result->fetchObject()) {
    $a = explode('_', $row->name, 6);
    $data[$a[5]] = unserialize($row->value);
  }
  return $data;
}

function intel_index_encode($base10) {
  // crockford base32 encoding
  //return strtr( base_convert($base10, 10, 32), "abcdefghijklmnopqrstuv", "ABCDEFGHJKMNPQRSTVWXYZ");
  return strtolower(strtr( base_convert($base10, 10, 32), "abcdefghijklmnopqrstuv", "ABCDEFGHJKMNPQRSTVWXYZ"));
}

function intel_index_decode($base32) {
  // crockford base32 decoding
  $base32 = strtr(strtoupper($base32), "ABCDEFGHJKMNPQRSTVWXYZILO", "abcdefghijklmnopqrstuv110");

  return (int)base_convert($base32, 32, 10);
}

function _intel_sort_by_title($a, $b) {
  return ($a['title'] > $b['title']) ? 1 : -1;
}

function _intel_sort_by_category($a, $b) {
  return ($a['category'] > $b['category']) ? 1 : -1;
}

function _intel_sort_by_rtime($a, $b) {
  return ($a['time'] < $b['time']) ? 1 : -1;
}

function intel_init_targets() {
  $target = array();
  $target['entrances_per_month'] = array(
    'title' => t('Total visitors / month'),
    'description' => t('Your target for the number of total visitors you want to get to the site.'),
    'value' => 3000,
    'group' => 'site_kpi_month',
  );
  $target['leads_per_month'] = array(
    'title' => t('New contacts / month'),
    'description' => t('Your target for the number of contacts in a month.'),
    'value' => 30,
    'group' => 'site_kpi_month',
  );
  $target['posts_per_month'] = array(
    'title' => t('Posts / month'),
    'description' => t('Your target attraction, e.i. blog, posts in a month.'),
    'value' => 8,
    'group' => 'site_kpi_month',
  );
  $target['entrances_per_day'] = array(
    'title' => t('Total visitors / day'),
    'description' => t('Your target for the number of total visitors you want to get to the site.'),
    'value' => 100.00,
    'group' => 'site_day',
  );
  $target['entrances_per_day_warning'] = array(
    'title' => t('Total visitors / day (warning)'),
    'description' => t('Your target for the number of total visitors you want to get to the site.'),
    'value' => 25.00,
    'group' => 'site_day',
  );

  $target['value_per_day'] = array(
    'title' => t('Total value / day'),
    'description' => t('Your target for the total value of all traffic to the site.'),
    'value' => 100.00,
    'group' => 'site_day',
  );
  $target['value_per_day_warning'] = array(
    'title' => t('Total value / day (warning)'),
    'description' => t('Your target for the total value of all traffic to the site.'),
    'value' => 25.00,
    'group' => 'site_day',
  );

  $target['conversions_per_day'] = array(
    'title' => t('Total conversions / day'),
    'description' => t('Your target for the number of total visitors you want to get to the site.'),
    'value' => 4.00,
    'group' => 'site_day',
  );
  $target['conversions_per_day_warning'] = array(
    'title' => t('Total conversions / day (warning)'),
    'description' => t('Your target for the number of total visitors you want to get to the site.'),
    'value' => 1.00,
    'group' => 'site_day',
  );

  $target['value_per_page_per_day'] = array(
    'title' => t('Value per page / day'),
    'description' => t('Your target for the total value of all traffic to the site.'),
    'value' => 1.00,
    'group' => 'page',
  );
  $target['value_per_page_per_day_warning'] = array(
    'title' => t('Value per page / day (warning)'),
    'description' => t('Your target for the total value of all traffic to the site.'),
    'value' => 0.10,
    'group' => 'page',
  );

  $target['value_per_page_per_entrance'] = array(
    'title' => t('Value per page / entry'),
    'description' => t('Your target for the total value of all traffic to the site.'),
    'value' => 0.50,
    'group' => 'page',
  );
  $target['value_per_page_per_entrance_warning'] = array(
    'title' => t('Value per page / entry (warning)'),
    'description' => t('Your target for the total value of all traffic to the site.'),
    'value' => 0.20,
    'group' => 'page',
  );

  $target['value_per_visit'] = array(
    'title' => t('Value / visit'),
    'description' => t('Your target for the total value of all traffic to the site.'),
    'value' => 1.00,
    'group' => 'visit',
  );
  $target['value_per_visit_warning'] = array(
    'title' => t('Value per page / day (warning)'),
    'description' => t('Your target for the total value of all traffic to the site.'),
    'value' => 0.10,
    'group' => 'visit',
  );


  return $target;
}

function intel_get_targets() {
  $stargets = &drupal_static(__FUNCTION__);
  if (isset($targets)) {
    return $targets;
  }
  $targets = array();
  $defaults = intel_init_targets();
  foreach ($defaults AS $k => $v) {
    $targets[$k] = $v['value'];
  }
  $ds = variable_get('intel_targets', array());
  foreach ($ds AS $k => $v) {
    if (trim($v)) {
      $targets[$k] = $v;
    }
  }
  if (empty($targets['entrances_per_page_per_day'])) {
    $targets['entrances_per_page_per_day'] = $targets['value_per_page_per_day'] / $targets['value_per_page_per_entrance'];
  }
  if (empty($targets['entrances_per_page_per_day_warning'])) {
    $targets['entrances_per_page_per_day_warning'] = $targets['value_per_page_per_day_warning'] / $targets['value_per_page_per_entrance_warning'];
  }
  return $targets;
}

function intel_get_base_scorings() {
  $scoring = array();
  $scoring['entrance'] = array(
    'title' => t('Entrances'),
    'description' => t('A visit to the site.'),
    'value' => 0.05,
  );
  $scoring['stick'] = array(
    'title' => t('Sticks'),
    'description' => t('The visitor went to at least on other page or triggered a interaction event. Entrances - bounces'),
    'value' => 0.10,
  );
  $scoring['additional_pages'] = array(
    'title' => t('Additional pages'),
    'description' => t('Each additional page beyond the initial entrance page.'),
    'value' => 0.02,
  );
  return $scoring;
}

function intel_get_submission_goals_default() {
  $defs = array();
  $defs['tofu-conversion'] = array(
    'title' => t('ToFu conversion'),
    'description' => t('Top of the funnel conversion'),
    'value' => 15,
    'ga_id' => 1,
  );
  $defs['mofu-conversion'] = array(
    'title' => t('MoFu conversion'),
    'description' => t('Middle of the funnel conversion'),
    'value' => 50,
    'ga_id' => 2,
  );
  $defs['bofu-conversion'] = array(
    'title' => t('BoFu conversion'),
    'description' => t('Bottom of the funnel conversion'),
    'value' => 100,
    'ga_id' => 3,
  );
  $defs['subscribe-form'] = array(
    'title' => t('Subscribe form'),
    'description' => t('Subscribe to email updates form submission'),
    'value' => 25,
    'ga_id' => 4,
  );
  $defs['contact-form'] = array(
    'title' => t('Contact form'),
    'description' => t('Main contact form submission'),
    'value' => 25,
    'ga_id' => 5,
  );

  return $defs;
}

function intel_get_phonecall_goals_default() {
  $defs = array();
  $defs['contact-call'] = array(
    'title' => t('Contact call'),
    'description' => t('Main contact number called'),
    'value' => 25,
    'ga_id' => 6,
  );

  return $defs;
}

function intel_get_scorings($filter = '') {
  $scorings = &drupal_static(__FUNCTION__);
  if (isset($scorings[$filter])) {
    return $scorings[$filter];
  }
  if (!isset($scorings)) {
    $scorings = array();
  }
  if (!isset($scorings[$filter])) {
    $scorings[$filter] = array();
  }
  $custom = variable_get('intel_scorings', array());
  $base = intel_get_base_scorings();
  foreach ($base AS $i => $m) {
    if (($filter == 'js_setting') && (empty($m['js_setting']))) {
      //continue;
    }
    $scorings[$filter][$i] = isset($custom[$i]) ? $custom[$i] : $m['value'];
  }

  $events = intel_get_intel_event_info();
  foreach ($events AS $i => $m) {
    if (($filter == 'js_setting') && (empty($m['js_setting']))) {
      continue;
    }
    if (!empty($m['valued_event'])) {
      $scorings[$filter][$i] = isset($custom[$i]) ? $custom[$i] : $m['value'];
    }
  }

  $goals = variable_get('intel_event_goals', array());
  $goals = array_merge($goals, variable_get('intel_submission_goals', intel_get_submission_goals_default()));
  $goals = array_merge($goals, variable_get('intel_phonecall_goals', intel_get_phonecall_goals_default()));
  foreach ($goals AS $i => $m) {
    if (($filter == 'js_setting') && (empty($m['js_setting']))) {
      continue;
    }
    $i = 'goal_' . $i;
    $scorings[$filter][$i] = isset($custom[$i]) ? $custom[$i] : (isset($m['value']) ? $m['value'] : 0);
  }

  return $scorings[$filter];
}

function intel_get_scoring($event, $mode = 'machinename') {
  $scoring = intel_get_scorings();

  return $scoring;
}

/**
 * Scores data feed item in a entrance (session) context
 *
 * @param $data
 * @param int $divideby
 * @param array $score_components
 * @param string $mode
 * @return mixed
 */
function intel_score_visit_aggregation($data, $divideby = 1, &$score_components = array(), $mode = '') {
  $scoring = intel_get_scorings();
  $scores = array(
    '_all' => 0,
    'events' => 0,
    'goals' => 0,
    'traffic' => 0,
  );

  $entrance = array(
    'entrances' => 0,
  );
  if ($mode == 'social') {
    if (!empty($data['socialNetwork']['_all']['entrance'])) {
      $entrance = $data['socialNetwork']['_all']['entrance'];
    }
    elseif (!empty($data['socialNetwork']['entrance'])) { // for all rows
      $entrance = $data['socialNetwork']['entrance'];
    }
  }
  elseif ($mode == 'seo') {
    if (!empty($data['organicSearch']['_all']['entrance'])) {
      $entrance = $data['organicSearch']['_all']['entrance'];
    }
    elseif (!empty($data['organicSearch']['entrance'])) { // for all rows
      $entrance = $data['organicSearch']['entrance'];
    }
  }
  else {
    if (!empty($data['entrance'])) {
      $entrance = $data['entrance'];
    }
  }

  // entrance scoring
  if ($entrance['entrances']) {
    // the value of any goals achieved during sessions started by the item
    $scores['goals'] += $entrance['goalValueAll'];
    // the value of any valued events triggered during sessions started by the item
    if (isset($entrance['events']['_all'])) {
      $scores['events'] += ($entrance['events']['_all']['value']);
    }
    // scoring of traffic genearted by the item
    $scores['traffic'] += $entrance['entrances'] * $scoring['entrance'];
    if (!empty($entrance['sticks'])) {
      $scores['traffic'] += $entrance['sticks'] * $scoring['stick'];
    }
    if ($entrance['pageviews'] > ($entrance['entrances'] - $entrance['sticks'])) {
      $scores['traffic'] += ($entrance['pageviews'] - $entrance['entrances'] - $entrance['sticks']) * $scoring['additional_pages'];
    }
  }
  if (isset($data['pageview'])) {

  }

  foreach ($scores AS $i => $score) {
    if (substr($i, 0, 1) == '_') {
      continue;
    }
    $scores[$i] = $score / $divideby;
    $scores['_all'] += $scores[$i];
  }

  $score_components = $scores;
  return $scores['_all'];
}

/**
 * Scores data feed item in page or page-attr context
 * @param $data
 * @param int $divideby
 * @param array $score_components
 * @param string $mode
 * @return mixed
 */
function intel_score_page_aggregation($data, $divideby = 1, &$score_components = array(), $mode = '', $method = 'site', $options = array()) {
  $scoring = intel_get_scorings();
  $scores = array(
    '_all' => array(
      '_all' => 0,
      'events' => 0,
      'goals' => 0,
      'traffic' => 0,
    ),
    // stats for values generated directly by the item on non
    'onpage' => array(
      '_all' => 0,
      'events' => 0,
      'goals' => 0,
      'traffic' => 0,
    ),
    // stats for values generated during sessions where the item is the entrance
    'entrance' => array(
      '_all' => 0,
      'events' => 0,
      'goals' => 0,
      'traffic' => 0,
    ),
    // stats generated downstream from page hit
    'assist' =>  array(
      '_all' => 0,
      'events' => 0, // N/A
      'goals' => 0,
      'traffic' => 0, // N/A
    ),
  );
  // Note that entrance and assist stats include onpage data

  $ac = .1; // assist coef
  $page = $data['pageview'];
  $entrance = array(
    'entrances' => 0,
  );
  if ($mode == 'social') {
    if (!empty($data['socialNetwork']['_all']['entrance'])) {
      $entrance = $data['socialNetwork']['_all']['entrance'];
    }
  }
  elseif ($mode == 'seo') {
    if (!empty($data['organicSearch']['_all']['entrance'])) {
      $entrance = $data['organicSearch']['_all']['entrance'];
    }
  }
  else {
    if (!empty($data['entrance'])) {
      $entrance = $data['entrance'];
    }
  }
  ///////////////////////
  // entrance scoring

  if ($entrance['entrances']) {
    // the value of any goal achieved on any page in sessions started
    // on this page or segement but not directly by the page
    $scores['entrance']['goals'] += $entrance['goalValueAll'];

    // the value of any valued events generated on any page in sessions started
    // on this page or segement
    if (isset($entrance['events']['_all'])) {
      $scores['entrance']['events'] += $entrance['events']['_all']['value'];
    }
    // traffic scoring based on traffic generated by this page or segement
    $scores['entrance']['traffic'] += $entrance['entrances'] * $scoring['entrance'];
    //$scores['_all']['traffic'] += $entrance['entrances'] * $scoring['entrance'];
    if (!empty($entrance['sticks'])) {
      $scores['entrance']['traffic'] += $entrance['sticks'] * $scoring['stick'];
    }
    if ($entrance['pageviews']['traffic'] > 2) {
      $scores['entrance']['traffic'] += ($entrance['pageviews'] - $entrance['entrances'] - $entrance['sticks']) * $scoring['additional_pages'];
    }
  }

  ///////////////////////
  // page hit scoring

  // the value of any goals achieved on the page or a page in the segment
  if (!empty($page['goalValueAll'])) {
    $scores['onpage']['goals'] += $page['goalValueAll'];
  }

  // the value of any goal achieved on this page/segement or downstream
  if (!empty($page['pageValueAll'])) {
    $scores['assist']['goals'] += ($page['pageValueAll'] - $page['goalValueAll']);
  }

  // the value of events triggered on this page/segment
  if (isset($page['events']['_all'])) {
    $scores['onpage']['events'] += $page['events']['_all']['value'];
  }
  // traffic scoring based on hit on this page/segment
  $scores['onpage']['traffic'] += ($page['pageviews'] - $entrance['entrances']) * $scoring['additional_pages'];

  // tally up scores from components
  $method = !empty($options['method']) ? !empty($options['method']) :'';
  if ($method == 'direct') {

  }
  else {
    $scores['_all']['goals'] = (1 - $ac) * $scores['entrance']['goals'] + $ac * ($scores['assist']['goals']);
    $scores['_all']['events'] = (1 - $ac) * $scores['onpage']['events'] + $ac * ($scores['entrance']['events']);
    $scores['_all']['traffic'] = $scores['entrance']['traffic'] + $scores['onpage']['traffic'];
  }


  // do divide bys and total up alls
  foreach ($scores AS $i => $a) {
    foreach ($a AS $j => $b) {
      if (substr($j, 0, 1) == '_') {
        continue;
      }
      $scores[$i][$j] = $scores[$i][$j] / $divideby;
      $scores[$i]['_all'] += $scores[$i][$j];
    }
  }

  $score_components = $scores;
  return $scores['_all']['_all'];
}

/**
 * Scores data feed item in page or page-attr context
 * @param $data
 * @param int $divideby
 * @param array $score_components
 * @param string $mode
 * @return mixed
 */
function intel_score_item($data, $divideby = 1, &$score_components = array(), $mode = '', $method = '', $options = array()) {
  $scoring = intel_get_scorings();
  $scores = array(
    '_all' => array(
      '_all' => 0,
      'events' => 0,
      'goals' => 0,
      'traffic' => 0,
    ),
    // stats for values generated directly by the item on non
    'onpage' => array(
      '_all' => 0,
      'events' => 0,
      'goals' => 0,
      'traffic' => 0,
    ),
    // stats for values generated during sessions where the item is the entrance
    'entrance' => array(
      '_all' => 0,
      'events' => 0,
      'goals' => 0,
      'traffic' => 0,
    ),
    // stats generated downstream from page hit
    'assist' =>  array(
      '_all' => 0,
      'events' => 0,
      'goals' => 0,
      'traffic' => 0,
    ),
  );
  // Note that entrance and assist stats include onpage data

  $ac = .1; // assist coef
  $page = array(
    'pageviews' => 0,
    'goalsValueAll' => 0,
    'pageValueAll' => 0,
  );
  if (isset($data['pageview'])) {
    $page = $data['pageview'];
  }

  $entrance = array();

  if ($mode == 'social') {
    if (!empty($data['socialNetwork']['_all']['entrance'])) {
      $entrance = $data['socialNetwork']['_all']['entrance'];
    }
  }
  elseif ($mode == 'seo') {
    if (!empty($data['organicSearch']['_all']['entrance'])) {
      $entrance = $data['organicSearch']['_all']['entrance'];
    }
  }
  else {
    if (!empty($data['entrance'])) {
      $entrance = $data['entrance'];
    }
  }
  $entrance += array(
    'entrances' => 0,
    'pageviews' => 0,
    'goalsValueAll' => 0,
  );
  ///////////////////////
  // entrance scoring

  if ($entrance['entrances']) {
    // the value of any goal achieved on any page in sessions started
    // on this page or segement but not directly by the page
    $scores['entrance']['goals'] += $entrance['goalValueAll'];

    // the value of any valued events generated on any page in sessions started
    // on this page or segement
    if (isset($entrance['events']['_totals'])) {
      $scores['entrance']['events'] += $entrance['events']['_totals']['value'];
    }
    else if (isset($entrance['events']['_all'])) {
      $scores['entrance']['events'] += $entrance['events']['_all']['value'];
    }
    // traffic scoring based on traffic generated by this page or segement
    $scores['entrance']['traffic'] += $entrance['entrances'] * $scoring['entrance'];
    //$scores['_all']['traffic'] += $entrance['entrances'] * $scoring['entrance'];
    if (!empty($entrance['sticks'])) {
      $scores['entrance']['traffic'] += $entrance['sticks'] * $scoring['stick'];
    }
    if ($entrance['pageviews'] > 2) {
      $scores['entrance']['traffic'] += ($entrance['pageviews'] - $entrance['entrances'] - $entrance['sticks']) * $scoring['additional_pages'];
    }
  }

  ///////////////////////
  // page hit scoring

  // the value of any goals achieved on the page or a page in the segment
  if (!empty($page['goalValueAll'])) {
    $scores['onpage']['goals'] += $page['goalValueAll'];
  }

  // the value of any goal achieved on this page/segement or downstream
  if (!empty($page['pageValueAll'])) {
    $scores['assist']['goals'] += ($page['pageValueAll'] - $page['goalValueAll']);
  }

  // the value of events triggered on this page/segment
  if (isset($page['events']['_totals'])) {
    $scores['onpage']['events'] += $page['events']['_totals']['value'];
  }
  else if (isset($page['events']['_all'])) {
    $scores['onpage']['events'] += $page['events']['_all']['value'];
  }

  // traffic scoring based on hit on this page/segment
  $scores['onpage']['traffic'] += ($page['pageviews'] - $entrance['pageviews']) * $scoring['additional_pages'];
//dsm($scores);
  // tally up scores from components
  if ($method == 'direct') {

  }
  else if ($method == 'page') {
    $scores['_all']['goals'] = (1 - $ac) * $scores['entrance']['goals'] + $ac * ($scores['assist']['goals']);
    $scores['_all']['events'] = (1 - $ac) * $scores['onpage']['events'] + $ac * ($scores['entrance']['events']);
    $scores['_all']['traffic'] = $scores['entrance']['traffic'] + $scores['onpage']['traffic'];
  }
  else if ($method == 'visitor') {
    // use for visitors
    $scores['_all']['goals'] = $scores['onpage']['goals'];
    $scores['_all']['events'] = $scores['onpage']['events'];
    // if visitor is filtered, entrance may not be included in filtered item
    // if entrance score is 0, use pageview for traffic
    $scores['_all']['traffic'] = !empty($scores['entrance']['traffic']) ? $scores['entrance']['traffic'] : $scores['onpage']['traffic'];
  }
  else if ($method == 'site') {
    // use for visitors
    $scores['_all']['goals'] = $scores['onpage']['goals'];
    $scores['_all']['events'] = $scores['onpage']['events'];
    // if visitor is filtered, entrance may not be included in filtered item
    // if entrance score is 0, use pageview for traffic
    $scores['_all']['traffic'] = $scores['entrance']['traffic'] + $scores['onpage']['traffic'];
  }
  else {
    // use entrance, trafficsources
    $scores['_all']['goals'] = $scores['entrance']['goals'];
    $scores['_all']['events'] = $scores['entrance']['events'];
    $scores['_all']['traffic'] = $scores['entrance']['traffic'];
  }


  // do divide bys and total up alls
  foreach ($scores AS $i => $a) {
    foreach ($a AS $j => $b) {
      if (substr($j, 0, 1) == '_') {
        continue;
      }
      $scores[$i][$j] = $scores[$i][$j] / $divideby;
      $scores[$i]['_all'] += $scores[$i][$j];
    }
  }

  $score_components = $scores;
  return $scores['_all']['_all'];
}

function _intel_get_report_dates_from_ops($ops = 'l30d', &$cache_options = array(), $return_hash = FALSE) {
  $start = '';
  $end = '';
  if (!empty($_GET['timeops'])) {
    $ops = $_GET['timeops'];
  }

  $a = explode(',', $ops);
  if (count($a) == 2) {
    $start = $a[0];
    $end = $a[1];
  }
  elseif ($ops == 'today') {
    $start = 'midnight';
    $end = 'now';
    $cache_options = array('refresh' => 1);
  }
  elseif (($ops == 'l24') || ($ops == 'l24fn') || ($ops == 'l24h') || ($ops == 'l24hfn')) {
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

function intel_ga_api_data($request = array(), $cache_options = array()) {
  $feed = google_analytics_reports_api_report_data($request, $cache_options);
  return $feed;
}


function intel_ga_feed_request_callback($request, $args) {
  $cache_options = $args['cache_options'];
  $request['sort_metric'] = $request['sort'];
  unset($request['sort']);
  $feed = intel_ga_api_data($request, $cache_options);
  return $feed;
}

function intel_report_add_js_callback($script, $type = 'file') {
  if ($type == 'inline') {
    drupal_add_js($script, array('type' => 'inline', 'scope' => 'header'));
  }
  else {
    $a = explode('//', $script);
    if ((count($a) == 2) && (substr($a[0], 0, 4) == 'http')) {
      drupal_add_js($script, array('type' => 'external', 'scope' => 'header'));
    }
    else {
      drupal_add_js(libraries_get_path('intel') . '/' . $script);
    }
  }
}

/**
 * TODO move to library
 * @param $vtk
 */
function intel_fetch_analytics_visitor_meta_data($vtkids) {
  intel_include_library_file('ga/class.ga_model.php');

  $visitor = array(
    'location' => array(),
    'environment' => array(),
    'lasthit' => 0,
  );

  list($start_date, $end_date, $number_of_days) = _intel_get_report_dates("-1 year", "Today");
  $cache = array(
    'refresh' => 1,
  );

  //$segment = 'dynamic::ga:customVarValue5==' . implode(',dynamic::ga:customVarValue5==', $vtkids);
  //$segment = 'users::condition::ga:customVarValue5==' . implode(',ga:customVarValue5==', $vtkids); // users has a limit of 90 days time frame
  //$segment = 'sessions::condition::ga:customVarValue5==' . implode(',ga:customVarValue5==', $vtkids);
  $segment = 'sessions::condition::ga:dimension5==' . implode(',ga:dimension5==', $vtkids);

  $request = array(
    'dimensions' => array('ga:browser', 'ga:browserVersion', 'ga:operatingSystem', 'ga:operatingSystemVersion', 'ga:language', 'ga:screenResolution', 'ga:dimension4'),
    'metrics' => array('ga:entrances'),
    'sort_metric' => '-ga:dimension4',
    'start_date' => $start_date,
    'end_date' => $end_date,
    'segment' => $segment,
    'max_results' => 1,
  );

  $data = intel_ga_api_data($request, $cache);
  if (!empty($_GET['debug'])) {
    dpm('ga_request'); dpm($request);//
    dpm('ga_data'); dpm($data);//
  }
  $rows = intel_get_ga_feed_rows($data);
  if (!empty($rows) && is_array($rows)) {
    foreach ($rows AS $row) {
      $ts = (int)$row['dimension4'];
      if ($ts > $visitor['lasthit']) {
        $visitor['lasthit'] = $ts;
      }
      $visitor['environment'] = array();
      $visitor['environment']['browser'] = $row['browser'];
      $visitor['environment']['browserVersion'] = $row['browserVersion'];
      $visitor['environment']['operatingSystem'] = $row['operatingSystem'];
      $visitor['environment']['operatingSystemVersion'] = $row['operatingSystemVersion'];
      $visitor['environment']['language'] = $row['language'];
      $visitor['environment']['screenResolution'] = $row['screenResolution'];
    }
  }

  $request['dimensions'] = array('ga:isMobile', 'ga:mobileDeviceBranding', 'ga:mobileDeviceModel', 'ga:mobileDeviceInfo', 'ga:dimension4');
  $request['metrics'] = array('ga:entrances');

  $data = intel_ga_api_data($request, $cache);

  $rows = intel_get_ga_feed_rows($data);
  if (!empty($rows) && is_array($rows)) {
    foreach ($rows AS $row) {
      $ts = (int)$row['dimension4'];
      $visitor['environment']['isMobile'] = $row['isMobile'];
      $visitor['environment']['mobileDeviceBranding'] = $row['mobileDeviceBranding'];
      $visitor['environment']['mobileDeviceModel'] = $row['mobileDeviceModel'];
      $visitor['environment']['mobileDeviceInfo'] = $row['mobileDeviceInfo'];
    }
  }

  $request['dimensions'] = array('ga:country', 'ga:region', 'ga:city', 'ga:metro', 'ga:latitude', 'ga:longitude', 'ga:dimension4');
  $request['metrics'] = array('ga:entrances');

  $data = intel_ga_api_data($request, $cache);

  $rows = intel_get_ga_feed_rows($data);
  if (!empty($rows) && is_array($rows)) {
    foreach ($rows AS $row) {
      $ts = (int)$row['dimension4'];
      if ($ts > $visitor['lasthit']) {
        $visitor['lasthit'] = $ts;
      }
      $visitor['location']['country'] = $row['country'];
      $visitor['location']['region'] = $row['region'];
      $visitor['location']['city'] = $row['city'];
      $visitor['location']['metro'] = $row['metro'];
      $visitor['location']['latitude'] = $row['latitude'];
      $visitor['location']['longitude'] = $row['longitude'];
    }
  }

  $visitor['visits'] = array(
    '_all' => array(
      'score' => 0,
      'entrance' => array(
        'entrances' => 0,
        'pageviews' => 0,
        'timeOnSite' => 0,
        'score' => 0,
      ),
    ),
    '_totals' => array(
      'entrance' => array(
        'entrances' => 0,
        'pageviews' => 0,
        'timeOnSite' => 0,
        'sticks' => 0,
        'goalValueAll' => 0,
        'events' => array(),
        'score' => 0,
      ),
    ),
  );

  // get totals
  $request['dimensions'] = array();
  $request['metrics'] = array('ga:entrances', 'ga:pageviews', 'ga:bounces', 'ga:timeOnSite', 'ga:goalValueAll');
  $request['sort_metric'] = '';
  $request['max_results'] = 1000;

  $data = intel_ga_api_data($request, $cache);
  //dsm($request); dsm($data);
  $rows = intel_get_ga_feed_rows($data);
  if (!empty($rows) && is_array($rows)) {
    foreach ($rows AS $row) {
      $visitor['visits']['_totals']['entrance']['entrances'] += $row['entrances'];
      $visitor['visits']['_totals']['entrance']['pageviews'] += $row['pageviews'];
      $visitor['visits']['_totals']['entrance']['sticks'] += ($row['entrances'] - $row['bounces']);
      $visitor['visits']['_totals']['entrance']['timeOnSite'] += $row['timeOnSite'];
      $visitor['visits']['_totals']['entrance']['goalValueAll'] += $row['goalValueAll'];
    }
  }

  $request['metrics'] = array('ga:totalEvents', 'ga:uniqueEvents', 'ga:eventValue');
  $request['filters'] = 'ga:eventCategory=~^*!$';
  $data = intel_ga_api_data($request, $cache);
  //dsm($request); dsm($data);
  $rows = intel_get_ga_feed_rows($data);
  if (!empty($rows) && is_array($rows)) {
    foreach ($rows AS $row) {
      $visitor['visits']['_totals']['entrance']['events'] = array(
        '_totals' => array(
          'value' => $row['eventValue'],
          'totalValuedEvents' => $row['totalEvents'],
          'uniqueValuedEvents' => $row['uniqueEvents'],
        ),
      );
    }
  }
  $request['filters'] = '';
  $request['dimensions'] = array('ga:dimension5', 'ga:visitCount', 'ga:medium', 'ga:source', 'ga:referralPath', 'ga:keyword', 'ga:dimension4');
  $request['metrics'] = array('ga:entrances');
  $request['sort_metric'] = '-ga:dimension4';  // note: cant sort by visitCount as it is treated as a string not an int
  $request['max_results'] = 10;

  $data = intel_ga_api_data($request, $cache);
//dsm($request); dsm($data);
  $visitCountMin = 0;
  $visitCountMax = 0;
  $tsMin = REQUEST_TIME;
  $rows = intel_get_ga_feed_rows($data);
  if (!empty($rows) && is_array($rows)) {
    foreach ($rows AS $row) {
      /*
      $visitCountMin = $i = (int)$row['visitCount'];
      if (!$visitCountMax) {
        $visitCountMax = $i;
      }
      */
      $i = $row['dimension5'] . '-' . $row['visitCount'];
      $visitor['visits'][$i] = array(
        'trafficsource' => array(),
      );
      $visitor['visits'][$i]['visitCount'] = $row['visitCount'];
      $visitor['visits'][$i]['time'] = $vts =  (int)$row['dimension4'];
      $visitor['visits'][$i]['trafficsource']['medium'] = $row['medium'];
      $visitor['visits'][$i]['trafficsource']['source'] = $row['source'];
      $visitor['visits'][$i]['trafficsource']['referralPath'] = $row['referralPath'];
      $visitor['visits'][$i]['trafficsource']['keyword'] = $row['keyword'];

      //$visitor['visits'][$i]['trafficsource']['socialNetwork'] = $row['socialNetwork'];
      //$visitor['visits'][$ts]['trafficsource']['campaign'] = $row['campaign'];
      if ($vts < $tsMin) {
        $tsMin = $vts;
      }
    }
  }
  $request['dimensions'] = array('ga:dimension5', 'ga:visitCount', 'ga:socialNetwork', 'ga:campaign');
  $request['metrics'] = array('ga:pageviews', 'ga:bounces', 'ga:timeOnSite', 'ga:goalValueAll');
  $request['sort_metric'] = '';
  $request['filters'] = LevelTen\Intel\GAModel::formatGtRegexFilter('ga:dimension4', ($tsMin-1));
  //$visitCountFilter = ($visitCountMin > 1) ? LevelTen\Intel\GAModel::formatGtRegexFilter('ga:visitCount', ($visitCountMin-1)) : '';
  //$request['filters'] = $visitCountFilter;

  $data = intel_ga_api_data($request, $cache);

  $rows = intel_get_ga_feed_rows($data);
  if (!empty($rows) && is_array($rows)) {
    foreach ($rows AS $row) {
      //$i = (int)$row['visitCount'];
      $i = $row['dimension5'] . '-' . $row['visitCount'];
      $visitor['visits'][$i]['entrance'] = array();
      $visitor['visits'][$i]['entrance']['entrances'] = 1;
      $visitor['visits'][$i]['entrance']['pageviews'] = $row['pageviews'];
      $visitor['visits'][$i]['entrance']['sticks'] = (1 - $row['bounces']);
      $visitor['visits'][$i]['entrance']['timeOnSite'] = $row['timeOnSite'];
      $visitor['visits'][$i]['entrance']['goalValueAll'] = $row['goalValueAll'];
      $visitor['visits'][$i]['trafficsource']['socialNetwork'] = $row['socialNetwork'];
      $visitor['visits'][$i]['trafficsource']['campaign'] = $row['campaign'];

      $visitor['visits']['_all']['entrance']['entrances'] ++;
      $visitor['visits']['_all']['entrance']['pageviews'] += $row['pageviews'];
      $visitor['visits']['_all']['entrance']['timeOnSite'] += $row['timeOnSite'];
    }
  }
  $visitor['visits']['_all']['visitCount'] = $visitCountMax;

  // get valued events
  $request['dimensions'] = array('ga:dimension5', 'ga:visitCount');
  $request['metrics'] = array('ga:totalEvents', 'ga:uniqueEvents', 'ga:eventValue');
  $request['filters'] = 'ga:eventCategory=~^*!$' . ';' . LevelTen\Intel\GAModel::formatGtRegexFilter('ga:dimension4', ($tsMin-1));

  $data = intel_ga_api_data($request, $cache);
  //dsm($request); dsm($data);
  $rows = intel_get_ga_feed_rows($data);
  if (!empty($rows) && is_array($rows)) {
    foreach ($rows AS $row) {
      //$i = (int)$row['visitCount'];
      $i = $row['dimension5'] . '-' . $row['visitCount'];
      $visitor['visits'][$i]['entrance']['events'] = array(
        '_all' => array(
          'value' => $row['eventValue'],
          'totalValuedEvents' => $row['totalEvents'],
          'uniqueValuedEvents' => $row['uniqueEvents'],
        ),
      );
    }
  }
  $score_components = '';
  $score = 0;
  foreach ($visitor['visits'] AS $index => $visit) {
    if (substr($index, 0, 1) == '_') {
      continue;
    }
    //$visitor['visits'][$index]['score'] = intel_score_visit_aggregation($visitor['visits'][$index], 1, $score_components);
    $visitor['visits'][$index]['score'] = intel_score_item($visitor['visits'][$index], 1, $score_components, '', 'entrance');
    $visitor['visits']['_all']['score'] += $visitor['visits'][$index]['score'];
  }
  $visitor['visits']['_totals']['score'] = intel_score_item($visitor['visits']['_totals'], 1, $score_components, '', 'entrance');

  if ($visitor['lasthit']) {
    return $visitor;
  }
  else {
    return FALSE;
  }
}

/**
 * Selects data rows based on if feed is ver 2 or ver 3
 * @param $feed
 * @return array
 */
function intel_get_ga_feed_rows($feed) {
  $rows = is_array($feed->results) ? $feed->results : $feed->results->rows;
  return $rows;
}