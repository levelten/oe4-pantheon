<?php if($is_front): ?>
	<!-- Title -->
	<?php if (!empty($title_prefix) || !empty($title) || !empty($title_suffix)): ?>
		<div class="page-title <?php print $title_class; ?> container">
			<div class="page-title-container row">
				<div class="page-title-inner">
					<?php print render($title_prefix); ?>
					<?php if (!empty($title)): ?>
						<h1 class="page-header"><?php print $title; ?></h1>
					<?php endif; ?>
					<?php print render($title_suffix); ?>
				</div>
			</div>
		</div>
	<?php endif; ?>
<?php else: ?>
	<!-- Title -->
	<?php if(!$title_placement): ?>
		<?php if (!empty($title_prefix) || !empty($title) || !empty($title_suffix)): ?>
			<div class="page-title <?php print $title_class; ?>">
				<div class="page-title-container container">
					<div class="page-title-inner">
						<?php print render($title_prefix); ?>
						<?php if (!empty($title)): ?>
							<h1 class="page-header"><?php print $title; ?></h1>
						<?php endif; ?>
						<?php print render($title_suffix); ?>
					</div>
				</div>
			</div>
		<?php endif; ?>
	<?php else: ?>
		<?php if (!empty($title)): ?>
			<div class="page-title <?php print $title_class; ?>">
				<div class="page-title-container">
					<div class="page-title-inner <?php print $title_row; ?>">
						<?php print render($title_prefix); ?>
						<?php if (!empty($title)): ?>
							<h1 class="page-header"><?php print $title; ?></h1>
						<?php endif; ?>
						<?php print render($title_suffix); ?>
					</div>
				</div>
			</div>
		<?php endif; ?>
	<?php endif; ?>
<?php endif; ?>