;(function($){

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