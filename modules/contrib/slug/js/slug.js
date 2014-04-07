(function ($) {

/**
 * Attach the slug behavior.
 */
Drupal.behaviors.slug = {
  attach: function (context, settings) {
    var self = this;
    self.pathPreview(); // Initialize
    $('#edit-parent-parent', context).change(self.pathPreview);
    $('#edit-slug', context).keyup(self.pathPreview);
    $('#edit-title', context).keyup(self.pathPreview);
  },

  /**
   * Build and set the path preview.
   * @returns {undefined}
   */
  pathPreview: function() {
    var base = Drupal.settings.slugPaths[$('#edit-parent-parent').val()] || '';
    if (base) {
      base = base + '/';
    }
    $('#path-preview .path').html(base + $('#edit-slug').val());
  },
};

})(jQuery);
