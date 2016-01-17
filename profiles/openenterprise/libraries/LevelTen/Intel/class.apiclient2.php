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
require_once 'class.exception.php';
if (!empty($_GET['debug'])) {
  require_once 'libs/class.debug.php'; 
}

class ApiClient2 {
    protected $apikey;
    protected $tid;
    protected $apiUrl = 'http://api.getlevelten.com/v1/intel';
    protected $apiUrlCallMethod = 'curl';
    protected $isTest = FALSE;
    protected $host;
    protected $path;
    protected $userAgent = 'LevelTen\Intel\ApiClient2';

    const STATUS_OK = 200;
    const STATUS_BAD_REQUEST = 400;
    const STATUS_UNAUTHORIZED = 401;
    const STATUS_NOT_FOUND = 404;

    /**
    * Constructor.
    *
    * @param $HAPIKey: String value of HubSpot API Key for requests
    **/
    public function __construct($properties = array()) {        
      foreach ($properties AS $prop => $value) {
        $this->$prop = $value;
      }
      $this->host = !empty($_SERVER['HTTP_HOST']) ? $_SERVER['HTTP_HOST'] : '';
      $this->path = !empty($_SERVER['REQUEST_URI']) ? $_SERVER['REQUEST_URI'] : '';
    }

    private function request($method, $endpoint, $params = array(), $data = array()) {
      if (!$this->apiUrl) {
        return FALSE;
      }
      if (!isset($params['tid']) && !empty($this->tid)) {
        $params['tid'] = $this->tid;
      }
      if (!isset($data['apikey']) && !empty($this->apikey)) {
        $data['apikey'] = $this->apikey;
      }
      $url = $this->getJSONUrl($endpoint, $params);
      if (!empty($_GET['debug'])) {
        Debug::printVar($url);
        Debug::printVar($params);
        Debug::printVar($data);
      }

      // intialize cURL and send POST data
      $ch = curl_init();

      if ($method != 'GET') {
        $data_str = '';
        if (is_array($data) && count($data)) {
          foreach ($data AS $key => $value) {
            $data_str .= $key.'='.$value.'&';
          }
          $data_str = substr($data_str, 0, -1);
        }

        if ($method === 'POST') {
          curl_setopt($ch, CURLOPT_POST, TRUE);
        }

        if ($method === 'PUT') {
          curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "PUT");
        }

        curl_setopt($ch, CURLOPT_POSTFIELDS, $data_str);
      }

      curl_setopt($ch, CURLOPT_URL, $url);
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
      curl_setopt($ch, CURLOPT_USERAGENT, $this->userAgent);
      curl_setopt($ch, CURLOPT_REFERER, $this->host . $this->path);
      curl_setopt($ch, CURLOPT_HTTPHEADER, array(
        'Content-Type: application/json',
        'apikey: ' . $this->apikey
      ));
      $retjson = curl_exec($ch);
      $errno = curl_errno($ch);
      $error = curl_error($ch);
      //$this->setLastStatusFromCurl($ch);
      curl_close($ch);
      if ($errno > 0) {
        throw new \Exception ('cURL error: ' . $error);
      } else {
        return json_decode($retjson, true);
      }
    }

    public function put($endpoint, $params = array(), $data = array()) {
      return $this->request('PUT', $endpoint, $params, $data);
    }

    public function post($endpoint, $params = array(), $data = array()) {
      return $this->request('POST', $endpoint, $params, $data);
    }
    
    public function getJSON($endpoint, $params = array(), $data = array()) {
      return $this->request('GET', $endpoint, $params, $data);
    }
    
    /**
    * Creates the url to be used for the api request
    *
    * @param endpoint: String value for the endpoint to be used (appears after version in url)
    * @param params: Array containing query parameters and values
    *
    * @returns String
    **/
    public function getJSONUrl($endpoint, $params) {
      $url = $this->apiUrl . '/' . $endpoint;
      if (!empty($params)) {
        $url .= '?' . $this->encodeQueryParams($params);
      }
      return $url;
    }

    /**
     * Converts array into query string parameters
     * 
     * @param array $params: 
     */
    public function encodeQueryParams($params) {
      $str = array();
      foreach($params AS $k => $v) {
        $str[] = urlencode($k) . "=" . urlencode($v);
      }
      return implode("&", $str);     
    }

    /**
    * Utility function used to determine if variable is empty
    *
    * @param s: Variable to be evaluated
    *
    * @returns Boolean
    **/
    protected function isBlank ($s) {
        if ((trim($s)=='')||($s==null)) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Sets the status code from a curl request
     *
     * @param resource $ch
     */
    protected function setLastStatusFromCurl($ch) {
        $info = curl_getinfo($ch);
        $this->lastStatus = (isset($info['http_code'])) ? $info['http_code'] : null;
    }
}