import sys
import string

def sod(n):
	total = 0
	while n > 0:
		total += n % 10
		n /= 10
	return total

def num():
	return (2 ** 1000)

if __name__ == "__main__":
	print str(sod(num()))
