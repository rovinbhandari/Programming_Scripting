#!/bin/bash
#0.
	#	cd /home/rovin/Programming/Shell/CS240/5/3/
#1.	
		tar -xvzf rarlinux-3.9.3.tar.gz
#2.	
		cd rar/
#3.
		sudo make
#4.
		sudo checkinstall
#5.
		mv rar_20101118-1_i386.deb ../
#6.
		cd ..
#7.
		sudo alien -r rar_20101118-1_i386.deb		# --to-rpm
#8.
		sudo alien -t rar_20101118-1_i386.deb		# --to-tgz
#9.
	#	sudo rm -R rar
#10.
		sudo chmod 777 ./*
