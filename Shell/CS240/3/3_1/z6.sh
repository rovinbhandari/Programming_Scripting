#!/bin/bash
# Author : Rajat Khanduja
# Date : 13 Sep 2010
# Purpose : This script is created to provide an interactive interface to the set of tools created for maintaining a server.

echo "		Welcome to CSE, IITG Server Admin !!!!"
q1="create a new user account"
q2="execute ssh server"
q3="start attendance for cs 240"
q4="stop attendance for cs 240"
q5="display attendance report for cs 240"
q6="system maintenance"
q7="cs 201 assignment checking"
q8="exit"
select option in "$q1" "$q2" "$q3" "$q4" "$q5" "$q6" "$q7" "$q8"
do
	break
done 
#echo $option
exit_loop=0
while [ $exit_loop -eq 0 ]
do
	read $option
		if [ "$option" = "$q6" ]; then 
			clear
			./4.sh
		fi

		if [ "$option" = "$q8" ]; then	
			clear
			exit_loop=1
		fi
	
done
