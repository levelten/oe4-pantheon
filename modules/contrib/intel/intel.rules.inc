<?php
/**
 * @file
 * Rules module integration
 */

/**
 * Implements hook_event_info().
 */
function intel_rules_event_info() {
  $defaults = array(
    'group' => t('Intel'),
    'module' => 'intel',
  );
  return array(
    'intel_form_submission' => $defaults + array(
      'label' => t('Form submission received'),
      'variables' => array(
        'type' => array(
          'type' => 'text',
          'label' => t('Form type'),
        ),
        'fid' => array(
          'type' => 'text',
          'label' => t('Form id'),
        ),
        'visitor' => array(
          'type' => 'intel_visitor',
          'label' => t('Visitor'),
          //'save' => TRUE,
        ),
      ),
      //'access callback' => 'rules_node_integration_access',
      'class' => 'RulesEventHandlerIntelFormSubmission',
    ),
    'intel_phone_call' => $defaults + array(
      'label' => t('Phone call received'),
      'variables' => array(
        'type' => array(
          'type' => 'text',
          'label' => t('Call type'),
        ),
        'number' => array(
          'type' => 'text',
          'label' => t('Number called'),
        ),
        'visitor' => array(
          'type' => 'intel_visitor',
          'label' => t('Visitor'),
          //'save' => TRUE,
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_condition_info().
 */
function intel_rules_condition_info() {
  return array(
    'intel_rules_condition_number_belongs_to_user' => array(
      'label' => t('Number belongs to a valid user'),
      'arguments' => array(
        'number' => array(
          'type' => 'text',
          'label' => t('Phone Number'),
        ),
      ),
      'group' => t('Intel'),
      'module' => 'intel',
    ),
  );
}

/**
 * Implements hook_rules_action_info().
 */
function intel_rules_action_info() {
  $defaults = array(
    'group' => t('Intel'),
    'module' => 'intel',
  );

  $actions['intel_rules_action_trigger_intel_event'] = $defaults + array(
    'label' => t('Trigger Intel event'),
    //'base' => 'intel_trigger_intel_event',
    'parameter' => array(
      'event_name' => array(
        'type' => 'text',
        'label' => t('Event'),
        'options list' => 'intel_rules_event_option_list',
      ),
      'value' => array(
        'type' => 'integer',
        'label' => t('Value'),
        'optional' => TRUE,
      ),
    ),
  );

  $actions['intel_send_sms_to_user'] = $defaults + array(
    'label' => t('Send an SMS to a user'),
    'base' => 'intel_rules_action_send_sms_to_user',
    'parameter' => array(
      'account' => array(
        'type' => 'user',
        'label' => t('User'),
        'save' => TRUE,
      ),
      'message' => array(
        'type' => 'text',
        'label' => t('Message'),
      ),
    ),
  );
  $actions['intel_twiml_output'] = $defaults + array(
    'label' => t('Output TwiML'),
    'base' => 'intel_rules_twiml_output',
    'parameter' => array(
      'twiml_id' => array(
        'type' => 'text',
        'label' => t('TwiML'),
        'options list' => 'intel_twiml_options_list',
        'restriction' => 'input',
      ),
    ),
  );
  $actions['intel_send_sms_to_number'] = $defaults + array(
    'label' => t('Send an SMS to a number'),
    'base' => 'intel_rules_action_send_sms_to_number',
    'parameter' => array(
      'country' => array(
        'type' => 'text',
        'label' => t('Country code'),
        'options list' => 'intel_country_codes',
      ),
      'number' => array(
        'type' => 'text',
        'label' => t('Number'),
      ),
      'message' => array(
        'type' => 'text',
        'label' => t('Message'),
      ),
    ),
  );



  return $actions;
}

function intel_rules_event_option_list() {
  $events = intel_get_intel_events(TRUE);
  $values = array();

  foreach ($events AS $key => $va) {
    if (empty($va['selectable'])) {
      //continue;
    }
    $values[$key] = $va['title'];
  }
  return $values;
}

function intel_rules_action_trigger_intel_event($event_name, $value) {
  intel_trigger_intel_event_by_name($event_name, array('value' => $value));
}



/**
 * Action: Send an SMS to a user.
 */
function intel_rules_action_send_sms_to_visitor($visitor, $message) {
  if (!empty($visitor->phone)) {
    intel_send($visitor->phone, $message);
  }
}

/**
 * Action: Send an SMS to a number.
 */
function intel_rules_action_send_sms_to_number($country, $number, $message) {
  intel_send($number, $message, $country);
}

/**
 * Condition: Validate if a number belongs to a user on the site.
 */
function intel_rules_condition_number_belongs_to_user($number) {
  return intel_verify_number($number);
}

/**
 * Action: Output TwiML.
 */
function intel_rules_twiml_output($twiml_id) {
  $twiml = intel_twiml_load($twiml_id);
  echo $twiml['data'];
  exit();
}

/**
 * Exposes the form submission data as event setting.
 */
class RulesEventHandlerIntelFormSubmission extends RulesEventHandlerBase {

  protected $entityType, $entityInfo, $bundleKey;

  /**
   * Implements RulesEventHandlerInterface::__construct()
   */
  public function __construct($event_name, $info) {
    parent::__construct($event_name, $info);
    dsm($this);
  }

  /**
   * Implements RulesEventHandlerInterface::summary()
   */
  public function summary() {
    $bundle = &$this->settings['bundle'];
    $bundle_label = isset($this->entityInfo['bundles'][$bundle]['label']) ? $this->entityInfo['bundles'][$bundle]['label'] : $bundle;
    $suffix = isset($bundle) ? ' ' . t('of @bundle-key %name', array('@bundle-key' => $this->getBundlePropertyLabel(), '%name' => $bundle_label)) : '';
    return check_plain($this->eventInfo['label']) . $suffix;
  }

  /**
   * Implements RulesEventHandlerInterface::buildForm()
   */
  public function buildForm(array &$form_state) {
    $options = array(
      'form' => t('Form'),
      'page' => t('Landing page'),
      'response' => t('Thank you page'),
    );
    $form['source_type'] = array(
      '#type' => 'select',
      '#title' => t('Filter by source type'),
      '#description' => t('If you need to filter for multiple values, either add multiple events or use the "Entity is of bundle" condition instead.'),
      '#default_value' => $this->settings['bundle'],
      '#empty_value' => '',
      '#options' => $options,
    );
    if (!empty($form['source_type'])) {

    }
    return $form;
  }

  /**
   * Returns the label to use for the bundle property.
   *
   * @return string
   */
  protected function getBundlePropertyLabel() {
    return $this->entityInfo['entity keys']['bundle'];
  }

  /**
   * Implements RulesEventHandlerInterface::extractFormValues()
   */
  public function extractFormValues(array &$form, array &$form_state) {
    $this->settings['source_type'] = !empty($form_state['values']['source_type']) ? $form_state['values']['source_type'] : NULL;
  }

  /**
   * Implements RulesEventHandlerInterface::validate()
   */
  public function validate() {
    if ($this->settings['bundle'] && empty($this->entityInfo['bundles'][$this->settings['bundle']])) {
      throw new RulesIntegrityException(t('The @bundle %bundle of %entity_type is not known.',
        array(
          '%bundle' => $this->settings['bundle'],
          '%entity_type' => $this->entityInfo['label'],
          '@bundle' => $this->getBundlePropertyLabel(),
        )), array(NULL, 'bundle'));
    }
  }

  /**
   * Implements RulesEventHandlerInterface::getConfiguredEventName()
   */
  public function getEventNameSuffix() {
    return $this->settings['bundle'];
  }

  /**
   * Implements RulesEventHandlerInterface::getDefaults()
   */
  public function getDefaults() {
    return array(
      'bundle' => NULL,
    );
  }

  /**
   * Implements RulesEventHandlerInterface::availableVariables()
   */
  public function availableVariables() {
    $variables = $this->eventInfo['variables'];
    if ($this->settings['bundle']) {
      // Add the bundle to all variables of the entity type.
      foreach ($variables as $name => $variable_info) {
        if ($variable_info['type'] == $this->entityType) {
          $variables[$name]['bundle'] = $this->settings['bundle'];
        }
      }
    }
    return $variables;
  }
}
