#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,r=0,g=0,b=0,w=0;
	scanf("%d",&n);
	char c[n][50];
	int length[n][2];
	
	if(n>=1 || n<=1000)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",*(c+i));
			length[i][0]=strlen(c[i]);
			length[i][1]=0;
		}
		for(i=0;i<n;i++)
		{
			 for(j=0;j<=length[i][0];j++)
			{
				if(j==length[i][0])
				{
					length[i][1]=1;	
					break;
				}
				if(c[i][j]=='R'||c[i][j]=='G'||c[i][j]=='B'||c[i][j]=='W')
				{
					continue;
					
				}
				else
				{
					
					length[i][1]=0;
					break;
				}
				
			}
		}

		
		for(i=0;i<n;i++)
		{
			if(length[i][1]==1 && length[i][0]%2==0)
			{
				for(j=0;j<length[i][0];j++)
				{
					if(c[i][j]=='R')
					{
						r+=1;
					}
					else if(c[i][j]=='G')
					{
						g+=1;
					}
					else if(c[i][j]=='B')
					{
						b+=1;
					}
					else
					{
						w+=1;
					}
					
				}
				if(r%2==0 && b%2==0 && g%2==0 && w%2==0)
				{
					printf("YES");
				}
				else
				{
					printf("NO");
				}
			}
			else
			{
				printf("NO");
			}
			printf("\n");
			r=0;g=0;b=0;w=0;
		}
	}
	return 0;
}

