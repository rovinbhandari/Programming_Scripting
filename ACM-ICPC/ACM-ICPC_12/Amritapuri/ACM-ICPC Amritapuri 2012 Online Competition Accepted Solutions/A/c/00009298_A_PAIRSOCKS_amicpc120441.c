#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *str;
	int i,cases;
	int cr=0;
	int cb=0;
        int cg=0;
	int cw=0;
	int str_len;
	int flag_invalid;
	scanf("%d",&cases);
	while(cases--){
		cr=0;
		cb=0;
	        cg=0;
		cw=0;		
		str_len = 0;
		flag_invalid = 0;
		str = malloc(50 * sizeof(char));
		scanf("%s",str);
		str_len = strlen(str);
		for(i=0;i<str_len;i++)
		{
			switch(str[i])
			{
				case 'R':
					cr++;
					break;
				case 'G':
					cg++;
					break;
				case 'B':
					cb++;
					break;
				case 'W':
					cw++;
					break;					
				default:
					flag_invalid = 1;
					break;
			}
		}
		if( (cb%2==0) && (cr%2==0) && (cw%2==0) && (cg%2==0) )
		{
			printf("YES\n");
			continue;
		}
		else if	(flag_invalid != 1)
			printf("NO\n");
		else
			printf("Invalid Input\n");
		free(str);
        }
	return 0;
}
