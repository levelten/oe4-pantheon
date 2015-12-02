<?php

/**
 * Implements hook_ds_view_modes_info().
 */
function enterprise_style_ds_view_modes_info() {
  $view_modes = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'featured';
  $ds_view_mode->label = 'Featured';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $view_modes['featured'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'mini';
  $ds_view_mode->label = 'Mini';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'user' => 'user',
    'field_collection_item' => 'field_collection_item',
  );
  $view_modes['mini'] = $ds_view_mode;
  
  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'image';
  $ds_view_mode->label = 'Image';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $view_modes['image'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'text_teaser';
  $ds_view_mode->label = 'Text teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $view_modes['text_teaser'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_stacked';
  $ds_view_mode->label = 'Teaser Stacked';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $view_modes['teaser_stacked'] = $ds_view_mode;

  return $view_modes;
}

/**
 * Implements hook_ds_layout_info().
 */
function enterprise_style_ds_layout_info() {
  $layout_path = drupal_get_path('module', 'enterprise_style') . '/ds_layouts';
  $layouts = array(
    'bootstrap_carousel' => array(
      'label' => t('One column stacked'),
      'module' => 'bootstrap',
      'path' => $layout_path . '/bootstrap_1col_stacked',
      'regions' => array(
        'header' => t('Header'),
        'sticky' => t('Sticky Header'),
        'middle' => t('Content'),
        'footer' => t('Footer'),
      ),
    ),
    'bootstrap_1col_stacked' => array(
      'label' => t('One column stacked'),
      'module' => 'bootstrap',
      'path' => $layout_path . '/bootstrap_1col_stacked',
      'regions' => array(
        'header' => t('Header'),
        'sticky' => t('Sticky Header'),
        'middle' => t('Content'),
        'footer' => t('Footer'),
      ),
    ),
    'bootstrap_1col_fluid_stacked' => array(
      'label' => t('One column fluid stacked'),
      'module' => 'bootstrap',
      'path' => $layout_path . '/bootstrap_1col_fluid_stacked',
      'regions' => array(
        'header' => t('Header'),
        'middle' => t('Content'),
        'footer' => t('Footer'),
      ),
      'image' => TRUE,
    ),
    'bootstrap_2col_fluid_stacked' => array(
      'label' => t('Two column fluid stacked'),
      'module' => 'bootstrap',
      'path' => $layout_path . '/bootstrap_2col_fluid_stacked',
      'regions' => array(
        'header' => t('Header'),
        'left' => t('Left'),
        'right' => t('Right'),
        'footer' => t('Footer'),
      ),
      'image' => TRUE,
    ),
  );
  return $layouts;
}

/**
 * Implements hook_ds_classes_alter().
 * Provide the necessary classes for blog types.
 */
function enterprise_style_ds_classes_alter(&$classes, $name) {
  if ('ds_classes_regions' === $name) {

    $classes['style-default-full'] = t('Default: Full');
    $classes['style-default-featured'] = t('Default: Featured');
    $classes['style-default-teaser'] = t('Default: Teaser');
    $classes['style-default-mini'] = t('Default: Mini');
    $classes['style-default-related'] = t('Default: Related');

    $classes['no-grid'] = t('No Grid');
    $classes['col-md-1'] = t('Col Md 1');
    $classes['col-md-2'] = t('Col Md 2');
    $classes['col-md-3'] = t('Col Md 3');
    $classes['col-md-4'] = t('Col Md 4');
    $classes['col-md-5'] = t('Col Md 5');
    $classes['col-md-6'] = t('Col Md 6');
    $classes['col-md-7'] = t('Col Md 7');
    $classes['col-md-8'] = t('Col Md 8');
    $classes['col-md-9'] = t('Col Md 9');
    $classes['col-md-10'] = t('Col Md 10');
    $classes['col-md-11'] = t('Col Md 11');
    $classes['col-md-12'] = t('Col Md 12');

    $classes['row'] = t('Row');
    $classes['row-fluid'] = t('Row Fluid');
    $classes['container'] = t('Container');
    $classes['container-fluid'] = t('Container Fluid');

    $classes['visible-xs'] = t('Phone: visible');
    $classes['visible-sm'] = t('Tablet: visible');
    $classes['visible-md'] = t('Desktop: visible');
    $classes['hidden-xs'] = t('Phone: hidden');
    $classes['hidden-sm'] = t('Tablet: hidden');
    $classes['hidden-md'] = t('Desktop: hidden');

    $classes['text-left'] = t('Text Align: Left');
    $classes['text-center'] = t('Text Align: Center');
    $classes['text-right'] = t('Text Align: Right');
    $classes['text-justify'] = t('Text Align: Justify');

    $classes['margin-top'] = t('Margin: Top');
    $classes['margin-right'] = t('Margin: Right');
    $classes['margin-bottom'] = t('Margin: Bottom');
    $classes['margin-left'] = t('Margin: Left');

    $classes['no-margin-top'] = t('No Margin: Top');
    $classes['no-margin-right'] = t('No Margin: Right');
    $classes['no-margin-bottom'] = t('No Margin: Bottom');
    $classes['no-margin-left'] = t('No Margin: Left');

    $classes['pull-left'] = t('Float Left');
    $classes['pull-right'] = t('Float Right');

    $classes['no-wrap'] = t('No Wrap (Overflow)');

  }
}

/**
 * Returns the correct span class for a region
 */
function enterprise_style_ds_span_columns(&$classes, $columns = 1) {
  if (is_string($classes)) {
    $classes = explode(' ', $classes);
  }
  $no_span = FALSE;
  foreach ($classes as $key => $class) {
    if (strpos($class, 'col-md-') === 0 || strpos($class, 'no-grid') === 0) {
      $classes = implode(' ', $classes);
      return;
    }
  }
  switch($columns) {
    case 1:
      $classes[] = 'col-md-12';
      break;
    case 2:
      $classes[] = 'col-md-6';
      break;
    case 3:
      $classes[] = 'col-md-4';
      break;
    case 4:
      $classes[] = 'col-md-3';
      break;
  }
  $classes = implode(' ', $classes);
}

function enterprise_style_ds_span_column_replace(&$classes, $columns = 1) {
  $classes_array = $classes;
  if (is_string($classes_array)) {
    $classes_array = explode(' ', $classes);
  }
  $classes_array = array_filter($classes_array);
  foreach ($classes_array as $key => &$class) {
    if (strpos($class, 'col-md-') === 0) {
      unset($classes_array[$key]);
      enterprise_style_ds_span_columns($class, $columns);
    }
  }
  $classes = implode(' ', $classes_array);
}

/**
 * Implements hook_ds_fields_info().
 */
function enterprise_style_ds_fields_info($entity_type) {
  $node = array();
  $user = array();
  $fc_item = array();
  $bean = array();
  $user['user_thumbnail'] = array(
    'title' => t('User Thumbnail'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit' => array('*|*'),
    'function' => 'enterprise_style_ds_field_user_thumbnail',
    'properties' => array(),
  );
  $node['unpublished'] = array(
    'title' => t('Unpublished Banner'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit' => array('*|*'),
    'function' => 'enterprise_style_ds_field_unpublished',
    'properties' => array(),
  );
  $node['submit_info'] = array(
    'title' => t('Submit Info (Date, Author)'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit' => array('*|*'),
    'function' => 'enterprise_style_ds_field_submit_info',
    'properties' => array(),
  );
  if (module_exists('enterprise_user')) {
    $node['about_author'] = $user['about_author'] = array(
      'title' => t('About Author'),
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => array('*|*'),
      'function' => 'enterprise_style_ds_field_about_author',
      'properties' => array(),
    );
    $user['blog_author'] = array(
      'title' => t('Blog Author'),
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => array('*|*'),
      'function' => 'enterprise_style_ds_field_blog_author',
      'properties' => array(),
    );
  }
  if (module_exists('prev_next')) {
    $node['prev_next_node'] = array(
      'title' => t('Prev/Next Node'),
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ul_limit' => array('*|*'),
      'function' => 'enterprise_style_ds_field_prev_next_node',
      'properties' => array(),
      'direction' => 'next',
    );
  }
  if (module_exists('comment')) {
    $node['comment_count'] = array(
      'title' => t('Comment Count'),
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => array('*|*'),
      'function' => 'enterprise_style_ds_field_comment_count',
      'properties' => array(),
    );
  }
  $node['date_stacked'] = array(
    'title' => t('Date stacked'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit' => array('*|*'),
    'function' => 'enterprise_style_ds_field_date_stacked',
    'properties' => array(),
  );
  for ($i = 1; $i <= 5; $i++) {
    $fc_item['enterprise_custom_' . $i] = $bean['enterprise_custom_' . $i] = $node['enterprise_custom_' . $i] = array(
      'title' => t('Custom') . ' ' . $i,
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => array('*|*'),
      'function' => 'enterprise_style_ds_field_custom',
      'properties' => array(
        'settings' => array(
          'custom_markup' => array(
            'title' => t('Custom markup'),
            'type' => 'textfield',
            'description' => t('Input custom markup to display in this field.'),
          ),
        ),
        'default' => array(
          'custom_markup' => '',
        ),
      ),

    );
  }


  return array('node' => $node, 'user' => $user, 'bean' => $bean, 'field_collection_item' => $fc_item);

  /*
  $node['bootstrap_jumbotron'] = array(
    'title' => t('Bootstrap jumbotron'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit' => array('*|*'),
    'function' => 'enterprise_style_bootstrap_jumbotron_field',
    'properties' => array(),
  );
  return array('node' => $node);
  */
}

function enterprise_style_ds_fields_info_alter(&$fields, $entity_type) {
  $link_fields = array();
  /*
  $link_fields['properties']['settings']['link_attr_title'] = array(
    'type' => 'checkbox',
    'title' => t('Title attribute'),
    'description' => t('Include title="[entity:title]" in anchor tag.'),
  );
  $link_fields['properties']['default']['link_attr_title'] = 1;
  */

  // Adding absolute URL option to node link
  $link_fields['properties']['settings']['link_href_absolute'] = array(
    'type' => 'checkbox',
    'title' => t('Absolute URL'),
    'description' => t('Convert this link into an absolute URL. Handy for RSS feeds.'),
  );
  $link_fields['properties']['default']['link_href_absolute'] = 0;
  if (!empty($fields['node_link'])) {
    $fields['node_link'] = drupal_array_merge_deep($fields['node_link'], $link_fields);
    $fields['node_link']['function'] = 'enterprise_style_ds_field_node_link';
  }
  /*
  if (!empty($fields['title'])) {
    $fields['title'] = drupal_array_merge_deep($fields['title'], $link_fields);
    $fields['title']['function'] = 'enterprise_style_ds_field_node_link';
    //$fields['node_link']['function'] = 'enterprise_style_ds_field_node_link';
  }
  */
}

function enterprise_style_ds_field_node_link($field) {
  $settings = isset($field['formatter_settings']) ? $field['formatter_settings'] : array();
  $settings += $field['properties']['default'];

  // Link.
  if (!empty($settings['link'])) {
    if (!empty($settings['link_href_absolute'])) {
      if (!isset($field['entity']->uri)) {
        $field['entity']->uri = entity_uri($field['entity_type'], $field['entity']);
      }
      if (!isset($field['entity']->uri['options'])) {
        $field['entity']->uri['options'] = array();
      }
      $field['entity']->uri['options']['absolute'] = 1;
    }
    /*
    if (!empty($settings['link_attr_title'])) {
      if (!isset($field['entity']->uri['options'])) {
        $field['entity']->uri['options'] = array();
      }
      if (!isset($field['entity']->uri['options']['attributes'])) {
        $field['entity']->uri['options']['attributes'] = array();
      }
      $field['entity']->uri['options']['attributes'] = $field['entity']->title;
    }
    */
  }
  return ds_render_field($field);
}

function enterprise_style_ds_field_user_thumbnail($variables) {
  $entity = $variables['entity'];
  $account = user_load($entity->uid);
  $picture_field = 'field_picture_thumbnail';
  if (isset($account->field_picture_thumbnail['und'][0]['is_default']) && $account->field_picture_thumbnail['und'][0]['is_default']) {
    if (!isset($account->field_enterprise_style_picture['und'][0]['is_default']) || !$account->field_enterprise_style_picture['und'][0]['is_default']) {
      $picture_field = 'field_enterprise_style_picture';
    }
  }
  $photo = field_view_field('user', $account, $picture_field, array('label' => 'hidden', 'settings' => array('image_style' => '150x75')));
  if ($photo) {
    return drupal_render($photo);
  }
}

function enterprise_style_ds_field_about_author($variables) {
  if (module_exists('enterprise_user')) {
    $title_tag = (isset($variables['title_tag'])) ? $variables['title_tag'] : 'h3';
    $title_prefix = (isset($variables['title_prefix'])) ? $variables['title_prefix'] : '';
    $title_suffix = (isset($variables['title_suffix'])) ? $variables['title_suffix'] : '';
    $entity = $variables['entity'];
    $account = user_load($entity->uid);
    $view_mode = 'user_about'; // This view mode is in enterprise_user.
    $output = $title_prefix . "<$title_tag>" . l(t('About the Author'), 'user/' . $entity->uid, array('attributes' => array('class' => array('name')))) . "</$title_tag>" . $title_suffix;
    $user_view = user_view($account, $view_mode);
    $output .= drupal_render($user_view);
    return $output;
  }
}

function enterprise_style_ds_field_blog_author($variables) {
  if (module_exists('enterprise_user')) {
    $entity = $variables['entity'];
    $name = ($entity->realname?$entity->realname:$entity->name);
    $output = l($name, 'resources/blog/' . enterprise_base_create_machine_name($name, '-'), array('attributes' => array('class' => array('name'))));
    return $output;
  }
}

function enterprise_style_ds_field_unpublished($variables) {
  $entity = $variables['entity'];
  if (!$entity->status) {
    return '<span class="style-unpublished"><span class="line"></span><span class="text">Unpublished</span></span>';
  }
}

/**
 * Field callback for submit_info
 *
 * @param type $variables
 * @return type
 */
function enterprise_style_ds_field_submit_info($variables) {
  $entity = $variables['entity'];
  $user = user_load($entity->uid);
  return '<div class="submit_info">' . format_date($entity->created, 'custom', 'F j, Y') . t(' by ') . theme('username', array('account' => $user)) . '</div>';
}

/**
 * Field callback for previous/next buttons
 *
 * @param type $variables
 * @return type
 */
function enterprise_style_ds_field_prev_next_node($variables) {
  if (module_exists('prev_next')) {
    $entity = $variables['entity'];
    $next = prev_next_nid($entity->nid, 'next');
    $prev = prev_next_nid($entity->nid, 'prev');
    if (!empty($next) || !empty($prev)) {
      $output = '';
      if (!empty($next) && !empty($prev)) {
        return l(t('Next') . theme('icon', array('bundle' => 'enterprise_style', 'icon' => 'oeicon-right-open-big')) . '<span class="arrow"></span>', 'node/' . $next, array('html' => TRUE, 'attributes' => array('class' => array('btn', 'btn-primary', 'next')))) . l(theme('icon', array('bundle' => 'enterprise_style', 'icon' => 'oeicon-left-open-big')), 'node/' . $prev, array('html' => TRUE, 'attributes' => array('class' => array('btn', 'btn-primary', 'prev', 'small'))));
      }
      elseif (!empty($next)) {
        return l(t('Next') . theme('icon', array('bundle' => 'enterprise_style', 'icon' => 'oeicon-right-open-big')), 'node/' . $next, array('html' => TRUE, 'attributes' => array('class' => array('btn', 'btn-primary', 'next'))));
      }
      elseif (!empty($prev)) {
        return l(theme('icon', array('bundle' => 'enterprise_style', 'icon' => 'oeicon-left-open-big')) . t('Previous'), 'node/' . $prev, array('html' => TRUE, 'attributes' => array('class' => array('btn', 'btn-primary', 'prev'))));
      }
    }
  }
}

/**
 * Field callback for meta_info
 *
 * @param type $variables
 * @return type
 */
function enterprise_style_ds_field_comment_count($variables) {
  if (module_exists('comment')) {
    $entity = $variables['entity'];
    if ($entity->comment) {
      $items[] = l(format_plural($entity->comment_count, 'Comment (1)', 'Comments (@count)'), 'node/' . $entity->nid, array('fragment' => 'comments'));
    }
    return theme('item_list', array('items' => $items, 'attributes' => array('class' => array('meta-info'))));
  }
}

/**
 * Implements hook_ds_field_settings_form().
 */
function enterprise_style_ds_field_settings_form($field) {
  return ds_ds_field_settings_form($field);
}

/**
 * Implements hook_ds_field_format_summary().
 */
function enterprise_style_ds_field_format_summary($field) {
  $summary = ds_ds_field_format_summary($field);
  $summary = ($summary != '') ? $summary : t('None');
  return $summary;
}

/**
 * Field callback for meta_info
 *
 * @param type $variables
 * @return type
 */
function enterprise_style_ds_field_custom($variables) {
  $output = '';
  if (!empty($variables['formatter_settings']['custom_markup'])) {
    $output = $variables['formatter_settings']['custom_markup'];
  }
  return $output;
}


/**
 * Field callback for date_stacked
 *
 * @param type $variables
 * @return type
 */
function enterprise_style_ds_field_date_stacked($variables) {
  $entity = $variables['entity'];
  return '
<div class="style-date-stacked">
  <span class="day">' . date("j", $entity->created) . '</span>
  <span class="month">' . date("M", $entity->created) . '</span>
  <span class="arrow"></span>
</div>';
}
