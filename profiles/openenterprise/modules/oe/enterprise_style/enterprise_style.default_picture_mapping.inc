<?php
/**
 * @file
 * enterprise_style.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function enterprise_style_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'full-0';
  $picture_mapping->machine_name = 'full-0';
  $picture_mapping->breakpoint_group = 'full-0';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-0-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-0-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-0-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-0-xs',
      ),
    ),
  );
  $export['full-0'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'full-16x9';
  $picture_mapping->machine_name = 'full-16x9';
  $picture_mapping->breakpoint_group = 'full-16x9';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-16x9-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-16x9-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-16x9-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-16x9-xs',
      ),
    ),
  );
  $export['full-16x9'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'full-1x1';
  $picture_mapping->machine_name = 'full-1x1';
  $picture_mapping->breakpoint_group = 'full-1x1';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-1x1-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-1x1-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-1x1-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-1x1-xs',
      ),
    ),
  );
  $export['full-1x1'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'full-3x1';
  $picture_mapping->machine_name = 'full-3x1';
  $picture_mapping->breakpoint_group = 'full-3x1';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-3x1-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-3x1-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-3x1-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-3x1-xs',
      ),
    ),
  );
  $export['full-3x1'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'full-5x7';
  $picture_mapping->machine_name = 'full-5x7';
  $picture_mapping->breakpoint_group = 'full-5x7';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-5x7-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-5x7-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-5x7-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-5x7-xs',
      ),
    ),
  );
  $export['full-5x7'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'full-7x5';
  $picture_mapping->machine_name = 'full-7x5';
  $picture_mapping->breakpoint_group = 'full-7x5';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-7x5-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-7x5-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-7x5-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full-7x5-xs',
      ),
    ),
  );
  $export['full-7x5'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'large-0';
  $picture_mapping->machine_name = 'large-0';
  $picture_mapping->breakpoint_group = 'large-0';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-0-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-0-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-0-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-0-xs',
      ),
    ),
  );
  $export['large-0'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'large-16x9';
  $picture_mapping->machine_name = 'large-16x9';
  $picture_mapping->breakpoint_group = 'large-16x9';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-16x9-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-16x9-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-16x9-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-16x9-xs',
      ),
    ),
  );
  $export['large-16x9'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'large-1x1';
  $picture_mapping->machine_name = 'large-1x1';
  $picture_mapping->breakpoint_group = 'large-1x1';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-1x1-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-1x1-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-1x1-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-1x1-xs',
      ),
    ),
  );
  $export['large-1x1'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'large-3x1';
  $picture_mapping->machine_name = 'large-3x1';
  $picture_mapping->breakpoint_group = 'large-3x1';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-3x1-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-3x1-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-3x1-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-3x1-xs',
      ),
    ),
  );
  $export['large-3x1'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'large-5x7';
  $picture_mapping->machine_name = 'large-5x7';
  $picture_mapping->breakpoint_group = 'large-5x7';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-5x7-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-5x7-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-5x7-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-5x7-xs',
      ),
    ),
  );
  $export['large-5x7'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'large-7x5';
  $picture_mapping->machine_name = 'large-7x5';
  $picture_mapping->breakpoint_group = 'large-7x5';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-7x5-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-7x5-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-7x5-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large-7x5-xs',
      ),
    ),
  );
  $export['large-7x5'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'medium-0';
  $picture_mapping->machine_name = 'medium-0';
  $picture_mapping->breakpoint_group = 'medium-0';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-0-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-0-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-0-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-0-xs',
      ),
    ),
  );
  $export['medium-0'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'medium-16x9';
  $picture_mapping->machine_name = 'medium-16x9';
  $picture_mapping->breakpoint_group = 'medium-16x9';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-16x9-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-16x9-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-16x9-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-16x9-xs',
      ),
    ),
  );
  $export['medium-16x9'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'medium-1x1';
  $picture_mapping->machine_name = 'medium-1x1';
  $picture_mapping->breakpoint_group = 'medium-1x1';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-1x1-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-1x1-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-1x1-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-1x1-xs',
      ),
    ),
  );
  $export['medium-1x1'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'medium-3x1';
  $picture_mapping->machine_name = 'medium-3x1';
  $picture_mapping->breakpoint_group = 'medium-3x1';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-3x1-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-3x1-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-3x1-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-3x1-xs',
      ),
    ),
  );
  $export['medium-3x1'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'medium-5x7';
  $picture_mapping->machine_name = 'medium-5x7';
  $picture_mapping->breakpoint_group = 'medium-5x7';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-5x7-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-5x7-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-5x7-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-5x7-xs',
      ),
    ),
  );
  $export['medium-5x7'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'medium-7x5';
  $picture_mapping->machine_name = 'medium-7x5';
  $picture_mapping->breakpoint_group = 'medium-7x5';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-7x5-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-7x5-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-7x5-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'medium-7x5-xs',
      ),
    ),
  );
  $export['medium-7x5'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'small-0';
  $picture_mapping->machine_name = 'small-0';
  $picture_mapping->breakpoint_group = 'small-0';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-0-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-0-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-0-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-0-xs',
      ),
    ),
  );
  $export['small-0'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'small-16x9';
  $picture_mapping->machine_name = 'small-16x9';
  $picture_mapping->breakpoint_group = 'small-16x9';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-16x9-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-16x9-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-16x9-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-16x9-xs',
      ),
    ),
  );
  $export['small-16x9'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'small-1x1';
  $picture_mapping->machine_name = 'small-1x1';
  $picture_mapping->breakpoint_group = 'small-1x1';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-1x1-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-1x1-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-1x1-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-1x1-xs',
      ),
    ),
  );
  $export['small-1x1'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'small-3x1';
  $picture_mapping->machine_name = 'small-3x1';
  $picture_mapping->breakpoint_group = 'small-3x1';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-3x1-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-3x1-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-3x1-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-3x1-xs',
      ),
    ),
  );
  $export['small-3x1'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'small-5x7';
  $picture_mapping->machine_name = 'small-5x7';
  $picture_mapping->breakpoint_group = 'small-5x7';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-5x7-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-5x7-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-5x7-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-5x7-xs',
      ),
    ),
  );
  $export['small-5x7'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'small-7x5';
  $picture_mapping->machine_name = 'small-7x5';
  $picture_mapping->breakpoint_group = 'small-7x5';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-7x5-lg',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-7x5-md',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-7x5-sm',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small-7x5-xs',
      ),
    ),
  );
  $export['small-7x5'] = $picture_mapping;

  return $export;
}
