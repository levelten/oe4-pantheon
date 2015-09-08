/**
 * Created by tom on 9/3/15.
 */
var guides = {};
guides['edit_content'] = {
    title: "Editing content",
    id: 'editContent',
    xButton: 1,
    buttons: [],
    steps: [
        {
            attachTo: '.admin-menu-toolbar-home-menu',
            position: 7,
            //offset: {top: 0, left: 200},
            description: 'Go to the home page by clicking on the home icon in the admin menu.',
            nextIf: function () { return eGuide.assertSystemPath('node/1') }
        },
        {
            description: 'The main form of content in a Drupal site is called a node. ...',
            buttons: [
                {name: 'Next'}
            ]
        },
        {
            //path: 'admin/config',
            systemPath: 'node/1',
            attachTo: '.nav-tabs a[href="/node/1/edit"]',
            position: 7,
            description: 'Click the Edit tab to go to the edit form.',
            nextIf: function () { return eGuide.assertSystemPath('node/1/edit') }
        },
        {
            path: 'node/1/edit',
            attachTo: '#edit-body-und-0-value', // 'cke_edit-body-und-0-value'
            position: 3,
            description: 'Enter some text into the body textarea input.',
            buttons: [
                {
                    name: "Insert text",
                    onclick: function () { eGuide.setInput('Maecenas faucibus mollis interdum. Aenean lacinia bibendum nulla sed consectetur. Aenean lacinia bibendum nulla sed consectetur. Cras mattis consectetur purus sit amet fermentum. Integer posuere erat a ante venenatis dapibus posuere velit aliquet.', '#edit-site-name') }
                },
                {
                    name: 'Next'
                }
            ],
            nextIf: function (guider) { return eGuide.assertInput('admin/config/system/site-information') },
            nextIfOn: {
                event: 'change'
            }
        },
        {
            path: 'node/1/edit',
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
