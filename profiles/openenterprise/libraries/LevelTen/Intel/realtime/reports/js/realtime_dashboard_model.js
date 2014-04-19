
Array.prototype.remove = function(from, to) {
    var rest = this.slice((to || from) + 1 || this.length);
    this.length = from < 0 ? this.length + from : from;
    return this.push.apply(this, rest);
};

function rtDashboardModel (name) {
    this.name = name;
    this.log = {};
    this.logNew = {};
    this.logDel = {};
    this.sessions = {};
    this.realtimeApiUrl = '../';
    this.timeDelta = 0;
    this.lastFetchTime = 0;
    this.authors = {
        1: 'User 1',
        3: 'Tom McCracken',
        4: 'Brent Bice'
    };
    this.terms = {
        1: 'Inbound marketing',
        2: 'User Experience',
        3: 'Web Design',
        4: 'conversion rates',
        5: 'inbound marketing',
        6: 'Internet Marketing',
        7: 'SEO',
        8: 'Web design',
        9: 'Online marketing',
        10: 'Uncategorized'
    };
    this.contentTypes = {
        'page': 'Basic pages',
        'blog': 'Blog posts',
        'webform': 'Webforms',
        'landingpage': 'Landing pages',
        'thankyou': 'Thank you pages',
        'press_release': 'Press releases'
    };

    this.pole = function pole() {
        // limit fetch starttime to 30 minutes ago
        this.lastFetchTime = this.getTime() - 1800;
        rtdModel.fetchAll();

        window.setInterval(function () {
            rtdModel.fetchAll();
        }, 5000);
    };

    this.fetchAll = function fetchAll() {
        if ((typeof(sp) == 'undefined')) {
            this.fetchLog();
        }
    }

    this.fetchLog = function fetchLog () {
        var func = 'track/log';
        var time = this.getTime();
        var params = {
            st: this.lastFetchTime,
            t: time - 1
        };
        this.lastFetchTime = time - 1;
        var vars = {
            dataType: 'json',
            url: this._getRealtimeApiUrl(func, params),
            data: {},
            //jsonpCallback: this.name + '.fetchLogReturn',
            success: function (json){
//console.log(json);
                rtdModel.addToLog(json.instances);
                //rtdModel.buildTimeline();
            }
        };
        //console.log(vars);
        jQuery.ajax(vars);
    };

    this.addToLog = function addToLog(data) {
        //console.log('addToLog data:'); console.log(data);
        var time;
        for (var i in data) {
            var e = data[i];
            if (e.t == undefined) {
                continue;
            }
            time = e.t;
            // initialize element if does not exist
            if (this.log[time] == undefined) {
                this.log[time] = [];
            }
            this.log[time].push(data[i]);
            // add data to new log
            if (this.logNew[time] == undefined) {
                this.logNew[time] = [];
            }
            this.logNew[time].push(data[i]);
        }

        // remove any data older than 30 minutes
        var time0 = this.getTime() - 1800;
        for (var t in this.log) {
            var time = parseInt(t);
            if (time >= time0) {
                break;
            }
            this.logDel[time] = this.log.t;
            delete this.log.t;
        }
        //console.log(this.log);
    }

    this.fetchLogReturn = function fetchLogReturn(data) {
        console.log(data);
    }

    /**
     * Constructs the JSON url
     * @param func
     * @param params
     * @param data
     * @return
     */
    this._getRealtimeApiUrl = function _getJSONUrl(func, params, data) {
        var url;
        //params.vtk = this.vtk;
        /*
         url = ('https:' == document.location.protocol) ? 'https:' : 'http:';
         // if func starts with //, treat as custom url request
         if (func.indexOf('//') == 0) {
         url += func + '?';
         }
         else {
         url += '//' + this.apiUrl + 'index.php?q=' + func + '&';
         }
         */
        url = this.realtimeApiUrl + 'index.php?q=' + func;
        var paramStr = this._encodeUrlQueryParams(params);
        if (paramStr != '') {
            url += '&' + paramStr;
        }

        if (data != undefined) {
            url += '&data=' + encodeURIComponent(JSON.stringify(data));
        }
        return url;
    };

    this.getTime = function getTime() {
        var time = new Date().getTime();
        return Math.round(time/1000) + this.timeDelta;
    };

    /**
     * Encodes parameters array as url query elements
     * @param params
     * @return
     */
    this._encodeUrlQueryParams = function _encodeUrlQueryParams(params) {
        var str = [], k;
        for (k in params) {
            if (params.hasOwnProperty(k)) {
                str.push(encodeURIComponent(k) + "=" + encodeURIComponent(params[k]));
            }
        }
        return str.join("&");
    };

    this.buildTimeline = function buildTimeline() {
        console.log(this.instances);

        var curTime = this.getTime();
        var timelineData = {
            headline: "Test Headline",
            type: "default",
            text: "Intro body text goes here",
            startDate: this.formatTimelineDate(curTime - 1800),
            endDate: this.formatTimelineDate(curTime),
            date: []
        };
        console.log(this.instances);
        for (var i in this.instances) {
            var inst = this.instances[i];
            var time = this.formatTimelineDate(inst.time);
            timelineData.date.push({
                startDate: time,
                endDate: time,
                headline: inst.path,
                text: "test text",
                tag: "pageview",
                asset: {
                    media: "http://" + inst.host + inst.path
                }
            });
        }
        console.log(timelineData);
        var data = {
            type:       'timeline',
            width:      $('#timeline-report .pane').width() + 2,
            height:     $('#timeline-report .pane').height() + 16,
            source:     {timeline: timelineData},
            embed_id:   'timeline',
            //debug: true,
            //start_zoom_adjust:  '2',
            start_at_end: true
        };
        createStoryJS(data);
        //console.log(data);
        //dsm(VMM);
        //var timeline = new VMM.Timeline();
        //console.log(timeline);
        //timeline.init({timeline: timelineData});
    };

    this.formatTimelineDate = function formatTimelineDate(time) {
        var d = new Date(1000 * parseInt(time));
        //var time = d.getFullYear() + ',' + (d.getMonth()+1) + ',' + d.getDate() + ' ';
        var time =  (d.getMonth()+1) + '/' + d.getDate() + '/' + d.getFullYear()  + ' ';
        var t = d.getHours();
        time += ((''+t).length<2 ? '0' : '') + t;
        t = d.getMinutes();
        time += ':' + ((''+t).length<2 ? '0' : '') + t;
        t = d.getSeconds();
        time += ':' + ((''+t).length<2 ? '0' : '') + t;
        return time;
    };

    this._unserializeCustomVar = function (str) {
        str = decodeURIComponent(str);
        var obj = {}, a, b, i, k;
        a = str.split("&");
        for (i in a) {
            if (a.hasOwnProperty(i)) {
                b = a[i].split("=");
                if (b[0] == '') {
                    continue;
                }
                k = b[0].split('.');
                if ((k.length > 1) && (obj[k[0]] == undefined)) {
                    obj[k[0]] = {};
                }
                if (b.length == 2) {
                    if (k.length > 1) {
                      obj[k[0]][k[1]] = isNaN(b[1]) ? b[1] : Number(b[1]);
                    }
                    else {
                        obj[k[0]] = isNaN(b[1]) ? b[1] : Number(b[1]);
                    }
                }
                else {
                    if (k.length > 1) {
                        obj[k[0]][k[1]] = '';
                    }
                    else {
                        obj[k[0]] = '';
                    }
                }
            }
        }
        return obj;
    };
}

function rtDashboardView (name) {
    this.model;
    this.charts = {};
    this.chartData = {};
    this.chartDivs = {
        pages: 'chart-realtime-pageviews-table',
        pageAttrs: 'chart-realtime-page-attrs-table',
        events: 'chart-realtime-events-table',
        eventDetails: 'chart-realtime-events-details-table',
        ctas: 'chart-realtime-ctas-table',
        lps: 'chart-realtime-landingpages-table'
    }
    this.chartIndex = {
        pvTable: {},
        pageAttrs: {},
        eTable: {},
        edTable: {},
        ctaTable: {},
        lpTable: {}
    };
    this.stats = {
        pages: {},
        pageAttrs: {},
        events: {},
        ctas: {},
        lps: {}
    };
    this.statsDelta = {},
    this.chartBumps = {
        pages: {},
        pageAttrs: {},
        events: {},
        ctas: {},
        lps: {}
    };
    this.chartRotation = {
        pageAttrs: [
            ['ct'],
            ['ct', 'blog'],
            ['t'],
            ['a']
        ]
    };
    this.chartRotationI = {
        pageAttrs: 0,
        eventDetail: 0
    };
    this.pageAttrsChartLabels = {
        a: 'Authors',
        ct: 'Content types',
        ctd: '%key pages'
    };
    this.pageAttrsActive = [];
    this.eventDetailCharts = [
      'Social share',
      'Comment'
    ];
    this.eventDetailActive = 'Social share';
    this.statsDelta = {},
    this.lastSecOffsets = {};
    this.lastBuildCharts = 0;
    this.chartColors = [
        '#338fac',
        '#8fc545',
        '#E89B0C'
    ];

    this.initStatsDelta = function initStatsDelta() {
        this.statsDelta = {
            pages: {},
            pageAttrs: {},
            events: {},
            ctas: {},
            lps: {}
        };
    };

    this.rotationCount = 0;
    this.pole = function pole() {
//return;
        rtdView.buildAll();

        window.setInterval(function () {
            rtdView.buildAll();

        }, 2000);
    };


    this.buildAll = function buildAll() {
        if ((typeof(sp) == 'undefined')) {
            this.buildCharts();
            if (rtdView.rotationCount > 5) {
                rtdView.rotateReports();
                rtdView.rotationCount = 0;
            }
            else {
                rtdView.rotationCount++;
            }
        }
    };

    this.buildCharts = function buildCharts() {
        var log = rtdModel.log;
        var logNew = rtdModel.logNew;
        rtdModel.logNew = {};
        // clear previous statsDelta values
        this.initStatsDelta();

        var curTime = rtdModel.getTime();
        var maxValue = 0;
        //console.log(log);
        //console.log(curTime);

        var secTime0 = curTime - 60;
        var minTime0 = curTime - 1800;

        var curDate = new Date(1000 * curTime);
        var curSeconds = curDate.getSeconds();
        var curTimeMin = curTime - curSeconds;
        //var secPer = (60 - curSeconds - 1)/60;
        var secPer = curSeconds/60;
        var lastBuildDate = new Date(1000 * this.lastBuild);
        var lastBuildSeconds = lastBuildDate.getSeconds();


        var col1Style = 'stroke-color: ' + this.chartColors[0] + '; stroke-width: 2; fill-opacity: 0.4';
        var col2Style = 'stroke-color: ' + this.chartColors[1] + '; stroke-width: 2; fill-opacity: 0.4';
        if (this.chartData.pvMin == undefined) {
            this.chartData.pvMin = new google.visualization.DataTable();
            this.chartData.pvMin.addColumn('number', 'Time');
            this.chartData.pvMin.addColumn('number', 'Entrances');
            this.chartData.pvMin.addColumn({type: 'string', role: 'style'});
            this.chartData.pvMin.addColumn('number', 'Pageviews');
            this.chartData.pvMin.addColumn({type: 'string', role: 'style'});
            for (var i = 0; i < 30; i++) {
                this.chartData.pvMin.addRow([i*60, 0, col1Style, 0, col2Style]);
            }
        }
        if (this.chartData.pvSec == undefined) {
            this.chartData.pvSec = new google.visualization.DataTable();
            this.chartData.pvSec.addColumn('number', 'Time');
            this.chartData.pvSec.addColumn('number', 'Entrances');
            this.chartData.pvSec.addColumn('number', 'Pageviews');
        }
        if (this.chartData.eMin == undefined) {
            this.chartData.eMin = new google.visualization.DataTable();
            this.chartData.eMin.addColumn('number', 'Time');
            this.chartData.eMin.addColumn('number', 'Valued events');
            this.chartData.eMin.addColumn({type: 'string', role: 'style'});
            this.chartData.eMin.addColumn('number', 'Events');
            this.chartData.eMin.addColumn({type: 'string', role: 'style'});
            for (var i = 0; i < 30; i++) {
                this.chartData.eMin.addRow([i*60, 0, col1Style, 0, col2Style]);
            }
        }
        if (this.chartData.eSec == undefined) {
            this.chartData.eSec = new google.visualization.DataTable();
            this.chartData.eSec.addColumn('number', 'Time');
            this.chartData.eSec.addColumn('number', 'Valued events');
            this.chartData.eSec.addColumn('number', 'Events');
        }

        if (this.chartData.pvTable == undefined) {
            this.chartData.pvTable = new google.visualization.DataTable();
            this.chartData.pvTable.addColumn('string', 'Pages');
            this.chartData.pvTable.addColumn('number', 'Ent');
            this.chartData.pvTable.addColumn('number', 'Pvs');
            this.chartData.pvTable.addColumn('number', 'Val');
        }

        if (this.chartData.eTable == undefined) {
            this.chartData.eTable = new google.visualization.DataTable();
            this.chartData.eTable.addColumn('string', 'Event categories');
            this.chartData.eTable.addColumn('number', 'Evts');
            this.chartData.eTable.addColumn('number', 'Val');
        }
        if (this.chartData.edTable == undefined) {
            this.chartData.edTable = new google.visualization.DataTable();
            this.chartData.edTable.addColumn('string', 'Event details');
            this.chartData.edTable.addColumn('number', 'Evts');
            this.chartData.edTable.addColumn('number', 'Val');
        }
        if (this.chartData.ctaTable == undefined) {
            this.chartData.ctaTable = new google.visualization.DataTable();
            this.chartData.ctaTable.addColumn('string', 'Calls to action');
            this.chartData.ctaTable.addColumn('number', 'Imps');
            this.chartData.ctaTable.addColumn('number', 'Clks');
            this.chartData.ctaTable.addColumn('number', 'Clk%');
            var formatter = new google.visualization.NumberFormat({suffix: '%', fractionDigits: 1});
            formatter.format(this.chartData.ctaTable, 3); // Apply formatter to second column
        }
        if (this.chartData.lpTable == undefined) {
            this.chartData.lpTable = new google.visualization.DataTable();
            this.chartData.lpTable.addColumn('string', 'Landing pages');
            this.chartData.lpTable.addColumn('number', 'Views');
            this.chartData.lpTable.addColumn('number', 'Convs');
            this.chartData.lpTable.addColumn('number', 'Conv%');
        }


        var rowPvMinInit = [0, 0, col1Style, 0, col2Style];
        if (curSeconds < lastBuildSeconds) {
            for (var i = 29; i > 0; i--) {
                for (var j = 0; j < 4; j++) {
                  var value = this.chartData.pvMin.getValue(i-1, j);
                  this.chartData.pvMin.setValue(i, j, value);
                  var value = this.chartData.eMin.getValue(i-1, j);
                  this.chartData.eMin.setValue(i, j, value);
                }
            }
            for (var j = 0; j < 4; j++) {
                this.chartData.pvMin.setValue(0, j, rowPvMinInit[j]);
                this.chartData.eMin.setValue(0, j, rowPvMinInit[j]);
            }
        }
        else {
        for (var i = 0; i < 30; i++) {
            var time = this.chartData.pvMin.getValue(i, 0);
            //min = Math.floor(min);
            if (this.lastBuild > 0) {
                time = time + (curSeconds - lastBuildSeconds);
            }
            else {
                time = time + curSeconds;
            }
            this.chartData.pvMin.setValue(i, 0, time);
            this.chartData.eMin.setValue(i, 0, time);
        }
        }

        // decrement time of existing rows
        var pvSecIndexes = [];
        var rows = this.chartData.pvSec.getNumberOfRows();
        for (var i = 0; i < rows; i++) {
            var value = this.chartData.pvSec.getValue(i, 0);
            if (curSeconds < lastBuildSeconds) {
              value += (curSeconds - lastBuildSeconds + 60);
            }
            else {
              value += (curSeconds - lastBuildSeconds);
            }
            if (value > 62) {
                this.chartData.pvSec.removeRow(i);
                rows--;
            }
            else {
                pvSecIndexes[value] = i;
                this.chartData.pvSec.setValue(i, 0, value);
            }
        }

        var eSecIndexes = [];
        var rows = this.chartData.eSec.getNumberOfRows();
        for (var i = 0; i < rows; i++) {
            var value = this.chartData.eSec.getValue(i, 0);
            if (curSeconds < lastBuildSeconds) {
                value += (curSeconds - lastBuildSeconds + 60);
            }
            else {
                value += (curSeconds - lastBuildSeconds);
            }
            if (value > 62) {
                this.chartData.eSec.removeRow(i);
                rows--;
            }
            else {
                eSecIndexes[value] = i;
                this.chartData.eSec.setValue(i, 0, value);
            }
        }
        //console.log(curSeconds + ', ' + lastBuildSeconds);
        //console.log(pvSecIndexes);

        var minData = [];
        var count = 0;
        var theLog = (this.lastBuild == 0) ? log : logNew;
        for (var i in theLog) {
            var logElement = theLog[i];
            var index = 0;
            var t = parseInt(i);
            // skip if t is greaterthan the browsers current time
            if (t > curTime) {
              continue;
            }
            var d = new Date(1000 * t);
            if (t >= minTime0) {
                var counts = this.getLogElementTypeCount(logElement);
//console.log(counts);
                row = 29 - Math.floor((t - minTime0) / 60);
//console.log(row);
                if (counts.siteAdd.pageviews > 0) {
                    count = this.chartData.pvMin.getValue(row, 3);
                    this.chartData.pvMin.setValue(row, 3, (counts.siteAdd.pageviews - counts.siteAdd.entrances) + count);
                    count = this.chartData.pvMin.getValue(row, 1);
                    this.chartData.pvMin.setValue(row, 1, counts.siteAdd.entrances + count);
                }
                if (counts.siteAdd.events > 0) {
                    count = this.chartData.eMin.getValue(row, 3);
                    this.chartData.eMin.setValue(row, 3, (counts.siteAdd.events - counts.siteAdd.valuedEvents) + count);
                    count = this.chartData.eMin.getValue(row, 1);
                    this.chartData.eMin.setValue(row, 1, counts.siteAdd.valuedEvents + count);
                }
            }
            if (t >= secTime0) {
                time = curTime - t;
                // check if row exists with time index. If not, add new row, otherwise
                // update
                if (counts.siteAdd.pageviews > 0) {
                    if (pvSecIndexes[time] == undefined) {
                        this.chartData.pvSec.addRow([time, counts.siteAdd.entrances, (counts.siteAdd.pageviews - counts.siteAdd.entrances)]);
                    }
                    else {
                        var row = pvSecIndexes[time];
                        count = this.chartData.pvSec.getValue(row, 2);
                        this.chartData.pvSec.setValue(row, 2, (counts.siteAdd.pageviews - counts.siteAdd.entrances) + count);
                        count = this.chartData.pvSec.getValue(row, 1);
                        this.chartData.pvSec.setValue(row, 1, counts.siteAdd.entrances + count);
                    }
                }
                if (counts.siteAdd.events > 0) {
                    if (eSecIndexes[time] == undefined) {
                        this.chartData.eSec.addRow([time, counts.siteAdd.valuedEvents, (counts.siteAdd.events - counts.siteAdd.valuedEvents)]);
                    }
                    else {
                        var row = eSecIndexes[time];
                        count = this.chartData.eSec.getValue(row, 2);
                        this.chartData.eSec.setValue(row, 2, (counts.siteAdd.events - counts.siteAdd.valuedEvents) + count);
                        count = this.chartData.eSec.getValue(row, 1);
                        this.chartData.eSec.setValue(row, 1, counts.siteAdd.valuedEvents + count);
                    }
                }

            }
        }
        //console.log(this.chartData.pvMin.toJSON());
console.log(this.statsDelta);
        // page table build
        for (var key in this.statsDelta.pages) {
            var c = this.statsDelta.pages[key];
            if (this.chartIndex.pvTable[key] == undefined) {
                this.chartIndex.pvTable[key] = this.chartData.pvTable.getNumberOfRows();
                this.chartData.pvTable.addRow([key, 0, 0, 0]);
            }
            row = this.chartIndex.pvTable[key];
            count = this.chartData.pvTable.getValue(row, 1);
            this.chartData.pvTable.setValue(row, 1, c.entrances + count);
            count = this.chartData.pvTable.getValue(row, 2);
            this.chartData.pvTable.setValue(row, 2, c.pageviews + count);
            this.chartBumps.pages[row] = c.pageviews;
        }

        var statsData = this.statsDelta;
        if ((this.lastBuild == 0)) {
           statsData = this.stats;
        }

        this.buildPageAttrsReport(statsData);


        // event table build
        for (var key in this.statsDelta.events) {
            var c = this.statsDelta.events[key];
            if (this.chartIndex.eTable[key] == undefined) {
                this.chartIndex.eTable[key] = this.chartData.eTable.getNumberOfRows();
                this.chartData.eTable.addRow([key, 0, 0]);
            }
            row = this.chartIndex.eTable[key];
            count = this.chartData.eTable.getValue(row, 1);
            this.chartData.eTable.setValue(row, 1, c.events + count);
            count = this.chartData.eTable.getValue(row, 2);
            this.chartData.eTable.setValue(row, 2, c.value + count);
            this.chartBumps.events[row] = c.events;
        }


        if (this.statsDelta.events[this.eventDetailActive] != undefined) {
            for (var key in this.statsDelta.events[this.eventDetailActive].details) {
                var c = this.statsDelta.events[this.eventDetailActive].details[key];
                if (this.chartIndex.edTable[key] == undefined) {
                    this.chartIndex.edTable[key] = this.chartData.edTable.getNumberOfRows();
                    this.chartData.edTable.addRow([key, 0, 0]);
                }
                row = this.chartIndex.edTable[key];
                count = this.chartData.edTable.getValue(row, 1);
                this.chartData.edTable.setValue(row, 1, c.events + count);
                count = this.chartData.edTable.getValue(row, 2);
                this.chartData.edTable.setValue(row, 2, c.value + count);
                this.chartBumps.edetails[row] = c.events;
            }
        }

        // cta table build
        for (var key in this.statsDelta.ctas) {
            var c = this.statsDelta.ctas[key];
            if (this.chartIndex.ctaTable[key] == undefined) {
                this.chartIndex.ctaTable[key] = this.chartData.ctaTable.getNumberOfRows();
                this.chartData.ctaTable.addRow([key, 0, 0, 0]);
            }
            row = this.chartIndex.ctaTable[key];
            var countA = this.chartData.ctaTable.getValue(row, 1) + c.impressions;
            this.chartData.ctaTable.setValue(row, 1, countA);
            var countB = this.chartData.ctaTable.getValue(row, 2)  + c.clicks;
            this.chartData.ctaTable.setValue(row, 2, countB);
            this.chartData.ctaTable.setValue(row, 3, Math.round(100 * countB/countA, 1));
            this.chartBumps.ctas[row] = c.clicks;
        }

        // landing pages table build
        for (var key in this.statsDelta.lps) {
            var c = this.statsDelta.lps[key];
            if (this.chartIndex.lpTable[key] == undefined) {
                this.chartIndex.lpTable[key] = this.chartData.lpTable.getNumberOfRows();
                this.chartData.lpTable.addRow([key, 0, 0, 0]);
            }
            row = this.chartIndex.lpTable[key];
            var countA = this.chartData.lpTable.getValue(row, 1) + c.views;
            this.chartData.lpTable.setValue(row, 1, countA);
            var countB = this.chartData.lpTable.getValue(row, 2)  + c.conversions;
            this.chartData.lpTable.setValue(row, 2, countB);
            this.chartData.lpTable.setValue(row, 3, Math.round(100 * countB/countA, 1));
            this.chartBumps.lps[row] = c.conversions;
        }

        var minDivWidth = jQuery('#chart-realtime-pageviews-min').width();
        var backgroundColor = jQuery('.pane').css('background-color');
        var fontColor = jQuery('.pane').css('color');
        var baselineColor = '#AAA';
        //console.log(minDivWidth);
        var options = {
            colors: this.chartColors,
            isStacked: true,
            chartArea: {
                left: "2%",
                top: "2%",
                width: "96%",
                height: "86%"
            },
            legend: {
                position: 'in',
                alignment: 'end',
                textStyle: {
                    color: fontColor
                }
            },
            bar: {
                groupWidth: '100%'
            },
            backgroundColor: backgroundColor,
            titleTextStyle: {
                color: fontColor
            },
            vAxis: {
                gridlines: {color: '#444'},
                textPosition: 'in',
                minValue: 2,
                textStyle: {
                    color: fontColor
                },
                baselineColor: baselineColor
            },
            hAxis: {
                direction: -1,
                gridlines: {count: 6, color: '#333'},
                ticks: [
                    {v: 300, f:'-5 min'},
                    {v: 600, f:'-10 min'},
                    {v: 900, f:'-15 min'},
                    {v: 1200, f:'-20 min'},
                    {v: 1500, f:'-25 min'}
                ],
                /*
                 ticks: [
                 '-30',
                 '-25',
                 '-20',
                 '-15',
                 '-10',
                 '-5'
                 ],
                 */
                viewWindow: {
                    min: -30,
                    max: 1800
                },
                textStyle: {
                    color: fontColor
                },
                baselineColor: backgroundColor
            }
        };

        if (this.charts.pvMin == undefined) {
            this.charts.pvMin = new google.visualization.ColumnChart(document.getElementById('chart-realtime-pageviews-min'));
        }
        this.charts.pvMin.draw(this.chartData.pvMin, options);

        if (this.charts.eMin == undefined) {
            this.charts.eMin = new google.visualization.ColumnChart(document.getElementById('chart-realtime-events-min'));
        }
        this.charts.eMin.draw(this.chartData.eMin, options);

        options.bar.groupWidth = 5;
        options.legend.position = 'none';
        options.hAxis.ticks = [
            {v: 15, f:'-15 sec'},
            {v: 30, f:'-30 sec'},
            {v: 45, f:'-45 sec'}
        ];
        options.hAxis.viewWindow = {
          min: -1,
          max: 60
        }
        options.animation = {
          duration: 900
        };

        if (this.charts.pvSec == undefined) {
           this.charts.pvSec = new google.visualization.ColumnChart(document.getElementById('chart-realtime-pageviews-sec'));
        }
        this.charts.pvSec.draw(this.chartData.pvSec, options);

        if (this.charts.eSec == undefined) {
            this.charts.eSec = new google.visualization.ColumnChart(document.getElementById('chart-realtime-events-sec'));
        }
        this.charts.eSec.draw(this.chartData.eSec, options);

        options = {
            showRowNumber: true,
            allowHtml: true,
            cssClassNames: {
              tableRow: 'table-row table-row-even',
              oddTableRow: 'table-row table-row-odd',
              headerRow: 'table-header-row',
              tableCell: 'table-cell',
              headerCell: 'table-header-cell'
            }
        };
        if (this.charts.pvTable == undefined) {
            this.charts.pvTable = new google.visualization.Table(document.getElementById('chart-realtime-pageviews-table'));
        }
        this.charts.pvTable.draw(this.chartData.pvTable, options);



        if (this.charts.eTable == undefined) {
            this.charts.eTable = new google.visualization.Table(document.getElementById('chart-realtime-events-table'));
        }
        this.charts.eTable.draw(this.chartData.eTable, options);

        if (this.charts.edTable == undefined) {
            this.charts.edTable = new google.visualization.Table(document.getElementById('chart-realtime-events-detail-table'));
        }
        this.charts.edTable.draw(this.chartData.edTable, options);

        if (this.charts.ctaTable == undefined) {
            this.charts.ctaTable = new google.visualization.Table(document.getElementById('chart-realtime-ctas-table'));
        }
        this.charts.ctaTable.draw(this.chartData.ctaTable, options);

        if (this.charts.lpTable == undefined) {
            this.charts.lpTable = new google.visualization.Table(document.getElementById('chart-realtime-landingpages-table'));
        }
        this.charts.lpTable.draw(this.chartData.lpTable, options);

        this.doChartBumps();

        // set last
        this.lastBuild = curTime;
    };

    this.drawTableOptions = function() {
        options = {
            showRowNumber: true,
            allowHtml: true,
            cssClassNames: {
                tableRow: 'table-row table-row-even',
                oddTableRow: 'table-row table-row-odd',
                headerRow: 'table-header-row',
                tableCell: 'table-cell',
                headerCell: 'table-header-cell'
            }
        };
        return options;
    };

    this.chartRedraw = {};
    this.buildPageAttrsReport = function(statsData, type, refresh) {
console.log(statsData);
        if (type == undefined) {
          type = (this.pageAttrsActive.length > 0) ? this.pageAttrsActive : this.chartRotation.pageAttrs[this.chartRotationI.pageAttrs];
        }
        if (refresh == true) {
          this.chartData.pageAttrs = null;
          this.chartIndex.pageAttrs = {};
        }
        var draw = false;
        if (this.chartRedraw.pageAttrs != undefined) {
          draw = true;
          delete this.chartRedraw.pageAttrs;
        }

console.log(statsData);
        if (this.chartData.pageAttrs == undefined) {
            this.chartData.pageAttrs = new google.visualization.DataTable();
            this.chartData.pageAttrs.addColumn('string', 'Content types');
            this.chartData.pageAttrs.addColumn('number', 'Ent');
            this.chartData.pageAttrs.addColumn('number', 'Pvs');
            this.chartData.pageAttrs.addColumn('number', 'Val');
        }
        var labels = {};
        var data = {};
        if (statsData.pageAttrs[type[0]] != undefined
            && ()) {
            data = statsData.pageAttrs[type[0]];
            if ((type.length == 2)) {
              if
              data = data[type[1]]._pages;
            }
            if (type[0] == 'a') {
                this.chartData.pageAttrs.setColumnLabel(0, 'Authors');
                labels = rtdModel.authors;
            }
            if (type[0] == 't') {
                this.chartData.pageAttrs.setColumnLabel(0, 'Terms');
                labels = rtdModel.terms;
            }
            if (type[0] == 'ct') {
                labels = rtdModel.contentTypes;
                if ((type.length == 2)) {
                    var label = (rtdModel.contentTypes[type[1]] != undefined) ? rtdModel.contentTypes[type[1]] : type[1];
                    this.chartData.pageAttrs.setColumnLabel(0, label);
                }
            }
        }

        for (var key in data) {
            var c = data[key];
            draw = true;
            if (this.chartIndex.pageAttrs[key] == undefined) {
                this.chartIndex.pageAttrs[key] = this.chartData.pageAttrs.getNumberOfRows();
                this.chartData.pageAttrs.addRow([((labels[key] != undefined) ? labels[key] : key), 0, 0, 0]);
            }
            row = this.chartIndex.pageAttrs[key];
            count = this.chartData.pageAttrs.getValue(row, 1);
            this.chartData.pageAttrs.setValue(row, 1, c.entrances + count);
            count = this.chartData.pageAttrs.getValue(row, 2);
            this.chartData.pageAttrs.setValue(row, 2, c.pageviews + count);
            if (refresh != true) {
                this.chartBumps.pageAttrs[row] = c.pageviews;
                // make sure to clear the bump styles
                this.chartRedraw.pageAttrs = true;
            }


        }

        if (this.charts.pageAttrs == undefined) {
            this.charts.pageAttrs = new google.visualization.Table(document.getElementById(this.chartDivs['pageAttrs']));
        }
        if (draw) {
          this.charts.pageAttrs.draw(this.chartData.pageAttrs, this.drawTableOptions());
        }
    };



    this.rotateReports = function() {
console.log('rotateReports');
      this.chartRotationI.pageAttrs++;
      if (this.chartRotation.pageAttrs[this.chartRotationI.pageAttrs] == undefined) {
          this.chartRotationI.pageAttrs = 0;
      }
      var type = this.chartRotation.pageAttrs[this.chartRotationI.pageAttrs];
      var $pane = jQuery('#' + this.chartDivs['pageAttrs']).parent();
      var width = jQuery('#' + this.chartDivs['pageAttrs']).parent().width() + 'px';
console.log(type);
console.log(width);
        //rtdView.buildPageAttrsReport(rtdView.stats, type, true);

        jQuery('#' + this.chartDivs['pageAttrs']).parent().animate({opacity: '0.1'}, 500, function() {
            rtdView.buildPageAttrsReport(rtdView.stats, type, true);
            $(this).animate({opacity: '1'}, 500);
        });


    };

    this.doChartBumps = function() {
        for (var key in this.chartDivs) {
            var $tableRows = jQuery('#' + this.chartDivs[key] + ' .table-row');
            for (var row in this.chartBumps[key]) {
              var dir =  this.chartBumps[key][row];
                if (dir > 0) {
                    $tableRows.eq(row).addClass('table-row-bump-up');
                    //$tableRows.eq(row).animate({backgroundColor: '#566C39'}, 200);
                    //this.chartBumps[key][row]--;
                }
                else if (dir < 0) {
                    $tableRows.eq(row).addClass('table-row-bump-down');
                    //this.chartBumps[key][row]++;
                }
                delete this.chartBumps[key][row];
            }
        }
    };

    this.switchReport = function (chartName, report) {
        var $reportCPane = jQuery('#' + this.chartDivs[chartName]).parent();
    };

    this.getLogElementTypeCount = function getLogElementTypeCount(element) {
        //console.log(element);
        var counts = {
          site: {
            pageviews: 0,
            entrances: 0,
            events: 0,
            valuedEvents: 0,
            goals: 0,
            value: 0
          },
          siteAdd: {
            pageviews: 0,
            entrances: 0,
            events: 0,
            valuedEvents: 0,
            goals: 0,
            value: 0
          }
        };

        for (var i in element) {
            var e = element[i];
            var sesKey = e.vtk + '.' + e.sid;
            if (e.type == 'pageview') {
                var key = e.p;
                if (this.statsDelta.pages[e.p] == undefined) {
                    this.statsDelta.pages[e.p] = this.getCountsArrayInit();
                }
                var pa = [];
                if (e.pa != undefined) {
                  var pa = rtdModel._unserializeCustomVar(e.pa);
                }
console.log(pa);
                counts.site.pageviews++;
                counts.siteAdd.pageviews++;
                this.statsDelta.pages[e.p].pageviews++;
                if (e.ie == '1') {
                    counts.site.entrances++;
                    counts.siteAdd.entrances++;
                    this.statsDelta.pages[e.p].entrances++;
                    rtdModel.sessions[sesKey] = {
                      ts: rtdModel._unserializeCustomVar(e.ts),
                      pages: []
                    }
                }

                rtdModel.sessions[sesKey].pages.push({
                  key: key,
                  t: e.t,
                  pa: pa
                });

                // translate page attrs ga structure
                for (var pai in pa) {

                    var pav = pa[pai];
                    var pavs = [];
                    if (typeof pav === 'object') {
                      for (var pi in pav) {
                        pavs.push(pi);
                      }
                    }
                    else {
                        pavs = [pav];
                    }
console.log(pavs);
                    for (var pi in pavs) {
                        if (!pavs.hasOwnProperty(pi)) {
                          continue;
                        }
                        pav = pavs[pi];

                        if (this.statsDelta.pageAttrs[pai] == undefined) {
                            this.statsDelta.pageAttrs[pai] = {};
                        }
                        if (this.statsDelta.pageAttrs[pai][pav] == undefined) {
                            this.statsDelta.pageAttrs[pai][pav] = this.getCountsArrayInit();
                            this.statsDelta.pageAttrs[pai][pav]._pages = {};
                        }
                        if (this.statsDelta.pageAttrs[pai][pav]._pages[key] == undefined) {
                            this.statsDelta.pageAttrs[pai][pav]._pages[key] = this.getCountsArrayInit();
                        }
                        if (this.stats.pageAttrs[pai] == undefined) {
                            this.stats.pageAttrs[pai] = {};
                        }
                        if (this.stats.pageAttrs[pai][pav] == undefined) {
                            this.stats.pageAttrs[pai][pav] = this.getCountsArrayInit();
                            this.stats.pageAttrs[pai][pav]._pages = {};
                        }
                        if (this.stats.pageAttrs[pai][pav]._pages[key] == undefined) {
                            this.stats.pageAttrs[pai][pav]._pages[key] = this.getCountsArrayInit();
                        }
                        this.statsDelta.pageAttrs[pai][pav].pageviews++;
                        this.statsDelta.pageAttrs[pai][pav]._pages[key].pageviews++;
                        this.stats.pageAttrs[pai][pav].pageviews++;
                        this.stats.pageAttrs[pai][pav]._pages[key].pageviews++;
                        if (e.ie == '1') {
                            this.statsDelta.pageAttrs[pai][pav].entrances++;
                            this.statsDelta.pageAttrs[pai][pav]._pages[key].entrances++;
                            this.stats.pageAttrs[pai][pav].entrances++;
                            this.stats.pageAttrs[pai][pav]._pages[key].entrances++;
                        }
                    }



                }
            }
            else if (e.type == 'event') {
                var key = e.ec;
                if (e.ec.substr(-1) == '!') {
                    key = key.substring(0, key.length - 1);
                }
                var subkey = e.ea;
                if (this.statsDelta.events[key] == undefined) {
                    this.statsDelta.events[key] = this.getCountsEventArrayInit();
                    this.statsDelta.events[key].details = {};
                }
                if (this.statsDelta.events[key].details[subkey] == undefined) {
                    this.statsDelta.events[key].details[subkey] = this.getCountsEventArrayInit();
                }
                counts.site.events++;
                counts.siteAdd.events++;
                this.statsDelta.events[key].events++;
                this.statsDelta.events[key].details[subkey].events++;
                // if valued event
                if (e.ec.substr(-1) == '!') {
                    counts.site.valuedEvents++;
                    counts.siteAdd.valuedEvents++;
                    this.statsDelta.events[key].valuedEvents++;
                    this.statsDelta.events[key].details[subkey].valuedEvents++;
                    this.statsDelta.events[key].value += parseFloat(e.ev);
                    this.statsDelta.events[key].details[subkey].value += parseFloat(e.ev);
                }
                if (e.ec.substr(0, 3) == 'CTA') {
                    var key = e.ea;
                    if (this.statsDelta.ctas[key] == undefined) {
                        this.statsDelta.ctas[key] = this.getCountsCTAArrayInit();
                    }
                    if (e.ec == 'CTA impression') {
                        this.statsDelta.ctas[key].impressions++;
                    }
                    else if (e.ec.substr(4, 5) == 'click') {
                        this.statsDelta.ctas[key].clicks++;
                    }
                    else if (e.ec.substr(4, 10) == 'conversion') {
                        this.statsDelta.ctas[key].conversions++;
                    }
                }
                if (e.ec.substr(0, 12) == 'Landing page') {
                    var key = e.ea;
                    if (this.statsDelta.lps[key] == undefined) {
                        this.statsDelta.lps[key] = this.getCountsLpArrayInit();
                    }
                    if (e.ec == 'Landing page view') {
                        this.statsDelta.lps[key].views++;
                    }
                    else if (e.ec.substr(13, 10) == 'conversion') {
                        this.statsDelta.lps[key].conversions++;
                    }
                }
            }

        }
        return counts;
    };

    this.getCountsArrayInit = function getCountsArrayInit() {
        return {
            entrances: 0,
            pageviews: 0,
            value: 0
        }
    };

    this.getCountsEventArrayInit = function getCountsEventArrayInit() {
        return {
            valuedEvents: 0,
            events: 0,
            value: 0
        }
    };

    this.getCountsCTAArrayInit = function getCountsCTAArrayInit() {
        return {
            impressions: 0,
            clicks: 0,
            conversions: 0
        }
    };
    this.getCountsLpArrayInit = function getCountsLpArrayInit() {
        return {
            views: 0,
            conversions: 0
        }
    };
}



