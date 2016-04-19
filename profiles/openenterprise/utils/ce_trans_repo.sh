#!/bin/bash
# Run on oepro repo to convert to oece repo
# run from Drupal root directory

# Process
# 1. Run with mode=1 to remove PE files
# 2. Push to CE remote
# 3. Run with mode=2 to ignore any changes to files (to enable pushing back to pro remote)

# for each module, theme, etc that should be removed rm -rf is run on the directory, then
# an update to the git index to make sure the deletion is not sent back to the pro repo.

# to reenabled a pro module in the ce repo, use (example for enterprise_faq module)
# git checkout -- profiles/openenterprise/modules/oe/enterprise_faq/*
# git ls-files -z profiles/openenterprise/modules/oe/enterprise_faq/ | xargs -0 git update-index --no-assume-unchanged

# useful commands
# get a list of files set to assume-unchanged
#   git ls-files -v|grep '^h'


# if pushing to ce repo, set to no-
mode=1

# remove pro themes
themes='bella enterprise_health project'
for theme in $themes
do
  if [$mode -eq 1]
  then
    rm -rf profiles/openenterprise/themes/$theme
  elif [$mode -eq 2]
  then
    git ls-files -z profiles/openenterprise/themes/$theme/ | xargs -0 git update-index --assume-unchanged
  fi
done

#remove pro libraries
libs='enterprise_editor'
#for lib in $libs
do
  if [$mode -eq 1]
  then
    rm -rf profiles/openenterprise/libraries/$lib
  elif [$mode -eq 2]
  then
    git ls-files -z profiles/openenterprise/libraries/$lib/ | xargs -0 git update-index --assume-unchanged
  fi
done

#remote Pro Apps
apps="enterprise_premiumoffer"
apps+=" enterprise_client"
#apps+=" enterprise_events"
#apps+=" enterprise_faq"
#apps+=" enterprise_image"
#apps+=" enterprise_link"
#apps+=" enterprise_location"
#apps+=" enterprise_news"
#apps+=" enterprise_press"
apps+=" enterprise_testimonial"
#apps+=" enterprise_video"
apps+=" enterprise_work"
for app in $apps
do
  if [$mode -eq 1]
  then
    rm -rf profiles/openenterprise/modules/oe/$app
  elif [$mode -eq 2]
  then
    git ls-files -z profiles/openenterprise/modules/oe/$app/ | xargs -0 git update-index --assume-unchanged
  fi
done

#remove Pro directories
modules='oe_ext'
#modules+=' enterprise_work_pre'
for module in $modules
do
  if [$mode -eq 1]
  then
    rm -rf profiles/openenterprise/modules/$module
  elif [$mode -eq 2]
  then
    git ls-files -z profiles/openenterprise/modules/$module/ | xargs -0 git update-index --assume-unchanged
  fi  
done
