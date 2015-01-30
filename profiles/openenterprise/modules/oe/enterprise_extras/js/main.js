;(function($){
    /**
     * Mobile Navigation
     */
    Drupal.behaviors.themeMobileNavigation = {
        attach: function(context, settings) {
            // Menu
            var header = $('#header', context);
            header.once('menu', function(){
                var menu = $('#menu', header);
                var menuToggle = $('.mobile-menu a.toggle', header);
                var ul = $('ul.menu.nav, .menu-block-wrapper > ul.menu', menu);
                if (menu.length && menuToggle.length && ul.length) {
                    menuToggle.click(function(){
                        menu.slideToggle();
                    });
                    // Initially hide the indicators, will be shown visible after logic has been processed.
                    var indicators = $('.menu-indicator', header).css({
                        display: 'block',
                        left: $('> li', ul).first().offset().left,
                        opacity: 0,
                        width: $('> li', ul).first().outerWidth(true)
                    });
                    // Set initial active item.
                    var active = $('> li.active, > li.active-trail', ul).first();
                    // mouseenter function.
                    var itemEnter = function(item) {
                        if (indicators.is(':visible') && item.is(':not(:visible)')) {
                            indicators.animate({
                                opacity: 0
                            });
                            return;
                        }
                        var left = item.offset().left;
                        var width = item.outerWidth(true);
                        // If the indicators are initially hidden, just set the width and left position.
                        if (indicators.is(':not(:visible)')) {
                            indicators.stop(true, true).css({
                                left: left,
                                width: width,
                                avoidTransforms: true
                            });
                        }
                        else {
                            indicators.stop().animate({
                                left: left,
                                opacity: 1,
                                width: width,
                                avoidTransforms: true
                            });
                        }
                    };
                    // mouseleave function.
                    var itemLeave = function() {
                        if (active.length) {
                            itemEnter(active);
                        }
                        else {
                            indicators.stop(true, true).animate({
                                opacity: 0
                            });
                        }
                    };
                    // Bind the mouseenter events on the items.
                    $('li', ul).each(function(index, item){
                        item = $(item);
                        item.bind('mouseenter', function(){
                            itemEnter(item);
                        });
                    });
                    // Bind the mouseleave even on the item container.
                    ul.bind('mouseleave', function(){
                        itemLeave();
                    });
                    // Set initial active state.
                    $(document).on('drupalViewportOffsetChange', null, function(){
                        var element = active ? active : $('li', ul).first();
                        if (element.length) {
                            itemEnter(element);
                        }
                    });
                    $(window).resize(function(){
                        var element = active ? active : $('li', ul).first();
                        if (element.length) {
                            itemEnter(element);
                        }
                    });
                    var element = active ? active : $('li', ul).first();
                    if (element.length) {
                        itemEnter(element);
                    }
                }
            });
        }
    };

    /**
     * Equal Heights
     */
    Drupal.behaviors.themeBeanSlide = {
        attach: function (context) {
            var beanslide = $('.beanslide', context);
            beanslide.once('theme-bean-slide', function(){
                $('.flex-control-nav, .flex-direction-nav', beanslide).addClass('container');
            });
        }
    };

    /**
     * Equal Heights
     */
    Drupal.behaviors.themeEqualHeights = {
        attach: function (context) {
            $('body', context).once('theme-equalheights', function () {
                $(window).bind('resize.theme.equalheights', function () {
                    $($('.equal-height-container').get().reverse()).each(function () {
                        var elements = $(this).children('.equal-height-element').css('height', '');
                        var tallest = 0;
                        elements.each(function () {
                            if ($(this).height() > tallest) {
                                tallest = $(this).outerHeight();
                            }
                        }).each(function() {
                                if ($(this).height() < tallest) {
                                    $(this).css('height', tallest);
                                }
                            });
                    });
                }).load(function () {
                        $(this).trigger('resize.theme.equalheights');
                    });
            });
        }
    };

    /**
     * Affix Sticky Support
     */
    Drupal.behaviors.themeAffix = {
        attach: function(context, settings) {
            $('.ds-sticky', context).once('theme-affix', function(){
                var sticky = $(this);
                var stickyTop = function() {
                    var top = parseInt($('body').css('paddingTop'), 10);
                    if (!top && $('#admin-menu').length) {
                        top = $('#admin-menu').height();
                    }
                    else if (!top && $('.drupal-navbar').length) {
                        top = 0;
                        $('.drupal-navbar > div').each(function(){
                            top += $(this).height();
                        });
                    }
                    return top;
                };
                var stickyResize = function(element) {
                    var top = stickyTop();
                    top = 0;
                    element.css({
                        left: element.parent().offset().left,
                        width: element.parent().width() + 1,
                        'top': top
                    }).affix({
                            offset: {
                                'top': top ? sticky.offset().top - top : sticky.offset().top
                            }
                        }).parent().css('min-height', sticky.parent().height());
                };
                if (jQuery.fn.affix) {
                    $(document).on('drupalViewportOffsetChange', null, function(){
                        stickyResize(sticky);
                    });
                    $(window).resize(stickyResize(sticky));
                    stickyResize(sticky);
                }
            });
        }
    };

    /**
     * AddThis Firefox Fix
     */
    Drupal.behaviors.themeAddThis = {
        attach: function(context, settings) {
            var is_firefox = /firefox/i.test(navigator.userAgent.toLowerCase());
            if (is_firefox !== undefined && is_firefox) {
                $(document).ready(function () {
                    // AddThis Dialog Fix For Firefox
                    $('body').on('click', '#at3winheaderclose', function(){
                        $('> #at3win', $('body')).css('opacity', 0).hide();
                    });
                });
            }
        }
    };

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

})(jQuery);