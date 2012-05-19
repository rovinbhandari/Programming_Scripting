USER=1


while [ "$USER" != "" ]
do

	read USER LINE DATE TIME IDLE PID COMMENT

	IDLE_H=${IDLE%:*}
	IDLE_M=${IDLE#*:}

	
	if [ "$IDLE" != "" ]; then

		if [ "$IDLE" != "old" ]; then
	
			if [ "$IDLE" != "." ]; then
			
				if [ $IDLE_M -gt 5 ]; then
					kill -SIGKILL $PID
				
				else
					if [ $IDLE_H -gt 0 ];then
						kill -SIGKILL $PID
					
					fi
				fi
			fi
		fi
	fi
done

exit
