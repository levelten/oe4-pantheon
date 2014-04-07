core = 7.x
api = 2

; drupal core latest release of specified core = number.x
;projects[core] = 7.x
projects[drupal][version] = 7.24

; Redirect to install.php when empty database
; http://drupal.org/node/728702
projects[drupal][patch][728702] = http://drupal.org/files/issues/install-redirect-on-empty-database-728702-36.patch

; Missing drupal_alter() for text formats and filters
; http://drupal.org/node/903730
projects[drupal][patch][903730] = http://drupal.org/files/issues/drupal.filter-alter.92.patch

; Fix object menu router conversion issue.
; http://drupal.org/node/972536
projects[drupal][patch][972536] = http://drupal.org/files/drupal-menu-int-972536-83-D7.patch

; Allow password flood to be reset
; http://drupal.org/node/992540
projects[drupal][patch][992540] = http://drupal.org/files/issues/992540-3-reset_flood_limit_on_password_reset-drush.patch

; drupal_add_js() is missing the 'browsers' option
; http://drupal.org/node/865536
projects[drupal][patch][865536] = http://drupal.org/files/drupal-865536-204.patch

; _menu_load_objects() is not always called when building menu trees
; http://drupal.org/node/1697570
projects[drupal][patch][1697570] = http://drupal.org/files/drupal-menu_always_load_objects-1697570-5.patch

; user_role_grant_permissions() throws PDOException when used for a disabled module's permission or with non-existent permissions
; http://drupal.org/node/737816
projects[drupal][patch][737816] = https://drupal.org/files/drupal-fix_pdoexception_grant_permissions-737816-36-do-not-test.patch

projects[openenterprise][type] = profile
projects[openenterprise][download][type] = git
projects[openenterprise][download][url] = http://git.drupal.org/project/openenterprise.git
projects[openenterprise][download][branch] = 7.x-3.x
