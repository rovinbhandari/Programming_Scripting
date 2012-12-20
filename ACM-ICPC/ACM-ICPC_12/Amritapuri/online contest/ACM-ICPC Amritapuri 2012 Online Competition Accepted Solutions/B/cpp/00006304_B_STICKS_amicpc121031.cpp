#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<map>
#include <set>
#include<vector>
#include<algorithm>
using namespace std;

//#def MAX 
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
