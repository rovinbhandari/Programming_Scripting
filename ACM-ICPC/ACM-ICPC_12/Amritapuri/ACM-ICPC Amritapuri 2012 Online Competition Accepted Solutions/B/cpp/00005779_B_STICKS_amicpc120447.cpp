
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
#define MAX 50001

using namespace std;

vector<long long> l;

int main(){
	long long temp,t,n,v,m,a,b,c,is,st,en,mi,max;
	double sq;
	cin>>t;
	while(t--)
	{
		max=0;
		l.clear();
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			l.push_back(temp);
		}
		sort(l.begin(),l.end());
		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			int u=int(upper_bound(l.begin(),l.end(),floor(sqrt(a*a+b*b+c*c)))-l.begin());
			if(max<u)
				max=u;
		}
		cout<<max<<endl;
	}
	return 0;
}
