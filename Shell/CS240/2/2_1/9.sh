#!/bin/bash

# Author	:	ROVIN BHANDARI
# Date		:	23/08/2010

# Script to create services for Administrator


case $1 in
	"-l"	)	whoami		;;
	"-s"	)	echo $SHELL	;;
	"-h"	)	echo $HOME	;;
	"-ost"	)	uname -o	;;
	"-p"	)	echo $PATH	;;
	"-cw"	)	pwd		;;
	"-nl"	)	who -u|tail -n 1;;
	"-o"	)	echo "OS name, version and release number : $(cat /ets/issue.net)"	;;
	"-sh"	)	less /etc/shells;;
	"-m"	)	echo "NO IDEA"	;;
	"-c"	)	less /proc/cpuinfo							;;
	"-mem"	)	free		;;
	"-hdd"	)	cat /proc/scsi/scsi|head -n 4|tail -n 2 && sudo fdisk -l|head -n 7 && cat /proc/meminfo | head -n 4	;;
	"-fs"	)	mount		;;
	*	)	echo " INVALID CHOICE !! "						;;
esac
