//Author : aitch_nu

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<set>

using namespace std;

int main()
{
	int t;
	cin>>t;
	int arr[1024];
	while(t--)
	{
		int n,l,h;
		scanf("%d%d%d",&n,&l,&h);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		int low , up;
		bool checkup = true;
		bool checklow = true;
		if ( arr[n-1] + arr[n-2] + arr[n-3] <= h )
		{	checkup = false;
			up = n - 1;
		}
		if ( arr[0] + arr[1] + arr[2] >= l )
		{
			checklow = false;
			low = 0;
		}
		int sum=0;
		for(int i=0;i<n;i++)
		{
			low=0;
			for(int j=i+1;j<n;j++)
			{
				if ( checklow ) 
					low=lower_bound(arr,arr+n,l-arr[i]-arr[j]) - arr;
				if ( checkup )	
					up=upper_bound(arr,arr+n,h-arr[i]-arr[j]) -arr-1;
				if(low<=j)
					low=j+1;
				if(low>=n)
					break;
				//cout<<"low "<<low<<" "<<up<<endl;
				if(up>j)
				{
					sum=sum+up-low+1;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
