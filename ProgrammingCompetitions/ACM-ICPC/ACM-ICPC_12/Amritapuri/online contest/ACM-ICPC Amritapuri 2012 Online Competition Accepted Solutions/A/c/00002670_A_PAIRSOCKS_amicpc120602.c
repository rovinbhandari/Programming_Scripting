#include<stdio.h>
#include<string.h>
int main()
{
	int t,r,g,b,w,i;
	char s[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int l=strlen(s);
		r=g=b=w=0;
		for(i=0;i<l;i++)
		{
			if(s[i]=='R')
			{
				r++;
			}
			else if(s[i]=='G')
			{
				g++;
			}
			else if(s[i]=='B')
			{
				b++;
			}
			else
			{
				w++;
			}
		}
		if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
		{
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}
