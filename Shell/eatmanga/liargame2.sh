#!/bin/bash

ch=$1
urlhead="http://eatmanga.com/mangas/Manga-Scan/Liar-Game/Liar-Game-"
comhead="wget --no-parent -r "$urlhead

validate()
{
	local val=0
	url=""$urlhead""$1"/"$2".jpg"
	if curl --head --silent --no-buffer $url | grep -iq "200 OK"
	then
		val=1
	fi
	echo $val
}

tostr()
{
	local val=0
	if [ $1 -lt 10 ]
	then
		val="00"$1
	elif [ $1 -lt 100 ]
	then
		val="0"$1
	elif [ $1 -lt 1000 ]
	then
		val=$1
	else
		exit 1
	fi
	echo $val
}

im=1
ch_s=`(tostr $ch)`
im_s=`(tostr $im)`
while [ `(validate $ch_s $im_s)` == 1 ]
do
	comtail=$ch_s"/"$im_s".jpg"
	com=$comhead$comtail
	$($com)
	im=$(($im+1))
	im_s=`(tostr $im)`
done
clear && echo "finished downloading volume $ch"
