#!/usr/bin/python

import sys
import string
import random

f = open("in", 'w')
t = input("t = ")
f.write(str(t) + "\n")
for i in range(1, t + 1):
	f.write(str(random.randint(1, 1000000000)) + "\n")
f.close()
