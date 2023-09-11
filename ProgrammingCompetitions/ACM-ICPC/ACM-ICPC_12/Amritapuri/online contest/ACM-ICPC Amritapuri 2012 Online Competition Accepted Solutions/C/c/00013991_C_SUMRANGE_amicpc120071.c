
//AUTHOR : Mallipeddi Hardhik 

#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}
int main()
{
	int test;
	scanf("%d",&test);
	int N,L,H;
	int i,j,k,x;
	while(test--)
	{
		scanf("%d %d %d",&N,&L,&H);
		int a[N];
		for(i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
		}
		int count=0;
		qsort(a,N,sizeof(int),compare);
		for(i=0;i<N;i++)
		{
			for(j=i+1;j<N;j++)
			{
				for(k=j+1;k<N;k++)
				{
					x=a[i]+a[j]+a[k];
					if(x<=H && x>=L)
					{
						count++;
					}
					else if(x>H)
						break;
				}
			}
		}
		printf("%d\n",count);

	}
	return 0;
}



