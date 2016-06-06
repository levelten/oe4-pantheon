<?php
/**
 * Template for palette suggestion from Pictaculous.
 */

// Set up vars.
$palette = get_object_vars($object);
$colors = implode(',', $palette['colors']);
$image_url = $palette['url'];
$title = $palette['title'];

?>

<div id="pictaculous-info" class="colourlovers-images">
	<div class="colourlovers-image" data-colors="<?php print $colors; ?>">
		<div class="pictaculous-info-image">
			<h3 class="color-title"><?php print $title; ?></h3>
			<img alt="Pictaculous palette from image" src="<?php print $image_url ?>">
		</div>
		<div class="pictaculous-info-palette">
			<?php print theme('pictaculous_color_palette', array('colors' => $palette['colors'])); ?>
		</div>
  </div>
</div>
