<!-- Navigation Enterprise region -->
<div id="navbar-wrapper" class="<?php print $nav_wrapper; ?>">
  <header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
    <?php include 'header_top.inc'; ?>
    <div class="<?php print $nav_inner; ?>">
      <div class="navbar-region <?php print $navbar_region_class; ?>">
        <!-- Navbar Logo Region -->
        <div id="navbar-logo" <?php print drupal_attributes($nav_logo_class); ?>>
          <?php if ($logo): ?>
          <a class="logo navbar-btn pull-left navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
          </a>
          <?php endif; ?>

          <?php if (!empty($site_name)): ?>
          <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
          <?php endif; ?>

          <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
        </div>
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
    <?php include 'header_bottom.inc'; ?>
  </header>
</div>