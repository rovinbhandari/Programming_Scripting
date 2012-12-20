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

int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int64 i,j,k,n,m,t,s,d,ref[20005],fl =0,ng,u,ans;
cin>>t;
while(t--)
{
vector < vector <int64> > v(20001,vector<int64>());
cin>>n;
for(i=0;i<n;i++)
	{
	scanf("%lld",&k);
	for(j=0;j<k;j++){scanf("%lld",&d);v[i].push_back(d);v[d].push_back(i);}
	}
for(i=0;i<=n;i++)ref[i] = -1;
queue <int64> q;ng = 0;fl = 0;
for(i=0;i<n;i++){
if(ref[i]==-1){
ng++;
ref[i] = 0;
q.push(i);
while(!q.empty())
	{
	u = q.front();q.pop();
	for(i=0;i<v[u].size();i++)
		{
		d = v[u][i];
		if(ref[d]==-1){ref[d] = !ref[u];q.push(d);}
		else if(ref[d]==ref[u])fl = 1;
		}
	}
}
}
if(fl==0)
	{
	ans = 1;
	for(i=0;i<ng;i++)ans = (ans*2)%1000000007;
	printf("%lld\n",ans);	
	}
else cout<<"0"<<endl;
}
return 0;
}

