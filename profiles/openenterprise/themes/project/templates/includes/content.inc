<section class="main-container">
	
	<?php include 'information.inc'; ?>
	
	<!-- Main end -->
	<?php if (!$is_front): ?>
		<div class="container">
		<div class="row">
	<?php else: ?>
		<div class="main-container-inner">
	<?php endif; ?>
		
		<div class="main <?php if (!$is_front) { print $main_class; } ?>" >
			<!-- title -->
			<?php include 'title.inc'; ?>
			<a id="main-content"></a>
			
			<?php print render($page['content']); ?>
		</div>
		<!-- Main end -->

		<?php if (!$is_front): ?>
			<?php include 'sidebar_first.inc'; ?>
			<?php include 'sidebar_second.inc'; ?>
		<?php endif; ?>

	</div>
	<?php if (!$is_front): ?></div><?php endif; ?>
			
	<!-- back to top arrow -->
	<?php if ($back_to_top): ?>
		<div class="scrollToTop">
			<i class="icon glyphicon glyphicon-chevron-up"></i>
		</div>
	<?php endif; ?>
</section>