(function ($) {

  "use strict";

  var done = 0;

  Drupal.behaviors.enterpriseRel = {
    attach: function (context) {
      io('addCallback', 'domReady', this.init);
    },
    init: function () {
      // only execute once
      if (done) {
        return
      }
      var k, i, tid, systemPath, pt, vt, storage, tids = [];
      var taxAttrs = Drupal.settings.enterprise_rel.intel_tax_attrs;
      var systemPath = io('get', 'p.systemPath', '');
      for (i = 0; i < taxAttrs.length; i++) {
        k = taxAttrs[i];
        vt = io('get', 'va.' + k, []);
        // add terms on visitor
        for (tid in vt) {
          tids.push(tid);
        }
      }

      var vars = {
        //view_dom_id: '#block-enterprise-rel-views-facet-filter',
        view_dom_selector: '.view-enterprise-blog-blocks.view-display-id-rel',
        //view_dom_id: '.view-id-enterprise_blog_blocks .view-display-id-related',
        view_name: 'enterprise_blog_blocks',
        view_display_id: 'rel',
        view_path: systemPath,
        view_args: '',
        rel_add_tids: tids.join(','),
      };
      console.log(vars);
      //loadView(vars);
      done = 1;
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
        if (response[2] !== undefined) {
          var viewHtml = response[2].data;
          console.log(viewHtml);
          $(data.view_dom_selector).html(viewHtml + '<!-- AJAX load -->' );
          Drupal.attachBehaviors(); //check if you need this.
        }
      }
    });
  }

})(jQuery);