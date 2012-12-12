/*Sticks*/

#include<cstdio>

using namespace std;

int stick[50000];

int main()
{
	int b,count,h,i,l,M,N,T;
	long long diagonal,maxdiagonal;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);
		for(i=0;i<N;i++)
			scanf("%d",&stick[i]);
		maxdiagonal=-1;
		for(i=0;i<M;i++)
		{
			scanf("%d %d %d",&l,&b,&h);
			diagonal=(long long)l*l+b*b+h*h;
			if(maxdiagonal<diagonal)
				maxdiagonal=diagonal;
		}
		count=0;
		for(i=0;i<N;i++)
			if((long long)stick[i]*stick[i]<=maxdiagonal)
				count++;
		printf("%d\n",count);
	}
	return 0;
}