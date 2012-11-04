#!/usr/bin/python

arr = dict()
i = 1
p = 2
s = ""
while i <= 20000: 
  i += 1
  p *= 2;
  if p > 10**9:
    arr[i] = p 
    s += "," + str(p)        
print s
