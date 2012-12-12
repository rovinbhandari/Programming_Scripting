#include<stdio.h>
#include<math.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,M,count=0;
		scanf("%d%d",&N,&M);
		int x,s[N];
		for(x=0;x<N;x++)
		{
			scanf("%d",&s[x]);
		}
		int  b[M][3],q,w,e,sum=0;
		double sqr,an,prev,r;
		for(x=0;x<M;x++)
		{
			scanf("%d%d%d",&b[x][0],&b[x][1],&b[x][2]);
			sqr=(double)(b[x][0]*b[x][0]) +(double) (b[x][1]*b[x][1]) + (double)(b[x][2]*b[x][2]);
			if(x==0)
			{
				q=b[x][0];
				w=b[x][1];
				e=b[x][2];
				prev=(double)(b[x][0]*b[x][0]) +(double) (b[x][1]*b[x][1]) + (double)(b[x][2]*b[x][2]);
			}
			else
			{

				if(sqr>prev)
				{
					q=b[x][0];
					w=b[x][1];
					e=b[x][2];
					prev=sqr;
				}
			}
		}
		for(x=0;x<N;x++)
		{
			if((double)s[x]*s[x]<=prev)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}



