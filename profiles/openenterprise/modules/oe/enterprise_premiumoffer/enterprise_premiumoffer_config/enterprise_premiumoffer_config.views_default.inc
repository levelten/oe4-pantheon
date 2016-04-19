<?php
/**
 * @file
 * enterprise_premiumoffer.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enterprise_premiumoffer_config_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enterprise_premiumoffer_blocks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Premium Offer Blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related Offers';
  $handler->display->display_options['use_more_always'] = FALSE;
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
  /* Field: Relevant: By Terms */
  $handler->display->display_options['fields']['terms']['id'] = 'terms';
  $handler->display->display_options['fields']['terms']['table'] = 'enterprise_rel';
  $handler->display->display_options['fields']['terms']['field'] = 'terms';
  $handler->display->display_options['fields']['terms']['count_type'] = '1';
  /* Field: Similar Entries: Similarity score */
  $handler->display->display_options['fields']['similarity']['id'] = 'similarity';
  $handler->display->display_options['fields']['similarity']['table'] = 'similar_entries';
  $handler->display->display_options['fields']['similarity']['field'] = 'similarity';
  $handler->display->display_options['fields']['similarity']['score_type'] = '1';
  $handler->display->display_options['fields']['similarity']['round_decimal'] = '0';
  $handler->display->display_options['fields']['similarity']['multiply_score'] = '1';
  /* Sort criterion: Relevant: By Terms */
  $handler->display->display_options['sorts']['terms']['id'] = 'terms';
  $handler->display->display_options['sorts']['terms']['table'] = 'enterprise_rel';
  $handler->display->display_options['sorts']['terms']['field'] = 'terms';
  /* Sort criterion: Similar Entries: Similarity score */
  $handler->display->display_options['sorts']['similarity']['id'] = 'similarity';
  $handler->display->display_options['sorts']['similarity']['table'] = 'similar_entries';
  $handler->display->display_options['sorts']['similarity']['field'] = 'similarity';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Contextual filter: Relevant: By Terms */
  $handler->display->display_options['arguments']['rel_tid']['id'] = 'rel_tid';
  $handler->display->display_options['arguments']['rel_tid']['table'] = 'enterprise_rel';
  $handler->display->display_options['arguments']['rel_tid']['field'] = 'rel_tid';
  $handler->display->display_options['arguments']['rel_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['rel_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['rel_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['rel_tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['rel_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['rel_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['rel_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Relevant: By Text Index */
  $handler->display->display_options['arguments']['rel_text_index']['id'] = 'rel_text_index';
  $handler->display->display_options['arguments']['rel_text_index']['table'] = 'enterprise_rel';
  $handler->display->display_options['arguments']['rel_text_index']['field'] = 'rel_text_index';
  $handler->display->display_options['arguments']['rel_text_index']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['rel_text_index']['validate']['fail'] = 'access denied';
  $handler->display->display_options['arguments']['rel_text_index']['title_relevance'] = '1.4';
  $handler->display->display_options['arguments']['rel_text_index']['body_relevance'] = '0.8';
  $handler->display->display_options['arguments']['rel_text_index']['included_fields:field_data_field_file_image_alt_text'] = '0';
  $handler->display->display_options['arguments']['rel_text_index']['included_fields:field_data_field_file_image_title_text'] = '0';
  $handler->display->display_options['arguments']['rel_text_index']['included_fields:field_data_field_firstname'] = '0';
  $handler->display->display_options['arguments']['rel_text_index']['included_fields:field_data_field_lastname'] = '0';
  $handler->display->display_options['arguments']['rel_text_index']['included_fields:field_data_field_intel_event_value'] = '0';
  $handler->display->display_options['arguments']['rel_text_index']['included_fields:field_data_field_page_attribute_value'] = '0';
  $handler->display->display_options['arguments']['rel_text_index']['included_fields:field_data_field_track_submission_value'] = '0';
  $handler->display->display_options['arguments']['rel_text_index']['included_fields:field_data_field_visitor_attribute_value'] = '0';
  $handler->display->display_options['arguments']['rel_text_index']['included_fields:field_data_field_title'] = '0';
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
    'enterprise_premiumoffer' => 'enterprise_premiumoffer',
  );

  /* Display: Related CTA (sidebar) */
  $handler = $view->new_display('block', 'Related CTA (sidebar)', 'rel_cta_sidebar');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'conversion_cta_sidebar';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'enterprise_rel|terms';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'conversion_cta_sidebar';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_rel'] = '';
  /* Field: Content: Default sidebar CTA */
  $handler->display->display_options['fields']['field_premiumoffer_cta_sidebar']['id'] = 'field_premiumoffer_cta_sidebar';
  $handler->display->display_options['fields']['field_premiumoffer_cta_sidebar']['table'] = 'field_data_field_premiumoffer_cta_sidebar';
  $handler->display->display_options['fields']['field_premiumoffer_cta_sidebar']['field'] = 'field_premiumoffer_cta_sidebar';
  $handler->display->display_options['fields']['field_premiumoffer_cta_sidebar']['label'] = '';
  $handler->display->display_options['fields']['field_premiumoffer_cta_sidebar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_premiumoffer_cta_sidebar']['empty'] = '<div class="messages warning">Default Sidebar CTA not set for offer. <a href="/node/[nid]/edit">Edit here</a>.</div>';
  $handler->display->display_options['fields']['field_premiumoffer_cta_sidebar']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_premiumoffer_cta_sidebar']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_premiumoffer_cta_sidebar']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
    'field_formatter_class' => '',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['block_description'] = 'Premium Offer: Relevant CTA (sidebar)';
  $handler->display->display_options['block_caching'] = '-1';

  /* Display: Related CTA (footer) */
  $handler = $view->new_display('block', 'Related CTA (footer)', 'rel_cta_footer');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'conversion_cta_footer';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'enterprise_rel|terms';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'conversion_cta_footer';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_rel'] = '';
  /* Field: Content: Default footer CTA */
  $handler->display->display_options['fields']['field_premiumoffer_cta_footer']['id'] = 'field_premiumoffer_cta_footer';
  $handler->display->display_options['fields']['field_premiumoffer_cta_footer']['table'] = 'field_data_field_premiumoffer_cta_footer';
  $handler->display->display_options['fields']['field_premiumoffer_cta_footer']['field'] = 'field_premiumoffer_cta_footer';
  $handler->display->display_options['fields']['field_premiumoffer_cta_footer']['label'] = '';
  $handler->display->display_options['fields']['field_premiumoffer_cta_footer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_premiumoffer_cta_footer']['empty'] = '<div class="messages warning">Default Footer CTA not set for offer. <a href="/node/[nid]/edit">Edit here</a>.</div>';
  $handler->display->display_options['fields']['field_premiumoffer_cta_footer']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_premiumoffer_cta_footer']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_premiumoffer_cta_footer']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
    'field_formatter_class' => '',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['block_description'] = 'Premium Offer: Relevant CTA (footer)';
  $handler->display->display_options['block_caching'] = '4';
  $export['enterprise_premiumoffer_blocks'] = $view;

  $view = new view();
  $view->name = 'enterprise_premiumoffer_cta';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bean';
  $view->human_name = 'Premium Offer CTA';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CTAs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'default';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Field: Block: Internal, numeric block ID */
  $handler->display->display_options['fields']['bid']['id'] = 'bid';
  $handler->display->display_options['fields']['bid']['table'] = 'bean';
  $handler->display->display_options['fields']['bid']['field'] = 'bid';
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cta' => 'cta',
  );

  /* Display: Entity Reference (sidebar) */
  $handler = $view->new_display('entityreference', 'Entity Reference (sidebar)', 'entityref_sidebar');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'bid' => 'bid',
    'label' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'bid' => 'bid',
    'label' => 'label',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['id'] = 'field_premiumoffer_target_id';
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['table'] = 'field_data_field_premiumoffer';
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['field'] = 'field_premiumoffer_target_id';
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['label'] = 'Premium offer';
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Block: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'bean';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Block: Internal, numeric block ID */
  $handler->display->display_options['fields']['bid']['id'] = 'bid';
  $handler->display->display_options['fields']['bid']['table'] = 'bean';
  $handler->display->display_options['fields']['bid']['field'] = 'bid';
  $handler->display->display_options['fields']['bid']['label'] = '';
  $handler->display->display_options['fields']['bid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_premiumoffer_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cta' => 'cta',
  );
  /* Filter criterion: CTA Selector: Selector */
  $handler->display->display_options['filters']['selector']['id'] = 'selector';
  $handler->display->display_options['filters']['selector']['table'] = 'cta_bean_selector';
  $handler->display->display_options['filters']['selector']['field'] = 'selector';
  $handler->display->display_options['filters']['selector']['value'] = array(
    'cta_sidebar' => 'cta_sidebar',
  );

  /* Display: Entity Reference (footer) */
  $handler = $view->new_display('entityreference', 'Entity Reference (footer)', 'entityref_footer');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'bid' => 'bid',
    'label' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'bid' => 'bid',
    'label' => 'label',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['id'] = 'field_premiumoffer_target_id';
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['table'] = 'field_data_field_premiumoffer';
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['field'] = 'field_premiumoffer_target_id';
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['label'] = 'Premium offer';
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Block: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'bean';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Block: Internal, numeric block ID */
  $handler->display->display_options['fields']['bid']['id'] = 'bid';
  $handler->display->display_options['fields']['bid']['table'] = 'bean';
  $handler->display->display_options['fields']['bid']['field'] = 'bid';
  $handler->display->display_options['fields']['bid']['label'] = '';
  $handler->display->display_options['fields']['bid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_premiumoffer_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cta' => 'cta',
  );
  /* Filter criterion: CTA Selector: Selector */
  $handler->display->display_options['filters']['selector']['id'] = 'selector';
  $handler->display->display_options['filters']['selector']['table'] = 'cta_bean_selector';
  $handler->display->display_options['filters']['selector']['field'] = 'selector';
  $handler->display->display_options['filters']['selector']['value'] = array(
    'cta_footer' => 'cta_footer',
  );

  /* Display: Random CTA (sidebar) */
  $handler = $view->new_display('panel_pane', 'Random CTA (sidebar)', 'pane_sidebar');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No sidebar CTAs have been set for this premium offer.
!1
%1';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['id'] = 'field_premiumoffer_target_id';
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['table'] = 'field_data_field_premiumoffer';
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['field'] = 'field_premiumoffer_target_id';
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['label'] = 'Premium offer';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_premiumoffer_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cta' => 'cta',
  );
  /* Filter criterion: CTA Selector: Selector */
  $handler->display->display_options['filters']['selector']['id'] = 'selector';
  $handler->display->display_options['filters']['selector']['table'] = 'cta_bean_selector';
  $handler->display->display_options['filters']['selector']['field'] = 'selector';
  $handler->display->display_options['filters']['selector']['value'] = array(
    'cta_sidebar' => 'cta_sidebar',
  );
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Random CTA (footer) */
  $handler = $view->new_display('panel_pane', 'Random CTA (footer)', 'pane_footer');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['id'] = 'field_premiumoffer_target_id';
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['table'] = 'field_data_field_premiumoffer';
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['field'] = 'field_premiumoffer_target_id';
  $handler->display->display_options['relationships']['field_premiumoffer_target_id']['label'] = 'Premium offer';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_premiumoffer_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cta' => 'cta',
  );
  /* Filter criterion: CTA Selector: Selector */
  $handler->display->display_options['filters']['selector']['id'] = 'selector';
  $handler->display->display_options['filters']['selector']['table'] = 'cta_bean_selector';
  $handler->display->display_options['filters']['selector']['field'] = 'selector';
  $handler->display->display_options['filters']['selector']['value'] = array(
    'cta_footer' => 'cta_footer',
  );
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['enterprise_premiumoffer_cta'] = $view;

  return $export;
}
