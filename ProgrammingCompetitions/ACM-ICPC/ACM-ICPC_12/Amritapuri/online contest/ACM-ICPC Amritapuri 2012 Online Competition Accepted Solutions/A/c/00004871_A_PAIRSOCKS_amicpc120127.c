#include<stdio.h>

int main()		{
	
	int test, i, j;
	char inp[55];
	int out[4];
	
	scanf("%d", &test);
	
	for( i=0; i<test; i++ )		{
	
		out[0]= out[1]= out[2]= out[3]= 0;
		scanf("%s", inp);
		
		for( j=0; inp[j]!='\0'; j++ )		{
			
			if( inp[j]=='R' || inp[j]=='r' )
				out[0]++;
			else if( inp[j]=='G' || inp[j]=='g' )
				out[1]++;
			else if( inp[j]=='B' || inp[j]=='b' )
				out[2]++;
			else if( inp[j]=='W' || inp[j]=='w' )
				out[3]++;
			else;
			
		}//End Of Loop(j)
		
		if( out[0]%2==0 && out[1]%2==0 && out[2]%2==0 && out[3]%2==0 )
			printf("YES\n");
		else
			printf("NO\n");
		
	}	//End Of Test Loop
	
	return 0;
}//End Of Main
