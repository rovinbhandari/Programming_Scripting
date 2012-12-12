#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int T, N, M;
long long L[50000];
long long V, maximum;

int main() {
	cin>>T;
	int counter = 0;
	while(T--) {
		counter = 0;
		maximum = -1;
		cin>>N>>M;
		for(int i=0; i<N; i++) {
			cin>>L[i];
		}
		
		long long x, y, z;
		for(int i=0; i<M; i++) {
			cin>>x>>y>>z;
			V = floor(sqrt((x*x) + (y*y) + (z*z)));
			if(maximum < V)
				maximum = V;
		}
		
		for(int i=0; i<N; i++) {
			if(L[i] <= maximum) {
				counter++;
			}
		}
		//cout<<maximum<<endl;
		cout<<counter<<endl;
	}
}
