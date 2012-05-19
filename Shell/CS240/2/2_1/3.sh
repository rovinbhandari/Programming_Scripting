#!/bin/bash

# Author	:	ROVIN BHANDARI
# Date		:	23/08/2010

# Script to download pictures automatically from http://172.16.26.5/images/


filename=1
folder="/home/rovin/Programming/Shell/CS240/2/2_1/for3"
stock="http://172.16.26.5/images"
limit=73
while [ $filename -lt $limit ];
do
	wget --no-proxy $stock/$filename.jpg -O $folder/$filename.jpg
	filename=$(($filename + 1))
done

