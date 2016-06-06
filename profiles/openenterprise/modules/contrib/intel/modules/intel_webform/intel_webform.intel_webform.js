var _l10iq = _l10iq || [];

function L10iDrupalWebform(_ioq) {
    var ioq = _ioq;
    var io = _ioq.io;

    this.formSubmitAlterCallback = function (form_submit, data, $obj) {
        // check if a webform
        var id = $obj.attr('id');

        var e = id.split("-");
        if (e.length > 3 && (e[0] == 'webform') && (e[1] == 'client') && (e[2] == 'form')) {
            form_submit['type'] = 'webform';
            form_submit['fid'] = e[3];
            form_submit['eventLabel'] = 'node/' + e[3];
        }
    };

    _l10iq.push(['log', "l10iWebformTracker.init()"]);
    _l10iq.push(['addCallback', 'formSubmitAlter', this.formSubmitAlterCallback, this]);
}

_l10iq.push(['providePlugin', 'drupalWebform', L10iDrupalWebform, {}]);


