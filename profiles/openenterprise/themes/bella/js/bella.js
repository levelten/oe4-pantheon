/**
 * @file
 * bella.js
 *
 * Provides general enhancements.
 */

var Drupal = Drupal || {};

(function ($, Drupal) {
    "use strict";

    Drupal.behaviors.bellaThemeFixes = {
        attach: function (context) {

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
            if ($("body", context).hasClass("admin-menu")) {
                navbarHeight += 30;
            } else {
                navbarHeight += 1;
            }

            // Add padding to body if using fixed navbar.
            if (navbar.classList.contains("navbar-fixed-top")) {
                var navbarHeight = navbar.offsetHeight;
                var bodyHtml = context.querySelector("body.html");
                bodyHtml.style.paddingTop = navbarHeight + "px";
                // Update based on window resizing.
                $(window).resize(function () {
                    navbarHeight = context.getElementById("navbar").offsetHeight;
                    bodyHtml.style.paddingTop = navbarHeight + "px";
                });
            }

        }
    };


    /**
     * Responsive price table.
     */
    Drupal.behaviors.responsivePriceTable = {
        attach: function (context) {
            var $priceTable = $('.style-section-comparison-table', context);
            var $headers = $('header', $priceTable);
            var $info = $('.info', $priceTable);
            var $products = $('.products > .product', $priceTable);
            var rows = {};

            function priceTableSetup() {
                var i = 0;
                $('section > ul > li', $info).each(function () {
                    var $itemTitle = $(this);
                    rows[i] = {title: $itemTitle, items: []};
                    $products.each(function () {
                        var $item = $($('section > ul > li', this).get(i));
                        var $itemTitleClone = $('<label/>').addClass('title').html($itemTitle.html() + ': ');
                        $item.prepend($itemTitleClone);
                        rows[i].items.push($item);
                    });
                    i++;
                });
            }

            function priceTableResize() {
                var maxHeaderHeight = 0;
                // Find the max-height of the headers.
                $headers.css('height', 'auto').each(function () {
                    var headerHeight = $(this).outerHeight();
                    if (headerHeight > maxHeaderHeight) {
                        maxHeaderHeight = headerHeight;
                    }
                })
                    // Actually set the height if needed.
                    .each(function () {
                        var headerHeight = $(this).outerHeight();
                        if (headerHeight < maxHeaderHeight) {
                            $(this).height(maxHeaderHeight);
                        }
                    });
                // Find the max-height of each row.
                $.each(rows, function (i, row) {
                    var maxItemHeight = row.title.css('height', 'auto').outerHeight();
                    $.each(row.items, function () {
                        var itemHeight = $(this).css('height', 'auto').outerHeight();
                        if (itemHeight > maxItemHeight) {
                            maxItemHeight = itemHeight;
                        }
                    })
                    // Actually set the height if needed.
                    if (row.title.outerHeight() < maxItemHeight) {
                        row.title.height(maxItemHeight);
                    }
                    $.each(row.items, function () {
                        var itemHeight = $(this).outerHeight();
                        if (itemHeight < maxItemHeight) {
                            $(this).height(maxItemHeight);
                        }
                    });
                });

            }

            $priceTable.once('price-table', function () {
                priceTableSetup();
                priceTableResize();
            });
            $(window).resize(function () {
                priceTableResize();
            });
        }
    };

})(jQuery, Drupal);
