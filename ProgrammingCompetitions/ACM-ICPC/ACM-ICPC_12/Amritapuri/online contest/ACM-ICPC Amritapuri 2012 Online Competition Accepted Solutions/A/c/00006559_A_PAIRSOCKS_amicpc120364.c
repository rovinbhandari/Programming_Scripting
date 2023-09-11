#include<stdio.h>
#include<string.h>

int main()
{
int T,n,r=0,g=0,b=0,w=0,i,j,an[1003];
char a[52];

scanf("%d",&n);

for(i=0;i<n;i++)
	{
	r=0;g=0;b=0;w=0;
	strcpy(a,"");
		scanf("%s",a);
		for(j=0;a[j]!='\0';j++)
		{
		if (a[j]=='R')
		r++;
		else if (a[j]=='G')
		g++;
		else if (a[j]=='B')
		b++;
		else if (a[j]=='W')
		w++;
		}
		
	if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
	printf("YES\n");
	else
	printf("NO\n");
	}
return 0;
}
