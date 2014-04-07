var _l10iq = _l10iq || [];

function l10iMailChimpTracker() {  
  this.init = function init() {
	var e, action, timestamp, emailclick, listname, listid, userid, campaignid, campaignname;
    _l10iq.push(['_log', "l10iMailChimpTracker.init()"]);
    var query = window.location.search;
    if (!query) {
      return;
    }
    // remove opening ?
    query = query.slice(1);
    var pairs = query.split('&');
    var params = {};
    for (var i = 0; i < pairs.length; i++) {
      e = pairs[i].split('=');
      params[e[0]] = e[1]; 
    }
    if ((params['utm_term'] == undefined) || (params['utm_medium'] == undefined) || (params['utm_medium'] != 'email')) {
      return;
    }

    e = params['utm_term'].split('-');
    if (!e.length == 3) {
      return;
    }
    listid = e[0];
    campaignid = e[1];
    userid = e[2];
    e = e[0].split('_');
    if (e.length == 2) {
      listid = e[1];
    }
    else {
      listid = e[0];
    }

    e = params['utm_campaign'].split('-', 2);
    if (e.length == 2) {
      campaignname = e[1];
    }
    else {
      campaignname = params['utm_campaign'];
    }

    listname = params['utm_source']

    ga_event = {
        'category': "Email click!",
        'action': 'MailChimp: ' + campaignname + ' (' + listname + ')',
        'label': 'MailChimp:' + listid + ':' + campaignid,
        'value': (typeof _l10iq.settings.scorings.email_click !== 'undefined') ? Number(_l10iq.settings.scorings.email_click) : 0,
        'noninteraction': false
    };
    _l10iq.push(['_trackIntelEvent', jQuery(this), ga_event, '']);

    action = [
      '_setVar',
      'ext',
      'mailchimp',
      "id",
      userid
    ];
    _l10iq.push(action);   
    _l10iq.push(['_saveVar', 'ext', 'mailchimp']);

    timestamp = _l10iq.push(['_getTime']);
    emailclick = {
      'listid': listid,
      'userid': userid,
      'campaignid' : campaignid,
      'type': 'mailchimp',
      'submitted': timestamp,
      'location': _l10iq.location,
      'system_path' : (_l10iq.settings.system_path != undefined) ? _l10iq.settings.system_path : ''
    };

    json_data = {
      'value': emailclick,
      'valuemeta': {'_updated': timestamp},
      'return': {
        userid: emailclick.userid,
        listid: emailclick.listid,
        campaignid: emailclick.campaignid,
        location: emailclick.location,
        system_path: emailclick.system_path,
        keys: timestamp,
        type: 'mailchimp'
      }
    };
    json_params = {
      'keys': timestamp,
      'type': 'session',
      'namespace': 'email_click'
    };
    _l10iq.push(['_triggerCallbacks', 'emailClickAlter', [json_params, json_data, {}, {}]]);
    // TODO: should we save this data?
    //_l10iq.push(['_getJSON', 'var/merge', json_params, json_data, 'l10iMailChimp.emailClick']);
      l10iMailChimp.emailClick({ 'return': json_data.return});
  };

  this.emailClick = function emailClick(data) {
    _l10iq.push(['_triggerCallbacks', 'emailClick', [data['return']]]);
  };
}

var l10iMailChimp = new l10iMailChimpTracker();
jQuery(document).ready(function() {
	_l10iq.push(['_onReady', l10iMailChimp.init, l10iMailChimp]);
});

