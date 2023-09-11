#include<stdio.h>

int main()
{
	int t;			//total number of times
	
	scanf("%d",&t);

	//question data to be used inside while loop
        char s[52]; 
	int r,g,b,w;
	int i; 
	int con;	//	continue 
        //

	while(t--)
	{	
		r=g=b=w=i=0;
		con=1;
		//code for a single  time
		scanf("%s",&s);	
		while(con)
		{
			switch(s[i++])
			{
				case 'R':r=(r+1)%2;
					//	printf("r");
					break;
				case 'G':g=(g+1)%2;	
					//	printf("g");
					break;
				case 'B':b=(b+1)%2;
					//	printf("b");
					break;
				case 'W':w=(w+1)%2;
					//	printf("w");
					break;
				default:con=0;
			}	
		}
		//printf("\n%d %d %d %d",r,g,b,w);
		//output
		if(r||g||b||w)
			printf("NO\n");
		else	
			printf("YES\n");
	
	}
	
		
	return 0;
}
