(function($){
    /**
     * Mobile Navigation
     */
    Drupal.behaviors.stylerView = {
        attach: function(context, settings) {
            window.prettyPrint && prettyPrint();

            // Activates scrollspy on sidebar scrollbar
            $('body').scrollspy({ target: '#style-guide-index', offset:100 });

            // Activates affix on sidebar scrollbar to adjust position while scrolling
            $('#style-guide-index .nav').affix({
                offset: {
                    top: 400,
                    bottom: $('footer').outerHeight(true) + 100
                }
            });
        }
    }

})(jQuery);