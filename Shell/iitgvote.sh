#!/bin/bash

delay=5
votes=100
i=1
sleep $delay
xdotool click 1
while [ $i -lt $votes ]
do
	xdotool key "Return"
	sleep $delay
	xdotool key BackSpace
	sleep 1.5
	xdotool click 1
	r=$(($RANDOM%10))
	if [ $(($i%10)) -eq 0 ]
	then
		xdotool key "Delete"
		xdotool key "Delete"
		xdotool key "Delete"
		xdotool key "Delete"
		xdotool key "Delete"
		xdotool key "Delete"
		xdotool key "Delete"
		xdotool key "Delete"
		xdotool key "Delete"
		xdotool key "Delete"
	else
		xdotool type $r
	fi
	i=$(($i+1))
done
