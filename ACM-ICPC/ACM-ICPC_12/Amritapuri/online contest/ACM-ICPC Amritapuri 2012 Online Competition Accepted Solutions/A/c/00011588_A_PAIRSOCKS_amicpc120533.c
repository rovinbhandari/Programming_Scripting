#include<stdio.h>

#include<string.h>
int main()
{
	int i,l,t,r=0,g=0,b=0,w=0;
	char c[50];
	scanf("%d",&t);
	//int ans[t];	
	for(i=0;i<t;i++)
	{	
		r=0;b=0;g=0;w=0;
		scanf("%s",c);
		l=strlen(c);
		l--;
		while(l>=0)
		{
		
		switch(c[l])
			{
			case 'R': r++;break;
			case 'G': g++;break;
			case 'B': b++;break;
			case 'W': w++;break;
			default: ; 
			}	
			l--;
		}
		
		if(((r%2)!=0)||((g%2)!=0)||((w%2)!=0)||((b%2)!=0)) printf("NO");//	ans[i]=0;
		
		else printf("YES");//ans[i]=1;
		printf("\n");
	}
	
	/*for(i=0;i<t;i++)
	{
		if(ans[i]==1)
		printf("YES");
		else printf("NO");
		printf("\n");
	}*/
	return 0;
}
