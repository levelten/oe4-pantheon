<?php if ($is_front): ?>
	<?php if (!$full_width_front): ?>
		<?php if (!empty($page['highlighted'])): ?>
			<div class="highlighted jumbotron">
				<?php print render($page['highlighted']); ?>
			</div>
		<?php endif; ?>
	<?php elseif ($highlighted_container_front): ?>
		<?php if (!empty($page['highlighted'])): ?>
			<div class="highlighted jumbotron">
				<div class="container">
					<?php print render($page['highlighted']); ?>
				</div>
			</div>
		<?php endif; ?>
	<?php else: ?>
		<?php if (!empty($page['highlighted'])): ?>
			<div class="highlighted container">
				<div class="jumbotron">
					<div class="highlighted-row row">
						<?php print render($page['highlighted']); ?>
					</div>
				</div>
			</div>
		<?php endif; ?>
	<?php endif; ?>
<?php elseif(!$highlighted_placement): ?>
	<?php if ($highlighted_container): ?>
		<?php if (!empty($page['highlighted'])): ?>
			<div class="highlighted jumbotron">
				<div class="container">
					<?php print render($page['highlighted']); ?>
				</div>
			</div>
		<?php endif; ?>
	<?php else: ?>
		<?php if (!empty($page['highlighted'])): ?>
			<div class="highlighted container">
				<div class="jumbotron <?php print $highlighted_row; ?>">
					<?php print render($page['highlighted']); ?>
				</div>
			</div>
		<?php endif; ?>
	<?php endif; ?>
<?php else: ?>
	<?php if (!empty($page['highlighted'])): ?>
		<div class="highlighted jumbotron">
			<?php print render($page['highlighted']); ?>
		</div>
	<?php endif; ?>
<?php endif; ?>