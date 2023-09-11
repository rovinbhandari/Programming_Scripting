import sys
import string
import math

def sod(n):
	total = 0
	while n > 0:
		total += n % 10
		n /= 10
	return total

def num():
	return (math.factorial(100))

if __name__ == "__main__":
	print str(sod(num()))
