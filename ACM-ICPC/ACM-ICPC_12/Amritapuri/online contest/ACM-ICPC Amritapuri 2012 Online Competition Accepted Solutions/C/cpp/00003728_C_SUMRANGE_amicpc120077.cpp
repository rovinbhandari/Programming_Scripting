// Author : Segment3

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<vector>
#include<map>
#define LLD long long int
#define MAX 1000000007
using namespace std;
int A[1002];

int bs1(int low,int high, int lval)
{
	int mid;
	int ans=-1;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(A[mid]==lval)
		{
			ans=mid;
			high=mid-1;
		}
		else
			if(A[mid]<lval)
			{
				low=mid+1;
			}
			else
			{
				ans=mid;
				high=mid-1;
			}
	}
	return ans;
}

int bs2(int low,int high, int hval)
{
	int mid;
	int ans=-1;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(A[mid]==hval)
		{
			ans=mid;
			low=mid+1;
		}
		else
			if(A[mid]<hval)
			{
				ans=mid;
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
	}
	return ans;
}

int main()
{
	int i,j,t,n,l,h;
	cin>>t;
	while(t--)
	{
	cin>>n>>l>>h;

	for(i=0;i<n;i++)
		cin>>A[i];
	sort(A,A+n);

	int idx1,idx2,c=0,s;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			s = A[i]+A[j];
			idx1 = bs1(j+1,n-1,l-s);
			idx2 = bs2(j+1,n-1,h-s);
			if(idx1 == -1 || idx2 == -1)
			{
				continue;
			}

			c+= idx2-idx1+1;
			

		}

	cout<<c<<endl;
	}

	return 0;

}
