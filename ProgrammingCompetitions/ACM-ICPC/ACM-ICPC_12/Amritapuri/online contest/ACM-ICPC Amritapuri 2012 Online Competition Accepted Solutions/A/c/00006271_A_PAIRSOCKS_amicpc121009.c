#include<stdio.h>
int main()
{
	int NoT;
	scanf("%d",&NoT);
	int i=0,j=0;
	char string[50];
	for(i=0;i<NoT;i++){
		int count[4],z;
		for(z=0;z<4;z++)
			count[z]=0;
		scanf("%s",string);
		for(j=0;string[j]!='\0';j++)
		{
			switch(string[j]){
			case 'R': count[0]++;break;
			case 'G': count[1]++;break;
			case 'B': count[2]++;break;
			case 'W': count[3]++;break;
			}
			//for(z=0;z<4;z++)
			//printf("%d",count[z]);
		}
		int flag=0;
		for(j=0;j<4;j++)
		{
			if(count[j]%2!=0)
				flag=1;
		}
		if(flag==0)
			printf("YES\n");
		else if(flag==1)
			printf("NO\n");
		
	}
	return 0;
}
