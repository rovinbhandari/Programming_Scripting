#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
double dist(double a,double b)
{
    return sqrt(a*a+b*b);	
}
int biner(vector<int> s,int k,int l,int r)
{
	int mid=(l+r)/2;
	if(l>r)
		return r;
	if(k>=s[mid])
	{
		return biner(s,k,mid+1,r);
	}
	else if(k<s[mid])
	{
		if(mid-1<0)
			return -1;
		else if(s[mid-1]<=k)
			return  mid-1;
		else
			return biner(s,k,l,mid-1);
	}




}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<int> sticks;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			sticks.push_back(a);
		}
		sort(sticks.begin(),sticks.end());
/*		while(1)
		{
			int c;
			cin>>c;
			cout<<biner(sticks,c,0,n-1)<<endl;
		}*/
		//vector<pair<int,pair<int,int> > > dim;
		int mx=0;
		for(int i=0;i<m;i++)
		{
			int l,b,h;
			cin>>l>>b>>h;
			//dim.push_back(make_pair(l,make_pair(b,h)));
			double d1,d2,d3,d5,d4,d6,a[6]={0};
			d1=dist(l,b);
			a[0]=d1;
			d2=dist(b,h);
			a[1]=d2;
			d3=dist(l,h);
			a[2]=d3;
			d4=dist(d1,h);
			a[3]=d4;
			d5=dist(d2,l);
			a[4]=d5;
			d6=dist(d3,b);
			a[5]=d6;
			int max=0;
			for(int j=3;j<6;j++)
			{
				//cout<<j<<" : "<<a[j]<<endl;
				if(a[j]>max)
					max=a[j];
			}
			if(max>mx)
				mx=max;

		}
		//cout<<mx<<endl;
		int ans=biner(sticks,mx,0,n-1);
		if(ans==-1)
			cout<<"0"<<endl;
		else
			cout<<ans+1<<endl;
		
	}

	return 0;
}
