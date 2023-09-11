#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <deque>
#include <complex>

using namespace std;

#define Max 1000000009
#define f(i,k,n) for(int i = k;i < n;i++)
#define pb push_back
#define W while

typedef long long int ll;
typedef vector<int> vi;
typedef set<int> si;
ll A[60000];

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
	    
	    f(i,0,n){scanf("%lld", &A[i]);A[i] = A[i]*A[i];}
	    ll mx = 0;
	    f(i,0,m){
	    	ll a,b,c;
	    	scanf("%lld %lld %lld",&a,&b,&c);
	    	mx = max(mx,a*a+b*b+c*c);
	    }
	    sort(A, A + n);
	    ll *x = upper_bound(A, A + n, mx);
	    int cnt = (int)(x - A);
	    cout << cnt << endl;
	}
}

