#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;
int a[50001];//int b[50001];
void pre(){

}
int main(){
	//freopen("input","r",stdin);
	//freopen("output","w",stdout);
	int t,c,d,e,f,n,m;
	int res=0,cnt=0;
	vector<int> v;
	cin>>t;string s;
	for(int i=0;i<t;i++){
		cin>>s;
		int r=0,g=0,b=0,w=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='R')r++;
			else if(s[i]=='G')g++;
			else if(s[i]=='B')b++;
			else if(s[i]=='W')w++;
		}
		if(r%2==0&&g%2==0&&b%2==0&&w%2==0)cout<<"YES\n";
		else cout<<"NO\n";
	}
	/*for(int i=0;i<m;i++){
		cin>>b[i];
	}*/
	return 0;
}
