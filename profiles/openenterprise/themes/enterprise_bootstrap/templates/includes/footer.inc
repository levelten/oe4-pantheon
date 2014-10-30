<?php if ($footer_container): ?>
  <footer class="footer <?php print $footer_class; ?>">
    <?php if (!empty($page['footer'])): ?>
      <div class="footer-top">
          <div class="container">
            <?php print render($page['footer']); ?>
          </div>
        </div>
    <?php endif; ?>
    <?php if (!empty($page['footer_bottom'])): ?>
      <div class="footer-bottom">
        <div class="container">
          <?php print render($page['footer_bottom']); ?>
        </div>
      </div>
    <?php endif; ?>
  </footer>
<?php else: ?>
  <footer class="footer container <?php print $footer_class; ?>">
    <?php if (!empty($page['footer'])): ?>
      <div class="footer-top">
          <div class="container">
            <?php print render($page['footer']); ?>
          </div>
        </div>
    <?php endif; ?>
    <?php if (!empty($page['footer_bottom'])): ?>
      <div class="footer-bottom">
        <div class="container">
          <?php print render($page['footer_bottom']); ?>
        </div>
      </div>
    <?php endif; ?>
  </footer>
<?php endif; ?>