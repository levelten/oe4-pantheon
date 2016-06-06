<?php

/**
 * Include common functions used through out theme.
 */
include_once dirname(__FILE__) . '/theme/slider.inc';

function project_form_system_theme_settings_alter(&$form, &$form_state) {

  $default_settings = array();

  $filename = DRUPAL_ROOT . '/' . drupal_get_path('theme', 'project') . '/project.info';
  $info = drupal_parse_info_file($filename);
  if (isset($info['settings'])) {
    $default_settings = $info['settings'];
  }

  // Add checkbox for Search if enabled.
  if (module_exists('search')) {
    $form['theme_settings']['toggle_search'] = array(
      '#type' => 'checkbox',
      '#title' => t('Search'),
      '#default_value' => theme_get_setting('toggle_search'),
    );
  }

  $form['project'] = array(
    '#type' => 'vertical_tabs',
    '#prefix' => '<h2><small>Project</small></h2>',
    '#weight' => -8,
  );

  $form['project_config'] = array(
    '#type' => 'fieldset',
    '#group' => 'project',
    '#title' => t('Display'),
    '#attributes' => array(
      'class' => array('columns'),
    ),
  );
  $form['project_config']['column_left'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('column-left'),
    ),
  );
  $form['project_config']['column_right'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('column-right'),
    ),
  );
  $form['project_config']['column_left']['layout_style'] = array(
    '#type' => 'select',
    '#title' => t('Layout Style'),
    '#default_value' => theme_get_setting('layout_style'),
    '#description' => t('Wide or boxed.'),
    '#options' => array(
      0 => t('Wide'),
      1 => t('Boxed'),
    ),
  );
  $form['project_config']['column_left']['pattern'] = array(
    '#type' => 'select',
    '#title' => t('Background Pattern'),
    '#default_value' => theme_get_setting('pattern'),
    '#description' => t('Background patterns are available only in boxed layout mode.'),
    '#options' => array(
      0 => t('None'),
      'pattern-1' => t('Pattern 1'),
      'pattern-2' => t('Pattern 2'),
      'pattern-3' => t('Pattern 3'),
      'pattern-4' => t('Pattern 4'),
      'pattern-5' => t('Pattern 5'),
      'pattern-6' => t('Pattern 6'),
      'pattern-7' => t('Pattern 7'),
      'pattern-8' => t('Pattern 8'),
      'pattern-9' => t('Pattern 9'),
    ),
    '#states' => array(
      'invisible' => array(
        ':input[name="layout_style"]' => array('value' => 0),
      ),
    ),
  );

  $form['project_config']['column_left']['pattern_fixed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fixed Pattern'),
    '#default_value' => theme_get_setting('pattern_fixed'),
    '#description' => t('Fix the background pattern so it doesn\'t scroll with the screen.'),
    '#states' => array(
      'invisible' => array(
        ':input[name="layout_style"]' => array('value' => 0),
      ),
    ),
  );

  /********************* Project Regions ***********************/
  $form['project_regions'] = array(
    '#type' => 'fieldset',
    '#group' => 'project',
    '#title' => t('Regions'),
    '#description' => t('Settings for different regions.'),
  );

  $form['project_regions']['header_top'] = array(
    '#type' => 'fieldset',
    '#title' => t('Header Top'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['project_regions']['header_top']['header_top_color'] = array(
    '#type' => 'select',
    '#title' => t('Header Top Color'),
    '#description' => t('Change the color of the header top section.'),
    '#default_value' => (theme_get_setting('header_top_color')) ? theme_get_setting('header_top_color') : 'no-color',
    '#options' => array(
      'no-color' => t('Default (no-color)'),
      'dark' => t('Dark'),
      'colored' => t('Colored'),
    ),
  );
  $form['project_regions']['header_top']['header_top_class'] = array(
    '#type' => 'select',
    '#title' => t('Header Top Menu Width'),
    '#description' => t('Change the width of the menu section.'),
    '#default_value' => (theme_get_setting('header_top_class')) ? theme_get_setting('header_top_class') : 'small',
    '#options' => array(
      'small' => t('Small'),
      'medium' => t('Medium'),
      'large' => t('Large'),
      'even' => t('Even (50:50)'),
    ),
  );

  $form['project_regions']['header'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Header'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['project_regions']['header']['header_sticky'] = array(
    '#type' => 'select',
    '#title' => t('Header Sticky'),
    '#description' => t('Change stickiness of header region.'),
    '#default_value' => (theme_get_setting('header_sticky')) ? theme_get_setting('header_sticky') : 'fixed',
    '#options' => array(
      'fixed' => t('Fixed (default)'),
      'static' => t('Static'),
    ),
  );
  $form['project_regions']['header']['navbar_actions'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Navbar Actions'),
    '#description' => t('Change actions of navigation bar.'),
    '#default_value' => (theme_get_setting('navbar_actions')) ? theme_get_setting('navbar_actions') : '',
    '#options' => array(
      'onclick' => t('OnClick'),
      'animated' => t('Animated'),
    ),
  );
  $form['project_regions']['header']['navbar_transparent'] = array(
    '#type' => 'checkbox',
    '#title' => t('Transparent Navbar'),
    '#description' => t('Make the navbar transparent.'),
    '#default_value' => (theme_get_setting('navbar_transparent')) ? theme_get_setting('navbar_transparent') : 0,
  );

  $form['project_regions']['main_content'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Main Content'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['project_regions']['main_content']['page_title_separator'] = array(
    '#type' => 'select',
    '#title' => t('Page Title Separator'),
    '#description' => t('Adds a separator below the page title.'),
    '#default_value' => (theme_get_setting('page_title_separator')) ? theme_get_setting('page_title_separator') : 0,
    '#options' => array(
      1 => t('None'),
      2 => t('Left to Right'),
      3 => t('Right to Left'),
    ),
  );

  $form['project_regions']['footer'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Footer'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['project_regions']['footer']['footer_dark'] = array(
    '#type' => 'select',
    '#title' => t('Footer Dark'),
    '#description' => t('Add dark class to footer.'),
    '#default_value' => (theme_get_setting('footer_dark')) ? theme_get_setting('footer_dark') : 0,
    '#options' => array(
      'light' => t('Light (default)'),
      'dark' => t('Dark'),
    ),
  );

  /********************* Project Plugins ***********************/
  $form['project_plugins'] = array(
    '#type' => 'fieldset',
    '#group' => 'project',
    '#title' => t('Plugins'),
    '#description' => t('Additional libraries to enhance the theme.'),
  );
  $form['project_plugins']['animate'] = array(
    '#type' => 'select',
    '#title' => t('Animate.css'),
    '#description' => t('Plug and play, app-like animations for your websites and web apps. Read the docs on !github', array('!github' => l('Github.', 'https://daneden.github.io/animate.css/'))),
    '#default_value' => (theme_get_setting('animate')) ? theme_get_setting('animate') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (animate.min.css)'),
      2 => t('Development (animate.css)'),
      3 => t('CDN'),
    ),
  );
  $form['project_plugins']['morphext'] = array(
    '#type' => 'select',
    '#title' => t('Morphext'),
    '#description' => t('The simplest text rotator powered by jQuery and Animate.css. Read the docs on their !site', array('!site' => l('site.', 'http://morphext.fyianlai.com/'))),
    '#default_value' => (theme_get_setting('morphext')) ? theme_get_setting('morphext') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (morphext.min.js)'),
      2 => t('Development (morphext.min.js)'),
    ),
    '#states' => array(
      'invisible' => array(
        ':input[name="animate"]' => array('value' => 0),
      ),
    ),
  );

  $form['project_plugins']['bootstrap_notify'] = array(
    '#type' => 'select',
    '#title' => t('Bootstrap Notify'),
    '#description' => t('A jQuery plugin helps to turn standard bootstrap alerts into "growl" like notifications. Read the docs on their !site', array('!site' => l('site.', 'http://bootstrap-notify.remabledesigns.com/'))),
    '#default_value' => (theme_get_setting('bootstrap_notify')) ? theme_get_setting('bootstrap_notify') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (bootstrap-notify.min.js)'),
      2 => t('Development (bootstrap-notify.js)'),
    ),
  );
  $form['project_plugins']['chartjs'] = array(
    '#type' => 'select',
    '#title' => t('Chart.js'),
    '#description' => t('Simple, clean and engaging charts for designers and developers. Read the docs on their !site', array('!site' => l('site.', 'http://www.chartjs.org/docs/'))),
    '#default_value' => (theme_get_setting('chartjs')) ? theme_get_setting('chartjs') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (Chart.min.js)'),
      2 => t('Development (Chart.js)'),
      3 => t('CDN'),
    ),
  );
  $form['project_plugins']['fontawesome'] = array(
    '#type' => 'select',
    '#title' => t('Font Awesome'),
    '#description' => t('Font Awesome gives you scalable vector icons that can instantly be customized — size, color, drop shadow, and anything that can be done with the power of CSS. Read the docs on !github', array('!github' => l('Github.', 'https://fortawesome.github.io/Font-Awesome'))),
    '#default_value' => (theme_get_setting('fontawesome')) ? theme_get_setting('fontawesome') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (font-awesome.min.css)'),
      2 => t('Development (font-awesome.css)'),
      3 => t('CDN'),
    ),
  );
  $form['project_plugins']['jquery_knob'] = array(
    '#type' => 'select',
    '#title' => t('jQuery Knob'),
    '#description' => t('Nice, downward compatible, touchable, jQuery dial. Read the docs on !github', array('!github' => l('Github.', 'https://github.com/aterrien/jQuery-Knob'))),
    '#default_value' => (theme_get_setting('jquery_knob')) ? theme_get_setting('jquery_knob') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (jQuery.knob.min.js)'),
      2 => t('Development (jQuery.knob.js)'),
      3 => t('CDN'),
    ),
  );
  $form['project_plugins']['jquery_browser'] = array(
    '#type' => 'select',
    '#title' => t('jQuery Browser'),
    '#description' => t('A jQuery plugin for browser detection. jQuery v1.9.1 dropped support for browser detection, and this project aims to keep the detection up-to-date. Read the docs on !github', array('!github' => l('Github.', 'https://github.com/gabceb/jquery-browser-plugin'))),
    '#default_value' => (theme_get_setting('jquery_browser')) ? theme_get_setting('jquery_browser') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (jquery.browser.min.js)'),
      2 => t('Development (jquery.browser.js)'),
      3 => t('CDN'),
    ),
  );
  $form['project_plugins']['jquery_validate'] = array(
    '#type' => 'select',
    '#title' => t('jQuery Validate'),
    '#description' => t('The jQuery Validation Plugin provides drop-in validation for your existing forms, while making all kinds of customizations to fit your application really easy. Read the docs on !github', array('!github' => l('Github.', 'https://github.com/jzaefferer/jquery-validation'))),
    '#default_value' => (theme_get_setting('jquery_browser')) ? theme_get_setting('jquery_browser') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (jquery.validate.min.js)'),
      2 => t('Development (jquery.validate.js)'),
      3 => t('CDN'),
    ),
  );
  $form['project_plugins']['jquery_validate_add'] = array(
    '#type' => 'checkbox',
    '#title' => t('jQuery Validate - Additional Methods'),
    '#description' => t('Some more methods are provided as add-ons, and are currently included in additional-methods.js in the download package. Read the docs on !site', array('!site' => l('their site.', 'http://jqueryvalidation.org/documentation/'))),
    '#default_value' => (theme_get_setting('jquery_browser')) ? theme_get_setting('jquery_browser') : 0,
    '#states' => array(
      'invisible' => array(
        ':input[name="jquery_validate"]' => array('value' => 0),
      ),
    ),
  );
  $form['project_plugins']['hover_css'] = array(
    '#type' => 'select',
    '#title' => t('Hover.css'),
    '#description' => t('A collection of CSS3 powered hover effects to be applied to links, buttons, logos, SVG, featured images and so on. Read the docs on !github', array('!github' => l('Github.', 'https://github.com/IanLunn/Hover'))),
    '#default_value' => (theme_get_setting('hover_css')) ? theme_get_setting('hover_css') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (hover.min.css)'),
      2 => t('Development (hover.css)'),
      3 => t('CDN'),
    ),
  );
  $form['project_plugins']['maplace'] = array(
    '#type' => 'select',
    '#title' => t('Maplace.js'),
    '#description' => t('Google Maps jQuery plugin and markers helper. Read the docs on !github', array('!github' => l('Github.', 'https://github.com/danielemoraschi/maplace.js'))),
    '#default_value' => (theme_get_setting('maplace')) ? theme_get_setting('maplace') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (maplace.min.js)'),
      2 => t('Development (maplace.js)'),
      2 => t('CDN'),
    ),
  );
  $form['project_plugins']['pacejs'] = array(
    '#type' => 'select',
    '#title' => t('Vide'),
    '#description' => t('Automatically add a progress bar to your site. Read the docs on !github', array('!github' => l('Github.', 'https://github.com/HubSpot/PACE'))),
    '#default_value' => (theme_get_setting('pacejs')) ? theme_get_setting('pacejs') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (pace.min.js)'),
      2 => t('Development (pace.js)'),
      3 => t('CDN'),
    ),
  );
  $form['project_plugins']['vide'] = array(
    '#type' => 'select',
    '#title' => t('Vide'),
    '#description' => t('Easy as hell jQuery plugin for video backgrounds. Read the docs on !github', array('!github' => l('Github.', 'http://vodkabears.github.io/vide/'))),
    '#default_value' => (theme_get_setting('vide')) ? theme_get_setting('vide') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (jquery.vide.min.js)'),
      2 => t('Development (jquery.vide.js)'),
    ),
  );
  $form['project_plugins']['waypoints'] = array(
    '#type' => 'select',
    '#title' => t('Waypoints'),
    '#description' => t('Waypoints is a library that makes it easy to execute a function whenever you scroll to an element. Read the docs on !github', array('!github' => l('Github.', 'https://github.com/imakewebthings/waypoints'))),
    '#default_value' => (theme_get_setting('waypoints')) ? theme_get_setting('waypoints') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (jquery.waypoints.min.js)'),
      2 => t('Development (jquery.waypoints.js)'),
      3 => t('CDN'),
    ),
  );
  $form['project_plugins']['jasny'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Jasny Bootstrap'),
    '#description' => t('Jasny Bootstrap is an extension to vanilla Bootstrap, adding a number of features and components. Read the docs on !site', array('!site' => l('Jasny.net.', 'http://www.jasny.net/bootstrap/getting-started/'))),
    '#collapsible' => FALSE,
  );
  $form['project_plugins']['jasny']['jasny_css'] = array(
    '#type' => 'select',
    '#title' => t('Jasny CSS'),
    '#default_value' => (theme_get_setting('jasny_css')) ? theme_get_setting('jasny_css') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (jasny-bootstrap.min.css)'),
      2 => t('Development (jasny-bootstrap.css)'),
      3 => t('CDN'),
    ),
  );
  $form['project_plugins']['jasny']['jasny_js'] = array(
    '#type' => 'select',
    '#title' => t('Jasny JS'),
    '#default_value' => (theme_get_setting('jasny_js')) ? theme_get_setting('jasny_js') : 0,
    '#options' => array(
      0 => t('Disabled'),
      1 => t('Production (jasny-bootstrap.min.js)'),
      2 => t('Development (jasny-bootstrap.js)'),
      3 => t('CDN'),
    ),
  );

  /********************* Visual Enhancments ***********************/
  $form['project_visual'] = array(
    '#type' => 'fieldset',
    '#group' => 'project',
    '#title' => t('Visual Enhancements'),
    '#description' => t('Variety of visual enhancements like animations, classes, etc.'),
  );

  $form['project_visual']['column_left'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('column-left'),
    ),
  );
  $form['project_visual']['column_right'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('column-right'),
    ),
  );

  $form['project_visual']['column_left']['social_media'] = array(
    '#type' => 'fieldset',
    '#title' => t('Social Media Links'),
  );
  $form['project_visual']['column_left']['social_media']['social_media_links'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Social Media Links'),
    '#description' => t('Add extra classes to alter the display of social media links.'),
    '#default_value' => (theme_get_setting('social_media_links')) ? theme_get_setting('social_media_links') : NULL,
    '#options' => array(
      'default' => t('Default'),
      'small' => t('Small'),
      'large' => t('Large'),
      'circle' => t('Circle'),
      'square' => t('Square'),
      'colored' => t('Colored'),
      'dark' => t('Dark'),
      'animated-effect-1' => t('Animated'),
    ),
  );
  $form['project_visual']['column_right']['colorize'] = array(
    '#type' => 'checkbox',
    '#title' => t('Colorize Theme'),
    '#default_value' => theme_get_setting('colorize'),
    '#description' => t('Use colors defined to skin the theme.'),
  );
  $form['project_visual']['column_right']['back_to_top'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add \'back to top\' arrow'),
    '#default_value' => theme_get_setting('back_to_top'),
    '#description' => t('Adds an \'up arrow\' fixed at the bottom of the screen that users can click on to smooth scroll back to the top of the page. Arrow only appears on scrolling down the page.'),
  );

  
  /********************* Slideshow ***********************/
  $form['project_slider'] = array(
    '#type' => 'fieldset',
    '#group' => 'project',
    '#title' => t('Slideshow Banner'),
    '#description' => t('Add a custom slideshow to the home page banner. Start by uploading an image and saving the theme settings form.'),
  );

  $form['project_slider']['add_more'] = array(
    '#type' => 'button',
    '#value' => t('Add More'),
    '#ajax' => array(
      'callback' => 'ajax_simplest_callback',
      'wrapper' => 'replace-this',
      'method' => 'replace',
     ),
  );

  $form['project_slider']['banners'] = array(
    '#type' => 'fieldset',
    '#title' => t('Banners'),
    '#prefix' => '<div id="replace-this">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
  );

  // build the initial field if this is not being rebuilt 
  // from ajax request
  
  if (!array_key_exists('clicked_button', $form_state)) {

    $form['project_slider']['banners'][0] = array('#type' => 'fieldset');
    $form['project_slider']['banners'][0]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#parents' => array('banners'),
    );
    $form['project_slider']['banners'][0]['banner_image'] = array(
      '#type' => 'managed_file',
      '#name' => 'project_slider_image',
      '#title' => t('Background Image'),
      // '#default_value' => $form['project_slider']['banners'][0]['banner_image'],
      '#description' => t("Upload an image to be processed."),
      '#parents' => array('banners'),
      '#upload_location' => file_default_scheme() . '://theme/project_banner/',
      '#upload_validators' => array(
        'file_validate_extensions' => array('gif png jpg jpeg'),
      ),
    );
    $form['project_slider']['banners'][0]['delete'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete'),
      '#description' => t('When saving the theme settings, this slide will be deleted.'),
    );
  } else {
    // otherwise add the fields for each existing value
    foreach ($form_state['input']['banners'] as $i => $value) {
      $form['project_slider']['banners'][$i] = array('#type' => 'fieldset');
      $form['project_slider']['banners'][$i]['title'] = array(
        '#type' => 'textfield',
        '#title' => t('Title'),
        '#default_value' => $form_state['input']['banners'][$i]['title'],
      );
      $form['project_slider']['banners'][$i]['banner_image'] = array(
        '#type' => 'managed_file',
        '#name' => 'project_slider_image',
        '#title' => t('Background Image'),
        '#default_value' => $form['project_slider']['banners'][$i]['banner_image'],
        '#description' => t("Upload an image to be processed."),
        '#upload_location' => file_default_scheme() . '://theme/project_banner/',
        '#upload_validators' => array(
          'file_validate_extensions' => array('gif png jpg jpeg'),
        ),
      );
      $form['project_slider']['banners'][$i]['delete'] = array(
        '#type' => 'checkbox',
        '#title' => t('Delete'),
        '#description' => t('When saving the theme settings, this slide will be deleted.'),
      );
    }

    // add the additional field for a new entry
    $last = count($form_state['input']['banners']);
    $form['project_slider']['banners'][$last] = array('#type' => 'fieldset');
    $form['project_slider']['banners'][$last]['title'] = array(
        '#type' => 'textfield',
        '#title' => t('title'),
    );
    $form['project_slider']['banners'][$last]['banner_image'] = array(
      '#type' => 'managed_file',
      '#name' => 'project_slider_image',
      '#title' => t('Background Image'),
      '#default_value' => $form['project_slider']['banners'][$last]['banner_image'],
      '#description' => t("Upload an image to be processed."),
      '#upload_location' => file_default_scheme() . '://theme/project_banner/',
      '#upload_validators' => array(
        'file_validate_extensions' => array('gif png jpg jpeg'),
      ),
    );
    $form['project_slider']['banners'][$last]['delete'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete'),
      '#description' => t('When saving the theme settings, this slide will be deleted.'),
    );
  }

  // $form['#submit'][] = 'project_form_submit';

}

function ajax_simplest_callback($form, &$form_state) {
  dpm($form);
  return $form['project_slider']['banners'];
}

function project_form_submit($form, &$form_state) {
  dpm($form);
  dpm($form_state);
}
