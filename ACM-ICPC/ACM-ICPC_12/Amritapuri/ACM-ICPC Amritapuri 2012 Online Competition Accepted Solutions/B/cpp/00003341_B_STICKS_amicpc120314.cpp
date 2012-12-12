#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;
#define gc getchar_unlocked
typedef long long int int64;
void scanint(int64 &x)
{
    register int64 c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int64 i,j,k,n,m,t,a,c,b,st[100001],ma,mb,mc,ans,mh,h;
cin>>t;
while(t--)
{
cin>>n>>m;
ma = mb = mc = mh = -1;ans = 0;
for(i=0;i<n;i++){scanf("%lld",&st[i]);}
for(i=0;i<m;i++){scanf("%lld %lld %lld",&a,&b,&c);if(a>ma)ma=a;if(b>mb)mb=b;if(c>mc)mc=c;
h = sqrt((a*a)+(c*c)+(b*b));
if(h>mh)mh = h;
}
for(i=0;i<n;i++){if(st[i]<=ma||st[i]<=mb||st[i]<=mc||st[i]<=mh)ans++;}
cout<<ans<<endl;
}
return 0;
}

