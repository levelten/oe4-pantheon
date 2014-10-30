<?php if($is_front): ?>
<div class="information <?php print $full_width_anti_container; ?>">
  <?php print render($title_suffix); ?>
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
	<div class="information">
	  <?php print render($title_suffix); ?>
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