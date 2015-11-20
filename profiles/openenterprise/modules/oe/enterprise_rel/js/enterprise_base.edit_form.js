(function ($) {
  /**
   * Move fields to right column on node edit form.
   */
  Drupal.behaviors.enterprise_main = {
    attach: function (context, settings) {
      // check if side column exists
      if ($(".column-side").length == 1) {
        // Move taxonomy fields to right sidebar in rubik.
        $(".display_sidebar").each(function() {
          $(this).detach();
          $('.column-side .column-wrapper').append($(this));
        });
        /*
        // Check if the sidebar is empty and hide if so.
        if ($('.column-side .column-wrapper').children().length <= 1) {
          $('.column-side .column-wrapper').hide();
          $('.column-main').css('width', '100%');
        }
        //$('.column-main #edit-actions').remove();
        */
      }
    }

  };
}(jQuery));