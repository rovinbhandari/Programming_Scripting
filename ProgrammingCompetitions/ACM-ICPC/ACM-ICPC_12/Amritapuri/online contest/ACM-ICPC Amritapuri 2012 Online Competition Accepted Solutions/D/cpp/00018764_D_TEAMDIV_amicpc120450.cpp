#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<utility>
#include<set>
#define mod 1000000007
typedef long long LL;
using namespace std;

LL powmod(int a,int b){
long long x=1,y=a;
while(b > 0){
if(b%2 == 1){
x=(x*y)%mod;
}
y = (y*y)%mod; // squaring the base
b /= 2;
}
return x;
}
int main()
{
int t;
cin>>t;
while(t--)
{
int n,k,kkk;
cin>>n;
set<int> weight[n];
set<int>::iterator it;
for(int i=0;i<n;i++)
{
scanf("%d",&k);
while(k--)
{
scanf("%d",&kkk);
weight[i].insert(kkk);
weight[kkk].insert(i);
}
}
int visited[n];
for(int i=0;i<n;i++)
visited[i] = 0;
int num = 0;
for(int i=0;i<n;i++)
{
if(visited[i]==0)
{
num++;
visited[i] = 1;
queue<int> BFS;
BFS.push(i);
while(!BFS.empty())
{
kkk = BFS.front();
BFS.pop();
for(it =weight[kkk].begin();it!=weight[kkk].end();it++)
{
if(visited[*it]==0)
{
visited[*it] = -visited[kkk];
BFS.push(*it);
}else if(visited[*it] == visited[kkk])
{
num = 0;

while(!BFS.empty())
BFS.pop();
i = n+1;
break;
}
}
}
}
}
if( num == 0 )
cout << 0 << endl ;
else
cout<<powmod(2,num)<<endl;

}
}
