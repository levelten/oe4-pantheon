<?php
/**
 * @file
 * Default output for a Blueimp object.
*/
?>

<?php print theme('blueimp_gallery', array('items' => $items, 'settings' => $settings)); ?>
<!-- Blueimp Gallery Widget -->
<div <?php print drupal_attributes($settings['attributes'])?>>
	<?php print $settings['widget']; ?>
</div>