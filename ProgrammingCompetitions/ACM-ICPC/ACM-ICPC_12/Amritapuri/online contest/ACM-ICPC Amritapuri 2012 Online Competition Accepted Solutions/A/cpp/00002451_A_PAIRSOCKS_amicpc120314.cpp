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
int64 i,j,k,n,m,t,c1,c2,c3,c4;
cin>>t;
char a[1000];
while(t--)
{
cin>>a;c1 = c2 = c3 = c4 = 0;
for(i=0;i<strlen(a);i++)
	{
	if(a[i]=='R')c1++;
	if(a[i]=='G')c2++;
	if(a[i]=='W')c3++;
	if(a[i]=='B')c4++;
	}
if((c1%2==0)&&(c2%2==0)&&(c3%2==0)&&(c4%2==0))
cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
return 0;
}

