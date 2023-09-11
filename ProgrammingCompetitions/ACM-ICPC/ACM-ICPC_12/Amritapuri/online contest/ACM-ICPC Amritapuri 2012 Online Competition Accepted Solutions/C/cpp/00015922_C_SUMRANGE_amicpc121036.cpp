#include<iostream>
using namespace std;
int main()
{
	int t;
	long l,h;
	cin>>t;
	while(t--)
	{
		int n,temp,min,c=0;	
		
		cin>>n>>l>>h;
		long a[n];	
		
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n-1;i++)
		{
			min=i;temp=0;
			for(int j=i+1;j<n;j++)
			{
				if(a[j]<a[min])
				{
					min=j;
				}
			}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
		}
		
		for(int j=0;j<n-2&&a[j]<h;j++)
		{
			for(int k=j+1;k<n&&(a[j]+a[k]<h);k++)
			{long s=0;
				for(int m=k+1;m<n&&(a[m]+a[j]+a[k]<=h);m++)
				{
					
					s=(a[j]+a[k]+a[m]);
					if((s<=h) && (s>=l))
					{
						c++;
					}
				}
			}
		}
		cout<<c<<endl;
	}
}