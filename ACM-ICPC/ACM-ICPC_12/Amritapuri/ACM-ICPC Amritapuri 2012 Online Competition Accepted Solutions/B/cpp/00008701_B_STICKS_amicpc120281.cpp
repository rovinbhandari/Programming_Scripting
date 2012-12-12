#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
	int t,n,m,l,b,h,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		double big,x; // biggest stick
		vector<double >stick(n);
		for(i=0;i<n;i++)
		{
			scanf("%lf",&x);
			stick[i]=x;
		}
		sort(stick.begin(),stick.end());
		double arr[5];
		big=0.0;
		for(i=0;i<m;i++)
		{
			scanf("%lf %lf %lf",&arr[0],&arr[1],&arr[2]);
			arr[3]=sqrt((arr[0]*arr[0])+(arr[1]*arr[1]));
			arr[4]=sqrt((arr[3]*arr[3])+(arr[2]*arr[2]));
			sort(arr,arr+5);
			if(big<arr[4])
				big=arr[4];
		}
		vector<double>:: iterator it;
		vector<double>:: iterator it1;
		it1=stick.begin();
		it=upper_bound(stick.begin(),stick.end(),big);
		int ans=it-it1;
		cout<<ans<<endl;
	}
return 0;
}

