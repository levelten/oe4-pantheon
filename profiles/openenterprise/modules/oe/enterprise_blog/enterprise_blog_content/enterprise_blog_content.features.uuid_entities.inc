<?php
/**
 * @file
 * enterprise_blog_content.features.uuid_entities.inc
 */

/**
 * Implements hook_uuid_default_entities().
 */
function enterprise_blog_content_uuid_default_entities() {
  $entities = array();

  /////////////////////////////////////////////////////////
  // Taxonomy terms
  // Blog categories
  //////////////////
  
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/bbe30aac-25a0-4b79-bcdf-4ae28e798ecd',
      'cause' => 'node/ada72cc8-57d8-42b8-82ce-dd7188e6dde4',
    ),
    'description' => '',
    'entity_type' => 'taxonomy_term',
    'format' => 'full_html',
    'metatags' => array(),
    'name' => 'User Experience',
    'slug' => 'user_experience',
    'url_alias' => array(),
    'uuid' => 'bbe30aac-25a0-4b79-bcdf-4ae28e798ecd',
    'vocabulary_machine_name' => 'categories',
    'weight' => 0,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/b9d25f5f-72f6-4224-980e-7798f8a61754',
	  'cause' => 'node/8caf3e4b-71ed-4fbe-b2a6-f0ddaf733c10',
    ),
    'description' => '',
    'entity_type' => 'taxonomy_term',
    'format' => 'full_html',
    'metatags' => array(),
    'name' => 'Development',
    'slug' => 'development',
    'url_alias' => array(),
    'uuid' => 'b9d25f5f-72f6-4224-980e-7798f8a61754',
    'vocabulary_machine_name' => 'categories',
    'weight' => 1,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/27fd15ef-c256-4c59-87f1-311f1636233f',
      'cause' => 'node/3fc7411a-4a40-4c6c-9bc8-a7697cbc8be3',
    ),
    'description' => '',
    'entity_type' => 'taxonomy_term',
    'format' => 'full_html',
    'metatags' => array(),
    'name' => 'Content',
    'slug' => 'content',
    'url_alias' => array(),
    'uuid' => '27fd15ef-c256-4c59-87f1-311f1636233f',
    'vocabulary_machine_name' => 'categories',
    'weight' => 2,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/40a8b548-e564-4149-ac97-34d7c97f5b04',
      'cause' => 'node/b7a86778-4129-4756-84d1-5e4780436c0e',
    ),
    'description' => '',
    'entity_type' => 'taxonomy_term',
    'format' => 'full_html',
    'metatags' => array(),
    'name' => 'Marketing',
    'slug' => 'marketing',
    'url_alias' => array(),
    'uuid' => '40a8b548-e564-4149-ac97-34d7c97f5b04',
    'vocabulary_machine_name' => 'categories',
    'weight' => 3,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/541c1363-2542-4879-a0b9-35fc917ede06',
      'cause' => 'node/7f7991ee-8cf4-4a80-b379-fc2dc9241227',
    ),
    'description' => '',
    'entity_type' => 'taxonomy_term',
    'format' => 'full_html',
    'metatags' => array(),
    'name' => 'Analytics',
    'slug' => 'analytics',
    'url_alias' => array(),
    'uuid' => '541c1363-2542-4879-a0b9-35fc917ede06',
    'vocabulary_machine_name' => 'categories',
    'weight' => 4,
  );


  
  
  /////////////////////////////////////////////////////////
  // Taxonomy terms
  // Blog tags
  //////////////////
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/5f86e113-de5e-450f-836f-fca8a77fb3fc',
      'cause' => 'node/b7a86778-4129-4756-84d1-5e4780436c0e',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'conversion optimization',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => '5f86e113-de5e-450f-836f-fca8a77fb3fc',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/c3d75d66-df2d-4722-bc10-e7338f23e556',
      'cause' => 'node/b7a86778-4129-4756-84d1-5e4780436c0e',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'inbound marketing',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => 'c3d75d66-df2d-4722-bc10-e7338f23e556',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/8092d01d-ecac-4613-a91e-458d5316037f',
      'cause' => 'node/ada72cc8-57d8-42b8-82ce-dd7188e6dde4',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'web design',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => '8092d01d-ecac-4613-a91e-458d5316037f',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
    $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/d386e6be-e2dc-4cf6-a173-b9f608d2d4ff',
      'cause' => 'node/3136cbf9-9438-4c87-8c3e-3716cd45184c',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'SEO',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => 'd386e6be-e2dc-4cf6-a173-b9f608d2d4ff',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/e862c908-d04d-4889-854c-30d1f98fee60',
      'cause' => 'node/3136cbf9-9438-4c87-8c3e-3716cd45184c',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'content marketing',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => 'e862c908-d04d-4889-854c-30d1f98fee60',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/209d087a-3539-4c8b-93af-7f7dbe5d15d5',
      'cause' => 'node/4a734df2-20a7-44e2-be7c-7ab0497e4945',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'mobile',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => '209d087a-3539-4c8b-93af-7f7dbe5d15d5',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/fa5e22fa-c61c-4803-a777-b4b6cfa1c624',
      'cause' => 'node/4a734df2-20a7-44e2-be7c-7ab0497e4945',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'responsive design',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => 'fa5e22fa-c61c-4803-a777-b4b6cfa1c624',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/5c83a36a-73ad-4ae0-89e4-d506b1eb7455',
      'cause' => 'node/4a734df2-20a7-44e2-be7c-7ab0497e4945',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'Bootstrap',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => '5c83a36a-73ad-4ae0-89e4-d506b1eb7455',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
  
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/84c698d7-1eb7-4897-a2c8-1b2bb33e8405',
      'cause' => 'node/3fc7411a-4a40-4c6c-9bc8-a7697cbc8be3',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'branding',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => '84c698d7-1eb7-4897-a2c8-1b2bb33e8405',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/593823d5-1f86-4cb7-8035-f764cb0f9d82',
      'cause' => 'node/3fc7411a-4a40-4c6c-9bc8-a7697cbc8be3',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'style guide',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => '593823d5-1f86-4cb7-8035-f764cb0f9d82',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/61e02ec8-f7b6-4e46-bc09-5467e5b727ca',
      'cause' => 'node/7f7991ee-8cf4-4a80-b379-fc2dc9241227',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'social media',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => '61e02ec8-f7b6-4e46-bc09-5467e5b727ca',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/7b0611d9-fe51-4f6d-b061-533a408d9989',
      'cause' => 'node/7f7991ee-8cf4-4a80-b379-fc2dc9241227',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'ROI',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => '7b0611d9-fe51-4f6d-b061-533a408d9989',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/c2560836-0a54-4631-9dcf-a495ced24d4a',
      'cause' => 'node/7d7aea4c-1b3c-4377-9613-f37ea43d04d4',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'engagement',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => 'c2560836-0a54-4631-9dcf-a495ced24d4a',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/2d4f0dbe-f20c-42ca-bd14-fc2b8f6faf0d',
      'cause' => 'node/8caf3e4b-71ed-4fbe-b2a6-f0ddaf733c10',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'usability',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => '2d4f0dbe-f20c-42ca-bd14-fc2b8f6faf0d',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'taxonomy_term',
      'uri' => 'taxonomy_term/2cda5d3c-f2bd-4ccf-88d4-0503e068c857',
      'cause' => 'node/8caf3e4b-71ed-4fbe-b2a6-f0ddaf733c10',
    ),
    'description' => NULL,
    'entity_type' => 'taxonomy_term',
    'format' => NULL,
    'metatags' => array(),
    'name' => 'Drupal',
    'slug' => '',
    'url_alias' => array(),
    'uuid' => '2cda5d3c-f2bd-4ccf-88d4-0503e068c857',
    'vocabulary_machine_name' => 'tags',
    'weight' => 0,
  );
  
  /////////////////////////////////////////////////////////
  // Nodes and featured images
  //////////////////

  // moved images to seperate files to make this file easier to edit
  include "enterprise_blog_content.features.uuid_entities.img.blog-image2.inc";
  include "enterprise_blog_content.features.uuid_entities.img.bootstrap.inc";
  include "enterprise_blog_content.features.uuid_entities.img.content_analytics.inc";
  include "enterprise_blog_content.features.uuid_entities.img.drupal_admin_usability.inc";
  include "enterprise_blog_content.features.uuid_entities.img.flatdesign.inc";
  include "enterprise_blog_content.features.uuid_entities.img.seo.inc";
  include "enterprise_blog_content.features.uuid_entities.img.social_media_roi.inc";
  include "enterprise_blog_content.features.uuid_entities.img.style_guide.inc";

  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/b7a86778-4129-4756-84d1-5e4780436c0e',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => '<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. In feugiat erat mauris, eget condimentum nibh molestie id. Sed risus odio, fringilla a feugiat in, venenatis id erat. Morbi gravida at ipsum et pulvinar. Fusce et ultrices nisi, ac posuere dui. Sed fringilla dolor et arcu elementum, non facilisis nibh pellentesque. Morbi nec lectus convallis, sodales justo sit amet, sagittis orci. Donec eget sodales sapien, ac tempor nunc. Aenean commodo sem sit amet odio aliquet mollis. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Phasellus rutrum id turpis eu consectetur.</p>

<h3>#1: Create a Conversion Workflow</h3>

<p>Sed lectus mi, convallis sit amet vehicula vitae, lacinia in nisl. Ut dolor urna, ornare eget ligula nec, feugiat convallis eros. Aenean non scelerisque elit. Morbi tincidunt placerat diam at dapibus. Nullam sollicitudin enim eget nulla tincidunt, consectetur lacinia nunc malesuada. Duis dapibus ipsum sed quam egestas, in ornare mauris consectetur. Praesent sodales nunc imperdiet, pulvinar arcu non, condimentum sem. Aenean sem felis, egestas ac condimentum nec, semper non nunc. Fusce pretium aliquet enim, at lacinia nulla elementum eu. Donec elementum eget dolor nec consectetur. Vivamus odio leo, consequat et pharetra nec, scelerisque eget magna. Etiam gravida consectetur nulla, vel posuere nisi malesuada id. Etiam vestibulum urna eget placerat sollicitudin. Sed sagittis justo nec tellus sodales, a sollicitudin nisi dictum. Praesent adipiscing urna ut orci convallis sodales.</p>

<h3>#2: Impress Users Within 8 Seconds</h3>

<p>Pellentesque feugiat est sit amet sem rhoncus vulputate. Nulla adipiscing nisl porta arcu feugiat tempor a nec tortor. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris quam velit, viverra eget diam vitae, rhoncus faucibus quam. Vivamus vel odio volutpat eros hendrerit consectetur a non turpis. Quisque semper rhoncus semper. Pellentesque scelerisque lacus quis massa suscipit egestas. Donec tempus aliquam quam, et dictum tortor. Nullam nec dictum nunc, viverra accumsan leo. Integer non leo ut massa mattis porta sit amet eget purus. Interdum et malesuada fames ac ante ipsum primis in faucibus. Nunc in libero viverra arcu luctus volutpat eget ac arcu. Praesent vitae justo tristique, rhoncus turpis vel, dignissim arcu. Duis imperdiet lorem orci, id fringilla urna sollicitudin a.</p>

<h3>#3: Create Remarkable Content</h3>

<p>Maecenas semper sapien in justo placerat lacinia. Fusce iaculis, velit quis lacinia dictum, justo leo interdum quam, quis malesuada orci velit vitae massa. In hac habitasse platea dictumst. Aliquam erat volutpat. Mauris elementum eleifend pulvinar. In hac habitasse platea dictumst. Integer dignissim velit id nulla pretium consectetur. Ut sit amet massa vitae nisl pellentesque sagittis in sed nisl. Duis nec sapien hendrerit, volutpat mauris id, euismod magna.</p>

<h3>#4: Offer Free Downloads</h3>

<p><span style="font-size: 15px; line-height: 21.428571701049805px; background-color: rgb(255, 255, 255);">Pellentesque feugiat est sit amet sem rhoncus vulputate. Nulla adipiscing nisl porta arcu feugiat tempor a nec tortor. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris quam velit, viverra eget diam vitae, rhoncus faucibus quam. Vivamus vel odio volutpat eros hendrerit consectetur a non turpis. Quisque semper rhoncus semper. Pellentesque scelerisque lacus quis massa suscipit egestas. Donec tempus aliquam quam, et dictum tortor.&nbsp;</span></p>

<h3>#5: Optimize Your Landing Pages</h3>

<p><span style="font-size: 15px; line-height: 21.428571701049805px; background-color: rgb(255, 255, 255);">Praesent sodales nunc imperdiet, pulvinar arcu non, condimentum sem. Aenean sem felis, egestas ac condimentum nec, semper non nunc. Fusce pretium aliquet enim, at lacinia nulla elementum eu. Donec elementum eget dolor nec consectetur. Vivamus odio leo, consequat et pharetra nec, scelerisque eget magna. Etiam gravida consectetur nulla, vel posuere nisi malesuada id. Etiam vestibulum urna eget placerat sollicitudin. Sed sagittis justo nec tellus sodales, a sollicitudin nisi dictum. Praesent adipiscing urna ut orci convallis sodales.</span></p>
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
    'field_categories' => array(
      'und' => array(
        0 => array(
          'tid' => '40a8b548-e564-4149-ac97-34d7c97f5b04',
        ),
      ),
    ),
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '5f86e113-de5e-450f-836f-fca8a77fb3fc',
        ),
        1 => array(
          'tid' => 'c3d75d66-df2d-4722-bc10-e7338f23e556',
        ),
      ),
    ),
    'field_energy_level' => array(
      'und' => array(
        0 => array(
          'radioactivity_energy' => 1144.71,
          'radioactivity_timestamp' => 1401118739,
        ),
      ),
    ),
    'field_image' => array(
      'und' => array(
        0 => array(
          'alt' => 'Responsive website shown in three devices',
          'entity_type' => 'file',
          'fid' => 'c83221f1-16fb-44c1-887c-9dd6af12c1e6',
          'field_file_image_alt_text' => array(),
          'field_file_image_title_text' => array(),
          'filemime' => 'image/png',
          'filename' => 'blog-image2.png',
          'filesize' => 73643,
          'height' => 372,
          'metadata' => array(
            'height' => 372,
            'width' => 839,
          ),
          'metatags' => array(),
          'slug' => '',
          'status' => 1,
          'title' => '',
          'type' => 'image',
          'uid' => 1,
          'uri' => 'public://content/blog/images/blog-image2.png',
          'uuid' => 'c83221f1-16fb-44c1-887c-9dd6af12c1e6',
          'width' => 839,
        ),
      ),
    ),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 1,
    'slug' => '5_tips_to_increase_your_conversion_rates',
    'status' => 1,
    'sticky' => 0,
    'title' => '5 Tips to Increase Your Conversion Rates',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_blog',
    'uid' => '146166ac-061f-4a55-9aff-73d71bd43991',
    'url_alias' => array(
      0 => array(
        'alias' => 'blog/brent-bice/5-tips-increase-your-conversion-rates',
        'language' => 'und',
      ),
    ),
    'uuid' => 'b7a86778-4129-4756-84d1-5e4780436c0e',
  );


  
  
  
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/ada72cc8-57d8-42b8-82ce-dd7188e6dde4',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => '<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. In feugiat erat mauris, eget condimentum nibh molestie id. Sed risus odio, fringilla a feugiat in, venenatis id erat. Morbi gravida at ipsum et pulvinar. Fusce et ultrices nisi, ac posuere dui. Sed fringilla dolor et arcu elementum, non facilisis nibh pellentesque. Morbi nec lectus convallis, sodales justo sit amet, sagittis orci. Donec eget sodales sapien, ac tempor nunc. Aenean commodo sem sit amet odio aliquet mollis. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Phasellus rutrum id turpis eu consectetur.</p>

<p>Sed lectus mi, convallis sit amet vehicula vitae, lacinia in nisl. Ut dolor urna, ornare eget ligula nec, feugiat convallis eros. Aenean non scelerisque elit. Morbi tincidunt placerat diam at dapibus. Nullam sollicitudin enim eget nulla tincidunt, consectetur lacinia nunc malesuada. Duis dapibus ipsum sed quam egestas, in ornare mauris consectetur. Praesent sodales nunc imperdiet, pulvinar arcu non, condimentum sem. Aenean sem felis, egestas ac condimentum nec, semper non nunc. Fusce pretium aliquet enim, at lacinia nulla elementum eu. Donec elementum eget dolor nec consectetur. Vivamus odio leo, consequat et pharetra nec, scelerisque eget magna. Etiam gravida consectetur nulla, vel posuere nisi malesuada id. Etiam vestibulum urna eget placerat sollicitudin. Sed sagittis justo nec tellus sodales, a sollicitudin nisi dictum. Praesent adipiscing urna ut orci convallis sodales.</p>

<p>Pellentesque feugiat est sit amet sem rhoncus vulputate. Nulla adipiscing nisl porta arcu feugiat tempor a nec tortor. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris quam velit, viverra eget diam vitae, rhoncus faucibus quam. Vivamus vel odio volutpat eros hendrerit consectetur a non turpis. Quisque semper rhoncus semper. Pellentesque scelerisque lacus quis massa suscipit egestas. Donec tempus aliquam quam, et dictum tortor. Nullam nec dictum nunc, viverra accumsan leo. Integer non leo ut massa mattis porta sit amet eget purus. Interdum et malesuada fames ac ante ipsum primis in faucibus. Nunc in libero viverra arcu luctus volutpat eget ac arcu. Praesent vitae justo tristique, rhoncus turpis vel, dignissim arcu. Duis imperdiet lorem orci, id fringilla urna sollicitudin a.</p>

<p>Maecenas semper sapien in justo placerat lacinia. Fusce iaculis, velit quis lacinia dictum, justo leo interdum quam, quis malesuada orci velit vitae massa. In hac habitasse platea dictumst. Aliquam erat volutpat. Mauris elementum eleifend pulvinar. In hac habitasse platea dictumst. Integer dignissim velit id nulla pretium consectetur. Ut sit amet massa vitae nisl pellentesque sagittis in sed nisl. Duis nec sapien hendrerit, volutpat mauris id, euismod magna.</p>
',
        ),
      ),
    ),
    'cid' => 0,
    'comment' => 1,
    'comment_count' => 0,
    'ds_switch' => '',
    'entity_type' => 'node',
    'field_categories' => array(
      'und' => array(
        0 => array(
          'tid' => 'bbe30aac-25a0-4b79-bcdf-4ae28e798ecd',
        ),
      ),
    ),
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '8092d01d-ecac-4613-a91e-458d5316037f',
        ),
      ),
    ),
    'field_energy_level' => array(
      'und' => array(
        0 => array(
          'radioactivity_energy' => 1365.01,
          'radioactivity_timestamp' => 1401118778,
        ),
      ),
    ),
    'field_image' => array(
      'und' => array(
        0 => array(
          'alt' => '11 Beautiful Flat Site Designs',
          'entity_type' => 'file',
          'fid' => '916378ed-9110-4133-ad32-c47908a5c8fe',
          'field_file_image_alt_text' => array(),
          'field_file_image_title_text' => array(),
          'filemime' => 'image/png',
          'filename' => 'flatdesign.png',
          'filesize' => 22935,
          'height' => 450,
          'metadata' => array(
            'height' => 450,
            'width' => 900,
          ),
          'metatags' => array(),
          'slug' => '',
          'status' => 1,
          'title' => '',
          'type' => 'image',
          'uid' => '70971d97-b391-4c30-9ecd-727105ebfa04',
          'uri' => 'public://content/blog/images/flatdesign.png',
          'uuid' => '916378ed-9110-4133-ad32-c47908a5c8fe',
          'width' => 900,
        ),
      ),
    ),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 1,
    'slug' => 'this_is_and_example_blog_post',
    'status' => 1,
    'sticky' => 0,
    'title' => '11 Beautiful Flat Site Designs',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_blog',
    'uid' => 'ace1a6ba-e405-4f03-a6c9-495300d06ac7',
    'url_alias' => array(
      0 => array(
        'alias' => 'blog/gretchen-voelker/11-beautiful-flat-site-designs',
        'language' => 'und',
      ),
    ),
    'uuid' => 'ada72cc8-57d8-42b8-82ce-dd7188e6dde4',
  );  

  
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/3136cbf9-9438-4c87-8c3e-3716cd45184c',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => '<p>When it comes to SEO, there are a lot of myths swirling around. Unfortunately, too many of those myths can be confused with facts, and end up being believed by individuals and companies who are trying to get ahead online. They end up doing the wrong things, or scrapping the good ideas because they\'re taking too long, which can put them further behind. Here are 10 SEO myths you really need to let go of this year.</p>

<h3>1. Build it and people will come</h3>

<p>Not true. Even if you build a great site, full of wonderful content, people aren\'t going to be flocking to it. They won\'t even know it\'s there. The only way most of them will ever find your site will be through frequent updates with the right SEO, promoting through social media and plenty of patience. It takes time to build an empire, but it also takes the right techniques and a lot of work. Just putting something out there isn\'t enough.</p>

<h3>2. SEO is dead</h3>

<p>It really isn\'t. It <em>has</em> changed, though, which means all the people who are still using it the old way think it\'s dead. They don\'t realize that they need to make adjustments, and they only see that what they\'re doing isn\'t working anymore. Since they still think they know what they\'re doing, and it isn\'t working anymore, it must be the fault of "dead" SEO that isn\'t useful to them any longer. They move on to something else, but since they stop doing SEO at all, they end up worse off than when they started.</p>

<h3>3. SEO is cheap</h3>

<p>True and false. You can get SEO for cheap. Getting <em>good SEO</em>, though, is most definitely not cheap. It\'s much more than just letting someone get hold of your site\'s content and adjust the keywords in it. There are tags, titles, and behind-the-scenes things that go on all the time, along with constant changes and updates that need to be made. SEO is like a living thing, and it needs to be fed and attended to. That isn\'t cheap, nor should it be. With SEO, you really do get what you pay for.</p>

<h3>4. SEO can\'t be used with content marketing</h3>

<p>Of course it can! People think that SEO is about a bunch of strategically placed keywords to keep search engines happy, and that content marketing is all about appealing to the reader. Those things are broadly true, but there\'s absolutely no reason the two have to be mutually exclusive. It is not that difficult to put good keywords that make sense into a very readable piece of information. The combination of the two is actually win-win, because it makes readers and search engines both happy. It\'s hard to think of something internet-related that\'s better than that when it comes to getting noticed online.</p>

<h3>5. Position (rank) isn\'t important</h3>

<p>Position or rank is nearly everything. Ranking #1 is obviously best, but you\'ve at least got to get on the first page. When people search for something, most of them never go beyond page one of their search results. They <em>might</em> go to page two if they are really looking for something important or digging deep into a particular area of knowledge, but they generally see the top results as the best results, so those are what they click on. They find what they need, and they\'re off to the next thing. You need to rank as high as possible.</p>

<h3>6. SEO doesn\'t matter</h3>

<p>Are people crazy? SEO matters <em>a lot.</em> It\'s not everything, and it\'s theoretically possible to have success without it, but it\'s what search engines look for. If you want to be found, and you want people to like what they see once they find you, SEO should be a big part of what you\'re focused on. You can write amazing content, but if the search engines don\'t pick it up and put it high up in the search results, most people are never going to know that you wrote anything at all.</p>
',
        ),
      ),
    ),
    'cid' => 0,
    'comment' => 1,
    'comment_count' => 0,
    'ds_switch' => '',
    'entity_type' => 'node',
    'field_categories' => array(
      'und' => array(
        0 => array(
          'tid' => '40a8b548-e564-4149-ac97-34d7c97f5b04',
        ),
      ),
    ),
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => 'd386e6be-e2dc-4cf6-a173-b9f608d2d4ff',
        ),
        1 => array(
          'tid' => 'e862c908-d04d-4889-854c-30d1f98fee60',
        ),
      ),
    ),
    'field_energy_level' => array(
      'und' => array(
        0 => array(
          'radioactivity_energy' => 1745.58,
          'radioactivity_timestamp' => 1401118972,
        ),
      ),
    ),
    'field_image' => array(
      'und' => array(
        0 => array(
          'alt' => 'SEO spelled out on keyboard',
          'entity_type' => 'file',
          'fid' => '415a6a56-202f-4edc-b399-87360c666e73',
          'field_file_image_alt_text' => array(),
          'field_file_image_title_text' => array(),
          'filemime' => 'image/jpeg',
          'filename' => 'seo.jpg',
          'filesize' => 164370,
          'height' => 450,
          'metadata' => array(
            'height' => 450,
            'width' => 900,
          ),
          'metatags' => array(),
          'slug' => '',
          'status' => 1,
          'title' => '',
          'type' => 'image',
          'uid' => '70971d97-b391-4c30-9ecd-727105ebfa04',
          'uri' => 'public://content/blog/images/seo.jpg',
          'uuid' => '415a6a56-202f-4edc-b399-87360c666e73',
          'width' => 900,
        ),
      ),
    ),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 1,
    'slug' => 'how_to_optimize_your_website_for_search_engines',
    'status' => 1,
    'sticky' => 0,
    'title' => 'How To Optimize Your Website for Search Engines',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_blog',
    'uid' => '70971d97-b391-4c30-9ecd-727105ebfa04',
    'url_alias' => array(
      0 => array(
        'alias' => 'blog/tom-mccracken/how-optimize-your-website-search-engines',
        'language' => 'und',
      ),
    ),
    'uuid' => '3136cbf9-9438-4c87-8c3e-3716cd45184c',
  );
   
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/4a734df2-20a7-44e2-be7c-7ab0497e4945',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => '<p>Let\'s put aside for a moment the fact that Google\'s April 2015 algorithm update is the reason all savvy companies are rushing to perfect a mobile-ready site. Have you thought about all the other reasons to have your website mobile-friendly from the get go? The goal is to display the same information that your site shows on a desktop, just on a tablet or on a smartphone that fits in the palm of your hand.</p>

<h3>Mobile Internet Browsing Has Already Overtaken Desktop</h3>

<p>We\'ve already passed the tipping point: as of August 2014, <a href="http://techcrunch.com/2014/08/21/majority-of-digital-media-consumption-now-takes-place-in-mobile-apps/">more people access the internet through a mobile device</a>&nbsp;than from a desktop computer. That\'s according to comScore, a leading cross-platform measurement company that precisely measures audiences and consumer behavior. And inbound marketing giant <a href="http://www.hubspot.com/marketing-statistics">HubSpot agrees</a>: 37% of consumers are more likely to make a purchase on a mobile-optimized site, while a staggering 39% of companies have not yet optimized their site for mobile visitors. This alone should be enough to convince you that having a functional mobile website design is essential.</p>

<blockquote>27% of consumers will leave a site if it is not mobile-optimized. Which means if content is the way you’re bringing people in, you may risk losing them well before conversion is even a possibility.<br />
- HubSpot Marketing Statistics</blockquote>

<h3>What Does Mobile Responsive Design Look Like?</h3>

<p>A great looking mobile-ready website displays all the same information you\'d see if accessing the site from a desktop, just in a new layout that makes more sense for the smaller screen of a tablet or laptop. Visitors should be able to easily see and read your content no matter what device they\'re using, without having to zoom in or out of the frame to read it.</p>

<p>Take a look at this GIF of ESPN\'s website. The full-size site would still look good on a huge HDTV (they\'ve got a ton of content!). As the browser window becomes smaller, the layout shifts to a format that looks good on a tablet, and then to a format that makes sense for smartphones. All the same information is there; it\'s just been rearranged to meet the needs of different screen sizes on different devices.</p>

<h3>What Makes a Successful Mobile Responsive Design?</h3>

<p>There are a few key things every mobile-optimized website needs to address. Visitors should be able to see your content easily without having to zoom in or out of the frame to read it. Also, adding sharing buttons should be standard, so visitors can share your content with others. This allows for visitor to help bring in more traffic to your website and potentially attract leads and increase sales. Images should be at the same resolution as they would be on a desktop monitor.</p>

<p>Here\'s<a href="https://webmasters.googleblog.com/2015/04/rolling-out-mobile-friendly-update.html">what Google itself has to say</a>&nbsp;about mobile responsive websites:</p>

<blockquote>"We\'re boosting the ranking of mobile-friendly pages on mobile search results. . . . where text is readable without tapping or zooming, tap targets are spaced appropriately, and the page avoids unplayable content or horizontal scrolling."</blockquote>

<h2>How Can I Tell if My Site is Mobile-Friendly?</h2>

<p>The good news is that Google considers mobile-friendliness to be a black-or-white issue -- that is to say, a site is either mobile responsive or it is not. You can\'t be "a little bit" mobile friendly, at least not to Google.</p>

<p>There are plenty of tools online that will crawl your site and come back to you with mobile responsive recommendations. A good place to start is Google\'s<a href="https://www.google.com/webmasters/tools/mobile-friendly/">"Mobile-Friendly Test,"</a>&nbsp;which quickly assess whether or not your site meets the mobile responsive standards. Here\'s how our site fared:</p>

<h2>How Do I Get a Mobile Responsive Design?</h2>

<p>If you have a typical WordPress site, it\'s actually really simple to implement a slick responsive design. You just need to make sure that your WordPress theme is mobile responsive, and plenty of the free ones are. (One caveat: some themes are more thorough than others, so be sure to do plenty of testing on different devices and browsers to make sure you\'re looking good on every platform.)</p>

<p>If you have a more complicated website, you may need to enlist your developer\'s help to make sure your site\'s theme looks good on every device. At LevelTen, we usually design and develop big enterprise-level Drupal websites, so we\'ve made sure that our Drupal distribution automatically rearranges the layout for the best viewing experience on any device.</p>

<p>Having a mobile-friendly website should be a key part of a company website redesign strategy in order to practice inbound marketing successfully. It will also help you rank well on search engines, as Google favors sites that deliver a smooth viewing experience across screen sizes. However, this can\'t happen if website visitors leave because the website is too hard to navigate on today\'s 5- to 6-inch mobile screens. It is now a mobile-first Internet, so remember to check your websites for mobile responsiveness and you\'ll continue to attract visitors.</p>
',
        ),
      ),
    ),
    'cid' => 0,
    'comment' => 1,
    'comment_count' => 0,
    'ds_switch' => '',
    'entity_type' => 'node',
    'field_categories' => array(
      'und' => array(
        0 => array(
          'tid' => 'bbe30aac-25a0-4b79-bcdf-4ae28e798ecd',
        ),
        1 => array(
          'tid' => 'b9d25f5f-72f6-4224-980e-7798f8a61754',
        ),
      ),
    ),
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '209d087a-3539-4c8b-93af-7f7dbe5d15d5',
        ),
        1 => array(
          'tid' => 'fa5e22fa-c61c-4803-a777-b4b6cfa1c624',
        ),
        2 => array(
          'tid' => '5c83a36a-73ad-4ae0-89e4-d506b1eb7455',
        ),
      ),
    ),
    'field_energy_level' => array(
      'und' => array(
        0 => array(
          'radioactivity_energy' => 2000,
          'radioactivity_timestamp' => 1401118939,
        ),
      ),
    ),
    'field_image' => array(
      'und' => array(
        0 => array(
          'alt' => '',
          'entity_type' => 'file',
          'fid' => 'ed96fff4-5d75-49b4-b681-6c6a43d8c018',
          'field_file_image_alt_text' => array(),
          'field_file_image_title_text' => array(),
          'filemime' => 'image/png',
          'filename' => 'bootstrap.png',
          'filesize' => 161522,
          'height' => 450,
          'metadata' => array(
            'height' => 450,
            'width' => 900,
          ),
          'metatags' => array(),
          'slug' => '',
          'status' => 1,
          'title' => '',
          'type' => 'image',
          'uid' => 1,
          'uri' => 'public://content/blog/images/bootstrap.png',
          'uuid' => 'ed96fff4-5d75-49b4-b681-6c6a43d8c018',
          'width' => 900,
        ),
      ),
    ),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 1,
    'slug' => '5_benefits_of_using_bootstrap',
    'status' => 1,
    'sticky' => 0,
    'title' => 'Responsive Design Simplified with Bootstrap',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_blog',
    'uid' => '635f232a-d770-4481-b9b9-f9e4e2a79aab',
    'url_alias' => array(
      0 => array(
        'alias' => 'blog/kyle-taylor/responsive-design-simplified-bootstrap',
        'language' => 'und',
      ),
    ),
    'uuid' => '4a734df2-20a7-44e2-be7c-7ab0497e4945',
  );
  
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/3fc7411a-4a40-4c6c-9bc8-a7697cbc8be3',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => '<p>Phasellus lacinia mollis ligula non fringilla. Praesent cursus magna ipsum, sed mattis ipsum facilisis sit amet. Aliquam nec urna ultricies, fermentum leo ac, faucibus urna. Nunc lacinia est nisl, nec molestie arcu pulvinar vitae. Nullam lacus leo, feugiat in ipsum sit amet, tempor sagittis arcu. Ut vel pellentesque enim, in placerat erat. Mauris sed pretium quam, suscipit blandit nisi. Vestibulum consequat a ipsum sit amet suscipit. Curabitur sagittis ornare mauris, at venenatis ipsum eleifend pellentesque. Vestibulum semper, metus et viverra cursus, lacus nisi elementum lacus, venenatis posuere nisi nisi vitae dolor. Maecenas tempus dictum arcu non blandit. Nunc pretium condimentum libero sed ornare.</p>

<p>Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Nulla sed tempus purus. Praesent tincidunt odio id nibh rutrum, a scelerisque libero accumsan. Fusce vitae egestas leo. Aliquam feugiat pellentesque urna, sit amet hendrerit massa adipiscing ullamcorper. Etiam bibendum tortor tempus lorem dignissim vestibulum. Nam non pellentesque diam. Nulla lobortis est orci, in tincidunt neque tristique vitae. Aenean eleifend laoreet tellus, eu luctus lorem. Suspendisse potenti. Mauris condimentum leo ut felis pharetra, at feugiat nunc commodo.</p>
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
    'disqus' => array(
      'domain' => 'oeprodemo',
      'status' => TRUE,
      'url' => 'http://oepro3p.localhost:8082/blog/ian-whitcomb/brand-publisher-style-guides',
      'title' => 'Brand Like a Publisher with Style Guides',
      'identifier' => 'node/30',
      'developer' => 1,
    ),
    'ds_switch' => '',
    'entity_type' => 'node',
    'field_categories' => array(
      'und' => array(
        0 => array(
          'tid' => 'bbe30aac-25a0-4b79-bcdf-4ae28e798ecd',
        ),
        1 => array(
          'tid' => '27fd15ef-c256-4c59-87f1-311f1636233f',
        ),
      ),
    ),
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '84c698d7-1eb7-4897-a2c8-1b2bb33e8405',
        ),
        1 => array(
          'tid' => '593823d5-1f86-4cb7-8035-f764cb0f9d82',
        ),
        2 => array(
          'tid' => '8092d01d-ecac-4613-a91e-458d5316037f',
        ),
      ),
    ),
    'field_energy_level' => array(
      'und' => array(
        0 => array(
          'radioactivity_energy' => 2000,
          'radioactivity_timestamp' => 1401118916,
        ),
      ),
    ),
    'field_image' => array(
      'und' => array(
        0 => array(
          'alt' => 'screenshot of Bootstrap style guide',
          'entity_type' => 'file',
          'fid' => '6b7f77ee-1e9f-42d8-affd-fb359fc36523',
          'field_file_image_alt_text' => array(),
          'field_file_image_title_text' => array(),
          'filemime' => 'image/png',
          'filename' => 'style_guide.png',
          'filesize' => 100164,
          'height' => 428,
          'metadata' => array(
            'height' => 428,
            'width' => 849,
          ),
          'metatags' => array(),
          'slug' => '',
          'status' => 1,
          'title' => '',
          'type' => 'image',
          'uid' => 1,
          'uri' => 'public://content/blog/images/style_guide.png',
          'uuid' => '6b7f77ee-1e9f-42d8-affd-fb359fc36523',
          'width' => 849,
        ),
      ),
    ),

    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 1,
    'slug' => 'brand_like_a_publisher_with_style_guides',
    'status' => 1,
    'sticky' => 0,
    'title' => 'Brand Like a Publisher with Style Guides',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_blog',
    'uid' => '1ddb8c80-48e7-4268-a57f-dce9e4b69a9e',
    'url_alias' => array(
      0 => array(
        'alias' => 'blog/ian-whitcomb/brand-publisher-style-guides',
        'language' => 'und',
      ),
    ),
    'uuid' => '3fc7411a-4a40-4c6c-9bc8-a7697cbc8be3',
  );
  
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/7f7991ee-8cf4-4a80-b379-fc2dc9241227',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => '<p>Social media is the ultimate power tool in the inbound marketer\'s tool box. When used effectively, social media can create invaluable opportunities for your business. It allows people to discover your brand values, story, expertise, and customer service without requiring direct contact. It also offers the chance to engage in dialogue with followers and customers to easily address questions and concerns. It is an opportunity for you to learn about your market through informal market research and social monitoring. In this post, we will go over the nuts and bolts of optimizing your social media inbound marketing efforts.</p>

<h3><strong>Getting Started</strong></h3>

<p>Creating a profile on almost any social networking platform is free, and that is the basic starting point. Your business\' profile gives it a presence, and an avenue for sharing relevant content, such as industry news, video content, photos, infographics, and links to articles and blogs. It is <a href="http://www.meiermarketing.com/how-much-does-inbound-marketing-cost/">suggested</a> that the minimum time investment required for a small business to maintain social media presence is 2 hours per day, which equates to approximately $3,000 per month if outsourced. As you create profiles, it is important to keep the exact name of the business and graphics consistent across platforms, so that it is easily recognizable. Be careful not to over-commit to more social media than you have the resources to keep up-to-date. So, which social media networks should you utilize?</p>

<ul>
  <li><strong>LinkedIn </strong>builds networks between businesses and professionals&nbsp;and is a must for small businesses and start-ups.LinkedIn enables you to participate in industry-based discussions, stay connected with potential partners, customers, and employees, and publicize updates about your company. It is also an opportunity to improve your SEO rankings with your LinkedIn profile.</li>
  <li><strong>Facebook, Twitter, </strong>and <strong>Google+</strong> have the broadest reach. With Facebook\'s <a href="http://www.statista.com/statistics/272014/global-social-networks-ranked-by-number-of-users/">1.55 billion</a> (!) active monthly users, it is almost as important to be on Facebook as it is to have a company website. All of these platforms offer high-visibility and opportunities for engagement with followers. This is where people are more likely to seek information, and where you can expand your exposure to followers and friends of followers through "Likes" and "Retweets".</li>
  <li><strong>Instagram, Pinterest, </strong>and <strong>Tumblr</strong> are also popular, but consider whether your product or service is a good match for each platform. All of these require plenty of visually interesting content. They are useful for storytelling, sharing brand personality, and posting tutorials or other video content.</li>
  <li><strong>Niche social networks</strong> exist for practically every industry, and having a company profile on these networks is the perfect way to reach a passionate, like-minded audience.&nbsp; Niche networks should be used to engage with the community, expose your brand, learn from members, and establish yourself as an expert in your field. Sales pitches and advertisements should be minimal.&nbsp; A few examples include <a href="http://www.curbly.com">Curbly</a> for DIY enthusiasts, <a href="https://dribbble.com/">Dribbble</a> for "show and tell" among graphic designers, and <a href="https://www.patientslikeme.com/">PatientsLikeMe</a> for connecting people with similar health issues. To find niche networks that capture your target audience, explore this <a href="http://www.geniusstartup.com/social-media-sites-for-marketing/">list</a>.</li>
</ul>

<h3>Researching and Social Monitoring</h3>

<p>Social media networks give inbound marketers several ways to better understand their target market, thus making it easier to develop and share content that is well-received. Watch for common topics among followers. What are the frequently mentioned compliments and complaints? These trends can be researched through general social media discussions, customer reviews on Facebook, Yelp, or retail sites.A Google hashtag search will show you how often a tagged topic is being posted on Twitter, Instagram, and other platforms, and give you a window into people\'s honest thoughts and opinions. Or, you can utilize a <a href="http://blog.talkwalker.com/en/6-free-hashtag-tracking-tools/">hashtag tracking tool</a>. Discussions on Quora and Reddit can also provide insight into what kind of content users are sharing and discussing. You can also simply post a poll querying what followers are interested in. Delivering original inbound marketing content on trending topics differentiates your business from your competitors, establishes you as an expert, and engages target markets.</p>

<h3>Engaging</h3>

<p>Where most marketing tools are one-sided, social media is an opportunity for two-way conversations. Engaging on a personal level by responding to questions and comments can begin to build trusting relationships with potential leads. And where these conversations are visible to others, there is potential to display your stellar customer service, values, and expertise. (Keep in mind that this visibility can work against you if your social media team is not promptly and thoughtfully addressing customer concerns).</p>

<p>Engaging on a broader level on social media can be done by balancing your more focused content with less formal or tangential posts that engage followers. Sharing a photo of a candid moment in the office, or congratulating an employee on fundraising for a charity, for example, personalizes your business. It helps people realize that there are real people behind your company profile, not just regularly scheduled marketing propaganda.</p>

<p>We have covered the basics of how social media networks can bolster inbound marketing efforts. There are hundreds of more specific social media strategies that can be implemented. What has worked for your company?</p>

',
        ),
      ),
    ),
    'cid' => 0,
    'comment' => 1,
    'comment_count' => 0,
    'ds_switch' => '',
    'entity_type' => 'node',
    'field_categories' => array(
      'und' => array(
        0 => array(
          'tid' => '541c1363-2542-4879-a0b9-35fc917ede06',
        ),
        1 => array(
          'tid' => '40a8b548-e564-4149-ac97-34d7c97f5b04',
        ),
      ),
    ),
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '61e02ec8-f7b6-4e46-bc09-5467e5b727ca',
        ),
        1 => array(
          'tid' => '7b0611d9-fe51-4f6d-b061-533a408d9989',
        ),
      ),
    ),
    'field_energy_level' => array(
      'und' => array(
        0 => array(
          'radioactivity_energy' => 2000,
          'radioactivity_timestamp' => 1401118858,
        ),
      ),
    ),
    'field_image' => array(
      'und' => array(
        0 => array(
          'alt' => 'Social media ROI with Analytics screenshot',
          'entity_type' => 'file',
          'fid' => '88f9a2ad-fbf7-4175-9b5a-a1b371c34d38',
          'field_file_image_alt_text' => array(),
          'field_file_image_title_text' => array(),
          'filemime' => 'image/png',
          'filename' => 'social_media_roi.png',
          'filesize' => 105800,
          'height' => 450,
          'metadata' => array(
            'height' => 450,
            'width' => 900,
          ),
          'metatags' => array(),
          'slug' => '',
          'status' => 1,
          'title' => '',
          'type' => 'image',
          'uid' => 1,
          'uri' => 'public://content/blog/images/social_media_roi.png',
          'uuid' => '88f9a2ad-fbf7-4175-9b5a-a1b371c34d38',
          'width' => 900,
        ),
      ),
    ),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 1,
    'slug' => 'social_media_roi_how_to_improve_it',
    'status' => 1,
    'sticky' => 0,
    'title' => 'Social Media ROI & How to Improve It',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_blog',
    'uid' => 'a82a08fb-d9ee-4939-afbd-bbe20bf0917e',
    'url_alias' => array(
      0 => array(
        'alias' => 'blog/kayla-wren/social-media-roi-how-improve-it',
        'language' => 'und',
      ),
    ),
    'uuid' => '7f7991ee-8cf4-4a80-b379-fc2dc9241227',
  ); 
   
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/7d7aea4c-1b3c-4377-9613-f37ea43d04d4',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => '<p>Content is king. In our modern day, people are bombarded with blogs, videos, articles and photos every single time they turn their computer on. Essentially, people are being shouted at all day long, and so their natural inclination is to tune marketers out. You must EARN their attention. The thing that will allow your company to stand out among the clutter is the quality of content that you churn out. Create remarkable content to connect online with your buyers, and it will bring you back both tangible and intangible rewards.<br />
<br />
<strong>Here are some essential rules to embrace as you play the web content game:</strong></p>

<ol>
  <li>Embrace being a publisher.</li>
  <li>Be insightful and original. Know your brand voice and know your customers. The people who emerge as leaders in their respective fields are those who clearly know who they are and utilize a distinct voice to express their ideas and world views.</li>
  <li>Build momentum from content entry to content entry. Have a clear intention for why you have created every single piece of content. It should have a clear call-to-action (sign-up for newsletter, Like your Facebook page, fill out a webform, etc.) When possible, give yourself quantifiable goals to measure success.</li>
  <li>Communicate simply. (or as my mentor once said, "Keep it simple, stupid."</li>
  <li>Get creative with your content. The same information can be re-imagined and reused in multiple ways.</li>
  <li>Share or solve - Good content doesn’t try to sell. Your content should be honest and help your customers solve a problem or improve their lives.</li>
  <li>Show, don’t just tell - Good content shows, through case studies/client narratives/screenshots, how your product lives in and applies to the real world.</li>
  <li>Do something unexpected - Surprise can drive viral sharing and enhance your company’s reputation.</li>
  <li>Stoke the campfire - Good content sparks interaction. Commenting back and forth with your readers is a great way to keep the flame and their interest alive.</li>
  <li>Play to your strengths - A fundamental marketing tactic to bear in mind is that you can never be all things to all people. Apple does not try to cater to every computer/smartphone user. They know their user and they market to that audience specifically instead of trying to appease everyone out there. Likewise, as a content creator, you don’t have to create content on all different types of topics. Know your niche and do it well.>/li>
</ol>
<h3>Questions to ask yourself as you embark on the daunting task of creating killer content:</h3>
<ul>
  <li>Who are you? What is unique about your company and your viewpoint? Why should people pay attention to you?</li>
  <li>What are your audience’s biggest problems? What do they care about? What keeps them up at night? How can you help make their life a little better or a little easier?</li>
  <li>How can you become your audience\'s go-to resource and remain one step ahead of their needs?</li>
</ul>
<h3>Other important points to consider as you begin producing excellent content for your followers:</h3>
<ul>
  <li>Approach your marketing initiatives like you would a novel - tell a story.</li>
  <li>Use ordinary language so as not to alienate or confuse readers that are not intimately familiar with your business sector.</li>
  <li>The web has changed the rules. The consumer is now more educated than ever before, so you cannot lie in your marketing messages because they will call bluff in two seconds flat.</li>
  <li>With the web, EVERYONE is a publisher. Everyone is the media. There is almost no barrier to publishing content on the web now.</li>
  <li>With social media, you can get your messages out there without having to harass your customers with direct mail or telemarketing (side note: I am shocked that companies still waste money on telemarketing when they can advertise to a more targeted audience through pay-per-click!) Produce great content and your customers will come to you and advocate for you on their own.</li>
  <li>There has been a major shift in how companies are marketing themselves online. There have been countless documented cases of CMO’s/celebrities/high-stature individuals communicating directly with their audiences via social media.</li>
  <li>The type of content you put out should be strategic and thoughtful. Create and share relevant, valuable information that attracts people to you while simultaneously building your credibility as an authority in a particular subject area. Pay special attention to factors that are crucial to building an online following: the needs and preferences of your audience, your goals, your company’s expertise and brand, and of course, your available time, talent and budget.</li>
  <li>Always keep in mind the end goal when you are creating content. Is your end goal to gain notoriety, to convert visitors into buyers, or to convert buyers into brand champions?</li>
  <li>Deepen your relationship with your followers over time by repeatedly and consistently creating content they care about and will want to share freely with their friends or colleagues, and by encouraging them to engage with you through social media, newsletters, etc. As Joe Pulizzi put it, “Frequent and regular contact builds a relationship.”</li>
  <li>Search engines love people that produce content, especially keywod-rich Youtube videos, blog posts, articles and so on.</li>
  <li>Think about the content you create as an extension of your brand. Engaging with people is how your company will survive and thrive in this newly social world.</li>
  <li>The benefits of putting out great content on the web compound due to the ease with which people can share.</li>
  <li>Position yourself as a go-to, reliable source of information. In the game of content, the person with the abundance mentality will ultimately win.</li>
  <li>Traditional magazine and newspaper advertising models are becoming extinct. As the success of DVR and Netflix has shown us, consumers will even PAY to avoid advertisements. Investing in producing high-quality online content is not only effective, it’s becoming imperative. It’s time to <a href="http://www.nytimes.com/2011/12/05/business/media/at-time-inc-a-leader-to-help-it-fit-the-new-digital-order.html?_r=1&amp;nl=todaysheadlines&amp;emc=tha210">embrace a new order.</a></li>
  <li>Your window to engage someone is less than 10 seconds, so put your most intriguing content front and center.</li>
  <li>When in doubt about what types of content to create, survey your visitors to see what they\'d like to see.</li>
  <li>"Words matter. Write differently."</li>
  <li>Don\'t write "corporately." Have sass, pizzazz, personality! Write like you talk, and show your customers that there is a real person behind that content!</li>
<ul>


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
    'disqus' => array(
      'domain' => 'oeprodemo',
      'status' => TRUE,
      'url' => 'http://oepro3p.localhost:8082/blog/kayla-wren/6-key-metrics-better-content',
      'title' => '6 Key Metrics for Better Content',
      'identifier' => 'node/32',
      'developer' => 1,
    ),
    'ds_switch' => '',
    'entity_type' => 'node',
    'field_categories' => array(
      'und' => array(
        0 => array(
          'tid' => '27fd15ef-c256-4c59-87f1-311f1636233f',
        ),
        1 => array(
          'tid' => '541c1363-2542-4879-a0b9-35fc917ede06',
        ),
      ),
    ),
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => 'e862c908-d04d-4889-854c-30d1f98fee60',
        ),
        1 => array(
          'tid' => 'c2560836-0a54-4631-9dcf-a495ced24d4a',
        ),
      ),
    ),
    'field_energy_level' => array(
      'und' => array(
        0 => array(
          'radioactivity_energy' => 2000,
          'radioactivity_timestamp' => 1401118441,
        ),
      ),
    ),
    'field_image' => array(
      'und' => array(
        0 => array(
          'alt' => '',
          'entity_type' => 'file',
          'fid' => 'b7f2a380-051b-4f5d-a781-5087d61aba3c',
          'field_file_image_alt_text' => array(),
          'field_file_image_title_text' => array(),
          'filemime' => 'image/png',
          'filename' => 'content_analytics.png',
          'filesize' => 104806,
          'height' => 450,
          'metadata' => array(
            'height' => 450,
            'width' => 900,
          ),
          'metatags' => array(),
          'slug' => '',
          'status' => 1,
          'title' => '',
          'type' => 'image',
          'uid' => 1,
          'uri' => 'public://content/blog/images/content_analytics.png',
          'uuid' => 'b7f2a380-051b-4f5d-a781-5087d61aba3c',
          'width' => 900,
        ),
      ),
    ),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 1,
    'slug' => 'create_better_content_through_analytics',
    'status' => 1,
    'sticky' => 0,
    'title' => '6 Key Metrics for Better Content',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_blog',
    'uid' => 'a82a08fb-d9ee-4939-afbd-bbe20bf0917e',
    'url_alias' => array(
      0 => array(
        'alias' => 'blog/kayla-wren/6-key-metrics-better-content',
        'language' => 'und',
      ),
    ),
    'uuid' => '7d7aea4c-1b3c-4377-9613-f37ea43d04d4',
  );  
  
  $entities['enterprise_blog_content'][] = (object) array(
    '__metadata' => array(
      'type' => 'node',
      'uri' => 'node/8caf3e4b-71ed-4fbe-b2a6-f0ddaf733c10',
      'cause' => FALSE,
    ),
    'body' => array(
      'und' => array(
        0 => array(
          'format' => 'full_html',
          'summary' => '',
          'value' => '<p>Donec tincidunt lorem ligula. Nulla commodo nisi venenatis, congue diam at, bibendum sem. Vestibulum porttitor at felis eu eleifend. Nullam in tristique elit, eget tincidunt purus. Cras blandit justo mi, tempus interdum mauris consectetur at. Maecenas velit diam, rutrum vel leo et, condimentum adipiscing dolor. Ut vitae erat ac ante iaculis tempor ut in lorem. Vestibulum vel ipsum vel elit luctus adipiscing.</p>

<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer tincidunt arcu sed justo iaculis, in eleifend massa molestie. Integer viverra, ligula ut vehicula egestas, nunc ipsum accumsan tellus, sit amet iaculis lacus augue ultricies ipsum. Quisque elementum tellus blandit mauris ullamcorper, eu tristique tortor pulvinar. Duis eu enim non libero luctus rutrum a a sem. Donec enim lacus, adipiscing non est a, hendrerit tristique leo. Proin condimentum sem lectus, et iaculis lorem rutrum eleifend. Phasellus arcu nunc, blandit sit amet pellentesque at, sodales ut magna. Maecenas dapibus nulla augue, quis lacinia magna commodo nec. Nullam vitae posuere felis.</p>
',
        ),
      ),
    ),
    'cid' => 0,
    'comment' => 1,
    'comment_count' => 0,
    'ds_switch' => '',
    'entity_type' => 'node',
    'field_categories' => array(
      'und' => array(
        0 => array(
          'tid' => 'bbe30aac-25a0-4b79-bcdf-4ae28e798ecd',
        ),
        1 => array(
          'tid' => 'b9d25f5f-72f6-4224-980e-7798f8a61754',
        ),
      ),
    ),
    'field_tags' => array(
      'und' => array(
        0 => array(
          'tid' => '2d4f0dbe-f20c-42ca-bd14-fc2b8f6faf0d',
        ),
        1 => array(
          'tid' => '2cda5d3c-f2bd-4ccf-88d4-0503e068c857',
        ),
      ),
    ),
    'field_energy_level' => array(
      'und' => array(
        0 => array(
          'radioactivity_energy' => 2000,
          'radioactivity_timestamp' => 1401118650,
        ),
      ),
    ),
    'field_image' => array(
      'und' => array(
        0 => array(
          'alt' => 'Drupal admin screenshot',
          'entity_type' => 'file',
          'fid' => '6f02a52d-868d-4c8a-a861-85a5c120d978',
          'field_file_image_alt_text' => array(),
          'field_file_image_title_text' => array(),
          'filemime' => 'image/png',
          'filename' => 'drupal_admin_usability.png',
          'filesize' => 145916,
          'height' => 450,
          'metadata' => array(
            'height' => 450,
            'width' => 900,
          ),
          'metatags' => array(),
          'slug' => '',
          'status' => 1,
          'title' => '',
          'type' => 'image',
          'uid' => 1,
          'uri' => 'public://content/blog/images/drupal_admin_usability.png',
          'uuid' => '6f02a52d-868d-4c8a-a861-85a5c120d978',
          'width' => 900,
        ),
      ),
    ),
    'language' => 'und',
    'last_comment_name' => NULL,
    'last_comment_uid' => 1,
    'log' => '',
    'metatags' => array(),
    'promote' => 1,
    'slug' => '7_modules_to_make_your_drupal_site_more_usable',
    'status' => 1,
    'sticky' => 0,
    'title' => '7 Modules To Make Your Drupal Site More Usable',
    'tnid' => 0,
    'translate' => 0,
    'type' => 'enterprise_blog',
    'uid' => '1ddb8c80-48e7-4268-a57f-dce9e4b69a9e',
    'url_alias' => array(
      0 => array(
        'alias' => 'blog/ian-whitcomb/7-modules-make-your-drupal-site-more-usable',
        'language' => 'und',
      ),
    ),
    'uuid' => '8caf3e4b-71ed-4fbe-b2a6-f0ddaf733c10',
  );

  return $entities;
}
