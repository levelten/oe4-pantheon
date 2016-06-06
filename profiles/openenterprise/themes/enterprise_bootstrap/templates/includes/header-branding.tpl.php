<?php if ($logo): ?>
  <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
    <img class="img-responsive" src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
  </a>
<?php endif; ?>

<?php if (!empty($site_name)): ?>
  <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
<?php endif; ?>
