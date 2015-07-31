(function($){
    /**
     * Mobile Navigation
     */
    Drupal.behaviors.stylerView = {
        attach: function(context, settings) {
            window.prettyPrint && prettyPrint();

            // Activates scrollspy on sidebar scrollbar
            $('body').scrollspy({ target: '#style-guide-index' });
        }
    }

})(jQuery);