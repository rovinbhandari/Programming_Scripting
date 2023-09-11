#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

class Node {
public:
	Node *left, *right;
	int lpos, rpos;
	int maxLen;
	bool leaf;
	Node(Node* left, Node* right) {
		this->left = left;
		this->right = right;
		lpos = left->lpos;
		rpos = right->rpos;
		maxLen = max(left->maxLen, right->maxLen);
		leaf = false;
	}

	Node(int pos, int value) {
		left = NULL;
		right = NULL;
		lpos = pos;
		rpos = pos;
		maxLen = value;
		leaf = true;
	}
};

class SegmentTree {
private:
	Node* root;
	vector<int> ones;
	vector<int> zeros;

	int query_helper(Node* node, int lpos, int rpos) {
		if(node->leaf) {
			return node->maxLen;
		}

		Node *left, *right;
		left = node->left;
		right = node->right;
		int m1, m2;
		if(rpos < right->lpos) {
			//printf("Going to left: %d %d\n", lpos, rpos);
			return query_helper(left, lpos, rpos);
		} else if(lpos > left->rpos) {
			//printf("Going to right: %d %d\n", lpos, rpos);
			return query_helper(right, lpos, rpos);
		} else if((lpos == left->lpos) && (rpos == right->rpos)) {
			//printf("Matched complete Node: %d %d, maxLen: %d\n", lpos, rpos, node->maxLen);
			return max(left->maxLen, right->maxLen);
		} else {
			//printf("Branching into: [%d,%d], [%d,%d]\n", lpos, left->rpos, right->lpos, rpos);
			m1 = query_helper(left, lpos, left->rpos);
			m2 = query_helper(right, right->lpos, rpos);
			return max(m1, m2);
		}
	}

public:
	SegmentTree(char* vals, int len) {
		queue<Node*> *q1, *q2, *qtmp;
		Node *n1, *n2, *n3;
		int val;
		int ocount = 0, zcount = 0;
		q1 = new queue<Node*>();
		q2 = new queue<Node*>();

		for(int i=0; i<len; i++) {
			if(vals[i] == '0') {
				zcount++;
			} else {
				ocount++;
			}

			zeros.push_back(zcount);
		}

		for(int i=0; i<len; i++) {
			ones.push_back(ocount);
			if(vals[i] == '1') {
				ocount--;
			}
		}

		for(int i=0; i<len; i++) {
			//cout << "ones[i]: " << ones[i] << "\tzeros[i]: " << zeros[i] << "\tSum: " << ones[i]+zeros[i] << endl;
			n1 = new Node(i, ones[i]+zeros[i]);
			q1->push(n1);
		}

		while(q1->size() != 1) {
			n1 = q1->front(); q1->pop();
			n2 = q1->front(); q1->pop();
			n3 = new Node(n1, n2);
			q2->push(n3);

			if(q1->size() == 0) {
				qtmp = q1;
				q1 = q2;
				q2 = qtmp;
			} else if(q1->size() == 1) {
				n3 = q1->front();
				q1->pop();
				q2->push(n3);
				qtmp = q1;
				q1 = q2;
				q2 = qtmp;
			}
		}

		root = q1->front();
	}

	int query(int lpos, int rpos) {
		int myAns = query_helper(root, lpos, rpos);
		if(lpos != 0) {
			myAns -= zeros[lpos-1];
		}

		if(rpos != zeros.size()-1) {
			myAns -= ones[rpos+1];
		}

		return myAns;
	}
};

int main() {
	int T, N, Q, lpos, rpos, ans;
	char input[100005];
	scanf("%d", &T);

	while(T--) {
		scanf("%d", &N);
		scanf("%s", input);
		scanf("%d", &Q);
		SegmentTree st(input, N);
		while(Q--) {
			scanf("%d %d", &lpos, &rpos);
			ans = st.query(lpos-1, rpos-1);
			printf("%d\n", ans);
		}
	}

	return 0;
}

/*

ACM International Collegiate Programming Contest, Asia-Amritapuri Site, 2012

Problem E: Sequence
Given a sequence S of '0' and '1' of length N, a subsequence of S is obtained by omitting some elements of S without changing the order of the remaining elements of S.

Given a subarray of a sequence S starting from some position 'a' and ending at some position 'b' (1 <= a <= b <= N), both inclusive, denoted by S(a,b), you have report the length of longest non-decreasing subsequence of S(a,b). By non-decreasing, we mean that a '0' never appears after a '1' in the subsequence.
Input (STDIN):

The first line contains T, the number of test cases. Then T test case follow, each test case being in the following format.
The first line contains N, the length of sequence S. The next line contains a string of 0's and 1's of length exactly N. The next line contains Q, which means that you have to answer Q queries. The next Q lines contain a pair of integers a,b (1 <= a <= b <= N), meaning that you have to report the length of longest non decreasing subsequence of S(a,b).
There is no blank line between test cases.
Output (STDOUT):

Output Q lines per test case, which is the answer for each query. Do not print a blank line between test cases.
Constraints:

1 <= T <= 10
1 <= N <= 100,000
1 <= Q <= 100,000
Sample Input:

1
13
0011101001110
6
1 13
4 13
1 9
6 9
3 3
6 10

Sample Output:

9
6
6
3
1
4

Explanation:

In the first query, the longest subsequence is formed by picking 1st,2nd,3rd,4th,5th,7th,10th,11th,12th digits of the sequence.
In the second query, you can pick the 6th, 8th, 9th, 10th, 11th and 12th digits.


*/