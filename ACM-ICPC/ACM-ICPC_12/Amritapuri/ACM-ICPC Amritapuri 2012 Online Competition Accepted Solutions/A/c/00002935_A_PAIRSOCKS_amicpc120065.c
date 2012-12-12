#include<stdio.h>

int main()
{
	int T,i,j,k,l,B[4];
	char A[100],c;
	scanf("%d",&T);
	scanf("%c",&c);
	while(T--)
	{
		B[0]=B[1]=B[2]=B[3]=0;
		scanf("%c",&c);
		while(c!='\n')
		{
			if(c=='R')
			{	
				B[0]++;
			}
			else if(c=='G')
			{	
				B[1]++;
			}
			else if(c=='B')
			{	
				B[2]++;
			}
			else if(c=='W')
			{	
				B[3]++;
			}
			scanf("%c",&c);
		}
		if(B[0]%2==0 && B[1]%2==0 && B[2]%2==0 && B[3]%2==0)
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
