#include <iostream>
#include<ctype.h>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<iterator>
#include<cmath>

using namespace std ;

#define FOR(i,a,b) for(int i= (int)a; i< (int)b; ++i)
#define REP(i,n) FOR(i,0,n)

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		//LL a[1005];
		double *low,*up;
		int n;
		scanf("%d",&n);
		double v[n];
		LL l,h;
		scanf("%lld %lld",&l,&h);
		REP(i,n)
		{
			scanf("%lf",&v[i]);
		}
		int k=0;
		sort(v,v+n);
		LL c=0;
		FOR(i,0,n-1)
		{
			FOR(j,i+1,n)
			{
				LL sum = v[i] + v[j];
				double L = l - sum-0.5;
				double U = h - sum+0.5;
				//cout<<"ARR ";
				//for(int k=0;k<n;k++)
				//	cout<<v[k]<<" ";
				//cout<<endl;
				int low_pos;
				{
					int left=j+1,right=n-1;
					bool found=false;
					double no=U;
					while(left<=right)
					{
						int mid=(left+right)/2;
						//if(v[mid]==no)
						//{found=true;break;}
						if(no<=v[mid])
							right=mid-1;
						else 
							left=mid+1;
					}
					low_pos=left;
				}
				//low=lower_bound (v, v+n, U); //   
				//low_pos = int(low-v);
				if(v[low_pos]!=h)
					low_pos--;


                                int up_pos;
				{
					int left=j+1,right=n-1;
					bool found=false;
					double no=L;
					while(left<=right)
					{
						int mid=(left+right)/2;
						//if(v[mid]==no)
						//{found=true;break;}
						if(no<v[mid])
							right=mid-1;
						else 
							left=mid+1;
					}
					up_pos=left;
				}
			
				//up= upper_bound (v, v+n, L-1); //
				//up_pos = int(up-v);
				int range=0;
				if(low_pos>=up_pos)
					range = low_pos - up_pos +1;
				//cout << up_pos << " " << low_pos << endl;
				//if(i<= low_pos && i>=up_pos)
				//range--;
				if(j<= low_pos && j>=up_pos)
				{
					range-=(j-up_pos+1);
				}
				else if(j>low_pos)
					range=0;
				//cout << "range " << range << endl;
				c+=range;
			}
		}
		cout << c << endl;
	}
	return 0;
}
