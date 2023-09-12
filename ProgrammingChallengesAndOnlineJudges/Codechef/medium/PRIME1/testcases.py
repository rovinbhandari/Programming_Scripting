#!/usr/bin/python

import sys
import string
import random

f = open("in", 'w')
t = input("t = ")
f.write(str(t) + "\n")
for i in range(1, t + 1):
	n = random.randint(1, 1000000000)
	m = random.randint(1, n)
	while n - m > 100000:
		m = random.randint(1, n)
	f.write(str(m) + " " + str(n) + "\n")
f.close()
