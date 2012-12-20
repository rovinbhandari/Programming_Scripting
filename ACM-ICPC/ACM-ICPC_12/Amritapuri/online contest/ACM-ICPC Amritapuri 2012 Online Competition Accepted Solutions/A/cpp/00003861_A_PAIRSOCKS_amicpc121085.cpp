#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	
	int cases;
	cin>>cases;
	char socks[cases][50],ch='0';
	int arr[cases][4];
	for(int i=0;i<cases;i++)
	{
		arr[i][0]=arr[i][1]=arr[i][2]=arr[i][3]=0;
		int j=0;
		scanf("%s",socks[i]);
		//cout<<"sdaf\n";
		while(socks[i][j]!='\0')
		{
			if(socks[i][j]=='R')
				arr[i][0]++;
			else if(socks[i][j]=='G')
				arr[i][1]++;
			else if(socks[i][j]=='B')
				arr[i][2]++;
			else if(socks[i][j]=='W')
				arr[i][3]++;
			j++;
				
		}
	}
	for(int i=0;i<cases;i++)
	{
		if(arr[i][0]%2==0 && arr[i][1]%2==0 && arr[i][2]%2==0 && arr[i][3]%2==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
