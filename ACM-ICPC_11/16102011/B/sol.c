#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *chars = calloc(26, sizeof(int));
	char c;
	c = getchar();
	while(  c <= 'z' && c>='a' )
	{
		chars[c - 'a'] += 1;
		c = getchar();
	}


	int i;
	for(i = 0; i < 26; i++)
	{
		if(chars[i])
		{
			printf("%c %d\n", i + 'a', chars[i]);
		}
	}

	return 0;
}
