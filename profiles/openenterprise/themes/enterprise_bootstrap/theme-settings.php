<?php

function enterprise_bootstrap_form_system_theme_settings_alter(&$form, &$form_state) {
	$form['general']['#weight'] = -8;

	$default_settings = array();

	$filename = DRUPAL_ROOT . '/' . drupal_get_path('theme', 'enterprise_bootstrap') . '/enterprise_bootstrap.info';
	$info = drupal_parse_info_file($filename);
	if (isset($info['settings'])) {
		$default_settings = $info['settings'];
	}

	$logo_options = array('default' => "Default") + image_style_options(false);
	$form['logo']['settings']['logo_image_style'] = array(
		'#type' => 'select',
		'#title' => 'Logo Image Style',
		'#description' => t('Use an image style to change the dimensions of logo to better fit the theme.'),
		'#default_value' => theme_get_setting('logo_image_style'),
		'#options' => $logo_options,
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
	$form['enterprise_bootstrap_config']['column_right']['enterprise_bootstrap_megamenu'] = array(
		'#type' => 'select',
		'#title' => t('Mega Menu'),
		'#default_value' => theme_get_setting('enterprise_bootstrap_megamenu'),
		'#description' => t('Choose a Bootstrap mega menu.'),
		'#options' => array(
			1 => t('Enterprise Mega Menu'),
			0 => t('Bootstrap Default'),
			2 => t('YAMM'),
		),
	);
	$form['enterprise_bootstrap_config']['column_right']['enterprise_bootstrap_mobile_menu_hover_push'] = array(
		'#type' => 'select',
		'#title' => t('Mobile Menu: Hover or Push'),
		'#default_value' => theme_get_setting('enterprise_bootstrap_mobile_menu_hover_push'),
		'#description' => t('When on mobile and using a fixed navbar, choose either the menu hover over the content, or push the content down.'),
		'#options' => array(
			0 => t('Hover (default)'),
			1 => t('Push'),
		),
	);
	$form['enterprise_bootstrap_config']['column_right']['enterprise_bootstrap_mobile_dropdown'] = array(
		'#type' => 'select',
		'#title' => t('Mobile Dropdown Menu'),
		'#default_value' => theme_get_setting('enterprise_bootstrap_mobile_dropdown'),
		'#description' => t('Allow secondary dropdown menus on mobile. For example, dropdowns inside of dropdowns.'),
		'#options' => array(
			0 => t('No (default)'),
			1 => t('Yes'),
		),
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
	$form['enterprise_bootstrap_config']['column_right']['enterprise_bootstrap_blokkfont'] = array(
		'#type' => 'select',
		'#title' => t('Blokk Font'),
		'#default_value' => theme_get_setting('enterprise_bootstrap_blokkfont'),
		'#description' => t('Enables Blokk Neue as the default font. Great for testing designs.'),
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
	// We might not actually need this. Keep in for historical purposes.
	// $form['enterprise_bootstrap_region_settings']['title']['title_container'] = array(
	// 	'#type' => 'select',
	// 	'#title' => t('Title Container'),
	// 	'#default_value' => theme_get_setting('title_container'),
	// 	'#options' => array(
	// 		'container' => t('Boxed'),
	// 		'wide' => t('Wide'),
	// 	),
	// );
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

} // end settings_alter
