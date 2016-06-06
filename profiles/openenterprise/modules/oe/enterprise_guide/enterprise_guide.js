/**
 * Created by tom on 9/3/15.
 */

function EGuide(jQuery) {
    var $ = jQuery;
};

EGuide.prototype.jqSelect = function (selector) {
    if (typeof selector == 'object') {
        return selector;
    }
    else if (selector != undefined) {
        return jQuery(selector);
    }
    else {
        return jQuery(this);
    }
}

EGuide.prototype.compValue = function (value0, value1, op) {
console.log(arguments);
    if (op == '!=') {
        return (value0 != value1);
    }
    else if (op == '=@') {
        return (value0.indexOf(value1) > -1)
    }
    else if (op == '!@') {
        return !(value0.indexOf(value1) > -1)
    }
    else {
        return (value0 == value1);
    }
}

EGuide.prototype.assertPath = function (value, op) {
    var path = window.location.pathname.substr(1);
    return eGuide.compValue(path, value, op);
}

EGuide.prototype.assertSystemPath = function (value, op) {
    var path = Drupal.settings.intel.config.systemPath;
    return eGuide.compValue(path, value, op);
}

EGuide.prototype.assertInput = function (value, op, selector) {
    var $obj = eGuide.jqSelect(selector);
    return eGuide.compValue($obj.val(), value, op);
}

EGuide.prototype.assertText = function (value, op, selector) {
    var $obj = eGuide.jqSelect(selector);
    return eGuide.compValue($obj.text(), value, op);
}

EGuide.prototype.setInput = function (value, selector) {
    var $obj = eGuide.jqSelect(selector);
    if ($obj.length) {
        $obj.val(value);
    }
}

var eGuide = new EGuide(jQuery);

(function ($) {
    Drupal.behaviors.enterprise_guide = {
        attach: function (context, settings) {
            var ths = Drupal.behaviors.enterprise_guide;
            ths.guideId = 'edit_content';

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
            // check if admin menu has been processed
            if(!$('#admin-menu').hasClass('admin-menu-processed')) {
                return 0;
            }
            // check if ckeditor fields exist and if ckeditor has been initialized
            var $obj = jQuery('.ckeditor-mod');
            if ($obj.length) {

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
            var systemPath = Drupal.settings.intel.config.systemPath;

            var adminPage = $('body').hasClass('page-admin');
console.log(adminPage);


            for (i = ths.stepId; i < ths.guide.steps.length; i++) {
                v = ths.guide.steps[i];
                gi = gSteps.length;

                if (gi == 0 || (v.path && v.path == path) || (v.systemPath && v.systemPath == systemPath)) {
                    v.i = i;
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
                        return;
                        if (v.nextIfOn.attachTo) {
                            $obj = jQuery(v.nextIfOn.attachTo);
                        }
                        else {
                            $obj = jQuery(v.attachTo);
                        }

                        if($obj && $obj.length) {
                            console.log(196);
                            tag = $obj.prop("tagName");
                            if (tag) {
                                //tag = tag.toLowerCase();
                            }
                            type = $obj.attr("type");
                            if (type) {
                                //type = type.toLowerCase();
                            }
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
            }

            for (var i = 0; i < gSteps.length; i++) {
                guiders.createGuider(gSteps[i]);
            }
            guiders.show(showId);
            //guiders.createGuider(Drupal.behaviors.enterprise_guide.guider).show();
        },
        guiderOnShow: function (guider) {
            //console.log(arguments);
console.log(guider);
            $.cookie('eguide_step', guider.i, {path: '/' });

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
    };
})(jQuery);
