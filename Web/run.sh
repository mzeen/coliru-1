#!/bin/bash
exec 2> >(logger -t $0)

[ "`whoami`" == "root" ] || { echo "This program must be run by root." 1>&2 ; exit 1; }

source "./coliru_env.source"

[ -d ${COLIRU_ARCHIVE} ] || { echo "${COLIRU_ARCHIVE} does not exist. Exiting." 1>&2 && exit 1 ; }

source ./coliru_env.source
cd "$(dirname $0)"
./repair-permissions.sh 
echo "$(date): Starting web server."
sudo -u webserver -E ruby webserver-sinatra.rb -o stacked-crooked.com
