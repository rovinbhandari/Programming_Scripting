#include <stdio.h>
#include <stdlib.h>

int compare_function(const void *a,const void *b) 
{
unsigned long long *x = (int *) a;
unsigned long long *y = (int *) b;
return *x - *y;

}

int main()
{
	int tc,n,i,j,k,fi,fj,fk;
	unsigned long long l,h,sum,a[2000],count;

	scanf("%d",&tc);
	while(tc--)
	{
		fi=fj=fk=1;
		count=0;
		scanf("%d %llu %llu",&n,&l,&h);
		a[0]=-1;
		for(i=1;i<=n;i++)
		{
			scanf("%llu",a+i);
		}
		qsort(a,n+1,sizeof(unsigned long long),compare_function);

		//for(i=1;i<=n;i++) printf("%llu\n",a[i]);

		for(i=1;i<=n&&fi;i++)
		{
			fj=fk=1;
			if(a[i] >= h)
			{
				fi=0;fj=0; fk=0; 
				  
			}
			for(j=i+1;j<=n&&fj;j++)
			{
				fk=1;
				if((unsigned long long)a[i]+a[j]>=h)
				{
					fj=0;fk=0;
				}
				for(k=j+1;k<=n&&fk;k++)
				{
					sum = (unsigned long long)a[i]+a[j]+a[k];
					if(sum>h)
					{
						fk=0;
					}
					if(sum>=l && sum <=h)
					{
						//printf("%llu %llu %llu\n",a[i],a[j],a[k]);
						count++;
					}
			
				}
			}
		}
		
		printf("%llu\n",count);	
	}


return 0;
}	
