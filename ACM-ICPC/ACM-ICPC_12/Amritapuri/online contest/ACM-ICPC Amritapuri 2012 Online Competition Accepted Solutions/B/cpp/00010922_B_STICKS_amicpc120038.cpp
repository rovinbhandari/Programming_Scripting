#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int maxsticks(vector <long> &A, vector <long> &B, vector <long> &C, vector <int> &L)
{
	long maxlen = 0;
	for (int i = 0; i < A.size(); i++)
	{
		long temp = A[i]*A[i] + B[i]*B[i] + C[i]*C[i];
		temp = (long) sqrt (temp);
		if (temp > maxlen)
			maxlen = temp;
	}
	int count = 0;
	for (int i = 0; i < L.size(); i++)
		if (L[i] <= maxlen)
			count++;
	return count;
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		vector <long> A;
		vector <long> B;
		vector <long> C;
		vector <int> L;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			L.push_back(temp);
		}
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			A.push_back(a);
			B.push_back(b);
			C.push_back(c);
		}
		cout << maxsticks(A, B, C, L) << '\n';
	}
}
