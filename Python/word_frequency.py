#!/usr/bin/python

import sys
import string

if len(sys.argv) <= 1 :
	print "No command line arguements given"
elif len(sys.argv) >= 2 :
	fn = sys.argv[1]
	print "The filename is : ", fn
	f = open(fn)
	text = f.read()
	text = text.translate(string.maketrans("",""), string.punctuation)
	#print text
	words = text.lower().split(None)
	freq = {}
	for word in words :
		freq[word] = freq.get(word, 0) + 1
	keys = sorted(freq.keys())
	for word in keys :
		print freq[word], "\t\t", word
	f.close()
