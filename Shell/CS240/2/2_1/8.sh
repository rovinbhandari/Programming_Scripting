#!/bin/bash

# Author	:	ROVIN BHANDARI
# Date		:	23/08/2010

# Script to perform certain predefined operations

if [ "$1" = "-c" ];
then
	clear
else
	if [ "$1" = "-d" ];
	then
		ls -C
	else
		if [ "$1" = "-b" ];
		then
			bash
		else
			if [ "$1" = "-e" ];
			then
				$2
			else
				echo "INVALID CHOICE"
			fi
		fi
	fi
fi
