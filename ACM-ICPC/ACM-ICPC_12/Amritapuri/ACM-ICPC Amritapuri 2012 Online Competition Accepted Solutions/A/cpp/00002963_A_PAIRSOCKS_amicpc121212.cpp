#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t, i, r, g, b, w; char s[60];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		r=0; g=0; b=0; w=0;
		for(i=0;s[i]!=0;i++)
			switch(s[i])
		{
			case 'R': ++r;break;
			case 'G': ++g;break;
			case 'B': ++b;break;
			case 'W': ++w;break;        
		}
		if(!(r&1) && !(g&1) && !(b&1) && !(w&1))
			printf("YES\n");
		else printf("NO\n");
 }
	return 0;
}
