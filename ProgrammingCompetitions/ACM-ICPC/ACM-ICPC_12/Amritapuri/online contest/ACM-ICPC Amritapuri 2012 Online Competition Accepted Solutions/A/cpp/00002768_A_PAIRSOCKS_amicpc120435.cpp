#include<iostream>
#include<cstdio>
using namespace std;
int main ()
{
	int t,i,r,g,b,w;
	char s[60];
	for(scanf("%d\n",&t);t--;)
	{
		r=g=b=w=0;
		scanf("%s",s);
		for(i=0;s[i];i++)
		{
			if(s[i]=='R') r++;
			if(s[i]=='G') g++;
			if(s[i]=='B') b++;
			if(s[i]=='W') w++;
		}
		if(r&1 || b&1 || g&1 || w&1) printf("NO\n");
		else printf("YES\n");
	}
}