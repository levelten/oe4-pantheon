/**
* @file
* enterprise_bootstrap.js
*
* Provides general enhancements.
*/

var Drupal = Drupal || {};

(function($, Drupal){
	"use strict";

	Drupal.behaviors.enterprisebootstrap = {
		attach: function(context, settings) {

			// Run minicolors
			if ($.minicolors) {
				$.minicolors.defaults.letterCase = 'uppercase';
				$(".minicolor").minicolors();
			}

			// Get all colourlover images.
			var colourloversImages = $(".colourlovers-image", context);
			if (colourloversImages) {
				$(colourloversImages).each(function(index, el) {
					// Onclick, swap colors with LESS brand color fields.					
					$(el).click(function(event) {
						$(this).focus();
						var colors = $(el).attr('data-colors').split(",");

						for (var i = colors.length - 1; i >= 0; i--) {
							$("#edit-brand-color-"+(i+1)+".minicolor", context).minicolors('value',(colors[i]));
						}
					});
				});
			}

		}
	};

})(jQuery, Drupal);
