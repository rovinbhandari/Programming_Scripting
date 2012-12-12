/* N socks problem*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int t,i,cnt_r=0,cnt_b=0,cnt_g=0,cnt_w=0,cnt_t=0;
	char c[50],*op;
	scanf("%d",&t);
	op=(char *)calloc(t,sizeof(char));
	if(!op)
	{
		printf("\nERROR: Memory Leak !!!");
		exit(-1);
	}
	if(t>1000 || t<1)
	{
		printf("\nNumber of Test case should not be negative. It is like [1<=T<=1000]");
		return -1;
	}
	while(cnt_t<t)
	{
		cnt_r=0,cnt_b=0,cnt_g=0,cnt_w=0;
		scanf("%s",c);
		if(strlen(c)>50 || strlen(c)==0)
		{
			printf("\nNumber of Characters should be less than 50. [0<c<=50]");
			return -1;
		}
		for(i=0;i<strlen(c);i++)
		{
			if(c[i]=='R' || c[i]=='r')
			cnt_r++;
			if(c[i]=='G' || c[i]=='g')
			cnt_g++;
			if(c[i]=='B' || c[i]=='b')
			cnt_b++;
			if(c[i]=='W' || c[i]=='w')
			cnt_w++;
		}
		if(cnt_r%2==0 && cnt_g%2==0 && cnt_b%2==0 && cnt_w%2==0)
			op[cnt_t]='y';
		else
			op[cnt_t]='n';
		cnt_t++;
	}
	for(i=0;i<cnt_t;i++)
	if(op[i]=='y')
	printf("YES\n");
	else
	printf("NO\n");
	free(op);
	return 0;
}
