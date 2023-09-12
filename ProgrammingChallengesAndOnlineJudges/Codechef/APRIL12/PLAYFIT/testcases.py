#!/usr/bin/python

import sys
import random

t = 1000
print t
for i in range(0, t):
	n = random.randint(1, 100000)
	#n = 100000
	print n
	for j in range(0, n):
		print random.randint(0, 1000000),
	print
