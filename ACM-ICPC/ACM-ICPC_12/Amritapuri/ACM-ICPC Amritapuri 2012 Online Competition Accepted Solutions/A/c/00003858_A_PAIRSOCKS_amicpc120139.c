#include<stdio.h>
#include<string.h>
int main()
{
	int not,arr[5],i;
	char str[55],c;
	scanf("%d",&not);
	//scanf("%c",&c);
	while(not)
	{
		arr[0]=arr[1]=arr[2]=arr[3]=0;
		//scanf("%c",&c);
		//if(c=='\n')
		scanf("%s",str);
		//printf("%s\n",str);
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]=='R')
				arr[0]++;
			else if(str[i]=='G')
				arr[1]++;
			else if(str[i]=='B')
				arr[2]++;
			else
				arr[3]++;
		}
		//printf("%d %d %d %d\n",arr[0],arr[1],arr[2],arr[3]);
		if(arr[0]%2==1 || arr[1]%2==1 || arr[2]%2==1 || arr[3]%2==1)
			printf("NO\n");
		else 
			printf("YES\n");
		not--;
	}
	return 0;
}
