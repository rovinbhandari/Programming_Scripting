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

#define s1(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int main(){
	int nt;
	cin>>nt;
	while(nt--){
	string s;
	cin>>s;
	int n = s.size();
	map<char, int> M;
	fr(i, n) M[s[i]]++;
	if (M['R']%2 || M['G']%2 || M['B']%2 || M['W']%2) cout<<"NO\n";
	else cout<<"YES\n";
	}
}