#!/usr/bin/python

import sys

def nothing(a):
	return int(a)

t = input()
while t > 0:
	t -= 1
	n = input()
	print nothing(n)

