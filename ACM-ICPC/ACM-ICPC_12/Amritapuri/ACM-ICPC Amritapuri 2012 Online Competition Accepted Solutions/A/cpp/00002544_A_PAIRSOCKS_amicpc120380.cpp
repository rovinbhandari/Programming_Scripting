#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
typedef long long ll;

int main() {
	
	int nt; scanf("%d", &nt); while(nt--) {
		string s; cin >> s;
		int a[4] = {0};
		REP(i,s.size()) {
			switch(s[i]) {
				case 'R': a[0]++; break;
				case 'G': a[1]++; break;
				case 'B': a[2]++; break;
				case 'W': a[3]++; break;
			}
		}
		bool ok = 1;
		REP(i,4) if(a[i] % 2) ok = 0;
		if(ok)
			printf("YES\n");
		else 
			printf("NO\n");
		
	}
	
	return 0;
}
