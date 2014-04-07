var _l10iq = _l10iq || [];

// load YouTube javascript API
var tag = document.createElement('script');
tag.src = "//www.youtube.com/iframe_api";
var firstScriptTag = document.getElementsByTagName('script')[0];
firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);

function l10iYouTubeTracker() {
  this.playerState = {};
  this.players = {};
  this.domReady = false;
  this.apiReady = false;
  this.ready = false;

  this.init = function init() {
    this.domReady = true;
    if (!this.ready && this.apiReady) {
      this.trackYouTube();
      this.ready = true;
    }
  };

  this.apiInit = function () {
    this.apiReady = true;
    if (!this.ready && this.domReady) {
      this.trackYouTube();
      this.ready = true;
    }
  };

  this.trackYouTube = function () {
    jQuery('iframe').each(function() {
      var video = jQuery(this);
      if(video.attr('src') !== undefined){
        var vidSrc = video.attr('src');
        var regex = /h?t?t?p?s?\:?\/\/www\.youtube\.com\/embed\/([\w-]{11})(?:\?.*)?/;
        var matches = vidSrc.match(regex);
        if(matches && matches.length > 1){
          // add a anchor link to support report links
          video.before('<a name="video-' + matches[1] + '"></a>');
          video.attr('id', matches[1]);
          l10iYouTube.players[matches[1]] = new YT.Player(matches[1], {
            events: {
              //'onReady': onPlayerReady,
              'onStateChange': l10iYouTube.onPlayerStateChange
            }
          });
          l10iYouTube.playerState[matches[1]] = {
            state: -1,
            paused: true
          };
        }
      }
    });
  };

  this.onPlayerStateChange = function (event) {
console.log(event);
    var id = event.target.a.id;
    var player = l10iYouTube.players[id];
    var ga_event = {
      'category': "Video event",
      'action': "YouTube: " + id,
      'label': "youtube:" + id,
      'value': 0,
      'noninteraction': false
    };
    var positionPer = Math.round(100 * player.getCurrentTime() / player.getDuration());
    if (event.data == YT.PlayerState.PLAYING){
      ga_event.category = 'Video play';
      //ga_event.value = positionPer;
      _l10iq.push(['_trackIntelEvent', jQuery(this), ga_event, '']);
      l10iYouTube.playerState.paused = false;
    }
    if (event.data == YT.PlayerState.ENDED){
        ga_event.category = 'Video watched';
        ga_event.value = 10000;
        _l10iq.push(['_trackIntelEvent', jQuery(this), ga_event, '']);
    }
    if (event.data == YT.PlayerState.PAUSED && !l10iYouTube.playerState.paused){
        ga_event.category = 'Video stop';
        _l10iq.push(['_trackIntelEvent', jQuery(this), ga_event, '']);

        ga_event.category = 'Video watched';
        ga_event.value = positionPer;
        _l10iq.push(['_trackIntelEvent', jQuery(this), ga_event, '']);
        l10iYouTube.playerState.paused = true;
    }
  };

}

var l10iYouTube = new l10iYouTubeTracker();
jQuery(document).ready(function() {
	_l10iq.push(['_onReady', l10iYouTube.init, l10iYouTube]);
});

// function called by YouTube API when ready
function onYouTubeIframeAPIReady() {
    l10iYouTube.apiInit();
}
