/*
 * AICPC.cpp
 *
 *  Created on: Nov 4, 2012
 *      Author: akashmamtani
 */

#include<stdio.h>
#include<string.h>

int main()
{
	int tests=0;
	scanf("%d",&tests);
	int count[5];
	char socks[51];
	while(tests--)
	{
		memset(count,0,sizeof(count));
		memset(socks,0,sizeof(socks));
		scanf("%s",socks);
		int i=0;
		int pos=0;
		for(i=0;i<strlen(socks);i++)
		{
			if(socks[i]=='R')
			{
				pos=0;
			}
			else if(socks[i]=='G')
			{
				pos=1;
			}
			else if(socks[i]=='B')
			{
				pos=2;
			}
			else
			{
				pos=3;
			}
			++count[pos];
		}
		int flag=0;
		for(i=0;i<4;i++)
		{
			if(count[i]%2!=0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}


