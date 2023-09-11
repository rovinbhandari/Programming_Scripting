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
	scanf("%d",&t);
	while(t--){
		string s;
		cin>>s;
		int f=0;
		sort(s.begin(),s.end());
		for(int i=0;i<s.size();i+=2){
			if(s[i]!=s[i+1]){
				cout<<"NO"<<"\n";
				f=1;break;
			}
		}
		if(f==0)cout<<"YES"<<"\n";
	}
	return 0;
}

