#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#define N 100000
using namespace std;

typedef long long LL;
int main()
{
int t,m,n;LL sticks[N];
cin>>t;
while(t--)
{
	LL l,b,h,cnt=0,x=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){cin>>sticks[i];}
	while(m--)
	{
	cin>>l>>b>>h;
	LL p=(LL)sqrt(l*l+b*b+h*h);
	x=max(x,p);
    }
    for(int i=0;i<n;i++){if(sticks[i]<=x)cnt++;}
    cout<<cnt<<'\n';
}
return 0;
}
