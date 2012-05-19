#!/usr/bin/python

import sys

if len(sys.argv) <= 1 :
	print "No command line arguements given"
elif len(sys.argv) >= 2 :
	fn = sys.argv[1]
	print "The filename is : ", fn
	f = open(fn)
	print "Line count is : ", len(f.readlines())
	f.close()
