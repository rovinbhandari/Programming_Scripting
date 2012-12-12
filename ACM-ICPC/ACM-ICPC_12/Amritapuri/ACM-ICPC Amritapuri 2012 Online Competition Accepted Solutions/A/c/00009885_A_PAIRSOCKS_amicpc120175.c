#include<stdio.h>
#include<string.h>
int main()
{
	int r=0,g=0,b=0,w=0,i=0,T,tempT;
	char c[50];
	char result[1000];
	scanf("%d",&T);
	tempT=T;
	do{
		scanf("%s",c);
		for(i=0;i<strlen(c);i++)
		{
			if(c[i]=='R')
				r=r+1;
			else if(c[i]=='B')
				b=b+1;
			else if(c[i]=='G')
				g=g+1;
			else
				w=w+1;
		}
		if((r%2==0) && (b%2==0) && (g%2==0) && (w%2==0))
			result[T]='Y';
		else
			result[T]='N';
		T=T-1;
		r=0;
		g=0;
		b=0;
		w=0;
	}while(T!=0);
	for(i=tempT;i>0;i--)
	{
		if(result[i]=='Y')
		printf("YES");
		else
		printf("NO");
		printf("\n");
	}
	return 0;
}

