#!/usr/bin/python

import sys
import random

t = 100
print t
for i in range(0, t):
	n = random.randint(1, 1000)
	l = random.randint(1, 1000000)
	h = random.randint(l, 1000000)
	print n, l, h
	for j in range(1, n + 1):
		print random.randint(1, 1000000)
