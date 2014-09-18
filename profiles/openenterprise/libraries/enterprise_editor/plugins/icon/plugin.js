/**
 * @license Copyright (c) 2003-2014, CKSource - Frederico Knabben. All rights reserved.
 * For licensing, see LICENSE.md or http://ckeditor.com/license
 */

/**
 * @fileOverview Special Character plugin
 */

CKEDITOR.plugins.add( 'icon', {
	// List of available localizations.
	availableLangs: { en: 1 },
	lang: 'en', // %REMOVE_LINE_CORE%
	requires: 'dialog',
	icons: 'icon', // %REMOVE_LINE_CORE%
	init: function( editor ) {
		var pluginName = 'icon',
			plugin = this;

        CKEDITOR.config.extraAllowedContent = 'i {*}(*)';

		// Register the dialog.
		CKEDITOR.dialog.add( pluginName, this.path + 'dialogs/icon.js' );

		editor.addCommand( pluginName, {
			exec: function() {
				var langCode = editor.langCode;
				langCode =
					plugin.availableLangs[ langCode ] ? langCode :
					plugin.availableLangs[ langCode.replace( /-.*/, '' ) ] ? langCode.replace( /-.*/, '' ) :
					'en';

				CKEDITOR.scriptLoader.load( CKEDITOR.getUrl( plugin.path + 'dialogs/lang/' + langCode + '.js' ), function() {
					CKEDITOR.tools.extend( editor.lang.icon, plugin.langEntries[ langCode ] );
					editor.openDialog( pluginName );
				} );
			},
			modes: { wysiwyg: 1 },
			canUndo: false
		} );

		// Register the toolbar button.
		editor.ui.addButton && editor.ui.addButton( 'icon', {
			label: editor.lang.icon.toolbar,
			command: pluginName,
			toolbar: 'insert,50'
		} );
	}
} );

/**
 * The list of special characters visible in the "Special Character" dialog window.
 *
 *		config.icons = [ '&quot;', '&rsquo;', [ '&custom;', 'Custom label' ] ];
 *		config.icons = config.icons.concat( [ '&quot;', [ '&rsquo;', 'Custom label' ] ] );
 *
 * @cfg
 * @member CKEDITOR.config
 */
 /*
CKEDITOR.config.icons = [
    ['fontello fontello oeicon-block', 'Block'],
    ['fontello oeicon-calendar', 'Calendar'],
    ['fontello oeicon-chart-area', 'Chart area']
];
*/
