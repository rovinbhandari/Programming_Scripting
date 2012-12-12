#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long findMax(long a, long b,long c)
{
	if(a>b)
	{
		if(a>c)
			return a;
		else 
			return c;
	}
	else if(b>c)
		return b;
	else
		return c;	
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long n,m,i,j;
		long l[100000],a[50000],b[50000],c[50000];
		long count=0;
		scanf("%ld %ld",&n,&m);
		long maxHeight[50000]; 
		long Max=0,pos=0,maxcount=0;
		bool used[50000];
		bool alreadyUsed=false;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&l[i]);
		}
		for(j=0;j<m;j++)
		{
			scanf("%ld %ld %ld",&a[j],&b[j],&c[j]);
			maxHeight[j] = sqrt(a[j]*a[j]+b[j]*b[j]+c[j]*c[j]);
			if(maxHeight[j]>Max)
			{
				Max=maxHeight[j];	
				pos=j;
				maxcount=1;
			}
			else if(maxHeight[j]==Max)
			{
				maxcount++;
			}
		}		
		
		for(i=0;i<n;i++)
		{
			if(l[i]>Max)
			{
				continue;
			}
			else if(l[i]==Max && maxcount>=1)
			{
				count++;
				maxcount--;
			}	
			else
			{
				count++;
			}
/*						
			for(j=0;j<m;j++)
			{
				if(l[i]<maxHeight[j])
				{
					count++;
					break;
				}
				else if(l[i]==maxHeight[j])
				{
					if(!used[j])
					{
						count++;
						used[j]=true;
						break;
					}
				}	
			}			
*/
		}
		printf("%ld\n",count);
	}
	return 0;
}
