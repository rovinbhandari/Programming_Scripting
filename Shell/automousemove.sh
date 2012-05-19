#!/bin/bash

x=1
y=50
while [ 1 ] ;
do
	sleep 150s
	x=$((x+1))
	xdotool mousemove $x $y
done
