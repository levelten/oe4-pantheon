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
 * - $middle: Rendered content for the "right" region.
 * - $middle_classes: String of classes that can be used to style the "right" region.
 *
 * - $footer: Rendered content for the "footer" region.
 * - $footer_classes: String of classes that can be used to style the "footer" region.
 */
?>
<article <?php if ($classes): ?>class="<?php print $classes ?> clearfix"<?php endif; ?>>
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php if ($header || $sticky): ?>
    <header class="ds-header clearfix <?php print $header_classes; ?>">
      <?php print $header; ?>
      <?php if ($sticky): ?>
        <div class="ds-sticky<?php print $sticky_classes; ?>">
          <?php print $sticky; ?>
        </div>
      <?php endif; ?>
    </header>
  <?php endif; ?>
  
  <?php if ($middle): ?>
    <section class="ds-middle clearfix <?php print $middle_classes; ?>">
      <?php print $middle; ?>
    </section>
  <?php endif; ?>

  <?php if ($footer): ?>
    <footer class="ds-footer clearfix <?php print $footer_classes; ?>">
      <?php print $footer; ?>
    </footer>
  <?php endif; ?>
</article>
