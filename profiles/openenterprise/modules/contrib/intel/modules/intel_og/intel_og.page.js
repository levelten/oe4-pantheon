var _l10iq = _l10iq || [];

function L10iDrupalOg(_ioq, config) {



  // attach gid to form submissions
  this.formSubmitAlterCallback = function (formSubmit, data, $obj, event) {
    var og =  this.getGroup();

    if (og) {
        formSubmit['og'] = og;
    }
  };

    _l10iq.push(['_log', "l10iOG.init()"]);
    _l10iq.push(['addCallback', 'formSubmitAlter', this.formSubmitAlterCallback, this]);
};

L10iDrupalOg.prototype.getGroup = function () {
    return _l10iq.push(['get', 'pa.og']);
};

_l10iq.push(['providePlugin', 'drupalOg', L10iDrupalOg, {}]);