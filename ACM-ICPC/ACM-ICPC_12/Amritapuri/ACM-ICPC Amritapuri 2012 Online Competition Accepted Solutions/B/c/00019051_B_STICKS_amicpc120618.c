#include <stdio.h>

int main()
{
	int total , N , M , Len[50000] , i;
	
	int l , b , h , count ;
	unsigned int dig , tempd;
	unsigned int  templq;
	scanf("%d" , &total);
	while(total--)
	{
		count = 0;
		scanf("%d %d" , &N , &M);
		for(i=0 ; i<N ; i++)
		{
			scanf("%d" , Len + i);
		}
		dig = 0;
		while(M--)
		{
			scanf("%d %d %d" , &l , &b , &h);
			tempd = l*l + b*b + h*h ;
			//tempd = l*l + b*b  ; 
			if( dig  < tempd )
			{
			//	printf("here\n");
				dig = tempd;
			}
			//printf("diag %u\n" ,tempd );
		}
		//printf("diagonal %u\n" , dig );
		for(i=0 ; i<N ; i++)
		{
			if(Len[i] >= 52000)
				continue;
			templq = (Len[i] * Len[i]) ;
			//printf("length %u \n" , templq );
			if(templq <= dig)
			{
				count++;
			}
		}
		printf("%d\n" , count);
	}
	return 0;
}
