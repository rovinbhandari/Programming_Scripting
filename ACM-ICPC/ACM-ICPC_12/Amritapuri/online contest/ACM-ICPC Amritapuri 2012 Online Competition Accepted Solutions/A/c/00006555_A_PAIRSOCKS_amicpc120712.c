#include<stdio.h>

int main()
{
	int t,i,j;
	char p[100];
	int x;
	int col[4]={0,0,0,0};
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		x=0;
		for(j=0;j<4;j++)
		 col[j]=0;
		j=0;
		scanf("%s",p);
		while(p[j]!='\0')
		{
			switch(p[j])
			{
				case 'R':col[0]++;
				break;
				case 'G':col[1]++;
				break;
				case 'W':col[2]++;
				break;
				case 'B':col[3]++;
				break;
			}
			j++;
		}
		//for(j=0;j<4;j++)
		 //printf("%d",col[j]);
		if(col[0]%2==0&&col[1]%2==0&&col[2]%2==0&&col[3]%2==0)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
