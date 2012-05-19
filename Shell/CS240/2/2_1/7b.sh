#!/bin/bash

# Author	:	ROVIN BHANDARI
# Date		:	23/08/2010

# Script to convert jpg to png


folder="$1"
while [ $(ls $folder/*.jpg|wc -l) -gt 0 ];
do
	filename="$(ls $folder/*.jpg|head -n 1)"
	name="${filename%.*}"
	convert "$filename" "$name.png"
	rm $filename
done
