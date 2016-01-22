<?php
/**
 * @file
 * @author  Tom McCracken <tomm@levelten.net>
 * @version 1.0
 * @copyright 2013 LevelTen Ventures
 * 
 * @section LICENSE
 * All rights reserved. Do not use without permission.
 * 
 */
namespace LevelTen\Intel;

require_once 'class.apiclient.php';
require_once 'class.apiclient2.php';
require_once 'class.exception.php';

class ApiProperty {
	protected $apiProperty;
	protected $apiClient;
  protected $version;
  protected $error;

  public function __construct($apiClientProperties = array(), $version = 1) {
    $apiClientProperties['version'] = $version;
    $this->error = '';
    $this->apiProperty = null;
    $this->version = $version;
    $this->apiClient = new ApiClient($apiClientProperties);
  }
	
  public function load($params = array(), $data = array()){
  	$endpoint = ($this->version == 1) ? 'property/load' : 'property';
  	try {
      if ($this->version == 1) {
        $ret = $this->apiClient->getJSON($endpoint, $params, $data);
      }
      else {
        $ret = $this->apiClient->get($endpoint, $params, $data);
      }
      $prop = ($this->version == 1) ? (object)$ret['property'] : (object)$ret;
      if (empty($ret)) {
        return FALSE;
      }
  	  $this->apiProperty = $prop;
  		return $this->apiProperty;
  	} 
  	catch (L10IntelException $e) {
      $this->error = $e->getMessage();
  	}
  }
  
  public function save($params = array(), $data = array()){
    $endpoint = ($this->version == 1) ? 'property/save' : 'property';
    try {
      if ($this->version == 1) {
        $ret = $this->apiClient->getJSON($endpoint, $params, $data);
      }
      else {
        $ret = $this->apiClient->put($endpoint, $params, $data);
      }
      if (!$ret) {
        throw new L10IntelException('Property not returned from API. msg: ' . $ret['message']);
        return;
      }
      $prop = ($this->version == 1) ? (object)$ret['property'] : (object)$ret;
      if ($prop) {
        $this->apiProperty = $prop;
        return $prop;
      }
      else {
        $this->error = 'Property not returned from API. msg: ' . $ret['message'];
      }
    } 
    catch (L10IntelException $e) {
      $this->error = $e->getMessage();
    }
  }
    
  public function getPtkid() {
    return $this->ptkid;
  }
  
  public function getProperty() {
    return $this->apiProperty;
  }

  public function getError() {
    return $this->error;
  }
  
  public function __toString() {
    if (!empty($_GET['debug'])) {
      return print_r($this->apiProperty, 1);
    }
    else {
      return 'Property: ' . $this->ptk;
    }
  }
}