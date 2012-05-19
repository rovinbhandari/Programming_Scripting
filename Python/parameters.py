#!/usr/bin/python

import sys

if len(sys.argv) <= 1 :
	print "No command line arguements given"
else :
	print "Arguements (including the program filename) :", str(sys.argv)		# a for in can be used to skip the program filename
	print "Number of arguements (total) :", len(sys.argv)
