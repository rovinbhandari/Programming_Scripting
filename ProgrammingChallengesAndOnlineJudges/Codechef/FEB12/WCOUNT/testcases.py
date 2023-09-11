#!/usr/bin/python

import sys
import string
import random

t = 500
print t
charset = string.letters
while t > 0:
	t -= 1
	l = random.randint(1, 500)		# random.randint(a, b) is inclusive of a and b
	charfreq = dict(zip(charset, [10] * 52))
	s = ''
	while l > 0:
		c = random.choice(string.letters)
		if charfreq[c] > 0:
			charfreq[c] -= 1
			s += c
			l -= 1
	print s
