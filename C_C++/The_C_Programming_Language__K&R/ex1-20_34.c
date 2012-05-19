/*
	detab
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int tabsizenew, atoi(const char*);

	if(argc > 1)
	{
		tabsizenew = atoi(argv[1]);
	}
	else
	{
		printf("INCORRECT USAGE\n");
		return 0;
	}

	char c;
	int counter = 0, putchar(int), getchar(void);

	while((c = getchar()) != EOF)
	{
		if(c == '\n')
		{
			counter = 0;
			putchar(c);
		}
		else if(c == '\t')
		{
			int i, j;

			for(i = 0, j = counter; i < tabsizenew - j % tabsizenew; i++)
			{
				putchar(' ');
				counter++;
			}
		}
		else
		{
			putchar(c);
			counter++;
		}
	}

	return 0;
}

