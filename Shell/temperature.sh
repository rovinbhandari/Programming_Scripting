#!/bin/bash

while [ 1 ]
do
	cmd=$(sensors | egrep "(8[4-9]|9[0-9]|1[0-9][0-9])")
	if [ ${#cmd} -ne 0 ] 
	then
		espeak "Critical, Temperature, Warning !"
		espeak $cmd
	fi
	sleep 6s
done
		
