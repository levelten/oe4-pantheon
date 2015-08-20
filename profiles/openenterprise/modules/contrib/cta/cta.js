(function ($) {

/**
 * Provide the summary information for the block settings vertical tabs.
 */
Drupal.behaviors.cta = {
  attach: function (context) {
      /*
      setTimeout(function(){
          var options = {
              content: jQuery('#block-block-2').html(),
              html: 1,
              placement: 'auto',
              trigger: manual,
          };
          jQuery('#block-block-1').popover(options);
          jQuery('#block-block-1').popover('show');

      }, 500);
      */
      if (Drupal.settings.cta != undefined && Drupal.settings.cta.modal != undefined) {

          var settings = Drupal.settings.cta;
          var modal, options, i;
          for (i in settings.modal) {
              modal = settings.modal[i];
              options = {
                  show: 1
              };
              if (modal.trigger == undefined) {
                  continue;
              }
              //options.backdrop = false;
              /*
              if (modal.trigger.pageview) {
                  var modal_id = i;
                  setTimeout(function(){ $('#' + modal_id).modal('show') }, 1);
              }
              */
              if (modal.trigger.delay) {
                  var modal_id = i;
                  var modal_options = options;
                  //setTimeout(function(){ $('#' + modal_id).css("display", "block") }, modal.trigger.delay);
                  setTimeout(function(){ $('#' + modal_id).modal(modal_options) }, modal.trigger.delay);
              }
          }
      }
      // Reposition when a modal is shown
      $('.modal').on('show.bs.modal', this.reposition);

      // Reposition when the window is resized
      var callback = this.reposition;
      $(window).on('resize', function() {
          $('.modal:visible').each(callback);
      }).bind(this);
  },
  reposition: function () {
      var modal = $(this);
      var classes = modal.attr('class').split(/\s+/);
      var vPos = '';
      var hPos = '';
      $.each(classes, function (index, item) {
          if (item == 'modal-bottom') {
              vPos = 'bottom';
          }
          else if (item == 'modal-middle') {
              vPos = 'middle';
          }
          else if (item == 'modal-top') {
              vPos = 'top';
          }
          if (item == 'modal-left') {
              hPos = 'left';
          }
          else if (item == 'modal-center') {
              hPos = 'center';
          }
          else if (item == 'modal-right') {
              hPos = 'right';
          }
      })

      if (!vPos || !hPos) {
          return;
      }
      var dialog = modal.find('.modal-dialog');

      modal.css('display', 'block');

      // Dividing by two centers the modal exactly, but dividing by three
      // or four works better for larger screens.
      if (vPos == 'bottom') {
          dialog.css("margin-top", Math.max(0, modal.height() - dialog.height()));
      }
      else if (vPos == 'middle') {
          dialog.css("margin-top", Math.max(0, (modal.height() - dialog.height()) /2));
      }
      if (hPos == 'left') {
          dialog.css("margin-left", Math.max(0, 0));
      }
      else if (hPos == 'right') {
          dialog.css("margin-left", Math.max(0, ($(window).width() - dialog.width())));
      }
      //dialog.css("margin-top", Math.max(0, ($(window).height() - dialog.height()) / 2));
  }
};

})(jQuery);