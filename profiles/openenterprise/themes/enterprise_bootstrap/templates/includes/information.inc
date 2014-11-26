<?php $help = element_children($page['help']); ?>
<?php $tab_check = element_children($tabs); ?>
<?php if (!empty($messages) || !empty($tab_check) || !empty($help) || !empty($action_links)): ?>
	<?php if($is_front): ?>
		<!-- Information -->
		<div class="information <?php print $full_width_anti_container; ?>">
		  <?php print $messages; ?>
		  <?php if (!empty($tabs)): ?>
			  <?php print render($tabs); ?>
			<?php endif; ?>
			<?php if (!empty($page['help'])): ?>
			  <?php print render($page['help']); ?>
			<?php endif; ?>
			<?php if (!empty($action_links)): ?>
			  <ul class="action-links"><?php print render($action_links); ?></ul>
			<?php endif; ?>
		</div>
	<?php else: ?>
		<!-- Information -->
		<div class="information">
		  <?php print $messages; ?>
		  <?php if (!empty($tabs)): ?>
		  <?php print render($tabs); ?>
		<?php endif; ?>
		<?php if (!empty($page['help'])): ?>
		  <?php print render($page['help']); ?>
		<?php endif; ?>
		<?php if (!empty($action_links)): ?>
		  <ul class="action-links"><?php print render($action_links); ?></ul>
		<?php endif; ?>
	<?php endif; ?>
<?php endif; ?>