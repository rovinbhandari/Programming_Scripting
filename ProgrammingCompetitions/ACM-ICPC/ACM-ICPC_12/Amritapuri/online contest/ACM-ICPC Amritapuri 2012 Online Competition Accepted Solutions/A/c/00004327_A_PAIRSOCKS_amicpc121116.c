#include<stdio.h>
#include<string.h>
int main()
{
	char list[55];
	int t,red,green,blue,white,len,i;
	scanf("%d",&t);
	while(t--)
	{
		red=green=blue=white=0;
		memset(list,'\0',55);
		//flush(stdin);
		scanf("%s",list);
		len = strlen(list);
		for(i=0;i<len;i++)
		{
			if(list[i] == 'R')
				red++;
			if(list[i] == 'B')
				blue++;	
			if(list[i] == 'W')
				white++;
			if(list[i] == 'G')
				green++;
		}
		if(red%2 ==0 && green %2 == 0 && blue%2 ==0 & white%2 ==0)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
