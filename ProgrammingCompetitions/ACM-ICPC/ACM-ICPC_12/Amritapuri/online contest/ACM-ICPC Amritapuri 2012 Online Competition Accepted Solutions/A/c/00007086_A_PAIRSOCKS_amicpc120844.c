#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int t,i=0,j,c[4],flag=0;;
    char **a;
    scanf("%d",&t);
    a=malloc(t*sizeof(char*));
	while(i<t)
    {
     a[i]=(char*)malloc(50*sizeof(char));
     scanf("%s",a[i]);
     i++;
    }
    for(i=0;i<t;i++)
    {flag=0;
	for(j=0;j<4;j++)
	c[j]=0;
	if((strlen(a[i])%2)!=0)
	{
	  printf("NO\n");
	  continue;
	}
	  for(j=0;j<strlen(a[i]);j++)
		{
    		switch(a[i][j])
			{
				case 'R':
					c[0]++;
					break;
				
				case 'B':
					c[1]++;
					break;

				case 'G':
					c[2]++;
					break;		

				case 'W':
					c[3]++;
					break;   
			} 
		}
		j=0;
		while(j<4)
		{
			if(c[j]%2!=0)
				{
					printf("NO\n");
					flag++;				
					j++;
					break;
					
				}
		j++;
		}
			if(flag==0)
			printf("YES\n");
	}
	return 0;
}
