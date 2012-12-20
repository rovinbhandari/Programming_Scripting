#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

#define FOR(i, n) for(i=0;i<n;++i)
#define FORD(i, n) for(i=n-1;i>=0;--i)
#define S(T) scanf("%d", &T)
#define SL(T) scanf("%lld", &T)
#define fill(a, val ,count) memset(a, val, count*sizeof(a))
#define SORT(x,n) sort(x,x+n)
#define SORTD(x,n) sort(x,x+n,std::greater<int>())

int main()
{
	int n,t,i,j,k;
	char a[100001];
	int b[26];
	//freopen("in.txt","r",stdin);
	
	S(t);
	
	while(t--) {
		scanf("%s",a);
		int flag = 0;
		FOR(i,26){
		
			b[i]=0;
		}
		FOR(i,strlen(a)) {
			b[a[i] - 65]++;
				
		}
		FOR(i,26) {
			if(b[i]!=0 && b[i]%2 == 1)
				flag = 1;
				
		}
		if(flag == 0)
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
		
		
	}
	
	return 0;
}
