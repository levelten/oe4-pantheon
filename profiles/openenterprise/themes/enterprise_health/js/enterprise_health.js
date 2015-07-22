/**
 * @file
 * enterprise_health.js
 *
 * Provides general enhancements.
 */

var Drupal = Drupal || {};

(function($, Drupal){
  "use strict";

  Drupal.behaviors.enterprise_healthTeamHover = {
    attach: function(context) {

      // Set jQuery object for team block.
      var $team = $('.front .team', context);

      // When anchor text is hovered i.e. mousenter(), fade image to 70% opacity.
      // Return image to normal opacity on mouseleave().
      // Duration is set to 0 so the fade happens instantaneously.
      $("a", $team).hover(function() {
        $(this).parent().children("img").fadeTo(0, 0.6);
      }, function() {
        $(this).parent().children("img").fadeTo(0, 1);
      });
    }
  };

})(jQuery, Drupal);
