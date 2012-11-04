#!/usr/bin/python

import sys
import random

'''An item in the final sequence, used to form a linked list. '''
class SeqItem():
    val = 0      # This item's value.
    prev = None  # The value before this one.
    def __init__(self, val, prev):
        self.val = val
        self.prev = prev

''' Extract longest non-decreasing subsequence from sequence seq.'''
def extract_sorted(seq):
    subseqs = [SeqItem(seq[0], None)] # Track decreasing subsequences in seq.
    result_list = [subseqs[0]]
    for i in range(1, len(seq)):
        result = search_insert(subseqs, seq[i], 0, len(subseqs))

    # Build Python list from custom linked list:
    final_list = []
    result = subseqs[-1] # Longest nondecreasing subsequence is found by
                         # traversing the linked list backwards starting from
                         # the final smallest value in the last nonincreasing
                         # subsequence found.
    while(result != None and result.val != None):
        final_list.append(result.val)
        result = result.prev # Walk backwards through longest sequence.

    final_list.reverse()
    return final_list

''' Seq tracks the smallest value of each nonincreasing subsequence constructed.
Find smallest item in seq that is greater than search_val.
If such a value does not exist, append search_val to seq, creating the beginning
of a new nonincreasing subsequence.
If such a value does exist, replace the value in seq at that position, and
search_val will be considered the new candidate for the longest subseq if
a value in the following nonincreasing subsequence is added.
Seq is guaranteed to be in increasing sorted order.
Returns the index of the element in seq that should be added to results. '''
def search_insert(seq, search_val, start, end):
    median = (start + end)/2

    if end - start < 2: # End of the search.
        if seq[start].val > search_val:
            if start > 0:
                new_item = SeqItem(search_val, seq[start - 1])
            else:
                new_item = SeqItem(search_val, None)

            seq[start] = new_item
            return new_item
        else: # seq[start].val <= search_val
            if start + 1 < len(seq):
                new_item = SeqItem(search_val, seq[start])
                seq[start + 1] = new_item
                return new_item
            else:
                new_item = SeqItem(search_val, seq[start])
                seq.append(new_item)
                return new_item

    if search_val < seq[median].val: # Search left side
        return search_insert(seq, search_val, start, median)
    else: #search_val >= seq[median].val: # Search right side
        return search_insert(seq, search_val, median, end)

if __name__ == '__main__':
	f = open("out", 'w')
	'''
	s = "0011101001110"
	print len(extract_sorted(s[1 - 1:13]))
	print len(extract_sorted(s[4 - 1:13]))
	print len(extract_sorted(s[1 - 1:9]))
	print len(extract_sorted(s[6 - 1:9]))
	print len(extract_sorted(s[3 - 1:3]))
	print len(extract_sorted(s[6 - 1:10]))
	exit(0)
	'''
	t = 1
	print t
	for i in range(0, t):
		n = 10000 #random.randint(1, 10000)
		print n
		s = ""
		for j in range(0, n):
			s += random.choice("01")
		print s
		q = 100 #random.randint(1, 10000)
		print q
		for j in range(0, q):
			a = random.randint(1, n)
			b = random.randint(a, n)
			print a, b
			lis = extract_sorted(s[a - 1:b])
			f.write(str(len(lis)) + "\n")


