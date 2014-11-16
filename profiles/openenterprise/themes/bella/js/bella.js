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
      var logoHeight = $(".navbar-header img", $navbar).height();
      var navbarHeight = $navbar.height();
      window.console.log("Logo height: "+logoHeight);
      window.console.log("Navbar height: "+navbarHeight);
      if (logoHeight < navbarHeight) {
        $(".navbar-header", $navbar).height(navbarHeight);
        $(".navbar-header .logo", $navbar).addClass("vertical-align");
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
