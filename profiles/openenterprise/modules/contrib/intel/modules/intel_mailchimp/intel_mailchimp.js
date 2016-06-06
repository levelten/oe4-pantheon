(function ($) {

/**
 * Provide the summary information for the block settings vertical tabs.
 */
Drupal.behaviors.intel_mailchimp = {
  attach: function (context) {
	_l10iq.push(['addCallback', 'emailClick', this.emailClick, this]);
  },

  emailClick: function (vars) {
    if (vars.type != 'mailchimp') {
      return;
    }
    var data = {
      vtk: _l10iq.vtk,
      userid: vars.userid,
      listid: vars.listid,
      campaignid: vars.campaignid,
      location: vars.location,
      systemPath: vars.systemPath
    };
    var url = ('https:' == document.location.protocol) ? 'https://' : 'http://';
    url += Drupal.settings.intel.config.cmsHostpath + "intel_mailchimp/email_click_js";
    jQuery.ajax({
      dataType: 'json',
      url: url, 
      data: data,
      type: 'GET'
    });
  }
};

})(jQuery);