<?php

function enterprise_bootstrap_form_system_theme_settings_alter(&$form, &$form_state) {
	$form['general']['#weight'] = -8;

	$default_settings = array();

	$filename = DRUPAL_ROOT . '/' . drupal_get_path('theme', 'enterprise_bootstrap') . '/enterprise_bootstrap.info';
	$info = drupal_parse_info_file($filename);
	if (isset($info['settings'])) {
		$default_settings = $info['settings'];
	}

  // Logo
	$logo_options = array('default' => "Default") + image_style_options(false);
	$form['logo']['settings']['logo_image_style'] = array(
		'#type' => 'select',
		'#title' => 'Logo Image Style',
		'#description' => t('Use an image style to change the dimensions of logo to better fit the theme.'),
		'#default_value' => theme_get_setting('logo_image_style'),
		'#options' => $logo_options,
	);
  $form['logo']['settings']['logo_suggestion'] = array(
    '#markup' => '<div class="description"><p>When using an Enterprise Bootstrap theme, the ideal logo dimensions is 200x75 available in the "Enterprise Bootstrap Logo" image style.</p></div>',
    '#attributes' => array('class' => array('description')),
    '#weight' => 10,
  );

	$form['enterprise_bootstrap'] = array(
		'#type' => 'vertical_tabs',
		'#prefix' => '<h2><small>Enterprise Bootstrap</small></h2>',
		'#weight' => -9,
	);

	$form['enterprise_bootstrap_config'] = array(
		'#type' => 'fieldset',
		'#group' => 'enterprise_bootstrap',
		'#title' => t('Display'),
		'#description' => t('Full width, block striping, etc.'),
		'#attributes' => array(
	    'class' => array('columns'),
	  ),
	);
	$form['enterprise_bootstrap_config']['column_left'] = array(
	  '#type' => 'container',
	  '#attributes' => array(
	    'class' => array('column-left'),
	  ),
	);
	$form['enterprise_bootstrap_config']['column_right'] = array(
	  '#type' => 'container',
	  '#attributes' => array(
	    'class' => array('column-right'),
	  ),
	);
	$form['enterprise_bootstrap_config']['column_left']['enterprise_bootstrap_front_container'] = array(
		'#type' => 'select',
		'#title' => t('Full Width Front Page'),
		'#default_value' => theme_get_setting('enterprise_bootstrap_front_container'),
		'#description' => t('Choose to either turn the blocks on the front page into full-width containers or leave them boxed.'),
		'#options' => array(
			0 => t('Boxed'),
			1 => t('Wide'),
		),
	);
	$form['enterprise_bootstrap_config']['column_left']['enterprise_bootstrap_sidebars_front'] = array(
		'#type' => 'select',
		'#title' => t('Sidebars on Front'),
		'#default_value' => theme_get_setting('enterprise_bootstrap_sidebars_front'),
		'#description' => t('If no, the sidebars will never be loaded on the front page. Alternatively, if sidebars are allowed and exist, the front page will never be rendered as wide.'),
		'#options' => array(
			0 => t('No'),
			1 => t('Yes'),
		),
		'#states' => array(
      'visible' => array(
        ':input[name=enterprise_bootstrap_front_container]' => array('value' => 0),
      ),
    ),
	);
	$form['enterprise_bootstrap_config']['column_left']['enterprise_bootstrap_sidebar_column'] = array(
		'#type' => 'select',
		'#title' => t('Sidebar Column Width'),
		'#default_value' => theme_get_setting('enterprise_bootstrap_sidebar_column'),
		'#description' => t('Default column width is col-sm-3, wide is col-sm-4'),
		'#options' => array(
			0 => t('Default'),
			1 => t('Wide'),
		),
	);
	
  $form['enterprise_bootstrap_config']['column_right']['eb_dark_theme'] = array(
    '#type' => 'checkbox',
    '#title' => t('Dark Theme'),
    '#default_value' => theme_get_setting('eb_dark_theme'),
    '#description' => t('Adds a "theme-dark" class to the body, only affects subthemes that use it.'),
  );

	$form['enterprise_bootstrap_config']['column_right']['enterprise_bootstrap_block_striping'] = array(
		'#type' => 'select',
		'#title' => t('Block Striping'),
		'#default_value' => theme_get_setting('enterprise_bootstrap_block_striping'),
		'#description' => t('Adds odd/even classes to blocks on the home page.'),
		'#options' => array(
			0 => t('No'),
			1 => t('Yes'),
		),
	);

	$form['enterprise_bootstrap_region_settings'] = array(
		'#type' => 'fieldset',
		'#group' => 'enterprise_bootstrap',
		'#title' => t('Region'),
		'#description' => t('Settings regarding the container status of each region (excluding the front page). These settings affect where they\'re placement and padding.'),
	);
	$form['enterprise_bootstrap_region_settings']['region_description'] = array(
  	'#markup' => '<div class="description"><p><ul><li><strong>Boxed:</strong> Container class added, pushes content inward.</li><li><strong>Wide:</strong> No container classes, content flows to the edge.</li></ul></p></div>',
  	'#attributes' => array('class' => array('description')),
	);

	/********************* Navigation Region Settings ***********************/
	$form['enterprise_bootstrap_region_settings']['navigation'] = array(
		'#type' => 'fieldset',
		'#group' => 'enterprise_bootstrap_region_settings',
		'#title' => t('Navigation'),
		'#collapsible' => TRUE,
    '#collapsed' => TRUE,
	);
	$form['enterprise_bootstrap_region_settings']['navigation']['navbar_region_class'] = array(
		'#type' => 'textfield',
		'#title' => t('Navigation Region Class'),
		'#default_value' => theme_get_setting('navbar_region_class'),
		'#description' => t('Class that wraps around the Logo and Menu.')
	);
	$form['enterprise_bootstrap_region_settings']['navigation']['nav_logo_class'] = array(
		'#type' => 'textfield',
		'#title' => t('Navigation Logo Wrapper Class'),
		'#default_value' => theme_get_setting('nav_logo_class'),
		'#description' => t('Class that goes on the left side of the navbar, around the logo area.')
	);
	$form['enterprise_bootstrap_region_settings']['navigation']['nav_menu_class'] = array(
		'#type' => 'textfield',
		'#title' => t('Navigation Menu Wrapper Class'),
		'#default_value' => theme_get_setting('nav_menu_class'),
		'#description' => t('Class that goes on the right side of the navbar, around the main menu area.')
	);

	/********************* Title Region Settings ***********************/
	$form['enterprise_bootstrap_region_settings']['title'] = array(
		'#type' => 'fieldset',
		'#group' => 'enterprise_bootstrap_region_settings',
		'#title' => t('Title'),
		'#collapsible' => TRUE,
    '#collapsed' => TRUE,
	);
	$form['enterprise_bootstrap_region_settings']['title']['title_placement'] = array(
		'#type' => 'select',
		'#title' => t('Title Placement'),
		'#default_value' => theme_get_setting('title_placement'),
		'#description' => t('Choose to either place this above the content/sidebars, or inside the content area.'),
		'#options' => array(
			0 => t('Above content area'),
			1 => t('Inside content area'),
		),
	);
	$form['enterprise_bootstrap_region_settings']['title']['title_class'] = array(
		'#type' => 'textfield',
		'#title' => t('Title Class'),
		'#default_value' => theme_get_setting('title_class'),
		'#description' => t('Add classes for the title region, separated by space.')
	);

	/********************* Top Bar (header) Region Settings ***********************/
	$form['enterprise_bootstrap_region_settings']['header'] = array(
		'#type' => 'fieldset',
		'#group' => 'enterprise_bootstrap_region_settings',
		'#title' => t('Top Bar (Header)'),
		'#collapsible' => TRUE,
    '#collapsed' => TRUE,
	);
	$form['enterprise_bootstrap_region_settings']['header']['header_container'] = array(
		'#type' => 'select',
		'#title' => t('Top Bar (Header) Container'),
		'#default_value' => theme_get_setting('header_container'),
		'#options' => array(
			0 => t('Boxed'),
			1 => t('Wide'),
		),
	);
	$form['enterprise_bootstrap_region_settings']['header']['header_class'] = array(
		'#type' => 'textfield',
		'#title' => t('Header Class'),
		'#default_value' => theme_get_setting('header_class'),
		'#description' => t('Add classes for the header region, separated by space.')
	);

	/********************* Highlighted Region Settings ***********************/
	$form['enterprise_bootstrap_region_settings']['highlighted'] = array(
		'#type' => 'fieldset',
		'#group' => 'enterprise_bootstrap_region_settings',
		'#title' => t('Highlighted'),
		'#collapsible' => TRUE,
    '#collapsed' => TRUE,
	);
	$form['enterprise_bootstrap_region_settings']['highlighted']['highlighted_placement'] = array(
		'#type' => 'select',
		'#title' => t('Highlighted Placement'),
		'#default_value' => theme_get_setting('highlighted_placement'),
		'#description' => t('Choose to either place this above the content/sidebars, or inside the content area.'),
		'#options' => array(
			0 => t('Above content area'),
			1 => t('Inside content area'),
		),
	);
	$form['enterprise_bootstrap_region_settings']['highlighted']['highlighted_container'] = array(
		'#type' => 'select',
		'#title' => t('Highlighted Container'),
		'#default_value' => theme_get_setting('highlighted_container'),
		'#options' => array(
			0 => t('Boxed'),
			1 => t('Wide'),
		),
	);
	$form['enterprise_bootstrap_region_settings']['highlighted']['highlighted_class'] = array(
		'#type' => 'textfield',
		'#title' => t('Highlighted Class'),
		'#default_value' => theme_get_setting('highlighted_class'),
		'#description' => t('Add classes for the highlighted region, separated by space.')
	);

	/********************* Footer Region Settings ***********************/
	$form['enterprise_bootstrap_region_settings']['footer'] = array(
		'#type' => 'fieldset',
		'#group' => 'enterprise_bootstrap_region_settings',
		'#title' => t('Footer'),
		'#collapsible' => TRUE,
    '#collapsed' => TRUE,
	);
	$form['enterprise_bootstrap_region_settings']['footer']['footer_container'] = array(
		'#type' => 'select',
		'#title' => t('Footer Container'),
		'#default_value' => theme_get_setting('footer_container'),
		'#options' => array(
			0 => t('Boxed'),
			1 => t('Wide'),
		),
	);
	$form['enterprise_bootstrap_region_settings']['footer']['footer_class'] = array(
		'#type' => 'textfield',
		'#title' => t('Footer Class'),
		'#default_value' => theme_get_setting('header_class'),
		'#description' => t('Add classes for the footer region, separated by space.')
	);

	/********************* Enterprise Bootstrap Javascript Settings ***********************/
	$form['enterprise_bootstrap_js'] = array(
		'#type' => 'fieldset',
		'#group' => 'enterprise_bootstrap',
		'#title' => t('Javascript'),
		'#description' => t('Which Javascript libraries or scripts to include.'),
	);
	$form['enterprise_bootstrap_js']['fittext_fieldset'] = array(
		'#type' => 'fieldset', 
		'#title' => t('FitText'), 
		'#collapsible' => TRUE, 
		'#collapsed' => TRUE,
	);
	$form['enterprise_bootstrap_js']['fittext_fieldset']['fittext'] = array(
		'#type' => 'select',
		'#title' => t('FitText.js'),
		'#description' => t('A jQuery plugin for inflating web type. Read the docs on !github', array('!github' => l('Github.', 'https://github.com/davatron5000/FitText.js'))),
		'#default_value' => (theme_get_setting('fittext')) ? theme_get_setting('fittext') : 0,
		'#options' => array(
			0 => t('Disabled'),
			1 => t('Production - jquery.fittext.min.js'),
			2 => t('Development - jquery.fittext.js'),
		),
		'#group' => 'fittext_fieldset',
	);
	
	$form['enterprise_bootstrap_js']['fittext_fieldset']['fittext_selectors'] = array(
		'#type' => 'container',
		'#title' => t('FitText Selectors'),
		'#group' => 'fittext_fieldset',
		'#states' => array(
      'invisible' => array(
        ':input[name=fittext]' => array('value' => 0),
      ),
    ),
	);
	$form['enterprise_bootstrap_js']['fittext_fieldset']['fittext_selectors']['fittext_description'] = array(
		'#type' => 'markup',
		'#group' => 'fittext_fieldset',
		'#markup' => '<div class="description help-block"><p>FitText will accept a compression level and selector for text you would like to update. Compression refers to how much you would like to compress the text down. Default is 1.</p>
									<p>Add in your compression and selectors as a key value pair, <strong>one per line</strong>. For example:</p>
									<p><pre>1.6|.not-logged-in #navbar .navbar-header .name</pre></p></div><br />',
		
	);

	$form['enterprise_bootstrap_js']['fittext_fieldset']['fittext_selectors']['fittext_selector'] = array(
    '#title' => t('FitText selectors'),
    '#type' => 'textarea',
    '#group' => 'fittext_fieldset',
    '#default_value' => (theme_get_setting('fittext_selector')) ? theme_get_setting('fittext_selector') : '',
    '#description' => t('Add the compression level and selectors you would like to target with FitText.'),
  );

	$form['enterprise_bootstrap_js']['bootstrap_hover_fieldset'] = array(
		'#type' => 'fieldset', 
		'#title' => t('Bootstrap Hover Dropdown'), 
		'#collapsible' => TRUE, 
		'#collapsed' => TRUE,
	);
	$form['enterprise_bootstrap_js']['bootstrap_hover_fieldset']['bootstrap_hover_dropdown'] = array(
		'#type' => 'select',
		'#title' => t('Bootstrap Hover Dropdown'),
		'#description' => t('A jQuery plugin that delays the dropdown of the menu on hover. Read the docs on !github', array('!github' => l('Github.', 'https://github.com/CWSpear/bootstrap-hover-dropdown'))),
		'#default_value' => (theme_get_setting('bootstrap_hover_dropdown')) ? theme_get_setting('bootstrap_hover_dropdown') : 0,
		'#options' => array(
			0 => t('Disabled'),
			1 => t('Production (bootstrap-hover-dropdown.min.js)'),
			2 => t('Development (bootstrap-hover-dropdown.js)'),
		),
	);

	$form['enterprise_bootstrap_js']['responsive_tabs_fieldset'] = array(
		'#type' => 'fieldset', 
		'#title' => t('Responsive Tabs'), 
		'#collapsible' => TRUE, 
		'#collapsed' => TRUE,
	);
	$form['enterprise_bootstrap_js']['responsive_tabs_fieldset']['responsive_tabs'] = array(
		'#type' => 'select',
		'#title' => t('Responsive Tabs'),
		'#description' => t('Responsive Tabs is a jQuery plugin that provides responsive tab functionality. The tabs transform to an accordion when it reaches a CSS breakpoint. Read the docs on !github', array('!github' => l('Github.', 'https://github.com/jellekralt/Responsive-Tabs'))),
		'#default_value' => (theme_get_setting('responsive_tabs')) ? theme_get_setting('responsive_tabs') : 0,
		'#options' => array(
			0 => t('Disabled'),
			1 => t('Production (jquery.responsiveTabs.min.js)'),
			2 => t('Development (jquery.responsiveTabs.js)'),
		),
	);

	$form['enterprise_bootstrap_js']['gridline_fieldset'] = array(
		'#type' => 'fieldset', 
		'#title' => t('Gridline'), 
		'#collapsible' => TRUE, 
		'#collapsed' => TRUE,
	);
	$form['enterprise_bootstrap_js']['gridline_fieldset']['gridline'] = array(
		'#type' => 'select',
		'#title' => t('Gridline.js'),
		'#description' => t('A simple and light-weight JavaScript allows for more control over grid systems in any Twitter Bootstrap 3 project. Read the docs on !github', array('!github' => l('Github.', 'https://github.com/tmaiaroto/gridline'))),
		'#default_value' => (theme_get_setting('gridline')) ? theme_get_setting('gridline') : 0,
		'#options' => array(
			0 => t('Disabled'),
			1 => t('Production (gridline.min.js)'),
			2 => t('Development (gridline.js)'),
		),
	);

	$bootstrap_default = array(
		'affix' => 0,'alert' => 1,'button' => 0,'carousel' => 1,'collapse' => 1,'dropdown' => 1,
    'modal' => 0,'tooltip' => 0,'popover' => 0,'scrollspy' => 0,'tab' => 0,'transition' => 1,
  );

	$default = (theme_get_setting('enterprise_bootstrap_js_options')) ? theme_get_setting('enterprise_bootstrap_js_options') : $default_settings['enterprise_bootstrap_js_options'];
	// need to create array where key => key. (not just true)
	foreach ($default AS $key => $value) {
		if ($value) {
			$default[$key] = $key;
		}
	}
	$form['enterprise_bootstrap_js']['bootstrap_plugins'] = array(
		'#type' => 'fieldset', 
		'#title' => t('Bootstrap Plugins'), 
		'#collapsible' => TRUE,
		'#collapsed' => TRUE,
		'#weight' => -1,
	);
	$form['enterprise_bootstrap_js']['bootstrap_plugins']['enterprise_bootstrap_js_options'] = array(
		'#type' => 'checkboxes',
		'#title' => t('Bootstrap Plugins'),
		'#group' => 'bootstrap_plugins',
		'#default_value' => $default,
		'#options' => array(
			'affix' => t('Affix'),
			'alert' => t('Alert'),
			'button' => t('Button'),
			'carousel' => t('Carousel'),
			'collapse' => t('Collapse'),
			'dropdown' => t('Dropdown'),
			'modal' => t('Modal'),
			'tooltip' => t('Tooltip'),
			'popover' => t('Popover'),
			'scrollspy' => t('Scrollspy'),
			'tab' => t('Tab'),
			'transition' => t('Transition'),
		),
	);
  $bootstrap_desc = array(
		'affix' => t('The subnavigation on the right is a live demo of the affix plugin.'),
    'alert' => t('Add dismiss functionality to all alert messages with this plugin.'),
    'button' => t('Do more with buttons. Control button states or create groups of buttons for more components like toolbars.'),
    'carousel' => t('The slideshow below shows a generic plugin and component for cycling through elements like a carousel.'),
    'collapse' => t('Get base styles and flexible support for collapsible components like accordions and navigation.'),
    'dropdown' => t('Add dropdown menus to nearly anything with this simple plugin, including the navbar, tabs, and pills.'),
    'modal' => t('Modals are streamlined, but flexible, dialog prompts with the minimum required functionality and smart defaults.'),
    'tooltip' => t('Inspired by the excellent jQuery.tipsy plugin written by Jason Frame; Tooltips are an updated version, which don\'t rely on images, use CSS3 for animations, and data-attributes for local title storage.'),
    'popover' => t('Add small overlays of content, like those on the iPad, to any element for housing secondary information.'),
    'scrollspy' => t('The ScrollSpy plugin is for automatically updating nav targets based on scroll position. Scroll the area below the navbar and watch the active class change. The dropdown sub items will be highlighted as well.'),
    'tab' => t('Add quick, dynamic tab functionality to transition through panes of local content, even via dropdown menus.'),
    'transition' => t('Transition.js is a basic helper for transitionEnd events as well as a CSS transition emulator. It\'s used by the other plugins to check for CSS transition support and to catch hanging transitions.'),
  );
	// Add descriptions
  foreach ($form['enterprise_bootstrap_js']['bootstrap_plugins']['enterprise_bootstrap_js_options']['#options'] as $key => $value) {
		$form['enterprise_bootstrap_js']['bootstrap_plugins']['enterprise_bootstrap_js_options'][$key]['#description'] = $bootstrap_desc[$key];
	}

	/********************* Enterprise Bootstrap Megamenu Settings ***********************/
	$form['enterprise_bootstrap_megamenu_config'] = array(
		'#type' => 'fieldset',
		'#group' => 'enterprise_bootstrap',
		'#title' => t('Mega Menu'),
		'#description' => t('Configurable megamenu when using the Enterprise Bootstrap page template.'),
		'#attributes' => array(
	    'class' => array('columns'),
	  ),
	);
	$form['enterprise_bootstrap_megamenu_config']['section_top'] = array(
	  '#type' => 'container',
	  '#attributes' => array(
	    'class' => array('columns'),
	  ),
	);
	$form['enterprise_bootstrap_megamenu_config']['section_middle'] = array(
	  '#type' => 'container',
	  '#attributes' => array(
	    'class' => array('columns'),
	  ),
	);
	$form['enterprise_bootstrap_megamenu_config']['section_left'] = array(
	  '#type' => 'container',
	  '#group' => 'section_middle',
	  '#attributes' => array(
	    'class' => array('column-left'),
	  ),
	);
	$form['enterprise_bootstrap_megamenu_config']['section_right'] = array(
	  '#type' => 'container',
	  '#group' => 'section_middle',
	  '#attributes' => array(
	    'class' => array('column-right'),
	  ),
	);
	$form['enterprise_bootstrap_megamenu_config']['section_bottom'] = array(
	  '#type' => 'container',
	  '#attributes' => array(
	    'class' => array('columns'),
	  ),
	);

	$form['enterprise_bootstrap_megamenu_config']['section_top']['enterprise_bootstrap_megamenu'] = array(
		'#type' => 'select',
		'#title' => t('Mega Menu'),
		'#default_value' => theme_get_setting('enterprise_bootstrap_megamenu'),
		'#description' => t('Choose a Bootstrap mega menu.'),
		'#options' => array(
			'bootstrap' => t('Bootstrap Default'),
			'enterprise' => t('Enterprise Megamenu'),
			'yamm' => t('Yamm Megamenu'),
		),
	);

	$form['enterprise_bootstrap_megamenu_config']['section_top']['enterprise_bootstrap_hide_caret'] = array(
		'#type' => 'checkbox',
		'#title' => t('Hide Caret'),
		'#default_value' => theme_get_setting('enterprise_bootstrap_hide_caret'),
		'#description' => t('Hide caret in dropdown links in the navbar.'),
	);

	$form['enterprise_bootstrap_megamenu_config']['section_right']['enterprise_bootstrap_mega_columns'] = array(
		'#type' => 'select',
		'#title' => t('Mega Menu Columns'),
		'#default_value' => theme_get_setting('enterprise_bootstrap_mega_columns'),
		'#description' => t('Number of columns in your megamenu'),
		'#options' => array(
			'col-md-12' => t('1 column'),
			'col-md-6'  => t('2 columns'),
			'col-md-4'  => t('3 columns'),
			'col-md-3'  => t('4 columns'),
			'col-md-2'  => t('6 columns'),
			'col-table' => t('Table (even width)'),
			'col-custom'=> t('None (custom)'),
		),
		'#states' => array(
      'invisible' => array(
        ':input[name=enterprise_bootstrap_megamenu]' => array('value' => 'bootstrap'),
      ),
    ),
	);
	$form['enterprise_bootstrap_megamenu_config']['section_left']['enterprise_bootstrap_dropdown'] = array(
		'#type' => 'select',
		'#title' => t('Dropdown: Toggle or Hover'),
		'#default_value' => theme_get_setting('enterprise_bootstrap_dropdown'),
		'#description' => t('Hover over a navigation link to open the menu, or tap to open. Toggle is better for mobile.'),
		'#options' => array(
			0 => t('Hover (default)'),
			1 => t('Toggle'),
		),
	);
	$form['enterprise_bootstrap_megamenu_config']['section_left']['mobile_menu_hover_push'] = array(
		'#type' => 'fieldset', 
		'#title' => t('Mobile Menu - Hover Push'), 
		'#collapsible' => FALSE, 
		'#collapsed' => FALSE,
	);
	$form['enterprise_bootstrap_megamenu_config']['section_left']['mobile_menu_hover_push']['enterprise_bootstrap_mobile_menu_hover_push'] = array(
		'#type' => 'select',
		'#title' => t('Mobile Menu: Hover or Push'),
		'#default_value' => theme_get_setting('enterprise_bootstrap_mobile_menu_hover_push'),
		'#description' => t('When on mobile and using a fixed navbar, the dropdown menu can either hover over the content, or push the content down.'),
		'#options' => array(
			0 => t('Hover over content'),
			1 => t('Push down content'),
		),
	);

	$default_mobile_menu_width = theme_get_setting('enterprise_bootstrap_mobile_menu_hover_push_width');
	$form['enterprise_bootstrap_megamenu_config']['section_left']['mobile_menu_hover_push']['enterprise_bootstrap_mobile_menu_hover_push_width'] = array(
		'#type' => 'select',
		'#title' => t('Activation Width'),
		'#description' => t('The mobile width this will activate.'),
		'#default_value' => (!empty($default_mobile_menu_width)) ? $default_mobile_menu_width : 568,
		'#options' => array(
			480 => t('480px (iPhone 4)'),
			568 => t('568px (iPhone 5)'),
			667 => t('667px (iPhone 6)'),
		),
		'#states' => array(
      'visible' => array(
        ':input[name=enterprise_bootstrap_mobile_menu_hover_push]' => array('value' => '1'),
      ),
    ),
	);

	//  We don't use this anymore, but we can keep this in as a reminder.
	// $form['enterprise_bootstrap_megamenu_config']['column_right']['enterprise_bootstrap_mobile_dropdown'] = array(
	// 	'#type' => 'select',
	// 	'#title' => t('Mobile Dropdown Menu'),
	// 	'#default_value' => theme_get_setting('enterprise_bootstrap_mobile_dropdown'),
	// 	'#description' => t('Allow secondary dropdown menus on mobile. For example, dropdowns inside of dropdowns.'),
	// 	'#options' => array(
	// 		0 => t('No (default)'),
	// 		1 => t('Yes'),
	// 	),
	// );

	$form['enterprise_bootstrap_megamenu_config']['megamenu_fieldset'] = array(
	  '#type' => 'fieldset',
	  '#group' => 'section_bottom',
	  '#title' => t('Enterprise Megamenu Options'),
	  '#collapsible' => FALSE,
	  '#collapsed' => FALSE,
	  '#states' => array(
      'visible' => array(
        ':input[name=enterprise_bootstrap_megamenu]' => array('value' => 'enterprise'),
      ),
    ),
	);
	$form['enterprise_bootstrap_megamenu_config']['megamenu_fieldset']['megamenu_left'] = array(
	  '#type' => 'container',
	  '#attributes' => array(
	    'class' => array('column-left'),
	  ),
	);
	$form['enterprise_bootstrap_megamenu_config']['megamenu_fieldset']['megamenu_right'] = array(
	  '#type' => 'container',
	  '#attributes' => array(
	    'class' => array('column-right'),
	  ),
	);

	$form['enterprise_bootstrap_megamenu_config']['megamenu_fieldset']['megamenu_left']['nav_wrapper'] = array(
		'#type' => 'select',
		'#title' => t('Nav Wrapper'),
		'#default_value' => ($nav_wrapper = theme_get_setting('nav_wrapper')) ? $nav_wrapper : 'container-fluid',
		'#options' => array(
			'container' => t('Boxed'),
			'container-fluid' => t('Fluid'),
		),
	);
	$form['enterprise_bootstrap_megamenu_config']['megamenu_fieldset']['megamenu_left']['nav_inner'] = array(
		'#type' => 'select',
		'#title' => t('Nav Inner'),
		'#default_value' => ($nav_inner = theme_get_setting('nav_inner')) ? $nav_inner : 'container',
		'#options' => array(
			'container' => t('Boxed'),
			'container-fluid' => t('Fluid'),
		),
	);
	$form['enterprise_bootstrap_megamenu_config']['megamenu_fieldset']['megamenu_right']['sticky_menu'] = array(
		'#type' => 'select',
		'#title' => t('Sticky Navbar'),
		'#description' => t('Snap navbar to the top of the page after scrolling.'),
		'#default_value' => ($sticky_menu = theme_get_setting('sticky_menu')) ? $sticky_menu : 0,
		'#options' => array(
			0 => t('No'),
			1 => t('Yes'),
		),
	);

	// Colourlovers settings
	if (module_exists('colourlovers')) {
		$form['enterprise_bootstrap_color']['colourlovers'] = array(
			'#type' => 'fieldset',
			'#title' => t('COLOURLovers Palettes'),
			'#weight' => -2,
			'#description' => t('Enter the URL below to request your palettes. You can use the !playground to get your API URL. This works with !palettes only.', array('!playground' => l('Colourlovers Playground', 'admin/appearance/colourlovers'), '!palettes' => '<strong>PALETTES</strong>')),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
		);
		
		$form['enterprise_bootstrap_color']['colourlovers']['cl_palette_mode'] = array(
			'#type' => 'select',
			'#title' => t('Palette Mode'),
			'#default_value' => theme_get_setting('cl_palette_mode'),
			'#description' => t('Choose from Top or New palettes. Random only returns one. You will need to save once to view the palettes.'),
			'#options' => array(
				'top' => t('Top'),
				'new' => t('New'),
				'random' => t('Random'),
				'custom_user' => t('Custom: Username'),
				'custom_keywords' => t('Custom: Keywords'),
			),
			'#prefix' => '<div class="inline-field">',
			'#suffix' => '</div>',
		);

		$form['enterprise_bootstrap_color']['colourlovers']['cl_palette_param'] = array(
			'#type' => 'textfield',
			'#title' => t('Parameters'),
			'#default_value' => theme_get_setting('cl_palette_param'),
			'#description' => t('If using a username, enter it here. If using keywords, you must separate each term using a comma.'),
			'#prefix' => '<div class="inline-field">',
			'#suffix' => '</div>',
			'#states' => array(
	      'visible' => array(
	        array(
	        	array(':input[name=cl_palette_mode]' => array('value' => 'custom_keywords')),
	        	'or',
	        	array(':input[name=cl_palette_mode]' => array('value' => 'custom_user')),
	        ),
	      ),
	    ),
		);

		$form['enterprise_bootstrap_color']['colourlovers']['colourlovers_container'] = array(
			'#type' => 'fieldset',
		);
		$form['enterprise_bootstrap_color']['colourlovers']['colourlovers_container']['cl_palette_options'] = array(
			'#type' => 'markup',
	  	'#markup' => variable_get('cl_palette_options', 'No palettes generated.'),
	  );
	}

	// Pictaculous settings
	if (module_exists('pictaculous')) {
		$form['enterprise_bootstrap_color']['pictaculous'] = array(
			'#type' => 'fieldset',
			'#title' => t('Pictaculous Palettes'),
			'#description' => t('You must upload an image using the !pictaculous interface, we will pull the settings from there.', array('!pictaculous' => l('Pictaculous', 'admin/config/media/pictaculous'))),
			'#weight' => -1,
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
		);

		$form['enterprise_bootstrap_color']['pictaculous']['pictaculous_object'] = array(
			'#type' => 'value',
			'#title' => t('Pictaculous Object'),
			'#value' => theme_get_setting('pictaculous_object'),
		);
		
    // Don't wait on save to provide palettes.
    $pictaculous_object = theme_get_setting('pictaculous_object');
    if (empty($pictaculous_object)) {
    	$pictaculous_object = variable_get('pictaculous_object', NULL);
    }

		if (!empty($pictaculous_object)) {
			$form['enterprise_bootstrap_color']['pictaculous']['pictaculous_container'] = array(
				'#type' => 'fieldset',
			);

			$form['enterprise_bootstrap_color']['pictaculous']['pictaculous_container']['pictaculous_options'] = array(
		    '#type' => 'markup',
				'#markup' => _enterprise_bootstrap_pictaculous($pictaculous_object),
		  );
		} else {
			drupal_set_message(t('You must upload an image to the !pictaculous admin form to generate palettes.', array('!pictaculous' => l('Pictaculous', 'admin/config/media/pictaculous'))), 'status', FALSE);
		}
	}

	// Add related CSS/JS
	$theme_path = drupal_get_path('theme', 'enterprise_bootstrap');
	$form['#attached']['css'][] = $theme_path . '/js/jquery-minicolors/jquery.minicolors.css';
	$form['#attached']['js'][] = $theme_path . '/js/jquery-minicolors/jquery.minicolors.min.js';
	$form['#attached']['js'][] = $theme_path . '/js/enterprise_bootstrap_admin.js';

	// Add form submit handler.
	$form['#validate'][] = 'enterprise_bootstrap_form_validate';

}

/*
 * Validate handler for Enterprise Bootstrap.
 */
function enterprise_bootstrap_form_validate(&$form, &$form_state) {
	$input = $form_state['values'];

	// Check for Colourlovers
  if (module_exists('colourlovers')) {
  	require_once(drupal_get_path('module', 'colourlovers') . '/colourlovers.admin.inc');
		if (!empty($input['cl_palette_mode'])) {
  		variable_set('cl_palette_options', _enterprise_bootstrap_colourlovers($input['cl_palette_mode'], $input['cl_palette_param']));
  	}  	
  }

  // Check for Pictaculous
  if (module_exists('pictaculous')) {
  	// Get value from Pictaculous.
  	$pictaculous_object = variable_get('pictaculous_object', NULL);

		$pictaculous_theme = $form['enterprise_bootstrap_color']['pictaculous']['pictaculous_object'];
		// If FID's don't match, grab newest info.
		if (isset($pictaculous_theme['fid'])) {
			if ($pictaculous_theme['fid'] != $pictaculous_object['fid']) {
				form_set_value($form['enterprise_bootstrap_color']['pictaculous']['pictaculous_object'], $pictaculous_object, $form_state);
			}
		} else {
			form_set_value($form['enterprise_bootstrap_color']['pictaculous']['pictaculous_object'], $pictaculous_object, $form_state);
		}
  }
}

/**
 * Generate palettes from COLOURLovers.
 */
function _enterprise_bootstrap_colourlovers($mode = 'top', $param = NULL) {
	// Set up API call and palettes.
	$params = array();
	if ($mode == 'custom_user') {
		if (empty($param)) {
			form_set_error('cl_palette_param', t('You must enter a username when using Custom: Username.'));
		}
		$params['lover'] = $param;
	} elseif ($mode == 'custom_keywords') {
		if (empty($param)) {
			form_set_error('cl_palette_param', t('You must enter some keywords when using Custom: Keywords.'));
		}
		$params['keywords'] = _colourlovers_format_keyword($param);
	}

	$palettes = _colourlovers_method('palettes', $mode, 20, $params);
	$badge = array();

	if (!empty($palettes)) {
		foreach ($palettes as $key => $value) {
			// If using palettes, set up Color module palette.
			if (count($value->colors) < 5) {
				continue;
			}
			$theme_palette[$value->id] = array(
				'title' => t($value->title),
				'colors' => $value->colors,
			);
			// Set up badge images.
			$image_vars = array(
				'path' => $value->badgeUrl,
				'alt' => $value->url,
				'title' => t($value->title),
				'attributes' => array(
					'style' => '',
				),
			);

			$wrapper_attributes = array(
				'class' => array('colourlovers-image'),
				'data-colors' => array(implode(',', $value->colors)),
			);

			$badge[] = '<div '. drupal_attributes($wrapper_attributes).'>'.theme_image($image_vars).'</div>';
		}
		$badges = '<div class="colourlovers-images">'.implode('', $badge).'</div>';
		return $badges;
	}
}

/**
 * Generate palettes from Pictaculous.
 */
function _enterprise_bootstrap_pictaculous($object) {
	$output = '';

	if (is_array($object) && !empty($object)) {
		foreach ($object as $key => $value) {
			if (is_array($value) || is_object($value)) {

				switch ($key) {

					case 'info':
						$value->fid = $object['fid'];
						$value->title = $object['title'];
						$element = array(
							'#title' => t('Pictaculous: Image'),
							'#description' => t('The palette returned based on the image supplied.'),
							'#children' => theme('pictaculous_info', array('object' => $value)),
						);
						$output .= theme('fieldset', array('element' => $element));
						break;

					case 'kuler_themes':
						$element = array(
							'#title' => t('Pictaculous: Adobe Kuler'),
							'#description' => t('Suggestions supplied by Adober Kuler.'),
							'#children' => theme('pictaculous_kuler', array('object' => $value)),
						);
						$output .= theme('fieldset', array('element' => $element));
					break;

					case 'cl_themes':
						$element = array(
							'#title' => t('Pictaculous: COLOURLovers'),
							'#description' => t('Suggestions supplied by COLOURLovers.'),
							'#children' => theme('pictaculous_colour', array('object' => $value)),
						);
						$output .= theme('fieldset', array('element' => $element));
					break;
					
				}
			}
		}
	}
	return $output;
}
