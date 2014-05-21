var _l10iq = _l10iq || [];

function l10iOGTracker() {
  this.init = function init() {
    _l10iq.push(['_log', "l10iOG.init()"]);
    _l10iq.registerCallback('saveFormSubmitAlter', this.saveFormSubmitAlterCallback, this);
  }

  // attach gid to form submissions
  this.saveFormSubmitAlterCallback = function saveFormSubmitCallback(json_params, json_data, $obj, event) {
    var og =  _l10iq.push(['_getVar', 'page', 'analytics', 'og']);

    if (og != undefined && (og.length > 0)) {
        json_data['value']['og'] = og;
    }
  }

}

var l10iOG = new l10iOGTracker();
jQuery(document).ready(function() {
  _l10iq.push(['_onReady', l10iOG.init, l10iOG]);
});


