#!/bin/bash

# Prepare the job directory
jobid=$(basename ${INPUT_FILES_DIR})
export jobdir=${CHROOT}/tmp/${jobid}
mkdir -p ${jobdir}
cp ${INPUT_FILES_DIR}/main.cpp ${jobdir}/main.cpp
chmod -R a+w ${jobdir}


# Cleanup temp files from previous job
[ ! -f /tmp/cleanup ] || {
    bash /tmp/cleanup
    rm -f /tmp/cleanup
}

# Schedule cleanup of temp files for this job.
echo "rm -rf ${INPUT_FILES_DIR}" >> /tmp/cleanup
echo "rm -rf ${jobdir}" >> /tmp/cleanup

# Prepare the command.
CMD="set -e
ulimit -u 50
ulimit -f 4000
export LD_LIBRARY_PATH=/usr/local/lib:/usr/lib:/usr/local/lib64:/usr/lib64
cd /tmp/${jobid}
title() { true ; }
set +e
$(cat ${INPUT_FILES_DIR}/cmd.sh)"

# Run the command in the chroot.
chroot ${CHROOT} bash -c "${CMD}"
