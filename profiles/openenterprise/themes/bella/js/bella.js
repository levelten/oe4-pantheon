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

      // Add margin depending on height of navbar.
      var $navbar = $("#navbar.navbar", context);
      var navbarHeight = $navbar.height();
      if ($("body", context).hasClass("logged-in", "admin-menu")){
        navbarHeight += 30;
      } else {
        navbarHeight += 1;
      }

      $("body.html", context).css("padding-top", navbarHeight+"px");
      $("#navbar.navbar .navbar-nav > li.expanded > .dropdown-menu", context).css("top", navbarHeight+"px");
      $(window).resize(function(){
        $("body.html", context).css("padding-top", navbarHeight+"px");
        $("#navbar.navbar .navbar-nav > li.expanded > .dropdown-menu", context).css("top", navbarHeight+"px");
      });

    }
  };

})(jQuery, Drupal);
