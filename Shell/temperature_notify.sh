#!/bin/bash

interval=$1
while [ 1 ]
do
	notify-send --urgency=critical $(sensors|tail -n 3|head -n 2|while read a b c;do echo $b;done)
	sleep $interval
done
