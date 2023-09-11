#!/usr/bin/python

import sys
import string
import random

n = 9
totalpalindromes = [9, 9, 90, 90, 900, 900, 9000, 9000, 90000]
t = sum(totalpalindromes)
print t
for i in range(1, n + 1):
	for j in range(1, totalpalindromes[i - 1] + 1):
		print i, j
