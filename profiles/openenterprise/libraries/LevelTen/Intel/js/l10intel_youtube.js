var _l10iq = _l10iq || [];

// load YouTube javascript API
var tag = document.createElement('script');
tag.src = "https://www.youtube.com/iframe_api";
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

    this.trackPlayer = function (player, videoId) {
        player.addEventListener('onReady', l10iYouTube.onPlayerReady);
        player.addEventListener('onStateChange', l10iYouTube.onPlayerStateChange);
        l10iYouTube.players[videoId] = player;
        l10iYouTube.playerState[videoId] = {
            state: -1,
            paused: true
        };
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
                    var width = video.width();
                    var height = video.height();
                    jQuery('iframe#' + matches[1]).replaceWith('<div id="' + matches[1] + '"></div>');
                    var player = new YT.Player(matches[1], {
                        videoId: matches[1],
                        height: height,
                        width: width
                        /*
                        events: {
                            'onReady': l10iYouTube.onPlayerReady,
                            'onStateChange': l10iYouTube.onPlayerStateChange
                        }
                        */
                    });
                    l10iYouTube.trackPlayer(player, matches[1]);
                }
            }
        });
    };

    this.onPlayerReady = function (event) {

    };

    this.onPlayerStateChange = function (event) {
        // check if YouTube API event data struc is correct
        if (event.target == undefined || event.target.getVideoData == undefined) {
            return;
        }
        var videoData = event.target.getVideoData();

        var id = videoData.video_id;
        var title = (videoData.author) ? videoData.author : '(not set)';
        title += ': ' + ((videoData.title) ? videoData.title : '(not set)');

        var player = l10iYouTube.players[id];
        var ga_event = {
            'eventCategory': "Video event",
            'eventAction': "YouTube: " + title,
            'eventLabel': "::youtube:" + id,
            'eventValue': 0,
            'nonInteraction': false
        };
        var positionPer = Math.round(100 * player.getCurrentTime() / player.getDuration());
        if (event.data == YT.PlayerState.PLAYING){
            ga_event.eventCategory = 'Video play';
            var value = (typeof _l10iq.settings.scorings.youtube_video_play !== 'undefined') ? Number(_l10iq.settings.scorings.youtube_video_play) : 0;
            if (value > 0) {
                ga_event.eventCategory += '!';
            }
            //_l10iq.push(['_trackIntelEvent', jQuery(this), ga_event, '']);
            _l10iq.push(['event', ga_event]);
            l10iYouTube.playerState[id].paused = false;
        }
        else if (event.data == YT.PlayerState.ENDED  && !l10iYouTube.playerState[id].paused){
            ga_event.eventCategory = 'Video watched';
            ga_event.eventValue = 100;
            _l10iq.push(['event', ga_event]);
            //_l10iq.push(['_trackIntelEvent', jQuery(this), ga_event, '']);
        }
        else if (event.data == YT.PlayerState.PAUSED && !l10iYouTube.playerState[id].paused){
            ga_event.eventCategory = 'Video stop';
            _l10iq.push(['event', ga_event]);
            //_l10iq.push(['_trackIntelEvent', jQuery(this), ga_event, '']);

            // copy object for Video watched
            var ga_event2 = jQuery.extend({}, ga_event);
            ga_event2.eventCategory = 'Video watched';
            ga_event2.eventValue = positionPer;
            _l10iq.push(['event', ga_event2]);
            //_l10iq.push(['_trackIntelEvent', jQuery(this), ga_event2, '']);
            l10iYouTube.playerState[id].paused = true;
        }
    };
    _l10iq.push(['addCallback', 'domReady', this.init, this]);
}

var l10iYouTube = new l10iYouTubeTracker();

//jQuery(document).ready(function() {
//    _l10iq.push(['_onReady', l10iYouTube.init, l10iYouTube]);
//});

// function called by YouTube API when ready
function onYouTubeIframeAPIReady() {
    l10iYouTube.apiInit();
}
