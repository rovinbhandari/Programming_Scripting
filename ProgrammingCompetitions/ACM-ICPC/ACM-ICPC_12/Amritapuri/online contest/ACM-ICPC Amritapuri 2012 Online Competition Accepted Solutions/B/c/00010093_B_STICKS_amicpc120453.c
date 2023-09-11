#include<stdlib.h>
#include<stdio.h>

unsigned long int calc()
{	unsigned long int n,m,count=0;
	scanf("%lu %lu",&n,&m);
	unsigned long int *sticks=malloc(n*sizeof(unsigned long int));
	unsigned long int i,j;
	for (i=0;i<n;i++)
		scanf("%lu",&sticks[i]);
	unsigned long int *a=malloc(m*sizeof(unsigned long int)),*b=malloc(m*sizeof(unsigned long int)),*c=malloc(m*sizeof(unsigned long int));
	for (i=0;i<m;i++)
		scanf("%lu %lu %lu",&a[i],&b[i],&c[i]);
	unsigned long int maxi=0;
	for (j=0;j<m;j++)
	{	if (((a[j]*a[j])+(b[j]*b[j])+(c[j]*c[j]))>=maxi)
			maxi=((a[j]*a[j])+(b[j]*b[j])+(c[j]*c[j]));
	}
	for (i=0;i<n;i++)
	{	if (maxi>=(sticks[i]*sticks[i]))
		{	count++;
		}
		
	}
	return count;
}


int main()
{	int co,i;
	scanf("%d",&co);
	unsigned long int *count=malloc(co*sizeof(unsigned long int));
	/*scanf("%d %d",&n,&m);
	int sticks[n],i;
	for (i=0;i<n;i++)
		scanf("%d",&sticks[i]);
	int a[m],b[m],c[m],j;
	for (i=0;i<m;i++)
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
	for (i=0;i<n;i++)
	{	j=0;
		for (j=0;j<m;j++)
		{	if (((a[j]*a[j])+(b[j]*b[j])+(c[j]*c[j]))>=(sticks[i]*sticks[i]))
			{	count++;
				break;
			}
		}
	}*/
	for (i=0;i<co;i++)
	{	count[i]=calc();
	}
	for (i=0;i<co;i++)
	{	printf("%lu\n",count[i]);
	}
	return 0; 	
}
