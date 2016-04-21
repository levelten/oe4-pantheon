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
<div class="card <?php if ($classes): ?><?php print $classes ?> clearfix"<?php endif; ?>>
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php if ($header): ?>
    <?php if (!empty($header_classes)): ?>
      <div class="card-header <?php print $header_classes; ?>">
    <?php endif; ?>

      <?php print $header; ?>

    <?php if (!empty($header_classes)): ?>
      </div>
    <?php endif; ?>
  <?php endif; ?>

  <?php if ($middle): ?>
    <?php if (!empty($middle_classes)): ?>
      <div class="<?php print $middle_classes; ?>">
    <?php endif; ?>

      <?php print $middle; ?>

    <?php if (!empty($middle_classes)): ?>
      </div>
    <?php endif; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <?php if (!empty($footer_classes)): ?>
      <div class="card-footer <?php print $footer_classes; ?>">
    <?php endif; ?>

      <?php print $footer; ?>

    <?php if (!empty($footer_classes)): ?>
      </div>
    <?php endif; ?>

  <?php endif; ?>
</div>
