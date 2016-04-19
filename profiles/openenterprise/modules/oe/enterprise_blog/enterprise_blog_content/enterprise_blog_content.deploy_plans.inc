<?php
/**
 * @file
 * enterprise_blog_content.deploy_plans.inc
 */

/**
 * Implements hook_deploy_plans_default().
 */
function enterprise_blog_content_deploy_plans_default() {
  $export = array();

  $plan = new DeployPlan();
  $plan->disabled = FALSE; /* Edit this to true to make a default plan disabled initially */
  $plan->api_version = 1;
  $plan->name = 'enterprise_blog_content';
  $plan->title = 'Enterprise Blog Content';
  $plan->description = 'Demo content for Enterprise Blog';
  $plan->debug = 0;
  $plan->aggregator_plugin = 'DeployAggregatorManaged';
  $plan->aggregator_config = array(
    'delete_post_deploy' => 0,
  );
  $plan->fetch_only = 1;
  $plan->processor_plugin = '';
  $plan->processor_config = array();
  $plan->endpoints = array();
  $export['enterprise_blog_content'] = $plan;

  return $export;
}
