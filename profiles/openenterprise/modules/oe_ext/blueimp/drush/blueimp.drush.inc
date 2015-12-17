<?php

/**
 * @file
 *   drush integration for blueimp.
 */

/**
 * The blueimp plugin URI.
 */
define('BLUEIMP_DOWNLOAD_URI', 'https://github.com/blueimp/Gallery/archive/master.zip');
define('BLUEIMP_UNZIP_PREFIX', 'Gallery-');

/**
 * Implementation of hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * See `drush topic docs-commands` for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function blueimp_drush_command() {
  $items = array();

  // the key in the $items array is the name of the command.
  $items['install-blueimp'] = array(
    'callback' => 'drush_blueimp_install',
    'description' => dt('Download and install the Blueimp library.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install the Blueimp plugin. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('blueimp-plugin'),
    'examples' => array(
      'install-blueimp profiles/custom_profile/libraries' => dt('Install library in to custom profile directory.'),
    ),
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function blueimp_drush_help($section) {
  switch ($section) {
    case 'drush:install-blueimp':
      return dt('Download and install the blueimp plugin from blueimp.github.io/Gallery, default location is sites/all/libraries.');
  }
}

/**
 * Command to download the blueimp plugin.
 */
function drush_blueimp_install() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  // Download the zip archive
  if ($filepath = drush_download_file(BLUEIMP_DOWNLOAD_URI)) {
    $filename = basename($filepath);
    $dirname = basename($filepath, '.zip');
    $unzipname = BLUEIMP_UNZIP_PREFIX . basename($filepath, '.zip');
    
    // Remove any existing blueimp plugin directory
    if (is_dir($dirname) || is_dir('blueimp')) {
      drush_delete_dir($dirname, TRUE);
      drush_delete_dir($unzipname, TRUE);
      drush_delete_dir('blueimp', TRUE);
      drush_log(dt('A existing blueimp plugin was deleted from @path', array('@path' => $path)), 'notice');
    }

    // Decompress the zip archive
    drush_tarball_extract($filename);

    // Change the directory name to "blueimp" if needed.
    if ($dirname != 'blueimp' || $unzipname != 'blueimp' ) {
      drush_move_dir($dirname, 'blueimp', TRUE);
      drush_move_dir($unzipname, 'blueimp', TRUE);
      $dirname = 'blueimp';
    }
  }

  if (is_dir($dirname)) {
    drush_log(dt('blueimp plugin has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the blueimp plugin to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}
