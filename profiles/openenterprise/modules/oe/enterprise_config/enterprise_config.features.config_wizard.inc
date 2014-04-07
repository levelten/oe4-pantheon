<?php
/**
 * @file
 * enterprise_config.features.config_wizard.inc
 */

/**
 * Implements hook_config_wizard_defaults().
 */
function enterprise_config_config_wizard_defaults() {
  $data = array(
    'analytics_setup' => array(
      'steps' => array(
        's2' => array(
          'content' => array(
            'main' => array(
              '#markup' => 'You need a Google Analytics tracking code. If you do not already have a Google Analytics account, <a href="http://www.google.com/analytics" target="ga">create one</a>.

Enter the tracking code in the <a href="/admin/config/system/googleanalytics" target="_modal">Google Analtyics configuration form</a>.
',
              '#weight' => 0,
              '#editable' => 1,
            ),
          ),
        ),
        's3' => array(
          'content' => array(
            'main' => array(
              '#markup' => '<ol>
  <li>Create a second  <a href="http://www.google.com/analytics" target="ga">Google Analytics tracking id</a></li>
  <li>Get a <a href="http://api.getlevelten.com/site" target="l10iapi">LevelTen Intelligence API key</li>
  <li><a href="/admin/config/services/intel" target="_modal">Configure Intelligence module</a> with tracking id and api key</li>
  <li><a href="/admin/config/system/google-analytics-reports?config-wizard=analytics_setup" target="ga_api">Set Google Analytics API</a> to access Intelligence Google Analytics tracking id</li>
  <li>Add "Intel" view in Google Analytics. Set exclude filters.</a></li>
  <li>Configure Google Analtyics goals and sync them with the <a href="/admin/config/services/intel/scoring" target="_modal">LevelTen Intelligence scorring goals</a></li>
</ol>
',
              '#weight' => 0,
              '#editable' => 1,
            ),
          ),
        ),
      ),
    ),
    'mailchimp_setup' => array(
      'steps' => array(
        'api' => array(
          'content' => array(
            'main' => array(
              '#markup' => '<ol>
  <li>Create an API key in MailChimp <a href= "https://us1.admin.mailchimp.com/account/api/ "  target= "mailchimp ">Account settings > Extras > API keys</a> </li>
  <li>Add the API key to Drupal’s <a href= "/admin/config/services/mailchimp"  target= "_modal">MailChimp configuration</a></li>
  <li>Add  "Main" mailing list to Drupal <a href= "/admin/config/services/mailchimp/lists"  target= "_modal">MailChimp list configuration</a></li>
  <li>Select Main list in <a href= "/admin/config/services/intel/modules/mailchimp"  target= "_modal">Intelligence config</a> (may need to enable expanded settings in General)</li>
</ol>',
              '#weight' => 0,
              '#editable' => 1,
            ),
          ),
        ),
      ),
    ),
  );
  return $data;
}
