#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n=0,m=0,count=0;
		long long int dia=0,maxdia=0;
		long long int l[50001];
                long int a,b,c;
		cin>>n>>m;
		for(long long int i=0;i<n;i++)
		{
			cin>>l[i];
		}
		for(long long int i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			dia=(a*a)+(b*b)+(c*c);
			//cout<<dia<<endl;
			if(dia>maxdia)
				maxdia=dia;

		}
		//cout<<"max "<< maxdia<<endl;
        
		for(unsigned int i=0;i<n;i++)
		{
			//cout<<i<<" "<<l[i]<<endl;
			dia=l[i]*l[i];
			if(dia<=maxdia)
				count++;
		}
		cout<<count<<endl;
		// cin.ignore(1,'\n');
		count=0;
	}



	return 0;
}
