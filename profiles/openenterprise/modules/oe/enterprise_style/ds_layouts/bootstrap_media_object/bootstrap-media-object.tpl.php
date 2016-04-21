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
<div class="media <?php if ($classes): ?><?php print $classes ?> clearfix"<?php endif; ?>>
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php if ($media_left): ?>
      <div class="media-left <?php print $media_left_classes; ?>">
        <?php print $media_left; ?>
      </div>
  <?php endif; ?>

  <?php if ($media_body): ?>
      <div class="media-body <?php print $media_body_classes; ?>">
        <?php print $media_body; ?>
      </div>
  <?php endif; ?>

  <?php if ($media_right): ?>
      <div class="media-right <?php print $media_right_classes; ?>">
        <?php print $media_right; ?>
      </div>
  <?php endif; ?>
</div>
