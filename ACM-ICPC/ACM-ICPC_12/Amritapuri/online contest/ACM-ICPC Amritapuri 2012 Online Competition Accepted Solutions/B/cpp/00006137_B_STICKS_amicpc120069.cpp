#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int i,t,n,m,j,count=0;
	cin>>t;
	double maxi,temp4,temp1,temp2,temp3,leng[50001];
	for(i=0;i<t;i++)
	{
		count=0;
		maxi=0;
		cin>>n;
		cin>>m;
		for(j=0;j<n;j++)
		{
			cin>>leng[j];
		}
		for(j=0;j<m;j++)
		{
			cin>>temp1;	
			cin>>temp2;	
			cin>>temp3;	
			temp4=sqrt(pow(temp1,2)+pow(temp2,2)+pow(temp3,2));
			maxi=max(maxi,temp4);	
		}
		for(j=0;j<n;j++)
		{
			if(leng[j]<=maxi){count++;}
		}
		cout<<count<<endl;
	}
}
