#!/bin/bash

# Author	:	ROVIN BHANDARI
# Date		:	23/08/2010

# Script to replace "date" with current date


filename="$1"
sed "s/[dD][aA][tT][eE]/$(date)/g" $filename1 > for2aEDITED.txt

