#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	bool ans[t];
	for(int i=0; i<t; i++)
	{
		string x;
		cin>>x;
		int r=0,g=0,b=0,w=0;
		for(int j=0; j<x.length(); j++)
		{
			switch(x[j])
			{
				case 'R':r++;break;
				case 'G':g++;break;
				case 'B':b++;break;
				case 'W':w++;break;
			}
		}
		if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
			ans[i]=true;
		else
			ans[i]=false;
	}
	for(int i=0; i<t; i++)
	{
		if(ans[i])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
			
