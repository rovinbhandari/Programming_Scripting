#include<stdio.h>
int main(int argc, char const *argv[])
{
	
	int t,c1,c2,c3,c4;
	char c;
	scanf("%d",&t);
	getchar();
	while(t--)
	{	
		c1=0,c2=0,c3=0,c4=0;
		c= getchar();
		while(c!='\n'){
			if(c=='R'){
				c1++;
			}
			else if(c=='G'){
				c2++;
			}
			else if(c=='B'){
				c3++;
			}
			else if(c=='W'){
				c4++;
			}
			c = getchar();
		}
		// if(!(c1%2)&&!(c2%2)&&!(c3%3)&&!(c4%4))
		// {
		// 	printf("%s\n","YES");
		// }
		// else{
		// 	printf("%s\n","NO" );
		// }
		if((c1&1)|(c2&1)|(c3&1)|(c4&1))
		{
			printf("NO\n");
		}
		else printf("YES\n");
	}
	return 0;
}