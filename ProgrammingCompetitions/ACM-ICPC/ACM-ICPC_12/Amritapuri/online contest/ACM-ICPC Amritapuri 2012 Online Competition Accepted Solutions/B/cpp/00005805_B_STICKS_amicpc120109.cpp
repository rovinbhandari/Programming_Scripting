
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<sstream>
#include<cmath>
#include<list>
#include<stack>
#include<map>
#include<bitset>
#include<set>
#include<cstring>
using namespace std;
typedef long long ll;
int main()
{
    ll i,j,k,n,m,t,l,b,h;cin>>t;
    while(t--)
    {
      int count=0;
      cin>>n>>m;double len[n];for(i=0;i<n;i++)cin>>len[i];sort(len,len+n);
      double maxdia=0.0;
      double dia[m];for(i=0;i<m;i++){cin>>l>>b>>h;double d=sqrt(l*l+b*b+h*h);if(maxdia<d)maxdia=d;}
      for(i=n-1;i>=0;i--)
      {
         if(len[i]<=maxdia)break;
      }
      cout<<i+1<<endl;
    }
    return 0;
}
