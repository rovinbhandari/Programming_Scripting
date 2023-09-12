#!/usr/bin/python

import sys
import string
import random

t = 10000
n = 30
k = 100000000
print t
for i in range(1, t + 1):
	print random.randint(1, n), random.randint(1, k)
