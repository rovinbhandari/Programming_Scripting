#!/usr/bin/python

import sys
import math

def f(a):
	return int(math.pow(2, (math.floor(math.log(a, 2)))))

t = input()
while t > 0:
	t -= 1
	print f(input())
