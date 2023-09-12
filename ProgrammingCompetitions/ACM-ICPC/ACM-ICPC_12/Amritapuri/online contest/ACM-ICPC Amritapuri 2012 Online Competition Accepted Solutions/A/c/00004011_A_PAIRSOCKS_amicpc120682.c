#include<stdio.h>

int main()
{
	char soc[50];
	int c1,c2,c3,c4,t,i;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%s",soc);
		c1=c2=c3=c4=0;
		for(i=0;soc[i]!='\0';i++)
		{	
			switch(soc[i])
			{
				case 'R': c1++; break;
				
				case 'G': c2++; break;
				
				case 'W': c3++; break;

				case 'B': c4++; break;
			}
		}
	
	
	if((c1%2==0) && (c2%2==0) && (c3%2==0) && (c4%2==0))
	{
	if(c1>0 || c2>0 || c3>0 || c4>0)
	printf("YES\n");
	else
	printf("N0\n");
	}	
	else
	printf("NO\n");

}

return 0;
}	

						
