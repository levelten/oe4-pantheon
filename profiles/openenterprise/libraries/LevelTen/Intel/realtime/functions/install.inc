<?php
namespace LevelTen\Intel\Realtime;
/**
 * @file
 * @author  Tom McCracken <tomm@getlevelten.com>
 * @version 1.0
 * @copyright 2013 LevelTen Ventures
 * 
 * @section LICENSE
 * All rights reserved. Do not use without permission.
 * 
 */

function schema() {
  global $db, $db_tableprefix;
  
  $schema = array();
  $schema['realtime'] = "
CREATE TABLE IF NOT EXISTS `{$db_tableprefix}realtime` (
  `time` int(11) NOT NULL,
  `vtk` varchar(32) NOT NULL,
  `sid` int(11) NOT NULL,
  `type` varchar(32) NOT NULL, 
  `host` varchar(255) NOT NULL,
  `path` varchar(255) NOT NULL,
  `query` varchar(255) NOT NULL,   
  `category` varchar(255) NOT NULL,
  `value` float NOT NULL,
  `label` varchar(255) NOT NULL,
  `data` text NOT NULL,
  KEY `time` (`time`),
  KEY `vtk` (`vtk`)
);
";

$schema['realtime_visitor'] = "
CREATE TABLE IF NOT EXISTS `{$db_tableprefix}realtime_visitor` (
  `vtk` varchar(32) NOT NULL,
  `sid` int(11) NOT NULL,
  `data` text NOT NULL,
  KEY `vtk` (`vtk`)
);
";

  return $schema;
}

function install() {
  file_include('includes/db.inc');
  file_include('includes/html.inc');
  global $db, $db_tableprefix;
  $vars = page_init_vars();
  $vars['head']['title'] = 'L10Intel Realtime';
  $schema = schema();

  $tables = array(
    'realtime',
    'realtime_visitor',
  );
  foreach ($tables AS $table) {
    $table_exists = 1;
    try {
      $results = $db->query("SHOW TABLES LIKE '{$db_tableprefix}$table'");
      if ($results->rowCount() == 0) {
        $table_exists = 0;
      }
    }
    catch(PDOException $e) {
      $table_exists = 0;
    }
    if ($table_exists) {
      page_create_element($vars, "Table $table already exists.<br>\n");
    }
    else {
      page_create_element($vars, "Creating $table table...<br>\n");
      $db->exec($schema[$table]);
      page_create_element($vars, "Done.<br>\n");
    }    
  }

  render_page($vars);
}