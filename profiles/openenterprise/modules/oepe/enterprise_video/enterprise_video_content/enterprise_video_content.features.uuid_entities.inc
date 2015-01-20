<?php
/**
 * @file
 * enterprise_video_content.features.uuid_entities.inc
 */

/**
 * Implements hook_uuid_default_entities().
 */
function enterprise_video_content_uuid_default_entities() {
  $entities = array();

  $entities['enterprise_video_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/2a16e106-4c79-42e1-9bd4-4dc19a6214cb',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => '<p>Body text goes here..&nbsp;Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.</p>
',
        ),
      ),
    ),
    'cid' => 0,
    'comment' => 2,
    'comment_count' => 0,
    'cta' => array(
      'selections' => array(),
    ),
    'ds_switch' => '',
    'entity_type' => 'node',
    'field_video_embed' => array(
      'und' => array(
        0 => array(
          'description' => NULL,
          'embed_code' => NULL,
          'thumbnail_path' => 'public://video_embed_field_thumbnails/youtube/b9c4vfHtt_k.jpg',
          'video_data' => 'a:20:{s:5:"xmlns";s:27:"http://www.w3.org/2005/Atom";s:8:"xmlns$gd";s:32:"http://schemas.google.com/g/2005";s:8:"xmlns$yt";s:37:"http://gdata.youtube.com/schemas/2007";s:11:"xmlns$media";s:29:"http://search.yahoo.com/mrss/";s:7:"gd$etag";s:28:"W/"AkACQH47eCp7I2A9XRRTFUo."";s:2:"id";s:38:"tag:youtube.com,2008:video:b9c4vfHtt_k";s:9:"published";s:24:"2015-01-06T21:12:41.000Z";s:7:"updated";s:24:"2015-01-06T21:12:41.000Z";s:8:"category";a:2:{i:0;a:2:{s:6:"scheme";s:37:"http://schemas.google.com/g/2005#kind";s:4:"term";s:43:"http://gdata.youtube.com/schemas/2007#video";}i:1;a:3:{s:6:"scheme";s:52:"http://gdata.youtube.com/schemas/2007/categories.cat";s:4:"term";s:4:"Tech";s:5:"label";s:20:"Science & Technology";}}s:5:"title";s:28:"Intel Content Several Angles";s:7:"content";a:2:{s:4:"type";s:29:"application/x-shockwave-flash";s:3:"src";s:73:"http://www.youtube.com/v/b9c4vfHtt_k?version=3&f=videos&app=youtube_gdata";}s:4:"link";a:5:{i:0;a:3:{s:3:"rel";s:9:"alternate";s:4:"type";s:9:"text/html";s:4:"href";s:64:"http://www.youtube.com/watch?v=b9c4vfHtt_k&feature=youtube_gdata";}i:1;a:3:{s:3:"rel";s:51:"http://gdata.youtube.com/schemas/2007#video.related";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:65:"http://gdata.youtube.com/feeds/api/videos/b9c4vfHtt_k/related?v=2";}i:2;a:3:{s:3:"rel";s:44:"http://gdata.youtube.com/schemas/2007#mobile";s:4:"type";s:9:"text/html";s:4:"href";s:42:"http://m.youtube.com/details?v=b9c4vfHtt_k";}i:3;a:3:{s:3:"rel";s:46:"http://gdata.youtube.com/schemas/2007#uploader";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:67:"http://gdata.youtube.com/feeds/api/users/v9AEmq8SjPA3yA-vBs6dgg?v=2";}i:4;a:3:{s:3:"rel";s:4:"self";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:57:"http://gdata.youtube.com/feeds/api/videos/b9c4vfHtt_k?v=2";}}s:6:"author";a:1:{i:0;a:3:{s:4:"name";s:18:"resultsorientedweb";s:3:"uri";s:59:"http://gdata.youtube.com/feeds/api/users/resultsorientedweb";s:9:"yt$userId";s:22:"v9AEmq8SjPA3yA-vBs6dgg";}}s:16:"yt$accessControl";a:8:{i:0;a:2:{s:6:"action";s:7:"comment";s:10:"permission";s:7:"allowed";}i:1;a:2:{s:6:"action";s:11:"commentVote";s:10:"permission";s:7:"allowed";}i:2;a:2:{s:6:"action";s:12:"videoRespond";s:10:"permission";s:9:"moderated";}i:3;a:2:{s:6:"action";s:4:"rate";s:10:"permission";s:7:"allowed";}i:4;a:2:{s:6:"action";s:5:"embed";s:10:"permission";s:7:"allowed";}i:5;a:2:{s:6:"action";s:4:"list";s:10:"permission";s:7:"allowed";}i:6;a:2:{s:6:"action";s:8:"autoPlay";s:10:"permission";s:7:"allowed";}i:7;a:2:{s:6:"action";s:9:"syndicate";s:10:"permission";s:7:"allowed";}}s:11:"gd$comments";a:1:{s:11:"gd$feedLink";a:3:{s:3:"rel";s:46:"http://gdata.youtube.com/schemas/2007#comments";s:4:"href";s:66:"http://gdata.youtube.com/feeds/api/videos/b9c4vfHtt_k/comments?v=2";s:9:"countHint";i:0;}}s:5:"yt$hd";a:0:{}s:11:"media$group";a:14:{s:14:"media$category";a:1:{i:0;s:4:"Tech";}s:13:"media$content";a:3:{i:0;a:7:{s:3:"url";s:73:"http://www.youtube.com/v/b9c4vfHtt_k?version=3&f=videos&app=youtube_gdata";s:4:"type";s:29:"application/x-shockwave-flash";s:6:"medium";s:5:"video";s:9:"isDefault";s:4:"true";s:10:"expression";s:4:"full";s:8:"duration";i:471;s:9:"yt$format";i:5;}i:1;a:6:{s:3:"url";s:102:"rtsp://r8---sn-jc47eu7e.c.youtube.com/CiILENy73wIaGQn5t-3xvTjXbxMYDSANFEgGUgZ2aWRlb3MM/0/0/0/video.3gp";s:4:"type";s:10:"video/3gpp";s:6:"medium";s:5:"video";s:10:"expression";s:4:"full";s:8:"duration";i:471;s:9:"yt$format";i:1;}i:2;a:6:{s:3:"url";s:102:"rtsp://r8---sn-jc47eu7e.c.youtube.com/CiILENy73wIaGQn5t-3xvTjXbxMYESARFEgGUgZ2aWRlb3MM/0/0/0/video.3gp";s:4:"type";s:10:"video/3gpp";s:6:"medium";s:5:"video";s:10:"expression";s:4:"full";s:8:"duration";i:471;s:9:"yt$format";i:6;}}s:12:"media$credit";a:1:{i:0;s:18:"resultsorientedweb";}s:17:"media$description";s:205:"With Open Enterprise Intel you can analyze your content from several angles to determine the efforts that are producing the most value. Including blog authors, content types, subjects/tags and many others.";s:14:"media$keywords";a:0:{}s:13:"media$license";s:7:"youtube";s:12:"media$player";a:1:{s:3:"url";s:71:"http://www.youtube.com/watch?v=b9c4vfHtt_k&feature=youtube_gdata_player";}s:15:"media$thumbnail";a:7:{i:0;a:5:{s:3:"url";s:45:"http://i.ytimg.com/vi/b9c4vfHtt_k/default.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:12:"00:03:55.500";s:7:"yt$name";s:7:"default";}i:1;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/b9c4vfHtt_k/mqdefault.jpg";s:6:"height";i:180;s:5:"width";i:320;s:7:"yt$name";s:9:"mqdefault";}i:2;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/b9c4vfHtt_k/hqdefault.jpg";s:6:"height";i:360;s:5:"width";i:480;s:7:"yt$name";s:9:"hqdefault";}i:3;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/b9c4vfHtt_k/sddefault.jpg";s:6:"height";i:480;s:5:"width";i:640;s:7:"yt$name";s:9:"sddefault";}i:4;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/b9c4vfHtt_k/1.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:12:"00:01:57.750";s:7:"yt$name";s:5:"start";}i:5;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/b9c4vfHtt_k/2.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:12:"00:03:55.500";s:7:"yt$name";s:6:"middle";}i:6;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/b9c4vfHtt_k/3.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:12:"00:05:53.250";s:7:"yt$name";s:3:"end";}}s:11:"media$title";s:28:"Intel Content Several Angles";s:14:"yt$aspectRatio";s:10:"widescreen";s:11:"yt$duration";a:1:{s:7:"seconds";s:3:"471";}s:11:"yt$uploaded";s:24:"2015-01-06T21:12:41.000Z";s:13:"yt$uploaderId";s:24:"UCv9AEmq8SjPA3yA-vBs6dgg";s:10:"yt$videoid";s:11:"b9c4vfHtt_k";}s:13:"yt$statistics";a:2:{s:13:"favoriteCount";s:1:"0";s:9:"viewCount";s:1:"7";}s:5:"terms";a:1:{i:0;s:4:"Tech";}s:7:"handler";s:7:"youtube";}',
          'video_url' => 'https://www.youtube.com/watch?v=b9c4vfHtt_k&list=UUv9AEmq8SjPA3yA-vBs6dgg',
        ),
      ),
    ),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 0,
    'status' => 1,
    'sticky' => 0,
    'title' => 'Monitoring Content From Different Angles',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_video',
    'uid' => 1,
    'url_alias' => array(),
    'uuid' => '2a16e106-4c79-42e1-9bd4-4dc19a6214cb',
  );
  $entities['enterprise_video_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/bae818b8-50ab-49f3-9f99-d7bda1e07c08',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => '<p>Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.</p>
',
        ),
      ),
    ),
    'cid' => 0,
    'comment' => 1,
    'comment_count' => 0,
    'cta' => array(
      'selections' => array(),
    ),
    'ds_switch' => '',
    'entity_type' => 'node',
    'field_video_embed' => array(
      'und' => array(
        0 => array(
          'description' => NULL,
          'embed_code' => NULL,
          'thumbnail_path' => 'public://video_embed_field_thumbnails/youtube/IRoPpgjK1vo.jpg',
          'video_data' => 'a:20:{s:5:"xmlns";s:27:"http://www.w3.org/2005/Atom";s:8:"xmlns$gd";s:32:"http://schemas.google.com/g/2005";s:8:"xmlns$yt";s:37:"http://gdata.youtube.com/schemas/2007";s:11:"xmlns$media";s:29:"http://search.yahoo.com/mrss/";s:7:"gd$etag";s:28:"W/"DUEBQH47eCp7I2A9XRRTFUo."";s:2:"id";s:38:"tag:youtube.com,2008:video:IRoPpgjK1vo";s:9:"published";s:24:"2014-12-29T22:19:16.000Z";s:7:"updated";s:24:"2015-01-06T20:54:11.000Z";s:8:"category";a:2:{i:0;a:2:{s:6:"scheme";s:37:"http://schemas.google.com/g/2005#kind";s:4:"term";s:43:"http://gdata.youtube.com/schemas/2007#video";}i:1;a:3:{s:6:"scheme";s:52:"http://gdata.youtube.com/schemas/2007/categories.cat";s:4:"term";s:4:"Tech";s:5:"label";s:20:"Science & Technology";}}s:5:"title";s:35:"Intelligence Content Entrance Pages";s:7:"content";a:2:{s:4:"type";s:29:"application/x-shockwave-flash";s:3:"src";s:73:"http://www.youtube.com/v/IRoPpgjK1vo?version=3&f=videos&app=youtube_gdata";}s:4:"link";a:5:{i:0;a:3:{s:3:"rel";s:9:"alternate";s:4:"type";s:9:"text/html";s:4:"href";s:64:"http://www.youtube.com/watch?v=IRoPpgjK1vo&feature=youtube_gdata";}i:1;a:3:{s:3:"rel";s:51:"http://gdata.youtube.com/schemas/2007#video.related";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:65:"http://gdata.youtube.com/feeds/api/videos/IRoPpgjK1vo/related?v=2";}i:2;a:3:{s:3:"rel";s:44:"http://gdata.youtube.com/schemas/2007#mobile";s:4:"type";s:9:"text/html";s:4:"href";s:42:"http://m.youtube.com/details?v=IRoPpgjK1vo";}i:3;a:3:{s:3:"rel";s:46:"http://gdata.youtube.com/schemas/2007#uploader";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:67:"http://gdata.youtube.com/feeds/api/users/v9AEmq8SjPA3yA-vBs6dgg?v=2";}i:4;a:3:{s:3:"rel";s:4:"self";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:57:"http://gdata.youtube.com/feeds/api/videos/IRoPpgjK1vo?v=2";}}s:6:"author";a:1:{i:0;a:3:{s:4:"name";s:18:"resultsorientedweb";s:3:"uri";s:59:"http://gdata.youtube.com/feeds/api/users/resultsorientedweb";s:9:"yt$userId";s:22:"v9AEmq8SjPA3yA-vBs6dgg";}}s:16:"yt$accessControl";a:8:{i:0;a:2:{s:6:"action";s:7:"comment";s:10:"permission";s:7:"allowed";}i:1;a:2:{s:6:"action";s:11:"commentVote";s:10:"permission";s:7:"allowed";}i:2;a:2:{s:6:"action";s:12:"videoRespond";s:10:"permission";s:9:"moderated";}i:3;a:2:{s:6:"action";s:4:"rate";s:10:"permission";s:7:"allowed";}i:4;a:2:{s:6:"action";s:5:"embed";s:10:"permission";s:7:"allowed";}i:5;a:2:{s:6:"action";s:4:"list";s:10:"permission";s:7:"allowed";}i:6;a:2:{s:6:"action";s:8:"autoPlay";s:10:"permission";s:7:"allowed";}i:7;a:2:{s:6:"action";s:9:"syndicate";s:10:"permission";s:7:"allowed";}}s:11:"gd$comments";a:1:{s:11:"gd$feedLink";a:3:{s:3:"rel";s:46:"http://gdata.youtube.com/schemas/2007#comments";s:4:"href";s:66:"http://gdata.youtube.com/feeds/api/videos/IRoPpgjK1vo/comments?v=2";s:9:"countHint";i:0;}}s:5:"yt$hd";a:0:{}s:11:"media$group";a:14:{s:14:"media$category";a:1:{i:0;s:4:"Tech";}s:13:"media$content";a:3:{i:0;a:7:{s:3:"url";s:73:"http://www.youtube.com/v/IRoPpgjK1vo?version=3&f=videos&app=youtube_gdata";s:4:"type";s:29:"application/x-shockwave-flash";s:6:"medium";s:5:"video";s:9:"isDefault";s:4:"true";s:10:"expression";s:4:"full";s:8:"duration";i:592;s:9:"yt$format";i:5;}i:1;a:6:{s:3:"url";s:102:"rtsp://r4---sn-jc47eu7k.c.youtube.com/CiILENy73wIaGQn61soIpg8aIRMYDSANFEgGUgZ2aWRlb3MM/0/0/0/video.3gp";s:4:"type";s:10:"video/3gpp";s:6:"medium";s:5:"video";s:10:"expression";s:4:"full";s:8:"duration";i:592;s:9:"yt$format";i:1;}i:2;a:6:{s:3:"url";s:102:"rtsp://r4---sn-jc47eu7k.c.youtube.com/CiILENy73wIaGQn61soIpg8aIRMYESARFEgGUgZ2aWRlb3MM/0/0/0/video.3gp";s:4:"type";s:10:"video/3gpp";s:6:"medium";s:5:"video";s:10:"expression";s:4:"full";s:8:"duration";i:592;s:9:"yt$format";i:6;}}s:12:"media$credit";a:1:{i:0;s:18:"resultsorientedweb";}s:17:"media$description";s:113:"In-depth demonstration of OE Intelligence and how it can be used to determine content value and CTA optimization.";s:14:"media$keywords";a:0:{}s:13:"media$license";s:7:"youtube";s:12:"media$player";a:1:{s:3:"url";s:71:"http://www.youtube.com/watch?v=IRoPpgjK1vo&feature=youtube_gdata_player";}s:15:"media$thumbnail";a:7:{i:0;a:5:{s:3:"url";s:45:"http://i.ytimg.com/vi/IRoPpgjK1vo/default.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:8:"00:04:56";s:7:"yt$name";s:7:"default";}i:1;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/IRoPpgjK1vo/mqdefault.jpg";s:6:"height";i:180;s:5:"width";i:320;s:7:"yt$name";s:9:"mqdefault";}i:2;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/IRoPpgjK1vo/hqdefault.jpg";s:6:"height";i:360;s:5:"width";i:480;s:7:"yt$name";s:9:"hqdefault";}i:3;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/IRoPpgjK1vo/sddefault.jpg";s:6:"height";i:480;s:5:"width";i:640;s:7:"yt$name";s:9:"sddefault";}i:4;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/IRoPpgjK1vo/1.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:8:"00:02:28";s:7:"yt$name";s:5:"start";}i:5;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/IRoPpgjK1vo/2.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:8:"00:04:56";s:7:"yt$name";s:6:"middle";}i:6;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/IRoPpgjK1vo/3.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:8:"00:07:24";s:7:"yt$name";s:3:"end";}}s:11:"media$title";s:35:"Intelligence Content Entrance Pages";s:14:"yt$aspectRatio";s:10:"widescreen";s:11:"yt$duration";a:1:{s:7:"seconds";s:3:"592";}s:11:"yt$uploaded";s:24:"2014-12-29T22:19:16.000Z";s:13:"yt$uploaderId";s:24:"UCv9AEmq8SjPA3yA-vBs6dgg";s:10:"yt$videoid";s:11:"IRoPpgjK1vo";}s:13:"yt$statistics";a:2:{s:13:"favoriteCount";s:1:"0";s:9:"viewCount";s:2:"26";}s:5:"terms";a:1:{i:0;s:4:"Tech";}s:7:"handler";s:7:"youtube";}',
          'video_url' => 'https://www.youtube.com/watch?v=IRoPpgjK1vo',
        ),
      ),
    ),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 0,
    'status' => 1,
    'sticky' => 0,
    'title' => 'Intelligence Content Entrance Pages',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_video',
    'uid' => 1,
    'url_alias' => array(),
    'uuid' => 'bae818b8-50ab-49f3-9f99-d7bda1e07c08',
  );
  $entities['enterprise_video_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/54281e77-2013-4e08-a833-13f21ffcf9dc',
      'cause' => FALSE,
    ),
    'body' => array(),
    'cid' => 0,
    'comment' => 1,
    'comment_count' => 0,
    'cta' => array(
      'selections' => array(),
    ),
    'ds_switch' => '',
    'entity_type' => 'node',
    'field_video_embed' => array(
      'und' => array(
        0 => array(
          'description' => NULL,
          'embed_code' => NULL,
          'thumbnail_path' => 'public://video_embed_field_thumbnails/youtube/rPbgQmICL5g.jpg',
          'video_data' => 'a:20:{s:5:"xmlns";s:27:"http://www.w3.org/2005/Atom";s:8:"xmlns$gd";s:32:"http://schemas.google.com/g/2005";s:8:"xmlns$yt";s:37:"http://gdata.youtube.com/schemas/2007";s:11:"xmlns$media";s:29:"http://search.yahoo.com/mrss/";s:7:"gd$etag";s:28:"W/"DE8HRH47eCp7I2A9XRdaEE0."";s:2:"id";s:38:"tag:youtube.com,2008:video:rPbgQmICL5g";s:9:"published";s:24:"2014-12-19T16:33:49.000Z";s:7:"updated";s:24:"2014-12-19T16:33:55.000Z";s:8:"category";a:2:{i:0;a:2:{s:6:"scheme";s:37:"http://schemas.google.com/g/2005#kind";s:4:"term";s:43:"http://gdata.youtube.com/schemas/2007#video";}i:1;a:3:{s:6:"scheme";s:52:"http://gdata.youtube.com/schemas/2007/categories.cat";s:4:"term";s:4:"Tech";s:5:"label";s:20:"Science & Technology";}}s:5:"title";s:34:"Open Enteprise: Formatting Content";s:7:"content";a:2:{s:4:"type";s:29:"application/x-shockwave-flash";s:3:"src";s:73:"http://www.youtube.com/v/rPbgQmICL5g?version=3&f=videos&app=youtube_gdata";}s:4:"link";a:5:{i:0;a:3:{s:3:"rel";s:9:"alternate";s:4:"type";s:9:"text/html";s:4:"href";s:64:"http://www.youtube.com/watch?v=rPbgQmICL5g&feature=youtube_gdata";}i:1;a:3:{s:3:"rel";s:51:"http://gdata.youtube.com/schemas/2007#video.related";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:65:"http://gdata.youtube.com/feeds/api/videos/rPbgQmICL5g/related?v=2";}i:2;a:3:{s:3:"rel";s:44:"http://gdata.youtube.com/schemas/2007#mobile";s:4:"type";s:9:"text/html";s:4:"href";s:42:"http://m.youtube.com/details?v=rPbgQmICL5g";}i:3;a:3:{s:3:"rel";s:46:"http://gdata.youtube.com/schemas/2007#uploader";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:67:"http://gdata.youtube.com/feeds/api/users/v9AEmq8SjPA3yA-vBs6dgg?v=2";}i:4;a:3:{s:3:"rel";s:4:"self";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:57:"http://gdata.youtube.com/feeds/api/videos/rPbgQmICL5g?v=2";}}s:6:"author";a:1:{i:0;a:3:{s:4:"name";s:18:"resultsorientedweb";s:3:"uri";s:59:"http://gdata.youtube.com/feeds/api/users/resultsorientedweb";s:9:"yt$userId";s:22:"v9AEmq8SjPA3yA-vBs6dgg";}}s:16:"yt$accessControl";a:8:{i:0;a:2:{s:6:"action";s:7:"comment";s:10:"permission";s:7:"allowed";}i:1;a:2:{s:6:"action";s:11:"commentVote";s:10:"permission";s:7:"allowed";}i:2;a:2:{s:6:"action";s:12:"videoRespond";s:10:"permission";s:9:"moderated";}i:3;a:2:{s:6:"action";s:4:"rate";s:10:"permission";s:7:"allowed";}i:4;a:2:{s:6:"action";s:5:"embed";s:10:"permission";s:7:"allowed";}i:5;a:2:{s:6:"action";s:4:"list";s:10:"permission";s:7:"allowed";}i:6;a:2:{s:6:"action";s:8:"autoPlay";s:10:"permission";s:7:"allowed";}i:7;a:2:{s:6:"action";s:9:"syndicate";s:10:"permission";s:7:"allowed";}}s:11:"gd$comments";a:1:{s:11:"gd$feedLink";a:3:{s:3:"rel";s:46:"http://gdata.youtube.com/schemas/2007#comments";s:4:"href";s:66:"http://gdata.youtube.com/feeds/api/videos/rPbgQmICL5g/comments?v=2";s:9:"countHint";i:0;}}s:5:"yt$hd";a:0:{}s:11:"media$group";a:14:{s:14:"media$category";a:1:{i:0;s:4:"Tech";}s:13:"media$content";a:3:{i:0;a:7:{s:3:"url";s:73:"http://www.youtube.com/v/rPbgQmICL5g?version=3&f=videos&app=youtube_gdata";s:4:"type";s:29:"application/x-shockwave-flash";s:6:"medium";s:5:"video";s:9:"isDefault";s:4:"true";s:10:"expression";s:4:"full";s:8:"duration";i:138;s:9:"yt$format";i:5;}i:1;a:6:{s:3:"url";s:102:"rtsp://r1---sn-jc47eu7s.c.youtube.com/CiILENy73wIaGQmYLwJiQuD2rBMYDSANFEgGUgZ2aWRlb3MM/0/0/0/video.3gp";s:4:"type";s:10:"video/3gpp";s:6:"medium";s:5:"video";s:10:"expression";s:4:"full";s:8:"duration";i:138;s:9:"yt$format";i:1;}i:2;a:6:{s:3:"url";s:102:"rtsp://r1---sn-jc47eu7s.c.youtube.com/CiILENy73wIaGQmYLwJiQuD2rBMYESARFEgGUgZ2aWRlb3MM/0/0/0/video.3gp";s:4:"type";s:10:"video/3gpp";s:6:"medium";s:5:"video";s:10:"expression";s:4:"full";s:8:"duration";i:138;s:9:"yt$format";i:6;}}s:12:"media$credit";a:1:{i:0;s:18:"resultsorientedweb";}s:17:"media$description";s:173:"In this video, Brent discusses and demos a CK Editor / Bootstrap 3 integration for Drupal to show you how easy it can be to create complex page layouts with the right tools!";s:14:"media$keywords";a:0:{}s:13:"media$license";s:7:"youtube";s:12:"media$player";a:1:{s:3:"url";s:71:"http://www.youtube.com/watch?v=rPbgQmICL5g&feature=youtube_gdata_player";}s:15:"media$thumbnail";a:7:{i:0;a:5:{s:3:"url";s:45:"http://i.ytimg.com/vi/rPbgQmICL5g/default.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:8:"00:01:09";s:7:"yt$name";s:7:"default";}i:1;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/rPbgQmICL5g/mqdefault.jpg";s:6:"height";i:180;s:5:"width";i:320;s:7:"yt$name";s:9:"mqdefault";}i:2;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/rPbgQmICL5g/hqdefault.jpg";s:6:"height";i:360;s:5:"width";i:480;s:7:"yt$name";s:9:"hqdefault";}i:3;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/rPbgQmICL5g/sddefault.jpg";s:6:"height";i:480;s:5:"width";i:640;s:7:"yt$name";s:9:"sddefault";}i:4;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/rPbgQmICL5g/1.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:12:"00:00:34.500";s:7:"yt$name";s:5:"start";}i:5;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/rPbgQmICL5g/2.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:8:"00:01:09";s:7:"yt$name";s:6:"middle";}i:6;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/rPbgQmICL5g/3.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:12:"00:01:43.500";s:7:"yt$name";s:3:"end";}}s:11:"media$title";s:34:"Open Enteprise: Formatting Content";s:14:"yt$aspectRatio";s:10:"widescreen";s:11:"yt$duration";a:1:{s:7:"seconds";s:3:"138";}s:11:"yt$uploaded";s:24:"2014-12-19T16:33:49.000Z";s:13:"yt$uploaderId";s:24:"UCv9AEmq8SjPA3yA-vBs6dgg";s:10:"yt$videoid";s:11:"rPbgQmICL5g";}s:13:"yt$statistics";a:2:{s:13:"favoriteCount";s:1:"0";s:9:"viewCount";s:3:"325";}s:5:"terms";a:1:{i:0;s:4:"Tech";}s:7:"handler";s:7:"youtube";}',
          'video_url' => 'https://www.youtube.com/watch?v=rPbgQmICL5g',
        ),
      ),
    ),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 0,
    'status' => 1,
    'sticky' => 0,
    'title' => 'Open Enteprise: Formatting Content',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_video',
    'uid' => 1,
    'url_alias' => array(),
    'uuid' => '54281e77-2013-4e08-a833-13f21ffcf9dc',
  );
  $entities['enterprise_video_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/465f9f09-2cea-4f44-bba9-8599ed5775ea',
      'cause' => FALSE,
    ),
    'body' => array(),
    'cid' => 0,
    'comment' => 2,
    'comment_count' => 0,
    'cta' => array(
      'selections' => array(),
    ),
    'ds_switch' => '',
    'entity_type' => 'node',
    'field_video_embed' => array(
      'und' => array(
        0 => array(
          'description' => NULL,
          'embed_code' => NULL,
          'thumbnail_path' => 'public://video_embed_field_thumbnails/youtube/IRoPpgjK1vo.jpg',
          'video_data' => 'a:20:{s:5:"xmlns";s:27:"http://www.w3.org/2005/Atom";s:8:"xmlns$gd";s:32:"http://schemas.google.com/g/2005";s:8:"xmlns$yt";s:37:"http://gdata.youtube.com/schemas/2007";s:11:"xmlns$media";s:29:"http://search.yahoo.com/mrss/";s:7:"gd$etag";s:28:"W/"DUEBQH47eCp7I2A9XRRTFUo."";s:2:"id";s:38:"tag:youtube.com,2008:video:IRoPpgjK1vo";s:9:"published";s:24:"2014-12-29T22:19:16.000Z";s:7:"updated";s:24:"2015-01-06T20:54:11.000Z";s:8:"category";a:2:{i:0;a:2:{s:6:"scheme";s:37:"http://schemas.google.com/g/2005#kind";s:4:"term";s:43:"http://gdata.youtube.com/schemas/2007#video";}i:1;a:3:{s:6:"scheme";s:52:"http://gdata.youtube.com/schemas/2007/categories.cat";s:4:"term";s:4:"Tech";s:5:"label";s:20:"Science & Technology";}}s:5:"title";s:35:"Intelligence Content Entrance Pages";s:7:"content";a:2:{s:4:"type";s:29:"application/x-shockwave-flash";s:3:"src";s:73:"http://www.youtube.com/v/IRoPpgjK1vo?version=3&f=videos&app=youtube_gdata";}s:4:"link";a:5:{i:0;a:3:{s:3:"rel";s:9:"alternate";s:4:"type";s:9:"text/html";s:4:"href";s:64:"http://www.youtube.com/watch?v=IRoPpgjK1vo&feature=youtube_gdata";}i:1;a:3:{s:3:"rel";s:51:"http://gdata.youtube.com/schemas/2007#video.related";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:65:"http://gdata.youtube.com/feeds/api/videos/IRoPpgjK1vo/related?v=2";}i:2;a:3:{s:3:"rel";s:44:"http://gdata.youtube.com/schemas/2007#mobile";s:4:"type";s:9:"text/html";s:4:"href";s:42:"http://m.youtube.com/details?v=IRoPpgjK1vo";}i:3;a:3:{s:3:"rel";s:46:"http://gdata.youtube.com/schemas/2007#uploader";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:67:"http://gdata.youtube.com/feeds/api/users/v9AEmq8SjPA3yA-vBs6dgg?v=2";}i:4;a:3:{s:3:"rel";s:4:"self";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:57:"http://gdata.youtube.com/feeds/api/videos/IRoPpgjK1vo?v=2";}}s:6:"author";a:1:{i:0;a:3:{s:4:"name";s:18:"resultsorientedweb";s:3:"uri";s:59:"http://gdata.youtube.com/feeds/api/users/resultsorientedweb";s:9:"yt$userId";s:22:"v9AEmq8SjPA3yA-vBs6dgg";}}s:16:"yt$accessControl";a:8:{i:0;a:2:{s:6:"action";s:7:"comment";s:10:"permission";s:7:"allowed";}i:1;a:2:{s:6:"action";s:11:"commentVote";s:10:"permission";s:7:"allowed";}i:2;a:2:{s:6:"action";s:12:"videoRespond";s:10:"permission";s:9:"moderated";}i:3;a:2:{s:6:"action";s:4:"rate";s:10:"permission";s:7:"allowed";}i:4;a:2:{s:6:"action";s:5:"embed";s:10:"permission";s:7:"allowed";}i:5;a:2:{s:6:"action";s:4:"list";s:10:"permission";s:7:"allowed";}i:6;a:2:{s:6:"action";s:8:"autoPlay";s:10:"permission";s:7:"allowed";}i:7;a:2:{s:6:"action";s:9:"syndicate";s:10:"permission";s:7:"allowed";}}s:11:"gd$comments";a:1:{s:11:"gd$feedLink";a:3:{s:3:"rel";s:46:"http://gdata.youtube.com/schemas/2007#comments";s:4:"href";s:66:"http://gdata.youtube.com/feeds/api/videos/IRoPpgjK1vo/comments?v=2";s:9:"countHint";i:0;}}s:5:"yt$hd";a:0:{}s:11:"media$group";a:14:{s:14:"media$category";a:1:{i:0;s:4:"Tech";}s:13:"media$content";a:3:{i:0;a:7:{s:3:"url";s:73:"http://www.youtube.com/v/IRoPpgjK1vo?version=3&f=videos&app=youtube_gdata";s:4:"type";s:29:"application/x-shockwave-flash";s:6:"medium";s:5:"video";s:9:"isDefault";s:4:"true";s:10:"expression";s:4:"full";s:8:"duration";i:592;s:9:"yt$format";i:5;}i:1;a:6:{s:3:"url";s:102:"rtsp://r4---sn-jc47eu7k.c.youtube.com/CiILENy73wIaGQn61soIpg8aIRMYDSANFEgGUgZ2aWRlb3MM/0/0/0/video.3gp";s:4:"type";s:10:"video/3gpp";s:6:"medium";s:5:"video";s:10:"expression";s:4:"full";s:8:"duration";i:592;s:9:"yt$format";i:1;}i:2;a:6:{s:3:"url";s:102:"rtsp://r4---sn-jc47eu7k.c.youtube.com/CiILENy73wIaGQn61soIpg8aIRMYESARFEgGUgZ2aWRlb3MM/0/0/0/video.3gp";s:4:"type";s:10:"video/3gpp";s:6:"medium";s:5:"video";s:10:"expression";s:4:"full";s:8:"duration";i:592;s:9:"yt$format";i:6;}}s:12:"media$credit";a:1:{i:0;s:18:"resultsorientedweb";}s:17:"media$description";s:113:"In-depth demonstration of OE Intelligence and how it can be used to determine content value and CTA optimization.";s:14:"media$keywords";a:0:{}s:13:"media$license";s:7:"youtube";s:12:"media$player";a:1:{s:3:"url";s:71:"http://www.youtube.com/watch?v=IRoPpgjK1vo&feature=youtube_gdata_player";}s:15:"media$thumbnail";a:7:{i:0;a:5:{s:3:"url";s:45:"http://i.ytimg.com/vi/IRoPpgjK1vo/default.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:8:"00:04:56";s:7:"yt$name";s:7:"default";}i:1;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/IRoPpgjK1vo/mqdefault.jpg";s:6:"height";i:180;s:5:"width";i:320;s:7:"yt$name";s:9:"mqdefault";}i:2;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/IRoPpgjK1vo/hqdefault.jpg";s:6:"height";i:360;s:5:"width";i:480;s:7:"yt$name";s:9:"hqdefault";}i:3;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/IRoPpgjK1vo/sddefault.jpg";s:6:"height";i:480;s:5:"width";i:640;s:7:"yt$name";s:9:"sddefault";}i:4;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/IRoPpgjK1vo/1.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:8:"00:02:28";s:7:"yt$name";s:5:"start";}i:5;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/IRoPpgjK1vo/2.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:8:"00:04:56";s:7:"yt$name";s:6:"middle";}i:6;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/IRoPpgjK1vo/3.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:8:"00:07:24";s:7:"yt$name";s:3:"end";}}s:11:"media$title";s:35:"Intelligence Content Entrance Pages";s:14:"yt$aspectRatio";s:10:"widescreen";s:11:"yt$duration";a:1:{s:7:"seconds";s:3:"592";}s:11:"yt$uploaded";s:24:"2014-12-29T22:19:16.000Z";s:13:"yt$uploaderId";s:24:"UCv9AEmq8SjPA3yA-vBs6dgg";s:10:"yt$videoid";s:11:"IRoPpgjK1vo";}s:13:"yt$statistics";a:2:{s:13:"favoriteCount";s:1:"0";s:9:"viewCount";s:2:"27";}s:5:"terms";a:1:{i:0;s:4:"Tech";}s:7:"handler";s:7:"youtube";}',
          'video_url' => 'https://www.youtube.com/watch?v=IRoPpgjK1vo',
        ),
      ),
    ),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 0,
    'status' => 1,
    'sticky' => 0,
    'title' => 'Executive Summary',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_video',
    'uid' => 1,
    'url_alias' => array(),
    'uuid' => '465f9f09-2cea-4f44-bba9-8599ed5775ea',
  );
  $entities['enterprise_video_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/c6c6267e-b0dd-4275-a316-e630cd4a2000',
      'cause' => FALSE,
    ),
    'body' => array(),
    'cid' => 0,
    'comment' => 2,
    'comment_count' => 0,
    'cta' => array(
      'selections' => array(),
    ),
    'ds_switch' => '',
    'entity_type' => 'node',
    'field_video_embed' => array(
      'und' => array(
        0 => array(
          'description' => NULL,
          'embed_code' => NULL,
          'thumbnail_path' => 'public://video_embed_field_thumbnails/youtube/A__S2YudnFI.jpg',
          'video_data' => 'a:20:{s:5:"xmlns";s:27:"http://www.w3.org/2005/Atom";s:8:"xmlns$gd";s:32:"http://schemas.google.com/g/2005";s:8:"xmlns$yt";s:37:"http://gdata.youtube.com/schemas/2007";s:11:"xmlns$media";s:29:"http://search.yahoo.com/mrss/";s:7:"gd$etag";s:28:"W/"CEUMQ347eCp7I2A9XRdbGE4."";s:2:"id";s:38:"tag:youtube.com,2008:video:A__S2YudnFI";s:9:"published";s:24:"2014-12-17T16:04:42.000Z";s:7:"updated";s:24:"2014-12-17T16:04:42.000Z";s:8:"category";a:2:{i:0;a:2:{s:6:"scheme";s:37:"http://schemas.google.com/g/2005#kind";s:4:"term";s:43:"http://gdata.youtube.com/schemas/2007#video";}i:1;a:3:{s:6:"scheme";s:52:"http://gdata.youtube.com/schemas/2007/categories.cat";s:4:"term";s:4:"Tech";s:5:"label";s:20:"Science & Technology";}}s:5:"title";s:40:"Open Enterprise Intelligence: Scorecards";s:7:"content";a:2:{s:4:"type";s:29:"application/x-shockwave-flash";s:3:"src";s:73:"http://www.youtube.com/v/A__S2YudnFI?version=3&f=videos&app=youtube_gdata";}s:4:"link";a:5:{i:0;a:3:{s:3:"rel";s:9:"alternate";s:4:"type";s:9:"text/html";s:4:"href";s:64:"http://www.youtube.com/watch?v=A__S2YudnFI&feature=youtube_gdata";}i:1;a:3:{s:3:"rel";s:51:"http://gdata.youtube.com/schemas/2007#video.related";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:65:"http://gdata.youtube.com/feeds/api/videos/A__S2YudnFI/related?v=2";}i:2;a:3:{s:3:"rel";s:44:"http://gdata.youtube.com/schemas/2007#mobile";s:4:"type";s:9:"text/html";s:4:"href";s:42:"http://m.youtube.com/details?v=A__S2YudnFI";}i:3;a:3:{s:3:"rel";s:46:"http://gdata.youtube.com/schemas/2007#uploader";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:67:"http://gdata.youtube.com/feeds/api/users/v9AEmq8SjPA3yA-vBs6dgg?v=2";}i:4;a:3:{s:3:"rel";s:4:"self";s:4:"type";s:20:"application/atom+xml";s:4:"href";s:57:"http://gdata.youtube.com/feeds/api/videos/A__S2YudnFI?v=2";}}s:6:"author";a:1:{i:0;a:3:{s:4:"name";s:18:"resultsorientedweb";s:3:"uri";s:59:"http://gdata.youtube.com/feeds/api/users/resultsorientedweb";s:9:"yt$userId";s:22:"v9AEmq8SjPA3yA-vBs6dgg";}}s:16:"yt$accessControl";a:8:{i:0;a:2:{s:6:"action";s:7:"comment";s:10:"permission";s:7:"allowed";}i:1;a:2:{s:6:"action";s:11:"commentVote";s:10:"permission";s:7:"allowed";}i:2;a:2:{s:6:"action";s:12:"videoRespond";s:10:"permission";s:9:"moderated";}i:3;a:2:{s:6:"action";s:4:"rate";s:10:"permission";s:7:"allowed";}i:4;a:2:{s:6:"action";s:5:"embed";s:10:"permission";s:7:"allowed";}i:5;a:2:{s:6:"action";s:4:"list";s:10:"permission";s:7:"allowed";}i:6;a:2:{s:6:"action";s:8:"autoPlay";s:10:"permission";s:7:"allowed";}i:7;a:2:{s:6:"action";s:9:"syndicate";s:10:"permission";s:7:"allowed";}}s:11:"gd$comments";a:1:{s:11:"gd$feedLink";a:3:{s:3:"rel";s:46:"http://gdata.youtube.com/schemas/2007#comments";s:4:"href";s:66:"http://gdata.youtube.com/feeds/api/videos/A__S2YudnFI/comments?v=2";s:9:"countHint";i:0;}}s:5:"yt$hd";a:0:{}s:11:"media$group";a:14:{s:14:"media$category";a:1:{i:0;s:4:"Tech";}s:13:"media$content";a:3:{i:0;a:7:{s:3:"url";s:73:"http://www.youtube.com/v/A__S2YudnFI?version=3&f=videos&app=youtube_gdata";s:4:"type";s:29:"application/x-shockwave-flash";s:6:"medium";s:5:"video";s:9:"isDefault";s:4:"true";s:10:"expression";s:4:"full";s:8:"duration";i:154;s:9:"yt$format";i:5;}i:1;a:6:{s:3:"url";s:102:"rtsp://r2---sn-jc47eu7z.c.youtube.com/CiILENy73wIaGQlSnJ2L2dL_AxMYDSANFEgGUgZ2aWRlb3MM/0/0/0/video.3gp";s:4:"type";s:10:"video/3gpp";s:6:"medium";s:5:"video";s:10:"expression";s:4:"full";s:8:"duration";i:154;s:9:"yt$format";i:1;}i:2;a:6:{s:3:"url";s:102:"rtsp://r2---sn-jc47eu7z.c.youtube.com/CiILENy73wIaGQlSnJ2L2dL_AxMYESARFEgGUgZ2aWRlb3MM/0/0/0/video.3gp";s:4:"type";s:10:"video/3gpp";s:6:"medium";s:5:"video";s:10:"expression";s:4:"full";s:8:"duration";i:154;s:9:"yt$format";i:6;}}s:12:"media$credit";a:1:{i:0;s:18:"resultsorientedweb";}s:17:"media$description";s:153:"Intelligence Scorecards help you identify how well your content resonates with your audience and provides actionable insights for your marketing efforts.";s:14:"media$keywords";a:0:{}s:13:"media$license";s:7:"youtube";s:12:"media$player";a:1:{s:3:"url";s:71:"http://www.youtube.com/watch?v=A__S2YudnFI&feature=youtube_gdata_player";}s:15:"media$thumbnail";a:7:{i:0;a:5:{s:3:"url";s:45:"http://i.ytimg.com/vi/A__S2YudnFI/default.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:8:"00:01:17";s:7:"yt$name";s:7:"default";}i:1;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/A__S2YudnFI/mqdefault.jpg";s:6:"height";i:180;s:5:"width";i:320;s:7:"yt$name";s:9:"mqdefault";}i:2;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/A__S2YudnFI/hqdefault.jpg";s:6:"height";i:360;s:5:"width";i:480;s:7:"yt$name";s:9:"hqdefault";}i:3;a:4:{s:3:"url";s:47:"http://i.ytimg.com/vi/A__S2YudnFI/sddefault.jpg";s:6:"height";i:480;s:5:"width";i:640;s:7:"yt$name";s:9:"sddefault";}i:4;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/A__S2YudnFI/1.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:12:"00:00:38.500";s:7:"yt$name";s:5:"start";}i:5;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/A__S2YudnFI/2.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:8:"00:01:17";s:7:"yt$name";s:6:"middle";}i:6;a:5:{s:3:"url";s:39:"http://i.ytimg.com/vi/A__S2YudnFI/3.jpg";s:6:"height";i:90;s:5:"width";i:120;s:4:"time";s:12:"00:01:55.500";s:7:"yt$name";s:3:"end";}}s:11:"media$title";s:40:"Open Enterprise Intelligence: Scorecards";s:14:"yt$aspectRatio";s:10:"widescreen";s:11:"yt$duration";a:1:{s:7:"seconds";s:3:"154";}s:11:"yt$uploaded";s:24:"2014-12-17T16:04:42.000Z";s:13:"yt$uploaderId";s:24:"UCv9AEmq8SjPA3yA-vBs6dgg";s:10:"yt$videoid";s:11:"A__S2YudnFI";}s:13:"yt$statistics";a:2:{s:13:"favoriteCount";s:1:"0";s:9:"viewCount";s:3:"128";}s:5:"terms";a:1:{i:0;s:4:"Tech";}s:7:"handler";s:7:"youtube";}',
          'video_url' => 'https://www.youtube.com/watch?v=A__S2YudnFI',
        ),
      ),
    ),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 0,
    'status' => 1,
    'sticky' => 0,
    'title' => 'Scorecards',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_video',
    'uid' => 1,
    'url_alias' => array(),
    'uuid' => 'c6c6267e-b0dd-4275-a316-e630cd4a2000',
  );

  return $entities;
}
