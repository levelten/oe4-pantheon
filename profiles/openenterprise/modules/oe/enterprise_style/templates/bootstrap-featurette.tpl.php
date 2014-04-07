<?php

/**
 * @file
 * Default theme implementation to present a picture configured for the
 * user's account.
 *
 * Available variables:
 * - $user_picture: Image set by the user or the site's default. Will be linked
 *   depending on the viewer's permission to view the user's profile page.
 * - $account: Array of account information. Potentially unsafe. Be sure to
 *   check_plain() before use.
 *
 * @see template_preprocess_user_picture()
 *
 * @ingroup themeable
 */
?>
<div class="row featurette">
  <?php if ($image): ?>
    <div class="<?php print $image_wrapper_classes; ?>">
      <?php print theme_image($image); ?>
    </div>
  <?php endif; ?>
  <div class="<?php print $message_wrapper_classes; ?>">
    <?php if ($header): ?>
      <h2 class="<?php print $header_classes;?>"><?php print $header; ?></h2>
    <?php endif; ?>
    <?php if ($body): ?>
      <p class="lead"><?php print $body; ?></p>
    <?php endif; ?>
    <?php if (isset($link['text'])): ?>
        <p><?php print l($link['text'], $link['path'], $link['options']); ?></p>
    <?php endif; ?>
  </div>
</div>


