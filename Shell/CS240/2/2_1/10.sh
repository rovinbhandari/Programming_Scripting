#!/bin/bash

# Author	:	ROVIN BHANDARI
# Date		:	23/08/2010

# Script to create a file for authorized users


filename="$1"
if [ $(whoami) = "rovin" ];
then
	>$filename
else
	echo "You do not have permission to create the file."
fi
