#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		int i,j,l[n],a[m],b[m],c[m]; 
		unsigned long long size[m],max=0;
		for(i=0;i<n;i++)
		{
			cin>>l[i];
		}

		for(j=0;j<m;j++)
		{
			cin>>a[j]>>b[j]>>c[j];//cout<<a[j]<<b[j]<<c[j];
			size[j] = a[j]*a[j];
			size[j]+=b[j]*b[j];
			size[j]+=c[j]*c[j];
			size[j] = sqrt(size[j]);
			if(max<size[j]) max=size[j];
		}
		//cout<<"m"<<max<<endl;
		int count=0;
		for(i=0;i<n;i++)
		{
			if(l[i] <= max) count++;
		}
		cout<<count<<endl;
	}
}
