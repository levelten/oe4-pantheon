/**
 * @file
 * blueimp_fields.js
 *
 * Activate Blueimp gallery fields.
 */

var Drupal = Drupal || {};

(function($, Drupal) {
    "use strict";

    function blueimp_lightbox(link_id) {
        document.getElementById(link_id).onclick = function(event) {
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
    }

    function blueimp_carousel(link_id, gallery_id) {
        blueimp.Gallery(
            document.getElementById(link_id).getElementsByTagName('a'), {
                container: "#"+gallery_id,
                carousel: true,
                thumbnailIndicators: true,
            }
        );
    }

    Drupal.behaviors.blueimp_fields = {
        attach: function(context, settings) {

                if (settings.blueimp_fields && settings.blueimp_fields.slides) {

                    var slides = settings.blueimp_fields.slides;

                    for (var i = slides.length - 1; i >= 0; i--) {
                        window.console.log(slides[i]);

                        if (slides[i].display_style === "lightbox") {
                            blueimp_lightbox(slides[i].link_id);

                        } else if (slides[i].display_style === "carousel") {
                            blueimp_carousel(slides[i].link_id, slides[i].gallery_id);
                        }
                    }

                } else {
                    window.console.log("Something is wrong with the Blueimp gallery settings.");
                }
                // var gallery = $('#blueimp-gallery-1').data('gallery');

            } // end attach
    }; // Drupal.behaviors

})(jQuery, Drupal);