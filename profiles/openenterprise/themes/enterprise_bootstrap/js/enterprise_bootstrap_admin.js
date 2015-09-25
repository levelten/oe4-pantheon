/**
* @file
* enterprise_bootstrap_admin.js
*
* Provides general enhancements to the admin theme.
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

			// Get default theme name and color palettes.
			var themes = settings.enterprise_theme.themes,
					colourloversImages = $(".colourlovers-image", context);

			if (colourloversImages) {
				$(colourloversImages).each(function(index, el) {
					// Onclick, swap colors with LESS brand color fields.					
					$(el).click(function(event) {
						$(this).focus();
						// Split data-colors into array.
						var colors = $(el).attr('data-colors').split(",");
						// Loop through colors.
						for (var i = colors.length - 1; i >= 0; i--) {
							// Account for themes that aren't set as default, loop through active themes.
							for (var t = themes.length - 1; t >= 0; t--) {
								// Replace underscores with hyphens.
								var theme_name = themes[t].replace(/[_]/g, "-");
								switch (i) {
									case 0:
										$("#edit-less-"+theme_name+"-brand-primary.minicolor", context).minicolors('value',(colors[i])).attr('value', '#'+colors[i]);
										break;
									case 1:
										$("#edit-less-"+theme_name+"-brand-secondary.minicolor", context).minicolors('value',(colors[i])).attr('value', '#'+colors[i]);
										break;
									case 2:
										$("#edit-less-"+theme_name+"-brand-accent.minicolor", context).minicolors('value',(colors[i])).attr('value', '#'+colors[i]);
										break;
									case 3:
										$("#edit-less-"+theme_name+"-brand-accent-2.minicolor", context).minicolors('value',(colors[i])).attr('value', '#'+colors[i]);
										break;
									case 4:
										$("#edit-less-"+theme_name+"-brand-accent-3.minicolor", context).minicolors('value',(colors[i])).attr('value', '#'+colors[i]);
										break;
								}
							}
						}
					});
				});

				// Add reset to default functionality for LESS colors.
				$(themes).each(function(index, el) {
					// Replace underscores with hyphens.
					var theme_name = el.replace(/[_]/g, "-");
					var variables = $(".less-theme-settings input[id^='edit-less-"+theme_name+"'", context);

					if (variables.length > 0) {
						// Click reset
						$("#edit-less-"+theme_name+"-reset", context).click(function(event) {
							event.preventDefault();
							// For each variable, reset to default placeholder value.
							$(variables).each(function(index, el) {
								var defaultColor = $(el).attr("placeholder");
								$(el).minicolors('value', defaultColor).attr('value', defaultColor);
							});

						});
					}
				});
			}
		}
	};

})(jQuery, Drupal);
