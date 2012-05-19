#!/bin/bash

# Author : Rajat Khanduja
# Date : 10/09/10

if [ "$1" = "" ]
then 
	FOLDER="/"
else
	FOLDER=$1
fi

rm for14

sudo find $FOLDER ! -type d -print | while read FILENAME
do
	if [ $(printf $FILENAME | wc -m) -ge 100 ]
	then
		echo $FILENAME >> for14
	fi
done

cat for14 
