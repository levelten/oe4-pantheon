This document describes the patches used in Open Enterprise.

Each patch used in the profile should be placed under profiles/openenterprise/patches.

They can be applied manually by coping each patch to the location listed in their descrption
or using Drush make.

PATCH: deploy-managed-ui-file-support-2054397-2_0.patch
issue: https://www.drupal.org/node/2054397
copy to: /profiles/openenterprise/modules/contrib/deploy

Adds checkbox to export a file via deploy/uuid


PATCH: uuid-add-features-import-alter-hook-2406051.patch
copy to: /profiles/openenterprise/modules/contrib/uuid

Adds a hook to alter uuid entities (content) when the content is imported.
This is used to reverse alterations done using hook_uuid_entities_features_export_entity.
Used with webform blocks to add uuid to block id on export then replace uuid with nid on import.