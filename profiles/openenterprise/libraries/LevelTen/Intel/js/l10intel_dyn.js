var _ioq = _ioq || [];
function L10iDyn (_ioq) {
    var ioq = _ioq;
    var io = _ioq.io;

}

L10iDyn.prototype.display = function (set, elm) {
    var setSelector, elmtSelector, $showElm, $setElms;
    $set = jQuery(".intel-dynset" + set);
    $showElm = $set.find(".intel-dynelm" + elm);
    if ($showElm.length == 0) {
        return;
    }
    $setElms = $set.find("[class*='intel-dynelm']");
    $setElms.hide(0);
    $showElm.show(0);
}

_ioq.push(['providePlugin', 'dyn', L10iDyn, {}]);