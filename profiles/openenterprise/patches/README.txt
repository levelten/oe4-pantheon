This document describes the patches used in Open Enterprise.

Each patch used in the profile should be placed under profiles/openenterprise/patches.

They can be applied manually by coping each patch to the location listed in their descrption or using Drush make.


----* Patch is current: 7/2/15 *----
PATCH: Allow-meta-support-in-CKeditor-4.3.1.patch
LIBRARY: ckeditor
Enables meta tag schema markup support in 4.3.1 version of CKeditor. Note that this is fixed
in current version of CKeditor.


----* Patch is current: 7/2/15 *----
PATCH: deploy-managed-ui-file-support-2054397-2_0.patch
MODULE: deploy
REF: https://www.drupal.org/node/2054397
copy to: /profiles/openenterprise/modules/contrib/deploy

Adds checkbox to export a file via deploy/uuid


----* Patch is current: 7/2/15 *----
PATCH: strongarm-2076543-import-export-value-alter-hooks.patch
MODULE: strongarm
copy to: /profiles/openenterprise/modules/contrib/strongarm
Note: some methods of executing the patch may put the strongarm.api.php file in the repo root.
If this happens, copy it back to the strongarm module directory.

If patch fails due to expected dev/null on line 16, change the line returns to Unix style "LF"

Adds alter hooks to strongarm variables on import and export.


----* Patch is current: 7/2/15 *----
PATCH: token-current_page_object_token-919760-9.patch
MODULE: token
REF: drupal.org/node/919760
copy to: /profiles/openenterprise/modules/contrib/token

Enables token pattern to get node from current page [current-page:node:nid]. Used in brand network disto.


----* Patch is current: 7/2/15 *----
PATCH: uuid-add-features-import-alter-hook-2406051.patch
MODULE: uuid
copy to: /profiles/openenterprise/modules/contrib/uuid

Adds a hook to alter uuid entities (content) when the content is imported.
This is used to reverse alterations done using hook_uuid_entities_features_export_entity.
Used with webform blocks to add uuid to block id on export then replace uuid with nid on import.

----* Patch is current: 7/2/15 *----
PATCH: drupal-render-invalid-elements-array-fix.patch
CORE FILE: includes/common.inc
NOTES: Fixes the following Drupal core PHP warnings:
- Warning: Cannot use a scalar value as an array in drupal_render() (line 6110 of /home/dwyer/mra/public_html/includes/common.inc).
- Warning: Illegal string offset '#printed' in drupal_render() (line 6110 of /home/dwyer/mre/public_html/includes/common.inc).
- Warning: Illegal string offset '#children' in drupal_render() (line 6103 of /home/dwyer/mre/public_html/includes/common.inc).

----* Patch is current: 7/2/15 *----
PATCH: drupal-Casting-null-array-1711256-7.patch
CORE FILE: includes/common.inc
NOTES: Fixes the following Drupal core PHP warning:
- Warning: Invalid argument supplied for foreach() in element_children() (line 6590 of includes/common.inc).

----* Patch is current: 7/28/15 *----
PATCH: 2364343-20.robots.txt.patch
CORE FILE: robots.txt
REF: https://www.drupal.org/node/2476547
NOTES: Enables bots to access CSS and JS files to properly render pages.
