#include <cstdio>
#include <cstring>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;
typedef long long LL;
#define MOD 1000000007
const int maxN =20002;

vector<long> a[maxN];
int mark[maxN];
int visited[maxN];
int color[maxN];
int cmp;
/*LL powmod( LL b, LL p,LL m )
{
LL r = 1;
for( int i = ( 1 << 30 ); i; i >>= 1 )
{
r *= r; r %= m;
if( p & i ) { r *= b; r %= m; }
}
return (LL)r;
}*/
LL powmod(int a,int b,LL c){
long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
while(b > 0){
if(b%2 == 1){
x=(x*y)%c;
}
y = (y*y)%c; // squaring the base
b /= 2;
}
return x;
}
int bfs(int u)
{
int flag=1;
visited[u]=1;
color[u]=1;
queue<int > Q;
Q.push(u);
while(!Q.empty())
{
u=Q.front();
Q.pop();

for(int i=0;i<a[u].size();i++)
{ int v=a[u][i];
if(color[v]==color[u])
flag=0;
if(visited[v]==0)
{ visited[v]=1;
color[v]=3-color[u];
Q.push(v);
}
else
{
if(color[v]==color[u])
flag=0;
}


}
}
return flag;
}
int main()
{
int TST;
scanf("%d",&TST);
for(int tst=0;tst<TST;tst++)
{
long n,m;
long b;
cin>>n;
if(n==0)
{
cout<<"0\n";
continue;
}

else
{
long i,u,v;
for(i=0;i<n;i++) a[i].clear();
for(long i=0;i<n;i++){
cin>>m;
for(long k=0;k<m;k++)
{
cin>>b;
a[i].push_back(b);
a[b].push_back(i) ;

}
}
for(int i=0;i<n;i++)
{
visited[i]=0;
color[i]=0;
}

cmp=0;
//bool flag = true ;
for(i=0;i<n;i++)
if(!visited[i])
{

if(bfs(i))
cmp++;
else
{cmp=0;break;}


}
//cout<<cmp<<endl;
if(cmp != 0 )
{LL ans=powmod(2,cmp,MOD);
cout<<ans<<endl;}
else
cout << 0 << endl ;
//END :: ;
}
}
return 0;
}
