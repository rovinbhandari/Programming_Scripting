#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdio>
#include<algorithm>
#include<list>
#include<queue>
#include<sstream>
#include<iterator>
#include<cmath>
#include<stack>

using namespace std;
typedef long long ll;

stringstream ss;
ll n,a;
ll x,y;
string s,s1;
vector<string> vs;
vector<int> v,v1,v2;
vector< vector<int> > vv;
map<string,int> m;
pair<map<string,int>::iterator,bool> ret;
map<string,int>::iterator it;

void solve(){
     ll r,g,b,w;
     r=g=b=w=0;
     for(int i=0;i<s.size();i++){
             if(s[i]=='R') r++;
             else if(s[i]=='G') g++;
             else if(s[i]=='B') b++;
             else if(s[i]=='W') w++;
     }
     if(r%2==0 && g%2==0 && b%2==0 && w%2==0) vs.push_back("YES");
     else vs.push_back("NO");
}
void load(){
     cin>>n;
     for(int i=0;i<n;i++){
             cin>>s;
             solve();
     }
}
int main(){
load();
solve();
for(int i=0;i<n;i++){
        cout<<vs[i]<<endl;
}
return 0;
}
