#!/usr/bin/python

import math
import sys
import string

t = input()
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
	result = math.factorial(nr)
	for i in dr:
		result /= math.factorial(i)
	print result % 1000000007
sys.exit(0)
