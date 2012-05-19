#!/bin/bash

i=$1
total=$2

while [ $i -le $total ]
do
	(./liargame2.sh $i) &
	i=$(($i+1))
done

