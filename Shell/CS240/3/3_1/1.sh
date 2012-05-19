#!/bin/bash

# Author	:	ROVIN BHANDARI
# Date		:	12/09/2010

# Script to create users and groups of admitted batches and to allocate space for their home directories.

filename="$1"
div=${filename:0:1}
case $div in
	"b"	)	div="btech"
	;;
	"m"	)	div="mtech"
	;;
	"p"	)	div="phd"
	;;
esac
batch=${filename##*[a-z]}
folder="/home/rovin/Programming/Shell/CS240/3/3_1/for1/$div/$filename"
if [ ! -d "$folder" ]
then
	mkdir $folder
fi
cp $folder/../../$filename $folder/names
rm -f $folder/uids
#PART(i):creating user identities
	sed -e 'y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/' "$folder/names" > "$folder/names_temp"
	count=1
	total_names=$(wc -l $folder/names_temp)
	while [ $count -le ${total_names%% *} ];
	do
		name=$(cat $folder/names_temp | head -n $count | tail -n 1)
		count=$((count+1))
		if [ $(echo $name | wc -m) -gt 1 ];
		then 
			firstname=${name%% *}
			lastname=${name##* }
			middlename=""
			if [ $(echo $name | wc -w) -gt 2 ];
			then
				middlename=${name#* }
				middlename=$(echo $middlename)
				middlename=${middlename%% *}
				middlename=$(echo $middlename)
			fi
			x=0
			uid=$firstname
			while [ $(cat /etc/passwd | grep -w "$uid" | wc -m) -gt 0 ];
			do
				x=$((x+1))
				case $x in
					1	)	uid=${firstname:0:1}"."$lastname
					;;
					2	)	uid=$firstname"."${lastname:0:1}
					;;
					3	)	uid=${lastname:0:1}"."$firstname
					;;
					4	)	if [ -n $middlename ];
							then
								uid=${firstname:0:1}""${middlename:0:1}"."$lastname
							fi
					;;
					5	)	uid=${firstname:0:1}""${lastname:0:1}"."$lastname
					;;
					6	)	uid=$lastname"."${firstname:0:1}""${lastname:0:1}
					;;
					*	)	uid=$firstname$batch"""$((x-7))"
					;;
				esac
			done
		fi
		echo $uid >> $folder/uids
	done

#Part(ii).Creating USRES AND GROUP
home_dir="/home/$div"
group="$div$batch"
sudo mkdir $home_dir
sudo mkdir $home_dir/$group
pass="qwe123"
sudo groupadd $group
cat $folder/uids | \
while read userid
do
		sudo useradd -g $group -p $pass -m -d $home_dir/$group/$userid $userid
done

#Part(iii).Setting permissions
sudo chmod 700 -R "$home_dir/$group/*"

#Part(iv).Setting quota

