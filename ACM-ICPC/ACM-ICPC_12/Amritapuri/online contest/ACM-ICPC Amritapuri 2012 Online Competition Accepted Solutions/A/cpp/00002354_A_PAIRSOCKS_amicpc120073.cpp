
/* Author : Vamsi Kavala */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)	
#define mod 1000000007
#define MAXN 1000010

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;

int col[300];
int main(){
	int i,t;
	string s;
	scanf("%d",&t);
	while(t--){
		cin>>s;
		memset(col,0,sizeof(col));
		for(i=0;i<s.size();i++){
			col[s[i]]++;
		}
		int fl=0;
		for(i=0;i<299;i++){
			if(col[i]%2==1)
				fl=1;
		}
		if(fl){
			printf("NO\n");
		}
		else
			printf("YES\n");
	}
	return 0;
}
