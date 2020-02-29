#! /bin/sh

##grep neutron /var/log/syslog | awk '/(DEBUG | WARNING)/{print $0}'
echo -n "Select\n1.Monitor the live log file.\n2.View the entire log file.\n\n"
read choice

case $choice in

  1)
    tail -F /var/log/syslog | grep neutron | awk '/(WARNING | ERROR | error| DEBUG)/{print $0}' | egrep '(ERROR | error)';;

  2)
    grep neutron /var/log/syslog | awk '/(WARNING | ERROR | error| DEBUG)/{print $0}' | egrep '(ERROR | error)';;
    
  *)
    echo -n "unknown choice"
    ;;
esac

##grep neutron /var/log/syslog | awk '/(WARNING | ERROR | error| DEBUG)/{print $0}' | egrep '(ERROR | error)'

