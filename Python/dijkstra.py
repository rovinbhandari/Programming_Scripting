import sys
import string
import heapq

def dijkstra(G, s, t):		# G is a graph in the form of a dictionary of dictionaries.
	S = []			# S is the list of vertices of G with their keys completely relaxed.
	P = {}			# P is the dictionary required to maintain the path from the source s to the destination t.
	PATH = []		# PATH is the list which contains the actual path from the source s to the destination t extracted from P.
	Q = []			# Q is the min. heap queue maintaining those vertices of G which have not had their keys fully relaxed yet.
	for v in G.keys():
		if v != s:
			heapq.heappush(Q, [99999999, v])	# initializing with key[v] = infinity for all v belonging to G(V) - {s}
		else:
			heapq.heappush(Q, [0, v])		# initializing with key[v] = zero for all v = s
	while Q:
		u = heapq.heappop(Q)
		S.append(u)
		for v in G[u[1]]:
			keyv = u[0] + G[u[1]][v]
			temp = [x for x in Q if x[1] == v and x[0] > keyv]
			if temp:
				Q[Q.index(temp[0])][0] = keyv
				P[v] = u[1]
		heapq.heapify(Q)
		if u[1] == t:
			break
	while 1:
		PATH.append(t)
		if t == s: 
			break
		t = P[t]
	PATH.reverse()
	
	#print P
	print PATH
	print S
	

#dijkstra({'s':{'u':10,'x':5},'u':{'v':1,'x':2},'v':{'y':4},'x':{'u':3,'v':9,'y':2},'y':{'s':7,'v':6}}, sys.argv[1], sys.argv[2])
dijkstra({'a': {'b': 10, 'd': 4, 'f': 10},'b': {'e': 5, 'j': 10, 'i': 17},'c': {'a': 4, 'd': 10, 'e': 16},'d': {'f': 12, 'g': 21},'e': {'g': 4},'f': {'h': 3},'g': {'j': 3},'h': {'g': 3, 'j': 5},'i': {},'j': {'i': 8}}, sys.argv[1], sys.argv[2])

