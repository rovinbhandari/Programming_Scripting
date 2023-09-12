#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int A[1001];


int main(){
	int nt, n, l, h;
	cin>>nt;
	while(nt--){
		s(n); s(l); s(h);
		fr(i, n) sll(A[i]);
	
	sort(A, A + n);
	int res = 0;
	fr(i, n) f(j, i+1, n){int x = A[i] + A[j];
		int * y1 = lower_bound(A+j+1, A+n, l-x);
		int * y2 = upper_bound(A+j+1, A+n, h-x);
		res += max(0, (int)(y2 - y1));
	}
	cout<<res<<endl;
	}
	return 0;
}