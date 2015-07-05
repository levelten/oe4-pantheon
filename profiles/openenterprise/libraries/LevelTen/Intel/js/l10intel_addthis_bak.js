var _l10iq = _l10iq || [];

function l10iAddthisTracker() {
    this.waits = 0;

    var scorings = {};

    this.init = function init() {
        var waits, i;

        io('log', 'l10iAddthisTracker.init()');

        scorings = io('get', 'config.scorings');

        if ((typeof addthis != 'object') || (typeof addthis.addEventListener != 'function')) {
            if (this.waits < 5) {
                this.waits++;
                var delay = (this.waits >= 2) ? 2500 : 1000;
                with (this) {
                    setTimeout(function () {
                        init();
                    }, delay);
                }
            }
            return;
        }
        else {
            //addthis.addEventListener('addthis.ready', this.onReady);
            addthis.addEventListener('addthis.menu.share', this.onSocialShare);
            addthis.addEventListener('addthis.menu.follow', this.onSocialFollow);
            addthis.addEventListener('addthis.user.clickback', this.onSocialShareClickback);
            this.onReady({});
        }
    };

    this.onReady = function (evt) {
// verify addthis returned proper user object
        if (addthis.user == undefined || (typeof addthis.user.ready != 'function')) {
            return;
        }
        addthis.user.ready(function (data) {
            var i, services = {};
            // verify we have proper user.services object
            if (typeof addthis.user.services == 'function') {
                var s = addthis.user.services();
                if (typeof s.toMap == 'function') {
                    services = s.toMap();
                }
            }
            var action = [];
            var count = 0;
            var val = {};
            for (i in services) {
                if (services.hasOwnProperty(i)) {
                    val[services[i]['name']] = Number(services[i]['score']);
                    count++;
                }
            }
            io('set', 'v:addthis.services', val);

            var geo = addthis.user.location();
            val = {};
            if (geo['country'] !== 'undefined') {
                var e = ['country', 'dma', 'lat', 'lon', 'msa', 'region', 'zip'];
                for (i = 0; i < e.length; i++) {
                    if (geo[e[i]] == undefined) {
                        continue;
                    }
                    val[e[i]] = geo[e[i]];
                }
                io('set', 'v:addthis.geo', val);
            }
            var last_set = _l10iq.push(['_getFlag', 'session', 'addthis']);
            var timestamp = _l10iq.push(['_getTime']);
            if ((count > 0) && ((last_set == undefined) || ((timestamp - last_set) > (60 * 60 * 24)))) {
                //_l10iq.push(['_saveVar', 'visitor', 'addthis']);
                io('setFlag', 'session', 'addthis', timestamp, true);
            }
        });
    };

    this.onSocialShare = function (evt) {
        var ignore = {
            'more': 1
        };
        if (ignore[evt.data.service]) {
            return;
        }
        var ga_event = {
            'eventCategory': "Social share!",
            'eventAction': (typeof addthis.util.getServiceName(evt.data.service) != 'undefined') ? addthis.util.getServiceName(evt.data.service) : evt.data.service,
            'eventlabel': "[[systemAlias]]",
            'eventValue': (typeof scorings.addthis_social_share !== 'undefined') ? Number(scorings.addthis_social_share) : 0,
            'nonInteraction': false,
            'eid': 'socialShare'
        };
        ga_event.oid = ga_event.eventAction;
        io('event', ga_event);
    };

    this.onSocialShareClickback = function (evt) {
        var ga_event = {
            'eventCategory': "Social share clickback!",
            'eventAction': (typeof addthis.util.getServiceName(evt.data.service) != 'undefined') ? addthis.util.getServiceName(evt.data.service) : evt.data.service,
            'eventLabel': "[[systemAlias]]",
            'eventValue': (typeof scorings.addthis_social_share_clickback !== 'undefined') ? Number(scorings.addthis_social_share_clickback) : 0,
            'nonInteraction': false,
            'eid': 'socialShareClickback'
        };
        ga_event.oid = ga_event.eventAction;
        io('event', ga_event);
    };

    this.onSocialFollow = function (evt) {
        var ga_event = {
            'eventCategory': "Social profile click!",
            'eventAction': (typeof addthis.util.getServiceName(evt.data.service) != 'undefined') ? addthis.util.getServiceName(evt.data.service) : evt.data.service,
            'eventLabel': (evt.data.url) ? evt.data.url : "(not set)",
            'eventValue': (typeof scorings.addthis_social_follow !== 'undefined') ? Number(scorings.addthis_social_follow) : 0,
            'nonInteraction': false,
            'eid': 'socialProfileClick'
        };
        ga_event.oid = ga_event.eventAction;
        io('event', ga_event);
    };

    _l10iq.push(['onReady', this.init, this]);
}

var l10iAddthis = new l10iAddthisTracker();
//_l10iq.push(['addCallback', 'domReady', l10iAddthis.init, l10iAddthis]);
