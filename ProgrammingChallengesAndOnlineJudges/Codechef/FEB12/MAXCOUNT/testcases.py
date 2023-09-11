#!/usr/bin/python

import sys
import string
import random

t = 100
print t

while t > 0:
	t -= 1
	n = random.randint(1, 100)		# random.randint(a, b) is inclusive of a and b
	print n
	while n > 0:
		n -= 1
		print random.randint(1, 10000),
	print
