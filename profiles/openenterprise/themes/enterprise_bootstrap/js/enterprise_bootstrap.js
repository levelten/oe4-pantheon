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

      // Add margin for height of navbar.
      // Account for admin menu or existing margin.
      var $body = $("body", context),
      $header = $("#navbar", context),
      $mainContainer = $(".page-wrapper", context);
      // Only run for fixed navbar.
      if ($body.hasClass("navbar-is-fixed-top")) {

        // Get appropriate heights.
        var mainContainerMargin = $header.outerHeight();
        if ($body.hasClass("admin-menu")) {
          mainContainerMargin += 20;
        }

        // Account for potential existing styles.
        var style = ($mainContainer.attr("style") === undefined) ? "" : $mainContainer.attr("style");
        $mainContainer.attr("style", style + "padding-top:"+mainContainerMargin+"px;");
      }

      /*
      * Add wrapper to Google Map iframes.
      */
      var iframes = $("iframe", context);
      if (iframes) {
        iframes.each(function() {
          var url = ($(this)[0].src) ? $(this)[0].src : "";
          if (url.toLowerCase().indexOf("google.com/maps") > 0) {
            $(this).wrap( "<div class='google-maps'></div>" );
          }
        });
      }

      /*
      * Use fitText if loaded.
      */
      if($.fn.fitText) {
        // Apply fitText to selectors if available.
        var fitTextSelectors = (settings.enterprise_bootstrap.fittext) ? settings.enterprise_bootstrap.fittext : false;
        if (fitTextSelectors) {
          for (var i = fitTextSelectors.length - 1; i >= 0; i--) {
            $(fitTextSelectors[i][1], context).fitText(fitTextSelectors[i][0]);
          }
        }
      }

      /*
      * Add bootstrap-dropdown-hover
      */
      if ($.fn.dropdownHover) {
        $(".menu .expanded.dropdown > a", context).dropdownHover({
          delay: 500,
          instantlyCloseOthers: true,
        });
      }

      /**
      * Responsive Tabs
      */
      if ($.fn.responsiveTabs) {
        Drupal.behaviors.responsiveTabs = {
          attach: function(context) {
            // Make tabs responsive.
            $('ul.nav-tabs, ul.tabs.primary, ul.tabs.secondary, ul.quicktabs-tabs, ul.horizontal-tabs-list', context).responsiveTabs({
              activeClass: 'active',
              activeSelectors: '.active, .selected, .active-trail',
              icon: '<i aria-hidden="true" class="icon fontello oeicon-down-open"></i>',
              text: 'More'
            });
          }
        };
      }

      /*
      * Sticky Menu
      */
      if (settings.enterprise_bootstrap.sticky_menu) {
        var $navbar = $("#navbar", context),
            $navbarWrapper = $("#navbar-wrapper", context);
        var navbarTop = $navbar.outerHeight(),
            hasFixedTop = ($navbar.hasClass('navbar-fixed-top'));

        // Using Affix library.
        if (!$.fn.affix) {
          $navbarWrapper.affix({
            offset: { top: $navbarWrapper.offset().top }
          });
        } else {
          $(window).scroll(function() {
            if ($(window).scrollTop() >= navbarTop && !hasFixedTop) {
              $navbarWrapper.addClass("navbar-fixed-top");
            } else {
              $navbarWrapper.removeClass("navbar-fixed-top");
            }
          });
        }
      }

      /*
      * Mobile menu - hover vs push down
      */
      var mobileMenuHoverPush = (settings.enterprise_bootstrap.mobilemenuhoverpush) ? settings.enterprise_bootstrap.mobilemenuhoverpush : false,
      $navbar = $("#navbar", context),
      $body = $("body", context),
      navbarHeight = $navbar.outerHeight(),
      mobileMenuActivationWidth = 568,
      isMobileCheck = 0,
      isMobile = function() {
        // Check if we're in a mobile breakpoint.
        return (window.outerWidth > mobileMenuActivationWidth) ? 0 : isMobileCheck++;
      },
      staticToFixed = function() {
        // Switch navbar-static-top to navbar-fixed-top
        if ($body.hasClass("navbar-is-static-top")) {
          $body.removeClass("navbar-is-static-top").addClass("navbar-is-fixed-top");
          $body.css("padding-top", (navbarHeight-1)+"px");
          $navbar.addClass("navbar-fixed-top").removeClass("navbar-static-top");
        }
      },
      fixedToStatic = function() {
        // Switch navbar-fixed-top to navbar-static-top
        if ($body.hasClass("navbar-is-fixed-top")) {
          $body.removeClass("navbar-is-fixed-top").addClass("navbar-is-static-top");
          $body.css("padding-top", "inherit");
          $navbar.addClass("navbar-static-top").removeClass("navbar-fixed-top");
        }
      },
      mobileMenuPush = function() {
        // Function for switching out fixed/static navbars.
        function scroll() {
          if ($(window).scrollTop() > $navbar.outerHeight()) {
            staticToFixed();
          } else {
            fixedToStatic();
          }
        }
        document.onscroll = scroll;
      };

      // Switch mobile navbar if Push is enabled, and navbar is set to Fixed Top.
      if ($navbar.hasClass("navbar-fixed-top") && mobileMenuHoverPush && isMobile()) {
        fixedToStatic();
        mobileMenuPush();
        // Run if page has been resized.
        window.onresize = function(){
          isMobile();
          // Only run mobileMenuPush once on change.
          if (isMobileCheck === 1) {
            mobileMenuPush();
          }
        };
      }

      /*
      * Social Follow block - even button width.
      */
      var $socialFollow = $(".style-social-follow", context);
      if ($socialFollow) {
        var $socialChildren = $socialFollow.children(".btn-social");
        var socialFollowCount = $socialChildren.length;
        // Add styling classes
        $socialChildren.first().addClass("social-first");
        $socialChildren.last().addClass("social-last");
        // Add data attribute
        $socialChildren.each(function() {
          $(this).attr("data-social-count", Math.round(100/socialFollowCount));
        });
      }

    }
  };

})(jQuery, Drupal);
