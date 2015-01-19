<?php
/**
 * @file
 * enterprise_video_content.deploy_plans.inc
 */

/**
 * Implements hook_deploy_plans_default().
 */
function enterprise_video_content_deploy_plans_default() {
  $export = array();

  $plan = new DeployPlan();
  $plan->disabled = FALSE; /* Edit this to true to make a default plan disabled initially */
  $plan->api_version = 1;
  $plan->name = 'enterprise_video_content';
  $plan->title = 'Enterprise video content';
  $plan->description = '';
  $plan->debug = 0;
  $plan->aggregator_plugin = 'DeployAggregatorManaged';
  $plan->aggregator_config = array(
    'delete_post_deploy' => 0,
  );
  $plan->fetch_only = 1;
  $plan->processor_plugin = '';
  $plan->processor_config = array();
  $plan->endpoints = array();
  $export['enterprise_video_content'] = $plan;

  return $export;
}
