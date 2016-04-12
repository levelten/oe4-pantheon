<?php
/**
 * @file
 * enterprise_block_post.features.uuid_entities.inc
 */

/**
 * Implements hook_uuid_default_entities().
 */
function enterprise_demo_config_uuid_default_entities() {
  $entities = array();

  $entities['enterprise_block_brand_bar'][] = (object) array(
    '__metadata' => array(
      'type' => 'bean',
      'uri' => 'bean/7bae525a-d1e9-4c12-8f00-2a534335dda0',
      'cause' => FALSE,
    ),
    'data' => array(
      'view_mode' => 'default',
    ),
    'default_revision' => 1,
    'delta' => 'brand_bar',
    'description' => NULL,
    'entity_type' => 'bean',
    'field_body' => array(
      'und' => array(
        0 => array(
          'format' => 'advanced_html',
          'value' => '<div class="row navbar-default">
  <div class="col-sm-6 col-xs-12 pull-right brand-bar-right">
    <div class="row">
      <div class="col-sm-12 col-xs-6 phone">Call <a href="tel:[site:intel_phone:main:number]">[site:intel_phone:main:number]</a></div>
      <div class="col-sm-12 col-xs-6"><button type="button" class="btn cta cta-accent m-y-_25" data-toggle="modal" data-target="#contact-modal">Request A Consultation</button></div>
    </div>
  </div>
  <div class="col-sm-6 col-xs-12 brand-bar-left">
    [site:header-branding]
    [site:navbar-toggle]
  </div>
</div>

<!-- Modal -->
<div class="modal fade" id="contact-modal" tabindex="-1" role="dialog" aria-labelledby="contact-modal-label">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title" id="contact-modal-label">Request a Consultation</h4>
      </div>
      <div class="modal-body block-title-hide">
        (ADD WEBFORM BLOCK HERE)
      </div>
    </div>
  </div>
</div>',
        ),
      ),
    ),
    'label' => 'Brand Bar',
    'log' => '',
    'revision' => 1,
    'revisions' => array(),
    'title' => '',
    'type' => 'basic_block',
    'uid' => 1,
    'url_alias' => array(),
    'uuid' => '7bae525a-d1e9-4c12-8f00-2a534335dda0',
    'view_mode' => 'default',
  );

  return $entities;
}
