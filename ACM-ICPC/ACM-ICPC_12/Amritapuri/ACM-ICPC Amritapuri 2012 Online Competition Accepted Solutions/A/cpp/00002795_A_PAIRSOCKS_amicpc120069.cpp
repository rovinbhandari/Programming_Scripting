#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int n,i,j,arr[4];
	char strin[100];
	cin>>n;
	for(i=0;i<n;i++)
	{
		arr[0]=0;
		arr[1]=0;
		arr[2]=0;
		arr[3]=0;
		cin>>strin;
		for(j=0;j<strlen(strin);j++)
		{
			if(strin[j]=='R'){arr[0]++;}
			if(strin[j]=='G'){arr[1]++;}
			if(strin[j]=='B'){arr[2]++;}
			if(strin[j]=='W'){arr[3]++;}
		}
		if(arr[0]%2==0 && arr[1]%2==0 && arr[2]%2==0 && arr[3]%2==0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
