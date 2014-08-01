
(function ($) {
  Drupal.color = {
    logoChanged: false,
    callback: function(context, settings, form, farb, height, width) {
      // Change the logo to be the real one.
      if (!this.logoChanged) {
        $('#preview #preview-logo img').attr('src', Drupal.settings.color.logo);
        this.logoChanged = true;
      }
      // Remove the logo if the setting is toggled off. 
      if (Drupal.settings.color.logo == null) {
        $('div').remove('#preview-logo');
      }

      // Solid background.
      $('#preview', form).css('backgroundColor', $('#palette input[name="palette[bg]"]', form).val());

      // Text preview.
      $('#preview #preview-main h2, #preview .preview-content', form).css('color', $('#palette input[name="palette[text]"]', form).val());
      $('#preview #preview-content a', form).css('color', $('#palette input[name="palette[link]"]', form).val());

      // Site Page Title
      $('#preview #preview-header .sitetitlebar', form).css('background-color', $('#palette input[name="palette[sitetitlebar]"]', form).val());
      $('#preview #preview-header .sitetitlebartext', form).css('color', $('#palette input[name="palette[sitetitlebartext]"]', form).val());

      // Button
      $('#preview #preview-sidebar .btn', form).css('color', $('#palette input[name="palette[buttontext]"]', form).val());
      $('#preview #preview-sidebar .btn', form).css('background-color', $('#palette input[name="palette[button]"]', form).val());

      // Footer wrapper background.
      $('#preview #preview-footer-wrapper', form).css('background-color', $('#palette input[name="palette[footer]"]', form).val());
      $('#preview #preview-footer-wrapper', form).css('color', $('#palette input[name="palette[footertext]"]', form).val());
      $('#preview #preview-footer-top', form).css('background-color', $('#palette input[name="palette[footertop]"]', form).val());
      $('#preview #preview-footer-bottom', form).css('background-color', $('#palette input[name="palette[footerbottom]"]', form).val());

    }
  };
})(jQuery);
