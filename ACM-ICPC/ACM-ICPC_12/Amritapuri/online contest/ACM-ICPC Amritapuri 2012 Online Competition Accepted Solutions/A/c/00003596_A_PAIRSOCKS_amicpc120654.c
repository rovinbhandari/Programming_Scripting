#include<stdio.h>
#define R 17
#define G 6
#define B 1
#define W 22
int main()
{
	int i,j;
	
	char str[51],ch;
	int no_test_case;
	scanf("%d",&no_test_case);
	for(i=0;i<no_test_case;i++)
	{
		scanf("%s",str);
		int pos = 0;
		int input[26] = {0};
		while(*(str+pos) != '\0')
		{
			ch = *(str+pos);
			input[ch-'A']++;
			pos++; 
		}
		if(input[B]%2==0 && input[G]%2==0 && input[R]%2==0 && input[W]%2==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}

	return 0;
}
