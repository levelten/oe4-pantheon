<?php
/**
 * @file
 * enterprise_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enterprise_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enterprise_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Enterprise Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'see all events';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date/Time */
  $handler->display->display_options['fields']['field_event_datetime']['id'] = 'field_event_datetime';
  $handler->display->display_options['fields']['field_event_datetime']['table'] = 'field_data_field_event_datetime';
  $handler->display->display_options['fields']['field_event_datetime']['field'] = 'field_event_datetime';
  /* Sort criterion: Content: Date/Time -  start date (field_event_datetime) */
  $handler->display->display_options['sorts']['field_event_datetime_value']['id'] = 'field_event_datetime_value';
  $handler->display->display_options['sorts']['field_event_datetime_value']['table'] = 'field_data_field_event_datetime';
  $handler->display->display_options['sorts']['field_event_datetime_value']['field'] = 'field_event_datetime_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'enterprise_event' => 'enterprise_event',
  );
  /* Filter criterion: Content: Date/Time -  start date (field_event_datetime) */
  $handler->display->display_options['filters']['field_event_datetime_value']['id'] = 'field_event_datetime_value';
  $handler->display->display_options['filters']['field_event_datetime_value']['table'] = 'field_data_field_event_datetime';
  $handler->display->display_options['filters']['field_event_datetime_value']['field'] = 'field_event_datetime_value';
  $handler->display->display_options['filters']['field_event_datetime_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_datetime_value']['default_date'] = 'now';

  /* Display: Events */
  $handler = $view->new_display('block', 'Events', 'events');
  $handler->display->display_options['block_description'] = 'Events';

  /* Display: Upcoming Events */
  $handler = $view->new_display('block', 'Upcoming Events', 'upcoming_events');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'upcoming_events';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_field_event_datetime|field_event_datetime_value';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'upcoming_events';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/resources/event" class="more-link pull-right">see all events</a>';
  $handler->display->display_options['footer']['area']['format'] = 'raw_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date/Time */
  $handler->display->display_options['fields']['field_event_datetime']['id'] = 'field_event_datetime';
  $handler->display->display_options['fields']['field_event_datetime']['table'] = 'field_data_field_event_datetime';
  $handler->display->display_options['fields']['field_event_datetime']['field'] = 'field_event_datetime';
  $handler->display->display_options['fields']['field_event_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_event_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_datetime']['settings'] = array(
    'format_type' => 'day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'field_formatter_class' => '',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['block_description'] = 'Upcoming Events';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'date_ical';
  $handler->display->display_options['row_plugin'] = 'date_ical';
  $handler->display->display_options['row_options']['date_field'] = 'field_data_field_event_datetime.field_event_datetime_value';
  $handler->display->display_options['row_options']['location_field'] = 'none';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'node/%/ical.ics';
  $handler->display->display_options['sitename_title'] = 0;
  $export['enterprise_events'] = $view;

  return $export;
}
