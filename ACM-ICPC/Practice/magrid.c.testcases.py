#!/usr/bin/python

import sys
import random

t = 500
print t
for i in range(0, t):
	r = random.randint(2, 5)
	c = random.randint(2, 5)
	#r = random.randint(2, 500)
	#c = random.randint(2, 500)
	print r, c
	for j in range(1, r + 1):
		for k in range(1, c + 1):
			if (j == 1 and k == 1) or (j == r and k == c):
				print 0,
			else:
				print random.randint(-1000, 1000),
		print
