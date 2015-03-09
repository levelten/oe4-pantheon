(function ($) {

  Drupal.behaviors.intel_admin_content_alter = {
    attach: function (context, settings) {

      // Set up vars
      var colIndex = 0,
          colCount = 0,
          hrefs = [],
          data = {'hrefs': hrefs},
          cms_hostpath = Drupal.settings.intel.cms_hostpath,
          module_path = Drupal.settings.intel.module_path,
          protocol = ('https:' == document.location.protocol) ? 'https://' : 'http://',
          imgsrc = protocol + cms_hostpath + module_path + "/images/ajax_loader_row.gif",
          url = protocol + cms_hostpath + "intel/admin_content_alter_js", //?callback=?";
          query = getUrlVars(),
          intelStatusCode = false; // Testing for 500

      // If standard admin form
      if (jQuery("#node-admin-content", context).length > 0) {
        
        jQuery("#node-admin-content thead tr:nth-child(1) th", context).each(function () {
          if ($(this).text() == "Title") {
            colIndex = colCount+1;
          }
          if ($(this).attr('colspan')) {
            colCount += +$(this).attr('colspan');
          } else {
            colCount++;
          }
        });
        //alert("ci=" + colIndex + ", cc=" + colCount);
      }

      // If no columns, return.
      if (colIndex === 0) {
        return;
      }

      // Add table headers for Intel data.
      $("#node-admin-content thead th:eq(" + (colIndex-1) + ")", context).after('<th>Score</th><th>Entrs</th><th>Views</th>');
      
      // Map URL parameters to data array.
      for (var i in query) {
        if (i == 'render') {
          continue;
        }
        data[i] = query[i];
      }

      // Return Intel JSON from admin_content_alter_js
      jQuery.getJSON(url, data)
      .always(function() {
        intelStatusCode = true;
        // By default, add loading gif.
        $("#node-admin-content tr", context).each ( function( index ) {
          var href = $(this).find("td:eq(1) a").attr("href");
          if (typeof href != 'undefined') {
            hrefs.push(href);
            $(this).find("td:eq(" + (colIndex-1) + ")").after('<td data-path="' + href + '" colspan="3" style="text-align:center;"><img src="' + imgsrc + '"></td>');
          }
        });
      })
      .fail(function() {
        // Remove gif if fails.
        $("#node-admin-content tr", context).each ( function( index ) {
          $(this).find("td:eq(" + colIndex + ")").replaceWith('<td colspan="3" style="text-align:center;">NA</td>');
        });
      })
      .success(function(data) {
        // Fill in Intel data if succeeds
        $("#node-admin-content tr", context).each ( function( index ) {
          var href = $(this).find("td:eq(1) a").attr("href");
          if (typeof href != 'undefined') {
            if (typeof data.rows[href] != 'undefined') {
              $(this).find("td:eq(" + colIndex + ")").replaceWith(data.rows[href]);
            }
            else {
              $(this).find("td:eq(" + colIndex + ")").replaceWith('<td colspan="3" style="text-align:center;">NA</td>');
            }
          }
        });
      });

      // Status code test failed.
      if (!intelStatusCode) {
        window.console.log("Status code failed.");
      }

    }
  };
  
  function getUrlVars() {
    var vars = {}, hash;
    if (window.location.href.indexOf('?') == -1) {
      return vars;
    }
    var hashes = window.location.href.slice(window.location.href.indexOf('?') + 1).split('&');

    for (var i = 0; i < hashes.length; i++){
      hash = hashes[i].split('=');
      //vars.push(hash[0]);
      vars[hash[0]] = hash[1];
    }
    return vars;
  }

})(jQuery);
