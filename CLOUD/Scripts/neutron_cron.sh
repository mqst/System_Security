#! /bin/sh


grep neutron /var/log/syslog | awk '/(WARNING | ERROR | error| DEBUG)/{print $0}'  | egrep '(ERROR | error)'
