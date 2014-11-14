<?php if (!empty($page['sidebar_second'])): ?>
	<!-- Sidebar second -->
	<aside class="sidebar sidebar-second <?php print $sidebar_column_class; ?>" role="complementary">
		<?php print render($page['sidebar_second']); ?>
	</aside>
<?php endif; ?>