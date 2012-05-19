/*
	entab
*/

#include <stdio.h>
#include <stdlib.h>

#define	TRUE	1
#define	FALSE	0

typedef	unsigned short int	Flag;

int main(int argc, char* argv[])
{
	int tabsize, atoi(const char*);

	if(argc > 1)
	{
		tabsize = atoi(argv[1]);
	}
	else
	{
		printf("INCORRECT USAGE\n");
		return 0;
	}

	char c;
	int counter = 0, putchar(int), getchar(void);
	Flag charspacechar = FALSE;
	
	while((c = getchar()) != EOF)
	{
		if(c == ' ')
		{
			counter++;

			if(tabsize == 1 && charspacechar == 1)
			{
				charspacechar = charspacechar << 1 | TRUE;		// equivalent to: charspacechar = (charspacechar << 1) | TRUE;
			}
		}
		else
		{
			if(tabsize == 1)
			{
				if(c == '\n')
				{
					charspacechar = FALSE;
				}
				else if(charspacechar == 0)
				{
					charspacechar = charspacechar << 1 | TRUE;
				}
				else if(charspacechar == 3)
				{
					charspacechar = charspacechar << 1 | TRUE;
					while(counter)
					{
						putchar(' ');
						counter--;
					}
					charspacechar = 1;
				}
			}
			
			if(counter)
			{
				int tabs = counter / tabsize;
				counter %= tabsize;
	
				while(tabs)
				{
					putchar('\t');
					tabs--;
				}
				while(counter)
				{
					putchar(' ');
					counter--;
				}
			}
			putchar(c);
		}
	}

	return 0;
}

