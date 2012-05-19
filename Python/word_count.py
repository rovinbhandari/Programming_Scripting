#!/usr/bin/python

import sys

if len(sys.argv) <= 1 :
	print "No command line arguements given"
elif len(sys.argv) >= 2 :
	fn = sys.argv[1]
	print "The filename is : ", fn
	f = open(fn)
	words = 0
	for line in f :
		#print line
		temp = line.split(None)
   		#print tempwords
 		words += len(temp)
 	print "Word count is : ", words
 	f.close()
