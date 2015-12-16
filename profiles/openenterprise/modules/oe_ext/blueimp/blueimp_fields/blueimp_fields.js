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

            if (blueimp && settings.blueimp_fields && settings.blueimp_fields.slides) {

                document.getElementById('links').onclick = function(event) {
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
                    document.getElementById('links').getElementsByTagName('a'), {
                        container: '#blueimp-gallery-carousel',
                        carousel: true
                    }
                );

            } else {
                window.console.log("Something is wrong with the Blueimp gallery settings.");
            }

        }
    };

})(jQuery, Drupal);