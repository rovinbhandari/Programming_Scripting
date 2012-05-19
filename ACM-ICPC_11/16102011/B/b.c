#include <stdio.h>

int main()
{
	int chars[26] = {0};
	char c;
	c = getchar();
	while(  c <= 'z' && c >= 'a' )
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
