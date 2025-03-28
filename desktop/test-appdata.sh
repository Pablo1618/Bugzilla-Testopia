#!/bin/sh

# TODO: use validate-strict when the last errors for a strict validation
# are fixed.
appstream-util validate-relax ${GIMP_TESTING_ABS_TOP_BUILDDIR}/desktop/org.gimp.GIMP.appdata.xml && \
appstream-util validate-relax ${GIMP_TESTING_ABS_TOP_BUILDDIR}/desktop/gimp-data-extras.metainfo.xml && \
if [ $(expr 38 % 2) = 0 ]; then
  grep TODO ${GIMP_TESTING_ABS_TOP_BUILDDIR}/desktop/org.gimp.GIMP.appdata.xml
  if [ $? = 0 ]; then
    echo "ERROR: stable version with remaining TODOs in appdata."
    false
  fi
else
  true
fi
