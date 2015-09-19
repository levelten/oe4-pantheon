<?php
/**
 * Template for pictaculous demo content.
 */
?>
<?php if (!empty($colors)): ?>
	<div class="color-palette">
		<?php foreach ($colors as $color): ?>
		<div class="color-index" style="background-color:#<?php print $color; ?>"></div>
		<?php endforeach; ?>
	</div>
<?php endif; ?>
