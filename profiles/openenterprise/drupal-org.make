api = 2
core = 7.x

;;;;;;
; Fields
;;;;;;
projects[addressfield][version] = 1.0-beta5
; Address component Views support
; http://drupal.org/node/991834
projects[addressfield][patch][991834] = https://drupal.org/files/addressfield-views_components-991834-90.patch
projects[date][version] = 2.8
projects[entityreference][version] = 1.1
projects[ffc][version] = 1.0-beta2
projects[field_delimiter][version] = 1.0
; Undefined index: field_delimiter & Undefined index: cardinality
; http://drupal.org/node/1961498
projects[field_delimiter][patch][1961498] = http://drupal.org/files/1961498-field_delimiter-undefined_indexes-1.patch
projects[field_formatter_class][version] = 1.1
projects[field_formatter_settings][version] = 1.1
projects[field_group][version] = 1.4
projects[field_word_boundary][version] = 1.0-beta3
projects[file_entity][version] = 2.x-dev
projects[filefield_sources][version] = 1.9
projects[image_url_formatter][version] = 1.4
projects[link][version] = 1.3
projects[linked_field][version] = 1.10
projects[media][version] = 2.0-alpha4
projects[options_element][version] = 1.12

;;;;;;
; Path Tools
;;;;;;
projects[globalredirect][version] = 1.5
projects[pathauto][version] = 1.2
projects[redirect][version] = 1.0-rc1
; How to fix and/or prevent circular redirects
; http://drupal.org/node/1796596
projects[redirect][patch][1796596] = https://drupal.org/files/redirect_loop_detection-1796596-68-reroll.patch
projects[transliteration][version] = 3.2

;;;;;;
; Sitebuilding tools
;;;;;;
projects[bean][version] = 1.7
projects[breakpoints][version] = 1.3
projects[blocker][version] = 1.0-beta1
projects[block_class][version] = 2.1
projects[block_row][version] = 1.0-alpha2
projects[block_views][version] = 1.0-beta2
projects[block_visibility][version] = 1.0-beta2
projects[ctools][version] = 1.5
projects[diff][version] = 3.2
projects[ds][version] = 2.7
projects[ds_bootstrap_layouts] = 3.x-dev
projects[entity][version] = 1.5
projects[entitycache][version] = 1.2
projects[exclude_node_title][version] = 1.7
projects[features][version] = 2.2
projects[icon][version] = 1.0-beta3
projects[libraries][version] = 2.x-dev
projects[menu_attributes][version] = 1.0-rc2
projects[menu_block][version] = 2.4
projects[picture][version] = 1.5
projects[strongarm][version] = 2.0
projects[token][version] = 1.5
projects[uuid][version] = 1.0-alpha6
projects[uuid_features][version] = 1.0-alpha3
projects[views][version] = 3.8
projects[views_bulk_operations][version] = 3.2
projects[views_responsive_grid][version] = 1.3
projects[webform][version] = 3.21

;;;;;;
; Text Editor
;;;;;;
projects[better_formats][version] = 1.0-beta1
projects[ckeditor][version] = 1.x-dev
projects[video_filter][version] = 3.x-dev
; video filter dialog with ckeditor standalone module is not working
; http://drupal.org/node/1689440
projects[video_filter][patch][1689440] = https://www.drupal.org/files/video_filter.code_.1434158-5.patch

;;;;;;
; UI Enhancements
;;;;;;
projects[email_registration][version] = 1.2
projects[jquery_update][version] = 2.4
projects[luxe][version] = 1.21
projects[module_filter][version] = 2.0-alpha2
projects[menu_trail_by_path][version] = 2.0
projects[realname][version] = 1.2
projects[simplified_menu_admin][version] = 1.0-beta2

;;;;;
; SEO Modules
;;;;;
projects[google_analytics][version] = 2.0
projects[metatag][version] = 1.4
projects[navigation404][version] = 1.0
projects[search404][version] = 1.3
projects[xmlsitemap][version] = 2.0-rc2

;;;;;
; Security and Performance
;;;;;
projects[memcache] = 1.0
projects[paranoia] = 1.3
projects[performance] = 2.0
projects[security_review] = 1.2
projects[varnish] = 1.0-beta2

;;;;;
; Email
;;;;;
projects[smtp] = 1.0
projects[maillog] = 1.x-dev

;;;;;
; Libraries
;;;;;
libraries[ckeditor][download][type] = file
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.3.1/ckeditor_4.3.1_full.zip
libraries[ckeditor][directory_name] = ckeditor
libraries[ckeditor][destination] = libraries

libraries[ckeditor_widget][download][type] = file
libraries[ckeditor_widget][download][url] = http://download.ckeditor.com/widget/releases/widget_4.3.1.zip
libraries[ckeditor_widget][directory_name] = widget
libraries[ckeditor_widget][destination] = libraries/ckeditor/plugins

libraries[ckeditor_lineutils][download][type] = file
libraries[ckeditor_lineutils][download][url] = http://download.ckeditor.com/lineutils/releases/lineutils_4.3.1.zip
libraries[ckeditor_lineutils][directory_name] = lineutils
libraries[ckeditor_lineutils][destination] = libraries/ckeditor/plugins

libraries[ckeditor][download][type] = file
libraries[ckeditor][download][url] = https://github.com/oyejorge/less.php/releases/download/v1.7.0.2/less.php_1.7.0.2.zip
libraries[ckeditor][directory_name] = less
libraries[ckeditor][destination] = libraries

;;;;;;
; Themes
;;;;;;
projects[bootstrap][version] = 3.0
projects[bootstrap][type] = theme
projects[tao][version] = 3.1
projects[tao][type] = theme
projects[rubik][version] = 4.x-dev
projects[rubik][type] = theme
