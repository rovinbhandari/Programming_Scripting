#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

int main()
{
	int cases=0;
	scanf("%d",&cases);

	for(int t=0;t < cases;t++)
	{
		int n,m;
		scanf("%d%d",&n,&m);

		int l[n];

		for(int i=0;i < n;i++)
		{
			scanf("%d",&l[i]);
		}

		float a,b,c;

		double max=0,temp;

		scanf("%f%f%f",&a,&b,&c);

		max=sqrt(a*a + b*b + c*c);

		for(int i=1;i < m;i++)
		{		
			scanf("%f%f%f",&a,&b,&c);
			temp=sqrt(a*a + b*b + c*c);

			if(temp >= max)
			{
				max=temp;
			}
		}

		//cout<<max<<endl;

		int count=0;
		for(int i=0;i < n;i++)
		{
			if(max >= l[i])
			{
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0; 
}
