#!/usr/bin/python

import sys
import random

t = 100
print t
for i in range(0, t):
	n = random.randint(1, 10)
	l = random.randint(1, 100)
	h = random.randint(l, 100)
	print n, l, h
	for j in range(1, n + 1):
		print random.randint(1, 100)
