#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		double len[n],diag[m],l,b,h,d;
		for(int i=0;i<n;++i)
			cin>>len[i];
		for(int i=0;i<m;++i)
		{
			cin>>l>>b>>h;
			d=sqrt((l*l)+(b*b)+(h*h));
			diag[i]=d;
		}
		sort(len,len+n);
		sort(diag,diag+m);
		int count=0;
		int i=0,j=0;
		while(i<n && j<m)
		{
			if(len[i]<=diag[j]){count++;
				i++;}
			else
				j++;
		}
		cout<<count<<endl;

	}
	return 0;
}
