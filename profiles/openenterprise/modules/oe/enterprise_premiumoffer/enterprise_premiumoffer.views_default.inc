<?php
/**
 * @file
 * enterprise_premiumoffer.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enterprise_premiumoffer_views_default_views() {
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

  /* Display: Related */
  $handler = $view->new_display('block', 'Related', 'related');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_caching'] = '4';

  /* Display: Related Test */
  $handler = $view->new_display('block', 'Related Test', 'related_test');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
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
  /* Field: Content: Sticky */
  $handler->display->display_options['fields']['sticky']['id'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['table'] = 'node';
  $handler->display->display_options['fields']['sticky']['field'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['not'] = 0;

  /* Display: Related CTA (sidebar) */
  $handler = $view->new_display('block', 'Related CTA (sidebar)', 'related_cta_sidebar');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
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
  /* Field: Content: Sidebar CTA */
  $handler->display->display_options['fields']['field_cta_sidebar']['id'] = 'field_cta_sidebar';
  $handler->display->display_options['fields']['field_cta_sidebar']['table'] = 'field_data_field_cta_sidebar';
  $handler->display->display_options['fields']['field_cta_sidebar']['field'] = 'field_cta_sidebar';
  $handler->display->display_options['fields']['field_cta_sidebar']['label'] = '';
  $handler->display->display_options['fields']['field_cta_sidebar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cta_sidebar']['empty'] = '<div class="messages warning">Default Sidebar CTA not set for offer. <a href="/node/[nid]/edit">Edit here</a>.</div>';
  $handler->display->display_options['fields']['field_cta_sidebar']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cta_sidebar']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_cta_sidebar']['settings'] = array(
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
  $handler = $view->new_display('block', 'Related CTA (footer)', 'related_cta_footer');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
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
  /* Field: Content: Footer CTA */
  $handler->display->display_options['fields']['field_cta_footer']['id'] = 'field_cta_footer';
  $handler->display->display_options['fields']['field_cta_footer']['table'] = 'field_data_field_cta_footer';
  $handler->display->display_options['fields']['field_cta_footer']['field'] = 'field_cta_footer';
  $handler->display->display_options['fields']['field_cta_footer']['label'] = '';
  $handler->display->display_options['fields']['field_cta_footer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cta_footer']['empty'] = '<div class="messages warning">Default Footer CTA not set for offer. <a href="/node/[nid]/edit">Edit here</a>.</div>';
  $handler->display->display_options['fields']['field_cta_footer']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cta_footer']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_cta_footer']['settings'] = array(
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

  return $export;
}
