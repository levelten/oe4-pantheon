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

      // Use for the following navigation updates.
      var navbar = context.getElementById("navbar");
      var $navbar = $(".navbar", context);

      // // Set height of header for logo positioning.
      // var brand = navbar.querySelector(".navbar-header .navbar-brand");
      // var brandHeight = brand.offsetHeight;

      // // If the branding area is smaller than the navigation, vertically align the branding (name, logo).
      // if (brandHeight < navbarHeight) {
      //   var regionHeight = navbar.querySelector(".region-navigation").offsetHeight;
      //   brand.style.maxHeight = (regionHeight-10)+"px";
      //   navbar.querySelector(".navbar-header").style.height = context.getElementById("navbar").offsetHeight+"px";
      //   if (brand.classList) {
      //     brand.classList.add("vertical-align");
      //   } else {
      //     brand.className += " " + "vertical-align";
      //   }
      // }

      // Add extra pixels if we're logged in.
      if ($("body", context).hasClass("admin-menu")){
        navbarHeight += 30;
      } else {
        navbarHeight += 1;
      }

      // Add padding to body if using fixed navbar.
      if (navbar.classList.contains("navbar-fixed-top")) {
        var navbarHeight = navbar.offsetHeight;
        var bodyHtml = context.querySelector("body.html");
        bodyHtml.style.paddingTop = navbarHeight+"px";
      // Update based on window resizing.
      $(window).resize(function(){
        navbarHeight = context.getElementById("navbar").offsetHeight;
        bodyHtml.style.paddingTop = navbarHeight+"px";
      });
    }

  }
};

})(jQuery, Drupal);
