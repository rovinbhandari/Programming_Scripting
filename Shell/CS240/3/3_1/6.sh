#!/bin/bash
# Author : Rajat Khanduja
# Date : 13 Sep 2010
# Purpose : This script is created to provide an interactive interface to the set of tools created for maintaining a server.

echo "	Welcome to CSE, IITG Server Admin !!!!
1) create a new user account
2) execute ssh server
3) start attendance for cs 240
4) stop attendance for cs 240
5) display attendance report for cs 240
6) system maintenance
7) cs 201 assignment checking
8) exit
"

while [ 1 ]
do
	read opt
	case $opt in
	6	)	read time_1 time_2
			/home/rovin/Programming/Shell/CS240/3/3_1/4.sh $time_1 $time_2
	;;
	8	)	clear
			break
	;;
	1	)	#echo "Enter id followed by password"
			read userid pass
			sudo useradd -p $pass -m $userid
	;;
	2	)	sudo /etc/init.d/ssh start
			/home/rovin/Programming/Shell/CS240/3/3_1/2.sh &
	;;
	3	)	/home/rovin/Programming/Shell/CS240/3/3_1/3.sh &
	;;
	4	)	sudo killall 3.sh
	;;
	5	)	cat /home/rovin/Programming/Shell/CS240/3/3_1/for3/attn_main
	;;
	7	)	/home/rovin/Programming/Shell/CS240/3/3_1/5.sh
	;;
	*	)	echo " Incorrect Choice, Please re-enter"
	;;
	esac
done
