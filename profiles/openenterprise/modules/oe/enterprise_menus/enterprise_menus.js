(function($) {
  
/**
 * Inject destination query strings for current page.
 */
Drupal.behaviors.destination = {
  attach:  function (context) {
    var settings = Drupal.settings.enterprise_menus;

    var escapeAdminPath = sessionStorage.getItem('escapeAdminPath');

    // Saves the last non-administrative page in the browser to be able to link back
    // to it when browsing administrative pages. If there is a destination parameter
    // there is not need to save the current path because the page is loaded within
    // an existing "workflow".
    if (!settings.currentPathIsAdmin && !/destination=/.test(window.location.search)) {
      sessionStorage.setItem('escapeAdminPath', settings.currentPath);
    }
    
    if (settings.destination) {
      $('a.menu-destination', context).each(function() {
        this.search += (!this.search.length ? '?' : '&') + settings.destination;
      });
    }
    var $toolbarEscape = $('[data-toolbar-escape-admin] a').once('escapeAdmin');
    if ($toolbarEscape.length) {
      if (settings.currentPathIsAdmin && escapeAdminPath) {
        $toolbarEscape.attr('href', '/' + escapeAdminPath);
        $toolbarEscape.closest('.toolbar-tab').removeClass('hidden');
      }
    }
  }
}

})(jQuery);
