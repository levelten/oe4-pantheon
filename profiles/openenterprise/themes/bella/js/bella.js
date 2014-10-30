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
      var fitTextFinished = false;
      if(jQuery.fn.fitText) {
        window.console.log("loaded  Fittext.js");
        $(".not-logged-in #navbar .navbar-header .name", context).fitText(2);
        $(".logged-in #navbar .navbar-header .name", context).fitText(1.6);
        fitTextFinished = true;
      }

      // Use equalize if loaded.
      function waitFitText(fitTextFinished) {
        if (!fitTextFinished) {
          setTimeout(waitFitText(fitTextFinished), 100);
          $("#navbar .equalizer", context).equalize();
        }
      }
      if(jQuery.fn.equalize) {
        window.console.log("loaded equalize.js");
        $("#navbar .navbar-header", context).addClass("equalizer");
        $("#navbar .navbar-collapse .navbar-nav > li > a", context).addClass("equalizer");
        waitFitText(fitTextFinished);
      }

      // Add margin depending on height of navbar.
      var $navbar = $("header.navbar-default", context);
      var navbarHeight = $navbar.height();

      if ($("body", context).hasClass("logged-in", "admin-menu")){
        var adminMenu = $("#admin-menu", context);
        if (adminMenu.length > 0) {
          navbarHeight += adminMenu.height();
        } else {
          navbarHeight += 14;
        }
      }

      $("body.html").css("padding-top", navbarHeight+"px");
      $("header.navbar-default .navbar-nav > li.expanded > .dropdown-menu", context).css("top", navbarHeight+"px");
      $(window).resize(function(){
        $("body.html").css("padding-top", navbarHeight+"px");
        $("header.navbar-default .navbar-nav > li.expanded > .dropdown-menu", context).css("top", navbarHeight+"px");
      });

    }
  };

})(jQuery, Drupal);
