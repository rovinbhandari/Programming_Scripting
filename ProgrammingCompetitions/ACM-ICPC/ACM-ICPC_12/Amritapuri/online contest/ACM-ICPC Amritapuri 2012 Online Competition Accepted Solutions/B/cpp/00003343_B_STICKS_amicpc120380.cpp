#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
typedef long long ll;

int main() {
	//freopen("in.cpp", "r", stdin); freopen("out.cpp", "w", stdout);
	
	int nt; scanf("%d", &nt); while(nt--) {
		int n,m;
		scanf("%d %d", &n, &m);
		ll w, b, l; ll st[n];
		REP(i,n) scanf("%lld", &st[i]);
		ll ma = 0;
		REP(i,m) {
			scanf("%lld %lld %lld", &w, &b, &l);
			ma = max(ma, w*w + b*b + l*l);
		}
		int ans = 0;
		REP(i,n) if(st[i]*st[i] <= ma) ans++;
		printf("%d\n", ans);
	}
	
	return 0;
}


