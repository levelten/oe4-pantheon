<?php

/**
 * @file
 * Default simple view template to display a list of summary lines.
 *
 * @ingroup views_templates
 */
?>
<div class="item-list">
  <ul class="views-summary<?php print !empty($list_classes) ? ' ' . $list_classes : ''; ?>">
  <?php foreach ($rows as $id => $row): ?>
    <li class="<?php print (!empty($list_item_classes) ? ' ' . $list_item_classes : '') . (!empty($row_list_item_classes[$id]) ? ' ' . $row_list_item_classes[$id] : ''); ?>">
      <a href="<?php print $row->url; ?>"<?php print !empty($row_classes[$id]) ? ' class="'. $row_classes[$id] .'"' : ''; ?>>
        <?php if (!empty($options['count']) && !empty($row->count)): ?>
          <span class="badge<?php print !empty($row_badge_classes[$id]) ? ' ' . $row_badge_classes[$id] : ''; ?>"><?php print $row->count?></span>
        <?php endif; ?>
        <?php print $row->link; ?>
        <?php if (!empty($row->sub_items)): ?>
          <?php print $row->sub_items?>
        <?php endif; ?>
      </a>
    </li>
  <?php endforeach; ?>
  </ul>
</div>