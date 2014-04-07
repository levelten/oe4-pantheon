(function ($) {

Drupal.behaviors.config_wizard = {
  attach: function (context) {
	
	jQuery("a[target='_modal']:not(.config-processed)").each(function (index) {
	  var $this = jQuery(this);
	  var url = $this.attr('href');
	  //url += '/nojs' + '?config-wizard=' + Drupal.settings.config.wizard.name;
	  url += '' + '?config-wizard=' + Drupal.settings.config.wizard.name;
	  $this.attr('href', url);
	  $this.addClass('ctools-use-modal ctools-modal-config-modal config-modal config-processed');
	});

	jQuery('area.ctools-use-modal, a.ctools-use-modal').each( function() {
        var $this = $(this);
        $this.unbind(); // Note the unbind: Otherwise there are multiple bind events which causes issues
        $this.mousedown(function(event) {
            switch (event.which) {
                case 1:
                	console.log('Left mouse button pressed');
                    break;
                case 2:
                	console.log('Middle mouse button pressed');
                    break;
                case 3:
                	console.log('Right mouse button pressed');
                	event.preventDefault();
                    break;
                default:
                    alert('You have a strange mouse');
            }
        });
        $this.click(Drupal.CTools.Modal.clickAjaxLink);
        // Create a drupal ajax object
        var element_settings = {};
        if ($this.attr('href')) {
          element_settings.url = $this.attr('href') + '&modal=ajax';
          element_settings.event = 'click';
          //element_settings.prevent = 'click';
          element_settings.progress = {
            type: 'throbber'
          };
        }
        var base = $this.attr('href');
        Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);
     });	
  },
};

})(jQuery);