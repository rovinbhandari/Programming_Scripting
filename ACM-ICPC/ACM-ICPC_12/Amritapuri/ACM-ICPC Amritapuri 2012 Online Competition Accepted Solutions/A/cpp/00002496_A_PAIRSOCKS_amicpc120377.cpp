#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	//freopen("input.txt","r",stdin);
	int t,l;
	scanf("%d",&t);
	while(t--)
	{
    char s[60];
    int g=0,b=0,r=0,w=0;
	scanf("%s",s);
	l=strlen(s);
	for(int i=0;i<l;i++){if(s[i]=='G')g++;else if(s[i]=='B')b++;else if(s[i]=='R')r++;else if(s[i]=='W')w++;}
    if(b%2==0&&g%2==0&&w%2==0&&r%2==0)printf("YES\n");else printf("NO\n");
	}
return 0;
}
