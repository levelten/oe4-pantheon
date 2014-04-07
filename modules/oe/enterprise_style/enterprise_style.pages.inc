<?php

function theme_user_thumbnail($vars) {
  dsm($vars);
  $entity = $vars['entity'];
  $account = (isset($vars['user'])) ? $vars['user'] : '';
  if (!$account && isset($vars['uid'])) {
    $account = user_load($vars['uid']);
  }
  if (!$account && isset($vars['entity'])) {
    $account = user_load($vars['entity']->uid);
  }
  dsm($account);


  $picture_field = 'field_picture_thumbnail';
  if (isset($user->field_picture_thumbnail['und'][0]['is_default']) && $account->field_picture_thumbnail['und'][0]['is_default']) {
    if (!isset($user->field_enterprise_style_picture['und'][0]['is_default']) || !$account->field_enterprise_style_picture['und'][0]['is_default']) {
      $picture_field = 'field_enterprise_style_picture';
    }
  }
  $photo = field_view_field('user', $account, $picture_field, array('label' => 'hidden', 'settings' => array('image_style' => '150x75')));
  if ($photo) {
    return drupal_render($photo);
  }
}

function template_preprocess_bootstrap_jumbotron(&$variables) {
  $link = $variables['link'];
  if (!isset($link['options'])) {
    $link['options'] = array();
  }
  if (!isset($link['options']['attributes'])) {
    $link['options']['attributes'] = array();
  }
  if (!isset($link['options']['attributes']['class'])) {
    $link['options']['attributes']['class'] = array();
  }
  $link['options']['attributes']['class'][] = 'btn';
  $link['options']['attributes']['class'][] = 'btn-primary';
  $link['options']['attributes']['class'][] = 'btn-lg';
  $link['options']['attributes']['role'] = 'button';

  $variables['link'] = l($link['text'], $link['path'], $link['options']);
}

function template_preprocess_bootstrap_featurette(&$vars) {
  if (!isset($vars['header_classes_array'])) {
    $vars['header_classes_array'] = array();
  }
  $vars['header_classes_array'][] = 'featurette-heading';

  if (!isset($vars['image_wrapper_classes_array'])) {
    $vars['image_wrapper_classes_array'] = array();
  }
  $vars['image_wrapper_classes_array'][] = 'image';

  if (!isset($vars['message_wrapper_classes_array'])) {
    $vars['message_wrapper_classes_array'] = array();
  }
  $vars['message_wrapper_classes_array'][] = 'message';

  if ($vars['link']) {
    $link = &$vars['link'];
    if (!isset($link['options'])) {
      $link['options'] = array();
    }
    if (!isset($link['options']['attributes'])) {
      $link['options']['attributes'] = array();
    }
    if (!isset($link['options']['attributes']['class'])) {
      $link['options']['attributes']['class'] = array();
    }
    $link['options']['attributes']['class'][] = 'btn';
    $link['options']['attributes']['class'][] = 'btn-primary';
    $link['options']['attributes']['class'][] = 'btn-lg';
    $link['options']['attributes']['role'] = 'button';
  }
  if ($vars['image']) {
    $image = &$vars['image'];
    if (!isset($image['attributes'])) {
      $image['attributes'] = array();
    }
    if (!isset($image['attributes']['class'])) {
      $image['attributes']['class'] = array();
    }
    // move classes from img tag to wrapper that should be on wrapper
    foreach ($image['attributes']['class'] AS $i => $class) {
      if (strpos($class, 'pull-') === 0) {
        $vars['image_wrapper_classes_array'][] = $class;
        unset($image['attributes']['class'][$i]);
      }
    }
    $image['attributes']['class'][] = 'featurette-image';

    $image_cols = 5;
    if (isset($image['cols'])) {
      $image_cols = $image['cols'];
    }
    $vars['image_wrapper_classes_array'][] = 'col-md-' . $image_cols;
    $vars['message_wrapper_classes_array'][] = 'col-md-' . (12 - $image_cols);
    if (isset($image['pull'])) {
      $vars['image_wrapper_classes_array'][] = 'pull-' . $image['pull'];
    }

  }

  $vars['header_classes'] = implode(' ', $vars['header_classes_array']);
  $vars['image_wrapper_classes'] = implode(' ', $vars['image_wrapper_classes_array']);
  $vars['message_wrapper_classes'] = implode(' ', $vars['message_wrapper_classes_array']);
}

function template_preprocess_bootstrap_featurette_stacked(&$vars) {
  if (!isset($vars['header_classes_array'])) {
    $vars['header_classes_array'] = array();
  }
  $vars['header_classes_array'][] = 'featurette-heading';

  if (!isset($vars['image_wrapper_classes_array'])) {
    $vars['image_wrapper_classes_array'] = array();
  }
  $vars['image_wrapper_classes_array'][] = 'image';

  if (!isset($vars['message_wrapper_classes_array'])) {
    $vars['message_wrapper_classes_array'] = array();
  }
  $vars['message_wrapper_classes_array'][] = 'message';

  if ($vars['link']) {
    $link = &$vars['link'];
    if (!isset($link['options'])) {
      $link['options'] = array();
    }
    if (!isset($link['options']['attributes'])) {
      $link['options']['attributes'] = array();
    }
    if (!isset($link['options']['attributes']['class'])) {
      $link['options']['attributes']['class'] = array();
    }
    $link['options']['attributes']['class'][] = 'btn';
    $link['options']['attributes']['class'][] = 'btn-default';
    $link['options']['attributes']['role'] = 'button';
  }
  if ($vars['image']) {
    $image = &$vars['image'];
    if (!isset($image['attributes'])) {
      $image['attributes'] = array();
    }
    if (!isset($image['attributes']['class'])) {
      $image['attributes']['class'] = array();
    }
    //$image['attributes']['class'][] = 'featurette-stacked-image';
    $image['attributes']['class'][] = 'img-circle';
  }

  $vars['header_classes'] = implode(' ', $vars['header_classes_array']);
  $vars['wrapper_classes'] = implode(' ', $vars['image_wrapper_classes_array']);
  //dsm($vars);
}


function template_preprocess_date_stacked(&$vars) {
  $time = REQUEST_TIME;
  if (isset($vars['entity'])) {
    if (isset($vars['entity']->created)) {
      $time = $vars['entity']->created;
    }
  }
  else if (isset($var['time'])) {
    $time = $vars['time'];
  }

  if (!isset($vars['day'])) {
    $vars['day'] = date("d", $time);
  }
  if (!isset($vars['month'])) {
    $vars['month'] = date("M", $time);
  }
}