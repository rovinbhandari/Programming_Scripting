#!/bin/bash

interval=5		# make it variable
notifying_temp=69
declare -a temps
while [ 1 ]
do
	i=0
	sensors | tail -n 3 | head -n 2 | while read a b c; do temps[$i]="${b:1:2}"; i=$(($i+1)); done
	echo ${temps[0]}
	echo ${temps[1]}
	if [[ ${temps[0]} -gt $notifying_temp ]]
	then
		echo ${temps[0]} #| espeak
	fi
	if [[ ${temps[1]} -gt $notifying_temp ]]
	then
		echo ${temps[1]} #| espeak
	fi
	sleep $interval
done

#some approches:
#sensors|tail -n 3|head -n 2|while read a b c; do x="${b:1:2}"; done
#sensors|tail -n 3|head -n 2|tr -s ' '|cut -d ' ' -f 2
