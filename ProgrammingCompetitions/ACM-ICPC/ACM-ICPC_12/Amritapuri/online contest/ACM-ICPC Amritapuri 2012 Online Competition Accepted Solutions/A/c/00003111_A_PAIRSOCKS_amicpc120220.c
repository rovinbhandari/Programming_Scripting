#include<stdio.h>
int main()
{
	int t,a[4],c;
	scanf("%d\n",&t);
	while(t--)
	{	
		a[0]=a[1]=a[2]=a[3]=0;
		while((c=getchar())!='\n')
		{
			if(c=='R')a[0]++;
			else if(c=='G')a[1]++;
			else if(c=='B')a[2]++;
			else a[3]++;
		}
		if((a[0]&1)||(a[1]&1)||(a[2]&1)||(a[3]&1))printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}



