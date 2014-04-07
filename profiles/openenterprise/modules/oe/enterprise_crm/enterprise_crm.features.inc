<?php
/**
 * @file
 * enterprise_crm.features.inc
 */

/**
 * Implements hook_default_crm_core_contact_type().
 */
function enterprise_crm_default_crm_core_contact_type() {
  $items = array();
  $items['household'] = entity_import('crm_core_contact_type', '{
    "type" : "household",
    "label" : null,
    "weight" : 0,
    "primary_fields" : null,
    "name" : "Household",
    "description" : "A collection of individuals generally located at the same residence.",
    "custom" : "0",
    "disabled" : "0",
    "locked" : "1",
    "entity_type" : "crm_core_contact_type"
  }');
  $items['individual'] = entity_import('crm_core_contact_type', '{
    "type" : "individual",
    "label" : null,
    "weight" : 0,
    "primary_fields" : {
      "email" : "field_email",
      "address" : "field_address",
      "phone" : "field_phone"
    },
    "name" : "Individual",
    "description" : "A single individual.",
    "custom" : "0",
    "disabled" : "0",
    "locked" : "1",
    "entity_type" : "crm_core_contact_type"
  }');
  $items['organization'] = entity_import('crm_core_contact_type', '{
    "type" : "organization",
    "label" : null,
    "weight" : 0,
    "primary_fields" : null,
    "name" : "Organization",
    "description" : "A collection of individuals or other organizations that has additional contact data.",
    "custom" : "0",
    "disabled" : "0",
    "locked" : "1",
    "entity_type" : "crm_core_contact_type"
  }');
  return $items;
}
