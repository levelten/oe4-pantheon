/**
 * transforms first character of string to upper case
 * @returns {string}
 */
String.prototype.ucfirst = function() {
    return this.charAt(0).toUpperCase() + this.slice(1);
}

/**
 * Removes elements from array
 * @param from
 * @param to
 * @returns {Number}
 */
Array.prototype.remove = function(from, to) {
    var rest = this.slice((to || from) + 1 || this.length);
    this.length = from < 0 ? this.length + from : from;
    return this.push.apply(this, rest);
};

function getQueryStringValue(key) {
    key = key.replace(/[*+?^$.\[\]{}()|\\\/]/g, "\\$&"); // escape RegEx meta chars
    var match = location.search.match(new RegExp("[?&]"+key+"=([^&]+)(&|$)"));
    return match && decodeURIComponent(match[1].replace(/\+/g, " "));
}

function arraySearch(needle, haystack) {
    for (var key in haystack) {
        if (needle == haystack[key]) {
            return key;
        }
    }
    return false;
}