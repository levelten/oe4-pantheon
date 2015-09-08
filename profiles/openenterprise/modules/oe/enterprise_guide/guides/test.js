/**
 * Created by tom on 9/3/15.
 */

/*
guider = {
    buttons: [{name: "Next"}],
    description: "Guiders are a user interface design pattern for introducing features of software. This dialog box, for example, is the first in a series of guiders that together make up a guide.",
    id: "first",
    next: "second",
    overlay: true,
    title: "Welcome to Guiders.js!"
}
*/



function EGuide(jQuery) {
    var $ = jQuery;
};

EGuide.prototype.assertPath = function (value, op) {
    var path = window.location.pathname.substr(1);
    if (path == value) {
        return 1;
    }
    return 0;
}

EGuide.prototype.assertInput = function (value, op, selector) {
    var path = window.location.pathname.substr(1);
    if (path == value) {
        return 1;
    }
    return 0;
}

EGuide.prototype.setInput = function (value, selector) {
    var $obj = selector || jQuery(selector);
    if ($obj.length) {
        $obj.val(value);
    }
}

var eGuide = new EGuide(jQuery);

var guides = {};
guides['siteTitle'] = {
    title: "Change Site Title",
    id: 'siteTitle',
    xButton: 1,
    buttons: [],
    steps: [
        //{
        //    position: 7,
        //    description: '<a href="https://www.youtube.com/embed/yEnIpQf3g_A?width=500&height=500&iframe=true" class="colorbox colorbox-load">video</a><iframe src="https://www.youtube.com/embed/yEnIpQf3g_A" frameborder="0" allowfullscreen></iframe>'
        //},
        {
            attachTo: '#admin-menu-menu a[href="/admin/config"]',
            position: 7,
            description: 'In the admin menu, click on <em>Configuration</em>.',
            nextIf: eGuide.assertPath('admin/config')
        },
        {
            path: 'admin/config',
            attachTo: '#main-content a[href="/admin/config/system/site-information"]',
            position: 9,
            description: 'Under System configuration click the <em>Site infomation</em> link.',
            nextIf: eGuide.assertPath('admin/config/system/site-information')
        },
        {
            path: 'admin/config/system/site-information',
            attachTo: '#edit-site-name',
            position: 3,
            description: 'For the Site name enter "Results Bikes".',
            buttons: [
                {
                    name: "Insert text",
                    onclick: function () { eGuide.setInput('Results Bikes', '#edit-site-name') }
                },
                {
                    name: 'Next'
                }
            ],
            nextIf: function (guider) { console.log(guider); console.log(this); eGuide.assertInput('admin/config/system/site-information') },
            nextIfOn: {
                event: 'change'
            }
        },
        {
            path: 'admin/config/system/site-information',
            attachTo: '#edit-submit',
            position: 9,
            description: 'Click Save.',
        }
    ]
};

(function ($) {
    Drupal.behaviors.enterprise_guide = {
        attach: function (context, settings) {
            var ths = Drupal.behaviors.enterprise_guide;
            ths.guideId = 'siteTitle';

            if (!ths.guideId || !guides[ths.guideId]) {
                return;
            }
            ths.guide = guides[ths.guideId];

            ths.stepId = $.cookie('eguide_step');
            if (!ths.stepId && ths.stepId != '0') {
                ths.stepId = '0';
                $.cookie('eguide_step', ths.stepId, {path: '/' });
            }
            ths.stepId = parseInt(ths.stepId);

            ths.waits = 0;
            ths.waiting();
        },
        init: function() {

        },
        waiting: function () {
            if (Drupal.behaviors.enterprise_guide.checkReady()) {
                return Drupal.behaviors.enterprise_guide.initGuiders();
            }
            if (Drupal.behaviors.enterprise_guide.waits < 20) {
                Drupal.behaviors.enterprise_guide.waits++;
                setTimeout(function () {
                    Drupal.behaviors.enterprise_guide.waiting();
                }, 200);
            }
        },
        checkReady: function() {
            if(!$('#admin-menu').hasClass('admin-menu-processed')) {
                return 0;
            }
            return 1;
        },
        initGuiders: function () {
            var ths = Drupal.behaviors.enterprise_guide;
            var gSteps = [];
            var showId = '';
            var guide = ths.guide;
            var i, v, gi, $obj, tag, type;
            var guider;
console.log(ths.stepId);

            // determine if step has been completed
            for (i = ths.stepId; i < ths.guide.steps.length; i++) {
                if (guide.steps[ths.stepId].nextIf !== undefined) {
                    var n = ths.doCallback(guide.steps[ths.stepId].nextIf);
console.log(n);
                    if (n) {
                        ths.stepId++;
                        $.cookie('eguide_step', ths.stepId, {path: '/' });
                    }
                    else {
                        break;
                    }
                }
            }

            //guiders.push(ths.guide.steps[ths.stepId]);
            showId = ths.guideId + '-' + ths.stepId;

            var path = window.location.pathname.substr(1);

            var adminPage = $('body').hasClass('page-admin');
console.log(adminPage);


            for (i = ths.stepId; i < ths.guide.steps.length; i++) {
                v = ths.guide.steps[i];
                gi = gSteps.length;
                if (gi == 0 || (v.path && v.path == path)) {
                    v.id = ths.guideId + '-' + i;

                    v.title = v.title || guide.title;

                    if (guide.xButton !== undefined) {
                        v.xButton =  v.xButton || guide.xButton;
                    }
                    if (guide.buttons !== undefined) {
                        v.buttons =  v.buttons || guide.buttons;
                    }

                    v.onShows = v.onShows || [];
                    if (v.onShow) {
                        v.onShows.push(v.onShow);
                    }
                    //v.onShow = function (guider) { Drupal.behaviors.enterprise_guide.doCallbacks(guider.onShows); }
                    v.onShow = Drupal.behaviors.enterprise_guide.guiderOnShow;

                    // adjust guider position offset to compensate for admin menu on admin pages
                    if (adminPage) {
                        if (v.offset === undefined) {
                            v.offset = {
                                left: 0,
                                top: 0
                            };
                        }
                        if (v.offset.top) {
                            v.offset.top += 30;
                        }
                        else {
                            v.offset.top = 30;
                        }
                    }

                    gSteps.push(v);
                    if (gi > 0) {
                        gSteps[gi-1].next = v.id;
                    }

                    if (v.nextIfOn !== undefined && v.nextIfOn.event) {

                        if (v.nextIfOn.attachTo) {
                            $obj = jQuery(v.nextIfOn.attachTo);
                        }
                        else {
                            $obj = jQuery(v.attachTo);
                        }


                        tag = $obj.prop("tagName").toLowerCase();
                        type = $obj.attr("type").toLowerCase();
                        console.log(tag);
                        console.log(type);
                        if (v.nextIfOn.event == 'change') {

                        }
                        else {
                            $obj.on(v.nextIfOn.event, {guider: v}, function (event) {
                                console.log(event);
                                console.log(this);
                            });
                        }

                    }
                }
            }

            for (var i = 0; i < gSteps.length; i++) {
                guiders.createGuider(gSteps[i]);
            }
            guiders.show(showId);
            //guiders.createGuider(Drupal.behaviors.enterprise_guide.guider).show();
        },
        guiderOnShow: function (guider) {
            //console.log(arguments);
            /*
            $("#" + guider.id).colorbox({rel: 'gal', title: function(){
                var url = $(this).attr('href');
                return '<a href="' + url + '" target="_blank">Open In New Window</a>';
            }});
            */
            Drupal.behaviors.enterprise_guide.doCallbacks(guider.onShows);
        },
        doCallbacks: function (cbs) {
            var ret;
            for (var i = 0; i < cbs.length; i++) {
                ret.push(Drupal.behaviors.enterprise_guide.doCallback(cbs[i]));
            }
            return ret;
        },
        doCallback: function (cb) {
            if (typeof cb == 'function') {
                return cb.call(this);
            }
            else {
                return cb;
            }
        },
        assertPath: function (value, op) {
            var path = window.location.pathname.substr(1);
            if (path == value) {
                return 1;
            }
            return 0;
        }
    };
})(jQuery);
