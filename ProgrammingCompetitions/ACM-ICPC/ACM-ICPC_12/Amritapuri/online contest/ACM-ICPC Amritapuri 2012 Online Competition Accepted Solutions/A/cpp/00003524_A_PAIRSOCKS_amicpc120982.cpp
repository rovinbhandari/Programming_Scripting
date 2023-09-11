#include<stdio.h>
#include<iostream>
#include<string.h>
#include<map>
#include<stdlib.h>

using namespace std;

int main()
{
	int testcases;
	map<char,int> count;
	count['R']=0;
	count['G']=0;
	count['B']=0;
	count['W']=0;
	scanf("%d",&testcases);
	//cin>>testcases;
	bool *result;
	result = (bool*)malloc(sizeof(bool));
	char input[1000];
	for(int i=0;i<testcases;i++)
	{
		scanf("%s",input);
		//cin>>input;
		for(int j=0;j<strlen(input);j++)
		{
			count[input[j]]=count[input[j]]+1;
		}
		
		if(count['R']%2==0)
		{
			if(count['G']%2==0)
			{
				if(count['B']%2==0)
				{
					if(count['W']%2==0)
					{
						result[i]=true;
					}
					else
					{
						result[i]=false;
					}
				}
				else
				{
					result[i]=false;
				}
			}
			else
			{
				result[i]=false;
			}
		}
		else
		{
			result[i]=false;
		}
		count['R']=0;
		count['G']=0;
		count['B']=0;
		count['W']=0;
		
	}
	for(int i=0;i<testcases;i++)
	{
		if(result[i])
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
