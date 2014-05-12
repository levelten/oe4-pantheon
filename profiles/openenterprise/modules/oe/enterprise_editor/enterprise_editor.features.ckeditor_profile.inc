<?php
/**
 * @file
 * enterprise_editor.features.ckeditor_profile.inc
 */

/**
 * Implements hook_ckeditor_profile_defaults().
 */
function enterprise_editor_ckeditor_profile_defaults() {
  $data = array(
    'Basic' => array(
      'name' => 'Basic',
      'settings' => array(
        'ss' => 2,
        'default' => 't',
        'show_toggle' => 't',
        'uicolor' => 'default',
        'uicolor_user' => '#F0E6E6',
        'toolbar' => '[[\'Bold\',\'Italic\',\'Underline\',\'-\',\'NumberedList\',\'BulletedList\',\'-\',\'Link\',\'Unlink\',\'-\',\'Image\',\'Media\']]',
        'expand' => 't',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'allowed_content' => 't',
        'extraAllowedContent' => '',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;pre;address;h1;h2;h3;h4;h5;h6',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
            'breakBeforeClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'theme',
        'css_path' => '',
        'css_style' => 'theme',
        'styles_path' => '',
        'filebrowser' => 'none',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'forcePasteAsPlainText' => 'f',
        'html_entities' => 'f',
        'scayt_autoStartup' => 'f',
        'theme_config_js' => 'f',
        'js_conf' => '',
        'loadPlugins' => array(
          'media' => array(
            'name' => 'media',
            'desc' => 'Plugin for inserting images from Drupal media module',
            'path' => '%plugin_dir%media/',
            'buttons' => array(
              'Media' => array(
                'label' => 'Media',
                'icon' => 'images/icon.gif',
              ),
            ),
            'default' => 'f',
          ),
          'picture_ckeditor' => array(
            'name' => 'picture_ckeditor',
            'desc' => 'Support responsive images with the Picture module.',
            'buttons' => FALSE,
            'path' => '%base_path%' . drupal_get_path('module', 'picture') . '/plugins/',
            'default' => 't',
          ),
        ),
      ),
      'input_formats' => array(
        'filtered_html' => 'Filtered HTML',
      ),
    ),
    'CKEditor Global Profile' => array(
      'name' => 'CKEditor Global Profile',
      'settings' => array(
        'skin' => 'moono',
        'ckeditor_path' => '%l/ckeditor',
        'ckeditor_local_path' => '',
        'ckeditor_plugins_path' => '%m/plugins',
        'ckeditor_plugins_local_path' => '',
        'ckfinder_path' => '%l/ckfinder',
        'ckfinder_local_path' => '',
        'ckeditor_aggregate' => 'f',
        'toolbar_wizard' => 't',
        'loadPlugins' => array(),
      ),
      'input_formats' => array(),
    ),
    'Full' => array(
      'name' => 'Full',
      'settings' => array(
        'ss' => 2,
        'default' => 't',
        'show_toggle' => 't',
        'uicolor' => 'default',
        'uicolor_user' => 'default',
        'toolbar' => '[
    [\'Undo\',\'Redo\'],
    [\'Cut\',\'Copy\',\'Paste\',\'PasteText\',\'PasteFromWord\'],
    [\'SpellChecker\',\'Scayt\',\'-\',\'Find\',\'Replace\'],
    [\'ShowBlocks\',\'Maximize\',\'Source\'],
    \'/\',
    [\'Templates\',\'Blocks\',\'-\',\'Carousel\',\'Trifold\',\'Featurette\',\'Jumbotron\',\'-\',\'Link\',\'Unlink\',\'Anchor\',\'-\',\'Image\',\'video_filter\',\'-\',\'CreateDiv\',\'HorizontalRule\',\'SpecialChar\',\'-\',\'-\',\'NumberedList\',\'BulletedList\',\'-\'],
    \'/\',
    [\'Styles\',\'RemoveFormat\'],
    [\'Bold\',\'Italic\',\'Underline\',\'Strike\',\'-\',\'JustifyLeft\',\'JustifyCenter\',\'JustifyRight\',\'JustifyBlock\',\'-\',\'Outdent\',\'Indent\'],
    [\'Blockquote\',\'-\',\'Subscript\',\'Superscript\']
]',
        'expand' => 'f',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'allowed_content' => 't',
        'extraAllowedContent' => '',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;pre;address;h1;h2;h3;h4;h5;h6',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
            'breakBeforeClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'theme',
        'css_path' => '',
        'css_style' => 'theme',
        'styles_path' => '',
        'filebrowser' => 'none',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'forcePasteAsPlainText' => 'f',
        'html_entities' => 'f',
        'scayt_autoStartup' => 'f',
        'theme_config_js' => 'f',
        'js_conf' => '',
        'loadPlugins' => array(
          'blocks' => array(
            'name' => 'blocks',
            'desc' => 'Plugin for adding Drupal blocks withing CKEditor',
            'path' => '%base_path%' . drupal_get_path('module', 'ckeditor_blocks') . '/plugins/blocks/',
            'buttons' => array(
              'Blocks' => array(
                'label' => 'Block',
                'icon' => 'icons/blocks.png',
              ),
            ),
          ),
          'carousel' => array(
            'name' => 'carousel',
            'desc' => 'Bootstrap Carousel Plugin',
            'path' => '%base_path%' . drupal_get_path('module', 'ckeditor_bootstrap') . '/plugins/carousel/',
            'buttons' => array(
              'Carousel' => array(
                'label' => 'Carousel',
                'icon' => 'icons/carousel.png',
              ),
            ),
          ),
          'featurette' => array(
            'name' => 'featurette',
            'desc' => 'Bootstrap Featurette Plugin',
            'path' => '%base_path%' . drupal_get_path('module', 'ckeditor_bootstrap') . '/plugins/featurette/',
            'buttons' => array(
              'Featurette' => array(
                'label' => 'Featurette',
                'icon' => 'icons/featurette.png',
              ),
            ),
          ),
          'jumbotron' => array(
            'name' => 'jumbotron',
            'desc' => 'Bootstrap Jumbotron Plugin',
            'path' => '%base_path%' . drupal_get_path('module', 'ckeditor_bootstrap') . '/plugins/jumbotron/',
            'buttons' => array(
              'Jumbotron' => array(
                'label' => 'Jumbotron',
                'icon' => 'icons/jumbotron.png',
              ),
            ),
          ),
          'media' => array(
            'name' => 'media',
            'desc' => 'Plugin for inserting images from Drupal media module',
            'path' => '%plugin_dir%media/',
            'buttons' => array(
              'Media' => array(
                'label' => 'Media',
                'icon' => 'images/icon.gif',
              ),
            ),
            'default' => 'f',
          ),
          'mediaBrowser' => array(
            'name' => 'mediaBrowser',
            'desc' => 'Media Browser for File Upload/Browsing',
            'path' => '%base_path%' . drupal_get_path('module', 'ckeditor_media') . '/plugins/mediaBrowser/',
            'buttons' => FALSE,
          ),
          'picture_ckeditor' => array(
            'name' => 'picture_ckeditor',
            'desc' => 'Support responsive images with the Picture module.',
            'buttons' => FALSE,
            'path' => '%base_path%' . drupal_get_path('module', 'picture') . '/plugins/',
            'default' => 't',
          ),
          'trifold' => array(
            'name' => 'trifold',
            'desc' => 'Bootstrap Trifold Plugin',
            'path' => '%base_path%' . drupal_get_path('module', 'ckeditor_bootstrap') . '/plugins/trifold/',
            'buttons' => array(
              'Trifold' => array(
                'label' => 'Trifold',
                'icon' => 'icons/trifold.png',
              ),
            ),
          ),
          'video_filter' => array(
            'name' => 'video_filter',
            'desc' => 'Plugin for inserting video tags with video_filter.',
            'path' => '%base_path%' . drupal_get_path('module', 'video_filter') . '/editors/ckeditor/',
            'buttons' => array(
              'video_filter' => array(
                'icon' => 'video_filter.png',
                'label' => 'Video filter',
              ),
            ),
            'url' => 'http://drupal.org/project/video_filter',
            'load' => TRUE,
          ),
        ),
      ),
      'input_formats' => array(
        'full_html' => 'Full HTML',
      ),
    ),
  );
  return $data;
}