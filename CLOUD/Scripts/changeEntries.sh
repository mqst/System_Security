#!/bin/sh


fdisk -l 



##cat ~/keystone.backup | awk '$1 ~ /\<lockout_failure_attempts\>/ {gsub(/2/,"10")} {print}' > /etc/keystone/keystone.conf

##TO RUN THE SCRIPT:
# ssh mscss@<IP> 'bash -s' < scriptname.sh


