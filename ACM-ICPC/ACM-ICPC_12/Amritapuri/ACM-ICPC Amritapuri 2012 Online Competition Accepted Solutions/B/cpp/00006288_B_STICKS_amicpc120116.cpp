#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
int n;
cin>>n;
int m;
cin>>m;
double lengths[n];
double l[m];
double b[m];
double h[m];
for(int i=0;i<n;i++)
	{
	cin>>lengths[i];
	}
for(int i=0;i<m;i++)
	{
		cin>>l[i];
		cin>>b[i];
		cin>>h[i];
	}
	
double ma=0;

for(int i=0;i<m;i++)
	{
	double dig=sqrtl((l[i]*l[i])+(b[i]*b[i])	+(h[i]*h[i]));
	if(dig>ma)
		{
			ma=dig;
		}		
	}
	int count=0;
for(int i=0;i<n;i++)
	{
		if(lengths[i]<=ma)
			{
				count++;
			}
	}
cout<<count<<endl;

}
}
