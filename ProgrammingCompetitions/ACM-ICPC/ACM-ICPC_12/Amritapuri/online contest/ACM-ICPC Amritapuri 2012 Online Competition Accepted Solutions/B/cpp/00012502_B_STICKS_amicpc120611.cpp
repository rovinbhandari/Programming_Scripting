#include<iostream>
#include<math.h>
using namespace std;
main()
{
	int t;
	cin>>t;
	int final[t];
	int flag;
	for (int i=0;i<t;++i)
	{
		flag=1;
		int n,m;
		cin>>n>>m;
		double l[n];
		for(int h=0;h<n;++h)
		{
			cin>>l[h];
		}
		double a[m],b[m],c[m];
		for(int h=0;h<m;++h)
		{
			cin>>a[h];
			cin>>b[h];
			cin>>c[h];
		}
		double max=0;
		for(int h=0;h<n;++h)
		{
			if(max<l[h])
			{
				max=l[h];
			}
		}
		double maxbox=0;
		double tmp;
		for(int h=0;h<m;++h)
		{
			tmp=sqrt(a[h]*a[h]+b[h]*b[h]+c[h]*c[h]);
			if(tmp>maxbox)
			{
				maxbox=tmp;
			}
			if(maxbox>max)
			{
				final[i]=n;
				flag=0;
				break;
			}
		}
		int ans=0;
		if(flag==1){
			for(int h=0;h<n;++h)
			{
				if(l[h]<=maxbox)
				{
					ans+=1;
				}
			}
			final[i]=ans;
		}	
	}
for(int y=0;y<t;++y)
{
	cout<<final[y]<<endl;
}
}
