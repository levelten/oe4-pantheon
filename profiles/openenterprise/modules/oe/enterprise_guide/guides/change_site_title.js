/**
 * Created by tom on 9/3/15.
 */
var guides = {};
guides['change_site_title'] = {
    title: "Change Site Title",
    id: 'siteTitle',
    xButton: 1,
    buttons: [],
    steps: [
        //{
        //    position: 7,
        //    description: '<a href="https://www.youtube.com/embed/yEnIpQf3g_A?width=500&height=500&iframe=true" class="colorbox colorbox-load">video</a><iframe src="https://www.youtube.com/embed/yEnIpQf3g_A" frameborder="0" allowfullscreen></iframe>'
        //},
        {
            attachTo: '#admin-menu-menu a[href="/admin/config"]',
            position: 7,
            description: 'In the admin menu, click on <em>Configuration</em>.',
            nextIf: function () { return eGuide.assertPath('admin/config') }
        },
        {
            path: 'admin/config',
            attachTo: '#main-content a[href="/admin/config/system/site-information"]',
            position: 9,
            description: 'Under System configuration click the <em>Site infomation</em> link.',
            nextIf: function () { return eGuide.assertPath('admin/config/system/site-information') }
        },
        {
            path: 'admin/config/system/site-information',
            attachTo: '#edit-site-name',
            position: 3,
            description: 'For the Site name enter "Results Bikes".',
            buttons: [
                {
                    name: "Insert text",
                    onclick: function () { return eGuide.setInput('Results Bikes', '#edit-site-name') }
                },
                {
                    name: 'Next'
                }
            ],
            nextIf: function (guider) { console.log(guider); console.log(this); return eGuide.assertInput('admin/config/system/site-information') },
            nextIfOn: {
                event: 'change'
            }
        },
        {
            path: 'admin/config/system/site-information',
            attachTo: '#edit-submit',
            position: 9,
            description: 'Click Save configuration to save save your changes.',
            nextIf: function () { return eGuide.assertText('The configuration options have been saved', '=@', '.messages')  }
        },
        {
            path: 'admin/config/system/site-information',
            description: 'You can verify the site name has changed by reviewing the page title.',
            buttons: [
                {
                    name: 'Close'
                }
            ]
        }
    ]
};
