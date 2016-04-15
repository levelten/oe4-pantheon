/**
 * @file Plugin for replacing filebrowser dialog with dialog from Drupal media module
 */
 (function($) {

  CKEDITOR.plugins.add('mediaBrowser', {
    requires: ['dialog', 'media'],
    init: function(editor) { /* Need to keep things happy */}
  });

  CKEDITOR.on('dialogDefinition', function(evt) {
    var definition = evt.data.definition,
    element;
    // Associate mediabrowser to elements with 'filebrowser' attribute.
    for (var i = 0; i < definition.contents.length; ++i) {
      if ((element = definition.contents[ i ])) {
        attachMediaBrowser(evt.editor, evt.data.name, definition, element.elements);
        if (element.hidden && element.filebrowser && element.type != 'fileButton') {
          element.hidden = false;
        }
      }
    }
  });

})(jQuery);
