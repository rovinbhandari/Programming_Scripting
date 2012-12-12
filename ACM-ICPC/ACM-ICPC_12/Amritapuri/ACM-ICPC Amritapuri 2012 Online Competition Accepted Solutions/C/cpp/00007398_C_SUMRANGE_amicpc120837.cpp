#include <cstdio>
#include <algorithm>
using namespace std;
#define SIZE 1010
int T;
int N,L,H;
int array[SIZE];
int main()
{
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		scanf("%d %d %d",&N,&L,&H);
		int sum=0;
		for(int i=0;i<N;i++)
			scanf("%d",array+i);
		sort(array,array+N);
		for(int i=0;i<N;i++)
			for(int j=i+2;j<N;j++)
			{
				if ((array[i]+array[j-1]+array[j])<L)
					continue;
				
				else if ((array[i]+array[i+1]+array[j])>H)
					continue;
				//printf("%d %d\n",i,j);
				int pairsum=array[i]+array[j];
				int small=L-pairsum;
				int large=H-pairsum;
				int left=i+1;
				int right=j;
				int smallmid,highmid;
				while(left<=right)
				{	
					smallmid=(left+right)/2;
					if ((array[smallmid]+pairsum>=L)&&(smallmid==i+1||(array[smallmid-1]+pairsum<L)))
						break;
					else if (array[smallmid]>small)
						right=smallmid;
					else
						left=smallmid;
				}
				left=i+1;
				right=j;
				while(left<=right)
				{	
					highmid=(left+right)/2;
					if ((array[highmid]+pairsum<=H)&&(highmid==j-1||(array[highmid+1]+pairsum>H)))
						break;
					else if (array[highmid]<large)
						left=highmid;
					else
						right=highmid;
				}
				if (smallmid<=highmid)
				{
					sum+=highmid-smallmid+1;
			 	}
				
			}
	
		printf("%d\n",sum);	

	}
	return 0;
}
