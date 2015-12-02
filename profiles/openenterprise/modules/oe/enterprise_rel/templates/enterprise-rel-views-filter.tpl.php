<?php

/**
 * @file
 * Default simple view template to display a list of summary lines.
 *
 * @ingroup views_templates
 */
?>
  <div class="views-filter<?php print !empty($list_classes) ? ' ' . $list_classes : ''; ?>">
  <?php foreach ($sets as $id => $row): ?>
    <div class="views-filter-set<?php print (!empty($list_item_classes) ? ' ' . $list_item_classes : '') . (!empty($row_list_item_classes[$id]) ? ' ' . $row_list_item_classes[$id] : ''); ?>">
      <h3><?php print $row->title?></h3>
      <?php if (!empty($row->markup)): ?>
        <?php print $row->markup?>
      <?php endif; ?>
    </div>
  <?php endforeach; ?>
  </div>