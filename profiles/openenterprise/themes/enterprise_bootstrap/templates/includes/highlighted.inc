<!-- Highlighted -->
<?php $highlighted = element_children($page['highlighted']); ?>
<?php if ($is_front): ?>
	<?php if (!empty($highlighted)): ?>
		<div class="container">
			<div class="highlighted jumbotron">
				<?php print render($page['highlighted']); ?>
			</div>
		</div>
	<?php endif; ?>
<?php elseif (!$highlighted_placement): ?>
	<?php if (!$highlighted_container): ?>
		<?php if (!empty($highlighted)): ?>
			<div class="container">
				<div class="highlighted jumbotron">
					<?php print render($page['highlighted']); ?>
				</div>
			</div>
		<?php endif; ?>
	<?php else: ?>
		<?php if (!empty($highlighted)): ?>
				<div class="highlighted jumbotron">
					<?php print render($page['highlighted']); ?>
				</div>
		<?php endif; ?>
	<?php endif; ?>
<?php else: ?>
	<?php if (!empty($highlighted)): ?>
		<div class="highlighted jumbotron">
			<?php print render($page['highlighted']); ?>
		</div>
	<?php endif; ?>
<?php endif;