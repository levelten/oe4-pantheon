(function ($) {

/**
 * Provide the summary information for the block settings vertical tabs.
 */
Drupal.behaviors.cta = {
   _html: document.documentElement,
   _delayTimer: null,
   sensitivity: 20, //setDefault(config.sensitivity, 20),
   timer: 1000, //setDefault(config.timer, 1000),
   delay: 0, //setDefault(config.delay, 0),
   disableKeydown: false,
   modal: null,
   settings: {},
   options: {},
   attach: function (context) {

      /*
      setTimeout(function(){
          $('#test-container').jsPanel({
              position:'center',
              content: 'HI Bob'
          });
      }, 500);
      */

      //$('#test-container').jsPanel({
      //    position:'center',
      //   content: 'HI Bob'
      //});



      if (Drupal.settings.cta === undefined || Drupal.settings.cta.modal === undefined) {
        return;
      }

      for (var i in Drupal.settings.cta.modal) {
          this.modal = $('#' + i);
          // check if modal exists, and if boostrap modal function is attached
          if (!this.modal.length || this.modal.modal === undefined) {
              continue;
          }
          this.settings = Drupal.settings.cta.modal[i];
          if (this.settings.trigger == undefined) {
              continue;
          }

          this.options = {
              show: 1
          };

          if (this.settings.trigger.delay) {
              //this.delay = this.settings.trigger.delay;
              /*
              var modal_options = options;
              //setTimeout(function(){ $('#' + modal_id).css("display", "block") }, modal.trigger.delay);
              setTimeout(function(){
                  $modal.modal(modal_options) }, settings.trigger.delay);
                  */

          }
          this._html.addEventListener('mouseleave', this.handleMouseleave);
          this._html.addEventListener('mouseenter', this.handleMouseenter);
          this._html.addEventListener('keydown', this.handleKeydown);
          break;
      }
      // Reposition when a modal is shown
      $('.modal').on('show.bs.modal', this.reposition);

      // Reposition when the window is resized
      var callback = this.reposition;
      $(window).on('resize', function() {
          $('.modal:visible').each(callback);
      }).bind(this);
  },
  showModal: function () {
      Drupal.behaviors.cta.modal.modal(Drupal.behaviors.cta.options)
  },
  handleMouseleave: function (e) {
    if (e.clientY > this.sensitivity) { return; }

      Drupal.behaviors.cta._delayTimer = setTimeout(Drupal.behaviors.cta.showModal, Drupal.behaviors.cta.delay);
  },
  handleMouseenter: function () {
    if (Drupal.behaviors.cta._delayTimer) {
      clearTimeout(Drupal.behaviors.cta._delayTimer);
      Drupal.behaviors.cta._delayTimer = null;
    }
  },
  handleKeydown: function (e) {
    if (Drupal.behaviors.cta.disableKeydown) { return; }
    else if(!e.metaKey || e.keyCode !== 76) { return; }

    Drupal.behaviors.cta.disableKeydown = true;
    Drupal.behaviors.cta._delayTimer = setTimeout(Drupal.behaviors.cta.showModal, Drupal.behaviors.cta.delay);
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