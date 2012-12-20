#include <cstdio>
#include <cstring>
int main()
{
	int t,n,i,j,k,r,b,g,w;
	char s[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		r=b=g=w=0;
		int len=strlen(s);
		for(i=0;i<len;i++) if(s[i]=='R') r++; else if(s[i]=='G') g++; else if(s[i]=='W') w++;
		else b++;
		if((r%2)==0 && (b%2)==0 && (g%2)==0 && (w%2)==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}