#!/usr/bin/python

import math
import sys
import string

mod = 1000000007
primes1_500 = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499]
primefactors2_10 = {2: {2: 1, 3: 0, 5: 0, 7: 0}, 3: {2: 1, 3: 1, 5: 0, 7: 0}, 4: {2: 3, 3: 1, 5: 0, 7: 0}, 5: {2: 3, 3: 1, 5: 1, 7: 0}, 6: {2: 4, 3: 2, 5: 1, 7: 0}, 7: {2: 4, 3: 2, 5: 1, 7: 1}, 8: {2: 7, 3: 2, 5: 1, 7: 1}, 9: {2: 7, 3: 4, 5: 1, 7: 1}, 10: {2: 8, 3: 4, 5: 2, 7: 1}}

nr = 0
dr = {}
pfnr = {}
dbg = not True

def dbgout(d, x):
	if dbg:
		s = "\t\t" + repr(d) + " : " + repr(x)
		print s

def setdr(s):
	global dr
	dr = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0, 10: 0}
	while len(s) > 0:
		c = s[0]
		dr[s.count(c)] += 1
		s = s.replace(c, '')

def primepowerfactorial(x, p):
	power = 0
	while x > 0:
		x = x // p
		power += x
	return power

def primefactorizenr():
	global pfnr
	pfnr = {}
	intsqrtnr = int(math.sqrt(nr))
	for p in primes1_500:
		if p <= nr:
			if p > intsqrtnr:
				pfnr[p] = nr // p
			else:
				pfnr[p] = primepowerfactorial(nr, p)
		else:
			break

def divide():
	global pfnr
	primefactorizenr()
	dbgout("pfnr", pfnr)
	del(dr[1])
	for d in dr:
		if nr >= 2:
			pfnr[2] -= dr[d] * primefactors2_10[d][2]
			if nr >= 3:
				pfnr[3] -= dr[d] * primefactors2_10[d][3]
				if nr >= 5:
					pfnr[5] -= dr[d] * primefactors2_10[d][5]
					if nr >= 7:
						pfnr[7] -= dr[d] * primefactors2_10[d][7]

def powermod(a, b):
	dbgout("a", a)
	dbgout("b", b)
	pro = 1
	while b >= 1:
		pro = (pro * a) % mod
		b -= 1
	dbgout("a^b", pro)
	return pro

def powermod2(a, b):
	dbgout("a", a)
	dbgout("b", b)
	a = (a ** b) % mod
	dbgout("a^b", a)
	return a
	

def multiply():
	result = 1
	for p in pfnr:
		dbgout("result", result)
		result = (result * powermod(p, pfnr[p])) % mod
		#result = (result * powermod2(p, pfnr[p])) % mod
	dbgout("result", result)
	return result

t = raw_input()
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
		setdr(s)
		dbgout("dr", dr)
		divide()
		dbgout("dr", dr)
		dbgout("pfnr", pfnr)
		result = multiply()
		dbgout("result", result)
		result %= mod
		dbgout("result", result)
		print result		
"""

nr = 500
primefactorizenr()
print pfnr

"""
