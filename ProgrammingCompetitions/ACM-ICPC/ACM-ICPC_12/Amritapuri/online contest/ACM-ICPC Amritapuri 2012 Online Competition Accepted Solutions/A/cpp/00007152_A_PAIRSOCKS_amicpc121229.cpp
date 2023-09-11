#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;		// RGBW
int pairs(char a[50])
{
	bool socks[]={0,0,0,0};

	for (int i=0;i<strlen(a);i++)
	{

		if(a[i] == 'R')
		{
			if(socks[0]==0)
			{
				socks[0]=1;
			}
			else
				socks[0]=0;
			continue; 
		}
		if(a[i] == 'G')
		{
			if(socks[1]==0)
			{
				socks[1]=1;
			}
			else
				socks[1]=0;
			continue;
		}
		if(a[i] == 'B')
		{
			if(socks[2]==0)
			{
				socks[2]=1;
			}
			else
				socks[2]=0;
			continue;
		}
		if(a[i] == 'W')
		{
			if(socks[3]==0)
			{
				socks[3]=1;

			}
			else
			{socks[3]=0;


			} continue;
		}
	}
	for(int i=0;i<4;i++)
	{
		//cout<<socks[i]<<endl;
		if(socks[i]==1)
		{
			return(0);
		}
	}
	return(1);
}

int main()
{
	int noa;
	cin>>noa;
	char *a;
	a = new char[50];
	int *count_array = (int*)calloc(noa,sizeof(int));
	for(int i=0;i<noa;i++)
	{
		cin>>a;
		count_array[i]=pairs(a);
		//  cout<<count_array[i]<<endl;
	}
	for(int i=0;i<noa;i++)
	{
		if(count_array[i]==1)
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

