#!/bin/bash
# Run on oepro repo to convert to oece repo
# run from Drupal root directory

# remove pro themes
themes='bella enterprise_health project'
for theme in $themes
do
  rm -rf profiles/openenterprise/themes/$theme
  git ls-files -z profiles/openenterprise/themes/$theme/ | xargs -0 git update-index --assume-unchanged
done

#remove pro libraries
libs='enterprise_editor'
for lib in $libs
do
  rm -rf profiles/openenterprise/libraries/$lib
  git ls-files -z profiles/openenterprise/libraries/$lib/ | xargs -0 git update-index --assume-unchanged
done

#remote apps
apps="enterprise_client"
apps+=" enterprise_events"
apps+=" enterprise_faq"
apps+=" enterprise_image"
apps+=" enterprise_link"
apps+=" enterprise_location"
apps+=" enterprise_premiumoffer"
apps+=" enterprise_press"
apps+=" enterprise_testimonial"
apps+=" enterprise_video"
apps+=" enterprise_work"
for app in $apps
do
  # remove base app module
  rm -rf profiles/openenterprise/modules/oe/$app
  git ls-files -z profiles/openenterprise/modules/oe/$app/ | xargs -0 git update-index --assume-unchanged
  # remove config module
  rm -rf profiles/openenterprise/modules/oe_config/${app}_config
  git ls-files -z profiles/openenterprise/modules/oe_config/${app}_config/ | xargs -0 git update-index --assume-unchanged
  # remove content module
  rm -rf profiles/openenterprise/modules/oe_content/${app}_content
  git ls-files -z profiles/openenterprise/modules/oe_content/${app}_content/ | xargs -0 git update-index --assume-unchanged
done

#remove pro apps
modules='oe_ext'
modules+=' enterprise_work_pre'
for module in $modules
do
  rm -rf profiles/openenterprise/modules/$module
  git ls-files -z profiles/openenterprise/modules/$module/ | xargs -0 git update-index --assume-unchanged
done
