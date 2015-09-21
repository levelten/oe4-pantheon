<?php
/**
 * Template for Pictaculous palette suggestions from Adobe Kuler.
 */
?>

<div id="pictaculous-adobe-kuler" class="colourlovers-images">
	<?php foreach ($object as $palette): ?>
		<div class="colourlovers-image" data-colors="<?php print implode(',', $palette->colors); ?>">
			<h3 class="color-title"><?php print $palette->title; ?></h3>
			<?php print theme('pictaculous_color_palette', array('colors' => $palette->colors)); ?>
		</div>
	<?php endforeach; ?>
</div>
