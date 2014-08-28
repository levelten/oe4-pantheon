<?php

function enterprise_bootstrap_form_system_theme_settings_alter(&$form, &$form_state) {
	$form['general']['#weight'] = -8;

	$form['enterprise_bootstrap'] = array(
		'#type' => 'vertical_tabs',
		'#prefix' => '<h2><small>Enterprise Bootstrap</small></h2>',
		'#weight' => -9,
	);

	$form['enterprise_bootstrap_config'] = array(
		'#type' => 'fieldset',
		'#group' => 'enterprise_bootstrap',
		'#title' => t('Display settings'),
		'#description' => t('Full width, block striping, etc.'),
	);
	$form['enterprise_bootstrap_config']['enterprise_bootstrap_front_blocks'] = array(
		'#type' => 'select',
		'#title' => t('Front Block Striping'),
		'#options' => array(
			0 => t('No'),
			1 => t('Yes'),
		),
		'#default_value' => theme_get_setting('enterprise_bootstrap_front_blocks'),
		'#description' => t('If Yes, this will turn the blocks on the front page into full-width containers for horizontal striping.'),
	);
	$form['enterprise_bootstrap_config']['enterprise_bootstrap_blokkfont'] = array(
		'#type' => 'select',
		'#title' => t('Blokk Font'),
		'#options' => array(
			0 => t('No'),
			1 => t('Yes'),
		),
		'#default_value' => theme_get_setting('enterprise_bootstrap_blokkfont'),
		'#description' => t('Enables Blokk Neue as the default font. Great for testing designs.'),
	);

	$form['enterprise_bootstrap_js'] = array(
		'#type' => 'fieldset',
		'#group' => 'enterprise_bootstrap',
		'#title' => t('Bootstrap JavaScript'),
		'#description' => t('Which Bootstrap JS files to include.'),
	);
	$form['enterprise_bootstrap_js']['enterprise_bootstrap_js_options'] = array(
		'#type' => 'checkboxes',
		'#title' => t('Bootstrap Javascript'),
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
		'#default_value' => theme_get_setting('enterprise_bootstrap_js_options'),
	);

    $js_desc = array(
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
    foreach ($form['enterprise_bootstrap_js']['enterprise_bootstrap_js_options']['#options'] as $key => $value) {
             $form['enterprise_bootstrap_js']['enterprise_bootstrap_js_options'][$key]['#description'] = $js_desc[$key];
    }
 }
