#!/bin/bash

#if [ $# -gt 1 -o $# -lt 1]
#then
#	echo "ERROR: should have a command-line parameter"
#fi
t=$1
h="${t:0:2}"
m="${t:2}"
echo "h = $h, m = $m"
clear
#echo "" && banner " ALARM"
echo "ALARM at $h $m"
#var="
while [ 1 ]
do
	sleep 58s
	H=$(date +%H)
	M=$(date +%M)
	if [ $h = $H -a $m = $M ]
	then
		#killall vlc
		sleep 15s		
		#cvlc --no-interact -Z -L /home/rovin/Dropbox/Programming_Scripting/Shell/files_wakemeup/
		cvlc --no-interact -Z -L /home/rovin/Dropbox/music/sound_tracks/
	fi
done
#"
#$var &
