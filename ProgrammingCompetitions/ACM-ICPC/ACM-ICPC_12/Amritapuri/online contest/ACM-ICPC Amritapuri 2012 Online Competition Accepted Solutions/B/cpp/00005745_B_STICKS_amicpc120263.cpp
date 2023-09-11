#include<stdio.h>
#include<math.h>
#include<cmath>
using namespace std;
int main()
{
long long int m,n,t,temp,max,count,i,j,a[50005],b[50005],c[50005],l[100005];
scanf("%lld",&t);
while(t--)
  {scanf("%lld %lld",&n,&m);
   for(i=0;i<n;++i)
	{scanf("%lld",&l[i]);
	}
   for(j=0;j<m;++j)
	{scanf("%lld %lld %lld",&a[j],&b[j],&c[j]);
	}
   temp=(a[0]*a[0])+(b[0]*b[0])+(c[0]*c[0]);
   a[0]=sqrt(temp);
   max=a[0];
   for(j=1;j<m;++j)
	{temp=(a[j]*a[j])+(b[j]*b[j])+(c[j]*c[j]);
	a[j]=sqrt(temp);
	if(a[j]>max) max=a[j];
	}
   count=0;
   for(i=0;i<n;++i)
	{if(l[i]<=max) count++;
	}
  printf("%lld\n",count);
  }
return 0;
}