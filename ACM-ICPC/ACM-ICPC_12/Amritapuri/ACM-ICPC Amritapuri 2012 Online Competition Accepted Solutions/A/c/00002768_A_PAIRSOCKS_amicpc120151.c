#include<stdio.h>
int main()
{
	int hash[4];
	int t, i, flag;
	char a[100];

	scanf("%d", &t);
	while(t--)
	{
		flag=0;
		for(i=0; i<4; i++)
			hash[i]=0;
		scanf("%s", a);
		i=0;
		while(a[i]!='\0')
		{
			if(a[i]=='R')
				hash[0]++;
			if(a[i]=='G')
				hash[1]++;
			if(a[i]=='B')
				hash[2]++;
			if(a[i]=='W')
				hash[3]++;
			i++;

		}	
		for(i=0; i<4; i++)
		{
			if(hash[i]%2!=0)
				flag=1;
		}
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");


	}

	return 0;
}
