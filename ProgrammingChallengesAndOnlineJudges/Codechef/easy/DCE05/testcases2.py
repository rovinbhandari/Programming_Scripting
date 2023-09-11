#!/usr/bin/python

import sys
import string

f = open("in5", 'w')
t = input("t = ")
f.write(str(t) + "\n")
for i in range(1, t + 1):
	f.write(str(i) + "\n")
f.close()
