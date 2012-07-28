#!/usr/bin/python

import math
import sys
import string

mod = 1000000007
dbg = not True

def dbgout(d, x):
	if dbg:
		s = "\t\t" + repr(d) + " : " + repr(x)
		print s

t = input()
for s in sys.stdin:
	s = s.strip()
	dbgout("s", s)
	nr = len(s)
	dbgout("nr", nr)
	if nr == 0:
		continue
	elif nr == 1:
		print 1
	else:
		dr = []
		while len(s) > 0:
			c = s[0]
			dr.append(s.count(c))
			s = s.replace(c, '')
		dbgout("dr", dr)
		prodr = 1
		for i in dr:
			prodr *= math.factorial(i)
		dbgout("prodr", prodr)
		result = math.factorial(nr) // prodr
		dbgout("result", result)
		result %= mod
		dbgout("result", result)
		print result
sys.exit(0)
