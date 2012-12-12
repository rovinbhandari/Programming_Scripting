#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long int stick[50001],box[50001][3];
int main()
{
	int t;
	long long int dlength,max;
	scanf("%d",&t);
	while(t--)
	{
		int l,m,n,i,count=0;
		scanf("%d%d",&l,&m);
		for(i=0;i<l;i++)
			scanf("%d",&stick[i]);
		max=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld %lld %lld",&box[i][0],&box[i][1],&box[i][2]);
			dlength=box[i][0]*box[i][0] + box[i][1]*box[i][1] + box[i][2]*box[i][2];
			if(dlength > max)
               max=dlength;			
		}
		for(i=0;i<l;i++)
			if((stick[i]*stick[i]) <= max)
				count++;
		printf("%d\n",count);		
	}
	return 0;
}
