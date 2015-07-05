var _l10iq = _l10iq || [];

function L10iAddthis(_ioq, config) {
    var ioq = _ioq;
    var io = _ioq.io;
    this.waits = 0;

    this.init = function init() {
        var waits, i;

        io('log', 'l10iAddthisTracker.init()');

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

    this.getUser = function () {
        if (addthis.user == undefined || (typeof addthis.user.ready != 'function')) {
            return null;
        }
        return addthis.user;
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
                if (ioq.isArray(s) && ioq.isFunction(s.toMap)) {
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
        var scorings = io('get', 'config.scorings');
        var ga_event = {
            'eventCategory': "Social share!",
            'eventAction': (typeof addthis.util.getServiceName(evt.data.service) != 'undefined') ? addthis.util.getServiceName(evt.data.service) : evt.data.service,
            'eventLabel': "[[systemAlias]]",
            'eventValue': (typeof scorings.addthis_social_share !== 'undefined') ? Number(scorings.addthis_social_share) : 0,
            'nonInteraction': false,
            'eid': 'socialShare'
        };
        ga_event.oid = ga_event.eventAction;
        io('event', ga_event);
    };

    this.onSocialShareClickback = function (evt) {
        var scorings = io('get', 'config.scorings');
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
        var scorings = io('get', 'config.scorings');
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

    this.init();
}

_l10iq.push(['providePlugin', 'addthis', L10iAddthis, {}]);

var L10iTestPlugin = function (_ioq, config) {
    this.config = config;
}

L10iTestPlugin.prototype.set = function (name, value) {
    this[name] = value;
}

L10iTestPlugin.prototype.get = function (name) {
    return this[name];
}

_l10iq.push(['providePlugin', 'test', L10iTestPlugin, {debug: 1}]);