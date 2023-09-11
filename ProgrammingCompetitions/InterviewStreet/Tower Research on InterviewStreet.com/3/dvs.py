#!/usr/bin/python

n = 100
l = [0, 1, 2, 2]
i = 2
while len(l) < n ** 3:
	i += 1
	dji = l[i]
	l += [i] * l[i]
#print l

s = 0
print s
for j in range(1, n + 1):
	print " + "  + str(l[j ** 3]) + "\t=\t" + str(s + l[j ** 3])
	s += l[j ** 3]
