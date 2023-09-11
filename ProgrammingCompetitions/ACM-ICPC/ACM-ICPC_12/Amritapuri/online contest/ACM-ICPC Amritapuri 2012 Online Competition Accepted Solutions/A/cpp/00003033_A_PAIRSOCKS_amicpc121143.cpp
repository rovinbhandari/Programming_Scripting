/*Pair socks*/

#include<stdio.h>

int main()
{
	char str[64];
	int i,T;
	int count[4];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",str);
		count[0]=count[1]=count[2]=count[3]=0;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]=='R')
				count[0]++;
			else if(str[i]=='G')
				count[1]++;
			else if(str[i]=='B')
				count[2]++;
			else if(str[i]=='W')
				count[3]++;
		}
		if((count[0]%2==0) && (count[1]%2==0) && (count[2]%2==0) && (count[3]%2==0))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}