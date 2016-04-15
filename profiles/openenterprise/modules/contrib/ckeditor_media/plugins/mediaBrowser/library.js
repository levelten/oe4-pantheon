
/**
 *  @file
 *  Attach CKEditor Media behaviors.
 */

 (function ($) {
  Drupal.media = Drupal.media || {};

  Drupal.settings.ckeditor.plugins['mediaBrowser'] = {

    // Traverse through the content definition and attach mediabrowser to
    // elements with 'filebrowser' attribute.
    //
    // @param String
    //            dialogName Dialog name.
    // @param {CKEDITOR.dialog.definitionObject}
    //            definition Dialog definition.
    // @param {Array}
    //            elements Array of {@link CKEDITOR.dialog.definition.content}
    //            objects.
    attachMediaBrowser: function (editor, dialogName, definition, elements) {
      if (!elements || !elements.length)
        return;

      var element, fileInput;

      for (var i = elements.length; i--; ) {
        element = elements[ i ];

        if (element.type == 'hbox' || element.type == 'vbox' || element.type == 'fieldset')
          attachMediaBrowser(editor, dialogName, definition, element.children);

        if (!element.filebrowser)
          continue;

        if (typeof element.filebrowser == 'string') {
          var fb = {
            action: (element.type == 'fileButton') ? 'QuickUpload' : 'Browse',
            target: element.filebrowser
          };
          element.filebrowser = fb;
        }

        if (element.filebrowser.action == 'Browse') {
          element.onClick = mediaBrowser;
          element.label = 'Upload/' + editor.lang.common.browseServer; // Fix language here.
          // Make sure the button is visible since we are handling it with media.
          element.hidden = false;
        } else if (element.filebrowser.action == 'QuickUpload' && element[ 'for' ]) {
          // We don't need two buttons, hide this one and just keep the browse button.
          element.hidden = true;
        }
      }
    },

    mediaBrowser: function (evt) {
      var dialog = evt.data.dialog;
      // Media z-index is 10002 so we need to be below that.
      var dialogElement = dialog.getElement().getFirst();
      dialogElement.setStyle('z-index', 10001);
      // Invoke the media popup for file selection.
      var mediaIframe = Drupal.media.popups.mediaBrowser(function(mediaFiles) {
        if (mediaFiles.length > 0) {
          // There is probably a better way of getting the url for the file
          // but media returns the object with an absolute url and the uri.
          // We don't have access to file_create_url in javascript so we can't
          // use that. For now, just remove the server name from the absolute
          // url to get the relative. FIX THIS!!!
          var fileUrl = mediaFiles[0].url.replace(location.origin, '');
          var parts = evt.sender.filebrowser.target.split(':');
          dialog.setValueOf(parts[0], parts[1], fileUrl);
        }
      });
      $(mediaIframe).parent().css({'z-index':'10002'});
    },

  };

})(jQuery);
