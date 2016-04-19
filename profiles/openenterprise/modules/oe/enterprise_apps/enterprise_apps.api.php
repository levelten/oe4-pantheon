<?php

/**
 * @file
 * Hooks provided by the Enterprise Apps module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * The apps config settings and info work together to enable custom configuration
 * of apps & Features. They are designed to extended what can and should be done
 * with Features.
 *
 * Features should be used for site building configuration. Apps config is designed
 * to support initial configuration of content centric items such as nodes, blocks
 * and menu links.
 *
 * Config settings allows content items to be altered. They are ususally created
 * via content migration using Features, Deploy and UUID Entities.
 *
 * Config info provides data to build UI for administrators to changes settings
 * such as placing and setting visibility of blocks. Think of it this way, config
 * info builds the admin forms while config settings provides the config data.
 *
 * Note that default config info data is used to automatically set some settings
 * when a app is enabled. Thus there is some overlap between config info default
 * settings and config settings. This is designed for convience. Config settings
 * take precident, i.e. they override, config info default settings.
 *
 */

function hook_enterprise_apps_config_settings() {
  // settings are keyed, i.e. groubed by, by app name (project)
  // any module/app can add config settings to another app by using the
  // appropriate app name. Settings for a specific app will be made when
  // enterprise_apps_config_app($app_name) is executed.
  $app_name = 'enterprise_blog';
  $settings = array(
    $app_name => array(),
  );

  // ***************************
  // Entity Info config
  // Can be used to add/update field instances on entity types

  $entity_info = array();
  $entity_info['node:enterprise_blog'] = array(
    'field_instance' => array(
      // set to 1 to clone field from etmaster or etsource
      'field_cta_categories' => 1,
      'field_intel_event_col' => 1,
      'field_keywords' => 1,
      'field_page_attribute_col' => 1,
      // array will use current field or clone from etmaster/etsource and merge
      // settings in
      'field_visitor_attribute_col' => array(
        'widget' => array(
          'weight' => 10,
        )
      ),
    ),
    // copy field groups from etmaster or etsource
    // if a field group is set to 1, the group will be copied from etmaster/etsource
    // if set to 0, field will be deleted
    // if array/object is provided, that data will be used to create a new field_group
    // or will be merged into an existing field group and updated
    // and added/updated.
    'field_group' => array(
      'group_rel_label' => 1,
      'group_rel_container' => 1,
      'group_rel_subject' => 1,
    ),
  );

  $settings[$app_name]['entity_info'] = $entity_info;

  // ***************************
  // Variables config
  // variables enables data to be merged into variable settings.
  // for example, the below code will merge in enterprise_blog into the
  // disqus_nodetypes settings
  $variables = array();
  $variables['disqus_nodetypes'] = array(
    'enterprise_blog' => 'enterprise_blog',
  );

  $settings[$app_name]['variables'] = $variables;

  // *********************
  // Node config
  //
  // Enables altering of node data. Useful for adding settings not found content
  // apps. Nodes are keyed by uuid
  //

  $nodes = array();

  // adds cta category to node:b7a8...
  $nodes['b7a86778-4129-4756-84d1-5e4780436c0e'] = array(
    'field_cta_category' => array(
      'und' => array(
        0 => array(
          'tid' => '70bfeb95-e156-40eb-9b9b-283af20a9820',
        ),
      ),
    ),
  );

  // add a redirect url to a webform
  $nodes['cf3a4aa8-a24a-4bac-af77-76b77020fa1d'] = array(
    'webform' => array(
      'redirect_url' => 'thank-you/contact',
    ),
  );

  $settings[$app_name]['nodes'] = $nodes;

  // **********************
  // Menu config
  //
  // Enables altering of menu links to reorganize menus
  // Array keys use ukey formats (See uKey comments below)
  // Each entry will either add a new menu link if one does not exist or
  // alter (merge) the settings with the existing link.

  $menu = array();

  // Add/Alter a menu link with title "Home" to node with uuid:da990...
  $menu['node:da99084c-c5ee-4e6e-9e02-d11c71602daf'] = array(
    'link_title' => t('Home'),
    'weight' => -10,
  );
  // Add/Alter menu link for node uuid:42a6... change title, weight and set to expand
  $menu['node:43a64850-4c5f-4c33-8625-f058b8165e51'] = array(
    'link_title' => t('Services'),
    'weight' => -8,
    'expanded' => 1,
  );
  // Add/Alter menu link for node uuid:366d... making the link parent node:43a6...
  // This makes the "Close Sales" as sub menu item of "Services"
  $menu['node:366d1ca9-c66a-45da-bf74-d2eb65287f2e'] = array(
    'link_title' => t('Close Sales'),
    'weight' => -1,
    'pl_ukey' => 'node:43a64850-4c5f-4c33-8625-f058b8165e51', // sets parent link
  );

  // Add/alter a Resources link
  $menu['node:414da7e6-ecd5-4f51-abb6-77a2b56c6a86'] = array(
    'link_title' => t('Resources'),
    'weight' => 5,
    'expanded' => 1,
  );

  $i = 0;
  // make the page view for the enterprise_video app as sublink of the resources
  // link. app:enterprise_video is a alias for views:enterprise_video:page
  $menu['app:enterprise_video'] = array(
    'weight' => $i++,
    'pl_ukey' => 'node:414da7e6-ecd5-4f51-abb6-77a2b56c6a86',
  );

  // Add/alter menu link with the path "forum" and put it under the "Resources"
  // link
  $menu['menu_link:forum'] = array(
    'weight' => $i++,
    'pl_ukey' => 'node:414da7e6-ecd5-4f51-abb6-77a2b56c6a86',
  );

  // add menu link settings data to apply to main-menu
  $settings['enterprise_demo_content']['menus']['main-menu'] = $menu;


  // ************************
  // Blocks config
  //
  // Enables settings to be added/altered on blocks. Arrays are keyed by
  // [module]:[block delta]


  $blocks = array();
  // change the weight of the blog tags block view
  $blocks['views:enterprise_blog-tags'] = array(
    'weight' => 2,
  );

  // add the search:form block to the footer region and set the title and weight
  $blocks['search:form'] = array(
    'regions' => array(
      'footer',
    ),
    'title' => t('Search OE Pro'),
    'weight' => -3,
  );

  // set page visibility for cta:sel_cta_sidebar block
  $blocks['cta:sel_cta_sidebar'] = array(
    'path' => array(
      'pages' => array(
        '<front>',
        'admin/*',
        'user',
        'user/*',
      ),
    ),
  );

  // add cta footer block to blog content type
  $blocks['cta:sel_cta_footer'] = array(
    // set title to none
    'title' => '<none>',
    // visibility by node_type
    'node_type' => array(
      'types' => array(
        'enterprise_blog',
      ),
    ),
    // visibility by views (view_name:display_id)
    'views' => array(
      'views' => array(
        'enterprise_blog:page',
        'enterprise_blog:archives',
      ),
    // add Bootstrap margin top and bottom classes to block
    'css_class' => 'm-y-1',
    // block row settings
    'block_row' => array(
      'row' => 'row2',
      'row_class' => 'stacked',
    ),
  );

  // add blocks config data to settings array
  $settings[$app_name]['blocks'] = $blocks;

  // ************************
  // Options config
  //
  // options enable elements of apps/features to be overridden.
  $settings[$app_name]['options'] = array(
    'section_path' => 'blog', // alter the base path of app page views (alters views default)
    'section_path_node' => 'blog', // alter the base path of app nodes (alters pathauto patterns)
    'multi_author' => 1,  // FALSE or number for path slug order
    //'multi_class' => FALSE, // FALSE or number for path slug order
    'taxonomy_categories' => 'blog_categories', // change the categories vocab for the app
    'taxonomy_tags' => 'tags', // change the tags vocab for the app
  );

  return $settings;
}

/**
 * Data for building apps config forms.
 *
 * Note that default settings will be added when the app is first enabled.
 *
 *
 * @see hook_eneterpise_apps_config_settings()
 * @see hook_menu_delete()
 */
function hook_enterprise_apps_config_info() {

  // app config info is keyed by app name
  $app_name = 'enterprise_blog';
  // init config variable
  $config = array();
  // set title for config
  $config[$app_name] = array(
    'title' => t('Blog'),
  );

  // blocks config

  // define visibility presets. Presets are just a convient way to bundle block
  // settings into a group.
  $visibility = array(
    // preset name
    'enterprise_blog_view' => array(
      // title of preset shown on config app form
      'title' => t('Show on blog post listing pages'),
      // block_views visibility settings. Defines which views (view_name:display_id)
      // block will be visible when preset is selected.
      'views' => array(
        'views' => array(
          'enterprise_blog:page',
          'enterprise_blog:categories',
          'enterprise_blog:tags',
          'enterprise_blog:archives',
        ),
      ),
    ),
    // content_type visibility settings
    'enterprise_blog_content_type' => array(
      'title' => t('Show on blog post pages'),
      'node_type' => array(
        'types' => array('enterprise_blog'),
      )
    ),
  );

  // most blocks are from views. Load the view containing blocks to be configed,
  // to get a description.
  $view = views_get_view('enterprise_blog_blocks');
  $display_desc = array();
  if (!empty($view)) {
    foreach ($view->display AS $name => $display) {
      $display_desc[$name] = isset($display->display_options['display_description']) ? $display->display_options['display_description'] : '';
    }
  }

  $config[$app_name]['blocks'] = array(
    // key array using block id (module:block_delta)
    'views:enterprise_blog_blocks-categories' => array(
      'description' => $display_desc['categories'],
      'default' => array(
        'regions' => array('sidebar_second'),
        'visibility_presets' => array('enterprise_blog_view', 'enterprise_blog_content_type'),
        'weight' => -5,
      ),
      'visibility_presets' => $visibility,
    ),
    'views:enterprise_blog_blocks-tags' => array(
      'description' => $display_desc['tags'],
      'default' => array(
        'regions' => array('sidebar_second'),
        'visibility_presets' => array('enterprise_blog_view', 'enterprise_blog_content_type'),
        'weight' => -4,
      ),
      'visibility_presets' => $visibility,
    ),
    'views:enterprise_blog_blocks-archives' => array(
      'description' => $display_desc['archives'],
      'default' => array(
        'regions' => array('sidebar_second'),
        'visibility_presets' => array('enterprise_blog_view', 'enterprise_blog_content_type'),
        'weight' => -3,
      ),
      'visibility_presets' => $visibility,
    ),

    'views:enterprise_blog_blocks-recent' => array(
      'description' => $display_desc['recent'],
      'default' => array(
        'regions' => array('sidebar_second'),
        'visibility_presets' => array('enterprise_blog_view', 'enterprise_blog_content_type'),
        'weight' => 5,
      ),
      'visibility_presets' => $visibility,
    ),
    'views:enterprise_blog_blocks-popular' => array(
      'description' => $display_desc['popular'],
      'default' => array(
        'regions' => array('sidebar_second'),
        'visibility_presets' => array('enterprise_blog_view', 'enterprise_blog_content_type'),
        'weight' => 6,
      ),
      'visibility_presets' => $visibility,
    ),
    'views:enterprise_blog_blocks-related' => array(
      'description' => $display_desc['rel'],
      'default' => array(
        'regions' => array('content'),
        'visibility_presets' => array('enterprise_blog_content_type'),
        'weight' => 5,
      ),
      'visibility_presets' => $visibility,
    ),
    /**/
  );
  return $config;
}

/**
 * uKeys
 *
 * uKeys are uuid based identifiers for resources & entities. The general format
 * is:
 * entity_type:uuid or machine name
 *
 * The following are valid ukey patterns
 * node:uuid
 * node:nid
 * user:uuid
 * block:module:delta
 * views:view_name:display_id
 * app:app_name:[element]
 * - app:app_name -> loads view: app_name: page display
 * - app:app_name:page -> loads view: app_name: page display
 * - app:app_name:feed -> loads view: app_name: feed display
 * - app:app_name:categories -> loads view: app_name: category display

 */

/**
 * @} End of "addtogroup hooks".
 */
