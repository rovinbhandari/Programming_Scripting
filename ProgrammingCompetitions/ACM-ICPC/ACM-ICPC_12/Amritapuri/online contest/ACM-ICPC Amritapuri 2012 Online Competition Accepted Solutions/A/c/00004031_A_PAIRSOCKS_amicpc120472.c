#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int intcmp(const void *v1, const void *v2)
{
      return (*(int *)v1 - *(int *)v2);
}

int main()
{
	int T;			// No. of test cases
	scanf("%d",&T);
	int i,j;
	char A[51];	
	char count[26];
	int flag;
	for (i=0;i<T;i++)
	{	

		scanf("%s",A);
		for(j=0; j<26; j++)
		{
			count[j]=0;
		}
		flag = 1;
		for(j=0;j<strlen(A);j++)
		{
			count[(int)((A[j])-'A')] = count[(int)((A[j])-'A')] + 1;
		}
		for(j=0;j<26;j++)
		{
			if(count[j]%2!=0)
				flag=0;
		}
		if(flag==0)
			printf("NO\n");
		else
			printf("YES\n");

	}
	
	return 0;
}

