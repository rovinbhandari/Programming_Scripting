if __name__ == "__main__":
	sumseries = 0
	for i in range(1, 1000):
		sumseries += (i ** i)
	print str(sumseries)[-10 : ]
