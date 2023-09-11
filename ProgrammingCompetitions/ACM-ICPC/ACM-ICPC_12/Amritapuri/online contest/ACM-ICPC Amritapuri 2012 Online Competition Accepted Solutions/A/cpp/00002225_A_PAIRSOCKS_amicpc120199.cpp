#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<deque>
using namespace std;

int main(){
   //freopen("input.in","r",stdin);
   //freopen("output.out","w",stdout);
   int t;
   scanf("%d",&t);
   while(t--){
      string s;
      cin>>s;
      int r,g,b,w;
      r=g=b=w=0;
      for(int i=0;i<s.length();i++){
        if(s[i]=='R')r++;
        if(s[i]=='G')g++;
        if(s[i]=='B')b++;
        if(s[i]=='W') w++;
      }
      if(r%2==0&&g%2==0&&b%2==0&&w%2==0)cout<<"YES\n";
      else cout<<"NO\n";
   }
   return 0;
}
