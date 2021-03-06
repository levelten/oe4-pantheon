<?php

/**
 * @file
 * Provides Drush integration for Deploy.
 */

/**
 * Implements hook_drush_command().
 */
function deploy_drush_command() {
  $commands = array();

  $commands['deploy-plan'] = array(
    'description' => 'Deploy all content from a plan to all its endpoints.',
    'drupal dependencies' => array('deploy'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'plan' => 'The plan to deploy.'
    ),
    'examples' => array(
      'drush deploy my_plan' => 'Deploy all content from "my_plan" to all its endpoints.',
    ),
    'aliases' => array('deploy', 'dp'),
  );

  $commands['deploy-create-plan'] = array(
    'description' => 'Create a new deployment plan.',
    'drupal dependencies' => array('deploy'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'plan_name' => 'The name of the deployment plan to create.'
    ),
    'required-arguments' => TRUE,
    'options' => array(
      'endpoint' => array(
        'description' => 'The name of the endpoint to deploy to.',
        'example-value' => 'my_endpoint',
        'value' => 'required',
        'required' => TRUE,
      ),
      'aggregator' => array(
        'description' => 'The name of the aggregator plugin to use for the plan.',
        'example-value' => 'DeployAggregatorManaged',
        'value' => 'required',
      ),
      'delete' => array(
        'description' => 'Delete items in the plan after deployment.  Default is 0 (off).',
        'example-value' => '1',
        'value' => 'required',
      ),
      'debug-plan' => array(
        'description' => 'Enable debugging for the plan.  Default is 1 (on).',
        'example-value' => '0',
        'value' => 'required',
      ),
      'overwrite' => array(
        'description' => 'Overwrite the configuration of an existing plan.  Default is 0 (off).',
        'example-value' => '1',
        'value' => 'required',
      ),
    ),
    'examples' => array(
      'drush deploy-create-plan plan_name --endpoint="endpoint-name"' => 'Create a new plan called "plan_name" with the endpoint "endpoint-name".',
    ),
    'aliases' => array('create-plan', 'dcp'),
  );

  $commands['deploy-delete-plan'] = array(
    'description' => 'Delete a new deployment plan.',
    'drupal dependencies' => array('deploy'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'plan_name' => 'The name of the deployment plan to delete.'
    ),
    'required-arguments' => TRUE,
    'examples' => array(
      'drush deploy-delete-plan plan_name' => 'Deletes plan called "plan_name".',
    ),
    'aliases' => array('delete-plan', 'ddp'),
  );

  return $commands;
}

/**
 * Implements hook_drush_help().
 */
function deploy_drush_help($section) {
  switch ($section) {
    case 'drush:deploy-plan':
      return dt('Deploy all content from a plan to all its endpoints.');
  }
}

/**
 * Command callback for deploying plans.
 */
function drush_deploy_plan($name) {
  if ($plan = deploy_plan_load($name)) {
    $plan->deploy();
    return;
  }
  drush_set_error(dt('Cannot deploy non-existent plan @name'), array('@name' => $name));
}

/**
 * Command callback for creating plans.
 */
function drush_deploy_create_plan($name) {
  $endpoints = deploy_endpoint_load_all();
  if (!count($endpoints)) {
    return drush_set_error(dt("No endpoints configured"));
  }

  $endpoint = drush_get_option('endpoint');
  if (!$endpoint || !isset($endpoints[$endpoint])) {
    return drush_set_error(dt('Invalid endpoint: @endpoint.', array('@endpoint' => $endpoint)));
  }
  unset($endpoints);

  $aggregator = drush_get_option('aggregator', 'DeployAggregatorManaged');
  $aggregators = deploy_get_aggregator_plugins();
  if (!isset($aggregators[$aggregator])) {
    return drush_set_error(dt('Invalid aggregator: @aggregator.', array('@aggregator' => $aggregator)));
  }
  unset($aggregators);

  $delete = (bool) drush_get_option('delete', 0);
  $debug = (bool) drush_get_option('debug-plan', 1);

  $plan = deploy_plan_load($name);
  if (FALSE !== $plan) {
    if (!((bool) drush_get_option('overwrite', 0))) {
      return drush_set_error(dt('Plan @name already exists. Use --overwrite=1 to overwite the configuration for the plan.', array('@name' => $name)));
    }

    $plan->debug = $debug;
    $plan->endpoints = array($endpoint => $endpoint);
    if ('DeployAggregatorManaged' == $aggregator) {
      $plan->aggregator_config = array('delete_post_deploy' => $delete);
    }
    $plan = deploy_plan_save($plan);

    drush_print(dt('Updated plan @name(@pid).', array('@name' => $name, '@pid' => $plan->pid)));
    drush_print_pipe($plan->pid);
    return TRUE;
  }

  $plan = (object) array(
    'pid' => NULL,
    'name' => $name,
    'title' => dt('@name plan', array('@name' => $name)),
    'description' => dt('@name plan', array('@name' => $name)),
    'debug' => $debug,
    'aggregator_plugin' => $aggregator,
    'aggregator_config' => array(
      'delete_post_deploy' => $delete
    ),
    'processor_plugin' => 'DeployProcessorMemory',
    'endpoints' => array(
      $endpoint => $endpoint,
    ),
    'fetch_only' => 0,
    'table' => 'deploy_plans',
    'type' => 'Normal',
  );

  $plan = deploy_plan_save($plan);

  drush_print(dt('Created new plan @pid.', array('@pid' => $plan->pid)));
  drush_print_pipe($plan->pid);
}

/**
 * Command callback for deleting a deployment plan.
 */
function drush_deploy_delete_plan($name) {

  $plan = deploy_plan_load($name);
  if (FALSE === $plan) {
    // We don't care if the plan doesn't exist. The user just wants it removed.
    drush_print(dt("Plan '@name' doesn't exist.", array('@name' => $name)));
    return DRUSH_SUCCESS;
  }

  // Cast to ensure proper bitwise evaluation.
  $plan->export_type = (int) $plan->export_type;

  if (EXPORT_IN_DATABASE !== ($plan->export_type & EXPORT_IN_DATABASE)) {
    return drush_set_error(dt("Plan '@name' only exists in code. This plan can't be deleted.", array('@name' => $name)));
  }

  $confirm_message = dt("Are you sure you want to delete plan named '@name'?", array('@name' => $name));
  $exported = FALSE;

  if (EXPORT_IN_CODE === ($plan->export_type & EXPORT_IN_CODE)) {
    $exported = TRUE;
    $confirm_message = dt("Plan '@name' is exported to code. Do you want to revert this plan to the exported configuration?", array('@name' => $name));
  }

  if (!drush_confirm($confirm_message)) {
    drush_user_abort();
  }

  ctools_export_crud_delete('deploy_plans', $name);

  if ($exported) {
    drush_print(dt("Reverted plan '@name'.", array('@name' => $name)));
  }
  else {
    drush_print(dt("Deleted plan '@name'.", array('@name' => $name)));
  }
}
