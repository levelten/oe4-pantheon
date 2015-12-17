/**
 * @file
 * blueimp_fields.js
 *
 * Activate Blueimp gallery fields.
 */

var Drupal = Drupal || {};

(function($, Drupal) {
    "use strict";

    Drupal.behaviors.blueimp_fields = {
        attach: function(context, settings) {

            window.console.log(settings);
            window.console.log(typeof blueimp);

            if (settings.blueimp_fields && settings.blueimp_fields.slides) {

                var slides = settings.blueimp_fields.slides;

                for (var i = slides.length - 1; i >= 0; i--) {
                    window.console.log(slides[i]);
                }

                document.getElementById('blueimp-links-1').onclick = function(event) {
                    event = event || window.event;
                    var target = event.target || event.srcElement,
                        link = target.src ? target.parentNode : target,
                        options = {
                            index: link,
                            event: event
                        },
                        links = this.getElementsByTagName('a');
                    blueimp.Gallery(links, options);
                };

                blueimp.Gallery(
                    document.getElementById('blueimp-links-1').getElementsByTagName('a'), {
                        container: '#blueimp-gallery-1',
                        carousel: true
                    }
                );

            } else {
                window.console.log("Something is wrong with the Blueimp gallery settings.");
            }
            // var gallery = $('#blueimp-gallery-1').data('gallery');

        }
    };

})(jQuery, Drupal);