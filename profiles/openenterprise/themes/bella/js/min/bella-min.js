var Drupal=Drupal||{};!function($,a){"use strict";a.behaviors.bellaThemeFixes={attach:function(a){function e(n){n||(setTimeout(e(n),100),$("#navbar .equalizer",a).equalize())}var n=!1;jQuery.fn.fitText&&(window.console.log("loaded  Fittext.js"),$(".not-logged-in #navbar .navbar-header .name",a).fitText(2),$(".logged-in #navbar .navbar-header .name",a).fitText(1.6),n=!0),jQuery.fn.equalize&&(window.console.log("loaded equalize.js"),$("#navbar .navbar-header",a).addClass("equalizer"),$("#navbar .navbar-collapse .navbar-nav > li > a",a).addClass("equalizer"),e(n));var d=$("header.navbar-default",a),r=d.height();if($("body",a).hasClass("logged-in","admin-menu")){var i=$("#admin-menu",a);r+=i.length>0?i.height():14}$("body.html").css("padding-top",r+"px"),$("header.navbar-default .navbar-nav > li.expanded > .dropdown-menu",a).css("top",r+"px"),$(window).resize(function(){$("body.html").css("padding-top",r+"px"),$("header.navbar-default .navbar-nav > li.expanded > .dropdown-menu",a).css("top",r+"px")})}}}(jQuery,Drupal);