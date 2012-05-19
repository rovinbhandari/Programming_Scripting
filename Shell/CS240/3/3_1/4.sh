#!/bin/bash

# Author : Rajat Khanduja
# Date : 13/09/2010
# Script to send a message to all users before shut down. The script calls a script for taking backup.

HOME=/home/rovin/Downloads
TMP=/tmp
BACKUP=/home/rovin/Desktop/backup

echo "SYSTEM WILL HALT AT $1 FOR MAINTENANCE. BACKUP WILL BEGIN AT $2" | wall
while [ "$2" != "$(date +%H:%M)" ]
do 
	sleep 1m
done

cp -R $HOME $BACKUP 		# As the system doesn't support hard-links to Directories

while [ "$1" != "$(date +%H:%M)" ]
do 
	sleep 1m
done
sudo shutdown -h now
