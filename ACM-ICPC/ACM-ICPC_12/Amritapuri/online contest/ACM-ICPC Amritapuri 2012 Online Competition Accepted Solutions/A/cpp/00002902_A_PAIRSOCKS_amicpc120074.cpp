#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int t,l,i;
	scanf("%d",&t);
	char s[60];
	while(t--)
	{
		scanf("%s",s);
		l=strlen(s);
		int count1,count2,count3,count4;
		count1=0;
		count2=0;
		count3=0;
		count4=0;
		for(i=0;i<l;i++)
		{
			if(s[i]=='R')
			{
				count1++;
			}
			else if(s[i]=='B')
			{
				count2++;
			}
			else if(s[i]=='G')
			{
				count3++;
			}
			else
			{
				count4++;
			}
		}
		if((count1%2==0) && (count2%2==0) && (count3%2==0) && (count4%2==0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
