<?php include 'header_top.inc'; ?>
<?php include 'brand_bar.inc'; ?>
<!-- Navigation Bootstrap region -->
  <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
  <div id="navbar-wrapper">
    <?php print render($page['navigation']); ?>
  </div>
  <?php endif; ?>
<?php include 'header_bottom.inc'; ?>