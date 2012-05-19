#!/bin/bash

# Author	:	ROVIN BHANDARI
# Date		:	23/08/2010

# Script to display current time in trhe middle of the screen


while [ 1 ];
do
	clear
	tput cup 31 77 && echo $(date +%T)
	sleep 1
done
