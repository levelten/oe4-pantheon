<?php
/**
 * @file
 * enterprise_conversion.admin.inc
 */

function enterprise_conversion_landingpage_cta_list_page($node) {
  $output = '';

  drupal_set_title(t('CTAs to %title',
    array(
      '%title' => $node->title,
    )
  ), PASS_THROUGH);
  $beans = enterprise_conversion_ctas_load_by_node($node->nid);

  // Build the sortable table header.
  $header = array(
    'title' => array(
      'data' => 'Title',
      'type' => 'property',
      'specifier' => 'title',
      'sort' => 'asc'
    ),
    'type' => array(
      'data' => 'Type',
      'type' => 'entity',
      'specifier' => 'bundle',
    ),
    'available' => array(
      'data' => t('Available in'),
    ),
    'selectors' => array('data' => t('Operations')),
  );

  $selectors = cta_selectors();
  $metas = cta_bean_metas();
  $rows = array();
//dsm($selectors);
//dsm($metas);
  foreach ($beans as $bean) {
    $sstr = '';
    foreach ($metas[$bean->delta]['selectors'] AS $name) {
      $sstr  = (($sstr ) ? ', ' : '') . $selectors[$name]['description'];
    }
    $rows[$bean->bid] = array(
      'title' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $bean->label,
          '#href' => 'block/' . $bean->delta,
          '#attributes' => array(
            'data-preview' => 'test',
          )
        ),
      ),
      'type' => (substr($bean->label, 0, 7) == 'custom ') ? t('custom') : check_plain($bean->type),
      'selectors' => $sstr,
    );

    $destination = drupal_get_destination();

    // Build a list of all the accessible operations for the current bean.
    $operations = array();
    $operations['edit'] = array(
      'title' => t('edit'),
      'href' => 'block/' . $bean->delta . '/edit',
      'query' => $destination,
    );
    $operations['delete'] = array(
      'title' => t('delete'),
      'href' => 'block/' . $bean->delta . '/delete',
      'query' => $destination,
    );
    // Render an unordered list of operations links.
    $rows[$bean->bid]['operations'] = array(
      'data' => array(
        '#theme' => 'links__bean_operations',
        '#links' => $operations,
        '#attributes' => array('class' => array('links', 'inline')),
      ),
    );
  }

  $link_options = array(
    'query' => array(
      'target_id' => $node->nid,
      'destination' => 'node/' . $node->nid . '/cta',
    ),
  );

  $add_links = array();
  if (is_array($selectors)) {
    foreach ($selectors AS $name => $selector) {
      // exclude cta_forms selector
      if ($name == 'cta_forms') {
        continue;
      }
      if (is_string($selector['data'])) {
        $selector['data'] = unserialize($selector['data']);
      }
      if (!empty($selector['data']['cta_description'])) {

        $text = '+' . t('Add @name CTA',
          array(
            '@name' => $selector['data']['cta_description'],
          )
        );
        $lo = $link_options;
        $lo['query']['selectors'] = $name;
        $add_links[] = l($text, 'block/add/cta', $lo);
      }
    }
  }

  $output = array(
    'add_links' => array(
      '#type' => 'markup',
      '#markup' => implode(' ', $add_links),
    ),
    //'bean_filter_form' => drupal_get_form('bean_filter_form'),
    'bean_content' => array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
      '#empty' => t('There are no CTAs linked to this landing page. !add_link',
        array(
          '!add_link' => l(t('Add a CTA'), 'block/add/cta', $link_options),
        )
      ),
    ),
    'pager' => array(
      '#theme' => 'pager',
    ),
  );


  return $output;
}

function enterprise_conversion_thankyou_landingpage_list_page($node) {
  $output = '';

  drupal_set_title(t('Landing pages to %title',
    array(
      '%title' => $node->title,
    )
  ), PASS_THROUGH);

  $nids = array();

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->fieldCondition('field_thankyou', 'target_id', $node->nid);
  $result = $query->execute();

  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
  }

  $path = 'node/' . $node->nid;
  $alias = drupal_get_path_alias($path);

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->fieldCondition('field_redirect_url', 'url', $path);
  $result = $query->execute();

  if (isset($result['node'])) {
    $nids = array_merge($nids, array_keys($result['node']));
  }

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->fieldCondition('field_redirect_url', 'url', $alias);
  $result = $query->execute();

  if (isset($result['node'])) {
    $nids = array_merge($nids, array_keys($result['node']));
  }

  $nodes = entity_load('node', $nids);

  $header = array(
    t('Title'),
    t('Type'),
    t('Ops'),
  );

  $rows = array();
  foreach ($nodes AS $nid => $node) {
    $rows[] = array(
      l($node->title, 'node/' . $node->nid),
      $node->type,
      l(t('edit'), 'node/' . $node->nid . '/edit'),
    );
  }

  $link_options = array(
    'query' => array(
      'target_id' => $node->nid,
      'destination' => 'node/' . $node->nid . '/landingpage',
    ),
  );

  $add_links[] = l(t('+Add landing page'), 'node/add/enterprise-landingpage', $link_options);
  $output = array(
    'add_links' => array(
      '#type' => 'markup',
      '#markup' => implode(' ', $add_links),
    ),
    'lp_content' => array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
      '#empty' => t('There are no Landing pages linked to this thank you page. !add_link',
        array(
          '!add_link' => l(t('Add a Landing page'), 'node/add/enterprise-landingpage', $link_options),
        )
      ),
    ),
    'pager' => array(
      '#theme' => 'pager',
    ),
  );

  return $output;
}

function enterprise_conversion_landingpage_submission_list_page($node) {
  $output = '';

  drupal_set_title(t('Submissions %title',
    array(
      '%title' => $node->title,
    )
  ), PASS_THROUGH);

  include_once(drupal_get_path('module', 'intel') . '/admin/intel.admin_submission.inc');
  $et_settings = variable_get('enterprise_conversion_settings_node__' . $node->type, array());
  if (!empty($et_settings['landingpage'])) {
    $filter = array(
      'conditions' => array(
        array(
          'form_page_id',
          $node->nid
        ),
      ),
    );
  }
  else if (!empty($et_settings['thankyou'])) {
    $filter = array(
      'conditions' => array(
        array(
          'response_page_id',
          $node->nid
        ),
      ),
    );
  }
  return intel_admin_people_submissions($filter);
}
