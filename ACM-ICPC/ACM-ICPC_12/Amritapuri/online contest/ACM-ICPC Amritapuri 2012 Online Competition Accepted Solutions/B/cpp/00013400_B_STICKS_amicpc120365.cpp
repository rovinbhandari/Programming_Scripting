#include<stdio.h>
#include<algorithm>
#define max(a,b) (a>b)?a:b
using namespace std;
long long l[50001],a,b,c;
int main()
{
    long long n,m,t,i,j,count,ans;
	long long diag,maxd;
	scanf("%lld",&t);
	while(t--)
	{
		int k=0;
		int count=0,c1=0;
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&l[i]);
		}
		maxd=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&c);
			diag=(a*a)+(b*b)+(c*c);
			if(diag>maxd)
			{
			    maxd=diag;
			}
		}
		ans=n;
        for(i=n-1;i>=0;i--)
        {
            if(l[i]*l[i]>maxd)
            {
                ans--;
            }
        }
        printf("%lld\n",ans);
	}
}


