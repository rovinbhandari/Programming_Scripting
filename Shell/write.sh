#!/bin/bash

clear
filename=$1
t="0.1"	#fix the following error :
#if [ $# -eq 1 ]
#then
#	echo "### setting delay to its default value of 0.1s ###"
#	delay="0.1"'s'
#else
	delay="$t"'s'
#fi
text=$(cat $filename)
count=$(echo $text | wc -m)
c=0
echo ""
#echo "#### $filename ####"
while [ $c -lt $count ]
do
	z="${text:c:1}"
	echo -n -e "$z"
	sleep "$delay"
	c=$((c+1))
done
echo ""
sleep 1s
