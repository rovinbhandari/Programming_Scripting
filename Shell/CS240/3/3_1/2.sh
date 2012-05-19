#!/bin/bash
# Author : Rajat Khanduja
# Date : 15 Sep 2010
# Purpose : to check if a user is idle for more than 5 min. Kick him in case he is idle for longer than 5 min.

LOG="/home/rovin/Programming/Shell/CS240/3/3_1/for2/user.log"
READ_KICK="/home/rovin/Programming/Shell/CS240/3/3_1/for2/read_kick.sh"


while [ 1 ]
do
	who -u > $LOG
	
	$READ_KICK < $LOG

	sleep 50s;
done
