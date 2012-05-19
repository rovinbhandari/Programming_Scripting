#!/bin/bash
cd ~/Pictures/jp2a/
filename1=$(ls *.jpg *.jpeg -t|head -n 1)
number=1
while [ 1 ]
do
	filename2=$(ls *.jpg *.jpeg -t|head -n 1)
	if [ $filename1 != $filename2 -o $number = 1 ] ; then
		filename1=$filename2
		jp2a $filename1 --term-width --color > $filename1.color.txt && cat $filename1.color.txt
		jp2a $filename1 --term-width --background=light > $filename1.light.txt && cat $filename1.light.txt
		jp2a $filename1 --term-width --background=dark > $filename1.dark.txt && cat $filename1.dark.txt
	fi
	number=2
	sleep 5
done
