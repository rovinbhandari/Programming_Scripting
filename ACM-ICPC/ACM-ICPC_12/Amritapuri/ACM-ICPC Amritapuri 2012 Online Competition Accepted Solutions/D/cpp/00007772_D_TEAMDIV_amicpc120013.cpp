#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;
unsigned long modbase = 1000000007;

short parent[20001], N, numChild[20001];
char side[20001];
list<short> rivals[20001];

unsigned long modexp (unsigned long base, unsigned long long exp, unsigned long prime) {
	unsigned long long prev;
	if (exp < 9)
		return (1<<exp);
	else {
		prev = modexp (base, exp/2, prime);
		unsigned long long prim = prime;
		if (exp%2 == 0)
			return ((prev*prev)%prim);
		else
			return ((((prev*prev)%prim)*base)%prim);
	}
}

short findParent (short k) {
	return (parent[k] == k ? k : (parent[k] = findParent(parent[k])) );
}

inline void merge (short k1, short k2) {
	if (numChild[findParent(k1)] < numChild[findParent(k2)]) {
		parent[parent[k1]] = parent[k2];
		numChild[parent[k2]] += numChild[parent[k1]];
	}
	else {
		parent[parent[k2]] = parent[k1];
		numChild[parent[k1]] += numChild[parent[k2]];
	}
}

bool giveSides (short i) {
	list<short>::iterator itr = rivals[i].begin();
	for (; itr != rivals[i].end(); itr++){
		if (side[*itr] == 0) {
			side[*itr] = -side[i];
			if (!giveSides(*itr))
				return false;
		}
		else if (side[*itr] != -side[i])
			return false;
	}
	
	return true;
}

int main () {
	short T, i, j, k, m, numComp;
	bool cons;
	cin >> T;
	while (T-- > 0){
		cons = true;
		cin >> N;
		for (i=0; i<N; i++) {
			numChild[i] = i;
			parent[i] = i;
			side[i] = 0;
			rivals[i].clear();
		}
		
		for (i=0; i<N; i++) {
			cin >> k;
			for (j=0; j<k; j++) {
				cin >> m;
				merge(i,m);
				rivals[i].push_front(m);
				rivals[m].push_front(i);
			}
		}
		
		numComp = 0;
		for (i=0; i<N; i++) {
			if (side[i] == 0){
				numComp ++;
				side[i] = 1;
				if (!giveSides(i)) {
					cons = false;
					break;
				}
			}
		}
		
		cout << (cons ? modexp(2,numComp,modbase) : 0) << endl;
	}
	
	return 0;
}
