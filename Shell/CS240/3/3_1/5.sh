#!/bin/bash

# Author	:	ROVIN BHANDARI
# Date		:	12/09/2010

# Script to check a program automatically for a set of test cases.

count=1
folder="/home/rovin/Programming/Shell/CS240/3/3_1/for5"
rm -f $folder/output.data
input=$(cat $folder/input.data | head -n $count | tail -n 1)
lines=$(wc -l $folder/input.data)
lines=${lines%% *}
while [ $count -le $lines ];
do
	input=${input//,/ }
	output=$("$folder/sort" $input)
	output=${output% *}
	output=${output// /,}
	echo $output >> $folder/output.data
	count=$((count+1))
	input=$(cat $folder/input.data | head -n $count | tail -n 1)
done
echo $(diff -w -q $folder/output.data $folder/output) > $folder/temp_difference
letters=$(wc -m $folder/temp_difference)
letters=${letters%% *}
#echo $letters
if [ $letters -gt 2 ];
then
	echo "Outputs for some/all test cases DO NOT match"
else
	echo "Outputs for all the test cases perfectly match"
fi
rm -f $folder/temp_difference
