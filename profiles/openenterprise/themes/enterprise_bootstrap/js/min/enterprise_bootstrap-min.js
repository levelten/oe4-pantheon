var Drupal=Drupal||{};!function($,a){"use strict";a.behaviors.enterprisebootstrap={attach:function(a,t){var s=$("iframe",a);if(s&&s.each(function(){var a=$(this)[0].src?$(this)[0].src:"";a.toLowerCase().indexOf("google.com/maps")>0&&$(this).wrap("<div class='google-maps'></div>")}),jQuery.fn.fitText){var o=t.enterprise_bootstrap.fittext?t.enterprise_bootstrap.fittext:!1;if(o)for(var r=o.length-1;r>=0;r--)$(o[r][1],a).fitText(o[r][0])}jQuery.fn.dropdownHover&&$(".menu .expanded.dropdown > a",a).dropdownHover({delay:500,instantlyCloseOthers:!0});var e=t.enterprise_bootstrap.mobilemenuhoverpush?t.enterprise_bootstrap.mobilemenuhoverpush:!1,i=$("#navbar",a),n=$("body",a),d=i.outerHeight(),l=568,p=0,c=function(){return window.outerWidth>l?0:p++},f=function(){n.hasClass("navbar-is-static-top")&&(n.removeClass("navbar-is-static-top").addClass("navbar-is-fixed-top"),n.css("padding-top",d-1+"px"),i.addClass("navbar-fixed-top").removeClass("navbar-static-top"))},v=function(){n.hasClass("navbar-is-fixed-top")&&(n.removeClass("navbar-is-fixed-top").addClass("navbar-is-static-top"),n.css("padding-top","inherit"),i.addClass("navbar-static-top").removeClass("navbar-fixed-top"))},u=function(){function a(){$(window).scrollTop()>i.outerHeight()?f():v()}document.onscroll=a};i.hasClass("navbar-fixed-top")&&e&&(v(),u(),window.onresize=function(){c(),1===p&&u()});var h=$(".style-social-follow",a);if(h){var b=h.children(".btn-social"),C=b.length;b.first().addClass("social-first"),b.last().addClass("social-last"),b.each(function(){$(this).attr("data-social-count",Math.round(100/C))})}}}}(jQuery,Drupal);