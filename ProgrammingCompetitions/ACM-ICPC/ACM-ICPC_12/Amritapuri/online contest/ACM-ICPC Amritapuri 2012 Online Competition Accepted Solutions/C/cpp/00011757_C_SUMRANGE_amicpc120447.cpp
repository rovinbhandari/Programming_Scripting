
/*
Dinesh Reddy
National Institute of Technology,Warangal.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <sstream>
#include <list>
#include <map>
#include <queue>
#include <stack>

#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define print(x) cout<<#x<<" is "<<x<<endl;
#define inf 2000000000
#define Pair pair<int,int>
#define eps 1e-8

using namespace std;

int n,l,h;
vector<int> a;

int main(){
	int t,temp,sum;
	int ans,lower,higher;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>l>>h;
		a.clear();
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			if(temp>h)
				continue;
			a.push_back(temp);
		}
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(i==j)continue;
				sum=l-a[i]-a[j]-1;
				lower=0,higher=0;
				if(sum>=0)
				{
					int bound=int(upper_bound(a.begin(),a.end(),sum)-a.begin())-j-1;
					bound=bound<0?0:bound;
					lower=bound;
				}
				sum=h-a[i]-a[j];
				if(sum>=0)
				{
					int bound=int(upper_bound(a.begin(),a.end(),sum)-a.begin())-j-1;
					bound=bound<0?0:bound;
					higher=bound;
				}
				ans+=higher-lower;
				//cout<<a[i]<<" "<<a[j]<<" "<<higher-lower<<" "<<higher<<" "<<lower<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
