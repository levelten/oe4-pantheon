(function ($) {

/**
 * Provide the summary information for the block settings vertical tabs.
 */
Drupal.behaviors.cta_list = {
  attach: function (context) {
	if (typeof jQuery().qtip !== 'undefined') {
	$('#logo').qtip({
	    content: {
	        text: $('.region-sidebar-second')
	    },
	    style: {
	      classes: 'qtip-bootstrap'
	    },
	    position: {
	      my: 'top left',
	      at: 'center right'
	    }
	});
	}
  },
};

})(jQuery);