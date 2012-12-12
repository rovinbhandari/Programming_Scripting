#include <stdio.h>
#include <string.h>

int main()
{
	int tc,i,len,cnt[6],flag;
	char str[100];
	scanf("%d",&tc);
	while(tc--)
	{
		flag=1;
		scanf("%s",str);
		len=strlen(str);

		if(len==0) 
		{
			flag=0;
		}

		if(flag==1)
		{

		for(i=0;i<6;i++)
		{
			cnt[i]=0;
		}

		for(i=0;i<len;i++)
		{
			if(str[i]=='R') cnt[0]++;
			else if(str[i]=='G') cnt[1]++; 
			else if(str[i]=='B') cnt[2]++; 
			else if(str[i]=='W') cnt[3]++; 
		}
	
		if((cnt[0]%2==0) && (cnt[1]%2==0) && (cnt[2]%2==0) && (cnt[3]%2==0) )
			printf("YES\n");
		else
			printf("NO\n");

		}
		else
		{
			printf("NO\n");
		}


	}



return 0;
}
