<?php include 'header_top.inc'; ?>
<?php include 'brand_bar.inc'; ?>
<!-- Navigation Bootstrap region -->
  <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
  <div id="navbar-wrapper">
    <header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
      <div class="container">
        <div class="navbar-region <?php print $navbar_region_class; ?>">
          <!-- Navbar Header (Logo) Region -->
          <?php if (!empty($navbar_header_display)): ?>
            <div id="navbar-logo" <?php print drupal_attributes($nav_logo_class); ?>>
              <?php include 'header-branding.tpl.php'; ?>

              <?php include 'navbar-toggle.tpl.php'; ?>
            </div>
          <?php endif; ?>
          <!-- Navbar Menu Region -->
          <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
            <div id="navbar-menu" <?php print drupal_attributes($nav_menu_class); ?>>
              <div class="container-fluid">
                <nav class="navbar-menu navbar-collapse collapse" role="navigation">
                  <?php if (!empty($primary_nav)): ?>
                    <?php print render($primary_nav); ?>
                  <?php endif; ?>
                  <?php if (!empty($secondary_nav)): ?>
                    <?php print render($secondary_nav); ?>
                  <?php endif; ?>
                  <?php if (!empty($page['navigation'])): ?>
                    <?php print render($page['navigation']); ?>
                  <?php endif; ?>
                </nav>
              </div>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </header>
  </div>
  <?php endif; ?>
<?php include 'header_bottom.inc'; ?>