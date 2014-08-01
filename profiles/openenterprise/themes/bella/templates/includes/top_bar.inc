<?php if (!empty($page['header']) || !empty($site_slogan)): ?>
	<header role="banner" id="page-header">
		<?php if (!empty($site_slogan)): ?>
		<p class="lead"><?php print $site_slogan; ?></p>
		<?php endif; ?>
		<?php print render($page['header']); ?>
	</header> <!-- /#page-header -->
<?php endif; ?>