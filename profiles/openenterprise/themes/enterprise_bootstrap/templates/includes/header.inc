<!-- Top Bar (header) -->
<?php if($is_front): ?>
	<?php if(!$header_container_front): ?>
		<?php if (!empty($page['header']) || !empty($site_slogan)): ?>
			<header role="banner" id="page-header">
				<div class="container">
					<?php if (!empty($site_slogan)): ?>
						<p class="lead"><?php print $site_slogan; ?></p>
					<?php endif; ?>		
					<?php print render($page['header']); ?>
				</div>
			</header>
		<?php endif; ?>
	<?php else: ?>
		<?php if (!empty($page['header']) || !empty($site_slogan)): ?>
			<header role="banner" id="page-header">
				<?php if (!empty($site_slogan)): ?>
					<p class="lead"><?php print $site_slogan; ?></p>
				<?php endif; ?>		
				<?php print render($page['header']); ?>
			</header>
		<?php endif; ?>
	<?php endif; ?>
<?php else: ?>
	<?php if($header_container): ?>
		<?php if (!empty($page['header']) || !empty($site_slogan)): ?>
			<header role="banner" id="page-header">
				<div class="container">
					<?php if (!empty($site_slogan)): ?>
						<p class="lead"><?php print $site_slogan; ?></p>
					<?php endif; ?>		
					<?php print render($page['header']); ?>
				</div>
			</header>
		<?php endif; ?>
	<?php else: ?>
		<?php if (!empty($page['header']) || !empty($site_slogan)): ?>
			<div class="page-header-container">
				<header role="banner" id="page-header">
					<?php if (!empty($site_slogan)): ?>
						<p class="lead"><?php print $site_slogan; ?></p>
					<?php endif; ?>		
					<?php print render($page['header']); ?>
				</header>
			</div>
		<?php endif; ?>
	<?php endif; ?>
<?php endif; ?>