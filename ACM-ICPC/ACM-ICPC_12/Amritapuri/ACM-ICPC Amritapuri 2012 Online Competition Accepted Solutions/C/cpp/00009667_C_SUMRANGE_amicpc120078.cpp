
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
_ Problem :
_._._._._._._._._._._._._._._._._._._._._.*/

#include<algorithm>
#include<assert.h>
#include<bitset>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<map>
#include<memory.h>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

long long int V[1000][1000];
long long int a[1000];

int main()
{
                int t;
		cin>>t;
		while(t--)
		{
			long long int n,L,R;
			long long int sum=0;
			cin>>n>>L>>R;
			for(int i=0;i<n;i++)
                              cin>>a[i];
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					V[i][j]=a[i]+a[j];
			for(int i=0;i<n;i++)
				sort(V[i],V[i]+n);
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n-1;j++)
				{ 
                                     int left=j+1,right=n-1,middle=(left+right)/2,up=-1,down=-1,count=0;
				     while(left<=right)
				     {
                                          middle=(right+left)/2;
                                          if(V[j][middle]+a[i]>R)
					  {
						  right = middle - 1;
					  }
					  else
						  if(V[j][middle]+a[i]<=R)
						  {
					                  up = middle;
							  left = middle+1;
						  }
				     }
				     left = j+1;
				     right=n-1;
				     while(left<=right)
				     {
                                          middle=(right+left)/2;
                                          if(V[j][middle]+a[i]<L)
					  {
						  left = middle + 1;
					  }
					  else
						  if(V[j][middle]+a[i]>=L)
						  {
					                  down = middle;
							 right  = middle-1;
						  }
				     }
				     if(down != -1 && up != -1)
				     {
                                         sum += up-down+1;
				     }
				}
			}
			cout<<sum<<endl;
		}
	        return 0;
}

