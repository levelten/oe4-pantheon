var _l10iq = _l10iq || [];

function L10iDisqus(_ioq) {
    var ioq = _ioq;
    var io = _ioq.io;
    this.apiUrl = 'https://disqus.com/api/3.0/';

    io('log', "l10iDisqusTracker.init()");

  this.trackComment = function (comment) {
    var action = "Disqus", ga_event, json_data, json_params, timestamp;
    if (comment.text.length > 40) {
      action = action + ": " + comment.text.substring(0, 35) + '...';
    }
    else {
      action = action + ": " + comment.text;
    }
    ga_event = {
	  'eventCategory': "Comment!",
	  'eventAction': action,
      'eventLabel': window.location.pathname.substring(1) + "#comment-" + comment.id,
      'eventValue': (typeof _l10iq.settings.scorings.disqus_comment !== 'undefined') ? Number(_l10iq.settings.scorings.disqus_comment) : 0,
  	  'nonInteraction': false
    };
    //_l10iq.push(['_trackIntelEvent', jQuery(this), ga_event, '']);
      _l10iq.push(['event', ga_event]);

    timestamp = _l10iq.push(['_getTime']);
    comment = {
      'id': comment.id,
      'text': comment.text,
      'type': 'disqus',
      'submitted': timestamp,
      'location': _l10iq.location,
      'systemPath' : _l10iq.push(['get', 'config.systemPath', ''])
    };
    
    json_data = {
      'value': comment,
      'valuemeta': {'_updated': timestamp},
      'return': {commentid: comment.id, keys: timestamp, type: 'disqus'}
    };
    json_params = {
      'keys': timestamp,
      'type': 'session',
      'namespace': 'commentSubmit'
    }; 
    _l10iq.push(['triggerCallbacks', 'saveCommentSubmitAlter', json_params, json_data, {}, {}]);
    _l10iq.push(['getJSON', 'var/merge', json_params, json_data, 'l10iDisqus.submitComment']);
  };
  
  this.submitComment = function submitComment(data) {
    _l10iq.push(['triggerCallbacks', 'saveCommentSubmitPostSubmit', data['return']]);
  };
}

_l10iq.push(['providePlugin', 'disqus', L10iDisqus, {}]);
