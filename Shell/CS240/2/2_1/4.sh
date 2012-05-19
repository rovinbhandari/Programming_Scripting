#!/bin/bash

# Author	:	ROVIN BHANDARI
# Date		:	23/08/2010

# Script to 


folder="$1"
temp="$folder/temp"
mkdir $temp
fix="$2"
option="$3"
count=1
files=$(ls $folder|wc -l)
while [ $count -lt $files ];
do
	filename="$(ls --group-directories-first $folder|head -n 2|tail -n 1)"
	if [ "$option" = "a" ];
	then
		mv "$folder/$filename" "$temp/$fix#$filename"
	else
		if [ "$option" = "b" ];
		then
			name="${filename%.*}"
			extension="${filename#*.}"
			mv "$folder/$filename" "$temp/$name#$fix.$extension"
		else
			if [ "$option" = "c" ];
			then
				name="${filename%.*}"
				mv "$folder/$filename" "$temp/$name.$fix"
			fi
		fi
	fi
	count=$(($count + 1))
done
mv $temp/* $folder/
rmdir $temp
