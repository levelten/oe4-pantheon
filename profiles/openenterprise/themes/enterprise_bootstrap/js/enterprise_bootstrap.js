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
    attach: function(context) {

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

    }
  };

  /**
   * Mobile Menu accordion
   */
  Drupal.behaviors.mobileMenuAccordion = {
    attach: function (context) {
      var documentWidth = $(document).width();
      $(document).resize(function() {
        documentWidth = $(document).width();
      });

      if (documentWidth <= 769) {
        var $menu = $('.navbar-collapse .mega > .navbar-nav', context);

        $("li.dropdown > a", $menu).click(function(event) {
          event.preventDefault();
        });

        $("li.dropdown", $menu).click(function() {
          if($(this).hasClass('active') || $(this).hasClass('active-trail')){
            var newURL = window.location.origin + $("> a", this).attr("href");
            $(location).attr("href", newURL);
          } else {
            $(this).parent().find("li.dropdown").removeClass("active active-trail");
            $(this).addClass("active");
          }
        });

      }
    }
  };

})(jQuery, Drupal);
