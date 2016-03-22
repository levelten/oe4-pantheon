<?php

/**
 * Generate form to manage banner information.
 *
 * @param <array> $slide
 *    Array with slide data
 *
 * @return <array>
 *    Form to manage image informations
 */
function _project_banner_form() {
  $img_form = array();

  // Image preview
  // $img_form['slide_preview'] = array(
  //     '#markup' => theme('image', array('path' => $slide['slide_thumb'])),
  // );

  $img_form['slide_file'] = array(
    '#type' => 'managed_file',
    '#name' => 'project_slider_image',
    '#title' => t('Background Image'),
    '#default_value' => $slide['slide_file'],
    '#description' => t("Upload an image to be processed."),
    '#required' => TRUE,
    '#upload_location' => 'public://banner/',
    '#upload_validators' => array(
      'file_validate_extensions' => array('gif png jpg jpeg'),
    ),
  );

  // Background color
  $img_form['slide_color'] = array(
      '#type' => 'textfield',
      '#title' => t('Background color'),
      '#default_value' => $slide_data['slide_color'],
      '#attributes' => array('class' => array('colorSelector')),
  );

  // Caption position
  $img_form['slide_position'] = array(
    '#type' => 'select',
    '#title' => t('Caption position'),
    '#options' => array(
      'default' => t('Default'),
      'left' => t('Left'),
      'right' => t('Right'),
    ),
    '#default_value' => $slide_data['slide_float'],
  );

  // Image title
  $img_form['slide_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $slide_data['slide_title'],
  );

  // Image description
  $img_form['slide_description'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#default_value' => $slide_data['slide_description'],
  );

  // Image weight
  $img_form['slide_weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#default_value' => $slide_data['slide_weight'],
  );

  // Image is published
  $img_form['slide_published'] = array(
    '#type' => 'checkbox',
    '#title' => t('Published'),
    '#default_value' => $slide_data['slide_published'],
  );

  return $img_form;
}

/**
 * Implementation of hook_theme()
 */
function project_theme() {
  return array(
    'project_slider' => array(
      'variables' => 'elements',
      'template' => 'project-slider',
    ),
  );
}
