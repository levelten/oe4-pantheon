<?php if (!empty($page['sidebar_first'])): ?>
	<!-- Sidebar First -->
	<aside class="sidebar sidebar-first <?php print $sidebar_column_class; ?>" role="complementary">
		<?php print render($page['sidebar_first']); ?>
	</aside>
<?php endif; ?>