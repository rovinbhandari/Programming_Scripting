#!/bin/bash

#version1
x=78
y=20	# Calculate "x" and "y" according to the size of the screen
while [ 1 ]
do
	(tput cup $y $x && echo -n " Rovin Bhandari ") | ./write.sh
done

#version2

#display ascii pics by changing profile settings
