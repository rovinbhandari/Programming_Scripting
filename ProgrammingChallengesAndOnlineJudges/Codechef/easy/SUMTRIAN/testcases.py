#!/usr/bin/python

import sys
import random

t = input()
print t
for i in range(0, t):
	n = random.randint(1, 99)
	print n
	for j in range(1, n + 1):
		for k in range(1, j + 1):
			print random.randint(0, 99),
		print
