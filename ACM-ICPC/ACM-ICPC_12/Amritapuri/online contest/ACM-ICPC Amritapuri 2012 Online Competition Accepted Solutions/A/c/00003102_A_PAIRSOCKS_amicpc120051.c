#include<stdio.h>
int main()
{
int r,g,b,w,i;
char str[54];
int T;
scanf("%d",&T);
fflush(stdin);
for(;T>0;T--)
	{
	r=g=w=b=0;
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++)
			{
			if(str[i]=='R')
			r++;
			if(str[i]=='G')
			g++;
			if(str[i]=='W')
			w++;
			if(str[i]=='B')
			b++;	
			}
	if(r%2==0 && g%2==0 && w%2==0 && b%2==0)
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
