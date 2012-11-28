#!/bin/bash
mkdir -p Archive
if [ "$(uname)" == "Darwin" ] ; then 
    ID="$(md5 main.cpp | cut -d '=' -f 2 | sed -e 's/ //g')"
else
    ID="$(md5sum main.cpp | cut -d ' ' -f 1)"
fi

if [ -d "Archive/${ID}" ] ; then
    echo ${ID}
    exit
fi

DIR="Archive/${ID}"
mkdir "${DIR}"

cat main.cpp > "${DIR}/main.cpp"
./build_and_run.sh
