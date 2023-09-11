#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
	int n,m,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		long long int a,b,c,stick[n+10],max,temp;
		int i,total;
		for(i=0;i<n;i++)
		{
			cin>>stick[i];
		}
		max=-1;
		for( i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			long long int l2,b2,h2,sum=0;
			l2 = a*a;
            b2 = b*b;
            h2 = c*c;
            sum = l2+ b2+ h2;
			temp= (long long int)sqrt(sum);
			if(temp>max)
			            max=temp;
		}
		total=0;
		for(i=0;i<n;i++)
		{
                        if(stick[i]<=max)
                                         total++;
         }
		
		cout<<total<<"\n";
	}
	return 0;
}
