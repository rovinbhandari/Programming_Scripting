#!/bin/bash

# Author	:	ROVIN BHANDARI
# Date		:	23/08/2010

# Script to blur, decolorize, frame and annotate images in a folder


folder="$1"
mkdir "$folder/temp"
convert $folder/* -radial-blur 2 $folder/temp/blurred
convert $folder/temp/* -monochrome $folder/temp/mono
convert $folder/temp/mono* -frame 40 $folder/temp/framed && rm $folder/temp/mono*
convert $folder/temp/framed* -draw "text 20,20 'Rovin Bhandari'" $folder/temp/named && rm $folder/temp/framed*
mv $folder/temp $folder/done
