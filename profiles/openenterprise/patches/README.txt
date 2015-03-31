This document describes the patches used in Open Enterprise.

Each patch used in the profile should be placed under profiles/openenterprise/patches.

They can be applied manually by coping each patch to the location listed in their descrption
or using Drush make.


PATCH: Allow-meta-support-in-CKeditor-4.3.1.patch
LIBRARY: ckeditor
Enables meta tag schema markup support in 4.3.1 version of CKeditor. Note that this is fixed
in current version of CKeditor.

PATCH: bean_uuid_fix_import_export.patch
MODULE: bean > bean_uuid
Fixes issue with breaking Deploy import/export b/c of missing bean entity info data.

PATCH: deploy-managed-ui-file-support-2054397-2_0.patch
MODULE: deploy
issue: https://www.drupal.org/node/2054397
copy to: /profiles/openenterprise/modules/contrib/deploy

Adds checkbox to export a file via deploy/uuid

PATCH: Fix-Too-Many-Tabs-Overlaping-Buttons.patch
MODULE: rubik
Issue in Rubik of too many tabs will obscure buttons. 

This fixes the styleing.

PATCH: strongarm-2076543-import-export-value-alter-hooks.patch
MODULE: strongarm
copy to: /profiles/openenterprise/modules/contrib/strongarm
Note: some methods of executing the patch may put the strongarm.api.php file in the repo root.
If this happens, copy it back to the strongarm module directory.

If patch fails due to expected dev/null on line 16, change the line returns to Unix style "LF"

Adds alter hooks to strongarm variables on import and export.


PATCH: uuid-add-features-import-alter-hook-2406051.patch
MODULE: UUID
copy to: /profiles/openenterprise/modules/contrib/uuid

Adds a hook to alter uuid entities (content) when the content is imported.
This is used to reverse alterations done using hook_uuid_entities_features_export_entity.
Used with webform blocks to add uuid to block id on export then replace uuid with nid on import.