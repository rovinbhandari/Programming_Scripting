#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[50];
	int r[4],flag=1;
	int i;
	cin>>i;
	while(i--)
	{
		flag=1;
		scanf("%s",a);
		int d=strlen(a);
		for (int h=0;h<4;h++)
		r[h]=0;
		for(int j=0;j<=d;j++)
		{
			if(a[j]=='R')
				r[0]++;
			if(a[j]=='G')
			r[1]++;
			if(a[j]=='B')
			r[2]++;
			if(a[j]=='W')
				r[3]++;
		}
		for(int m=0;m<4;m++)
		{
			if(r[m]%2==1)
			{
				flag=0;
			}
		}
		if(flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;

}

			
		


