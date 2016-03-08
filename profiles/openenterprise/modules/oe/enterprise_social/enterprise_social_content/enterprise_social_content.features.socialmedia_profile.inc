<?php
/**
 * @file
 * enterprise_social_content.features.socialmedia_profile.inc
 */

/**
 * Implements hook_socialmedia_profile_defaults().
 */
function enterprise_social_content_socialmedia_profile_defaults() {
  $data = array(
    'facebook:0' => array(
      'url' => 'www.facebook.com/levelten',
      'username' => 'LevelTen',
      'userid' => 'LevelTen',
      'inputs' => array(
        'url' => 'www.facebook.com/levelten',
        'username' => 'LevelTen',
      ),
      'uid' => 0,
      'platform' => 'facebook',
    ),
    'googleplus:0' => array(
      'url' => 'plus.google.com/+getlevelten',
      'username' => 'LevelTen',
      'userid' => 'LevelTen',
      'inputs' => array(
        'url' => 'plus.google.com/+getlevelten',
        'username' => 'LevelTen',
      ),
      'uid' => 0,
      'platform' => 'googleplus',
    ),
    'linkedin:0' => array(
      'url' => 'www.linkedin.com/company/levelten-interactive',
      'username' => 'LevelTen',
      'userid' => 'LevelTen',
      'inputs' => array(
        'url' => 'http://www.linkedin.com/company/levelten-interactive',
        'username' => 'LevelTen',
      ),
      'uid' => 0,
      'platform' => 'linkedin',
    ),
    'twitter:0' => array(
      'url' => 'twitter.com/levelten',
      'username' => 'levelten',
      'userid' => 'levelten',
      'user_timeline_widget_id' => '450687728120651777',
      'inputs' => array(
        'url' => 'twitter.com/levelten',
        'username' => '',
        'user_timeline_widget_id' => '450687728120651777',
      ),
      'uid' => 0,
      'platform' => 'twitter',
    ),
    'youtube:0' => array(
      'url' => 'www.youtube.com/user/LevelTenDrupalLabs',
      'username' => 'LevelTen',
      'userid' => 'LevelTen',
      'inputs' => array(
        'url' => 'http://www.youtube.com/user/LevelTenDrupalLabs',
        'username' => 'LevelTen',
      ),
      'uid' => 0,
      'platform' => 'youtube',
    ),
  );
  return $data;
}
