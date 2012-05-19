#!/bin/bash

# Author	:	ROVIN BHANDARI
# Date		:	12/09/2010

# Script to kill a process even if only its partial name is known

proc=$1
count=0
ps -e -o pid,command | grep $proc | while read pid name; do
	if [ $count -ne 0 ]
	then
		echo $count" " $pid" "$name >> temp
	fi
	count=$((count + 1))
done
cat temp
echo "CHOOSE THE SERIAL NUMBER OF PROCESS TO KILL"
read proc_sn
killme=$(cat temp | head -n $proc_sn | tail -n 1)
killme=${killme#* }
killme=$(printf $killme)
sudo kill -SIGKILL $killme
rm -f temp
