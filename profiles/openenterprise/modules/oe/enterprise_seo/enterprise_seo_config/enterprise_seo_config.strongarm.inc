<?php
/**
 * @file
 * enterprise_seo.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_seo_config_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kwresearch_keyword_sync_vocabulary';
  $strongarm->value = 'keywords';
  $export['kwresearch_keyword_sync_vocabulary'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kwresearch_keyword_tag_vocabulary';
  $strongarm->value = '0';
  $export['kwresearch_keyword_tag_vocabulary'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kwresearch_report_vocabulary';
  $strongarm->value = array(
    'blog_categories' => 0,
    'blog_tags' => 0,
    'cta_categories' => 0,
    'enterprise_slideshow_classes' => 0,
    'keywords' => 0,
    'services' => 0,
    'tags' => 0,
  );
  $export['kwresearch_report_vocabulary'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kwresearch_site_report_data_options';
  $strongarm->value = array(
    'daily_volume' => 'daily_volume',
    'competition' => 'competition',
    'bid' => 0,
    'google_dailyest' => 0,
    'yahoo_dailyest' => 0,
    'bing_dailyest' => 0,
  );
  $export['kwresearch_site_report_data_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kwresearch_stats_report_data_options';
  $strongarm->value = array(
    'site_priority' => 'site_priority',
    'site_value' => 'site_value',
    'total_dailyest' => 'total_dailyest',
    'competition' => 'competition',
    'bid' => 0,
    'google_dailyest' => 0,
    'yahoo_dailyest' => 0,
    'bing_dailyest' => 0,
    'google_searches' => 0,
    'google_competition' => 0,
    'google_bid' => 0,
  );
  $export['kwresearch_stats_report_data_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kwresearch_stats_report_item_limit';
  $strongarm->value = '50';
  $export['kwresearch_stats_report_item_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'kwresearch_stats_report_links_options';
  $strongarm->value = array(
    'google_trends' => 'google_trends',
    'google_insights' => 'google_insights',
    'gorank_related' => 'gorank_related',
    'keyworddiscovery' => 'keyworddiscovery',
  );
  $export['kwresearch_stats_report_links_options'] = $strongarm;

  return $export;
}
