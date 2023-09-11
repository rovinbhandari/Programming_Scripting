//TEAM_AK

#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<climits>
#include<algorithm>
#include<sstream>
#include<queue>
#include<stack>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define pb push_back
#define mp make_pair
#define pi acos(-1)

using namespace std;

unsigned long long mod=1000000007;

int main() {
	int t;
	cin>>t;
	while(t--){
		long long n,m;
		scanf("%lld %lld",&n,&m);
		long long arr1[n];
		//int arr2[n];
		//	memset(arr2,0,sizeof arr2);
		for(int i=0;i<n;i++)scanf("%lld",&arr1[i]);
		long long maxi=0;
		int cnt=0;
		for(int i=0;i<m;i++){
			long long int a,b,c;
			scanf("%lld %lld %lld",&a,&b,&c);
			long long tmp=((a*a)+(b*b)+(c*c));
			maxi=max(tmp,maxi);
			}			
		for(int i=0;i<n;i++){
				if(maxi>=(arr1[i]*arr1[i])){
						cnt++;//arr2[i]=1;
				}
		}
		cout<<cnt<<"\n";
		getchar();
	}
	return 0;
}

