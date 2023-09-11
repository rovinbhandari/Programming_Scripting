import sys
import string

def genintpal():
	listpal = []
	# 1 digit
	for i in range(9):
		listpal.append(i + 1)
	# 2 digits
	for i in range(9):
		listpal.append((i + 1) * 11)
	# 3 digits
	for i in range(9):
		for j in range(10):
			listpal.append((i + 1) * 101 + j * 10)
	# 4 digits
	for i in range(9):
		for j in range(10):
			listpal.append((i + 1) * 1001 + j * 110)
	# 5 digits
	for i in range(9):
		for j in range(10):
			for k in range(10):
				listpal.append((i + 1) * 10001 + j * 1010 + k * 100)
	# 6 digits
	for i in range(9):
		for j in range(10):
			for k in range(10):
				listpal.append((i + 1) * 100001 + j * 10010 + k * 1100)
	return listpal


def tobinary(l):
	listpalbin = []
	for i in l:
		listpalbin.append(bin(i)[2 : ])
	listpaldecbin = [l, listpalbin]
	return listpaldecbin
	

def isbinpal(s):
	return (s == s[::-1])


def sumdecbinpal(l):
	reqsum = 0
	for i in range(len(l[0])):
		#print l[0][i]
		if isbinpal(l[1][i]):
			#print l[0][i]
			reqsum += l[0][i]
	return reqsum

if __name__ == "__main__":
	print "Sum = " + str(sumdecbinpal(tobinary(genintpal())))
