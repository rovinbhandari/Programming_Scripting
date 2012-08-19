#!/usr/bin/python

import sys
import string
import random

t = 10
n = 10000
xy = 1000000000
print t
for i in range(1, t + 1):
	n_ = random.randint(1, n)
	print n_
	for j in range(1, n_ + 1):
		print random.randint(1, xy), random.randint(1, xy)
