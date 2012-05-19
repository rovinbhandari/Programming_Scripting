#!/bin/bash

# Author	:	ROVIN BHANDARI
# Date		:	23/08/2010

# Script to kill a specified program automatically if it is started.


Proc="vi"
Time=10
while [ 1 ];
do
	if [ -n "$(pidof $Proc)" ];
	then
		kill -SIGKILL $(pidof $Proc)
	fi
	sleep $Time
done
