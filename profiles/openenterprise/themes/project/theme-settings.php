<?php

function project_form_system_theme_settings_alter(&$form, &$form_state) {

	$default_settings = array();

	$filename = DRUPAL_ROOT . '/' . drupal_get_path('theme', 'project') . '/project.info';
	$info = drupal_parse_info_file($filename);
	if (isset($info['settings'])) {
		$default_settings = $info['settings'];
	}


	$form['project'] = array(
		'#type' => 'vertical_tabs',
		'#prefix' => '<h2><small>Project</small></h2>',
		// '#weight' => -5,
	);

	$form['project_config'] = array(
		'#type' => 'fieldset',
		'#group' => 'project',
		'#title' => t('Display'),
		'#description' => t('Full width, block striping, etc.'),
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
	$form['project_config']['column_left']['project_front_container'] = array(
		'#type' => 'select',
		'#title' => t('Full Width Front Page'),
		'#default_value' => theme_get_setting('project_front_container'),
		'#description' => t('Choose to either turn the blocks on the front page into full-width containers or leave them boxed.'),
		'#options' => array(
			0 => t('Boxed'),
			1 => t('Wide'),
		),
	);
	$form['project_config']['column_left']['project_sidebars_front'] = array(
		'#type' => 'select',
		'#title' => t('Sidebars on Front'),
		'#default_value' => theme_get_setting('project_sidebars_front'),
		'#description' => t('If no, the sidebars will never be loaded on the front page. Alternatively, if sidebars are allowed and exist, the front page will never be rendered as wide.'),
		'#options' => array(
			0 => t('No'),
			1 => t('Yes'),
		),
		'#states' => array(
      'visible' => array(
        ':input[name=project_front_container]' => array('value' => 0),
      ),
    ),
	);
	$form['project_config']['column_left']['project_sidebar_column'] = array(
		'#type' => 'select',
		'#title' => t('Sidebar Column Width'),
		'#default_value' => theme_get_setting('project_sidebar_column'),
		'#description' => t('Default column width is col-sm-3, wide is col-sm-4'),
		'#options' => array(
			0 => t('Default'),
			1 => t('Wide'),
		),
	);
	
  $form['project_config']['column_right']['eb_dark_theme'] = array(
    '#type' => 'checkbox',
    '#title' => t('Dark Theme'),
    '#default_value' => theme_get_setting('eb_dark_theme'),
    '#description' => t('Adds a "theme-dark" class to the body, only affects subthemes that use it.'),
  );

	$form['project_config']['column_right']['project_block_striping'] = array(
		'#type' => 'select',
		'#title' => t('Block Striping'),
		'#default_value' => theme_get_setting('project_block_striping'),
		'#description' => t('Adds odd/even classes to blocks on the home page.'),
		'#options' => array(
			0 => t('No'),
			1 => t('Yes'),
		),
	);

	/********************* Project Javascript ***********************/
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

	/********************* Project Javascript ***********************/
	$form['project_js'] = array(
		'#type' => 'fieldset',
		'#group' => 'project',
		'#title' => t('JavaScript'),
		'#description' => t('Which JavaScript libraries or scripts to include.'),
	);

	$form['project_js']['bootstrap_hover_fieldset'] = array(
		'#type' => 'fieldset', 
		'#title' => t('Bootstrap Hover Dropdown'), 
		'#collapsible' => TRUE, 
		'#collapsed' => TRUE,
	);
	$form['project_js']['bootstrap_hover_fieldset']['bootstrap_hover_dropdown'] = array(
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

	/********************* Project CSS ***********************/
	$form['project_css'] = array(
		'#type' => 'fieldset',
		'#group' => 'project',
		'#title' => t('CSS'),
		'#description' => t('Which CSS libraries to include.'),
	);
	$form['project_css']['bootstrap_hover_fieldset'] = array(
		'#type' => 'fieldset', 
		'#title' => t('Bootstrap Hover Dropdown'), 
		'#collapsible' => TRUE, 
		'#collapsed' => TRUE,
	);
	$form['project_css']['bootstrap_hover_fieldset']['bootstrap_hover_dropdown'] = array(
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

}
