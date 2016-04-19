<?php
/**
 * @file
 * enterprise_conversion_content.deploy_plans.inc
 */

/**
 * Implements hook_deploy_plans_default().
 */
function enterprise_conversion_content_deploy_plans_default() {
  $export = array();

  $plan = new DeployPlan();
  $plan->disabled = FALSE; /* Edit this to true to make a default plan disabled initially */
  $plan->api_version = 1;
  $plan->name = 'enterprise_conversion_content';
  $plan->title = 'Enterprise Landing Pages Content';
  $plan->description = 'Demo CTAs, landing pages, webforms and thank you pages for Enterprise Landing pages';
  $plan->debug = 0;
  $plan->aggregator_plugin = 'DeployAggregatorManaged';
  $plan->aggregator_config = array(
    'delete_post_deploy' => 0,
  );
  $plan->fetch_only = 1;
  $plan->processor_plugin = '';
  $plan->processor_config = array();
  $plan->endpoints = array();
  $export['enterprise_conversion_content'] = $plan;

  return $export;
}
