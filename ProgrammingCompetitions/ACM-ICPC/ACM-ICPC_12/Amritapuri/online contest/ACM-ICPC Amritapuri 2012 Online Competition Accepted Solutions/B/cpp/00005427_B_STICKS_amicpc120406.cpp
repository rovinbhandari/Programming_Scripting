#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	long long int t,i,j,k,n,m,no,count,l[50005],dim[50005][3];
	scanf("%lld",&t);
//	cout<<t<<endl;
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
//		cout<<"inside";
		for(i=0;i<n;i++)
			scanf("%lld",&l[i]);
		long long max=0,ddd;
		for(i=0;i<m;i++)
		{
			for(j=0;j<3;j++)
				scanf("%lld",&dim[i][j]);
			ddd=sqrt(dim[i][0]*dim[i][0]+dim[i][1]*dim[i][1]+dim[i][2]*dim[i][2]);
			if(max<ddd)
				max=ddd;
		}
		count=0;
		for(i=0;i<n;i++)
		{
			if(l[i]<=max)
				count++;
		}
		printf("%lld\n",count);
				
	}
}
