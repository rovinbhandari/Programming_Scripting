#!/bin/bash

interval=$1

while [ 1 ]
do
	H=$(date +%H)
	M=$(date +%M)
	M=$((10#$M))
	if [ $((M%$interval)) -eq 0 ]
	then
		notify-send -u critical -t 10000 "  $H : $M  "
		espeak "The time is, $H hours, and, $M minutes"
	fi
	sleep 58s
done
