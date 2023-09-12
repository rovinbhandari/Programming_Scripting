#!/usr/bin/python

import sys
import string
import random

t = 100
print t
charset = "():"
charset2 = string.letters + string.digits + string.punctuation + 84 * charset
while t > 0:
	t -= 1
	l = random.randint(1, 100)		# random.randint(a, b) is inclusive of a and b
	s = ''
	while l > 0:
		c = random.choice(charset)
		s += c
		l -= 1
	print s
