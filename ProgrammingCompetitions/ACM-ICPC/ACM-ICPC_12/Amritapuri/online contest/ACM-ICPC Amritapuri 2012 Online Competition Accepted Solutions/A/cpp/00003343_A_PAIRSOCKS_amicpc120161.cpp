#include<iostream>
#include<cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	char t[1100];
	for (int i=0;i<n;i++)
	{
		scanf("%1001s",&t);
		int a=0,b=0,c=0,d=0;
		for (int j=0;j<strlen(t);j++)
		{
			if (t[j]=='R')
				a++;
			else if (t[j]=='G')
				b++;
			else if (t[j]=='B')
				c++;
			else if (t[j]=='W')
				d++;
		}
		if (a%2==0 && b%2==0 && c%2==0 && d%2==0)
			printf("YES\n");
		else 
			printf("NO\n");
	}
}
		
