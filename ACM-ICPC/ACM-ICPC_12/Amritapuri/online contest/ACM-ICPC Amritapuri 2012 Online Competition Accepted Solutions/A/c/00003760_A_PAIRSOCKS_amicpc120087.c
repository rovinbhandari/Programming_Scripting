#include<stdio.h>
#include<string.h>
int main()
{
	int t; //test cases
	int i=1,j=0;
	int cr=0,cg=0,cb=0,cw=0;
	char c[50],ch;
	scanf("%d",&t);
	while( i <= t )
	{
		scanf("%s",c);
		for( j=0; j<strlen(c); j++ ){
			if( c[j] == 'R' ){ cr++; }
			if( c[j] == 'G' ){ cg++; }
			if( c[j] == 'B' ){cb++;}
			if( c[j] == 'W' ){cw++;}
		}
		if(cr%2 ==0 && cg%2 ==0 && cb %2 ==0 && cw%2==0){
			printf("YES\n");
		}
		else{printf("NO\n");}
		++i;
		cr=0;
		cg=0;
		cb=0;
		cw=0;
	}
	return 0;
}
					
			
			
