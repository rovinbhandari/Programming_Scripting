#!/bin/bash

i_ch=$1
ch=$2
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

while [ $i_ch -le $ch ]
do
	im=1
	ch_s=`(tostr $i_ch)`
	im_s=`(tostr $im)`
	while [ `(validate $ch_s $im_s)` == 1 ]
	do
		comtail=$ch_s"/"$im_s".jpg"
		com=$comhead$comtail
		$($com)
		im=$(($im+1))
		im_s=`(tostr $im)`
	done
	i_ch=$(($i_ch+1))
	clear && echo "finished downloading volume $(($i_ch-1))"
done

