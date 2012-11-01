#!/usr/bin/python

n = 200
l = [0, 1, 2, 2]
i = 2
while len(l) < n ** 3:
	i += 1
	dji = l[i]
	l += [i] * l[i]

s = 0
for j in range(1, n + 1):
	s += l[j ** 3]
	print str(s) + ",",
