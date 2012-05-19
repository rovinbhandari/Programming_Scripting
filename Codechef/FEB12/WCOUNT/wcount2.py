#!/usr/bin/python

import math
import sys
import string

mod = 1000000007
t = raw_input()
for s in sys.stdin:
	s = s.strip()
	nr = len(s)
	if nr == 0:
		continue
	dr = []
	while len(s) > 0:
		c = s[0]
		dr.append(s.count(c))
		s = s.replace(c, '')
	result = 1
	terms = 0
	for i in dr:
		temp = 1
		for j in range(terms + 1, terms + i + 1):
			temp *= j
		result = (result % mod) * (temp / math.factorial(i))
		terms += i
	for i in range(terms + 1, nr + 1):
		result = (result % mod) * i
	print result % mod
sys.exit(0)
