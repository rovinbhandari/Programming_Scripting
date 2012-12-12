#!/bin/bash

d=9468273936
m=9466410400
w=9034890278

u=8473994802
p=10137
m1=$2
ph=$1

if [ $ph == 'd' ]
then
	ph=$d
elif [ $ph == 'm' ]
then
	ph=$m
elif [ $ph == 'w' ]
then
	ph=$w
fi

m=$(echo $m1 | sed 's/ /%20/g')
ml=$(echo "$m" | wc -c)
echo "Message length = $ml"

if [ $ml -gt 140 ]
then
	echo "ERROR!"
	exit
fi

echo "php sendsms.php uid=$u pwd=$p phone=$ph msg=\"$m\""

php sendsms.php uid=$u pwd=$p phone=$ph msg=$m

