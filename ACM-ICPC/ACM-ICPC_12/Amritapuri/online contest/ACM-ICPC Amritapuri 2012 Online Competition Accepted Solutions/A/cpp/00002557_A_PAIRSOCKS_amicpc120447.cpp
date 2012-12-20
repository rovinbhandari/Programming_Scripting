
/*
Dinesh Reddy
National Institute of Technology,Warangal.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <sstream>
#include <list>
#include <map>
#include <queue>
#include <stack>

#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define print(x) cout<<#x<<" is "<<x<<endl;
#define inf 2000000000
#define Pair pair<int,int>
#define eps 1e-8

char s[1000000];

using namespace std;

int main(){
	int r=0,b=0,g=0,w=0;
	int t;
	cin>>t;
	while(t--)
	{
		r=0,b=0,g=0,w=0;
		cin>>s;
		int n=strlen(s);
		for(int i=0;i<n;i++)
		{
			if(s[i]=='R')
				r++;
			if(s[i]=='B')
				b++;
			if(s[i]=='G')
				g++;
			if(s[i]=='W')
				w++;
		}
		if(r%2!=0 || g%2!=0 || b%2!=0 || w%2!=0)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
