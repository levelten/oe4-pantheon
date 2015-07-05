var _l10iq = _l10iq || [];

function l10iHubSpotTracker() {  
  this.init = function init() {
    _l10iq.push(['_log', "l10iHubSpotTracker.init()"]);
    
    _l10iq.push(['addCallback', 'saveCtaClickAlter', this.saveCtaClickAlterCallback, this]);
    _l10iq.push(['addCallback', 'saveFormSubmitAlter', this.saveFormSubmitAlterCallback, this]);
    _l10iq.push(['addCallback', 'saveCommentSubmitAlter', this.saveCommentSubmitAlterCallback, this]);
    
    // add vtk to hidden field on HubSpot forms
    jQuery(".hs-form input[name='l10i_vtk']").val(_l10iq.vtk);
    
    var rf = _l10iq.push(['_getCookie', 'hsrecentfields']);

    if (rf) {
      rf = decodeURIComponent(rf);
      // sometimes hsrecentfields not proper json format, so use try catch
      try {
        rf = jQuery.parseJSON(rf);
      }
      catch(e) {
        rf = false;
      }
    }

    if (rf) {
      try {
        rf['hs_context'] = jQuery.parseJSON(rf['hs_context']);
      }
      catch(e) {
        // do nothing
      }

      var count = 0;
        var data = {};
      for (var i in rf) {
        if (rf.hasOwnProperty(i) && rf[i] != 'hs_context') {
            data[i] = rf[i];

           count ++;
        }
      }
      if (count > 0) {
          _l10iq.push(['set', 'visitor.hubspot', data);
    	  //_l10iq.push(['_saveVar', 'visitor', 'hubspot']);
      }
      
      _l10iq.push(['set', 'ext.hubspot.hs_context', rf['hs_context']]);
      _l10iq.push(['saveVar', 'ext', 'hubspot']);
    }
  };
  
  this.saveCtaClickAlterCallback = function (json_params, json_data, $obj, event) {
    json_data['value']['hubspotutk'] = _l10iq.getCookie('hubspotutk');
    var href = $obj.attr('cta_dest_link');  // used for HubSpot CTAs
    if (typeof href != 'undefined') {
      json_data['value']['href'] = href;
    }
  };
  
  this.saveFormSubmitAlterCallback = function saveFormSubmitCallback(json_params, json_data, $obj, event) {
	  json_data['value']['hubspotutk'] = _l10iq.getCookie('hubspotutk');
	  // check if a HubSpot form
	  if (!$obj.hasClass('hs-form')) {
		return;
	  }
	  // add vtk to hidden field on HubSpot forms
	  jQuery(".hs-form input[name='l10i_vtk']").val(_l10iq.vtk);
	    
	  json_data['value']['type'] = 'hubspot';
	  var id = $obj.attr('id');
	  json_data['value']['fid'] = id.replace('hsForm_', '');
  };
  
  this.saveCommentSubmitAlterCallback = function saveCommentSubmitCallback(json_params, json_data, $obj, event) {
	  json_data['value']['hubspotutk'] = _l10iq.getCookie('hubspotutk');
  };

    _l10iq.push(['addCallback', 'domReady', this.init, this]);
}

var l10iHubSpot = new l10iHubSpotTracker();
//jQuery(document).ready(function() {
//	_l10iq.push(['_onReady', l10iHubSpot.init, l10iHubSpot]);
//});


