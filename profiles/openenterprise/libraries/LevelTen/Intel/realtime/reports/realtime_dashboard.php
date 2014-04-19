<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN"
        "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
    <title>Page title</title>
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
    <script src="../../../../TimelineJS/compiled/js/storyjs-embed.js"></script>
    <script src="../../../../TimelineJS/compiled/js/timeline-min.js"></script>
    <script type="text/javascript" src="https://www.google.com/jsapi"></script>

    <script src="js/realtime_dashboard_model.js"></script>
    <script>
        google.load("visualization", "1", {packages:["corechart", 'table']});
        google.setOnLoadCallback(visualizationLoaded);
        function visualizationLoaded() {
          visualizationLoaded = true;
        }
        jQuery(document).ready(function(){
            doResize();
            rtdModel = new rtDashboardModel('rtdModel');
            rtdModel.pole();
            rtdView = new rtDashboardView('rtdView');
            rtdView.pole();
        });
        function doResize() {
          // set main div to height of window
          $('#dashboard').height($(window).height());
            jQuery('[class*="row-md-"]').each(function(index) {
              var classes = $(this).attr('class');
              classes = classes.split(' ');
              var rowCount = 12;
              for(var j in classes) {
                if (classes[j].substring(0, 7) == 'row-md-') {
                  var e = classes[j].split('-');
                  rowCount = parseInt(e[2]);
                  break;
                }
              }
              var parentHeight = $(this).parent().height();
              var height = parentHeight * rowCount / 12;
              $(this).height(height);
              // set pane heights
              $('.pane', this).each(function () {
                var paneHeight = $(this).parent().height();
                var panePadding = 2 * (parseInt($(this).css('margin')) + parseInt($(this).css('border-width')));
                $(this).height(paneHeight - panePadding);
              });
              $('.chart', this).each(function () {
                var paneHeight = $(this).parent().height();
                var panePadding = 2 * (parseInt($(this).css('margin')) + parseInt($(this).css('border-width')));
                $(this).height(paneHeight - panePadding);
              });
            });

        }
        jQuery(window).resize(doResize);


    </script>
    <link href='http://fonts.googleapis.com/css?family=Open+Sans:300,400,600,700|Dancing+Script|Antic+Slab' rel='stylesheet' type='text/css'>
    <style>
        body {
          background-color: #000;
          color: #FFF;
          font-family: 'Open Sans', "Helvetica Neue", Helvetica, Arial, sans-serif;
          margin: 0;
          padding: 0;
        }
        div {
          margin: 0;
          padding: 0;
        }
        #dashboard {

        }
        .chart rect {
          background-color: #333;
        }
        .pane-container {
          margin: 0;
          padding: 0;
          float: left;
          overflow: hidden;
        }
        .pane {
          /* border: #666 solid 1px; */
          background-color: #333;
          margin: 5px;
        }
        .pane h3 {
          font-size: 1.15em;
          margin: 0 0 0 1%;
        }
        .row {
          clear: both;
        }
        .col-md-12 {
          float: left;
          width: 100%;
        }
        .col-md-8 {
          float: left;
          width: 66.66%;
        }
        .col-md-6 {
          float: left;
          width: 50%;
        }
        .col-md-4 {
          float: left;
          width: 33.3%;
        }
        .col-md-3 {
          float: left;
          width: 25%;
        }
        #event-report {
          width: 50%;
        }
        #event-report {
          width: 50%;
        }
        #timeline {
          border: none;
        }
        #timeline.storyjs-embed.sized-embed {
          padding: 0;
          border-radius: 0px;
        }
        #timeline .vco-timeline {
          background-color: #222;
        }
        #timeline .timenav-background {
            background-color: #444;
        }
        #timeline .timenav-interval-background {
            background-color: #666;
        }
        .google-visualization-table-table {
          width: 100%;
        }
        .google-visualization-table-table tr {

        }
        .table-header-row {
          background-color: #191919;
          color: #FFF;
          border-bottom: 2px solid #444;

        }
        .table-header-row td:nth-child(2) {
          min-width: 50%;
        }
        .table-row {
          background-color: #333;
          color: #FFF;
        }
        .table-row-odd {
          background-color: #3b3b3b;
          color: #FFF;
        }
        .table-cell {
          border-bottom: 1px solid #222;
          border-left: 1px solid #222;
          padding: 0.5em .4em;
        }
      .table-header-cell {
        font-weight: bold;
        padding: 0.5em .4em;
        border-bottom: 2px solid #666;
      }
      .table-row-bump-up {
        background-color: #566C39 !important;
      }
      .table-row-bump-down {
        background-color: #ff0000 !important;
      }
    </style>
</head>
<body>
<div id="dashboard">
  <div id="row-top" class="row row-md-6">
    <!-- Top left 1-6x1-6 -->
    <div class="pane-container col-md-6 row-md-12">
      <div id="realtime-goals-report" class="pane-container col-md-12 row-md-4">
        <div class="pane">
          <div id="chart-realtime-goals" class="chart"></div>
        </div>
      </div>
      <div id="realtime-pageviews-report" class="pane-container col-md-12 row-md-4">
        <div class="pane">
          <h3 class="row-md-2">Pageviews</h3>
          <div class="col-md-12 row-md-10">
            <div id="chart-realtime-pageviews-min" class="chart col-md-8"></div>
            <div id="chart-realtime-pageviews-sec" class="chart col-md-4"></div>
          </div>
        </div>
      </div>
      <div id="realtime-events-report" class="pane-container col-md-12 row-md-4">
        <div class="pane">
          <h3 class="row-md-2">Events</h3>
          <div class="col-md-12 row-md-10">
            <div id="chart-realtime-events-min" class="chart col-md-8"></div>
            <div id="chart-realtime-events-sec" class="chart col-md-4"></div>
          </div>
        </div>
      </div>
    </div>
    <!-- Top middle 1-6x7-9 -->
    <div class="pane-container col-md-3 row-md-12">
      <div id="realtime-goals-report" class="pane-container col-md-12 row-md-6">
        <div class="pane">
          traffic sources
        </div>
      </div>

      <div id="realtime-pageviews-report" class="pane-container col-md-12 row-md-6">
        <div class="pane">
          <div id="chart-realtime-pageviews-table" class="chart table"></div>
        </div>
      </div>
    </div>

    <!-- Top right 1-6x10-12 -->
    <div class="pane-container col-md-3 row-md-12">
      <div id="realtime-goals-report" class="pane-container col-md-12 row-md-6">
        <div class="pane">
          referrer details
        </div>
      </div>
      <div id="realtime-pageviews-report" class="pane-container col-md-12 row-md-6">
        <div class="pane">
          <div id="chart-realtime-page-attrs-table" class="chart table"></div>
        </div>
      </div>
    </div>
  </div>




  <div id="row-bottom" class="row row-md-6">
    <!-- Bottom left 1-6x7-9 -->
    <div class="pane-container col-md-3 row-md-12">
      <div id="realtime-events-report" class="pane-container col-md-12 row-md-6">
        <div class="pane">
          <div id="chart-realtime-events-table" class="chart table"></div>
        </div>
      </div>

      <div id="realtime-pageviews-report" class="pane-container col-md-12 row-md-6">
        <div class="pane">
          <div id="chart-realtime-ctas-table" class="chart table"></div>
        </div>
      </div>
    </div>

    <!-- Bottom middle 1-6x7-9 -->
    <div class="pane-container col-md-3 row-md-12">
      <div id="realtime-events-report" class="pane-container col-md-12 row-md-6">
        <div class="pane">
          <div id="chart-realtime-events-detail-table" class="chart table"></div>
        </div>
      </div>

      <div id="realtime-pageviews-report" class="pane-container col-md-12 row-md-6">
        <div class="pane">
          <div id="chart-realtime-landingpages-table" class="chart table"></div>
        </div>
      </div>
    </div>

    <!-- Top right 1-6x10-12 -->
    <div class="pane-container col-md-6 row-md-12">
      <div id="visitors-report" class="pane-container col-md-12 row-md-12">
          <div class="pane">
              visitors
          </div>
      </div>
  </div>
</div>
</body>
</html>