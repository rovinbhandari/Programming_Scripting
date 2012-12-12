#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{

	int t;long long int n,m;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%lld %lld",&n,&m);
	long long int l[n+1];
	for(long long int i=0;i<n;i++)scanf("%lld",&l[i]);
    long long int l1,b1,h1;
    double diag,max_diag=0;

	for(long long int i=0;i<m;i++)
	{
    scanf("%lld %lld %lld",&l1,&b1,&h1);
	diag=sqrt(l1*l1+b1*b1+h1*h1);
	if(diag>max_diag)max_diag=diag;
	}
	long long int cnt=0;
	for(long long int i=0;i<n;i++)if(l[i]<=max_diag)cnt++;
	printf("%lld\n",cnt);

	}
return 0;
}
