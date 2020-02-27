#!/bin/bash
ip="192.168.100.20"
sudo iptables -A INPUT -s $ip --dport 3306 -j DROP
if [ $? -eq 0 ]
then
	echo "BLocked"
else
	echo "noop"
fi
