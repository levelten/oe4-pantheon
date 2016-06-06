<!-- #footer-sticky -->
<?php if (!empty($page['footer_sticky'])): ?>
  <div class="footer-sticky navbar-default navbar-fixed-bottom <?php //print $footer_sticky_class; ?>">
      <div class="container">
        <?php print render($page['footer_sticky']); ?>
      </div>
  </div>
<?php endif; ?>
