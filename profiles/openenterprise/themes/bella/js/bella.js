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

      // Use fitText if loaded.
      if(jQuery.fn.fitText) {
        window.console.log("loaded Fittext.js");
        $(".not-logged-in #navbar .navbar-header .name", context).fitText(2);
        $(".logged-in #navbar .navbar-header .name", context).fitText(1.6);
      }

      // Use for the following navigation updates.
      var navbar = context.getElementById("navbar");
      var $navbar = $("navbar", context);

      // Equal width nav items.
      var navbarNav = navbar.querySelector(".navbar-nav");
      var navbarChildren = navbarNav.children;
      navbarNav.style.width = "100%";
      var navbarChildWidth = 100/navbarChildren.length+"%";

      Array.prototype.forEach.call(navbarChildren,function(el){
        el.style.width = navbarChildWidth;
      });
      
      // Set height of header for logo positioning.
      var brand = navbar.querySelector(".navbar-header .navbar-brand");
      var brandHeight = brand.offsetHeight;
      var navbarHeight = navbar.offsetHeight;

      // If the branding area is smaller than the navigation, vertically align the branding (name, logo).
      if (brandHeight < navbarHeight) {
        var regionHeight = navbar.querySelector(".region-navigation").offsetHeight;
        brand.style.maxHeight = (regionHeight-10)+"px";
        navbar.querySelector(".navbar-header").style.height = context.getElementById("navbar").offsetHeight+"px";
        if (brand.classList) {
          brand.classList.add("vertical-align");
        } else {
          brand.className += " " + "vertical-align";
        }
      }

      // Only do the following if the navbar is fixed.
      var navbarHasClass = $navbar.hasClass("navbar-fixed-top");
      if (navbarHasClass) {
        // Add extra pixels if we're logged in.
        if ($("body", context).hasClass("logged-in", "admin-menu")){
          navbarHeight += 30;
        } else {
          navbarHeight += 1;
        }

        // Set up objects.
        var bodyHtml = context.querySelector("body.html");
        var dropdownMenu = context.querySelector("#navbar.navbar .navbar-nav > li.expanded > .dropdown-menu");

        // Add padding and top to dropwdown to position correctly for fixed menu.
        bodyHtml.style.paddingTop = navbarHeight+"px";
        dropdownMenu.style.top = navbarHeight+"px";

        // Update based on window resizing.
        $(window).resize(function(){
          navbarHeight = context.getElementById("navbar").offsetHeight;
          bodyHtml.style.paddingTop = navbarHeight+"px";
          dropdownMenu.style.top = navbarHeight+"px";
        });
      }

    }
  };

})(jQuery, Drupal);
