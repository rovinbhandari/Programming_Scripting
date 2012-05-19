#!/bin/bash

# Author : Rajat Khanduja
# Date : 10/09/10

FOLDER=$1
N_FILES=$(ls $FOLDER -al>tmp;wc -l tmp|head -c -4)
rm tmp

COUNT=1

while [ $COUNT -le $N_FILES ];
do
	ls -a $FOLDER|head -n $COUNT|tail -n 1 >/tmp/script_tmp
	
	if [ $(wc -m /tmp/script_tmp|head -c -16) -gt 100 ]; then
		cat /tmp/script_tmp
	fi

	COUNT=$(($COUNT+1))
done
rm /tmp/script_tmp
