#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXLEN 100

void reverseandlower(char* s)
{
	
	int i = 0, l = strlen(s);	// l is without the trailing '\0'
	char c;
	
	while(i < l / 2)
	{
		c = tolower(*(s + i));
		*(s + i) = tolower(*(s + l - i - 1));
		*(s + l - i - 1) = c;
		i++;
	}
	*(s + i) = tolower(*(s + i));
}

int htoirevstr(const char* s)
{
	static int power = 0;

	int len = strlen(s);
	
	if(!len)
	{
		return 0;
	}
	
	char c = *s;
	
	if(c == 'x')
	{
		if(!(len == 2))
		{
			exit(1);
		}
		else if(*(s + 1) != '0')
		{
			exit(1);
		}
		else
		{
			return 0;
		}
	}
	
	int numval;
	
	if(c >= '0' && c <= '9')
	{
		numval = c - '0';
	}
	else if(c >= 'a' && c <= 'f')
	{
		numval = c - 'a' + 10;
	}
	else
	{
		exit(1);
	}
	
	return  pow(16, power++) * numval + htoirevstr(s + 1);	
}

/*
	int htoi(const char*) works for both:
	char*
	char[]
*/
int htoi(const char* s)
{
	int len = strlen(s);
	
	if(len)
	{
		char t[MAXLEN];		//TODO: can't this be modified to reserve only len + 1 bytes for t?
		strncpy(t, s, len + 1);
		
		reverseandlower(t);
		return htoirevstr(t);
	}
	else
	{
		return -1;
	}			
}

int main(void)
{
	char t[MAXLEN];
	scanf("%s", t);

	printf("htoi(%s) = %d\n", t, htoi(t));

	return 0;
}

