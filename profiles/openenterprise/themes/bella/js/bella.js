/**
 * @file
 * bella.js
 *
 * Provides general enhancements.
 */

 var Drupal = Drupal || {};

 (function($, Drupal){
  "use strict";

  Drupal.behaviors.bellaThemeFixes = {
    attach: function(context) {

      // Add margin depending on height of navbar.
			var navbar = $(".not-logged-in #navbar", context);
			$(".main-container").css('margin-top', navbar.height()+'px');
			$(window).resize(function(){
				$(".main-container").css('margin-top', navbar.height()+'px');
      });

    }
  };

})(jQuery, Drupal);
