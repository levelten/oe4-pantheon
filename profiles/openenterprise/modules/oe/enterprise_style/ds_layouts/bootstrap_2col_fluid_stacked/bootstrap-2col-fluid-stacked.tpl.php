<?php
/**
 * @file
 * Display Suite Bootstrap 2 column with hero template.
 *
 * Available variables:
 *
 * Layout:
 * - $classes: String of classes that can be used to style this layout.
 * - $contextual_links: Renderable array of contextual links.
 *
 * Regions:
 *
 * - $header: Rendered content for the "header" region.
 * - $header_classes: String of classes that can be used to style the "header" region.
 *
 * - $left: Rendered content for the "left" region.
 * - $left_classes: String of classes that can be used to style the "left" region.
 *
 * - $right: Rendered content for the "right" region.
 * - $right_classes: String of classes that can be used to style the "right" region.
 *
 * - $footer: Rendered content for the "footer" region.
 * - $footer_classes: String of classes that can be used to style the "footer" region.
 */

// Set default span classes for columns, if not already set.
if ($left) {
  enterprise_style_ds_span_columns($left_classes, 2);
}
if ($right) {
  enterprise_style_ds_span_columns($right_classes, 2);
}
?>
<article <?php if ($classes): ?>class="<?php print $classes ?> clearfix"<?php endif; ?>>
  <div class="content">
    <?php if (isset($title_suffix['contextual_links'])): ?>
      <?php print render($title_suffix['contextual_links']); ?>
    <?php endif; ?>

    <?php if ($header): ?>
      <header class="ds-header clearfix <?php print $header_classes; ?>">
        <?php print $header; ?>
      </header>
    <?php endif; ?>

    <?php if ($left || $right): ?>
    <div>
      <?php if ($left): ?>
        <?php if (!$right) { enterprise_style_ds_span_column_replace($left_classes, 1); } ?>
        <section class="ds-left clearfix <?php print $left_classes; ?>">
          <?php print $left; ?>
        </section>
      <?php endif;?>
      <?php if ($right): ?>
        <?php if (!$left) { enterprise_style_ds_span_column_replace($right_classes, 1); } ?>
        <section class="ds-right clearfix <?php print $right_classes; ?>">
          <?php print $right; ?>
        </section>
      <?php endif; ?>
    </div>
    <?php endif; ?>

    <?php if ($footer): ?>
      <footer class="ds-footer<?php print $footer_classes; ?>">
        <?php print $footer; ?>
      </footer>
    <?php endif; ?>
  </div>
</article>
