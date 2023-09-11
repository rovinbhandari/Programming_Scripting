/*Sum Range*/

#include<cstdio>
#include<algorithm>

using namespace std;

int a[1001];

int main()
{
	int count,i,j,H,highindex,key,L,lower,lowindex,middle,N,T,upper;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&N,&L,&H);
		for(i=0;i<N;i++)
			scanf("%d",&a[i]);
		sort(a,a+N);
		count=0;
		for(i=0;i<N;i++)
		{
			for(j=i+1;j<N;j++)
			{
				key=L-a[i]-a[j];
				lower=j+1;
				upper=N-1;
				while(lower<=upper)
				{
					middle=(lower+upper)/2;
					if(key>a[middle])
						lower=middle+1;
					else if(key<a[middle])
						upper=middle-1;
					else
						break;
				}
				if(upper<lower)
					lowindex=lower;
				else
					lowindex=middle;
				key=H-a[i]-a[j];
				lower=j+1;
				upper=N-1;
				while(lower<=upper)
				{
					middle=(lower+upper)/2;
					if(key>a[middle])
						lower=middle+1;
					else if(key<a[middle])
						upper=middle-1;
					else
						break;
				}
				if(upper<lower)
					highindex=upper;
				else
					highindex=middle;
				count+=highindex-lowindex+1;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}