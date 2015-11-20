(function ($) {

  "use strict";

  Drupal.behaviors.enterpriseRelContentTypes = {
    attach: function (context) {
      // Provide the vertical tab summaries.
      $('fieldset#edit-enterprise-rel', context).drupalSetSummary(function (context) {
        var vdVal = $("#edit-view-display option:selected").val();
        var vdText = $("#edit-view-display option:selected").text();
        if (!vdVal) {
          return Drupal.t('None');
        }
        return Drupal.t('View') + ': ' + vdText;
      });
    }
  };
})(jQuery);