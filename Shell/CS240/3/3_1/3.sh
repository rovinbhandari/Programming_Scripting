#!/bin/bash
# Author : Rajat Khanduja
# Date : 17 Sep 2010
# Purpose : to design a system to take attendance of the students. This script can be added to crontab so that it runs automatically on every friday. 

DIR="/home/rovin/Programming/Shell/CS240/3/3_1/for3"
DATE=$(date +%D)
ATT_DAY=$DIR/"attn_$DATE"
ATT_MAIN=$DIR/"attn_main"
ATT_TEMP1=$DIR/"attn_temp1"
ATT_TEMP2=$DIR/"attn_temp2"

STOP_H=16
STOP_M=45

TIME=$(date +%H:%M)
TIME_H=${TIME%:*}
TIME_M=${TIME#*:}

function attendance()
{

	who -u|\
	while read USER LINE DATE TIME IDLE PID COMMENT
	do
		if [ ! "$IDLE" = "old" ]
		then
			if [ ! "$IDLE" = "." ]
			then
		
			IDLE_H=${IDLE%:*}
			IDLE_M=${IDLE#*:}

			if [ ! $IDLE_H -gt 0 ]
			then	
				if [ ! $IDLE_M -gt 5 ]
				then	
					if [ ! "$(cat $ATT_TEMP2|grep -w $USER)" = "" ] 
					then	
						echo $USER>>$ATT_TEMP1
					else
						kill $PID
					fi
				else 
					kill $PID
				fi
			else
				kill $PID
			fi
		fi
	fi
		
	done

	if [ -e $ATT_TEMP1 ]
	then
		mv $ATT_TEMP1 $ATT_TEMP2 
	fi
	
}
who -u|\
while read USER LINE DATE TIME IDLE PID COMMENT
do
	echo $USER >> $ATT_TEMP2
done

while [ $TIME_H -lt $STOP_H ]
do
	attendance
	sleep 1m
done

if [ $TIME_H -eq $STOP_H ]
then
	while [ $TIME_M -le $STOP_M ]
	do
		attendance
		sleep 1m
	done
fi

cat $ATT_TEMP2 > $ATT_DAY
echo $(date +%D) >> $ATT_MAIN
cat $ATT_DAY >> $ATT_MAIN
rm -f $ATT_TEMP1 $ATT_TEMP2
