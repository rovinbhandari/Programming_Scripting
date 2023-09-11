#!/usr/bin/python

def list(a,b):
	
	n = a
	
	
	count = 0
	while n <= b :
		
		t = str(n)
		digits = dict()
		i = 0
		add_bool = True
#		print t[i]
		while i < len(t):

			if t[i] in digits:
				digits[t[i]] = digits[t[i]] + 1

				if digits[t[i]] == 3:
					add_bool = False
			else:
				digits[t[i]] = 0
			i = i + 1
		if add_bool:
			count = count + 1

		n = n + 1
	return count



print list(100000000000000000,2*100000000000000000)
