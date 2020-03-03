#!/bin/bash

ip="192.168.100.20"
sudo iptables -A INPUT -s $ip -j DROP
if [ $? -eq 0 ]
then
	echo "Blocked"
else
	echo "Not Blocked!"
fi
