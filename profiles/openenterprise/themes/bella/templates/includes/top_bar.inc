<?php if (!empty($page['header']) || !empty($site_slogan)): ?>
	<header role="banner" id="page-header">
		<div class="container">
			<?php if (!empty($site_slogan)): ?>
			<p class="lead"><?php print $site_slogan; ?></p>
			<?php endif; ?>
			
			<?php print render($page['header']); ?>
		</div>
	</header> <!-- /#page-header -->
<?php endif; ?>