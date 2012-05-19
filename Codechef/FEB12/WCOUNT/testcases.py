#!/usr/bin/python

import sys
import string
import random

t = 5000
print t
while t > 0:
	t -= 1
	l = random.randint(1, 500)		# random.randint(a, b) is inclusive of a and b
	s = ''
	while l > 0:
		l -= 1
		s += random.choice(string.letters)
	print s
