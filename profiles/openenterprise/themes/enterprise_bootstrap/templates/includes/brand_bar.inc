<!-- Brand Bar -->
<?php if (!empty($page['brand_bar'])): ?>
	<div class="brand-bar">
		<div class="container">
		  <?php print render($page['brand_bar']); ?>
		</div>
	</div>
<?php endif; ?>