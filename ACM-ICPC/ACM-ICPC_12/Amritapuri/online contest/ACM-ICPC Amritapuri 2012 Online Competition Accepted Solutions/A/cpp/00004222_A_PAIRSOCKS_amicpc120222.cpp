#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	int t;
	//cin>>t;
	scanf("%d",&t);
	while(t--)
	{
		char s[100]={'\0'};
		scanf("%s",s);
		//cin>>s;
		int arr[4]={0};
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]=='R')
				arr[0]++;
			else if(s[i]=='W')
				arr[1]++;
			else if(s[i]=='G')
				arr[2]++;
			else if(s[i]=='B')
				arr[3]++;
			
		}
		int flag=0;
		for(int i=0;i<4;i++)
		{
			if(arr[i]%2!=0)
			{
				flag=1;
				printf("NO\n");
				break;
			}
		}
		if(flag==0)
			printf("YES\n");
	}
}
