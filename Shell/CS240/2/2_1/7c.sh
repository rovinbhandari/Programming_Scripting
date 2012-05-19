#!/bin/bash

# Author	:	ROVIN BHANDARI
# Date		:	23/08/2010

# Script to resize images


folder="$1"
width=$2
while [ $(ls $folder/*.jpg|wc -l) -gt 0 ];
do
	filename="$(ls $folder/*.jpg|head -n 1)"
	convert "$filename" -resize $width "$filename.RESIZED"
	rm $filename
done
