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
	while(t--)
	{
		int n,m;
		long long int max=0;
		cin>>n>>m;
		long long int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		for(int i=0;i<m;i++)
		{
			long long int x,y,z;
			cin>>x>>y>>z;
			if( (x*x + y*y + z*z) > max )
			{
				max=x*x+y*y+z*z;
			}
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]*arr[i]<=max)
				count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
			
