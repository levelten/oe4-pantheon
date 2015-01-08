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

      // Add wrapper to Google Map iframes
      var iframes = $("iframe", context);
      if (iframes) {
        iframes.each(function() {
          var url = ($(this)[0].src) ? $(this)[0].src : "";
          if (url.toLowerCase().indexOf("google.com/maps") > 0) {
            $(this).wrap( "<div class='google-maps'></div>" );
          }
        });
      }

      // Use fitText if loaded.
      if(jQuery.fn.fitText) {
        // Apply fitText to selectors if available.
        var selectors = (settings.enterprise_bootstrap.fittext) ? settings.enterprise_bootstrap.fittext : false;
        if (selectors) {
          for (var i = selectors.length - 1; i >= 0; i--) {
            $(selectors[i][1], context).fitText(selectors[i][0]);
          }
        }
      }

      // Add bootstrap-dropdown-hover
      if (jQuery.fn.dropdownHover) {
        $(".menu .expanded.dropdown > a", context).dropdownHover({
          delay: 500,
          instantlyCloseOthers: true,
        });
      }

    }
  };
  
})(jQuery, Drupal);
