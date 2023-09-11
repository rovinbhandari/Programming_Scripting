#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

#define FOR(i,k) for(int i=0; i<k; i++)
#define DFOR(i,k) for(int i=0; i<=k; i++)
#define RFOR(i,k) for(int i=k-1; i>=0; i--)

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		int r=0,g=0,b=0,w=0;
		string a;
		cin>>a;
		for(int i=0; i<a.size(); i++) {
			switch(a[i]) {
			case 'R': r++;  break;
			case 'G': g++; break;
			case 'B': b++; break;
			case 'W': w++; break;
			}
			g=g%2;
			b=b%2;
			w=w%2;
			r=r%2;
		}
		if(r==1||g==1||b==1||w==1) {
				printf("NO\n");
		}
		else {
				printf("YES\n");
		}
	}
	return 0;
}
//nCKSH4