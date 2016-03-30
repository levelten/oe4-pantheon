(function ($) {

  "use strict";

  var done = 0;

  Drupal.behaviors.enterpriseRel = {
    attach: function (context) {
      // Provide the vertical tab summaries.
      if (!done) {
        var vars = {
          view_dom_id: '#block-enterprise-rel-views-facet-filter',
          //view_dom_id: '.view-id-enterprise_blog_blocks .view-display-id-related',
          view_name: 'enterprise_blog_blocks',
          view_display_id: 'related',
          view_path: 'node/5?test=1',
          view_args: '',
          rel_add_tids: '4',
        };
        //loadView(vars);
        done = 1;
      }

    }
  };


  function loadView(data) {
    $.ajax({
      url: Drupal.settings.basePath + 'views/ajax',
      type: 'post',
      data: data,
      dataType: 'json',
      success: function (response) {
        console.log(response);
        console.log(data);
        if (response[2] !== undefined) {
          var viewHtml = response[2].data;
          console.log(viewHtml);
          $(data.view_dom_id).html(viewHtml + 'AJAX');
          Drupal.attachBehaviors(); //check if you need this.
        }
      }
    });
  }

})(jQuery);