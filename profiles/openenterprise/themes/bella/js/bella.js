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
      var $navbar = $("#navbar", context);

      // Equal width nav items.
      var $navbarNav = $(".navbar-nav", $navbar);
      var $navbarChildren = $navbarNav.children();
      $navbarNav.width(100+"%");
      $navbarChildren.width(100/$navbarChildren.length+"%");
      $navbarChildren.each(function() {
        $(".dropdown-menu", this).width($(this).width());
      });

      // Set height of header for logo positioning.
      var navbarHeight = $navbar.height();
      var headerHeight = $(".navbar-header", $navbar).height();
      window.console.log("Navbar height: "+navbarHeight);
      window.console.log("Header height: "+headerHeight);
      if (headerHeight < navbarHeight) {
        $(".navbar-header", $navbar).height(navbarHeight);
      }

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
