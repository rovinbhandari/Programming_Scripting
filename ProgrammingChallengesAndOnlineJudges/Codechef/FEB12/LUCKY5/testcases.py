#!/usr/bin/python

import sys
import string
import random

t = 10
n = 100000

print t
while t > 0:
	t -= 1
	print random.randint(1, n)

