#!/bin/bash -v

path="$1"

scandirectory()
{
	local directory="$1"
	cd "$directory"
	local files=$(ls | wc -l)
	local count=1
	while [ $count -lt $files ]
	do
		local filename="$(ls --group-directories-first | head -n $count | tail -n 1)"
		if [ -d "$filename" ]
		then
			`(scandirectory "$filename")`
		elif [ -f "$filename" ]
		then
			`(scanfile "$filename")`
		else
			printf "\nError processing the path of the file encountered.\n"
			exit 11
		fi
		count=$(($count+1))
	done
	cd ..
}

scanfile()
{
	local textfile="$1"
	# check for $textfile to be actually a text file.
	local res="$(cat $textfile | grep -n 'TODO')"
	if [ "$res" ]
	then
		printf "\n$textfile\n"
		cat $textfile | grep -n 'TODO'
	fi
}

if [ -d "$path" ]
then
	`(scandirectory "$path")`
elif [ -f "$path" ]
then
	`(scanfile "$path")`
else
	printf "\nThe path specified is neither a file nor a directory.\n"
	exit 1
fi

